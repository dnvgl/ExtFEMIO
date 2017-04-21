/**
   \file bdf/bdf_cards_bar_prop.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF PBAR and PBARL cards.

   Detailed description
*/
#include "StdAfx.h"
#include "extfem_misc.h"

// ID:
namespace {
   const char cID_bdf_cards_bar_prop[] _EXTFEMIO_UNUSED =
       "@(#) $Id$";
}

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;

using types::entry_type;
using namespace type_bounds;

using namespace cards::__base;

bar_prop::bar_prop(const std::list<std::string> &inp) :
        beam_base(inp) {}

cards::types bar_prop::card_type() const {
    return types::BAR_PROP;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
