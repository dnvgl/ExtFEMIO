/**
   \file fem/fem_cards_glsec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GLSEC` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_glsec[]
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

fem::types::card const glsec::head("GLSEC");

entry_type<double> const glsec::_form_HZ("HZ");
entry_type<double> const glsec::_form_TY("TY");
entry_type<double> const glsec::_form_BY("BY");
entry_type<double> const glsec::_form_TZ("TZ");
entry_type<double> const glsec::_form_SFY("SFY");
entry_type<double> const glsec::_form_SFZ("SFZ");
entry_type<bool> const glsec::_form_K("K");
entry_type<long> const glsec::_form_NLOBY("NLOBY");
entry_type<long> const glsec::_form_NLOBZ("NLOBZ");

glsec::glsec(vector<std::string> const &inp, size_t const len) :
        __base::beam_prop(inp, len) {
    read(inp, len);
}

void glsec::read(vector<std::string> const &inp, size_t const len) {
    if (len < 9)
        throw errors::parse_error(
            "GLSEC", "Illegal number of entries.");

    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BY = _form_BY(inp.at(4));
    TZ = _form_TZ(inp.at(5));
    SFY = _form_SFY(inp.at(6));
    SFZ = _form_SFZ(inp.at(7));
    K = _form_K(inp.at(8));
    if (len > 9)
        NLOBY = _form_NLOBY(inp.at(9));
    else
        NLOBY = {0};
    if (len > 10)
        NLOBZ = _form_NLOBZ(inp.at(10));
    else
        NLOBZ = {0};
}

glsec::glsec(void) :
        glsec(-1, 0., 0., 0., 0., 0., 0., false) {}

glsec::glsec(long const GEONO, double const HZ,
             double const TY, double const BY,
             double const TZ, double const SFY,
             double const SFZ, bool const K,
             long const NLOBY/*=0*/, long const NLOBZ/*=0*/) :
        __base::beam_prop(GEONO),
        HZ(HZ), TY(TY), BY(BY), TZ(TZ),
        SFY(SFY), SFZ(SFZ),
        K(K), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

dnvgl::extfem::fem::cards::types const
glsec::card_type(void) const {return types::GLSEC;}

std::ostream &glsec::put(std::ostream& os) const {
    if (GEONO == -1) return os;
    os << glsec::head.format()
       << _form_GEONO.format(GEONO)
       << _form_HZ.format(HZ)
       << _form_TY.format(TY)
       << _form_BY.format(BY)
       << std::endl << dnvgl::extfem::fem::types::card().format()
       << _form_TZ.format(TZ)
       << _form_SFY.format(SFY)
       << _form_SFZ.format(SFZ)
       << _form_K.format(K)
       << std::endl;
    if (!(NLOBY || NLOBZ))
        return os;
    os << dnvgl::extfem::fem::types::card().format()
       << _form_NLOBY.format(NLOBY)
       << _form_NLOBZ.format(NLOBZ)
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
