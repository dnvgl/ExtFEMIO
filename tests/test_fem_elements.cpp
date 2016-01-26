/**
   \file test_fem_elements.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for Sesam FEM element representing classes.

   Detailed description
*/

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "fem/elements.h"

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;
using namespace ::dnvgl::extfem::fem::elements;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("Basic test", "[fem_elemsnts_basic]") {
   /*
   DllExport gelmnt1(
      const long &ELNOX, const long &ELNO,
      const el_types &ELTYP, const long &ELTYAD,
      const ::std::deque<long> &NODIN);
   */
   ::std::deque<long> nodes;
   nodes.push_back(6);
   nodes.push_back(7);
   gelmnt1 data1(1, 2, elements::TESS, nodes);
   CHECK(data1.ELNOX == 1);
   CHECK(data1.ELNO == 2);
   CHECK(data1.ELTYP == elements::TESS);
   CHECK(data1.NODIN.size() == 2);
   CHECK(data1.NODIN[0] == 6);
   CHECK(data1.NODIN[1] == 7);

   tess probe1(&data1);
   CHECK(probe1.get_type() == elements::TESS);
   CHECK(probe1.nnodes == 2);
   CHECK(probe1.nodes.size() == 2);
   CHECK(probe1.nodes[0] == 6);
   CHECK(probe1.nodes[1] == 7);

   ::std::unique_ptr<__base> probe2;
   dispatch(probe2, &data1);
   CHECK(probe2->get_type() == TESS);
   CHECK(static_cast<tess*>(probe2.get())->nnodes == 2);
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
