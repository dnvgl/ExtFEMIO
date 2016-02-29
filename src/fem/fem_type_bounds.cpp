/**
   \file fem/fem_type_bounds.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implementation of type bounds for Seasam FEM IO.

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

#include <string>

#include "fem/type_bounds.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace type_bounds {

            base::~base () {};

            bool base::has_min() const {
               return _has_min;
            }

            void base::got_min() {
               _has_min = true;
            }

            bool base::has_max() const {
               return _has_max;
            }

            void base::got_max() {
               _has_max = true;
            }

            void base::got_default() {
               _has_default = true;
            }


            base::base() :
               _has_min(false), _has_max(false), _has_default(false)
            {}

            bool base::has_default() const {
               return _has_default;
            }


         }
      }
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
