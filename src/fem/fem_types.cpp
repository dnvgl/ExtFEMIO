/**
   \file fem/fem_types.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for SESAM FEM data entry types.

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

#ifndef _MSC_VER
#include <config.h>
#endif

#include "fem/types.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace types {
            namespace __base {

               b_type::b_type(const std::string &name) : name(name) {};

               std::istringstream b_type::conv;

               /// std::set input and output locale for conv
               static imbue_helper _imbue_helper(std::locale::classic());
            }

            std::string card::format() const {
               std::ostringstream res;
               res.setf(std::ios_base::left, std::ios_base::adjustfield);
               res.fill(' ');
               res.width(8);
               res << name;
               return res.str();
            }

            std::string empty::format() const {
               std::ostringstream res;
               res.fill(' ');
               res.width(16);
               res << "            0.00";
               return res.str();
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
