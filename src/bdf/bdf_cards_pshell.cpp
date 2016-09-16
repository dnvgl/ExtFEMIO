/**
   \file bdf/bdf_cards_pshell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PSHELL cards.

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
#include "bdf/errors.h"

#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
   static const long cl1 = 1, cl_1 = -1;
   static const double cd0 = 0., cd1 = 1., cd833 = .833333;
}

namespace dnvgl {
   namespace extfem  {
      namespace bdf  {
         namespace cards {;

            using bdf::types::entry_type;

            const entry_type<long> pshell::form_PID(
               "PID", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<long> pshell::form_MID1(
               "MID1",
               bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));
            const entry_type<double> pshell::form_T(
               "T",
               bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
            const entry_type<long> pshell::form_MID2(
               "MID2",
               bdf::type_bounds::bound<long>(&cl_1, nullptr, nullptr, true));
            const entry_type<double> pshell::form_12I_T__3(
               "12I/T**3",
               bdf::type_bounds::bound<double>(&cd0, nullptr, &cd1));
            const entry_type<long> pshell::form_MID3(
               "MID3",
               bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));
            const entry_type<double> pshell::form_TS_T(
               "TS/T", bdf::type_bounds::bound<double>(&cd0, nullptr, &cd833));
            const entry_type<double> pshell::form_NSM(
               "NSM",
               bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
            const entry_type<double> pshell::form_Z1(
               "Z1",
               bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
            const entry_type<double> pshell::form_Z2(
               "Z2",
               bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
            const entry_type<long> pshell::form_MID4(
               "MID4",
               bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));

            pshell::pshell(const std::list<std::string> &inp) :
               card(inp) {
               this->read(inp);
            }

            void pshell::read(const std::list<std::string> &inp) {
               auto pos = inp.rbegin();

               form_MID4.set_value(MID4, "");
               form_Z2.set_value(Z2, "");
               form_Z1.set_value(Z1, "");
               form_NSM.set_value(NSM, "");
               form_TS_T.set_value(TS_T, "");
               form_MID3.set_value(MID3, "");

               switch (inp.size()-1) {
               case 16:
                  ++pos;
               case 15:
                  ++pos;
               case 14:
                  ++pos;
               case 13:
                  ++pos;
               case 12:
                  ++pos;
               case 11:
                  form_MID4.set_value(MID4, *(pos++));
               case 10:
                  form_Z2.set_value(Z2, *(pos++));
               case 9:
                  form_Z1.set_value(Z1, *(pos++));
               case 8:
                  form_NSM.set_value(NSM, *(pos++));
               case 7:
                  form_TS_T.set_value(TS_T, *(pos++));
               case 6:
                  form_MID3.set_value(MID3, *(pos++));
               case 5:
                  form_12I_T__3.set_value(x12I_T__3, *(pos++));
                  form_MID2.set_value(MID2, *(pos++));
                  form_T.set_value(T, *(pos++));
                  form_MID1.set_value(MID1, *(pos++));
                  form_PID.set_value(PID, *pos);
                  break;
               default:
                  throw errors::parse_error("PSHELL", "Illegal number of entries.");
               }
            }

            const dnvgl::extfem::bdf::cards::types
            pshell::card_type(void) const { return PSHELL; };

            void pshell::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {
               throw errors::error("PSHELL", "can't write PSHELL.");
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
