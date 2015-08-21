// Copyright © 2015 by DNV GL SE

// Purpose: Defintions for Patran CBAR cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_cards.h"

#include "bdf_cards.h"
#include "bdf_types.h"
#include "bdf_errors.h"

using namespace ::std;
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;
using namespace ::bdf::type_bounds;

bdf_int cbar::_EID("EID",
                    num<long>(make_unique<long>(1).get()));
bdf_int cbar::_PID("PID");
bdf_int cbar::_GA("GA");
bdf_int cbar::_GB("GB");
bdf_float cbar::_X1("X1");
bdf_int cbar::_G0(
  "G0", num<long>(make_unique<long>(1).get()));
bdf_float cbar::_X2(
  "X2", num<double>(nullptr, nullptr, nullptr, true));
bdf_float cbar::_X3(
  "X3", num<double>(nullptr, nullptr, nullptr, true));
namespace {
  const char* initVals[8] = {
    "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO" };
  const ::std::set<::std::string> OFFT_set(initVals, initVals + 8);
}
bdf_str cbar::_OFFT("OFFT", str(OFFT_set, "GGG"));

bdf_list<int> cbar::_PA("PA"); // maxelem=5, minval=1, maxval=6, uniq=True);
bdf_list<int> cbar::_PB("PB"); // maxelem=5, minval=1, maxval=6, uniq=True);
bdf_float cbar::_W1A(
  "W1A",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
bdf_float cbar::_W2A(
  "W2A",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
bdf_float cbar::_W3A(
  "W3A",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
bdf_float cbar::_W1B(
  "W1B",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
bdf_float cbar::_W2B(
  "W2B",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
bdf_float cbar::_W3B(
  "W3B",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),

cbar::cbar(const ::std::deque<::std::string> &inp) :
  bdf_card(inp) {
/*
  typedef enum {has_DVEC, has_DCODE} CHOOSE_DIR_CODE;
  CHOOSE_DIR_CODE choose_dir_code;
*/

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  double *dval;


  W3B = nullptr;
  W2B = nullptr;
  W1B = nullptr;
  W3A = nullptr;
  W2A = nullptr;
  W1A = nullptr;
  PB = nullptr;
  PA = nullptr;
  OFFT = nullptr;

  switch (inp.size()-1) {
  case 16:
    W3B = make_unique<double>(*_W3B(*pos));
    ++pos;
  case 15:
    W2B = make_unique<double>(*_W2B(*pos));
    ++pos;
  case 14:
    W1B = make_unique<double>(*_W1B(*pos));
    ++pos;
  case 13:
    W3A = make_unique<double>(*_W3A(*pos));
    ++pos;
  case 12:
    W2A = make_unique<double>(*_W2A(*pos));
    ++pos;
  case 11:
    W1A = make_unique<double>(*_W1A(*pos));
    ++pos;
  case 10:
    PB = make_unique<deque<int>>(*_PB(*pos));
    ++pos;
  case 9:
    PA = make_unique<deque<int>>(*_PA(*pos));
    ++pos;
  case 8:
    OFFT = make_unique<::std::string>(*_OFFT(*pos));
    ++pos;
  case 7:
    dval = _X3(*pos);
    if (!dval)
      X3 = nullptr;
    else
      X3 = make_unique<double>(*dval);
    ++pos;
  case 6:
    dval = _X2(*pos);
    if (!dval)
      X2 = nullptr;
    else
      X2 = make_unique<double>(*dval);
    ++pos;
  case 5:
    /*
      typedef enum {has_DVEC, has_DCODE} CHOOSE_DIR_CODE;
      CHOOSE_DIR_CODE choose_dir_code;
    */
    try {
      X1 = make_unique<double>(*_X1(*pos));
      if (!X2 || !X3) {
        throw bdf_parse_error(
          "CBAR", "Incomplete direction vector.");
      }
      G0 = nullptr;
      choose_dir_code = has_DVEC;
    }
    catch (bdf_float_error) {
      G0 = make_unique<long>(*_G0(*pos));
      X1 = nullptr;
      choose_dir_code = has_DCODE;
    }
    ++pos;
    GB = make_unique<long>(*_GB(*pos));
    ++pos;
    GA = make_unique<long>(*_GA(*pos));
    ++pos;
    PID = make_unique<long>(*_PID(*pos));
    ++pos;
    EID = make_unique<long>(*_EID(*pos));
    break;
  default:
    throw bdf_parse_error(
      "CBAR", "Illegal number of entries for CBAR");
  }
};


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
