/**
   \file bdf/bdf_cards_enddata.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implementation fro handling Nastran BDF ENDDATA cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_enddata[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#include <cstdlib>
#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf::cards;

enddata::enddata(list<std::string> const &inp) :
__base::card(inp) {}

enddata::enddata(void) : __base::card() {}

const types enddata::card_type(void) const {
    return types::ENDDATA;
}

void enddata::read(list<std::string> const &inp) {}

bdf::types::card enddata::head = bdf::types::card("ENDDATA");

void enddata::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    res.push_back(unique_ptr<format_entry>(format(enddata::head)));
    return;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
