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
            EXTFEMIO_API string(const ::std::string& in) : ::std::string(in) {};
            EXTFEMIO_API string trim(const ::std::string& = " \t");
            string upper();
            string lower();
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
