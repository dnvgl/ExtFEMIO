/**
\file bdf/bdf_cards_mat.cpp
\author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
\copyright Copyright © 2016 by DNV GL SE
\brief Common definitions for Nastran BDF MAT1 and MAT2 cards.

Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char cID_bdf_cards_mat[]
#ifdef __GNUC__
      __attribute__((__unused__))
#endif
      = "@(#) $Id$";
}

#include <list>
#include <string>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
   static const long cl0 = 0, cl1 = 1;
   static const double cd0 = 0., cd05 = 0.5, cd_1 = -1.;
}

namespace dnvgl {
   namespace extfem {
      namespace bdf {

         using types::entry_type;
         using namespace type_bounds;

         namespace cards {
            namespace __base {

               const entry_type<long> mat::form_MID(
                  "MID", bound<long>(&cl1));
               const entry_type<double> mat::form_G(
                  "G", bound<double>(&cd0, nullptr, nullptr, true));
               const entry_type<double> mat::form_RHO(
                  "RHO", bound<double>(nullptr, nullptr, nullptr, true));
               const entry_type<double> mat::form_A(
                  "A", bound<double>(nullptr, nullptr, nullptr, true));
               const entry_type<double> mat::form_TREF(
                  "TREF", bound<double>(nullptr, nullptr, nullptr, true));
               const entry_type<double> mat::form_GE(
                  "GE", bound<double>(nullptr, nullptr, nullptr, true));
               const entry_type<double> mat::form_ST(
                  "ST", bound<double>(&cd0, nullptr, nullptr, true));
               const entry_type<double> mat::form_SC(
                  "SC", bound<double>(&cd0, nullptr, nullptr, true));
               const entry_type<double> mat::form_SS(
                  "SS", bound<double>(&cd0, nullptr, nullptr, true));
               const entry_type<long> mat::form_MCSID(
                  "MCSID", bound<long>(&cl0, nullptr, nullptr, true));

               mat::mat(const std::list<std::string> &inp) : card(inp) {}

               mat::mat() : card() {}
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
