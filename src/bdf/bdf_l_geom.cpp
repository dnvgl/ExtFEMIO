/**
   \file bdf/bdf_l_geom.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Basic code for geometry describing beam property cards for
   BDF file format (`PBEAML`, `PBARL`)

   Detailed description
   */

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_l_geom[] _EXTFEMIO_UNUSED
        = "@(#) $Id$";
}

#include "bdf/cards.h"

#include <cstdlib>
#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf::cards::__base;

l_geom::l_geom() {};

const std::set<std::string> l_geom::dimnum1({"ROD"});
const std::set<std::string> l_geom::dimnum2({"TUBE", "BAR"});
const std::set<std::string> l_geom::dimnum3({"HEXA"});
const std::set<std::string> l_geom::dimnum4({
    "L", "CHAN", "T", "BOX", "CROSS", "H", "T1", "I1", "CHAN1", "Z",
    "CHAN2", "T2", "HAT"});
const std::set<std::string> l_geom::dimnum5({"HAT1"});
const std::set<std::string> l_geom::dimnum6({"I", "BOX1"});
const std::set<std::string> l_geom::dimnum10({"DBOX"});

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
