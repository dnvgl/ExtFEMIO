/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MGSPRNG` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_mgsprng[]) =
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
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

card const mgsprng::head("MGSPRNG");

// entry_type<long> const mgsprng::_form_MATNO("MATNO");
entry_type<long> const mgsprng::_form_NDOF("NDOF");
entry_type<double> const mgsprng::_form_K("K");

mgsprng::mgsprng(vector<std::string> const &inp, size_t const len) {
    mgsprng::read(inp, len);
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

mgsprng::mgsprng() : mgsprng(-1, 0, {}) {}

mgsprng::mgsprng(long const MATNO, long const NDOF,
                 vector<vector<double> > const &K) :
        material(MATNO), NDOF(NDOF), K(K) {}

mgsprng::mgsprng(long const MATNO, vector<vector<double> > const &K) :
        material(MATNO), NDOF(long(K.size())), K(K) {}

cards::types mgsprng::card_type() const {
    return types::MGSPRNG;
}

ostream &mgsprng::put(ostream& os) const {
    if (MATNO == -1) return os;
    os << head.format()
       << _form_MATNO.format(MATNO) << _form_NDOF.format(NDOF);
    long cnt = 1;
    for (size_t i = 0; i < static_cast<size_t>(NDOF); i++) {
        for (size_t j = i; j < static_cast<size_t>(NDOF); j++) {
            if (!(++cnt % 4))
                os << endl << fem::types::card().format();
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
