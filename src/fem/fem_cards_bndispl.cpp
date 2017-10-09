/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNDISPL` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_bndispl[]) =
        "@(#) $Id$";
}

#include <cassert>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

using namespace cards;

const card bndispl::head("BNDISPL");

const entry_type<long> bndispl::_form_LLC("LLC");
const entry_type<long> bndispl::_form_DTYPE("DTYPE");
const entry_type<bool> bndispl::_form_COMPLX("COMPLX");
const entry_type<long> bndispl::_form_NODENO("NODENO");
const entry_type<long> bndispl::_form_NDOF("NDOF");
const entry_type<double> bndispl::_form_RDISP("RDISP");
const entry_type<double> bndispl::_form_IDISP("IDISP");

bndispl::bndispl(const std::vector<std::string> &inp, size_t const len) {
    bndispl::read(inp, len);
}

void bndispl::read(const std::vector<std::string> &inp, size_t const len) {
    if (len < 8)
        throw errors::parse_error(
            "BNDISPL", "Illegal number of entries.");

    LLC = _form_LLC(inp.at(1));
    DTYPE = _form_DTYPE (inp.at(2));
    COMPLX = _form_COMPLX(inp.at(3));
    NODENO = _form_NODENO(inp.at(5));
    NDOF = _form_NDOF(inp.at(6));
    for (size_t i{0}; i < static_cast<size_t>(NDOF); i++)
        RDISP.push_back(_form_RDISP(inp.at(7 + i)));

    if (COMPLX)
        for (size_t i{0}; i < static_cast<size_t>(NDOF); i++)
            IDISP.push_back(_form_IDISP(inp.at(7 + NDOF + i)));
}

bndispl::bndispl() :
        bndispl(-1, 0, false, 0, {}) {}

bndispl::bndispl(const long LLC,
                 const long DTYPE,
                 const bool COMPLX,
                 const long NODENO,
                 const long NDOF,
                 const std::vector<double> &RDISP,
                 const std::vector<double> &IDISP) :
        card(), LLC(LLC), DTYPE(DTYPE), COMPLX(COMPLX),
        NODENO(NODENO), NDOF(NDOF),
        RDISP(RDISP), IDISP(IDISP) {}


bndispl::bndispl(const long LLC,
                 const long DTYPE,
                 const bool COMPLX,
                 const long NODENO,
                 const std::vector<double> &RDISP,
                 const std::vector<double> &IDISP) :
        bndispl(LLC, DTYPE, COMPLX, NODENO, long(RDISP.size()),
                RDISP, IDISP) {}

bndispl::bndispl(const long LLC,
                 const long DTYPE,
                 const long NODENO,
                 const long NDOF,
                 const std::vector<double> &RDISP,
                 const std::vector<double> &IDISP) :
        bndispl(LLC, DTYPE, IDISP.size() > 0, NODENO, NDOF,
                RDISP, IDISP) {}


bndispl::bndispl(const long LLC,
                 const long DTYPE,
                 const long NODENO,
                 const std::vector<double> &RDISP,
                 const std::vector<double> &IDISP) :
        bndispl(LLC, DTYPE, NODENO, long(RDISP.size()),
                RDISP, IDISP) {}

cards::types
bndispl::card_type() const {return types::BNDISPL;}

std::ostream &bndispl::put(std::ostream& os) const {
    if (this->LLC == -1) return os;
    os << head.format()
       << this->_form_LLC.format(this->LLC)
       << this->_form_DTYPE.format(this->DTYPE)
       << this->_form_COMPLX.format(this->COMPLX)
       << this->empty.format() << std::endl
       << fem::types::card().format()
       << this->_form_NODENO.format(this->NODENO)
       << this->_form_NDOF.format(this->NDOF);
    long cnt{2};
    for (long i = 0; i < this->NDOF; i++) {
        if (!(cnt++ % 4))
            os << std::endl << fem::types::card().format();
        os << this->_form_RDISP.format(this->RDISP.at(i));
    }
    if (this->COMPLX) {
        assert(this->IDISP.size() == static_cast<size_t>(this->NDOF));
        for (long i = 0; i < this->NDOF; i++) {
            if (!(cnt++ % 4))
                os << std::endl << fem::types::card().format();
            os << this->_form_IDISP.format(this->IDISP.at(i));
        }
    }
    os << std::endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
