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
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for reading and writing FEM {{ elem|upper() }} element information.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
   const char cID_test_fem_elements[]  _EXTFEMIO_UNUSED =
       "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif

#include <deque>
#include <memory>

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"
#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;

TEST_CASE("Basic test", "[fem_elemsnts_basic]") {
   elements::__base::elem::reset();
   vector<long> nodes({ 6, 7 });
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
       unique_ptr<elements::__base::elem> probe2;
       elements::dispatch(probe2, &data1);
       CHECK(probe2->get_type() == elements::el_types::TESS);
       CHECK(static_cast<elements::tess*>(probe2.get())->nnodes() == 2);
   }
}

TEST_CASE("Mapping of element types to names.", "[fem_element]") {
    {% for name, _ in enums %}SECTION("{{ name }}") {
        CHECK(name_elem(elements::el_types::{{ name }}) == "{{ name }}");
    }
    {% endfor %}
    SECTION("INVALID") {
        CHECK(name_elem(elements::el_types::INVALID) == "INVALID");
    }

    SECTION("UNDEFINED") {
        CHECK(name_elem(elements::el_types::UNDEFINED) == "UNDEFINED");
    }
}
{% for elem, vals in elements -%}
TEST_CASE("FEM {{ elem|upper() }} element definitions.", "[fem_element_{{ elem }}]") {

    long const ELNOX = 1;
    long const ELNO = 2;
    elements::el_types const ELTYP = elements::el_types::{{ elem|upper() }};
    long const ELTYAD = 2;
    vector<long> const NODIN ({{ list_init_form(100, 100+vals.nnodes) }});
    elements::__base::elem::reset();
    unique_ptr<cards::gelmnt1> gelmnt1_data(
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

    unique_ptr<cards::gelref1> gelref1_data(
        new cards::gelref1(ELNO, MATNO, ADDNO, INTNO, MINTNO,
                           STRANO, STRENO, STREPONO, GEONO_OPT,
                           FIXNO_OPT, ECCNO_OPT, TRANSNO_OPT));

    elements::{{ elem }} probe(gelmnt1_data.get());
    probe.add(gelref1_data.get());

    SECTION("check members") {

        CHECK(probe.processors == set<elements::el_processor> ({
                    {{ vals.procs|join(', ') }} }));
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
        CHECK(probe.section == vector<long>(1, GEONO_OPT));
        CHECK(probe.fixations == vector<long>(1, FIXNO_OPT));
        CHECK(probe.eccentrities == vector<long>(1, ECCNO_OPT));
        CHECK(probe.csys == vector<long>(1, TRANSNO_OPT));
    }
}

TEST_CASE("Output for {{ elem|upper() }} elements.", "[fem_element_{{ elem }}]") {

    stringstream test;

    elements::__base::elem::reset();

    SECTION("simple (empty)") {
        elements::{{ elem }} probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("check output") {
        elements::{{ elem }} probe(
            3,                    // elnox
            4,                    // elno
            3,                    // eltyad
            vector<long>({{ list_init_form(100, 100+vals.nnodes) }}), // nodin
            6,                    // matno
            7,                    // addno
            8,                    // intno
            9,                    // mintno
            10,                   // strano
            11,                   // streno
            12,                   // strepono
            vector<long>(1, 13),  // geono_opt
            vector<long>(1, 14),  // fixno_opt
            vector<long>(1, 15),  // eccno_opt
            vector<long>(1, 16)); // transno_opt

        test << probe;
        CHECK(test.str() ==
            {{ gelmnt1(*([3, 4 , vals.eltyp, 3] + list_init(100, 100+vals.nnodes))) }}
            {{ gelref1(4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }});
    }

    SECTION("check output (default elno)") {
        elements::{{ elem }} probe(
            3,                    // elnox
            3,                    // eltyad
            vector<long>({{ list_init_form(100, 100+vals.nnodes) }}), // nodin
            6,                    // matno
            7,                    // addno
            8,                    // intno
            9,                    // mintno
            10,                   // strano
            11,                   // streno
            12,                   // strepono
            vector<long>(1, 13),  // geono_opt
            vector<long>(1, 14),  // fixno_opt
            vector<long>(1, 15),  // eccno_opt
            vector<long>(1, 16)); // transno_opt

        test << probe;
        CHECK(test.str() ==
            {{ gelmnt1(*([3, 1, vals.eltyp, 3] + list_init(100, 100+vals.nnodes))) }}
            {{ gelref1(1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }});
    }

    SECTION("reuse (check output)") {
        elements::{{ elem }} probe;
        test << probe(7,                         // elnox
                      7,                         // elno
                      3,                         // eltyad
                      vector<long>({{ list_init_form(100, 100+vals.nnodes) }}), // nodin
                      6,                         // matno
                      7,                         // addno
                      8,                         // intno
                      9,                         // mintno
                      10,                        // strano
                      11,                        // streno
                      12,                        // strepono
                      vector<long>(1, 13),  // geono_opt
                      vector<long>(1, 14),  // fixno_opt
                      vector<long>(1, 15),  // eccno_opt
                      vector<long>(1, 16)); // transno_opt
        CHECK(test.str() ==
            {{ gelmnt1(*([7, 7, vals.eltyp, 3] + list_init(100, 100+vals.nnodes))) }}
            {{ gelref1(7, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }});
    }

    SECTION("reuse (check output) (use default elno)") {
        elements::{{ elem }} probe;
        test << probe(7,                    //< elnox
                      3,                    //< eltyad
                      vector<long>({{ list_init_form(100, 100+vals.nnodes) }}),
                      //< nodin
                      6,                    //< matno
                      7,                    //< addno
                      8,                    //< intno
                      9,                    //< mintno
                      10,                   //< strano
                      11,                   //< streno
                      12,                   //< strepono
                      vector<long>(1, 13),  //< geono_opt
                      vector<long>(1, 14),  //< fixno_opt
                      vector<long>(1, 15),  //< eccno_opt
                      vector<long>(1, 16)); //< transno_opt
        CHECK(test.str() ==
            {{ gelmnt1(*([7, 1, vals.eltyp, 3] + list_init(100, 100+vals.nnodes))) }}
            {{ gelref1(1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }});
    }

    SECTION("reuse (check output) (use default elno) multiple calls") {
        elements::{{ elem }} probe;
        test << probe(7,                         // elnox
                      3,                         // eltyad
                      vector<long>({{ list_init_form(100, 100+vals.nnodes) }}), // nodin
                      6,                         // matno
                      7,                         // addno
                      8,                         // intno
                      9,                         // mintno
                      10,                        // strano
                      11,                        // streno
                      12,                        // strepono
                      vector<long>(1, 13),  // geono_opt
                      vector<long>(1, 14),  // fixno_opt
                      vector<long>(1, 15),  // eccno_opt
                      vector<long>(1, 16)); // transno_opt
        test << probe(8,                         // elnox
                      3,                         // eltyad
                      vector<long>({{ list_init_form(100+vals.nnodes,
                                      100+(vals.nnodes*2)) }}), // nodin
                      6,                         // matno
                      7,                         // addno
                      8,                         // intno
                      9,                         // mintno
                      10,                        // strano
                      11,                        // streno
                      12,                        // strepono
                      vector<long>(1, 13),  // geono_opt
                      vector<long>(1, 14),  // fixno_opt
                      vector<long>(1, 15),  // eccno_opt
                      vector<long>(1, 16)); // transno_opt
        CHECK(test.str() ==
            {{ gelmnt1(*([7, 1, vals.eltyp, 3] +
                         list_init(100, 100+vals.nnodes))) }}
            {{ gelref1(1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }}
            {{ gelmnt1(*([8, 2, vals.eltyp, 3] +
                         list_init(100+vals.nnodes,
                                   100+(vals.nnodes*2)))) }}
            {{ gelref1(2, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }});
    }
}

{% endfor -%}
// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_elements --use-colour no)"
// End:
