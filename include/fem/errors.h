/**
\file fem/errors.h
\author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
\copyright Copyright © 2015 by DNV GL SE
\brief Define errors for handling FEM files.

Detailed description
*/

// ID: $Id$

#if !defined _FEM_ERRORS_H_
#define _FEM_ERRORS_H_

#include <string>

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

               error(
                  const std::string &msg,
                  const std::string &err_class="fem_error");

               error(
                  const std::string&, const std::string &msg,
                  const std::string &err_class="fem_error");

               std::string operator() (void) const;
            };

            class types_error : public error {

            public:

               types_error(const std::string &msg);
            };

            class float_error : public error {

            public:

               float_error(const std::string &name, const std::string &msg);
            };

            class int_error : public error {

            public:

               int_error(const std::string &name, const std::string &msg);
            };

            class bool_error : public error {

            public:

               bool_error(const std::string &name, const std::string &msg);
            };

            class output_error : public error {

            public:

               output_error(const std::string &name, const std::string &msg);
            };

            class list_error : public error {

            public:

               list_error(const std::string &name, const std::string &msg);
            };

            class str_error : public error {

            public:

               str_error(const std::string &name, const std::string &msg);
            };

            class string_error : public error {

            public:

               string_error(const std::string &name, const std::string &msg);
            };

            class parse_error : public error {

            public:

               parse_error(const std::string &name, const std::string &msg);
            };

            class usage_error : public error {

            public:

               usage_error(const std::string &name, const std::string &msg);
            };
         }
      }
   }
}

#endif // _FEM_ERRORS_H_

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
