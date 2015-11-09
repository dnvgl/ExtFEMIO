/* Copyright © 2015 by DNV GL SE */

/*
  Purpose: Define boundaries for bdf cards.

  Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
 */

/* ID: $Id$
 */

#if !defined _BERHOL20151104_TYPE_BOUNDS
#define _BERHOL20151104_TYPE_BOUNDS

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

          ~base () {};

          bool has_min() const {return _has_min;};

          void got_min() {_has_min = true;};

          bool has_max() const {return _has_max;};

          void got_max() {_has_max = true;};

          void got_default() {_has_default = true;};

        public:

          base() : _has_min(false), _has_max(false), _has_default(false) {};

          bool has_default() const {
            return _has_default;
          };
        };

        template <class T> class bound : public base {

        protected:

          T min_val;
          T max_val;
          T default_val;
          bool allow_empty;

        public:

          ~bound() {};

          bound(const T *_min=nullptr,
                const T *_max=nullptr,
                const T *_default=nullptr,
                const bool &allow_empty=false) :
            allow_empty(allow_empty) {
            if (_min)
              set_min(*_min);
            if (_max)
              set_max(*_max);
            if (_default)
              set_default(*_default);
          };

          void set_min(const T &inp) {
            this->min_val = inp;
            got_min();
          };

          void set_max(const T &inp) {
            this->max_val = inp;
            got_max();
          };

          void set_default(const T &inp) {
            this->default_val = inp;
            got_default();
          };

          T get_default(void) const {
            if (!has_default())
              throw ::dnvgl::extfem::fem::errors::types_error("** ERROR **: No default value avaliable.");
            return this->default_val;
          };

          bool in_bounds(const T *val) const {
            return ((!has_min() || *val >= this->min_val) &&
                    (!has_max() || *val <= this->max_val));
          };

          bool in_bounds(const T &val) const {
            return ((!has_min() || val >= this->min_val) &&
                    (!has_max() || val <= this->max_val));
          };

          bool does_allow_empty(void) const {
            return allow_empty;
          };
        };

        template<> class bound<::std::string> : public base {

        private:

          ::std::set<::std::string> allowed;
          ::std::string default_val;

        public:

          bound() {};
          bound(::std::set<::std::string> allowed) :
            base(),
            allowed(allowed) {};
          bound(::std::set<::std::string> allowed, ::std::string default_val) :
            base(),
            allowed(allowed), default_val(default_val) {
            got_default();
          };
          bound(::std::string default_val) :
            base(),
            default_val(default_val) {
            got_default();
          };

          bool is_allowed(const ::std::string probe) const {
            if (allowed.size() == 0)
              return true;
            return !(allowed.find(probe) == allowed.end());
          }

          ::std::string get_default(void) const {
            if (!has_default())
              throw ::dnvgl::extfem::fem::errors::types_error("** ERROR **: No default value avaliable.");
            return this->default_val;
          };
        };
      }
    }
  }
}

#endif // _BERHOL20151104_BOUNDS

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../.. check -j8"
  coding: utf-8
  End:
 */
