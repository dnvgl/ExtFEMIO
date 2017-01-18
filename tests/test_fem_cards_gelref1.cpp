/**
   \file tests/test_fem_cards_gelref1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GELREF1` cards.

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

#include <catch.hpp>

#include "config.h"

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex.what();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GELREF1 definitions.", "[fem_gelref1]" ) {

   std::list<std::string> lines;

   SECTION("GELREF1 (sample 1)") {
      std::list<std::string> data({
         "GELREF1  1.80000000e+001 3.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});

      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 1);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == 0);
      CHECK(probe.TRANSNO_OPT == 0);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }

   SECTION("GELREF1 (sample 2)") {
      std::list<std::string> data({
         "GELREF1  1.70000000e+001 3.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         1.03005000e+005 0.00000000e+000-1.00000000e+000 1.70000000e+001\n",
         "         3.30000000e+001 3.40000000e+001 0.00000000e+000 0.00000000e+000\n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 17);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 103005);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == -1);
      CHECK(probe.TRANSNO_OPT == 17);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({33, 34}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }


   SECTION("GELREF1 (sample 3)") {
      std::list<std::string> data({
         "GELREF1 +1.80000000e+01 +3.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +1.03005000e+05 +0.00000000e+00 -1.00000000e+00 +1.70000000e+01 \n",
         "        +3.30000000e+01 +3.40000000e+01  0.00000000e+00  0.00000000e+00 \n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 103005);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == -1);
      CHECK(probe.TRANSNO_OPT == 17);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({33, 34}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }

   SECTION("GELREF1 (sample 4)") {
      std::list<std::string> data({
         "GELREF1 +1.80000000e+01 +3.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        -1.00000000e+00 +0.00000000e+00 +1.03005000e+05 +1.70000000e+01 \n",
         "        +3.30000000e+01 +3.40000000e+01  0.00000000e+00  0.00000000e+00 \n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == -1);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == 103005);
      CHECK(probe.TRANSNO_OPT == 17);
      CHECK(probe.GEONO.size() == 2);
      CHECK(probe.GEONO[0] == 33);
      CHECK(probe.GEONO[1] == 34);
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }

   SECTION("GELREF1 (sample 5") {
      std::list<std::string> data({
         "GELREF1 +1.80000000e+01 +3.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +1.03005000e+05 -1.00000000e+00 +1.00000000e+00 +1.70000000e+01 \n",
         "        +3.30000000e+01 +3.40000000e+01  0.00000000e+00  0.00000000e+00 \n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 103005);
      CHECK(probe.FIXNO_OPT == -1);
      CHECK(probe.ECCNO_OPT == 1);
      CHECK(probe.TRANSNO_OPT == 17);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO.size() == 2);
      CHECK(probe.FIXNO[0] == 33);
      CHECK(probe.FIXNO[1] == 34);
      CHECK(probe.ECCNO == std::vector<long>({}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }

   SECTION("GELREF1 (sample 6") {
      std::list<std::string> data({
         "GELREF1 +1.80000000e+01 +3.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n",
         "        +1.03005000e+05 +0.00000000e+00 +1.00000000e+00 -1.00000000e+00 \n",
         "        +3.30000000e+01 +3.40000000e+01  0.00000000e+00  0.00000000e+00 \n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 103005);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == 1);
      CHECK(probe.TRANSNO_OPT == -1);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({}));
      CHECK(probe.TRANSNO.size() == 2);
      CHECK(probe.TRANSNO[0] == 33);
      CHECK(probe.TRANSNO[1] == 34);
   }
}

TEST_CASE("FEMIO-28: Failing to import GELREF1 card from SESAM GeniE FEM file") {

   std::list<std::string> lines;

   SECTION("Failing card") {
      std::list<std::string> data({
            "GELREF1   5.61680000E+04  3.00000000E+00  0.00000000E+00  0.00000000E+00\n",
            "          0.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
            "          1.10000000E+01  0.00000000E+00 -1.00000000E+00  6.00000000E+00\n",
            "          1.80000000E+01  1.90000000E+01\n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 56168);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 11);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == -1);
      CHECK(probe.TRANSNO_OPT == 6);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({18, 19}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }
}
TEST_CASE("FEM GELREF1 types output.", "[fem_gelref1,out]" ) {

   std::ostringstream test;

   SECTION("GELREF1 OUT (empty)") {
      gelref1 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("GELREF1 OUT (sample 1)") {
      long ELNO(18), MATNO(3), ADDNO(0), INTNO(0), MINTNO(0), STRANO(0),
         STRENO(0), STREPONO(0), GEONO_OPT(1), FIXNO_OPT(0),
         ECCNO_OPT(0), TRANSNO_OPT(0);
      std::vector<long> GEONO, FIXNO, ECCNO, TRANSNO;

      gelref1 probe(ELNO, MATNO, ADDNO, INTNO, MINTNO, STRANO,
                    STRENO, STREPONO, GEONO_OPT, FIXNO_OPT,
                    ECCNO_OPT, TRANSNO_OPT, GEONO, FIXNO, ECCNO,
                    TRANSNO);
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n");
   }

   SECTION("GELREF1 OUT (sample 2)") {
      long ELNO(18), MATNO(3), ADDNO(0), INTNO(0), MINTNO(0), STRANO(0),
         STRENO(0), STREPONO(0), GEONO_OPT(103005), FIXNO_OPT(0),
         ECCNO_OPT(-1), TRANSNO_OPT(17);
      std::vector<long> GEONO, FIXNO, ECCNO({33, 34});

      gelref1 probe(ELNO, MATNO, ADDNO, INTNO, MINTNO, STRANO,
                    STRENO, STREPONO, GEONO_OPT, FIXNO_OPT,
                    ECCNO_OPT, TRANSNO_OPT, GEONO, FIXNO, ECCNO);
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +1.030050000e+05+0.000000000e+00-1.000000000e+00+1.700000000e+01\n"
            "        +3.300000000e+01+3.400000000e+01\n");
   }

   SECTION("GELREF1 OUT (sample cons)") {
      gelref1 probe(18, 3, 0, 0, 0, 0, 0, 0, 103005, 0, -1, 17,
                    {}, {}, {33, 34}, {});
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +1.030050000e+05+0.000000000e+00-1.000000000e+00+1.700000000e+01\n"
            "        +3.300000000e+01+3.400000000e+01\n");
   }

   SECTION("GELREF1 OUT (sample 3)") {
      long ELNO(18), MATNO(3), ADDNO(0), INTNO(0), MINTNO(0), STRANO(0),
         STRENO(0), STREPONO(0), GEONO_OPT(103005), FIXNO_OPT(0),
         ECCNO_OPT(-1), TRANSNO_OPT(17);
      std::vector<long> GEONO, FIXNO, ECCNO, TRANSNO;

      ECCNO.push_back(33);
      ECCNO.push_back(34);

      gelref1 probe(ELNO, MATNO, ADDNO, INTNO, MINTNO, STRANO,
                    STRENO, STREPONO, GEONO_OPT, FIXNO_OPT,
                    ECCNO_OPT, TRANSNO_OPT, GEONO, FIXNO, ECCNO,
                    TRANSNO);
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +1.030050000e+05+0.000000000e+00-1.000000000e+00+1.700000000e+01\n"
            "        +3.300000000e+01+3.400000000e+01\n");
   }

   SECTION("GELREF1 OUT (sample 4)") {
      long ELNO(18), MATNO(3), ADDNO(0), INTNO(0), MINTNO(0), STRANO(0),
         STRENO(0), STREPONO(0), GEONO_OPT(-1), FIXNO_OPT(0),
         ECCNO_OPT(103005), TRANSNO_OPT(17);
      std::vector<long> GEONO({33, 34});

      gelref1 probe(ELNO, MATNO, ADDNO, INTNO, MINTNO, STRANO,
                    STRENO, STREPONO, GEONO_OPT, FIXNO_OPT,
                    ECCNO_OPT, TRANSNO_OPT, GEONO);
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        -1.000000000e+00+0.000000000e+00+1.030050000e+05+1.700000000e+01\n"
            "        +3.300000000e+01+3.400000000e+01\n");
   }

   SECTION("GELREF1 OUT (sample 5)") {
      long ELNO(18), MATNO(3), ADDNO(0), INTNO(0), MINTNO(0), STRANO(0),
         STRENO(0), STREPONO(0), GEONO_OPT(103005), FIXNO_OPT(-1),
         ECCNO_OPT(1), TRANSNO_OPT(17);
      std::vector<long> GEONO, FIXNO({33, 34});

      gelref1 probe(ELNO, MATNO, ADDNO, INTNO, MINTNO, STRANO,
                    STRENO, STREPONO, GEONO_OPT, FIXNO_OPT,
                    ECCNO_OPT, TRANSNO_OPT, GEONO, FIXNO);
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +1.030050000e+05-1.000000000e+00+1.000000000e+00+1.700000000e+01\n"
            "        +3.300000000e+01+3.400000000e+01\n");
   }
   SECTION("GELREF1 OUT (sample 6)") {
      long ELNO(18), MATNO(3), ADDNO(0), INTNO(0), MINTNO(0), STRANO(0),
         STRENO(0), STREPONO(0), GEONO_OPT(103005), FIXNO_OPT(0),
         ECCNO_OPT(1), TRANSNO_OPT(-1);
      std::vector<long> GEONO, FIXNO, ECCNO, TRANSNO({33, 34});

      gelref1 probe(ELNO, MATNO, ADDNO, INTNO, MINTNO, STRANO,
                    STRENO, STREPONO, GEONO_OPT, FIXNO_OPT,
                    ECCNO_OPT, TRANSNO_OPT, GEONO, FIXNO, ECCNO,
                    TRANSNO);
      test << probe;
      CHECK(test.str() ==
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
            "        +1.030050000e+05+0.000000000e+00+1.000000000e+00-1.000000000e+00\n"
            "        +3.300000000e+01+3.400000000e+01\n");
   }
}

TEST_CASE("FEM GELREF1 conversion from own output.", "[fem_gelref1,in/out]") {

   std::list<std::string> lines;

   SECTION("GELREF1 (sample 1)") {
      std::list<std::string> data({
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 1);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == 0);
      CHECK(probe.TRANSNO_OPT == 0);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }

   SECTION("GELREF1 (sample 2)") {
      std::list<std::string> data({
            "GELREF1 +1.800000000e+01+3.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +1.030050000e+05+0.000000000e+00-1.000000000e+00+1.700000000e+01\n",
            "        +3.300000000e+01+3.400000000e+01\n"});
      __base::card::card_split(data, lines);
      gelref1 probe(lines);

      CHECK(probe.ELNO == 18);
      CHECK(probe.MATNO == 3);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.INTNO == 0);
      CHECK(probe.MINTNO == 0);
      CHECK(probe.STRANO == 0);
      CHECK(probe.STRENO == 0);
      CHECK(probe.STREPONO == 0);
      CHECK(probe.GEONO_OPT == 103005);
      CHECK(probe.FIXNO_OPT == 0);
      CHECK(probe.ECCNO_OPT == -1);
      CHECK(probe.TRANSNO_OPT == 17);
      CHECK(probe.GEONO == std::vector<long>({}));
      CHECK(probe.FIXNO == std::vector<long>({}));
      CHECK(probe.ECCNO == std::vector<long>({33, 34}));
      CHECK(probe.TRANSNO == std::vector<long>({}));
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
