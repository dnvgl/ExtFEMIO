/**
   \file bdf/bdf_cards_cquad4.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF CQUAD4 cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char cID_bdf_cards_cquad4[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/errors.h"

#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;

using types::entry_type;

using namespace cards;

cquad4::cquad4(const std::list<std::string> &inp) :
shell(inp) {
    this->cquad4::read(inp);
}

void cquad4::read(const std::list<std::string> &inp) {
    auto pos = inp.rbegin();

    form_THETA.set_value(THETA, "");
    form_ZOFFS.set_value(ZOFFS, "");
    form_TFLAG.set_value(TFLAG, "");
    form_T1.set_value(T1, "");
    form_T2.set_value(T2, "");
    form_T3.set_value(T3, "");
    form_T4.set_value(T4, "");

    switch (inp.size() - 1) {
    case 16:
        ++pos;
    case 15:
        ++pos;
    case 14:
        form_T4.set_value(T4, *(pos++));
    case 13:
        form_T3.set_value(T3, *(pos++));
    case 12:
        form_T2.set_value(T2, *(pos++));
    case 11:
        form_T1.set_value(T1, *(pos++));
    case 10:
        form_TFLAG.set_value(TFLAG, *(pos++));
    case 9:
        ++pos;
    case 8:
        form_ZOFFS.set_value(ZOFFS, *(pos++));
    case 7:
        try {
            form_THETA.set_value(THETA, *pos);
            MCID.is_value = false;
            choose_mcid_theta = CHOOSE_MCID_THETA::has_THETA;
        } catch (errors::float_error) {
            try {
                form_MCID.set_value(MCID, *pos);
                form_THETA.set_value(THETA, "");
                choose_mcid_theta = CHOOSE_MCID_THETA::has_MCID;
            } catch (errors::int_error) {
                THETA.is_value = true;
                THETA.value = 0.;
                MCID.is_value = false;
                choose_mcid_theta = CHOOSE_MCID_THETA::has_THETA;
            }
        }
        ++pos;
    case 6:
        form_G4.set_value(G4, *(pos++));
        form_G3.set_value(G3, *(pos++));
        form_G2.set_value(G2, *(pos++));
        form_G1.set_value(G1, *(pos++));
        form_PID.set_value(PID, *(pos++));
        // form_EID.set_value(EID, *pos);
        break;
    default:
        throw errors::parse_error(
            "CQUAD4", "Illegal number of entries.");
    }

    if (!THETA.is_value && !MCID.is_value)
        form_THETA.set_value(THETA, "");
    if (TFLAG.is_value) {
        if (!T1.is_value) form_T1.set_value(T1, "");
        if (!T2.is_value) form_T2.set_value(T2, "");
        if (!T3.is_value) form_T3.set_value(T3, "");
        if (!T4.is_value) form_T4.set_value(T4, "");
    }
}
            
cards::types cquad4::card_type() const {
    return types::CQUAD4;
}

void cquad4::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    throw errors::error("CQUAD4", "can't write CQUAD4.");
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
