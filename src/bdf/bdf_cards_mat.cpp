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
   const char  cID[]
#ifdef __GNUC__
      __attribute__((__unused__))
#endif
      = "@(#) $Id: bdf_cards_mat1.cpp 225 2015-12-02 14:20:44Z berhol $";
}

#include <deque>
#include <string>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long cl0 = 0, cl1 = 1;
   static const double cd0 = 0., cd05 = 0.5, cd_1 = -1.;
}

const entry_type<long> mat::form_MID(
   "MID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<double> mat::form_G(
   "G",
   bdf::type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> mat::form_RHO(
   "RHO",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_A(
   "A",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_TREF(
   "TREF",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_GE(
   "GE",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_ST(
   "ST",
   bdf::type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> mat::form_SC(
   "SC",
   bdf::type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> mat::form_SS(
   "SS",
   bdf::type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<long> mat::form_MCSID(
   "MCSID",
   bdf::type_bounds::bound<long>(&cl0, nullptr, nullptr, true));

mat::mat(const deque<std::string> &inp) : card(inp) {}

mat::mat() : card() {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
