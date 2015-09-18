// Copyright © 2015 by DNV GL SE

// Purpose: Common definitions for Nastran BDF PBAR and PBARL cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "stdafx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_cards.h"

#include <cstdlib>
#include <memory>

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> bdf_bar_prop::_PID(
  "PID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> bdf_bar_prop::_MID(
  "MID",
  bdf::type_bounds::bound<long>(make_unique<long>(1).get(), nullptr,
                                nullptr, true));

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
