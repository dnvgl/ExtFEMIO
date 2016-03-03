/**
   \file bdf/bdf_cards_shell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF CTRIA3 and CQUAD4 cards.

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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;
using dnvgl::extfem::bdf::types::entry_type;

namespace {
   static const long cl0 = 0, cl1 = 1;
   static const double cd0 = 0.;
}

const entry_type<long> base_shell::form_EID(
   "EID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> base_shell::form_PID(
   "PID",
   bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));
const entry_type<long> base_shell::form_G1(
   "G1", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> base_shell::form_G2(
   "G2", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> base_shell::form_G3(
   "G3", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> base_shell::form_G4(
   "G4", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> base_shell::form_MCID(
   "MCID", bdf::type_bounds::bound<long>(&cl0));
const entry_type<double> base_shell::form_THETA(
   "MCID", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> base_shell::form_ZOFFS(
   "ZOFFS", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<long> base_shell::form_TFLAG(
   "TFLAG", bdf::type_bounds::bound<long>(&cl0, &cl1, &cl0));
const entry_type<double> base_shell::form_T1(
   "T1", bdf::type_bounds::bound<double>(&cd0, nullptr, &cd0, true));
const entry_type<double> base_shell::form_T2(
   "T2", bdf::type_bounds::bound<double>(&cd0, nullptr, &cd0, true));
const entry_type<double> base_shell::form_T3(
   "T3", bdf::type_bounds::bound<double>(&cd0, nullptr, &cd0, true));
const entry_type<double> base_shell::form_T4(
   "T4", bdf::type_bounds::bound<double>(&cd0, nullptr, &cd0, true));

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
