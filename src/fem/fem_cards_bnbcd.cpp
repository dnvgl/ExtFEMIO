/**
   \file fem/fem_cards_bnbcd.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNBCD` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_bnbcd[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#ifdef FIX
#undef FIX
#endif // FIX

#include <memory>
#include <algorithm>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace cards;
using namespace types;


const fem::types::card bnbcd::head("BNBCD");

const entry_type<long> bnbcd::_form_NODENO("NODENO");
const entry_type<long> bnbcd::_form_NDOF("NDOF");
const entry_type<long> bnbcd::_form_FIX("FIX");

bnbcd::bnbcd(std::vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

void bnbcd::read(std::vector<std::string> const &inp, size_t const len) {
    if (len < 4)
        throw errors::parse_error(
            "BNBCD", "Illegal number of entries.");

    NODENO = _form_NODENO(inp.at(1));
    NDOF = _form_NDOF(inp.at(2));

    for (size_t i{0}; i < static_cast<size_t>(NDOF); i++)
        FIX.push_back(fix_key_conv(_form_FIX(inp.at(i + 3))));
}

bnbcd::bnbcd(void) :
        bnbcd(-1, {}) {}

bnbcd::bnbcd(long const NODENO,
             long const NDOF,
             std::vector<fix_key> const &FIX) :
        card(), NODENO(NODENO), NDOF(NDOF), FIX(FIX) {}

bnbcd::bnbcd(
    long const NODENO,
    std::vector<fix_key> const &FIX) :
        bnbcd(NODENO, (long)FIX.size(), FIX) {}

bnbcd::bnbcd(long const NODENO,
             fix_key const FIX1, fix_key const FIX2, fix_key const FIX3,
             fix_key const FIX4, fix_key const FIX5, fix_key const FIX6) :
        bnbcd(NODENO, 6, std::vector<fix_key>({
                    FIX1, FIX2, FIX3, FIX4, FIX5, FIX6})) {}

bnbcd::bnbcd(long const NODENO,
             bool const FIX1, bool const FIX2, bool const FIX3,
             bool const FIX4, bool const FIX5, bool const FIX6) :
        bnbcd(NODENO, 6, std::vector<fix_key>({
                    fix_key_conv(FIX1), fix_key_conv(FIX2), fix_key_conv(FIX3),
                    fix_key_conv(FIX4), fix_key_conv(FIX5), fix_key_conv(FIX6)})) {}

const dnvgl::extfem::fem::cards::types
bnbcd::card_type(void) const {return types::BNBCD;}

std::ostream &bnbcd::put(std::ostream& os) const {
    if (NODENO == -1) return os;
    os << bnbcd::head.format()
       << _form_NODENO.format(NODENO)
       << _form_NDOF.format(NDOF);
    long cnt(2);
    for (size_t i{0}; i < static_cast<size_t>(NDOF); i++) {
        if (!(cnt++ % 4))
            os << std::endl << dnvgl::extfem::fem::types::card().format();
        os << _form_FIX.format(fix_key_conv(FIX.at(i)));
    }
    os << std::endl;
    return os;
}

cards::__base::card const &bnbcd::operator() (
    long const NODENO,
    long const NDOF,
    std::vector<fix_key> const &FIX) {
    this->NODENO = NODENO;
    this->NDOF = NDOF;
    this->FIX = FIX;
    return *this;
};

cards::__base::card const &bnbcd::operator() (
    long const NODENO,
    std::vector<fix_key> const &FIX) {
    return (*this)(NODENO, (long)FIX.size(), FIX);
}

cards::__base::card const &bnbcd::operator() (
    long const NODENO,
    fix_key const FIX1, fix_key const FIX2, fix_key const FIX3,
    fix_key const FIX4, fix_key const FIX5, fix_key const FIX6) {
    return (*this)(NODENO, 6, std::vector<fix_key>({
                FIX1, FIX2, FIX3, FIX4, FIX5, FIX6}));
}

cards::__base::card const &bnbcd::operator() (
    long const NODENO,
    bool const FIX1, bool const FIX2, bool const FIX3,
    bool const FIX4, bool const FIX5, bool const FIX6) {
    return (*this)(NODENO, 6, std::vector<fix_key>({
                fix_key_conv(FIX1), fix_key_conv(FIX2), fix_key_conv(FIX3),
                fix_key_conv(FIX4), fix_key_conv(FIX5), fix_key_conv(FIX6)}));
}

bnbcd::fix_key const bnbcd::fix_key_conv(long const inp) const {
    if (0 <= inp && inp <= 4)
        return bnbcd::fix_key(inp);
    else
        return bnbcd::fix_key::INVALID;
}

bnbcd::fix_key const bnbcd::fix_key_conv(bool const inp) const {
    return inp ? bnbcd::fix_key::DISPL_FIX : bnbcd::fix_key::FREE;
}

long const bnbcd::fix_key_conv(bnbcd::fix_key const inp) const {
    switch (inp) {
    case bnbcd::fix_key::FREE:
        return 0;
    case bnbcd::fix_key::DISPL_FIX:
        return 1;
    case bnbcd::fix_key::PRESCRIBED:
        return 2;
    case bnbcd::fix_key::LINDEP:
        return 3;
    case bnbcd::fix_key::RETAINED:
        return 4;
    case bnbcd::fix_key::INVALID:
        break;
    }
    return -1;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
