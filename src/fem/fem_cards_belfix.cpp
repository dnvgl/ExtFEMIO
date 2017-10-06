/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BELFIX` cards.

   Detailed description
   */

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_belfix[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/types.h"
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

namespace {
    long m_one(-1)/*, one(1), two(2)*/;
}

const card belfix::head("BELFIX");

const entry_type<long> belfix::_form_FIXNO("FIXNO");
const entry_type<long> belfix::_form_OPT(
    "OPT", type_bounds::bound<long>(/* &one, &two */));
const entry_type<long> belfix::_form_TRANO(
    "TRANO", type_bounds::bound<long>(&m_one));
const entry_type<double> belfix::_form_A("A");

belfix::belfix() :
        belfix(-1, n_opt::INVALID, 0,
               {0., 0., 0., 0., 0., 0.}) {}

belfix::belfix(const std::vector<std::string> &inp, size_t const len) {
    belfix::read(inp, len);
}

void belfix::read(const std::vector<std::string> &inp, size_t const len) {
    A.resize(6);
    if (len < 11)
        throw errors::parse_error(
        "BELFIX", "Illegal number of entries.");

    FIXNO = _form_FIXNO(inp.at(1));
    long tmp(_form_OPT(inp.at(2)));
    if (tmp == 1)
        OPT = n_opt::FIXATION;
    else if (tmp == 2)
        OPT = n_opt::SPRING;
    else if (tmp == 3)
        OPT = n_opt::FIXATION_END;
    else if (tmp == 4)
        OPT = n_opt::SPRING_END;
    else {
        OPT = n_opt::INVALID;
        std::ostringstream msg(
            "BELFIX: OPT allows only 1, 2, 3, or 4, got ",
            std::ostringstream::ate);
        msg << tmp << ".";
        error_report(msg.str());
    }
    TRANO = _form_TRANO(inp.at(3));
    for (size_t i{0}; i < 6; i++)
        A[i] = _form_A(inp.at(i + 5));
}

belfix::belfix(long const FIXNO,
               n_opt const OPT,
               long const TRANO,
               std::vector<double> const &A) :
               card(), FIXNO(FIXNO), OPT(OPT), TRANO(TRANO), A(A) {}

cards::types belfix::card_type() const {
    return types::BELFIX;
}

std::ostream &belfix::put(std::ostream &os) const {
    if (OPT == n_opt::INVALID) return os;
    os << head.format()
        << _form_FIXNO.format(FIXNO)
        << _form_OPT.format(static_cast<long>(OPT))
        << _form_TRANO.format(TRANO)
        << empty.format()
        << std::endl << fem::types::card("").format()
        << _form_A.format(A.at(0))
        << _form_A.format(A.at(1))
        << _form_A.format(A.at(2))
        << _form_A.format(A.at(3))
        << std::endl << fem::types::card("").format()
        << _form_A.format(A.at(4))
        << _form_A.format(A.at(5));
    return os << std::endl;;
}

std::string belfix::pos_string() const {
    std::ostringstream res;
    if (OPT != n_opt::FIXATION)
        throw errors::types_error(
        "Only BELFIX records with OPT==1 can be transformed to Poseidon BEAM DOFs.");
    for (double a : A) {
        if (a != 0. && a != 1.)
            throw errors::types_error(
            "Only BELFIX fixation values of 0. and 1. can be transformed to Poseidon BEAM DOFs.");
        res << static_cast<int>(a);
    }
    return res.str();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
