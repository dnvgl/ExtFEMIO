/* Copyright © 2015 by DNV GL SE */

/*
  Purpose: Define errors for handling FEM files.

  Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
 */

/* ID: $Id$
 */

#if !defined _BERHOL20151104_ERRORS
#define _BERHOL20151104_ERRORS

#include "extfem_misc.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace errors {

        class error {

        protected:

          std::string msg;
          std::string name;
          std::string err_class;

          std::string get_msg(void) const;

        public:

          DllExport error(
            const std::string &msg,
            const std::string &err_class="fem_error");

          DllExport error(
            const std::string&, const std::string &msg,
            const std::string &err_class="fem_error");

          DllExport std::string operator() (void) const;
        };

        class types_error : public error {

        public:

          types_error(const std::string &msg);
        };

        class float_error : public error {

        public:

          float_error(const std::string&, const std::string&);
        };

        class int_error : public error {

        public:

          int_error(const std::string&, const std::string&);
        };

        class output_error : public error {

        public:

          output_error(const std::string&, const std::string&);
        };

        class list_error : public error {

        public:

          list_error(const std::string&, const std::string &);
        };

        class str_error : public error {

        public:

          str_error(const std::string&, const std::string &);
        };

        class string_error : public error {

        public:

          string_error(const std::string&, const std::string &);
        };

        class parse_error : public error {

        public:

          parse_error(const std::string&, const std::string &);
        };
      }
    }
  }
}

#endif // _BERHOL20151104_ERRORS

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
