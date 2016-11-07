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

TEST_CASE("Basic test", "[fem_elemsnts_basic]") {
   elements::__base::elem::reset();
   std::vector<long> nodes({ 6, 7 });
   cards::gelmnt1 data1(19999, 29999, elements::el_types::TESS, nodes);

   SECTION("check values") {
      CHECK(data1.ELNOX == 19999);
      CHECK(data1.ELNO == 29999);
      CHECK(data1.ELTYP == elements::el_types::TESS);
      CHECK(data1.NODIN.size() == 2);
      CHECK(data1.NODIN[0] == 6);
      CHECK(data1.NODIN[1] == 7);
   }

   SECTION("check copy") {
      elements::tess probe1(&data1);
      CHECK(probe1.get_type() == elements::el_types::TESS);
      CHECK(probe1.nnodes() == 2);
      CHECK(probe1.nodes.size() == 2);
      CHECK(probe1.nodes[0] == 6);
      CHECK(probe1.nodes[1] == 7);
   }

   SECTION("check downcast") {
      elements::__base::elem::reset();
      std::unique_ptr<elements::__base::elem> probe2;
      elements::dispatch(probe2, &data1);
      CHECK(probe2->get_type() == elements::el_types::TESS);
      CHECK(static_cast<elements::tess*>(probe2.get())->nnodes() == 2);
   }
}

TEST_CASE("Mapping of element types to names.", "[fem_element]") {
    
    SECTION("INVALID") {
        CHECK(name_elem(elements::el_types::INVALID) == "INVALID");
    }

    SECTION("UNDEFINED") {
        CHECK(name_elem(elements::el_types::UNDEFINED) == "UNDEFINED");
    }
}

TEST_CASE("FEM BEPS element definitions.", "[fem_element_beps]") {

   long const ELNOX = 1;
   long const ELNO = 2;
   elements::el_types const ELTYP = elements::el_types::BEPS;
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

   elements::beps probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::beps probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::beps probe(3,                         // elnox
              4,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.000000000e+00+4.000000000e+00+2.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +4.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::beps probe;
      test << probe(7,                         // elnox
                    7,                         // elno
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
            "GELMNT1 +7.000000000e+00+7.000000000e+00+2.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +7.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CSTA element definitions.", "[fem_element_csta]") {

   long const ELNOX = 8;
   long const ELNO = 9;
   elements::el_types const ELTYP = elements::el_types::CSTA;
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

   elements::csta probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::csta probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::csta probe(10,                         // elnox
              11,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+01+1.100000000e+01+3.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.100000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::csta probe;
      test << probe(14,                         // elnox
                    14,                         // elno
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
            "GELMNT1 +1.400000000e+01+1.400000000e+01+3.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.400000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM RPBQ element definitions.", "[fem_element_rpbq]") {

   long const ELNOX = 15;
   long const ELNO = 16;
   elements::el_types const ELTYP = elements::el_types::RPBQ;
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

   elements::rpbq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::rpbq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::rpbq probe(17,                         // elnox
              18,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.700000000e+01+1.800000000e+01+5.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +1.800000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::rpbq probe;
      test << probe(21,                         // elnox
                    21,                         // elno
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
            "GELMNT1 +2.100000000e+01+2.100000000e+01+5.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.100000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ILST element definitions.", "[fem_element_ilst]") {

   long const ELNOX = 22;
   long const ELNO = 23;
   elements::el_types const ELTYP = elements::el_types::ILST;
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

   elements::ilst probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ilst probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ilst probe(24,                         // elnox
              25,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.400000000e+01+2.500000000e+01+6.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.500000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ilst probe;
      test << probe(28,                         // elnox
                    28,                         // elno
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
            "GELMNT1 +2.800000000e+01+2.800000000e+01+6.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.800000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM IQQE element definitions.", "[fem_element_iqqe]") {

   long const ELNOX = 29;
   long const ELNO = 30;
   elements::el_types const ELTYP = elements::el_types::IQQE;
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

   elements::iqqe probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::iqqe probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::iqqe probe(31,                         // elnox
              32,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.100000000e+01+3.200000000e+01+8.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +3.200000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::iqqe probe;
      test << probe(35,                         // elnox
                    35,                         // elno
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
            "GELMNT1 +3.500000000e+01+3.500000000e+01+8.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +3.500000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LQUA element definitions.", "[fem_element_lqua]") {

   long const ELNOX = 36;
   long const ELNO = 37;
   elements::el_types const ELTYP = elements::el_types::LQUA;
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

   elements::lqua probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::lqua probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::lqua probe(38,                         // elnox
              39,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.800000000e+01+3.900000000e+01+9.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +3.900000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::lqua probe;
      test << probe(42,                         // elnox
                    42,                         // elno
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
            "GELMNT1 +4.200000000e+01+4.200000000e+01+9.000000000e+00+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +4.200000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TESS element definitions.", "[fem_element_tess]") {

   long const ELNOX = 43;
   long const ELNO = 44;
   elements::el_types const ELTYP = elements::el_types::TESS;
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

   elements::tess probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::tess probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::tess probe(45,                         // elnox
              46,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.500000000e+01+4.600000000e+01+1.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +4.600000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::tess probe;
      test << probe(49,                         // elnox
                    49,                         // elno
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
            "GELMNT1 +4.900000000e+01+4.900000000e+01+1.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +4.900000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GMAS element definitions.", "[fem_element_gmas]") {

   long const ELNOX = 50;
   long const ELNO = 51;
   elements::el_types const ELTYP = elements::el_types::GMAS;
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

   elements::gmas probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::gmas probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::gmas probe(52,                         // elnox
              53,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.200000000e+01+5.300000000e+01+1.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +5.300000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::gmas probe;
      test << probe(56,                         // elnox
                    56,                         // elno
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
            "GELMNT1 +5.600000000e+01+5.600000000e+01+1.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +5.600000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GLMA element definitions.", "[fem_element_glma]") {

   long const ELNOX = 57;
   long const ELNO = 58;
   elements::el_types const ELTYP = elements::el_types::GLMA;
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

   elements::glma probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::glma probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::glma probe(59,                         // elnox
              60,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.900000000e+01+6.000000000e+01+1.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +6.000000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::glma probe;
      test << probe(63,                         // elnox
                    63,                         // elno
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
            "GELMNT1 +6.300000000e+01+6.300000000e+01+1.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +6.300000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GLDA element definitions.", "[fem_element_glda]") {

   long const ELNOX = 64;
   long const ELNO = 65;
   elements::el_types const ELTYP = elements::el_types::GLDA;
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

   elements::glda probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::glda probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::glda probe(66,                         // elnox
              67,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.600000000e+01+6.700000000e+01+1.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +6.700000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::glda probe;
      test << probe(70,                         // elnox
                    70,                         // elno
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
            "GELMNT1 +7.000000000e+01+7.000000000e+01+1.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +7.000000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM BEAS element definitions.", "[fem_element_beas]") {

   long const ELNOX = 71;
   long const ELNO = 72;
   elements::el_types const ELTYP = elements::el_types::BEAS;
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

   elements::beas probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework, elements::el_processor::Launch, elements::el_processor::Platework, elements::el_processor::Pretube, elements::el_processor::Wadam, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::beas probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::beas probe(73,                         // elnox
              74,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.300000000e+01+7.400000000e+01+1.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +7.400000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::beas probe;
      test << probe(77,                         // elnox
                    77,                         // elno
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
            "GELMNT1 +7.700000000e+01+7.700000000e+01+1.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +7.700000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXIS element definitions.", "[fem_element_axis]") {

   long const ELNOX = 78;
   long const ELNO = 79;
   elements::el_types const ELTYP = elements::el_types::AXIS;
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

   elements::axis probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::axis probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::axis probe(80,                         // elnox
              81,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.000000000e+01+8.100000000e+01+1.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +8.100000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::axis probe;
      test << probe(84,                         // elnox
                    84,                         // elno
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
            "GELMNT1 +8.400000000e+01+8.400000000e+01+1.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +8.400000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXDA element definitions.", "[fem_element_axda]") {

   long const ELNOX = 85;
   long const ELNO = 86;
   elements::el_types const ELTYP = elements::el_types::AXDA;
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

   elements::axda probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::axda probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::axda probe(87,                         // elnox
              88,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.700000000e+01+8.800000000e+01+1.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +8.800000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::axda probe;
      test << probe(91,                         // elnox
                    91,                         // elno
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
            "GELMNT1 +9.100000000e+01+9.100000000e+01+1.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +9.100000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GSPR element definitions.", "[fem_element_gspr]") {

   long const ELNOX = 92;
   long const ELNO = 93;
   elements::el_types const ELTYP = elements::el_types::GSPR;
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

   elements::gspr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::gspr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::gspr probe(94,                         // elnox
              95,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +9.400000000e+01+9.500000000e+01+1.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +9.500000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::gspr probe;
      test << probe(98,                         // elnox
                    98,                         // elno
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
            "GELMNT1 +9.800000000e+01+9.800000000e+01+1.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +9.800000000e+01+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GDAM element definitions.", "[fem_element_gdam]") {

   long const ELNOX = 99;
   long const ELNO = 100;
   elements::el_types const ELTYP = elements::el_types::GDAM;
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

   elements::gdam probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::gdam probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::gdam probe(101,                         // elnox
              102,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.010000000e+02+1.020000000e+02+1.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +1.020000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::gdam probe;
      test << probe(105,                         // elnox
                    105,                         // elno
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
            "GELMNT1 +1.050000000e+02+1.050000000e+02+1.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +1.050000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM IHEX element definitions.", "[fem_element_ihex]") {

   long const ELNOX = 106;
   long const ELNO = 107;
   elements::el_types const ELTYP = elements::el_types::IHEX;
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

   elements::ihex probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework }));
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

   SECTION("simple (empty)") {
      elements::ihex probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ihex probe(108,                         // elnox
              109,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.080000000e+02+1.090000000e+02+2.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "GELREF1 +1.090000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ihex probe;
      test << probe(112,                         // elnox
                    112,                         // elno
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
            "GELMNT1 +1.120000000e+02+1.120000000e+02+2.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "GELREF1 +1.120000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LHEX element definitions.", "[fem_element_lhex]") {

   long const ELNOX = 113;
   long const ELNO = 114;
   elements::el_types const ELTYP = elements::el_types::LHEX;
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

   elements::lhex probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework }));
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

   SECTION("simple (empty)") {
      elements::lhex probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::lhex probe(115,                         // elnox
              116,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.150000000e+02+1.160000000e+02+2.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +1.160000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::lhex probe;
      test << probe(119,                         // elnox
                    119,                         // elno
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
            "GELMNT1 +1.190000000e+02+1.190000000e+02+2.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +1.190000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SECB element definitions.", "[fem_element_secb]") {

   long const ELNOX = 120;
   long const ELNO = 121;
   elements::el_types const ELTYP = elements::el_types::SECB;
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

   elements::secb probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::secb probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::secb probe(122,                         // elnox
              123,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.220000000e+02+1.230000000e+02+2.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.230000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::secb probe;
      test << probe(126,                         // elnox
                    126,                         // elno
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
            "GELMNT1 +1.260000000e+02+1.260000000e+02+2.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.260000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM BTSS element definitions.", "[fem_element_btss]") {

   long const ELNOX = 127;
   long const ELNO = 128;
   elements::el_types const ELTYP = elements::el_types::BTSS;
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

   elements::btss probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::btss probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::btss probe(129,                         // elnox
              130,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.290000000e+02+1.300000000e+02+2.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.300000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::btss probe;
      test << probe(133,                         // elnox
                    133,                         // elno
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
            "GELMNT1 +1.330000000e+02+1.330000000e+02+2.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.330000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM FQUS_FFQ element definitions.", "[fem_element_fqus_ffq]") {

   long const ELNOX = 134;
   long const ELNO = 135;
   elements::el_types const ELTYP = elements::el_types::FQUS_FFQ;
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

   elements::fqus_ffq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Platework, elements::el_processor::Pretube, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::fqus_ffq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::fqus_ffq probe(136,                         // elnox
              137,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.360000000e+02+1.370000000e+02+2.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +1.370000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::fqus_ffq probe;
      test << probe(140,                         // elnox
                    140,                         // elno
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
            "GELMNT1 +1.400000000e+02+1.400000000e+02+2.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +1.400000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM FTRS_FFTR element definitions.", "[fem_element_ftrs_fftr]") {

   long const ELNOX = 141;
   long const ELNO = 142;
   elements::el_types const ELTYP = elements::el_types::FTRS_FFTR;
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

   elements::ftrs_fftr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Platework, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::ftrs_fftr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ftrs_fftr probe(143,                         // elnox
              144,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.430000000e+02+1.440000000e+02+2.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.440000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ftrs_fftr probe;
      test << probe(147,                         // elnox
                    147,                         // elno
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
            "GELMNT1 +1.470000000e+02+1.470000000e+02+2.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +1.470000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SCTS element definitions.", "[fem_element_scts]") {

   long const ELNOX = 148;
   long const ELNO = 149;
   elements::el_types const ELTYP = elements::el_types::SCTS;
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

   elements::scts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework }));
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

   SECTION("simple (empty)") {
      elements::scts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::scts probe(150,                         // elnox
              151,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.500000000e+02+1.510000000e+02+2.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +1.510000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::scts probe;
      test << probe(154,                         // elnox
                    154,                         // elno
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
            "GELMNT1 +1.540000000e+02+1.540000000e+02+2.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +1.540000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM MCTS element definitions.", "[fem_element_mcts]") {

   long const ELNOX = 155;
   long const ELNO = 156;
   elements::el_types const ELTYP = elements::el_types::MCTS;
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

   elements::mcts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::mcts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::mcts probe(157,                         // elnox
              158,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.570000000e+02+1.580000000e+02+2.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +1.580000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::mcts probe;
      test << probe(161,                         // elnox
                    161,                         // elno
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
            "GELMNT1 +1.610000000e+02+1.610000000e+02+2.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +1.610000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SCQS element definitions.", "[fem_element_scqs]") {

   long const ELNOX = 162;
   long const ELNO = 163;
   elements::el_types const ELTYP = elements::el_types::SCQS;
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

   elements::scqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::scqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::scqs probe(164,                         // elnox
              165,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.640000000e+02+1.650000000e+02+2.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +1.650000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::scqs probe;
      test << probe(168,                         // elnox
                    168,                         // elno
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
            "GELMNT1 +1.680000000e+02+1.680000000e+02+2.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +1.680000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM MCQS element definitions.", "[fem_element_mcqs]") {

   long const ELNOX = 169;
   long const ELNO = 170;
   elements::el_types const ELTYP = elements::el_types::MCQS;
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

   elements::mcqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::mcqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::mcqs probe(171,                         // elnox
              172,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.710000000e+02+1.720000000e+02+2.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +1.720000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::mcqs probe;
      test << probe(175,                         // elnox
                    175,                         // elno
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
            "GELMNT1 +1.750000000e+02+1.750000000e+02+2.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +1.750000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM IPRI element definitions.", "[fem_element_ipri]") {

   long const ELNOX = 176;
   long const ELNO = 177;
   elements::el_types const ELTYP = elements::el_types::IPRI;
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

   elements::ipri probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::ipri probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ipri probe(178,                         // elnox
              179,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.780000000e+02+1.790000000e+02+3.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +1.790000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ipri probe;
      test << probe(182,                         // elnox
                    182,                         // elno
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
            "GELMNT1 +1.820000000e+02+1.820000000e+02+3.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +1.820000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ITET element definitions.", "[fem_element_itet]") {

   long const ELNOX = 183;
   long const ELNO = 184;
   elements::el_types const ELTYP = elements::el_types::ITET;
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

   elements::itet probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::itet probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::itet probe(185,                         // elnox
              186,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.850000000e+02+1.860000000e+02+3.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02\n"
            "GELREF1 +1.860000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::itet probe;
      test << probe(189,                         // elnox
                    189,                         // elno
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
            "GELMNT1 +1.890000000e+02+1.890000000e+02+3.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02\n"
            "GELREF1 +1.890000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TPRI element definitions.", "[fem_element_tpri]") {

   long const ELNOX = 190;
   long const ELNO = 191;
   elements::el_types const ELTYP = elements::el_types::TPRI;
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

   elements::tpri probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework }));
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

   SECTION("simple (empty)") {
      elements::tpri probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::tpri probe(192,                         // elnox
              193,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.920000000e+02+1.930000000e+02+3.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +1.930000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::tpri probe;
      test << probe(196,                         // elnox
                    196,                         // elno
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
            "GELMNT1 +1.960000000e+02+1.960000000e+02+3.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +1.960000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TETR element definitions.", "[fem_element_tetr]") {

   long const ELNOX = 197;
   long const ELNO = 198;
   elements::el_types const ELTYP = elements::el_types::TETR;
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

   elements::tetr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::tetr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::tetr probe(199,                         // elnox
              200,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.990000000e+02+2.000000000e+02+3.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.000000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::tetr probe;
      test << probe(203,                         // elnox
                    203,                         // elno
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
            "GELMNT1 +2.030000000e+02+2.030000000e+02+3.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.030000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LCTS element definitions.", "[fem_element_lcts]") {

   long const ELNOX = 204;
   long const ELNO = 205;
   elements::el_types const ELTYP = elements::el_types::LCTS;
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

   elements::lcts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::lcts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::lcts probe(206,                         // elnox
              207,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.060000000e+02+2.070000000e+02+3.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.070000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::lcts probe;
      test << probe(210,                         // elnox
                    210,                         // elno
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
            "GELMNT1 +2.100000000e+02+2.100000000e+02+3.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.100000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM LCQS element definitions.", "[fem_element_lcqs]") {

   long const ELNOX = 211;
   long const ELNO = 212;
   elements::el_types const ELTYP = elements::el_types::LCQS;
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

   elements::lcqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::lcqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::lcqs probe(213,                         // elnox
              214,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.130000000e+02+2.140000000e+02+3.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.140000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::lcqs probe;
      test << probe(217,                         // elnox
                    217,                         // elno
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
            "GELMNT1 +2.170000000e+02+2.170000000e+02+3.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.170000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TRS1 element definitions.", "[fem_element_trs1]") {

   long const ELNOX = 218;
   long const ELNO = 219;
   elements::el_types const ELTYP = elements::el_types::TRS1;
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

   elements::trs1 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::trs1 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::trs1 probe(220,                         // elnox
              221,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.200000000e+02+2.210000000e+02+3.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +2.210000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::trs1 probe;
      test << probe(224,                         // elnox
                    224,                         // elno
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
            "GELMNT1 +2.240000000e+02+2.240000000e+02+3.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +2.240000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TRS2 element definitions.", "[fem_element_trs2]") {

   long const ELNOX = 225;
   long const ELNO = 226;
   elements::el_types const ELTYP = elements::el_types::TRS2;
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

   elements::trs2 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::trs2 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::trs2 probe(227,                         // elnox
              228,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.270000000e+02+2.280000000e+02+3.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +2.280000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::trs2 probe;
      test << probe(231,                         // elnox
                    231,                         // elno
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
            "GELMNT1 +2.310000000e+02+2.310000000e+02+3.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02\n"
            "GELREF1 +2.310000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM TRS3 element definitions.", "[fem_element_trs3]") {

   long const ELNOX = 232;
   long const ELNO = 233;
   elements::el_types const ELTYP = elements::el_types::TRS3;
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

   elements::trs3 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::trs3 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::trs3 probe(234,                         // elnox
              235,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.340000000e+02+2.350000000e+02+3.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "GELREF1 +2.350000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::trs3 probe;
      test << probe(238,                         // elnox
                    238,                         // elno
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
            "GELMNT1 +2.380000000e+02+2.380000000e+02+3.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "GELREF1 +2.380000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GLSH element definitions.", "[fem_element_glsh]") {

   long const ELNOX = 239;
   long const ELNO = 240;
   elements::el_types const ELTYP = elements::el_types::GLSH;
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

   elements::glsh probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Sestra, elements::el_processor::Poseidon }));
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

   SECTION("simple (empty)") {
      elements::glsh probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::glsh probe(241,                         // elnox
              242,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.410000000e+02+2.420000000e+02+4.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.420000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::glsh probe;
      test << probe(245,                         // elnox
                    245,                         // elno
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
            "GELMNT1 +2.450000000e+02+2.450000000e+02+4.000000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.450000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXCS element definitions.", "[fem_element_axcs]") {

   long const ELNOX = 246;
   long const ELNO = 247;
   elements::el_types const ELTYP = elements::el_types::AXCS;
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

   elements::axcs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::axcs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::axcs probe(248,                         // elnox
              249,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.480000000e+02+2.490000000e+02+4.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.490000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::axcs probe;
      test << probe(252,                         // elnox
                    252,                         // elno
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
            "GELMNT1 +2.520000000e+02+2.520000000e+02+4.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +2.520000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXLQ element definitions.", "[fem_element_axlq]") {

   long const ELNOX = 253;
   long const ELNO = 254;
   elements::el_types const ELTYP = elements::el_types::AXLQ;
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

   elements::axlq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::axlq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::axlq probe(255,                         // elnox
              256,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.550000000e+02+2.560000000e+02+4.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.560000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::axlq probe;
      test << probe(259,                         // elnox
                    259,                         // elno
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
            "GELMNT1 +2.590000000e+02+2.590000000e+02+4.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.590000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXLS element definitions.", "[fem_element_axls]") {

   long const ELNOX = 260;
   long const ELNO = 261;
   elements::el_types const ELTYP = elements::el_types::AXLS;
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

   elements::axls probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::axls probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::axls probe(262,                         // elnox
              263,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.620000000e+02+2.630000000e+02+4.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.630000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::axls probe;
      test << probe(266,                         // elnox
                    266,                         // elno
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
            "GELMNT1 +2.660000000e+02+2.660000000e+02+4.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +2.660000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM AXQQ element definitions.", "[fem_element_axqq]") {

   long const ELNOX = 267;
   long const ELNO = 268;
   elements::el_types const ELTYP = elements::el_types::AXQQ;
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

   elements::axqq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::axqq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::axqq probe(269,                         // elnox
              270,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.690000000e+02+2.700000000e+02+4.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.700000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::axqq probe;
      test << probe(273,                         // elnox
                    273,                         // elno
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
            "GELMNT1 +2.730000000e+02+2.730000000e+02+4.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +2.730000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM PILS element definitions.", "[fem_element_pils]") {

   long const ELNOX = 274;
   long const ELNO = 275;
   elements::el_types const ELTYP = elements::el_types::PILS;
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

   elements::pils probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::pils probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::pils probe(276,                         // elnox
              277,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.760000000e+02+2.770000000e+02+4.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.770000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::pils probe;
      test << probe(280,                         // elnox
                    280,                         // elno
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
            "GELMNT1 +2.800000000e+02+2.800000000e+02+4.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.800000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM PCAB element definitions.", "[fem_element_pcab]") {

   long const ELNOX = 281;
   long const ELNO = 282;
   elements::el_types const ELTYP = elements::el_types::PCAB;
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

   elements::pcab probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::pcab probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::pcab probe(283,                         // elnox
              284,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.830000000e+02+2.840000000e+02+4.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.840000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::pcab probe;
      test << probe(287,                         // elnox
                    287,                         // elno
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
            "GELMNT1 +2.870000000e+02+2.870000000e+02+4.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +2.870000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM PSPR element definitions.", "[fem_element_pspr]") {

   long const ELNOX = 288;
   long const ELNO = 289;
   elements::el_types const ELTYP = elements::el_types::PSPR;
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

   elements::pspr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::pspr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::pspr probe(290,                         // elnox
              291,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.900000000e+02+2.910000000e+02+4.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.910000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::pspr probe;
      test << probe(294,                         // elnox
                    294,                         // elno
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
            "GELMNT1 +2.940000000e+02+2.940000000e+02+4.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02\n"
            "GELREF1 +2.940000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ADVA_4 element definitions.", "[fem_element_adva_4]") {

   long const ELNOX = 295;
   long const ELNO = 296;
   elements::el_types const ELTYP = elements::el_types::ADVA_4;
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

   elements::adva_4 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::adva_4 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::adva_4 probe(297,                         // elnox
              298,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +2.970000000e+02+2.980000000e+02+4.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +2.980000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::adva_4 probe;
      test << probe(301,                         // elnox
                    301,                         // elno
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
            "GELMNT1 +3.010000000e+02+3.010000000e+02+4.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +3.010000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM ADVA_2 element definitions.", "[fem_element_adva_2]") {

   long const ELNOX = 302;
   long const ELNO = 303;
   elements::el_types const ELTYP = elements::el_types::ADVA_2;
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

   elements::adva_2 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::ADVANCE }));
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

   SECTION("simple (empty)") {
      elements::adva_2 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::adva_2 probe(304,                         // elnox
              305,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.040000000e+02+3.050000000e+02+4.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +3.050000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::adva_2 probe;
      test << probe(308,                         // elnox
                    308,                         // elno
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
            "GELMNT1 +3.080000000e+02+3.080000000e+02+4.900000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +3.080000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCP element definitions.", "[fem_element_ctcp]") {

   long const ELNOX = 309;
   long const ELNO = 310;
   elements::el_types const ELTYP = elements::el_types::CTCP;
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

   elements::ctcp probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::ctcp probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctcp probe(311,                         // elnox
              312,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.110000000e+02+3.120000000e+02+5.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +3.120000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctcp probe;
      test << probe(315,                         // elnox
                    315,                         // elno
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
            "GELMNT1 +3.150000000e+02+3.150000000e+02+5.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02\n"
            "GELREF1 +3.150000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCL element definitions.", "[fem_element_ctcl]") {

   long const ELNOX = 316;
   long const ELNO = 317;
   elements::el_types const ELTYP = elements::el_types::CTCL;
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

   elements::ctcl probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::ctcl probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctcl probe(318,                         // elnox
              319,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.180000000e+02+3.190000000e+02+5.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +3.190000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctcl probe;
      test << probe(322,                         // elnox
                    322,                         // elno
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
            "GELMNT1 +3.220000000e+02+3.220000000e+02+5.200000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +3.220000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTAL element definitions.", "[fem_element_ctal]") {

   long const ELNOX = 323;
   long const ELNO = 324;
   elements::el_types const ELTYP = elements::el_types::CTAL;
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

   elements::ctal probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::ctal probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctal probe(325,                         // elnox
              326,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.250000000e+02+3.260000000e+02+5.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +3.260000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctal probe;
      test << probe(329,                         // elnox
                    329,                         // elno
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
            "GELMNT1 +3.290000000e+02+3.290000000e+02+5.300000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "GELREF1 +3.290000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCC element definitions.", "[fem_element_ctcc]") {

   long const ELNOX = 330;
   long const ELNO = 331;
   elements::el_types const ELTYP = elements::el_types::CTCC;
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

   elements::ctcc probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::ctcc probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctcc probe(332,                         // elnox
              333,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.320000000e+02+3.330000000e+02+5.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +3.330000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctcc probe;
      test << probe(336,                         // elnox
                    336,                         // elno
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
            "GELMNT1 +3.360000000e+02+3.360000000e+02+5.400000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +3.360000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTAQ element definitions.", "[fem_element_ctaq]") {

   long const ELNOX = 337;
   long const ELNO = 338;
   elements::el_types const ELTYP = elements::el_types::CTAQ;
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

   elements::ctaq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem }));
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

   SECTION("simple (empty)") {
      elements::ctaq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctaq probe(339,                         // elnox
              340,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.390000000e+02+3.400000000e+02+5.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +3.400000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctaq probe;
      test << probe(343,                         // elnox
                    343,                         // elno
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
            "GELMNT1 +3.430000000e+02+3.430000000e+02+5.500000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +3.430000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTLQ element definitions.", "[fem_element_ctlq]") {

   long const ELNOX = 344;
   long const ELNO = 345;
   elements::el_types const ELTYP = elements::el_types::CTLQ;
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

   elements::ctlq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::ctlq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctlq probe(346,                         // elnox
              347,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.460000000e+02+3.470000000e+02+5.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +3.470000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctlq probe;
      test << probe(350,                         // elnox
                    350,                         // elno
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
            "GELMNT1 +3.500000000e+02+3.500000000e+02+5.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +3.500000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTCQ element definitions.", "[fem_element_ctcq]") {

   long const ELNOX = 351;
   long const ELNO = 352;
   elements::el_types const ELTYP = elements::el_types::CTCQ;
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

   elements::ctcq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::ctcq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctcq probe(353,                         // elnox
              354,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.530000000e+02+3.540000000e+02+5.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "GELREF1 +3.540000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctcq probe;
      test << probe(357,                         // elnox
                    357,                         // elno
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
            "GELMNT1 +3.570000000e+02+3.570000000e+02+5.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "GELREF1 +3.570000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM CTMQ element definitions.", "[fem_element_ctmq]") {

   long const ELNOX = 358;
   long const ELNO = 359;
   elements::el_types const ELTYP = elements::el_types::CTMQ;
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

   elements::ctmq probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::ctmq probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ctmq probe(360,                         // elnox
              361,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.600000000e+02+3.610000000e+02+5.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +3.610000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ctmq probe;
      test << probe(364,                         // elnox
                    364,                         // elno
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
            "GELMNT1 +3.640000000e+02+3.640000000e+02+5.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02\n"
            "GELREF1 +3.640000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM HCQS element definitions.", "[fem_element_hcqs]") {

   long const ELNOX = 365;
   long const ELNO = 366;
   elements::el_types const ELTYP = elements::el_types::HCQS;
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

   elements::hcqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Pretube }));
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

   SECTION("simple (empty)") {
      elements::hcqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::hcqs probe(367,                         // elnox
              368,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.670000000e+02+3.680000000e+02+6.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02\n"
            "GELREF1 +3.680000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::hcqs probe;
      test << probe(371,                         // elnox
                    371,                         // elno
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
            "GELMNT1 +3.710000000e+02+3.710000000e+02+6.100000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02\n"
            "GELREF1 +3.710000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SLQS element definitions.", "[fem_element_slqs]") {

   long const ELNOX = 372;
   long const ELNO = 373;
   elements::el_types const ELTYP = elements::el_types::SLQS;
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

   elements::slqs probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::slqs probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::slqs probe(374,                         // elnox
              375,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.740000000e+02+3.750000000e+02+6.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +3.750000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::slqs probe;
      test << probe(378,                         // elnox
                    378,                         // elno
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
            "GELMNT1 +3.780000000e+02+3.780000000e+02+6.600000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "GELREF1 +3.780000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SLTS element definitions.", "[fem_element_slts]") {

   long const ELNOX = 379;
   long const ELNO = 380;
   elements::el_types const ELTYP = elements::el_types::SLTS;
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

   elements::slts probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::slts probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::slts probe(381,                         // elnox
              382,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.810000000e+02+3.820000000e+02+6.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +3.820000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::slts probe;
      test << probe(385,                         // elnox
                    385,                         // elno
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
            "GELMNT1 +3.850000000e+02+3.850000000e+02+6.700000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02\n"
            "GELREF1 +3.850000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM SLCB element definitions.", "[fem_element_slcb]") {

   long const ELNOX = 386;
   long const ELNO = 387;
   elements::el_types const ELTYP = elements::el_types::SLCB;
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

   elements::slcb probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general }));
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

   SECTION("simple (empty)") {
      elements::slcb probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::slcb probe(388,                         // elnox
              389,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.880000000e+02+3.890000000e+02+6.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +3.890000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::slcb probe;
      test << probe(392,                         // elnox
                    392,                         // elno
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
            "GELMNT1 +3.920000000e+02+3.920000000e+02+6.800000000e+01+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02\n"
            "GELREF1 +3.920000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM MATR element definitions.", "[fem_element_matr]") {

   long const ELNOX = 393;
   long const ELNO = 394;
   elements::el_types const ELTYP = elements::el_types::MATR;
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

   elements::matr probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::ADVANCE, elements::el_processor::Splice }));
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

   SECTION("simple (empty)") {
      elements::matr probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::matr probe(395,                         // elnox
              396,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +3.950000000e+02+3.960000000e+02+7.000000000e+01+3.000000000e+00\n"
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
            "GELREF1 +3.960000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::matr probe;
      test << probe(399,                         // elnox
                    399,                         // elno
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
            "GELMNT1 +3.990000000e+02+3.990000000e+02+7.000000000e+01+3.000000000e+00\n"
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
            "GELREF1 +3.990000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX100 element definitions.", "[fem_element_ghex100]") {

   long const ELNOX = 400;
   long const ELNO = 401;
   elements::el_types const ELTYP = elements::el_types::GHEX100;
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

   elements::ghex100 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex100 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex100 probe(402,                         // elnox
              403,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.020000000e+02+4.030000000e+02+1.000000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02\n"
            "GELREF1 +4.030000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex100 probe;
      test << probe(406,                         // elnox
                    406,                         // elno
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
            "GELMNT1 +4.060000000e+02+4.060000000e+02+1.000000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02\n"
            "GELREF1 +4.060000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX101 element definitions.", "[fem_element_ghex101]") {

   long const ELNOX = 407;
   long const ELNO = 408;
   elements::el_types const ELTYP = elements::el_types::GHEX101;
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

   elements::ghex101 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex101 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex101 probe(409,                         // elnox
              410,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.090000000e+02+4.100000000e+02+1.010000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.100000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex101 probe;
      test << probe(413,                         // elnox
                    413,                         // elno
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
            "GELMNT1 +4.130000000e+02+4.130000000e+02+1.010000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.130000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX102 element definitions.", "[fem_element_ghex102]") {

   long const ELNOX = 414;
   long const ELNO = 415;
   elements::el_types const ELTYP = elements::el_types::GHEX102;
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

   elements::ghex102 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex102 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex102 probe(416,                         // elnox
              417,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.160000000e+02+4.170000000e+02+1.020000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.170000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex102 probe;
      test << probe(420,                         // elnox
                    420,                         // elno
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
            "GELMNT1 +4.200000000e+02+4.200000000e+02+1.020000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.200000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX103 element definitions.", "[fem_element_ghex103]") {

   long const ELNOX = 421;
   long const ELNO = 422;
   elements::el_types const ELTYP = elements::el_types::GHEX103;
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

   elements::ghex103 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex103 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex103 probe(423,                         // elnox
              424,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.230000000e+02+4.240000000e+02+1.030000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.240000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex103 probe;
      test << probe(427,                         // elnox
                    427,                         // elno
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
            "GELMNT1 +4.270000000e+02+4.270000000e+02+1.030000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.270000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX104 element definitions.", "[fem_element_ghex104]") {

   long const ELNOX = 428;
   long const ELNO = 429;
   elements::el_types const ELTYP = elements::el_types::GHEX104;
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

   elements::ghex104 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex104 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex104 probe(430,                         // elnox
              431,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.300000000e+02+4.310000000e+02+1.040000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.310000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex104 probe;
      test << probe(434,                         // elnox
                    434,                         // elno
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
            "GELMNT1 +4.340000000e+02+4.340000000e+02+1.040000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.340000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX105 element definitions.", "[fem_element_ghex105]") {

   long const ELNOX = 435;
   long const ELNO = 436;
   elements::el_types const ELTYP = elements::el_types::GHEX105;
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

   elements::ghex105 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex105 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex105 probe(437,                         // elnox
              438,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.370000000e+02+4.380000000e+02+1.050000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.380000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex105 probe;
      test << probe(441,                         // elnox
                    441,                         // elno
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
            "GELMNT1 +4.410000000e+02+4.410000000e+02+1.050000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.410000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX106 element definitions.", "[fem_element_ghex106]") {

   long const ELNOX = 442;
   long const ELNO = 443;
   elements::el_types const ELTYP = elements::el_types::GHEX106;
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

   elements::ghex106 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex106 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex106 probe(444,                         // elnox
              445,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.440000000e+02+4.450000000e+02+1.060000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.450000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex106 probe;
      test << probe(448,                         // elnox
                    448,                         // elno
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
            "GELMNT1 +4.480000000e+02+4.480000000e+02+1.060000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.480000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX107 element definitions.", "[fem_element_ghex107]") {

   long const ELNOX = 449;
   long const ELNO = 450;
   elements::el_types const ELTYP = elements::el_types::GHEX107;
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

   elements::ghex107 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex107 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex107 probe(451,                         // elnox
              452,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.510000000e+02+4.520000000e+02+1.070000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +4.520000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex107 probe;
      test << probe(455,                         // elnox
                    455,                         // elno
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
            "GELMNT1 +4.550000000e+02+4.550000000e+02+1.070000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +4.550000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX108 element definitions.", "[fem_element_ghex108]") {

   long const ELNOX = 456;
   long const ELNO = 457;
   elements::el_types const ELTYP = elements::el_types::GHEX108;
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

   elements::ghex108 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex108 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex108 probe(458,                         // elnox
              459,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.580000000e+02+4.590000000e+02+1.080000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.590000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex108 probe;
      test << probe(462,                         // elnox
                    462,                         // elno
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
            "GELMNT1 +4.620000000e+02+4.620000000e+02+1.080000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +4.620000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX109 element definitions.", "[fem_element_ghex109]") {

   long const ELNOX = 463;
   long const ELNO = 464;
   elements::el_types const ELTYP = elements::el_types::GHEX109;
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

   elements::ghex109 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex109 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex109 probe(465,                         // elnox
              466,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.650000000e+02+4.660000000e+02+1.090000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.660000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex109 probe;
      test << probe(469,                         // elnox
                    469,                         // elno
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
            "GELMNT1 +4.690000000e+02+4.690000000e+02+1.090000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.690000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX110 element definitions.", "[fem_element_ghex110]") {

   long const ELNOX = 470;
   long const ELNO = 471;
   elements::el_types const ELTYP = elements::el_types::GHEX110;
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

   elements::ghex110 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex110 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex110 probe(472,                         // elnox
              473,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.720000000e+02+4.730000000e+02+1.100000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.730000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex110 probe;
      test << probe(476,                         // elnox
                    476,                         // elno
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
            "GELMNT1 +4.760000000e+02+4.760000000e+02+1.100000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.760000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX111 element definitions.", "[fem_element_ghex111]") {

   long const ELNOX = 477;
   long const ELNO = 478;
   elements::el_types const ELTYP = elements::el_types::GHEX111;
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

   elements::ghex111 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex111 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex111 probe(479,                         // elnox
              480,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.790000000e+02+4.800000000e+02+1.110000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +4.800000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex111 probe;
      test << probe(483,                         // elnox
                    483,                         // elno
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
            "GELMNT1 +4.830000000e+02+4.830000000e+02+1.110000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +4.830000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX112 element definitions.", "[fem_element_ghex112]") {

   long const ELNOX = 484;
   long const ELNO = 485;
   elements::el_types const ELTYP = elements::el_types::GHEX112;
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

   elements::ghex112 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex112 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex112 probe(486,                         // elnox
              487,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.860000000e+02+4.870000000e+02+1.120000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.870000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex112 probe;
      test << probe(490,                         // elnox
                    490,                         // elno
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
            "GELMNT1 +4.900000000e+02+4.900000000e+02+1.120000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +4.900000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX113 element definitions.", "[fem_element_ghex113]") {

   long const ELNOX = 491;
   long const ELNO = 492;
   elements::el_types const ELTYP = elements::el_types::GHEX113;
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

   elements::ghex113 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex113 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex113 probe(493,                         // elnox
              494,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +4.930000000e+02+4.940000000e+02+1.130000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +4.940000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex113 probe;
      test << probe(497,                         // elnox
                    497,                         // elno
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
            "GELMNT1 +4.970000000e+02+4.970000000e+02+1.130000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +4.970000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX114 element definitions.", "[fem_element_ghex114]") {

   long const ELNOX = 498;
   long const ELNO = 499;
   elements::el_types const ELTYP = elements::el_types::GHEX114;
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

   elements::ghex114 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex114 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex114 probe(500,                         // elnox
              501,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.000000000e+02+5.010000000e+02+1.140000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.010000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex114 probe;
      test << probe(504,                         // elnox
                    504,                         // elno
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
            "GELMNT1 +5.040000000e+02+5.040000000e+02+1.140000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.040000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX115 element definitions.", "[fem_element_ghex115]") {

   long const ELNOX = 505;
   long const ELNO = 506;
   elements::el_types const ELTYP = elements::el_types::GHEX115;
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

   elements::ghex115 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex115 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex115 probe(507,                         // elnox
              508,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.070000000e+02+5.080000000e+02+1.150000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +5.080000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex115 probe;
      test << probe(511,                         // elnox
                    511,                         // elno
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
            "GELMNT1 +5.110000000e+02+5.110000000e+02+1.150000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +5.110000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX116 element definitions.", "[fem_element_ghex116]") {

   long const ELNOX = 512;
   long const ELNO = 513;
   elements::el_types const ELTYP = elements::el_types::GHEX116;
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

   elements::ghex116 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex116 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex116 probe(514,                         // elnox
              515,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.140000000e+02+5.150000000e+02+1.160000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +5.150000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex116 probe;
      test << probe(518,                         // elnox
                    518,                         // elno
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
            "GELMNT1 +5.180000000e+02+5.180000000e+02+1.160000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +5.180000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX117 element definitions.", "[fem_element_ghex117]") {

   long const ELNOX = 519;
   long const ELNO = 520;
   elements::el_types const ELTYP = elements::el_types::GHEX117;
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

   elements::ghex117 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex117 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex117 probe(521,                         // elnox
              522,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.210000000e+02+5.220000000e+02+1.170000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.220000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex117 probe;
      test << probe(525,                         // elnox
                    525,                         // elno
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
            "GELMNT1 +5.250000000e+02+5.250000000e+02+1.170000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.250000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX118 element definitions.", "[fem_element_ghex118]") {

   long const ELNOX = 526;
   long const ELNO = 527;
   elements::el_types const ELTYP = elements::el_types::GHEX118;
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

   elements::ghex118 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex118 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex118 probe(528,                         // elnox
              529,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.280000000e+02+5.290000000e+02+1.180000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.290000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex118 probe;
      test << probe(532,                         // elnox
                    532,                         // elno
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
            "GELMNT1 +5.320000000e+02+5.320000000e+02+1.180000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.320000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX119 element definitions.", "[fem_element_ghex119]") {

   long const ELNOX = 533;
   long const ELNO = 534;
   elements::el_types const ELTYP = elements::el_types::GHEX119;
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

   elements::ghex119 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex119 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex119 probe(535,                         // elnox
              536,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.350000000e+02+5.360000000e+02+1.190000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.360000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex119 probe;
      test << probe(539,                         // elnox
                    539,                         // elno
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
            "GELMNT1 +5.390000000e+02+5.390000000e+02+1.190000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.390000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX120 element definitions.", "[fem_element_ghex120]") {

   long const ELNOX = 540;
   long const ELNO = 541;
   elements::el_types const ELTYP = elements::el_types::GHEX120;
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

   elements::ghex120 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex120 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex120 probe(542,                         // elnox
              543,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.420000000e+02+5.430000000e+02+1.200000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.430000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex120 probe;
      test << probe(546,                         // elnox
                    546,                         // elno
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
            "GELMNT1 +5.460000000e+02+5.460000000e+02+1.200000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.460000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX121 element definitions.", "[fem_element_ghex121]") {

   long const ELNOX = 547;
   long const ELNO = 548;
   elements::el_types const ELTYP = elements::el_types::GHEX121;
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

   elements::ghex121 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex121 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex121 probe(549,                         // elnox
              550,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.490000000e+02+5.500000000e+02+1.210000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.500000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex121 probe;
      test << probe(553,                         // elnox
                    553,                         // elno
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
            "GELMNT1 +5.530000000e+02+5.530000000e+02+1.210000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.530000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX122 element definitions.", "[fem_element_ghex122]") {

   long const ELNOX = 554;
   long const ELNO = 555;
   elements::el_types const ELTYP = elements::el_types::GHEX122;
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

   elements::ghex122 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex122 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex122 probe(556,                         // elnox
              557,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.560000000e+02+5.570000000e+02+1.220000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.570000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex122 probe;
      test << probe(560,                         // elnox
                    560,                         // elno
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
            "GELMNT1 +5.600000000e+02+5.600000000e+02+1.220000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.600000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX123 element definitions.", "[fem_element_ghex123]") {

   long const ELNOX = 561;
   long const ELNO = 562;
   elements::el_types const ELTYP = elements::el_types::GHEX123;
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

   elements::ghex123 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex123 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex123 probe(563,                         // elnox
              564,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.630000000e+02+5.640000000e+02+1.230000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +5.640000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex123 probe;
      test << probe(567,                         // elnox
                    567,                         // elno
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
            "GELMNT1 +5.670000000e+02+5.670000000e+02+1.230000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +5.670000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX124 element definitions.", "[fem_element_ghex124]") {

   long const ELNOX = 568;
   long const ELNO = 569;
   elements::el_types const ELTYP = elements::el_types::GHEX124;
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

   elements::ghex124 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex124 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex124 probe(570,                         // elnox
              571,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.700000000e+02+5.710000000e+02+1.240000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.710000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex124 probe;
      test << probe(574,                         // elnox
                    574,                         // elno
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
            "GELMNT1 +5.740000000e+02+5.740000000e+02+1.240000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +5.740000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX125 element definitions.", "[fem_element_ghex125]") {

   long const ELNOX = 575;
   long const ELNO = 576;
   elements::el_types const ELTYP = elements::el_types::GHEX125;
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

   elements::ghex125 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex125 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex125 probe(577,                         // elnox
              578,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.770000000e+02+5.780000000e+02+1.250000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.780000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex125 probe;
      test << probe(581,                         // elnox
                    581,                         // elno
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
            "GELMNT1 +5.810000000e+02+5.810000000e+02+1.250000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.810000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX126 element definitions.", "[fem_element_ghex126]") {

   long const ELNOX = 582;
   long const ELNO = 583;
   elements::el_types const ELTYP = elements::el_types::GHEX126;
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

   elements::ghex126 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex126 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex126 probe(584,                         // elnox
              585,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.840000000e+02+5.850000000e+02+1.260000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.850000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex126 probe;
      test << probe(588,                         // elnox
                    588,                         // elno
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
            "GELMNT1 +5.880000000e+02+5.880000000e+02+1.260000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.880000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX127 element definitions.", "[fem_element_ghex127]") {

   long const ELNOX = 589;
   long const ELNO = 590;
   elements::el_types const ELTYP = elements::el_types::GHEX127;
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

   elements::ghex127 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex127 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex127 probe(591,                         // elnox
              592,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.910000000e+02+5.920000000e+02+1.270000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +5.920000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex127 probe;
      test << probe(595,                         // elnox
                    595,                         // elno
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
            "GELMNT1 +5.950000000e+02+5.950000000e+02+1.270000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +5.950000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX128 element definitions.", "[fem_element_ghex128]") {

   long const ELNOX = 596;
   long const ELNO = 597;
   elements::el_types const ELTYP = elements::el_types::GHEX128;
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

   elements::ghex128 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex128 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex128 probe(598,                         // elnox
              599,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +5.980000000e+02+5.990000000e+02+1.280000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +5.990000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex128 probe;
      test << probe(602,                         // elnox
                    602,                         // elno
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
            "GELMNT1 +6.020000000e+02+6.020000000e+02+1.280000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.020000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX129 element definitions.", "[fem_element_ghex129]") {

   long const ELNOX = 603;
   long const ELNO = 604;
   elements::el_types const ELTYP = elements::el_types::GHEX129;
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

   elements::ghex129 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex129 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex129 probe(605,                         // elnox
              606,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.050000000e+02+6.060000000e+02+1.290000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +6.060000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex129 probe;
      test << probe(609,                         // elnox
                    609,                         // elno
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
            "GELMNT1 +6.090000000e+02+6.090000000e+02+1.290000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +6.090000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX130 element definitions.", "[fem_element_ghex130]") {

   long const ELNOX = 610;
   long const ELNO = 611;
   elements::el_types const ELTYP = elements::el_types::GHEX130;
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

   elements::ghex130 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex130 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex130 probe(612,                         // elnox
              613,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.120000000e+02+6.130000000e+02+1.300000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +6.130000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex130 probe;
      test << probe(616,                         // elnox
                    616,                         // elno
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
            "GELMNT1 +6.160000000e+02+6.160000000e+02+1.300000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +6.160000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX131 element definitions.", "[fem_element_ghex131]") {

   long const ELNOX = 617;
   long const ELNO = 618;
   elements::el_types const ELTYP = elements::el_types::GHEX131;
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

   elements::ghex131 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex131 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex131 probe(619,                         // elnox
              620,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.190000000e+02+6.200000000e+02+1.310000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +6.200000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex131 probe;
      test << probe(623,                         // elnox
                    623,                         // elno
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
            "GELMNT1 +6.230000000e+02+6.230000000e+02+1.310000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +6.230000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX132 element definitions.", "[fem_element_ghex132]") {

   long const ELNOX = 624;
   long const ELNO = 625;
   elements::el_types const ELTYP = elements::el_types::GHEX132;
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

   elements::ghex132 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex132 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex132 probe(626,                         // elnox
              627,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.260000000e+02+6.270000000e+02+1.320000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +6.270000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex132 probe;
      test << probe(630,                         // elnox
                    630,                         // elno
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
            "GELMNT1 +6.300000000e+02+6.300000000e+02+1.320000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02\n"
            "GELREF1 +6.300000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX133 element definitions.", "[fem_element_ghex133]") {

   long const ELNOX = 631;
   long const ELNO = 632;
   elements::el_types const ELTYP = elements::el_types::GHEX133;
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

   elements::ghex133 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex133 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex133 probe(633,                         // elnox
              634,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.330000000e+02+6.340000000e+02+1.330000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.340000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex133 probe;
      test << probe(637,                         // elnox
                    637,                         // elno
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
            "GELMNT1 +6.370000000e+02+6.370000000e+02+1.330000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.370000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX134 element definitions.", "[fem_element_ghex134]") {

   long const ELNOX = 638;
   long const ELNO = 639;
   elements::el_types const ELTYP = elements::el_types::GHEX134;
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

   elements::ghex134 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex134 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex134 probe(640,                         // elnox
              641,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.400000000e+02+6.410000000e+02+1.340000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.410000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex134 probe;
      test << probe(644,                         // elnox
                    644,                         // elno
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
            "GELMNT1 +6.440000000e+02+6.440000000e+02+1.340000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.440000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX135 element definitions.", "[fem_element_ghex135]") {

   long const ELNOX = 645;
   long const ELNO = 646;
   elements::el_types const ELTYP = elements::el_types::GHEX135;
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

   elements::ghex135 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex135 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex135 probe(647,                         // elnox
              648,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.470000000e+02+6.480000000e+02+1.350000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.480000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex135 probe;
      test << probe(651,                         // elnox
                    651,                         // elno
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
            "GELMNT1 +6.510000000e+02+6.510000000e+02+1.350000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.510000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX136 element definitions.", "[fem_element_ghex136]") {

   long const ELNOX = 652;
   long const ELNO = 653;
   elements::el_types const ELTYP = elements::el_types::GHEX136;
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

   elements::ghex136 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex136 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex136 probe(654,                         // elnox
              655,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.540000000e+02+6.550000000e+02+1.360000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.550000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex136 probe;
      test << probe(658,                         // elnox
                    658,                         // elno
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
            "GELMNT1 +6.580000000e+02+6.580000000e+02+1.360000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.580000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX137 element definitions.", "[fem_element_ghex137]") {

   long const ELNOX = 659;
   long const ELNO = 660;
   elements::el_types const ELTYP = elements::el_types::GHEX137;
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

   elements::ghex137 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex137 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex137 probe(661,                         // elnox
              662,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.610000000e+02+6.620000000e+02+1.370000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.620000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex137 probe;
      test << probe(665,                         // elnox
                    665,                         // elno
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
            "GELMNT1 +6.650000000e+02+6.650000000e+02+1.370000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.650000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX138 element definitions.", "[fem_element_ghex138]") {

   long const ELNOX = 666;
   long const ELNO = 667;
   elements::el_types const ELTYP = elements::el_types::GHEX138;
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

   elements::ghex138 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex138 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex138 probe(668,                         // elnox
              669,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.680000000e+02+6.690000000e+02+1.380000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.690000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex138 probe;
      test << probe(672,                         // elnox
                    672,                         // elno
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
            "GELMNT1 +6.720000000e+02+6.720000000e+02+1.380000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.720000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX139 element definitions.", "[fem_element_ghex139]") {

   long const ELNOX = 673;
   long const ELNO = 674;
   elements::el_types const ELTYP = elements::el_types::GHEX139;
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

   elements::ghex139 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex139 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex139 probe(675,                         // elnox
              676,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.750000000e+02+6.760000000e+02+1.390000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +6.760000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex139 probe;
      test << probe(679,                         // elnox
                    679,                         // elno
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
            "GELMNT1 +6.790000000e+02+6.790000000e+02+1.390000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +6.790000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX140 element definitions.", "[fem_element_ghex140]") {

   long const ELNOX = 680;
   long const ELNO = 681;
   elements::el_types const ELTYP = elements::el_types::GHEX140;
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

   elements::ghex140 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex140 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex140 probe(682,                         // elnox
              683,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.820000000e+02+6.830000000e+02+1.400000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.830000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex140 probe;
      test << probe(686,                         // elnox
                    686,                         // elno
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
            "GELMNT1 +6.860000000e+02+6.860000000e+02+1.400000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +6.860000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX141 element definitions.", "[fem_element_ghex141]") {

   long const ELNOX = 687;
   long const ELNO = 688;
   elements::el_types const ELTYP = elements::el_types::GHEX141;
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

   elements::ghex141 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex141 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex141 probe(689,                         // elnox
              690,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.890000000e+02+6.900000000e+02+1.410000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.900000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex141 probe;
      test << probe(693,                         // elnox
                    693,                         // elno
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
            "GELMNT1 +6.930000000e+02+6.930000000e+02+1.410000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.930000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX142 element definitions.", "[fem_element_ghex142]") {

   long const ELNOX = 694;
   long const ELNO = 695;
   elements::el_types const ELTYP = elements::el_types::GHEX142;
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

   elements::ghex142 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex142 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex142 probe(696,                         // elnox
              697,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +6.960000000e+02+6.970000000e+02+1.420000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +6.970000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex142 probe;
      test << probe(700,                         // elnox
                    700,                         // elno
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
            "GELMNT1 +7.000000000e+02+7.000000000e+02+1.420000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.000000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX143 element definitions.", "[fem_element_ghex143]") {

   long const ELNOX = 701;
   long const ELNO = 702;
   elements::el_types const ELTYP = elements::el_types::GHEX143;
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

   elements::ghex143 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex143 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex143 probe(703,                         // elnox
              704,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.030000000e+02+7.040000000e+02+1.430000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.040000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex143 probe;
      test << probe(707,                         // elnox
                    707,                         // elno
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
            "GELMNT1 +7.070000000e+02+7.070000000e+02+1.430000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.070000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX144 element definitions.", "[fem_element_ghex144]") {

   long const ELNOX = 708;
   long const ELNO = 709;
   elements::el_types const ELTYP = elements::el_types::GHEX144;
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

   elements::ghex144 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex144 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex144 probe(710,                         // elnox
              711,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.100000000e+02+7.110000000e+02+1.440000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.110000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex144 probe;
      test << probe(714,                         // elnox
                    714,                         // elno
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
            "GELMNT1 +7.140000000e+02+7.140000000e+02+1.440000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.140000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX145 element definitions.", "[fem_element_ghex145]") {

   long const ELNOX = 715;
   long const ELNO = 716;
   elements::el_types const ELTYP = elements::el_types::GHEX145;
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

   elements::ghex145 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex145 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex145 probe(717,                         // elnox
              718,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.170000000e+02+7.180000000e+02+1.450000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.180000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex145 probe;
      test << probe(721,                         // elnox
                    721,                         // elno
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
            "GELMNT1 +7.210000000e+02+7.210000000e+02+1.450000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.210000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX146 element definitions.", "[fem_element_ghex146]") {

   long const ELNOX = 722;
   long const ELNO = 723;
   elements::el_types const ELTYP = elements::el_types::GHEX146;
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

   elements::ghex146 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex146 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex146 probe(724,                         // elnox
              725,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.240000000e+02+7.250000000e+02+1.460000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.250000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex146 probe;
      test << probe(728,                         // elnox
                    728,                         // elno
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
            "GELMNT1 +7.280000000e+02+7.280000000e+02+1.460000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.280000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX147 element definitions.", "[fem_element_ghex147]") {

   long const ELNOX = 729;
   long const ELNO = 730;
   elements::el_types const ELTYP = elements::el_types::GHEX147;
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

   elements::ghex147 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex147 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex147 probe(731,                         // elnox
              732,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.310000000e+02+7.320000000e+02+1.470000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +7.320000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex147 probe;
      test << probe(735,                         // elnox
                    735,                         // elno
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
            "GELMNT1 +7.350000000e+02+7.350000000e+02+1.470000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +7.350000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX148 element definitions.", "[fem_element_ghex148]") {

   long const ELNOX = 736;
   long const ELNO = 737;
   elements::el_types const ELTYP = elements::el_types::GHEX148;
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

   elements::ghex148 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex148 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex148 probe(738,                         // elnox
              739,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.380000000e+02+7.390000000e+02+1.480000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +7.390000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex148 probe;
      test << probe(742,                         // elnox
                    742,                         // elno
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
            "GELMNT1 +7.420000000e+02+7.420000000e+02+1.480000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02\n"
            "GELREF1 +7.420000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX149 element definitions.", "[fem_element_ghex149]") {

   long const ELNOX = 743;
   long const ELNO = 744;
   elements::el_types const ELTYP = elements::el_types::GHEX149;
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

   elements::ghex149 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex149 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex149 probe(745,                         // elnox
              746,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.450000000e+02+7.460000000e+02+1.490000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.460000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex149 probe;
      test << probe(749,                         // elnox
                    749,                         // elno
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
            "GELMNT1 +7.490000000e+02+7.490000000e+02+1.490000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.490000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX150 element definitions.", "[fem_element_ghex150]") {

   long const ELNOX = 750;
   long const ELNO = 751;
   elements::el_types const ELTYP = elements::el_types::GHEX150;
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

   elements::ghex150 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex150 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex150 probe(752,                         // elnox
              753,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.520000000e+02+7.530000000e+02+1.500000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.530000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex150 probe;
      test << probe(756,                         // elnox
                    756,                         // elno
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
            "GELMNT1 +7.560000000e+02+7.560000000e+02+1.500000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.560000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX151 element definitions.", "[fem_element_ghex151]") {

   long const ELNOX = 757;
   long const ELNO = 758;
   elements::el_types const ELTYP = elements::el_types::GHEX151;
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

   elements::ghex151 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex151 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex151 probe(759,                         // elnox
              760,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.590000000e+02+7.600000000e+02+1.510000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.600000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex151 probe;
      test << probe(763,                         // elnox
                    763,                         // elno
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
            "GELMNT1 +7.630000000e+02+7.630000000e+02+1.510000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.630000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX152 element definitions.", "[fem_element_ghex152]") {

   long const ELNOX = 764;
   long const ELNO = 765;
   elements::el_types const ELTYP = elements::el_types::GHEX152;
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

   elements::ghex152 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex152 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex152 probe(766,                         // elnox
              767,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.660000000e+02+7.670000000e+02+1.520000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.670000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex152 probe;
      test << probe(770,                         // elnox
                    770,                         // elno
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
            "GELMNT1 +7.700000000e+02+7.700000000e+02+1.520000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.700000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX153 element definitions.", "[fem_element_ghex153]") {

   long const ELNOX = 771;
   long const ELNO = 772;
   elements::el_types const ELTYP = elements::el_types::GHEX153;
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

   elements::ghex153 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex153 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex153 probe(773,                         // elnox
              774,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.730000000e+02+7.740000000e+02+1.530000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.740000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex153 probe;
      test << probe(777,                         // elnox
                    777,                         // elno
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
            "GELMNT1 +7.770000000e+02+7.770000000e+02+1.530000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.770000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX154 element definitions.", "[fem_element_ghex154]") {

   long const ELNOX = 778;
   long const ELNO = 779;
   elements::el_types const ELTYP = elements::el_types::GHEX154;
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

   elements::ghex154 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex154 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex154 probe(780,                         // elnox
              781,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.800000000e+02+7.810000000e+02+1.540000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.810000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex154 probe;
      test << probe(784,                         // elnox
                    784,                         // elno
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
            "GELMNT1 +7.840000000e+02+7.840000000e+02+1.540000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +7.840000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX155 element definitions.", "[fem_element_ghex155]") {

   long const ELNOX = 785;
   long const ELNO = 786;
   elements::el_types const ELTYP = elements::el_types::GHEX155;
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

   elements::ghex155 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex155 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex155 probe(787,                         // elnox
              788,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.870000000e+02+7.880000000e+02+1.550000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +7.880000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex155 probe;
      test << probe(791,                         // elnox
                    791,                         // elno
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
            "GELMNT1 +7.910000000e+02+7.910000000e+02+1.550000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +7.910000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX156 element definitions.", "[fem_element_ghex156]") {

   long const ELNOX = 792;
   long const ELNO = 793;
   elements::el_types const ELTYP = elements::el_types::GHEX156;
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

   elements::ghex156 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex156 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex156 probe(794,                         // elnox
              795,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +7.940000000e+02+7.950000000e+02+1.560000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.950000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex156 probe;
      test << probe(798,                         // elnox
                    798,                         // elno
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
            "GELMNT1 +7.980000000e+02+7.980000000e+02+1.560000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "GELREF1 +7.980000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX157 element definitions.", "[fem_element_ghex157]") {

   long const ELNOX = 799;
   long const ELNO = 800;
   elements::el_types const ELTYP = elements::el_types::GHEX157;
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

   elements::ghex157 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex157 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex157 probe(801,                         // elnox
              802,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.010000000e+02+8.020000000e+02+1.570000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +8.020000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex157 probe;
      test << probe(805,                         // elnox
                    805,                         // elno
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
            "GELMNT1 +8.050000000e+02+8.050000000e+02+1.570000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +8.050000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX158 element definitions.", "[fem_element_ghex158]") {

   long const ELNOX = 806;
   long const ELNO = 807;
   elements::el_types const ELTYP = elements::el_types::GHEX158;
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

   elements::ghex158 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex158 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex158 probe(808,                         // elnox
              809,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.080000000e+02+8.090000000e+02+1.580000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +8.090000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex158 probe;
      test << probe(812,                         // elnox
                    812,                         // elno
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
            "GELMNT1 +8.120000000e+02+8.120000000e+02+1.580000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +8.120000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX159 element definitions.", "[fem_element_ghex159]") {

   long const ELNOX = 813;
   long const ELNO = 814;
   elements::el_types const ELTYP = elements::el_types::GHEX159;
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

   elements::ghex159 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex159 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex159 probe(815,                         // elnox
              816,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.150000000e+02+8.160000000e+02+1.590000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +8.160000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex159 probe;
      test << probe(819,                         // elnox
                    819,                         // elno
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
            "GELMNT1 +8.190000000e+02+8.190000000e+02+1.590000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +8.190000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX160 element definitions.", "[fem_element_ghex160]") {

   long const ELNOX = 820;
   long const ELNO = 821;
   elements::el_types const ELTYP = elements::el_types::GHEX160;
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

   elements::ghex160 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex160 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex160 probe(822,                         // elnox
              823,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.220000000e+02+8.230000000e+02+1.600000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +8.230000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex160 probe;
      test << probe(826,                         // elnox
                    826,                         // elno
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
            "GELMNT1 +8.260000000e+02+8.260000000e+02+1.600000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02\n"
            "GELREF1 +8.260000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX161 element definitions.", "[fem_element_ghex161]") {

   long const ELNOX = 827;
   long const ELNO = 828;
   elements::el_types const ELTYP = elements::el_types::GHEX161;
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

   elements::ghex161 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex161 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex161 probe(829,                         // elnox
              830,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.290000000e+02+8.300000000e+02+1.610000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +8.300000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex161 probe;
      test << probe(833,                         // elnox
                    833,                         // elno
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
            "GELMNT1 +8.330000000e+02+8.330000000e+02+1.610000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +8.330000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX162 element definitions.", "[fem_element_ghex162]") {

   long const ELNOX = 834;
   long const ELNO = 835;
   elements::el_types const ELTYP = elements::el_types::GHEX162;
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

   elements::ghex162 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex162 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex162 probe(836,                         // elnox
              837,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.360000000e+02+8.370000000e+02+1.620000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +8.370000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex162 probe;
      test << probe(840,                         // elnox
                    840,                         // elno
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
            "GELMNT1 +8.400000000e+02+8.400000000e+02+1.620000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02\n"
            "GELREF1 +8.400000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }
}

TEST_CASE("FEM GHEX163 element definitions.", "[fem_element_ghex163]") {

   long const ELNOX = 841;
   long const ELNO = 842;
   elements::el_types const ELTYP = elements::el_types::GHEX163;
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

   elements::ghex163 probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<elements::el_processor> ({
               elements::el_processor::general, elements::el_processor::Sestra }));
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

   SECTION("simple (empty)") {
      elements::ghex163 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
   elements::ghex163 probe(843,                         // elnox
              844,                         // elno
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

      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +8.430000000e+02+8.440000000e+02+1.630000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02+1.260000000e+02\n"
            "GELREF1 +8.440000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
   }

   SECTION("reuse (check output)") {
      elements::ghex163 probe;
      test << probe(847,                         // elnox
                    847,                         // elno
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
            "GELMNT1 +8.470000000e+02+8.470000000e+02+1.630000000e+02+3.000000000e+00\n"
            "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
            "        +1.040000000e+02+1.050000000e+02+1.060000000e+02+1.070000000e+02\n"
            "        +1.080000000e+02+1.090000000e+02+1.100000000e+02+1.110000000e+02\n"
            "        +1.120000000e+02+1.130000000e+02+1.140000000e+02+1.150000000e+02\n"
            "        +1.160000000e+02+1.170000000e+02+1.180000000e+02+1.190000000e+02\n"
            "        +1.200000000e+02+1.210000000e+02+1.220000000e+02+1.230000000e+02\n"
            "        +1.240000000e+02+1.250000000e+02+1.260000000e+02\n"
            "GELREF1 +8.470000000e+02+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
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