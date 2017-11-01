/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implementation fro handling Nastran BDF ENDDATA cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_cards_enddata[]) =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#include <memory>

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

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

enddata::enddata(list<std::string> const &inp) :
card(inp) {}

cards::types enddata::card_type() const {
    return types::ENDDATA;
}

void enddata::read(list<std::string> const &inp) {}

bdf::types::card enddata::head = bdf::types::card("ENDDATA");

void enddata::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    res.push_back(unique_ptr<format_entry>(format(head)));
    return;
}

void enddata::check_data() {
}

cards::__base::card const &enddata::operator()(list<std::string> const &inp) {
    this->enddata::read(inp);
    return *this;
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
