/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BNBCD` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_bnbcd[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM BNBCD definitions.", "[fem_bnbcd]") {

    vector<std::string> lines;

    size_t len;

    SECTION("BNBCD (1)") {
        vector<std::string> data({
            "BNBCD    8.31700000e+003 6.00000000e+000 1.00000000e+000 1.00000000e+000\n",
            "         1.00000000e+000 1.00000000e+000 0.00000000e+000 1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bnbcd probe(lines, len);

        CHECK(probe.NODENO == 8317);
        CHECK(probe.NDOF == 6);
        CHECK(probe.FIX == std::vector<bnbcd::fix_key>({
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX}));
    }

    SECTION("BNBCD (2)") {
        vector<std::string> data({
            "BNBCD    8.31700000e+03  6.000000000e+00 1.000000000e+00 1.000000000e+00\n",
            "         1.000000000e+00 1.000000000e+00 0.000000000e+00 1.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bnbcd probe(lines, len);

        CHECK(probe.NODENO == 8317);
        CHECK(probe.NDOF == 6);
        CHECK(probe.FIX == std::vector<bnbcd::fix_key>({
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX}));
    }

    SECTION("BNBCD (2)") {
        vector<std::string> data({
            "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bnbcd probe(lines, len);

        CHECK(probe.NODENO == 1);
        CHECK(probe.NDOF == 3);
        CHECK(probe.FIX == std::vector<bnbcd::fix_key>({
            bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::PRESCRIBED,
            bnbcd::fix_key::LINDEP}));
    }

    SECTION("reuse (BNBCD)") {
        vector<std::string> data({
            "BNBCD    8.31700000e+003 6.00000000e+000 1.00000000e+000 1.00000000e+000\n",
            "         1.00000000e+000 1.00000000e+000 0.00000000e+000 1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bnbcd probe;
        probe(lines, len);

        CHECK(probe.NODENO == 8317);
        CHECK(probe.NDOF == 6);
        CHECK(probe.FIX == std::vector<bnbcd::fix_key>({
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::DISPL_FIX,
            bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX}));
    }
}

TEST_CASE("FEM BNBCD types output.", "[fem_bnbcd,, 6out]") {

    std::ostringstream test;

    bnbcd::fix_key inp_fix[6] = {
        bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::PRESCRIBED,
        bnbcd::fix_key::LINDEP, bnbcd::fix_key::RETAINED,
        bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX};

    SECTION("empty") {
        bnbcd probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        bnbcd probe(1, 6, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 6));
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n");
    }

    SECTION("simple (const)") {
        bnbcd probe(1, 6, {bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::PRESCRIBED,
                    bnbcd::fix_key::LINDEP, bnbcd::fix_key::RETAINED,
                    bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX});
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n");
    }

    SECTION("simple (2)") {
        bnbcd probe(1, 3, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 3));
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00\n");
    }

    SECTION("calc ndof") {
        bnbcd probe(1, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 6));
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n");
    }

    SECTION("calc ndof (2)") {
        bnbcd probe(1, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 3));
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00\n");
    }
    SECTION("calc ndof (2)") {
        bnbcd probe(1, true, false, true, false, true, false);
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n");
    }

    SECTION("reuse (simple)") {
        bnbcd probe;
        test << probe(1, 6, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 6));
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n");
    }

    SECTION("reuse (simple (const))") {
        bnbcd probe;
        test << probe(1, 6, {bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::PRESCRIBED,
                      bnbcd::fix_key::LINDEP, bnbcd::fix_key::RETAINED,
                      bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX});
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n");
    }

    SECTION("reuse (simple (2))") {
        bnbcd probe;
        test << probe(1, 3, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 3));
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00\n");
    }

    SECTION("reuse (calc ndof)") {
        bnbcd probe;
        test << probe(1, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 6));
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n");
    }

    SECTION("reuse (calc ndof (2))") {
        bnbcd probe;
        test << probe(1, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 3));
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00\n");
    }
    SECTION("reuse (calc ndof (2))") {
        bnbcd probe;
        test << probe(1, true, false, true, false, true, false);
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n");
    }

    SECTION("reuse (multiple)") {
        bnbcd probe;
        test << probe;
        test << probe(1, 6, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 6));
        test << probe(1, 6, {bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::PRESCRIBED,
                      bnbcd::fix_key::LINDEP, bnbcd::fix_key::RETAINED,
                      bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX});
        test << probe(1, 3, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 3));
        test << probe(1, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 6));
        test << probe(1, std::vector<bnbcd::fix_key>(inp_fix, inp_fix + 3));
        test << probe(1, true, false, true, false, true, false);
        test << probe;
        CHECK(test.str() ==
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00\n"
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00\n"
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n");
    }
}

TEST_CASE("FEM BNBCD conversion from own output.", "[fem_bnbcd,in/out]") {

    vector<std::string> lines;

    size_t len;

    SECTION("BNBCD (1)") {
        vector<std::string> data({
            "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bnbcd probe(lines, len);

        CHECK(probe.NODENO == 1);
        CHECK(probe.NDOF == 3);
        CHECK(probe.FIX == std::vector<bnbcd::fix_key>({
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::PRESCRIBED,
            bnbcd::fix_key::LINDEP}));
    }

    SECTION("BNBCD (2)") {
        vector<std::string> data({
            "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+0.000000000e+00+1.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bnbcd probe(lines, len);

        CHECK(probe.NODENO == 1);
        CHECK(probe.NDOF == 6);
        CHECK(probe.FIX == std::vector<bnbcd::fix_key>({
            bnbcd::fix_key::DISPL_FIX, bnbcd::fix_key::PRESCRIBED,
            bnbcd::fix_key::LINDEP, bnbcd::fix_key::RETAINED,
            bnbcd::fix_key::FREE, bnbcd::fix_key::DISPL_FIX}));
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
