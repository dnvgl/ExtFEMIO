/**
   \file bdf/bdf_cards_enddata.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implementation fro handling Nastran BDF ENDDATA cards.

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

#include "bdf/cards.h"

#include <cstdlib>
#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

            enddata::enddata(const std::list<std::string> &inp) :
               __base::card(inp) {}

            enddata::enddata(void) : __base::card() {}

            const types enddata::card_type(void) const {
               return ENDDATA;
            }

            bdf::types::card enddata::head = bdf::types::card("ENDDATA");

            void enddata::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {
               res.push_back(format(enddata::head));
               return;
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
