/**
   \file fem/fem_cards_gunivec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GUNIVEC` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_gunivec[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#include <memory>
#include <algorithm>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace dnvgl::extfem::fem::cards;

const fem::types::card gunivec::head("GUNIVEC");

const entry_type<long> gunivec::_form_TRANSNO("TRANSNO");
const entry_type<double> gunivec::_form_UNIX("UNIX");
const entry_type<double> gunivec::_form_UNIY("UNIY");
const entry_type<double> gunivec::_form_UNIZ("UNIZ");

gunivec::gunivec(const vector<std::string> &inp, size_t const &len) {
    read(inp, len);
}

void gunivec::read(const vector<std::string> &inp, size_t const &len) {
    if (len < 5)
        throw errors::parse_error(
            "GUNIVEC", "Illegal number of entries.");

    TRANSNO = _form_TRANSNO(inp.at(1));
    UNIX = _form_UNIX(inp.at(2));
    UNIY = _form_UNIY(inp.at(3));
    UNIZ = _form_UNIZ(inp.at(4));
}

gunivec::gunivec(void) :
        gunivec(-1, 0., 0., 0.) {}

gunivec::gunivec(const long &TRANSNO,
                 const double &UNIX,
                 const double &UNIY,
                 const double &UNIZ) :
        card(), TRANSNO(TRANSNO),
        UNIX(UNIX), UNIY(UNIY), UNIZ(UNIZ) {}

const dnvgl::extfem::fem::cards::types
gunivec::card_type(void) const {return types::GUNIVEC;}

std::ostream &gunivec::put(std::ostream& os) const {
    if (TRANSNO == -1) return os;
    os << gunivec::head.format()
       << _form_TRANSNO.format(TRANSNO)
       << _form_UNIX.format(UNIX)
       << _form_UNIY.format(UNIY)
       << _form_UNIZ.format(UNIZ)
       << std::endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
