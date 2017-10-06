/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `MGSPRNG` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_mgsprng[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM MGSPRNG definitions.", "[fem_mgsprng]") {

    std::vector<std::vector<double> > ref_K(6);
    for (auto i = 0; i < 6; i++) {
        ref_K[i] = std::vector<double>(6);
        for (auto j = 0; j < 6; j++)
            ref_K[i][j] = 0;
    }
    ref_K[1][1] = 1e8;

    vector<std::string> lines;
    size_t len;

    SECTION("MGSPRNG (1)") {
        vector<std::string> data({
            "MGSPRNG  7.00000000e+001 6.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         1.00000000e+008 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        mgsprng probe(lines, len);

        CHECK(probe.MATNO == 70);
        CHECK(probe.NDOF == 6);
        CHECK(probe.K.size() == 6);
        for (int i = 0; i < 6; i++)
            CHECK(probe.K[i].size() == 6);
        CHECK(probe.K == ref_K);
    }

    SECTION("MGSPRNG (2)") {
        vector<std::string> data({
            "MGSPRNG  7.00000000e+01  6.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
            "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
            "         1.00000000e+08  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
            "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
            "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
            "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        mgsprng probe(lines, len);

        CHECK(probe.MATNO == 70);
        CHECK(probe.NDOF == 6);
        CHECK(probe.K.size() == 6);
        for (int i = 0; i < 6; i++)
            CHECK(probe.K[i].size() == 6);
        CHECK(probe.K == ref_K);
    }

    SECTION("MGSPRNG (3)") {

        std::vector<std::vector<double> > ref_K_l(6);
        ref_K_l[0] = std::vector<double>({1., 2., 3., 4., 5., 6.});
        ref_K_l[1] = std::vector<double>({2., 7., 8., 9., 10., 11.});
        ref_K_l[2] = std::vector<double>({3., 8., 12., 13., 14., 15.});
        ref_K_l[3] = std::vector<double>({4., 9., 13., 16., 17., 18.});
        ref_K_l[4] = std::vector<double>({5., 10., 14., 17., 19., 20.});
        ref_K_l[5] = std::vector<double>({6., 11., 15., 18., 20., 21.});

        vector<std::string> data({
            "MGSPRNG  7.00000000e+01  6.00000000e+00  1.00000000e+00  2.00000000e+00 \n",
            "         3.00000000e+00  4.00000000e+00  5.00000000e+00  6.00000000e+00 \n",
            "         7.00000000e+00  8.00000000e+00  9.00000000e+00  1.00000000e+01 \n",
            "         1.10000000e+01  1.20000000e+01  1.30000000e+01  1.40000000e+01 \n",
            "         1.50000000e+01  1.60000000e+01  1.70000000e+01  1.80000000e+01 \n",
            "         1.90000000e+01  2.00000000e+01  2.10000000e+01  0.00000000e+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        mgsprng probe(lines, len);

        CHECK(probe.MATNO == 70);
        CHECK(probe.NDOF == 6);
        CHECK(probe.K.size() == 6);
        for (auto i = 0; i < 6; i++)
            CHECK(probe.K[i].size() == 6);

        CHECK(probe.K == ref_K_l);
    }
}

TEST_CASE("FEM MGSPRNG types output.", "[fem_mgsprng,out]") {

    std::ostringstream test;

    double c_ref_K[6] = {0., 0., 0., 0., 0., 0.};
    std::vector<std::vector<double> > ref_K(6);
    for (auto i = 0; i < 6; i++)
        ref_K[i] = std::vector<double>(c_ref_K, c_ref_K + 6);
    ref_K[1][1] = 999;

    SECTION("empty") {
        mgsprng probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        mgsprng probe(1, 6, ref_K);
        test << probe;
        CHECK(test.str() ==
              "MGSPRNG +1.000000000e+00+6.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +9.990000000e+02+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00\n");
    }

    SECTION("calc NDOF") {
        mgsprng probe(1, ref_K);
        test << probe;
        CHECK(test.str() ==
              "MGSPRNG +1.000000000e+00+6.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +9.990000000e+02+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00+0.000000000e+00+0.000000000e+00\n");
    }

    SECTION("all vals std::set") {
        vector<vector<double> > ref_K_l(6);
        ref_K_l[0] = vector<double>({1., 2., 3., 4., 5., 6.});
        ref_K_l[1] = vector<double>({2., 7., 8., 9., 10., 11.});
        ref_K_l[2] = vector<double>({3., 8., 12., 13., 14., 15.});
        ref_K_l[3] = vector<double>({4., 9., 13., 16., 17., 18.});
        ref_K_l[4] = vector<double>({5., 10., 14., 17., 19., 20.});
        ref_K_l[5] = vector<double>({6., 11., 15., 18., 20., 21.});


        mgsprng probe(1, ref_K_l);
        test << probe;
        CHECK(test.str() ==
              "MGSPRNG +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n"
              "        +7.000000000e+00+8.000000000e+00+9.000000000e+00+1.000000000e+01\n"
              "        +1.100000000e+01+1.200000000e+01+1.300000000e+01+1.400000000e+01\n"
              "        +1.500000000e+01+1.600000000e+01+1.700000000e+01+1.800000000e+01\n"
              "        +1.900000000e+01+2.000000000e+01+2.100000000e+01\n");
    }
}

TEST_CASE("FEM MGSPRNG conversion from own output.", "[fem_mgsprng,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("MGSPRNG (1)") {
        vector<std::string> data({
            "MGSPRNG +1.000000000e+00+6.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +9.990000000e+02+0.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n",
            "        +0.000000000e+00+0.000000000e+00+0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        mgsprng probe(lines, len);

        CHECK(probe.MATNO == 1);
        CHECK(probe.NDOF == 6);
        CHECK(probe.K.size() == 6);
        vector<vector<double> > ref_K(6);
        ref_K[0] = vector<double>({0., 0., 0., 0., 0., 0.});
        ref_K[1] = vector<double>({0., 999., 0., 0., 0., 0.});
        ref_K[2] = vector<double>({0., 0., 0., 0., 0., 0.});
        ref_K[3] = vector<double>({0., 0., 0., 0., 0., 0.});
        ref_K[4] = vector<double>({0., 0., 0., 0., 0., 0.});
        ref_K[5] = vector<double>({0., 0., 0., 0., 0., 0.});
        CHECK(probe.K == ref_K);
    }

    SECTION("MGSPRNG (2)") {
        vector<std::string> data({
            "MGSPRNG +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n",
            "        +7.000000000e+00+8.000000000e+00+9.000000000e+00+1.000000000e+01\n",
            "        +1.100000000e+01+1.200000000e+01+1.300000000e+01+1.400000000e+01\n",
            "        +1.500000000e+01+1.600000000e+01+1.700000000e+01+1.800000000e+01\n",
            "        +1.900000000e+01+2.000000000e+01+2.100000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        mgsprng probe(lines, len);

        CHECK(probe.MATNO == 1);
        CHECK(probe.NDOF == 6);
        CHECK(probe.K.size() == 6);
        vector<vector<double> > ref_K(6);
        ref_K[0] = vector<double>({1., 2., 3., 4., 5., 6.});
        ref_K[1] = vector<double>({2., 7., 8., 9., 10., 11.});
        ref_K[2] = vector<double>({3., 8., 12., 13., 14., 15.});
        ref_K[3] = vector<double>({4., 9., 13., 16., 17., 18.});
        ref_K[4] = vector<double>({5., 10., 14., 17., 19., 20.});
        ref_K[5] = vector<double>({6., 11., 15., 18., 20., 21.});
        CHECK(probe.K == ref_K);
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
