/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF PBEAM and PBEAML cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_beam_prop[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;

using types::entry_type;
using namespace type_bounds;

using namespace cards::__base;

namespace {
    auto const cl1_ = make_shared<long>(1);
    auto const cl1 = cl1_.get();

    auto const MID_bound_ = make_shared<bound<long>>(cl1, nullptr, nullptr, true);
    auto const MID_bound = MID_bound_.get();
}
entry_type<long> beam_base::form_MID("MID", MID_bound);

beam_base::beam_base() : property() {}

beam_base::beam_base(const list<std::string> &inp) :
        property(inp) {}

beam_base::beam_base(long const *PID, long const *MID) :
        property(PID), MID(MID) {}

cards::types beam_base::card_type() const {
    return types::BEAM_BASE;
}

card const &beam_base::operator() (long const *PID, long const *MID) {
    this->property::operator() (PID);
    this->MID(MID);
    return *this;
}

beam_prop::beam_prop(const list<std::string> &inp) :
        beam_base(inp) {}

beam_prop::beam_prop(long const *PID, long const *MID) :
        beam_base(PID, MID) {}

cards::types beam_prop::card_type() const {
    return types::BEAM_PROP;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test ;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
