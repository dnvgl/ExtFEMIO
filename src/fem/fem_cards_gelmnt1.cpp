/**
   \file fem/fem_cards_gelmnt1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELMNT1` cards.

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
#include <map>

#include "fem/cards.h"
#include "fem/types.h"
#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

namespace {


   const size_t tmp_elmap_len = 121;
   const std::pair<long, elements::el_types> tmp_elmap[tmp_elmap_len] = {
      std::pair<long, elements::el_types>(2, elements::BEPS),
      std::pair<long, elements::el_types>(3, elements::CSTA),
      std::pair<long, elements::el_types>(5, elements::RPBQ),
      std::pair<long, elements::el_types>(6, elements::ILST),
      std::pair<long, elements::el_types>(8, elements::IQQE),
      std::pair<long, elements::el_types>(9, elements::LQUA),
      std::pair<long, elements::el_types>(10, elements::TESS),
      std::pair<long, elements::el_types>(11, elements::GMAS),
      std::pair<long, elements::el_types>(12, elements::GLMA),
      std::pair<long, elements::el_types>(13, elements::GLDA),
      std::pair<long, elements::el_types>(15, elements::BEAS),
      std::pair<long, elements::el_types>(16, elements::AXIS),
      std::pair<long, elements::el_types>(17, elements::AXDA),
      std::pair<long, elements::el_types>(18, elements::GSPR),
      std::pair<long, elements::el_types>(19, elements::GDAM),
      std::pair<long, elements::el_types>(20, elements::IHEX),
      std::pair<long, elements::el_types>(21, elements::LHEX),
      std::pair<long, elements::el_types>(22, elements::SECB),
      std::pair<long, elements::el_types>(23, elements::BTSS),
      std::pair<long, elements::el_types>(24, elements::FQUS_FFQ),
      std::pair<long, elements::el_types>(25, elements::FTRS_FFTR),
      std::pair<long, elements::el_types>(26, elements::SCTS),
      std::pair<long, elements::el_types>(27, elements::MCTS),
      std::pair<long, elements::el_types>(28, elements::SCQS),
      std::pair<long, elements::el_types>(29, elements::MCQS),
      std::pair<long, elements::el_types>(30, elements::IPRI),
      std::pair<long, elements::el_types>(31, elements::ITET),
      std::pair<long, elements::el_types>(32, elements::TPRI),
      std::pair<long, elements::el_types>(33, elements::TETR),
      std::pair<long, elements::el_types>(34, elements::LCTS),
      std::pair<long, elements::el_types>(35, elements::LCQS),
      std::pair<long, elements::el_types>(36, elements::TRS1),
      std::pair<long, elements::el_types>(37, elements::TRS2),
      std::pair<long, elements::el_types>(38, elements::TRS3),
      std::pair<long, elements::el_types>(40, elements::GLSH),
      std::pair<long, elements::el_types>(41, elements::AXCS),
      std::pair<long, elements::el_types>(42, elements::AXLQ),
      std::pair<long, elements::el_types>(43, elements::AXLS),
      std::pair<long, elements::el_types>(44, elements::AXQQ),
      std::pair<long, elements::el_types>(45, elements::PILS),
      std::pair<long, elements::el_types>(46, elements::PCAB),
      std::pair<long, elements::el_types>(47, elements::PSPR),
      std::pair<long, elements::el_types>(48, elements::ADVA_4),
      std::pair<long, elements::el_types>(49, elements::ADVA_2),
      std::pair<long, elements::el_types>(51, elements::CTCP),
      std::pair<long, elements::el_types>(52, elements::CTCL),
      std::pair<long, elements::el_types>(53, elements::CTAL),
      std::pair<long, elements::el_types>(54, elements::CTCC),
      std::pair<long, elements::el_types>(55, elements::CTAQ),
      std::pair<long, elements::el_types>(56, elements::CTLQ),
      std::pair<long, elements::el_types>(57, elements::CTCQ),
      std::pair<long, elements::el_types>(58, elements::CTMQ),
      std::pair<long, elements::el_types>(61, elements::HCQS),
      std::pair<long, elements::el_types>(66, elements::SLQS),
      std::pair<long, elements::el_types>(67, elements::SLTS),
      std::pair<long, elements::el_types>(68, elements::SLCB),
      std::pair<long, elements::el_types>(70, elements::MATR),
      std::pair<long, elements::el_types>(100, elements::GHEX100),
      std::pair<long, elements::el_types>(101, elements::GHEX101),
      std::pair<long, elements::el_types>(102, elements::GHEX102),
      std::pair<long, elements::el_types>(103, elements::GHEX103),
      std::pair<long, elements::el_types>(104, elements::GHEX104),
      std::pair<long, elements::el_types>(105, elements::GHEX105),
      std::pair<long, elements::el_types>(106, elements::GHEX106),
      std::pair<long, elements::el_types>(107, elements::GHEX107),
      std::pair<long, elements::el_types>(108, elements::GHEX108),
      std::pair<long, elements::el_types>(109, elements::GHEX109),
      std::pair<long, elements::el_types>(110, elements::GHEX110),
      std::pair<long, elements::el_types>(111, elements::GHEX111),
      std::pair<long, elements::el_types>(112, elements::GHEX112),
      std::pair<long, elements::el_types>(113, elements::GHEX113),
      std::pair<long, elements::el_types>(114, elements::GHEX114),
      std::pair<long, elements::el_types>(115, elements::GHEX115),
      std::pair<long, elements::el_types>(116, elements::GHEX116),
      std::pair<long, elements::el_types>(117, elements::GHEX117),
      std::pair<long, elements::el_types>(118, elements::GHEX118),
      std::pair<long, elements::el_types>(119, elements::GHEX119),
      std::pair<long, elements::el_types>(120, elements::GHEX120),
      std::pair<long, elements::el_types>(121, elements::GHEX121),
      std::pair<long, elements::el_types>(122, elements::GHEX122),
      std::pair<long, elements::el_types>(123, elements::GHEX123),
      std::pair<long, elements::el_types>(124, elements::GHEX124),
      std::pair<long, elements::el_types>(125, elements::GHEX125),
      std::pair<long, elements::el_types>(126, elements::GHEX126),
      std::pair<long, elements::el_types>(127, elements::GHEX127),
      std::pair<long, elements::el_types>(128, elements::GHEX128),
      std::pair<long, elements::el_types>(129, elements::GHEX129),
      std::pair<long, elements::el_types>(130, elements::GHEX130),
      std::pair<long, elements::el_types>(131, elements::GHEX131),
      std::pair<long, elements::el_types>(132, elements::GHEX132),
      std::pair<long, elements::el_types>(133, elements::GHEX133),
      std::pair<long, elements::el_types>(134, elements::GHEX134),
      std::pair<long, elements::el_types>(135, elements::GHEX135),
      std::pair<long, elements::el_types>(136, elements::GHEX136),
      std::pair<long, elements::el_types>(137, elements::GHEX137),
      std::pair<long, elements::el_types>(138, elements::GHEX138),
      std::pair<long, elements::el_types>(139, elements::GHEX139),
      std::pair<long, elements::el_types>(140, elements::GHEX140),
      std::pair<long, elements::el_types>(141, elements::GHEX141),
      std::pair<long, elements::el_types>(142, elements::GHEX142),
      std::pair<long, elements::el_types>(143, elements::GHEX143),
      std::pair<long, elements::el_types>(144, elements::GHEX144),
      std::pair<long, elements::el_types>(145, elements::GHEX145),
      std::pair<long, elements::el_types>(146, elements::GHEX146),
      std::pair<long, elements::el_types>(147, elements::GHEX147),
      std::pair<long, elements::el_types>(148, elements::GHEX148),
      std::pair<long, elements::el_types>(149, elements::GHEX149),
      std::pair<long, elements::el_types>(150, elements::GHEX150),
      std::pair<long, elements::el_types>(151, elements::GHEX151),
      std::pair<long, elements::el_types>(152, elements::GHEX152),
      std::pair<long, elements::el_types>(153, elements::GHEX153),
      std::pair<long, elements::el_types>(154, elements::GHEX154),
      std::pair<long, elements::el_types>(155, elements::GHEX155),
      std::pair<long, elements::el_types>(156, elements::GHEX156),
      std::pair<long, elements::el_types>(157, elements::GHEX157),
      std::pair<long, elements::el_types>(158, elements::GHEX158),
      std::pair<long, elements::el_types>(159, elements::GHEX159),
      std::pair<long, elements::el_types>(160, elements::GHEX160),
      std::pair<long, elements::el_types>(161, elements::GHEX161),
      std::pair<long, elements::el_types>(162, elements::GHEX162),
      std::pair<long, elements::el_types>(163, elements::GHEX163)};
}

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const std::map<long, dnvgl::extfem::fem::elements::el_types>
            gelmnt1::eltyp_map(tmp_elmap, tmp_elmap+tmp_elmap_len);

            const fem::types::card gelmnt1::head("GELMNT1");

            const entry_type<long> gelmnt1::_form_ELNOX("ELNOX");
            const entry_type<long> gelmnt1::_form_ELNO("ELNO");
            const entry_type<long> gelmnt1::_form_ELTYP("ELTYP");
            const entry_type<long> gelmnt1::_form_ELTYAD("ELTYAD");
            const entry_type<long> gelmnt1::_form_NODIN("NODIN");

            gelmnt1::gelmnt1(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 6)
                  throw errors::parse_error(
                     "GELMNT1", "Illegal number of entries.");

               auto pos = inp.begin();

               long tmp;

               ++pos;

               ELNOX = _form_ELNOX(*(pos++));
               ELNO = _form_ELNO(*(pos++));
               tmp = _form_ELTYP(*(pos++));
               try {
                  ELTYP = eltyp_map.at(tmp);
               } catch (std::out_of_range) {
                  dnvgl::extfem::fem::errors::parse_error(
                     "gelmnt1", "wrong element type");
               }
               ELTYAD = _form_ELTYAD(*(pos++));
               while (pos != inp.end() && *pos != "                ") {
                  tmp = _form_NODIN(*(pos++));
                  if (tmp == 0) break;
                  NODIN.push_back(tmp);
               }
            }

            gelmnt1::gelmnt1(void) :
               gelmnt1(-1, 0, elements::INVALID, {}) {}

            gelmnt1::gelmnt1(long const &ELNOX,
                             long const &ELNO,
                             elements::el_types const &ELTYP,
                             long const &ELTYAD,
                             std::vector<long> const &NODIN) :
               card(),
               ELNOX(ELNOX), ELNO(ELNO), ELTYP(ELTYP), ELTYAD(ELTYAD),
               NODIN(NODIN) {}

            gelmnt1::gelmnt1(long const &ELNOX,
                             long const &ELNO,
                             elements::el_types const &ELTYP,
                             std::vector<long> const &NODIN) :
               gelmnt1(ELNOX, ELNO, ELTYP, 0, NODIN) {}

            const dnvgl::extfem::fem::cards::types
            gelmnt1::card_type(void) const { return GELMNT1; }

            std::ostream&
            operator<< (std::ostream &os, const gelmnt1 &card) {
               if (card.ELTYP == elements::INVALID) return os;
               os << gelmnt1::head.format()
                  << card._form_ELNOX.format(card.ELNOX)
                  << card._form_ELNO.format(card.ELNO)
                  << card._form_ELTYP.format(static_cast<long>(card.ELTYP))
                  << card._form_ELTYAD.format(card.ELTYAD);
               size_t i = 5;
               for (auto p : card.NODIN) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << dnvgl::extfem::fem::types::card().format();
                  }
                  os << card._form_NODIN.format(p);
               }
               os << std::endl;
               return os;
            }

            const std::ostream&
            gelmnt1::operator<< (std::ostream& os) const {
               os << this;
               return os;
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
// compile-command: "make -C ../.. check -j8"
// End:
