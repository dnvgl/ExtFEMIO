/**
   \file extfem_string.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief String helper functions.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_extfem_string[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {

   extfem::string::string::string(const std::string& in) :
      std::string(in) {}

   /// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
   extfem::string::string extfem::string::string::trim(const std::string &whitespace) {
      const auto strBegin = this->find_first_not_of(whitespace);
      if (strBegin == std::string::npos)
         return extfem::string::string(""); // no content

      const auto strEnd = this->find_last_not_of(whitespace);
      const auto strRange = strEnd - strBegin + 1;

      return this->substr(strBegin, strRange);
   }

   extfem::string::string extfem::string::string::upper() {
      transform(this->begin(), this->end(), this->begin(), ::toupper);
      return *this;
   }

   extfem::string::string extfem::string::string::lower() {
      transform(this->begin(), this->end(), this->begin(), ::tolower);
      return *this;
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
