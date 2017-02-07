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
    const char cID_fem_cards_mgsprng[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
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

fem::types::card const mgsprng::head("MGSPRNG");

entry_type<long> const mgsprng::_form_MATNO("MATNO");
entry_type<long> const mgsprng::_form_NDOF("NDOF");
entry_type<double> const mgsprng::_form_K("K");

mgsprng::mgsprng(vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

void mgsprng::read(vector<std::string> const &inp, size_t const len) {
    if (len < 4)
        throw errors::parse_error(
            "MGSPRNG", "Illegal number of entries.");

    MATNO = _form_MATNO(inp.at(1));
    NDOF = _form_NDOF (inp.at(2));
    K.resize(NDOF);
    size_t k{3};
    for (size_t i = 0; i < static_cast<size_t>(NDOF); i++) {
        K[i] = vector<double>(NDOF);
        if (i > 0) {
            for (size_t j = 0; j < i; j++)
                K[i][j] = K[j][i];
        }
        for (size_t j = i; j < static_cast<size_t>(NDOF); j++)
            K[i][j] = _form_K(inp.at(k++));
    }
}

mgsprng::mgsprng(void) :
        mgsprng(-1, 0, {}) {}

mgsprng::mgsprng(long const MATNO, long const NDOF,
                 vector<vector<double> > const &K) :
        card(), MATNO(MATNO), NDOF(NDOF), K(K) {}

mgsprng::mgsprng(long const MATNO, vector<vector<double> > const &K) :
        card(), MATNO(MATNO), NDOF((long)K.size()), K(K) {}

fem::cards::types const mgsprng::card_type(void) const {
    return types::MGSPRNG;
}

ostream &mgsprng::put(ostream& os) const {
    if (MATNO == -1) return os;
    os << mgsprng::head.format()
       << _form_MATNO.format(MATNO) << _form_NDOF.format(NDOF);
    long cnt = 1;
    for (size_t i = 0; i < static_cast<size_t>(NDOF); i++) {
        for (size_t j = i; j < static_cast<size_t>(NDOF); j++) {
            if (!(++cnt % 4))
                os << endl << dnvgl::extfem::fem::types::card().format();
            os << _form_K.format(K[i][j]);
        }
    }
    os << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
