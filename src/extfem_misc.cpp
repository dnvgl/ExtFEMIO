/**
   \file extfem_misc.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of some base extfem functionality.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "extfem_misc.h"
#include "config.h"

namespace dnvgl {
   namespace extfem {
      namespace __base {
         outline::outline(void) {}

         std::ostream &outline::operator<<(std::ostream &os) {
            return this->put(os);
         }

         std::ostream &operator<<(std::ostream &os, outline const &val) {
            return val.put(os);
         }
      }

      std::string version(void) {
         return "ExtFEMIO, Ver. " ExtFEMIO_VERSION;
      }

      std::string build_data(void) {
         return __DATE__ ", " __TIME__;
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
