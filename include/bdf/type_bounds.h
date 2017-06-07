/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright © 2015 by DNV GL SE

   \brief Define boundaries for BDF types.
*/

// ID: $Id$

#if !defined _BDF_TYPE_BOUNDS_H_
#define _BDF_TYPE_BOUNDS_H_

#include <set>
#include <unordered_set>

#include "extfem_misc.h"

#include "bdf/errors.h"

namespace dnvgl {
    namespace extfem {
        namespace bdf {
//! \brief Boundary definitions for BDF card entries.
            namespace type_bounds {
                namespace __base {
                    class type_bound {
                    private:
                        bool _has_min;
                        bool _has_max;
                        bool _has_default;
                    protected:
                        virtual ~type_bound() = default;
                        bool has_min() const;
                        void got_min();
                        bool has_max() const;
                        void got_max();
                        void got_default();
                    public:
                        type_bound();
                        bool has_default() const;
                    };
                }

                template <typename _Ty>
                class bound : public __base::type_bound {
                protected:
                    _Ty min_val;
                    _Ty max_val;
                    std::set<std::string> allowed;
                    _Ty default_val;
                    bool allow_empty;
                public:
                    virtual ~bound() = default;
                    explicit bound(
                        const _Ty *_min = nullptr, const _Ty *_max = nullptr,
                        const _Ty *_default = nullptr,
                        const bool allow_empty = false);
                    explicit bound(std::set<std::string> const&);
                    explicit bound(
                        std::set<std::string> const&, std::string const&);
                    void set_min(const _Ty inp);
                    void set_max(const _Ty inp);
                    void set_default(const _Ty inp);
                    _Ty get_default() const;
                    bool virtual in_bounds(_Ty &val);
                    bool virtual in_bounds(
                        dnvgl::extfem::bdf::types::entry_value<_Ty> &val);
                    bool does_allow_empty() const;
                    bool is_allowed(std::string probe) const;
                    void virtual reset();
                };

                template <typename _Ty>
                bound<_Ty>::bound(
                    const _Ty *_min/*=nullptr*/, const _Ty *_max/*=nullptr*/,
                    const _Ty *_default/*=nullptr*/,
                    const bool allow_empty/*=false*/) :
                        allowed(), allow_empty(allow_empty) {
                    if (_min) set_min(*_min);
                    if (_max) set_max(*_max);
                    if (_default) set_default(*_default);
                }

                template <typename _Ty>
                bound<_Ty>::bound(std::set<std::string> const&) :
                        allowed() {
                    static_assert(true, "Not applicable.");
                }

                template <typename _Ty>
                bound<_Ty>::bound(
                    std::set<std::string> const&, std::string const&) :
                        allowed() {
                    static_assert(true, "Not applicable.");
                }


                template <typename _Ty>
                void bound<_Ty>::set_min(const _Ty inp) {
                    this->min_val = inp;
                    got_min();
                }

                template <typename _Ty>
                void bound<_Ty>::set_max(const _Ty inp) {
                    this->max_val = inp;
                    got_max();
                }

                template <typename _Ty>
                void bound<_Ty>::set_default(const _Ty inp) {
                    this->default_val = inp;
                    got_default();
                }

                template <typename _Ty>
                _Ty bound<_Ty>::get_default() const {
                    if (!has_default())
                        throw errors::types_error(
                            "** ERROR **: No default value avaliable.");
                    return this->default_val;
                }

                template <typename _Ty> inline
                bool bound<_Ty>::is_allowed(std::string probe) const {
                    if (allowed.size() == 0)
                        return true;
                    return (allowed.find(probe) != allowed.end());
                }

                template <typename _Ty>
                bool bound<_Ty>::in_bounds(_Ty &val) {
                    return ((!has_min() || val >= this->min_val) &&
                            (!has_max() || val <= this->max_val));
                }

                template <> inline
                bool bound<std::string>::in_bounds(std::string &val) {
                    return ((!has_min() || val >= this->min_val) &&
                            (!has_max() || val <= this->max_val) &&
                            this->is_allowed(val));
                }

                template <typename _Ty>
                bool bound<_Ty>::in_bounds(
                    dnvgl::extfem::bdf::types::entry_value<_Ty> &val) {
                    return this->in_bounds(val.value);
                }

                template <typename _Ty>
                bool bound<_Ty>::does_allow_empty() const {
                    return allow_empty;
                }

                template <typename _Ty>
                void bound<_Ty>::reset() {}

                template <> inline
                bool bound<std::complex<double>>::in_bounds(
                    std::complex<double> &val);

                template <> inline
                bound<std::string>::bound(std::set<std::string> const &allowed) :
                    type_bound(), allowed(allowed) {}

                template <> inline
                bound<std::string>::bound(
                    std::set<std::string> const &allowed,
                    std::string const &default_val) :
                    type_bound(), allowed(allowed), default_val(default_val) {
                    got_default();
                }

                template <typename _Ty>
                class bound_unique : public bound<_Ty> {
                private:
                    _Ty max_used_id;
                    std::unordered_set<_Ty> used_id;
                public:
                    virtual ~bound_unique() = default;
                    explicit bound_unique(
                        const _Ty *_min=nullptr, const _Ty *_max=nullptr,
                        const _Ty *_default=nullptr,
                        const bool allow_empty=false) :
                            bound<_Ty>(_min, _max, _default, allow_empty),
                            max_used_id{_min ? *_min-1 : -1}, used_id{} {};
                    bool virtual in_bounds(_Ty &val) override {
                        if (!this->bound<_Ty>::in_bounds(val)) {
                            val = max_used_id += 1;
                        }
                        if (used_id.find(val) != used_id.end()) {
                            do { val = max_used_id += 1;
                            } while(used_id.find(max_used_id) != used_id.end());
                        }
                        used_id.insert(val);
                        return this->bound<_Ty>::in_bounds(val);
                    }
                    bool virtual in_bounds(
                        dnvgl::extfem::bdf::types::entry_value<_Ty> &val) override {
                        return in_bounds(val.value);
                    }
                    void virtual reset() override {
                        max_used_id = this->has_min() ? this->min_val - 1 : -1;
                        used_id.clear();
                    };
                };
            }
        }
    }
}

template <> inline
bool dnvgl::extfem::bdf::type_bounds::bound<std::complex<double>>::in_bounds(
    std::complex<double> &val) {
    return ((!has_min() || abs(val) >= abs(this->min_val)) &&
            (!has_max() || abs(val) <= abs(this->max_val)));
}

#endif // _BDF_TYPE_BOUNDS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_types --use-colour no;
//    ../../cbuild/tests/test_bdf_bounds --use-colour no)"
// coding: utf-8
// End:
