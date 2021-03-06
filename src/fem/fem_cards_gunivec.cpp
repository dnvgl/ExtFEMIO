/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GUNIVEC` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_fem_cards_gunivec[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/types.h"

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
using namespace fem;
using namespace types;
using namespace cards;

card const gunivec::head("GUNIVEC");

// entry_type<long> const gunivec::_form_TRANSNO("TRANSNO");
entry_type<double> const gunivec::_form_UNIX("UNIX");
entry_type<double> const gunivec::_form_UNIY("UNIY");
entry_type<double> const gunivec::_form_UNIZ("UNIZ");

gunivec::gunivec(const vector<std::string> &inp, size_t const len) :
        transno(inp, len) {
    __base::card::this_type = types::GUNIVEC;
    gunivec::read(inp, len);
}

gunivec::gunivec() : gunivec(-1, 0., 0., 0.) {}

gunivec::gunivec(
    long const TRANSNO,
    double const UNIX, double const UNIY, double const UNIZ) :
        transno(TRANSNO),
        UNIX(UNIX), UNIY(UNIY), UNIZ(UNIZ) {
    __base::card::this_type = types::GUNIVEC;
}

gunivec::gunivec(
    double const UNIX, double const UNIY, double const UNIZ) :
        transno(0),
        UNIX(UNIX), UNIY(UNIY), UNIZ(UNIZ) {
    __base::card::this_type = types::GUNIVEC;
}

cards::__base::card const &gunivec::operator() (
    long const TRANSNO,
    double const UNIX, double const UNIY, double const UNIZ) {
    set_transno(TRANSNO);
    this->UNIX = UNIX;
    this->UNIY = UNIY;
    this->UNIZ = UNIZ;
    return *this;
}

cards::__base::card const &gunivec::operator() (
    double const UNIX, double const UNIY, double const UNIZ) {
    set_transno();
    this->UNIX = UNIX;
    this->UNIY = UNIY;
    this->UNIZ = UNIZ;
    return *this;
}

void gunivec::read(const vector<std::string> &inp, size_t const len) {
    if (len < 5)
        throw errors::parse_error(
            "GUNIVEC", "Illegal number of entries.");

    // TRANSNO = _form_TRANSNO(inp.at(1));
    UNIX = _form_UNIX(inp.at(2));
    UNIY = _form_UNIY(inp.at(3));
    UNIZ = _form_UNIZ(inp.at(4));
}

ostream &gunivec::put(ostream& os) const {
    if (TRANSNO == -1) return os;
    os << head.format()
       << _form_TRANSNO.format(TRANSNO) << _form_UNIX.format(UNIX)
       << _form_UNIY.format(UNIY) << _form_UNIZ.format(UNIZ) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
