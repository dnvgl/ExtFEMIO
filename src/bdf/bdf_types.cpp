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

#include <iomanip>
#include <locale>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/types.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::dnvgl::extfem;

::std::istringstream bdf::types::base::conv;

bdf::types::base::base(const ::std::string &name) : name(name) {};

// set input and output locale for conv and outp
static bdf::types::imbue_helper _imbue_helper(::std::locale::classic());

bdf::types::out_form_type bdf::types::base::out_form = bdf::types::SHORT;

::std::string bdf::types::card::format(const void* d) const {
   std::ostringstream outp;

   outp << std::resetiosflags(std::ios::adjustfield);
   switch (out_form) {
   case bdf::types::LONG:
      outp << setiosflags(::std::ios::left) << std::setfill(' ')
           << std::setw(8) << (name + "*");
      break;
   case bdf::types::SHORT:
      outp << setiosflags(::std::ios_base::left) << std::setfill(' ')
           << std::setw(8) << name;
      break;
   case bdf::types::FREE:
      outp << name;
      break;
   }

   return outp.str();
}

bdf::types::empty::empty(void) : bdf::types::base("<empty>") {}

::std::string bdf::types::empty::format(const void* d) const {
   std::ostringstream outp;

   switch (out_form) {
   case bdf::types::LONG:
   case bdf::types::SHORT:
      outp << std::setfill(' ') << std::setw(out_form) << " ";
      break;
   case bdf::types::FREE:
      break;
   }
   return outp.str();
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
