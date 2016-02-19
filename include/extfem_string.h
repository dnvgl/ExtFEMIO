/**
   \file extfem_string.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Helper functions for string manipulation.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _EXTFEM_STRING_H_
#define _EXTFEM_STRING_H_

#include <string>
#include <algorithm>

#include "extfem_misc.h"

namespace dnvgl {
   namespace extfem {

      namespace string {

         class string : public ::std::string {
         public:
            DECLSPECIFIER string(const ::std::string& in) : ::std::string(in) {};

            // http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
            DECLSPECIFIER string inline trim(const ::std::string &whitespace = " \t") {
               const auto strBegin = this->find_first_not_of(whitespace);
               if (strBegin == std::string::npos)
                  return extfem::string::string(""); // no content

               const auto strEnd = this->find_last_not_of(whitespace);
               const auto strRange = strEnd - strBegin + 1;

               return this->substr(strBegin, strRange);
            };

            string inline upper() {
               transform(this->begin(), this->end(), this->begin(), ::toupper);
               return *this;
            };

            string inline lower() {
               transform(this->begin(), this->end(), this->begin(), ::tolower);
               return *this;
            };
         };
      }
   }
}

#endif // _EXTFEM_STRING_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
