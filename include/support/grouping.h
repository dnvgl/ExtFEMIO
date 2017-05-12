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
                class elem_info {
                public:
                    long id;
                    long nnodes;

                    std::string napa_obj;
                    std::string func_name;
                    std::string grade;
                    double yield;

                    elem_info();
                    elem_info(
                        long const &id, long const &nnodes,
                        std::string const &napa_obj,
                        std::string const &func_name,
                        std::string const &grade,
                        double const &yield);
                    elem_info(long const &id);

                    inline bool operator== (const elem_info &other) const {
                        return (id == other.id);
                    };

                    inline bool operator< (const elem_info &other) const {
                        return (id < other.id);
                    };
                };

                /// Process additional information for FE file import.
                class grp_info : public std::map<long, elem_info> {

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
                        (*this)[id] = elem_info(
                            id, nnodes, napa_obj, func_name, grade, yield);
                    };

                    void add_elem(long const &id) {
                        (*this)[id] = elem_info(id);
                    };
                };

                class CSV : public virtual grp_info {

                public:

                    explicit CSV(std::istream &);

                protected:

                    CSV() {};

                    static void process_line(std::string const &, elem_info *);
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

#endif // _SUPPORT_GROUPING_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
