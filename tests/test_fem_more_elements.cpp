/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for reading and writing FEM  element information.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_more_elements[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <deque>
#include <memory>

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"
#include "fem/elements.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;

TEST_CASE("Output for various elements.", "[fem_element]") {

    elements::__base::elem::reset();

    std::stringstream test;

    elements::beas beas;
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

    SECTION("multiple element types") {
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
        test << fqus(1,                         // elnox
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
        test << ftrs(1,                         // elnox
                     2,                         // elno
                     3,                         // eltyad
                     std::vector<long>({100, 101, 104}), // nodin
                     6,                         // matno
                     7,                         // addno
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
              "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"
              "GELMNT1 +2.000000000e+00+1.000000000e+00+2.400000000e+01+3.000000000e+00\n"
              "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
              "GELREF1 +1.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"
              "GELMNT1 +3.000000000e+00+3.000000000e+00+2.500000000e+01+3.000000000e+00\n"
              "        +1.000000000e+02+1.010000000e+02+1.040000000e+02\n"
              "GELREF1 +3.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
    }

    SECTION("multiple element types (auto id)") {
        test << beps(3,                         // eltyad
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
        test << fqus(3,                         // eltyad
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
        test << ftrs(3,                         // eltyad
                     std::vector<long>({100, 101, 104}), // nodin
                     6,                         // matno
                     7,                         // addno
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
              "GELMNT1 +1.000000000e+00+1.000000000e+00+2.000000000e+00+3.000000000e+00\n"
              "        +1.000000000e+02+1.010000000e+02\n"
              "GELREF1 +1.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"
              "GELMNT1 +2.000000000e+00+2.000000000e+00+2.400000000e+01+3.000000000e+00\n"
              "        +1.000000000e+02+1.010000000e+02+1.020000000e+02+1.030000000e+02\n"
              "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"
              "GELMNT1 +3.000000000e+00+3.000000000e+00+2.500000000e+01+3.000000000e+00\n"
              "        +1.000000000e+02+1.010000000e+02+1.040000000e+02\n"
              "GELREF1 +3.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");
    }

    SECTION("multiple element types (auto id) (2)") {
        test << beas(0, // eltyad
                     std::vector<long>({100, 101}), // nodin
                     6, // matno
                     7, // addno
                     8, // intno
                     9, // mintno
                     10, // strano
                     11, // streno
                     12, // strepono
                     std::vector<long>({13, 14})); // geono_opt
        test << beas(0, // eltyad
                     {101, 102}, // nodin
                     6, // matno
                     7, // addno
                     8, // intno
                     9, // mintno
                     10, // strano
                     11, // streno
                     12, // strepono
                     {13, 14}); // geono_opt
        test << beas(0, // eltyad
                     {102, 103}, // nodin
                     6, // matno
                     7, // addno
                     8, // intno
                     9, // mintno
                     10, // strano
                     11, // streno
                     12, // strepono
                     {13, 14}); // geono_opt
        CHECK(test.str() ==
              "GELMNT1 +1.000000000e+00+1.000000000e+00+1.500000000e+01+0.000000000e+00\n"
              "        +1.000000000e+02+1.010000000e+02\n"
              "GELREF1 +1.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        -1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +1.300000000e+01+1.400000000e+01\n"
              "GELMNT1 +2.000000000e+00+2.000000000e+00+1.500000000e+01+0.000000000e+00\n"
              "        +1.010000000e+02+1.020000000e+02\n"
              "GELREF1 +2.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        -1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +1.300000000e+01+1.400000000e+01\n"
              "GELMNT1 +3.000000000e+00+3.000000000e+00+1.500000000e+01+0.000000000e+00\n"
              "        +1.020000000e+02+1.030000000e+02\n"
              "GELREF1 +3.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        -1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +1.300000000e+01+1.400000000e+01\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_elements --use-colour no)"
// End:
