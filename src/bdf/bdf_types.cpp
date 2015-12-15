/**
   \file bdf/bdf_types.cpp
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

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/types.h"
#include "extfem_string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::dnvgl::extfem;

bdf::types::base::base(const ::std::string &name) : name(name) {};

::std::istringstream bdf::types::base::conv = ::std::istringstream();

bdf::types::out_form_type bdf::types::base::out_form = bdf::types::SHORT;

::std::string bdf::types::card::format(const void* d) const {
   ::std::ostringstream res;
   switch (out_form) {
   case bdf::types::LONG:
      res.setf(::std::ios_base::left, ::std::ios_base::adjustfield);
      res.fill(' ');
      res.width(bdf::types::SHORT);
      res << (name + "*");
      break;
   case bdf::types::SHORT:
      res.setf(::std::ios_base::left, ::std::ios_base::adjustfield);
      res.fill(' ');
      res.width(bdf::types::SHORT);
      res << name;
      break;
   case bdf::types::FREE:
      res << name;
      break;
   }
   return res.str();
}

::std::string bdf::types::empty::format(const void* d) const {
   ::std::ostringstream res;
   switch (out_form) {
   case bdf::types::LONG:
   case bdf::types::SHORT:
      res.fill(' ');
      break;
   case bdf::types::FREE:
      break;
   }
   res.width(out_form);
   res << " ";
   return res.str();
}

::std::string bdf::types::empty::format() const {
   return this->format(nullptr);
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
