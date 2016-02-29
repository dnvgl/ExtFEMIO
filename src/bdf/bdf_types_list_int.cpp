/**
   \file bdf/bdf_types_list_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef __GNUC__
using ::boost::regex;
#else
using ::std::regex;
#endif

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

DECLSPECIFIER const regex dnvgl::extfem::bdf::types::list_int_re("[[:digit:]]*");


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
