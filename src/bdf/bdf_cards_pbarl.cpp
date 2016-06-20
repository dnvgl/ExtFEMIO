/**
   \file bdf/bdf_cards_pbarl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBARL cards.

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

#include "bdf/cards.h"
#include "bdf/errors.h"

#include <cstdlib>
#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;

namespace {
   static const double cd0 = 0;
}

const entry_type<std::string> pbarl::form_GROUP(
   "GROUP", bdf::type_bounds::bound<std::string>("MSCBML0"));
namespace {
   static const size_t TYPE_len = 22;
   const char* TYPEinit[TYPE_len] = {
      "T", "TW", "I", "L", "ROD", "TUBE", "CHAN", "BOX", "BAR", "CROSS",
      "H", "T1", "I1", "CHAN1", "Z", "CHAN2", "T2", "BOX1", "HEXA",
      "HAT", "HAT1", "DBOX"};
   const std::set<std::string> TYPE_set(TYPEinit, TYPEinit + TYPE_len);
}
const entry_type<std::string> pbarl::form_TYPE(
   "TYPE", bdf::type_bounds::bound<std::string>(TYPE_set));
const entry_type<double> pbarl::form_DIM(
   "DIM", bdf::type_bounds::bound<double>(&cd0));
const entry_type<double> pbarl::form_NSM(
   "NSM", bdf::type_bounds::bound<double>( nullptr, nullptr, &cd0));

pbarl::pbarl(const std::deque<std::string> &inp) : bar_prop(inp) {

   size_t dim_num = 0;
   size_t i = 0;

   auto pos = inp.begin();

   if (pos == inp.end()) goto invalid;
   ++pos;
   if (pos == inp.end()) goto invalid;
   form_PID.set_value(PID, *(pos++));
   if (pos == inp.end()) goto invalid;
   form_MID.set_value(MID, *(pos++));
   if (pos == inp.end()) goto invalid;
   form_GROUP.set_value(GROUP, *(pos++));
   if (GROUP.value != "MSCBML0")
      throw errors::parse_error(
         "PBARL", "Currently only GROUP==MSCBML0 is supported.");
   if (pos == inp.end()) goto invalid;
   form_TYPE.set_value(TYPE, *(pos++));
   if (pos == inp.end()) goto invalid;
   if (dimnum1.find(TYPE.value) != dimnum1.end())
      dim_num = 1;
   else if (dimnum2.find(TYPE.value) != dimnum2.end())
      dim_num = 2;
   else if (dimnum3.find(TYPE.value) != dimnum3.end())
      dim_num = 3;
   else if (dimnum4.find(TYPE.value) != dimnum4.end())
      dim_num = 4;
   else if (dimnum5.find(TYPE.value) != dimnum5.end())
      dim_num = 5;
   else if (dimnum6.find(TYPE.value) != dimnum6.end())
      dim_num = 6;
   else if (dimnum10.find(TYPE.value) != dimnum10.end())
      dim_num = 10;
   else
      throw errors::parse_error(
         "PBARL", "Unknown beam type " + TYPE.value + ".");

   ++pos;
   for (i=1; i<4; i++) {
      if (pos == inp.end()) goto invalid;
      ++pos;
   }

   for (i=0; i < dim_num; i++) {
      if (pos == inp.end()) goto invalid;
      DIM.push_back(form_DIM(*(pos++)));
   }
   if (pos == inp.end()) goto end;
   form_NSM.set_value(NSM, *(pos));

   goto end;

 invalid:
   throw errors::parse_error("PBARL", "Illegal number of entries.");
 end: ;
}

std::ostream& pbarl::operator << (std::ostream& os) const {
   throw errors::error("can't write PBARL.");
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
