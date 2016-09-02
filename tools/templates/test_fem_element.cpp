/**
   \file test_fem_element_{{ elem }}.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for reading and writing FEM {{ elem|upper() }} element information.

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

TEST_CASE("FEM {{ elem|upper() }} element definitions.", "[fem_element_{{ elem }}]") {

   long const ELNOX = 11316;
   long const ELNO = 1;
   el_types const ELTYP = {{ elem|upper() }};
   long const ELTYAD = 2;
   std::vector<long> const NODIN ({ {{ range(100, 100+nnodes)|join(", ") }} });
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

   {{ elem }} probe(gelmnt1_data.get());
   probe.add(gelref1_data.get());

   SECTION("check members") {

      CHECK(probe.processors == std::set<el_processor> ({
               {{ procs|join(', ') }} }));
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

TEST_CASE("Output for {{ elem|upper() }} elements.", "[fem_element_{{ elem }}]") {

   std::stringstream test;

   {{ elem }} probe(1,                         // elnox
              2,                         // elno
              3,                         // eltyad
              std::vector<long>({ {{ range(100, 100+nnodes)|join(", ") }} }), // nodin
              6,                         // matno
              7,                         // addno
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
      {{ elem }} probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("check output") {
      test << probe;
      CHECK(test.str() ==
            {{ gelmnt1(*([1, 2, eltyp, 3] + range(100, 100+nnodes)|list())) }}
            {{ gelref1(2, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) }});
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End: