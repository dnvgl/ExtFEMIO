// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF LOAD cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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
#include "bdf/types.h"
#include "bdf/errors.h"

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;

const entry_type<long> load::_SID(
  "SID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<double> load::_S("S");
const entry_type<double> load::_Si("Si");
const entry_type<long> load::_Li(
  "Li", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));

load::load(const std::deque<std::string> &inp) :
  card(inp) {

  auto pos = inp.begin();

  Si = make_unique<std::deque<double>>();
  Li = make_unique<std::deque<long>>();

  if (pos == inp.end()) goto invalid;
  ++pos;
  if (pos == inp.end()) goto invalid;
  SID = bdf::types::get_val<long>(_SID, *(pos++));
  if (pos == inp.end()) goto invalid;
  S = bdf::types::get_val<double>(_S, *(pos++));
  if (pos == inp.end()) goto invalid;
  while (pos != inp.end() && extfem::string::string(*pos) != "") {
    Si->push_back(*_Si(*(pos++)));
    if (pos == inp.end()) goto invalid;
    Li->push_back(*_Li(*(pos++)));
  }
  goto end;

 invalid:
  throw errors::parse_error("LOAD", "Illegal number of entries.");
 end: ;
}

load::load(long &SID, double &S,
           std::deque<double> &Si, std::deque<long> &Li) :
  SID(&SID), S(&S), Si(&Si), Li(&Li) {}

const std::ostream& load::operator << (std::ostream& os) const {
  return os;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
