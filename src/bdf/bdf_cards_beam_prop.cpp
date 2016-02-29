/**
   \file bdf/bdf_cards_beam_prop.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF PBEAM and PBEAML cards.

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

#include <cstdlib>
#include <memory>

using namespace std;
using namespace dnvgl::extfem;
using namespace bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long cl1 = 1;
}

const entry_type<long> beam_base::form_PID(
   "PID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> beam_base::form_MID(
   "MID",
   bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
