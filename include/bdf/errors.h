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

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace errors {

            class error{

            protected:
               
               ::std::string msg;
               ::std::string name;
               ::std::string err_class;

               ::std::string get_msg(void) const;

            public:

               DECLSPECIFIER error(
                  const ::std::string &msg,
                  const ::std::string &err_class="bdf_error");

               DECLSPECIFIER error(
                  const ::std::string&, const ::std::string &msg,
                  const ::std::string &err_class="bdf_error");

               DECLSPECIFIER ::std::string operator() (void) const;
            };

            class types_error : public error{

            public:

               DECLSPECIFIER types_error(const ::std::string &msg);
            };

            class form_error : public error{

            protected:

               DECLSPECIFIER form_error(
                  const ::std::string &name, const ::std::string &msg,
                  const ::std::string &cls) :
                  error(name, msg, cls) {};
            };

            class float_error : public form_error{

            public:

               DECLSPECIFIER float_error(const ::std::string&, const ::std::string&);
            };

            class int_error : public form_error{

            public:

               DECLSPECIFIER int_error(const ::std::string&, const ::std::string&);
            };

            class output_error : public error{

            public:

               DECLSPECIFIER output_error(const ::std::string&, const ::std::string&);
            };

            class list_error : public error{

            public:

               DECLSPECIFIER list_error(const ::std::string&, const ::std::string &);
            };

            class str_error : public error{

            public:

               DECLSPECIFIER str_error(const ::std::string&, const ::std::string &);
            };

            class string_error : public error{

            public:

               DECLSPECIFIER string_error(const ::std::string&, const ::std::string &);
            };

            class parse_error : public error{

            public:

               DECLSPECIFIER parse_error(const ::std::string&, const ::std::string &);
            };
         }
      }
   }
}

#endif // _BDF_ERRORS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
