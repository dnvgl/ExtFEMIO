// Copyright © 2015 by DNV GL SE

// Purpose: Common definitions for Nastran BDF FORCE and MOMENT cards.

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

const entry_type<long> momforce_base::_SID(
  "SID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> momforce_base::_G(
  "G", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> momforce_base::_CID(
  "CID", bdf::type_bounds::bound<long>(
    make_unique<long>(0).get(), nullptr, make_unique<long>(0).get()));
const entry_type<double> momforce_base::_F("F");
const entry_type<double> momforce_base::_N1(
  "N1",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> momforce_base::_N2(
  "N2",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> momforce_base::_N3(
  "N3",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));

momforce_base::momforce_base(const std::deque<std::string> &inp) :
  card(inp) {

  auto pos = inp.rbegin();

  SID = nullptr;
  G = nullptr;
  CID = nullptr;
  F = nullptr;
  N1 = nullptr;
  N2 = nullptr;
  N3 = nullptr;

  switch (inp.size()-1) {
  case 8:
    ++pos;
  case 7:
    N3 = bdf::types::get_val<double>(_N3, *(pos++));
  case 6:
    N2 = bdf::types::get_val<double>(_N2, *(pos++));
  case 5:
    N1 = bdf::types::get_val<double>(_N1, *(pos++));
    if (*N1 == 0. && *N2 == 0. && *N3 == 0.) {
      throw errors::parse_error(
        "FORCE/MOMENT", "At least one of N1, N2, and N3 has to be != 0..");
    }
    F = bdf::types::get_val<double>(_F, *(pos++));
    CID = bdf::types::get_val<long>(_CID, *(pos++));
    G = bdf::types::get_val<long>(_G, *(pos++));
    SID = bdf::types::get_val<long>(_SID, *(pos++));
    break;
  default:
    throw errors::parse_error("FORCE/MOMENT", "Illegal number of entries.");
  }
}

momforce_base::momforce_base(
  const long *iSID, const long *iG, const long *iCID,
  const double *iF,
  const double *iN1, const double *iN2, const double *iN3) {
  SID = std::make_unique<long>(*iSID);
  G = std::make_unique<long>(*iG);
  CID = std::make_unique<long>(*iCID);
  F = std::make_unique<double>(*iF);
  if (iN1)
    N1 = std::make_unique<double>(*iN1);
  else
    N1 = nullptr;
  if (iN2)
    N2 = std::make_unique<double>(*iN2);
  else
    N2 = nullptr;
  if (iN3)
    N3 = std::make_unique<double>(*iN3);
  else
    N3 = nullptr;
};

void momforce_base::add_collect(
  std::deque<std::unique_ptr<format_entry>> &res,
  const momforce_base &card) const {
  res.push_back(format<long>(card._SID, card.SID));
  res.push_back(format<long>(card._G, card.G));
  res.push_back(format<long>(card._CID, card.CID));
  res.push_back(format<double>(card._F, card.F));
  res.push_back(format<double>(card._N1, card.N1));
  if (N2 || N3)
    res.push_back(format<double>(card._N2, card.N2));
  if (N3)
    res.push_back(format<double>(card._N3, card.N3));

}

const std::ostream& momforce_base::operator<<(std::ostream& os) const {
  os << this;
  return os;
}

namespace dnvgl {
  namespace extfem {
    namespace bdf{
      namespace cards{

        bdf::types::card force::head = bdf::types::card("FORCE");

        const std::ostream& force::operator<< (std::ostream& os) const {
          return os << *this;
        }

        bdf::types::card moment::head = bdf::types::card("MOMENT");

        const std::ostream& moment::operator<< (std::ostream& os) const {
          return os << *this;
        }

        std::ostream& operator<<(std::ostream &os, const force &card) {

          std::deque<std::unique_ptr<format_entry>> entries;

          entries.push_back(format(force::head));

          card.add_collect(entries, card);

          os << card.format_outlist(entries) << std::endl;

          return os;
        }

        std::ostream& operator<<(std::ostream &os, const moment &card) {

          std::deque<std::unique_ptr<format_entry>> entries;

          entries.push_back(format(moment::head));

          card.add_collect(entries, card);

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
// compile-command: "make -C ../.. check -j 8"
// End:
