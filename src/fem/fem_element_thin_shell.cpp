/**
   \file fem/fem_element_thin_shell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for fem_thin_shell.

   Flat Quadrilateral/Triangular Thin Shell / Free Formulation
   Quadrilateral/Triangular Shell
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

#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {

         using namespace cards;

         namespace elements {
            namespace __base {

               fem_thin_shell::fem_thin_shell(gelmnt1 const *data) :
                  elem(data) {}

               fem_thin_shell::fem_thin_shell(gelref1 const *data) :
                  elem(data) {}

               fem_thin_shell::fem_thin_shell(__base::elem const *data) :
                  elem(data) {}
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
