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

#include <cassert>

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

load::load(const long *iSID, const double *iS,
           const std::deque<double> *iSi, const std::deque<long> *iLi) {
  SID = ::std::make_unique<long>(*iSID);
  S = ::std::make_unique<double>(*iS);
  Si = ::std::make_unique<::std::deque<double>>();
  for (auto &p : *iSi)
    Si->push_back(p);
  Li = ::std::make_unique<::std::deque<long>>();
  for (auto &p : *iLi)
    Li->push_back(p);
}

namespace dnvgl {
  namespace extfem {
    namespace bdf {
      namespace cards {

        bdf::types::card load::head = bdf::types::card("LOAD");

        const std::ostream&
        load::operator<< (std::ostream& os) const {
          return os << *this;
        }

        ::std::ostream&
        operator<<(::std::ostream &os, const load &card) {

          std::deque<std::unique_ptr<format_entry>> entries;

          entries.push_back(format(load::head));

          entries.push_back(format<long>(card._SID, card.SID));
          entries.push_back(format<double>(card._S, card.S));

          assert(card.Si->size() == card.Li->size());

          for (size_t i=0; i<card.Si->size(); i++) {
            entries.push_back(format<double>(card._Si, card.Si->at(i)));
            entries.push_back(format<long>(card._Li, card.Li->at(i)));
          }

          os << card.format_outlist(entries) << std::endl;

          return os;
        }
      }
    }
  }
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
