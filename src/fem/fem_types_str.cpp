/**
   \file fem/fem_types_str.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing of string entries from Sesam FEM files.

   Detailed description
*/

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_types_str[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <sstream>

#include "fem/types.h"
#include "fem/errors.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {

         using namespace type_bounds;

         namespace types {

            entry_type<std::string>::entry_type(const std::string &name) :
               __base::b_type(name), bounds() {}

            entry_type<std::string>::entry_type(
               const std::string &name,
               const bound<std::string> &bounds) :
               __base::b_type(name), bounds(bounds) {}

            std::string
            entry_type<std::string>::operator() (
               const std::string &inp1, const std::string &inp2,
               const std::string &inp3, const std::string &inp4) const {

               std::string sval = extfem::string::string(
                  inp1 + inp2 + inp3 + inp4).trim();

               if (sval.length() == 0)
                  sval = bounds.get_default();

               return sval;
            }

            std::string entry_type<std::string>::format(
               const std::string &inp, const size_t &len) const {

               std::ostringstream res;

               res.setf(std::ios_base::left, std::ios_base::adjustfield);
               res.fill(' ');
               res.width(len);

               res << inp;
               std::string out(res.str());
               if (out.size() > len) {
                  std::ostringstream msg("output string for value ", std::ostringstream::ate);
                  msg << inp << " of incorrect size, got length of " << out.size()
                      << " instead of allowed length of " << len << ".";
                  throw errors::int_error(name, msg.str());
               }
               out.resize(len-8, ' ');
               return out;
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
