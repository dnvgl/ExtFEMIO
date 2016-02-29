/**
   \file bdf/bdf_types_int.cpp
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
#include "config.h"
#endif

#include "bdf/types.h"
#include "bdf/errors.h"

DECLSPECIFIER const
#if HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
dnvgl::extfem::bdf::types::int_re(
   "[[:space:]]*[\\+-]?[[:digit:]]+[[:space:]]*");

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
