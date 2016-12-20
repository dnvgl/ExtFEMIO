/**
   \file support_grouping.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implement base functionality for processing grouping information for
       FE file import.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   char const cID_support_grouping[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "support/grouping.h"

using namespace std;

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

elem_info::elem_info(void) :
        elem_info(-1, 0, "", "", "", 0.) {}

elem_info::elem_info(long const &id) :
        elem_info(id, 0, "", "", "", 0.) {}

elem_info::elem_info(long const &id, long const &nnodes,
                     std::string const &napa_obj, std::string const &func_name,
                     std::string const &grade, double const &yield) :
        id(id), nnodes(nnodes), napa_obj(napa_obj), func_name(func_name),
        grade(grade), yield(yield) {}

double const &grp_info::yield(long const &id) {
    return (*this)[id].yield;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
