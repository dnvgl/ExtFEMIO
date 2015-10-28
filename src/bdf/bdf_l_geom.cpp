// Copyright © 2015 by DNV GL SE

// Purpose: Basic code for geometry describing beam property cards for
//          BDF file format (PBEAML, PBARL)

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

#include <cstdlib>
#include <memory>

#ifdef _TYPE
#undef _TYPE
#endif

using namespace bdf::cards;

namespace {
  static const size_t dimnum1_len = 1;
  static const size_t dimnum2_len = 2;
  static const size_t dimnum3_len = 1;
  static const size_t dimnum4_len = 13;
  static const size_t dimnum5_len = 1;
  static const size_t dimnum6_len = 2;
  static const size_t dimnum10_len = 1;

  const char *dimnum1_init[dimnum1_len] = {"ROD"};
  const char *dimnum2_init[dimnum2_len] = {"TUBE", "BAR"};
  const char *dimnum3_init[dimnum3_len] = {"HEXA"};
  const char *dimnum4_init[dimnum4_len] = {
    "L", "CHAN", "T", "BOX", "CROSS", "H", "T1", "I1", "CHAN1", "Z",
    "CHAN2", "T2", "HAT"};
  const char *dimnum5_init[dimnum5_len] = {"HAT1"};
  const char *dimnum6_init[dimnum6_len] = {"I", "BOX1"};
  const char *dimnum10_init[dimnum10_len] = {"DBOX"};

  const std::set<std::string> dimnum1_set(dimnum1_init, dimnum1_init + dimnum1_len);
  const std::set<std::string> dimnum2_set(dimnum2_init, dimnum2_init + dimnum2_len);
  const std::set<std::string> dimnum3_set(dimnum3_init, dimnum3_init + dimnum3_len);
  const std::set<std::string> dimnum4_set(dimnum4_init, dimnum4_init + dimnum4_len);
  const std::set<std::string> dimnum5_set(dimnum5_init, dimnum5_init + dimnum5_len);
  const std::set<std::string> dimnum6_set(dimnum6_init, dimnum6_init + dimnum6_len);
  const std::set<std::string> dimnum10_set(dimnum10_init, dimnum10_init + dimnum10_len);
}
const std::set<std::string> l_geom::dimnum1(dimnum1_set);
const std::set<std::string> l_geom::dimnum2(dimnum2_set);
const std::set<std::string> l_geom::dimnum3(dimnum3_set);
const std::set<std::string> l_geom::dimnum4(dimnum4_set);
const std::set<std::string> l_geom::dimnum5(dimnum5_set);
const std::set<std::string> l_geom::dimnum6(dimnum6_set);
const std::set<std::string> l_geom::dimnum10(dimnum10_set);

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
