/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Classes for processing external grouping information for FE files.

   Detailed description
*/

// ID: $Id$

#ifndef _SUPPORT_GROUPING_H_
#define _SUPPORT_GROUPING_H_

#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std::rel_ops;

namespace dnvgl {
    namespace extfem {
        namespace support {
            namespace GroupInfo {

                /// Store extra information on elements.
                class CElemInfo {
                public:
                    long id;
                    long nnodes;

                    std::string napa_obj;
                    std::string func_name;
                    std::string grade;
                    double yield;

                    CElemInfo();
                    CElemInfo(
                        long const &id, long const &nnodes,
                        std::string const &napa_obj,
                        std::string const &func_name,
                        std::string const &grade,
                        double const &yield);
                    explicit CElemInfo(long const &id);

                    bool operator== (const CElemInfo &other) const {
                        return (id == other.id);
                    };

                    bool operator< (const CElemInfo &other) const {
                        return (id < other.id);
                    };
                };

                /// Process additional information for FE file import.
                class grp_info : public std::map<long, CElemInfo> {

                protected:

                    long lastID;

                    grp_info() : lastID{0} {}

                public:

                    double const &yield(const long &id);

                    void add_elem(
                        long const &id,
                        long const &nnodes,
                        std::string const &napa_obj,
                        std::string const &func_name,
                        std::string const &grade,
                        double const &yield) {
                        (*this)[id] = CElemInfo(
                            id, nnodes, napa_obj, func_name, grade, yield);
                    };

                    void add_elem(long const &id) {
                        (*this)[id] = CElemInfo(id);
                    };
                };

                class CSV : public virtual grp_info {

                public:

                    explicit CSV(std::istream &);

                protected:

                    CSV() {};

                    static void process_line(std::string const &, CElemInfo *);
                };

                class Session : public grp_info {

                public:

                    explicit Session(std::istream const &);

                protected:

                    static void process_range(
                        std::string const &, std::vector<long> *) = delete;
                };
            }
        }
    }
}

namespace std {
    template <>
    struct hash<dnvgl::extfem::support::GroupInfo::CElemInfo> {
        size_t operator()(const dnvgl::extfem::support::GroupInfo::CElemInfo& k) const {
            return hash<long>()(k.id);
        }
    };
}
#endif // _SUPPORT_GROUPING_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
