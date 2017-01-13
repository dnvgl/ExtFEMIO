/**
   \file bdf/type_bounds.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright © 2015 by DNV GL SE

   \brief Define boundaries for BDF types.
*/

// ID: $Id$

#if !defined _BDF_TYPE_BOUNDS_H_
#define _BDF_TYPE_BOUNDS_H_

#include "bdf/errors.h"

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         /*!
           \brief Boundary definitions for BDF card entries.
         */
         namespace type_bounds {

            namespace __base {
               class type_bound {

               private:

                  bool _has_min;
                  bool _has_max;
                  bool _has_default;

               protected:

                  virtual ~type_bound ();

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

            template <class _Ty>
            class bound : public __base::type_bound {

            protected:

               _Ty min_val;
               _Ty max_val;
               _Ty default_val;
               bool allow_empty;

            public:

               virtual ~bound() {};

               bound(const _Ty *_min=nullptr,
                     const _Ty *_max=nullptr,
                     const _Ty *_default=nullptr,
                     const bool &allow_empty=false) :
                  allow_empty(allow_empty) {
                  if (_min)
                     set_min(*_min);
                  if (_max)
                     set_max(*_max);
                  if (_default)
                     set_default(*_default);
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

               _Ty get_default(void) const {
                  if (!has_default())
                     throw errors::types_error("** ERROR **: No default value avaliable.");
                  return this->default_val;
               };

               bool in_bounds(const _Ty &val) const {
                  return ((!has_min() || val >= this->min_val) &&
                          (!has_max() || val <= this->max_val));
               };

               bool does_allow_empty(void) const {
                  return allow_empty;
               };
            };

            template<>
            class bound<std::string> : public __base::type_bound{

            private:

               std::set<std::string> allowed;
               std::string default_val;

            public:

               bound() {}

               bound(std::set<std::string> allowed) :
                  __base::type_bound(), allowed(allowed) {}

               bound(std::set<std::string> allowed, std::string default_val) :
                  __base::type_bound(), allowed(allowed), default_val(default_val) {
                  got_default();
               }

               bound(std::string default_val) :
                  __base::type_bound(),
                  default_val(default_val) {
                  got_default();
               }

               bool is_allowed(const std::string probe) const {
                  if (allowed.size() == 0)
                     return true;
                  return !(allowed.find(probe) == allowed.end());
               }

               std::string get_default(void) const {
                  if (!has_default())
                     throw errors::types_error("** ERROR **: No default value avaliable.");
                  return this->default_val;
               }
            };
         }
      }
   }
}

#endif // _BDF_TYPE_BOUNDS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
