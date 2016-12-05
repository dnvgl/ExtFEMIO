/**
   \file test_fem_more_element.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for reading and writing FEM  element information.

   Detailed description
*/

// ID:
namespace {
   const char cID_test_fem_more_elements[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

#include <iostream>
#include <deque>
#include <memory>

#include <catch.hpp>

#include "config.h"

#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("Output for various elements.", "[fem_element]") {

   elements::__base::elem::reset();

   std::stringstream test;

   elements::beps beps;
   elements::fqus_ffq fqus;
   elements::ftrs_fftr ftrs;


   SECTION("simple") {
      test << beps << fqus << ftrs;
      test << beps(1,                         // elnox
                   2,                         // elno
                   3,                         // eltyad
                   std::vector<long>({100, 101}), // nodin
                   6,                         // matno
                   7,                         // addno
                   8,                         // intno
                   9,                         // mintno
                   10,                        // strano
                   11,                        // streno
                   12,                        // strepono
                   std::vector<long>(1, 13),  // geono_opt
                   std::vector<long>(1, 14),  // fixno_opt
                   std::vector<long>(1, 15),  // eccno_opt
                   std::vector<long>(1, 16)); // transno_opt
      test << beps(std::vector<long>({101, 102}), 7, std::vector<long>(1, 8));
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"
            "GELMNT1 +2.000000000e+00+1.000000000e+00+2.000000000e+00+0.000000000e+00\n"
            "        +1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.000000000e+00+7.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +8.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
