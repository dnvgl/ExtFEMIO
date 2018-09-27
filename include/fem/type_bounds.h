/*!
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Define boundaries for fem cards.

   Detailed description
*/

// ID: $Id$

#if !defined _FEM_TYPE_BOUNDS_H_
#define _FEM_TYPE_BOUNDS_H_

#include <set>

#include "fem/errors.h"

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace type_bounds {
                class base {
                private:
                    bool _has_min;
                    bool _has_max;
                    bool _has_default;
                protected:
                    ~base () = default;
                    bool has_min() const;
                    void got_min();
                    bool has_max() const;
                    void got_max();
                    void got_default();
                public:
                    base();
                    bool has_default() const;
                };

                template <typename _Ty> class bound : public base {
                protected:
                    _Ty min_val;
                    _Ty max_val;
                    _Ty default_val;
                    bool allow_empty;
                public:
                    ~bound() {};
                    bound(const _Ty *_min=nullptr,
                          const _Ty *_max=nullptr,
                          const _Ty *_default=nullptr,
                          const bool &allow_empty=false) :
                            allow_empty(allow_empty) {
                        if (_min) set_min(*_min);
                        if (_max) set_max(*_max);
                        if (_default) set_default(*_default);
                    };
                    void set_min(const _Ty &inp) {
                        this->min_val = inp;
                        got_min();
                    };
                    void set_max(const _Ty &inp) {
                        this->max_val = inp;
                        got_max();
                    };
                    void set_default(const _Ty &inp) {
                        this->default_val = inp;
                        got_default();
                    };
                    _Ty get_default() const {
                        if (!has_default())
                            throw errors::types_error(
                                "** ERROR **: No default value avaliable.");
                        return this->default_val;
                    };
                    bool in_bounds(const _Ty *val) const {
                        return ((!has_min() || *val >= this->min_val) &&
                                (!has_max() || *val <= this->max_val));
                    };
                    bool in_bounds(const _Ty &val) const {
                        return ((!has_min() || val >= this->min_val) &&
                                (!has_max() || val <= this->max_val));
                    };
                    bool does_allow_empty() const {
                        return allow_empty;
                    };
                };

                template<> class bound<std::string> : public base{
                private:
                    std::set<std::string> allowed;
                    std::string default_val;
                public:
                    bound() {};
                    bound(std::set<std::string> const &allowed) :
                            base(), allowed(allowed) {};
                    bound(std::set<std::string> const &allowed,
                          std::string const &default_val) :
                            base(), allowed(allowed), default_val(default_val) {
                        got_default();
                    };
                    bound(std::string const &default_val) :
                            base(), default_val(default_val) {
                        got_default();
                    };
                    bool is_allowed(std::string const &probe) const {
                        if (allowed.empty())
                            return true;
                        return !(allowed.find(probe) == allowed.end());
                    };
                    std::string get_default() const {
                        if (!has_default())
                            throw errors::types_error(
                                "** ERROR **: No default value avaliable.");
                        return this->default_val;
                    };
                };

                template<> class bound<bool> : public base{
                private:
                    bool default_val;
                public:
                    bound() = default;
                    explicit bound(bool &_default) {
                        got_default();
                    }
                    bool get_default() const {
                        if (!has_default())
                            throw errors::types_error(
                                "** ERROR **: No default value avaliable.");
                        return this->default_val;
                    };
                };
            }
        }
    }
}

#endif // _FEM_TYPE_BOUNDS_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
