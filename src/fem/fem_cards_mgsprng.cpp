/**
   \file fem/fem_cards_mgsprng.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MGSPRNG` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_mgsprng[]
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

const fem::types::card mgsprng::head("MGSPRNG");

const entry_type<long> mgsprng::_form_MATNO("MATNO");
const entry_type<long> mgsprng::_form_NDOF("NDOF");
const entry_type<double> mgsprng::_form_K("K");

mgsprng::mgsprng(vector<std::string> const &inp, size_t const &len) {
    read(inp, len);
}

void mgsprng::read(vector<std::string> const &inp, size_t const &len) {
    if (len < 4)
        throw errors::parse_error(
            "MGSPRNG", "Illegal number of entries.");

    auto pos = inp.begin();

    ++pos;

    MATNO = _form_MATNO(*(pos++));
    NDOF = _form_NDOF (*(pos++));
    K.resize(NDOF);
    for (long i = 0; i < NDOF; i++) {
        K[i] = std::vector<double>(NDOF);
        if (i > 0) {
            for (long j = 0; j < i; j++)
                K[i][j] = K[j][i];
        }
        for (long j = i; j < NDOF; j++)
            K[i][j] = _form_K(*(pos++));
    }
}

mgsprng::mgsprng(void) :
        mgsprng(-1, 0, {}) {}

mgsprng::mgsprng(long const &MATNO,
                 long const &NDOF,
                 std::vector<std::vector<double> > const &K) :
        card(), MATNO(MATNO), NDOF(NDOF), K(K) {}

mgsprng::mgsprng(long const &MATNO,
                 std::vector<std::vector<double> > const &K) :
        card(), MATNO(MATNO), NDOF((long)K.size()), K(K) {}

const dnvgl::extfem::fem::cards::types
mgsprng::card_type(void) const {return types::MGSPRNG;}

std::ostream &mgsprng::put(std::ostream& os) const {
    if (this->MATNO == -1) return os;
    os << mgsprng::head.format()
       << this->_form_MATNO.format(this->MATNO)
       << this->_form_NDOF.format(this->NDOF);
    long cnt = 2;
    for (long i = 0; i < this->NDOF; i++) {
        for (long j = i; j < this->NDOF; j++) {
            if (cnt == 4) {
                os << std::endl << dnvgl::extfem::fem::types::card().format();
                cnt = 0;
            }
            os << this->_form_K.format(this->K[i][j]);
            cnt += 1;
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
