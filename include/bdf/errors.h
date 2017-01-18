/**
   \file bdf/errors.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error handling for processing BDF data.

   Detailed description
*/

// ID: $Id$

#if !defined _BDF_ERRORS_H_
#define _BDF_ERRORS_H_

#include <string>

#include "extfem_misc.h"

#if defined(_MSC_VER) & _MSC_VER < 1900
#define _EXTFEMIO_NOEXCEPT
#else
#define _EXTFEMIO_NOEXCEPT noexcept
#endif

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace errors {

            class error{

            protected:

               std::string msg;
               std::string name;
               std::string err_class;

               std::string get_msg(void) const;

            public:

               error(
                  const std::string&, const std::string &msg,
                  const std::string &err_class="bdf_error");

               char const *what(void) const _EXTFEMIO_NOEXCEPT;
            };

            class types_error : public error {

            public:

               types_error(const std::string &msg);
            };

            class form_error : public error {

            protected:

               form_error(
                  const std::string &name, const std::string &msg,
                  const std::string &cls);
            };

            class float_error : public form_error {

            public:

               float_error(const std::string&, const std::string&);
            };

            class int_error : public form_error {

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

#endif // _BDF_ERRORS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
