/**
   \file test_fem_element_matr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for reading and writing FEM MATR element information.

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

#include <limits>

#include <iostream>
#include <deque>
#include <memory>

#include <catch.hpp>

#include <config.h>

#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::elements;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM MATR element definitions.", "[fem_element_matr]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = MATR;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169});
   std::unique_ptr<cards::gelmnt1> gelmnt1_data(
      new cards::gelmnt1(
         ELNOX, ELNO, ELTYP, ELTYAD, NODIN));


   long const MATNO = 3;
   long const ADDNO = 4;
   long const INTNO = 5;
   long const MINTNO = 6;
   long const STRANO = 7;
   long const STRENO = 8;
   long const STREPONO = 9;
   long const GEONO_OPT = 10;
   long const FIXNO_OPT = 11;
   long const ECCNO_OPT = 12;
   long const TRANSNO_OPT = 13;

   std::unique_ptr<cards::gelref1> gelref1_data(
      new cards::gelref1(ELNO, MATNO, ADDNO, INTNO, MINTNO,
                         STRANO, STRENO, STREPONO, GEONO_OPT,
                         FIXNO_OPT, ECCNO_OPT, TRANSNO_OPT));

   matr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               general, ADVANCE, Splice }));
      CHECK(probe.eleno == ELNOX);
      CHECK(probe.elident == ELNO);
      CHECK(probe.el_add == ELTYAD);
      CHECK(probe.nodes == NODIN);
      CHECK(probe.matref == MATNO);
      CHECK(probe.add_no == ADDNO);
      CHECK(probe.intno == INTNO);
      CHECK(probe.mass_intno == MINTNO);
      CHECK(probe.i_strain_ref == STRANO);
      CHECK(probe.i_stress_ref == STRENO);
      CHECK(probe.strpoint_ref == STREPONO);
      CHECK(probe.section == std::vector<long>(1, GEONO_OPT));
      CHECK(probe.fixations == std::vector<long>(1, FIXNO_OPT));
      CHECK(probe.eccentrities == std::vector<long>(1, ECCNO_OPT));
      CHECK(probe.csys == std::vector<long>(1, TRANSNO_OPT));
   }
}

TEST_CASE("Output for MATR elements.", "[fem_element_matr]") {

   std::stringstream test;

   matr probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169}), // nodin
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

   SECTION("simple (empty)") {
      matr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+7.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02+1.260000000e+02+1.270000000e+02\n"
            "        +1.280000000e+02+1.290000000e+02+1.300000000e+02+1.310000000e+02\n"
            "        +1.320000000e+02+1.330000000e+02+1.340000000e+02+1.350000000e+02\n"
            "        +1.360000000e+02+1.370000000e+02+1.380000000e+02+1.390000000e+02\n"
            "        +1.400000000e+02+1.410000000e+02+1.420000000e+02+1.430000000e+02\n"
            "        +1.440000000e+02+1.450000000e+02+1.460000000e+02+1.470000000e+02\n"
            "        +1.480000000e+02+1.490000000e+02+1.500000000e+02+1.510000000e+02\n"
            "        +1.520000000e+02+1.530000000e+02+1.540000000e+02+1.550000000e+02\n"
            "        +1.560000000e+02+1.570000000e+02+1.580000000e+02+1.590000000e+02\n"
            "        +1.600000000e+02+1.610000000e+02+1.620000000e+02+1.630000000e+02\n"
            "        +1.640000000e+02+1.650000000e+02+1.660000000e+02+1.670000000e+02\n"
            "        +1.680000000e+02+1.690000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End: