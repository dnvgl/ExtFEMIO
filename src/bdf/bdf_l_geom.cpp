/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Basic code for geometry describing beam property cards for
   BDF file format (`PBEAML`, `PBARL`)

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_l_geom[]) =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf::cards::__base;

namespace {
    const std::set<std::string> dimnum1({"ROD"});
    const std::set<std::string> dimnum2({"TUBE", "BAR"});
    const std::set<std::string> dimnum3({"HEXA"});
    const std::set<std::string> dimnum4({
            "L", "CHAN", "T", "BOX", "CROSS", "H", "T1", "I1", "CHAN1", "Z",
                "CHAN2", "T2", "HAT"});
    const std::set<std::string> dimnum5({"HAT1"});
    const std::set<std::string> dimnum6({"I", "BOX1"});
    const std::set<std::string> dimnum10({"DBOX"});
}

size_t l_geom::get_dim(std::string const &TYPE) {
    if (dimnum1.find(TYPE) != dimnum1.end())
        return 1;
    else if (dimnum2.find(TYPE) != dimnum2.end())
        return 2;
    else if (dimnum3.find(TYPE) != dimnum3.end())
        return 3;
    else if (dimnum4.find(TYPE) != dimnum4.end())
        return 4;
    else if (dimnum5.find(TYPE) != dimnum5.end())
        return 5;
    else if (dimnum6.find(TYPE) != dimnum6.end())
        return 6;
    else if (dimnum10.find(TYPE) != dimnum10.end())
        return 10;
    else
        return -1;
}
// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
