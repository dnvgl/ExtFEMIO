/**
   \file bdf/bdf_cards_mat2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF MAT2 cards.

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

#include <deque>
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

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long cl0 = 0, cl1 = 1;
   static const double cd0 = 0., cd05 = 0.5, cd_1 = -1.;
}

mat2::mat2(const std::deque<std::string> &inp) : mat(inp) {

   form_MCSID.set_value(MCSID, "");
   form_SS.set_value(SS, "");
   form_SC.set_value(SC, "");
   form_ST.set_value(ST, "");
   form_GE.set_value(GE, "");
   form_TREF.set_value(TREF, "");
   form_A.set_value(A1, "");
   form_A.set_value(A2, "");
   form_A.set_value(A3, "");
   form_RHO.set_value(RHO, "");
   form_G.set_value(G33, "");
   form_G.set_value(G23, "");
   form_G.set_value(G22, "");
   form_G.set_value(G13, "");
   form_G.set_value(G12, "");
   form_G.set_value(G11, "");

   auto pos = inp.rbegin();

   switch (inp.size()-1) {
   case 24:
      ++pos;
   case 23:
      ++pos;
   case 22:
      ++pos;
   case 21:
      ++pos;
   case 20:
      ++pos;
   case 19:
      ++pos;
   case 18:
      ++pos;
   case 17:
      form_MCSID.set_value(MCSID, *(pos++));
   case 16:
      form_SS.set_value(SS, *(pos++));
   case 15:
      form_SC.set_value(SC, *(pos++));
   case 14:
      form_ST.set_value(ST, *(pos++));
   case 13:
      form_GE.set_value(GE, *(pos++));
   case 12:
      form_TREF.set_value(TREF, *(pos++));
   case 11:
      form_A.set_value(A3, *(pos++));
   case 10:
      form_A.set_value(A2, *(pos++));
   case 9:
      form_A.set_value(A1, *(pos++));
   case 8:
      form_RHO.set_value(RHO, *(pos++));
   case 7:
      form_G.set_value(G33, *(pos++));
   case 6:
      form_G.set_value(G23, *(pos++));
   case 5:
      form_G.set_value(G22, *(pos++));
   case 4:
      form_G.set_value(G13, *(pos++));
   case 3:
      form_G.set_value(G12, *(pos++));
   case 2:
      form_G.set_value(G11, *(pos++));
      form_MID.set_value(MID, *(pos));
      break;
   default:
      throw errors::parse_error("MAT2", "Illegal number of entries.");
   }

   if (((bool)A1 || (bool)A2 || (bool)A3) && !(bool)TREF)
      form_TREF.set_value(TREF, "");
}

const std::ostream& mat2::operator << (std::ostream& os) const {
   throw errors::error("can't write MAT2.");
   return os;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
