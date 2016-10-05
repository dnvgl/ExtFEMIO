/*
   #####     #    #     # #######   ###   ####### #     #   ###
  #     #   # #   #     #    #       #    #     # ##    #   ###
  #        #   #  #     #    #       #    #     # # #   #   ###
  #       #     # #     #    #       #    #     # #  #  #    #
  #       ####### #     #    #       #    #     # #   # #
  #     # #     # #     #    #       #    #     # #    ##   ###
   #####  #     #  #####     #      ###   ####### #     #   ###

   Automatically generated source file. Contact author if changes are
   required.
 */

/**
   \file test_fem_element_.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for reading and writing FEM  element information.

   Detailed description
*/

// ID:
namespace {
   const char cID_test_fem_elements[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#line 38 "/data/tmp/berhol/ExtFEMIO/tools/templates/test_fem_elements.cpp"

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
using namespace dnvgl::extfem::fem::cards;
using namespace dnvgl::extfem::fem::elements;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("Basic test", "[fem_elemsnts_basic]") {
   std::vector<long> nodes({ 6, 7 });
   gelmnt1 data1(1, 2, elements::el_types::TESS, nodes);

   SECTION("check values") {
      CHECK(data1.ELNOX == 1);
      CHECK(data1.ELNO == 2);
      CHECK(data1.ELTYP == elements::el_types::TESS);
      CHECK(data1.NODIN.size() == 2);
      CHECK(data1.NODIN[0] == 6);
      CHECK(data1.NODIN[1] == 7);
   }

   SECTION("check copy") {
      tess probe1(&data1);
      CHECK(probe1.get_type() == elements::el_types::TESS);
      CHECK(probe1.nnodes() == 2);
      CHECK(probe1.nodes.size() == 2);
      CHECK(probe1.nodes[0] == 6);
      CHECK(probe1.nodes[1] == 7);
   }

   SECTION("check downcast") {
      std::unique_ptr<elements::__base::elem> probe2;
      dispatch(probe2, &data1);
      CHECK(probe2->get_type() == elements::el_types::TESS);
      CHECK(static_cast<tess*>(probe2.get())->nnodes() == 2);
   }
}

TEST_CASE("FEM BEPS element definitions.", "[fem_element_beps]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::BEPS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   beps probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::ADVANCE }));
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

TEST_CASE("Output for BEPS elements.", "[fem_element_beps]") {

   std::stringstream test;

   beps probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      beps probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      beps probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CSTA element definitions.", "[fem_element_csta]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CSTA;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102});
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

   csta probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE }));
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

TEST_CASE("Output for CSTA elements.", "[fem_element_csta]") {

   std::stringstream test;

   csta probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102}), // nodin
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
      csta probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      csta probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM RPBQ element definitions.", "[fem_element_rpbq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::RPBQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   rpbq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for RPBQ elements.", "[fem_element_rpbq]") {

   std::stringstream test;

   rpbq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      rpbq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      rpbq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ILST element definitions.", "[fem_element_ilst]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::ILST;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   ilst probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for ILST elements.", "[fem_element_ilst]") {

   std::stringstream test;

   ilst probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      ilst probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ilst probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM IQQE element definitions.", "[fem_element_iqqe]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::IQQE;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   iqqe probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for IQQE elements.", "[fem_element_iqqe]") {

   std::stringstream test;

   iqqe probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      iqqe probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+8.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      iqqe probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+8.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LQUA element definitions.", "[fem_element_lqua]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::LQUA;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   lqua probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Poseidon }));
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

TEST_CASE("Output for LQUA elements.", "[fem_element_lqua]") {

   std::stringstream test;

   lqua probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      lqua probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+9.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      lqua probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+9.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TESS element definitions.", "[fem_element_tess]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::TESS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   tess probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Poseidon }));
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

TEST_CASE("Output for TESS elements.", "[fem_element_tess]") {

   std::stringstream test;

   tess probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      tess probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      tess probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GMAS element definitions.", "[fem_element_gmas]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GMAS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN (1, 100);
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

   gmas probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Poseidon }));
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

TEST_CASE("Output for GMAS elements.", "[fem_element_gmas]") {

   std::stringstream test;

   gmas probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>(1, 100), // nodin
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
      gmas probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      gmas probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>(1, 100), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GLMA element definitions.", "[fem_element_glma]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GLMA;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   glma probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GLMA elements.", "[fem_element_glma]") {

   std::stringstream test;

   glma probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      glma probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      glma probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GLDA element definitions.", "[fem_element_glda]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GLDA;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   glda probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for GLDA elements.", "[fem_element_glda]") {

   std::stringstream test;

   glda probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      glda probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      glda probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM BEAS element definitions.", "[fem_element_beas]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::BEAS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   beas probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework, el_processor::Launch, el_processor::Platework, el_processor::Pretube, el_processor::Wadam, el_processor::Poseidon }));
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

TEST_CASE("Output for BEAS elements.", "[fem_element_beas]") {

   std::stringstream test;

   beas probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      beas probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      beas probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXIS element definitions.", "[fem_element_axis]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::AXIS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   axis probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework, el_processor::Poseidon }));
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

TEST_CASE("Output for AXIS elements.", "[fem_element_axis]") {

   std::stringstream test;

   axis probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      axis probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      axis probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXDA element definitions.", "[fem_element_axda]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::AXDA;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   axda probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::Poseidon }));
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

TEST_CASE("Output for AXDA elements.", "[fem_element_axda]") {

   std::stringstream test;

   axda probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      axda probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      axda probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GSPR element definitions.", "[fem_element_gspr]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GSPR;
   long const ELTYAD = 2;
   std::vector<long> const NODIN (1, 100);
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

   gspr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework, el_processor::Poseidon }));
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

TEST_CASE("Output for GSPR elements.", "[fem_element_gspr]") {

   std::stringstream test;

   gspr probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>(1, 100), // nodin
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
      gspr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      gspr probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>(1, 100), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GDAM element definitions.", "[fem_element_gdam]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GDAM;
   long const ELTYAD = 2;
   std::vector<long> const NODIN (1, 100);
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

   gdam probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::Poseidon }));
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

TEST_CASE("Output for GDAM elements.", "[fem_element_gdam]") {

   std::stringstream test;

   gdam probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>(1, 100), // nodin
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
      gdam probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      gdam probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>(1, 100), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM IHEX element definitions.", "[fem_element_ihex]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::IHEX;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119});
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

   ihex probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework }));
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

TEST_CASE("Output for IHEX elements.", "[fem_element_ihex]") {

   std::stringstream test;

   ihex probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119}), // nodin
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
      ihex probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ihex probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LHEX element definitions.", "[fem_element_lhex]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::LHEX;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   lhex probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework }));
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

TEST_CASE("Output for LHEX elements.", "[fem_element_lhex]") {

   std::stringstream test;

   lhex probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      lhex probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      lhex probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SECB element definitions.", "[fem_element_secb]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::SECB;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102});
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

   secb probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for SECB elements.", "[fem_element_secb]") {

   std::stringstream test;

   secb probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102}), // nodin
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
      secb probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      secb probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM BTSS element definitions.", "[fem_element_btss]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::BTSS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102});
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

   btss probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework, el_processor::Pretube }));
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

TEST_CASE("Output for BTSS elements.", "[fem_element_btss]") {

   std::stringstream test;

   btss probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102}), // nodin
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
      btss probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      btss probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM FQUS_FFQ element definitions.", "[fem_element_fqus_ffq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::FQUS_FFQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   fqus_ffq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Platework, el_processor::Pretube, el_processor::Poseidon }));
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

TEST_CASE("Output for FQUS_FFQ elements.", "[fem_element_fqus_ffq]") {

   std::stringstream test;

   fqus_ffq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      fqus_ffq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      fqus_ffq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM FTRS_FFTR element definitions.", "[fem_element_ftrs_fftr]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::FTRS_FFTR;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102});
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

   ftrs_fftr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Platework, el_processor::Poseidon }));
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

TEST_CASE("Output for FTRS_FFTR elements.", "[fem_element_ftrs_fftr]") {

   std::stringstream test;

   ftrs_fftr probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102}), // nodin
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
      ftrs_fftr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ftrs_fftr probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SCTS element definitions.", "[fem_element_scts]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::SCTS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   scts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework }));
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

TEST_CASE("Output for SCTS elements.", "[fem_element_scts]") {

   std::stringstream test;

   scts probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      scts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      scts probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM MCTS element definitions.", "[fem_element_mcts]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::MCTS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   mcts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for MCTS elements.", "[fem_element_mcts]") {

   std::stringstream test;

   mcts probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      mcts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      mcts probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SCQS element definitions.", "[fem_element_scqs]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::SCQS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   scqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework, el_processor::Pretube }));
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

TEST_CASE("Output for SCQS elements.", "[fem_element_scqs]") {

   std::stringstream test;

   scqs probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      scqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      scqs probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM MCQS element definitions.", "[fem_element_mcqs]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::MCQS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   mcqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for MCQS elements.", "[fem_element_mcqs]") {

   std::stringstream test;

   mcqs probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      mcqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      mcqs probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+2.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM IPRI element definitions.", "[fem_element_ipri]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::IPRI;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114});
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

   ipri probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE }));
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

TEST_CASE("Output for IPRI elements.", "[fem_element_ipri]") {

   std::stringstream test;

   ipri probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114}), // nodin
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
      ipri probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ipri probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ITET element definitions.", "[fem_element_itet]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::ITET;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109});
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

   itet probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for ITET elements.", "[fem_element_itet]") {

   std::stringstream test;

   itet probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109}), // nodin
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
      itet probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      itet probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TPRI element definitions.", "[fem_element_tpri]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::TPRI;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   tpri probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework }));
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

TEST_CASE("Output for TPRI elements.", "[fem_element_tpri]") {

   std::stringstream test;

   tpri probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      tpri probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      tpri probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TETR element definitions.", "[fem_element_tetr]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::TETR;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   tetr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for TETR elements.", "[fem_element_tetr]") {

   std::stringstream test;

   tetr probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      tetr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      tetr probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LCTS element definitions.", "[fem_element_lcts]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::LCTS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   lcts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for LCTS elements.", "[fem_element_lcts]") {

   std::stringstream test;

   lcts probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      lcts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      lcts probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LCQS element definitions.", "[fem_element_lcqs]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::LCQS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   lcqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for LCQS elements.", "[fem_element_lcqs]") {

   std::stringstream test;

   lcqs probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      lcqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      lcqs probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TRS1 element definitions.", "[fem_element_trs1]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::TRS1;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117});
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

   trs1 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra, el_processor::Pretube }));
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

TEST_CASE("Output for TRS1 elements.", "[fem_element_trs1]") {

   std::stringstream test;

   trs1 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117}), // nodin
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
      trs1 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      trs1 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TRS2 element definitions.", "[fem_element_trs2]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::TRS2;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114});
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

   trs2 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra, el_processor::Pretube }));
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

TEST_CASE("Output for TRS2 elements.", "[fem_element_trs2]") {

   std::stringstream test;

   trs2 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114}), // nodin
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
      trs2 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      trs2 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TRS3 element definitions.", "[fem_element_trs3]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::TRS3;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111});
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

   trs3 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra, el_processor::Pretube }));
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

TEST_CASE("Output for TRS3 elements.", "[fem_element_trs3]") {

   std::stringstream test;

   trs3 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111}), // nodin
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
      trs3 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      trs3 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+3.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GLSH element definitions.", "[fem_element_glsh]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GLSH;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   glsh probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::Sestra, el_processor::Poseidon }));
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

TEST_CASE("Output for GLSH elements.", "[fem_element_glsh]") {

   std::stringstream test;

   glsh probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      glsh probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      glsh probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXCS element definitions.", "[fem_element_axcs]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::AXCS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102});
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

   axcs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE }));
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

TEST_CASE("Output for AXCS elements.", "[fem_element_axcs]") {

   std::stringstream test;

   axcs probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102}), // nodin
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
      axcs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      axcs probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXLQ element definitions.", "[fem_element_axlq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::AXLQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   axlq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE }));
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

TEST_CASE("Output for AXLQ elements.", "[fem_element_axlq]") {

   std::stringstream test;

   axlq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      axlq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      axlq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXLS element definitions.", "[fem_element_axls]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::AXLS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   axls probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for AXLS elements.", "[fem_element_axls]") {

   std::stringstream test;

   axls probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      axls probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      axls probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXQQ element definitions.", "[fem_element_axqq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::AXQQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   axqq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Sestra }));
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

TEST_CASE("Output for AXQQ elements.", "[fem_element_axqq]") {

   std::stringstream test;

   axqq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      axqq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      axqq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM PILS element definitions.", "[fem_element_pils]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::PILS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN (1, 100);
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

   pils probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::ADVANCE }));
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

TEST_CASE("Output for PILS elements.", "[fem_element_pils]") {

   std::stringstream test;

   pils probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>(1, 100), // nodin
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
      pils probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      pils probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>(1, 100), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM PCAB element definitions.", "[fem_element_pcab]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::PCAB;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   pcab probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::ADVANCE }));
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

TEST_CASE("Output for PCAB elements.", "[fem_element_pcab]") {

   std::stringstream test;

   pcab probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      pcab probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      pcab probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM PSPR element definitions.", "[fem_element_pspr]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::PSPR;
   long const ELTYAD = 2;
   std::vector<long> const NODIN (1, 100);
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

   pspr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Preframe, el_processor::ADVANCE }));
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

TEST_CASE("Output for PSPR elements.", "[fem_element_pspr]") {

   std::stringstream test;

   pspr probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>(1, 100), // nodin
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
      pspr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      pspr probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>(1, 100), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ADVA_4 element definitions.", "[fem_element_adva_4]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::ADVA_4;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   adva_4 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::ADVANCE }));
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

TEST_CASE("Output for ADVA_4 elements.", "[fem_element_adva_4]") {

   std::stringstream test;

   adva_4 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      adva_4 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      adva_4 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ADVA_2 element definitions.", "[fem_element_adva_2]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::ADVA_2;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   adva_2 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::ADVANCE }));
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

TEST_CASE("Output for ADVA_2 elements.", "[fem_element_adva_2]") {

   std::stringstream test;

   adva_2 probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      adva_2 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      adva_2 probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+4.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCP element definitions.", "[fem_element_ctcp]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTCP;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101});
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

   ctcp probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for CTCP elements.", "[fem_element_ctcp]") {

   std::stringstream test;

   ctcp probe(1,                         // elnox
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

   SECTION("simple (empty)") {
      ctcp probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctcp probe;
      test << probe(1,                         // elnox
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCL element definitions.", "[fem_element_ctcl]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTCL;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   ctcl probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for CTCL elements.", "[fem_element_ctcl]") {

   std::stringstream test;

   ctcl probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      ctcl probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctcl probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTAL element definitions.", "[fem_element_ctal]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTAL;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103});
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

   ctal probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for CTAL elements.", "[fem_element_ctal]") {

   std::stringstream test;

   ctal probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103}), // nodin
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
      ctal probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctal probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCC element definitions.", "[fem_element_ctcc]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTCC;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   ctcc probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for CTCC elements.", "[fem_element_ctcc]") {

   std::stringstream test;

   ctcc probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      ctcc probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctcc probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTAQ element definitions.", "[fem_element_ctaq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTAQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   ctaq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem }));
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

TEST_CASE("Output for CTAQ elements.", "[fem_element_ctaq]") {

   std::stringstream test;

   ctaq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      ctaq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctaq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTLQ element definitions.", "[fem_element_ctlq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTLQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   ctlq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Pretube }));
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

TEST_CASE("Output for CTLQ elements.", "[fem_element_ctlq]") {

   std::stringstream test;

   ctlq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      ctlq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctlq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCQ element definitions.", "[fem_element_ctcq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTCQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115});
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

   ctcq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Pretube }));
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

TEST_CASE("Output for CTCQ elements.", "[fem_element_ctcq]") {

   std::stringstream test;

   ctcq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115}), // nodin
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
      ctcq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctcq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTMQ element definitions.", "[fem_element_ctmq]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::CTMQ;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117});
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

   ctmq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Pretube }));
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

TEST_CASE("Output for CTMQ elements.", "[fem_element_ctmq]") {

   std::stringstream test;

   ctmq probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117}), // nodin
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
      ctmq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ctmq probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+5.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM HCQS element definitions.", "[fem_element_hcqs]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::HCQS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108});
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

   hcqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Prefem, el_processor::Pretube }));
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

TEST_CASE("Output for HCQS elements.", "[fem_element_hcqs]") {

   std::stringstream test;

   hcqs probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108}), // nodin
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
      hcqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      hcqs probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SLQS element definitions.", "[fem_element_slqs]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::SLQS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107});
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

   slqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for SLQS elements.", "[fem_element_slqs]") {

   std::stringstream test;

   slqs probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      slqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      slqs probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SLTS element definitions.", "[fem_element_slts]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::SLTS;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105});
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

   slts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for SLTS elements.", "[fem_element_slts]") {

   std::stringstream test;

   slts probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      slts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      slts probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SLCB element definitions.", "[fem_element_slcb]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::SLCB;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102});
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

   slcb probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general }));
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

TEST_CASE("Output for SLCB elements.", "[fem_element_slcb]") {

   std::stringstream test;

   slcb probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102}), // nodin
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
      slcb probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      slcb probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+6.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM MATR element definitions.", "[fem_element_matr]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::MATR;
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
               el_processor::general, el_processor::ADVANCE, el_processor::Splice }));
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

   SECTION("reuse (check output)") {
      matr probe;
      test << probe(1,                         // elnox
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

TEST_CASE("FEM GHEX100 element definitions.", "[fem_element_ghex100]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX100;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120});
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

   ghex100 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX100 elements.", "[fem_element_ghex100]") {

   std::stringstream test;

   ghex100 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120}), // nodin
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
      ghex100 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.000000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex100 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.000000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX101 element definitions.", "[fem_element_ghex101]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX101;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121});
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

   ghex101 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX101 elements.", "[fem_element_ghex101]") {

   std::stringstream test;

   ghex101 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      ghex101 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.010000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex101 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.010000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX102 element definitions.", "[fem_element_ghex102]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX102;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121});
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

   ghex102 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX102 elements.", "[fem_element_ghex102]") {

   std::stringstream test;

   ghex102 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      ghex102 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.020000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex102 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.020000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX103 element definitions.", "[fem_element_ghex103]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX103;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex103 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX103 elements.", "[fem_element_ghex103]") {

   std::stringstream test;

   ghex103 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex103 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.030000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex103 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.030000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX104 element definitions.", "[fem_element_ghex104]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX104;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121});
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

   ghex104 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX104 elements.", "[fem_element_ghex104]") {

   std::stringstream test;

   ghex104 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      ghex104 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.040000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex104 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.040000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX105 element definitions.", "[fem_element_ghex105]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX105;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex105 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX105 elements.", "[fem_element_ghex105]") {

   std::stringstream test;

   ghex105 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex105 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.050000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex105 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.050000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX106 element definitions.", "[fem_element_ghex106]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX106;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex106 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX106 elements.", "[fem_element_ghex106]") {

   std::stringstream test;

   ghex106 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex106 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.060000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex106 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.060000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX107 element definitions.", "[fem_element_ghex107]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX107;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex107 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX107 elements.", "[fem_element_ghex107]") {

   std::stringstream test;

   ghex107 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex107 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.070000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex107 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.070000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX108 element definitions.", "[fem_element_ghex108]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX108;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121});
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

   ghex108 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX108 elements.", "[fem_element_ghex108]") {

   std::stringstream test;

   ghex108 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      ghex108 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.080000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex108 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.080000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX109 element definitions.", "[fem_element_ghex109]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX109;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex109 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX109 elements.", "[fem_element_ghex109]") {

   std::stringstream test;

   ghex109 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex109 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.090000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex109 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.090000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX110 element definitions.", "[fem_element_ghex110]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX110;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex110 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX110 elements.", "[fem_element_ghex110]") {

   std::stringstream test;

   ghex110 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex110 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.100000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex110 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.100000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX111 element definitions.", "[fem_element_ghex111]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX111;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex111 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX111 elements.", "[fem_element_ghex111]") {

   std::stringstream test;

   ghex111 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex111 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.110000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex111 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.110000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX112 element definitions.", "[fem_element_ghex112]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX112;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex112 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX112 elements.", "[fem_element_ghex112]") {

   std::stringstream test;

   ghex112 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex112 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.120000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex112 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.120000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX113 element definitions.", "[fem_element_ghex113]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX113;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex113 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX113 elements.", "[fem_element_ghex113]") {

   std::stringstream test;

   ghex113 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex113 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.130000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex113 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.130000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX114 element definitions.", "[fem_element_ghex114]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX114;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex114 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX114 elements.", "[fem_element_ghex114]") {

   std::stringstream test;

   ghex114 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex114 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.140000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex114 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.140000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX115 element definitions.", "[fem_element_ghex115]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX115;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex115 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX115 elements.", "[fem_element_ghex115]") {

   std::stringstream test;

   ghex115 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex115 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.150000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex115 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.150000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX116 element definitions.", "[fem_element_ghex116]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX116;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121});
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

   ghex116 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX116 elements.", "[fem_element_ghex116]") {

   std::stringstream test;

   ghex116 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      ghex116 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.160000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex116 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.160000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX117 element definitions.", "[fem_element_ghex117]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX117;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex117 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX117 elements.", "[fem_element_ghex117]") {

   std::stringstream test;

   ghex117 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex117 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.170000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex117 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.170000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX118 element definitions.", "[fem_element_ghex118]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX118;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex118 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX118 elements.", "[fem_element_ghex118]") {

   std::stringstream test;

   ghex118 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex118 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.180000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex118 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.180000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX119 element definitions.", "[fem_element_ghex119]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX119;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex119 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX119 elements.", "[fem_element_ghex119]") {

   std::stringstream test;

   ghex119 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex119 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.190000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex119 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.190000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX120 element definitions.", "[fem_element_ghex120]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX120;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex120 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX120 elements.", "[fem_element_ghex120]") {

   std::stringstream test;

   ghex120 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex120 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.200000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex120 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.200000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX121 element definitions.", "[fem_element_ghex121]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX121;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex121 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX121 elements.", "[fem_element_ghex121]") {

   std::stringstream test;

   ghex121 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex121 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.210000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex121 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.210000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX122 element definitions.", "[fem_element_ghex122]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX122;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex122 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX122 elements.", "[fem_element_ghex122]") {

   std::stringstream test;

   ghex122 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex122 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.220000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex122 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.220000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX123 element definitions.", "[fem_element_ghex123]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX123;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex123 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX123 elements.", "[fem_element_ghex123]") {

   std::stringstream test;

   ghex123 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex123 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.230000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex123 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.230000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX124 element definitions.", "[fem_element_ghex124]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX124;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex124 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX124 elements.", "[fem_element_ghex124]") {

   std::stringstream test;

   ghex124 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex124 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.240000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex124 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.240000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX125 element definitions.", "[fem_element_ghex125]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX125;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex125 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX125 elements.", "[fem_element_ghex125]") {

   std::stringstream test;

   ghex125 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex125 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.250000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex125 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.250000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX126 element definitions.", "[fem_element_ghex126]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX126;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex126 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX126 elements.", "[fem_element_ghex126]") {

   std::stringstream test;

   ghex126 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex126 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.260000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex126 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.260000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX127 element definitions.", "[fem_element_ghex127]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX127;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex127 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX127 elements.", "[fem_element_ghex127]") {

   std::stringstream test;

   ghex127 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex127 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.270000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex127 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.270000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX128 element definitions.", "[fem_element_ghex128]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX128;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex128 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX128 elements.", "[fem_element_ghex128]") {

   std::stringstream test;

   ghex128 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex128 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.280000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex128 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.280000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX129 element definitions.", "[fem_element_ghex129]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX129;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex129 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX129 elements.", "[fem_element_ghex129]") {

   std::stringstream test;

   ghex129 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex129 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.290000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex129 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.290000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX130 element definitions.", "[fem_element_ghex130]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX130;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex130 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX130 elements.", "[fem_element_ghex130]") {

   std::stringstream test;

   ghex130 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex130 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.300000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex130 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.300000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX131 element definitions.", "[fem_element_ghex131]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX131;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125});
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

   ghex131 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX131 elements.", "[fem_element_ghex131]") {

   std::stringstream test;

   ghex131 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      ghex131 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.310000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex131 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.310000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX132 element definitions.", "[fem_element_ghex132]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX132;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121});
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

   ghex132 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX132 elements.", "[fem_element_ghex132]") {

   std::stringstream test;

   ghex132 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      ghex132 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.320000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex132 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.320000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX133 element definitions.", "[fem_element_ghex133]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX133;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex133 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX133 elements.", "[fem_element_ghex133]") {

   std::stringstream test;

   ghex133 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex133 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.330000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex133 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.330000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX134 element definitions.", "[fem_element_ghex134]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX134;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex134 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX134 elements.", "[fem_element_ghex134]") {

   std::stringstream test;

   ghex134 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex134 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.340000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex134 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.340000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX135 element definitions.", "[fem_element_ghex135]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX135;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex135 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX135 elements.", "[fem_element_ghex135]") {

   std::stringstream test;

   ghex135 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex135 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.350000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex135 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.350000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX136 element definitions.", "[fem_element_ghex136]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX136;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex136 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX136 elements.", "[fem_element_ghex136]") {

   std::stringstream test;

   ghex136 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex136 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.360000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex136 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.360000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX137 element definitions.", "[fem_element_ghex137]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX137;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex137 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX137 elements.", "[fem_element_ghex137]") {

   std::stringstream test;

   ghex137 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex137 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.370000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex137 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.370000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX138 element definitions.", "[fem_element_ghex138]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX138;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex138 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX138 elements.", "[fem_element_ghex138]") {

   std::stringstream test;

   ghex138 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex138 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.380000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex138 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.380000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX139 element definitions.", "[fem_element_ghex139]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX139;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex139 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX139 elements.", "[fem_element_ghex139]") {

   std::stringstream test;

   ghex139 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex139 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.390000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex139 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.390000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX140 element definitions.", "[fem_element_ghex140]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX140;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex140 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX140 elements.", "[fem_element_ghex140]") {

   std::stringstream test;

   ghex140 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex140 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.400000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex140 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.400000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX141 element definitions.", "[fem_element_ghex141]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX141;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex141 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX141 elements.", "[fem_element_ghex141]") {

   std::stringstream test;

   ghex141 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex141 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.410000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex141 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.410000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX142 element definitions.", "[fem_element_ghex142]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX142;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex142 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX142 elements.", "[fem_element_ghex142]") {

   std::stringstream test;

   ghex142 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex142 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.420000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex142 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.420000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX143 element definitions.", "[fem_element_ghex143]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX143;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex143 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX143 elements.", "[fem_element_ghex143]") {

   std::stringstream test;

   ghex143 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex143 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.430000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex143 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.430000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX144 element definitions.", "[fem_element_ghex144]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX144;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex144 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX144 elements.", "[fem_element_ghex144]") {

   std::stringstream test;

   ghex144 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex144 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.440000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex144 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.440000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX145 element definitions.", "[fem_element_ghex145]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX145;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex145 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX145 elements.", "[fem_element_ghex145]") {

   std::stringstream test;

   ghex145 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex145 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.450000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex145 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.450000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX146 element definitions.", "[fem_element_ghex146]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX146;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex146 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX146 elements.", "[fem_element_ghex146]") {

   std::stringstream test;

   ghex146 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex146 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.460000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex146 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.460000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX147 element definitions.", "[fem_element_ghex147]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX147;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125});
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

   ghex147 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX147 elements.", "[fem_element_ghex147]") {

   std::stringstream test;

   ghex147 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      ghex147 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.470000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex147 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.470000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX148 element definitions.", "[fem_element_ghex148]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX148;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122});
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

   ghex148 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX148 elements.", "[fem_element_ghex148]") {

   std::stringstream test;

   ghex148 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      ghex148 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.480000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex148 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.480000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX149 element definitions.", "[fem_element_ghex149]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX149;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex149 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX149 elements.", "[fem_element_ghex149]") {

   std::stringstream test;

   ghex149 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex149 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.490000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex149 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.490000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX150 element definitions.", "[fem_element_ghex150]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX150;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex150 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX150 elements.", "[fem_element_ghex150]") {

   std::stringstream test;

   ghex150 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex150 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.500000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex150 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.500000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX151 element definitions.", "[fem_element_ghex151]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX151;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex151 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX151 elements.", "[fem_element_ghex151]") {

   std::stringstream test;

   ghex151 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex151 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.510000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex151 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.510000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX152 element definitions.", "[fem_element_ghex152]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX152;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex152 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX152 elements.", "[fem_element_ghex152]") {

   std::stringstream test;

   ghex152 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex152 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.520000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex152 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.520000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX153 element definitions.", "[fem_element_ghex153]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX153;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex153 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX153 elements.", "[fem_element_ghex153]") {

   std::stringstream test;

   ghex153 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex153 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.530000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex153 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.530000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX154 element definitions.", "[fem_element_ghex154]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX154;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex154 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX154 elements.", "[fem_element_ghex154]") {

   std::stringstream test;

   ghex154 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex154 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.540000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex154 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.540000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX155 element definitions.", "[fem_element_ghex155]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX155;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125});
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

   ghex155 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX155 elements.", "[fem_element_ghex155]") {

   std::stringstream test;

   ghex155 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      ghex155 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.550000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex155 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.550000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX156 element definitions.", "[fem_element_ghex156]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX156;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123});
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

   ghex156 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX156 elements.", "[fem_element_ghex156]") {

   std::stringstream test;

   ghex156 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      ghex156 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.560000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex156 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.560000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX157 element definitions.", "[fem_element_ghex157]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX157;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex157 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX157 elements.", "[fem_element_ghex157]") {

   std::stringstream test;

   ghex157 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex157 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.570000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex157 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.570000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX158 element definitions.", "[fem_element_ghex158]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX158;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex158 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX158 elements.", "[fem_element_ghex158]") {

   std::stringstream test;

   ghex158 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex158 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.580000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex158 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.580000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX159 element definitions.", "[fem_element_ghex159]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX159;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125});
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

   ghex159 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX159 elements.", "[fem_element_ghex159]") {

   std::stringstream test;

   ghex159 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      ghex159 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.590000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex159 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.590000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX160 element definitions.", "[fem_element_ghex160]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX160;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124});
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

   ghex160 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX160 elements.", "[fem_element_ghex160]") {

   std::stringstream test;

   ghex160 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      ghex160 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.600000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex160 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.600000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX161 element definitions.", "[fem_element_ghex161]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX161;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125});
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

   ghex161 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX161 elements.", "[fem_element_ghex161]") {

   std::stringstream test;

   ghex161 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      ghex161 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.610000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex161 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.610000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX162 element definitions.", "[fem_element_ghex162]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX162;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125});
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

   ghex162 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX162 elements.", "[fem_element_ghex162]") {

   std::stringstream test;

   ghex162 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      ghex162 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.620000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex162 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.620000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX163 element definitions.", "[fem_element_ghex163]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = elements::el_types::GHEX163;
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126});
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

   ghex163 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               el_processor::general, el_processor::Sestra }));
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

TEST_CASE("Output for GHEX163 elements.", "[fem_element_ghex163]") {

   std::stringstream test;

   ghex163 probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126}), // nodin
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
      ghex163 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.630000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02+1.260000000e+02\n"
            "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      ghex163 probe;
      test << probe(1,                         // elnox
                    2,                         // elno
                    3,                         // eltyad
                    std::vector<long>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126}), // nodin
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
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+2.000000000e+00+1.630000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02+1.260000000e+02\n"
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End: