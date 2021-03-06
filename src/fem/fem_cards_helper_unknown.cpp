/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Implementing fem::cards::unknown helper class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_helper_unknown[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"

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
using namespace cards;

unknown::unknown(vector<std::string> const &inp, size_t const len) :
        card(types::UNKNOWN), content(inp.begin(), inp.begin()+len) {
    unknown::read(inp, len);
};

ostream &unknown::put(ostream &os) const {
    throw errors::error("can't write UNKNOWN.");
}

void unknown::read(const vector<std::string> &inp, size_t const len) {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
