/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error handling for processing support data.

   Detailed description
*/

// ID: $Id$

#if !defined _SUPPORT_ERRORS_H_
#define _SUPPORT_ERRORS_H_

#include <string>

namespace dnvgl {
   namespace extfem {
      namespace support {
         namespace errors {

            class error{

            protected:

               std::string msg;
               std::string name;
               std::string err_class;

               std::string get_msg() const;

            public:

               error(
                  const std::string&, const std::string &msg,
                  const std::string &err_class="support_error");

               std::string operator() () const;
            };

            class string_error : public error {

            public:

               string_error(const std::string&, const std::string &);
            };

            class parse_error : public error {

            public:

               parse_error(const std::string&, const std::string &);
            };

             class unreadable_error : public error {

            public:

               unreadable_error(const std::string&, const std::string &);
            };
}
      }
   }
}

#endif // _SUPPORT_ERRORS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
