/**
   \file bdf/bdf_cards_grid.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF GRID cards.

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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long cl0 = 0, cl1 = 1, cl_1 = -1, cl_2 = -2;
   static const long cl1e8 = 100000000;
   static const double cd0 = 0.;
}

const entry_type<long> grid::form_ID(
   "ID", bdf::type_bounds::bound<long>(&cl1, &cl1e8));
const entry_type<long> grid::form_CP(
   "CP", bdf::type_bounds::bound<long>(&cl1, nullptr, &cl_1));
const entry_type<double> grid::form_X1(
   "X1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> grid::form_X2(
   "X2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> grid::form_X3(
   "X3", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<long> grid::form_CD(
   "CD", bdf::type_bounds::bound<long>(&cl_1, nullptr, &cl_2));
const entry_type<std::deque<int>> grid::form_PS("PS");
const entry_type<long> grid::form_SEID(
   "SEID", bdf::type_bounds::bound<long>(&cl_1, nullptr, &cl0));


grid::grid(const ::std::deque<::std::string> &inp) : card(inp) {

   auto pos = inp.rbegin();


   form_SEID.set_value(SEID, "");
   form_PS.set_value(PS, "");
   form_CD.set_value(CD, "");

   switch (inp.size()-1) {
   case 8:
      form_SEID.set_value(SEID, *(pos++));
   case 7:
      form_PS.set_value(PS, *(pos++));
   case 6:
      form_CD.set_value(CD, *(pos++));
   case 5:
      form_X3.set_value(X3, *(pos++));
      form_X2.set_value(X2, *(pos++));
      form_X1.set_value(X1, *(pos++));
      form_CP.set_value(CP, *(pos++));
      form_ID.set_value(ID, *pos);
      break;
   default:
      throw errors::parse_error("GRID", "Illegal number of entries.");
   }
}

grid::grid(long &ID, long &CP, double &X1, double &X2, double &X3) :
   card(),
   ID(ID), CP(CP), X1(X1), X2(X2), X3(X3),
   CD(), PS(), SEID() {}

const std::ostream& grid::operator << (std::ostream& os) const {
   throw errors::error("can't write GRID.");
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
