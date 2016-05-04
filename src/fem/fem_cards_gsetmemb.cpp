/**
   \file fem/fem_cards_gsetmemb.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GSETMEMB` cards.

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

#include <memory>
#include <algorithm>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card gsetmemb::head("GSETMEMB");

            const entry_type<long> gsetmemb::_form_NFIELD("NFIELD");
            const entry_type<long> gsetmemb::_form_ISREF("ISREF");
            const entry_type<long> gsetmemb::_form_INDEX("INDEX");
            const entry_type<long> gsetmemb::_form_ISTYPE("ISTYPE");
            const entry_type<long> gsetmemb::_form_ISORIG("ISORIG");
            const entry_type<long> gsetmemb::_form_IRMEMB("IRMEMB");

            gsetmemb::gsetmemb(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 7)
                  throw errors::parse_error(
                  "GSETMEMB", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               NFIELD = _form_NFIELD(*(pos++));
               ISREF = _form_ISREF(*(pos++));
               INDEX = _form_INDEX(*(pos++));
               ISTYPE = gsetmemb::to_types(_form_ISTYPE(*(pos++)));
               ISORIG = gsetmemb::to_origins(_form_ISORIG(*(pos++)));
               IRMEMB.resize(NFIELD - 5);
               for (long i = 0; i < NFIELD - 5; i++)
                  IRMEMB[i] = _form_IRMEMB(*(pos++));
            }

            gsetmemb::gsetmemb(void) :
               gsetmemb(-1, 0, 0, UNDEF_TYPE, UNDEF_ORIGIN) {}

            gsetmemb::gsetmemb(long const &NFIELD,
                               long const &ISREF,
                               long const &INDEX,
                               gsetmemb::types const &ISTYPE,
                               gsetmemb::origins const &ISORIG,
                               std::deque<long> const &IRMEMB) :
                               card(), NFIELD(NFIELD), ISREF(ISREF), INDEX(INDEX),
                               ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(IRMEMB) {}

            gsetmemb::gsetmemb(const long &NFIELD,
                               const long &ISREF,
                               const long &INDEX,
                               gsetmemb::types const &ISTYPE,
                               gsetmemb::origins const &ISORIG) :
                               gsetmemb(NFIELD, ISREF, INDEX, ISTYPE, ISORIG, {}) {}

            gsetmemb::gsetmemb(long const &ISREF,
                               long const &INDEX,
                               gsetmemb::types const &ISTYPE,
                               gsetmemb::origins const &ISORIG,
                               std::deque<long> const &IRMEMB) :
                               gsetmemb((long)IRMEMB.size() + 5, ISREF, INDEX,
                               ISTYPE, ISORIG, IRMEMB) {}

            gsetmemb::gsetmemb(long const &ISREF,
                               long const &INDEX,
                               gsetmemb::types const &ISTYPE,
                               gsetmemb::origins const &ISORIG) :
                               gsetmemb(5, ISREF, INDEX, ISTYPE, ISORIG, {}) {}

            const dnvgl::extfem::fem::cards::types
               gsetmemb::card_type(void) const {
               return GSETMEMB;
            }

            const std::ostream&
               gsetmemb::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
               operator<< (std::ostream &os, gsetmemb const &card) {
               if (card.NFIELD == -1) return os;
               os << gsetmemb::head.format()
                  << card._form_NFIELD.format(card.NFIELD)
                  << card._form_ISREF.format(card.ISREF)
                  << card._form_INDEX.format(card.INDEX)
                  << card._form_ISTYPE.format(card.ISTYPE)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << card._form_ISORIG.format(card.ISORIG);
               long cnt = 1;
               for (long i = 0; i < card.NFIELD - 5; i++) {
                  if (cnt == 4) {
                     os << std::endl << dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << card._form_IRMEMB.format(card.IRMEMB[i]);
                  cnt += 1;
               }
               os << std::endl;
               return os;
            }

            namespace {
               using namespace dnvgl::extfem::fem;

               const size_t types_map_pair_entries = 2;
               const std::pair<long, gsetmemb::types> types_map_pairs[types_map_pair_entries] = {
                  std::make_pair(1, gsetmemb::NODE_SET),
                  std::make_pair(2, gsetmemb::ELEM_SET)
               };

               const size_t origins_map_pair_entries = 5;
               const std::pair<long, gsetmemb::origins> origins_map_pairs[origins_map_pair_entries] = {
                  std::make_pair(0, gsetmemb::UNDEF_ORIGIN),
                  std::make_pair(1, gsetmemb::POINT_ORIGIN),
                  std::make_pair(2, gsetmemb::LINE_OR_CURVE_ORIGIN),
                  std::make_pair(3, gsetmemb::SURFACE_ORIGIN),
                  std::make_pair(4, gsetmemb::BODY_ORIGIN)
               };
            }

            std::map<long, gsetmemb::types> const
               gsetmemb::types_map(
               types_map_pairs, types_map_pairs + types_map_pair_entries);

            std::map<long, gsetmemb::origins> const
               gsetmemb::origins_map(
               origins_map_pairs, origins_map_pairs + origins_map_pair_entries);


            gsetmemb::types gsetmemb::to_types(long const &inp) {
               try {
                  return gsetmemb::types_map.at(inp);
               } catch (std::out_of_range) {
                  std::ostringstream msg("");
                  msg << inp << ": Illegal value for ISTYPE." << std::endl;
                  throw errors::parse_error(
                     "GSETMEMB", msg.str());
               }
            }


            gsetmemb::origins gsetmemb::to_origins(long const &inp) {
               try {
                  return gsetmemb::origins_map.at(inp);
               } catch (std::out_of_range) {
                  std::ostringstream msg("");
                  msg << inp << ": Illegal value for ISORIG." << std::endl;
                  throw errors::parse_error(
                     "GSETMEMB", msg.str());
               }
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
