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
   const char cID_fem_cards_gelmnt1[]
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
      std::pair<long, elements::el_types>(2, elements::el_types::BEPS),
      std::pair<long, elements::el_types>(3, elements::el_types::CSTA),
      std::pair<long, elements::el_types>(5, elements::el_types::RPBQ),
      std::pair<long, elements::el_types>(6, elements::el_types::ILST),
      std::pair<long, elements::el_types>(8, elements::el_types::IQQE),
      std::pair<long, elements::el_types>(9, elements::el_types::LQUA),
      std::pair<long, elements::el_types>(10, elements::el_types::TESS),
      std::pair<long, elements::el_types>(11, elements::el_types::GMAS),
      std::pair<long, elements::el_types>(12, elements::el_types::GLMA),
      std::pair<long, elements::el_types>(13, elements::el_types::GLDA),
      std::pair<long, elements::el_types>(15, elements::el_types::BEAS),
      std::pair<long, elements::el_types>(16, elements::el_types::AXIS),
      std::pair<long, elements::el_types>(17, elements::el_types::AXDA),
      std::pair<long, elements::el_types>(18, elements::el_types::GSPR),
      std::pair<long, elements::el_types>(19, elements::el_types::GDAM),
      std::pair<long, elements::el_types>(20, elements::el_types::IHEX),
      std::pair<long, elements::el_types>(21, elements::el_types::LHEX),
      std::pair<long, elements::el_types>(22, elements::el_types::SECB),
      std::pair<long, elements::el_types>(23, elements::el_types::BTSS),
      std::pair<long, elements::el_types>(24, elements::el_types::FQUS_FFQ),
      std::pair<long, elements::el_types>(25, elements::el_types::FTRS_FFTR),
      std::pair<long, elements::el_types>(26, elements::el_types::SCTS),
      std::pair<long, elements::el_types>(27, elements::el_types::MCTS),
      std::pair<long, elements::el_types>(28, elements::el_types::SCQS),
      std::pair<long, elements::el_types>(29, elements::el_types::MCQS),
      std::pair<long, elements::el_types>(30, elements::el_types::IPRI),
      std::pair<long, elements::el_types>(31, elements::el_types::ITET),
      std::pair<long, elements::el_types>(32, elements::el_types::TPRI),
      std::pair<long, elements::el_types>(33, elements::el_types::TETR),
      std::pair<long, elements::el_types>(34, elements::el_types::LCTS),
      std::pair<long, elements::el_types>(35, elements::el_types::LCQS),
      std::pair<long, elements::el_types>(36, elements::el_types::TRS1),
      std::pair<long, elements::el_types>(37, elements::el_types::TRS2),
      std::pair<long, elements::el_types>(38, elements::el_types::TRS3),
      std::pair<long, elements::el_types>(40, elements::el_types::GLSH),
      std::pair<long, elements::el_types>(41, elements::el_types::AXCS),
      std::pair<long, elements::el_types>(42, elements::el_types::AXLQ),
      std::pair<long, elements::el_types>(43, elements::el_types::AXLS),
      std::pair<long, elements::el_types>(44, elements::el_types::AXQQ),
      std::pair<long, elements::el_types>(45, elements::el_types::PILS),
      std::pair<long, elements::el_types>(46, elements::el_types::PCAB),
      std::pair<long, elements::el_types>(47, elements::el_types::PSPR),
      std::pair<long, elements::el_types>(48, elements::el_types::ADVA_4),
      std::pair<long, elements::el_types>(49, elements::el_types::ADVA_2),
      std::pair<long, elements::el_types>(51, elements::el_types::CTCP),
      std::pair<long, elements::el_types>(52, elements::el_types::CTCL),
      std::pair<long, elements::el_types>(53, elements::el_types::CTAL),
      std::pair<long, elements::el_types>(54, elements::el_types::CTCC),
      std::pair<long, elements::el_types>(55, elements::el_types::CTAQ),
      std::pair<long, elements::el_types>(56, elements::el_types::CTLQ),
      std::pair<long, elements::el_types>(57, elements::el_types::CTCQ),
      std::pair<long, elements::el_types>(58, elements::el_types::CTMQ),
      std::pair<long, elements::el_types>(61, elements::el_types::HCQS),
      std::pair<long, elements::el_types>(66, elements::el_types::SLQS),
      std::pair<long, elements::el_types>(67, elements::el_types::SLTS),
      std::pair<long, elements::el_types>(68, elements::el_types::SLCB),
      std::pair<long, elements::el_types>(70, elements::el_types::MATR),
      std::pair<long, elements::el_types>(100, elements::el_types::GHEX100),
      std::pair<long, elements::el_types>(101, elements::el_types::GHEX101),
      std::pair<long, elements::el_types>(102, elements::el_types::GHEX102),
      std::pair<long, elements::el_types>(103, elements::el_types::GHEX103),
      std::pair<long, elements::el_types>(104, elements::el_types::GHEX104),
      std::pair<long, elements::el_types>(105, elements::el_types::GHEX105),
      std::pair<long, elements::el_types>(106, elements::el_types::GHEX106),
      std::pair<long, elements::el_types>(107, elements::el_types::GHEX107),
      std::pair<long, elements::el_types>(108, elements::el_types::GHEX108),
      std::pair<long, elements::el_types>(109, elements::el_types::GHEX109),
      std::pair<long, elements::el_types>(110, elements::el_types::GHEX110),
      std::pair<long, elements::el_types>(111, elements::el_types::GHEX111),
      std::pair<long, elements::el_types>(112, elements::el_types::GHEX112),
      std::pair<long, elements::el_types>(113, elements::el_types::GHEX113),
      std::pair<long, elements::el_types>(114, elements::el_types::GHEX114),
      std::pair<long, elements::el_types>(115, elements::el_types::GHEX115),
      std::pair<long, elements::el_types>(116, elements::el_types::GHEX116),
      std::pair<long, elements::el_types>(117, elements::el_types::GHEX117),
      std::pair<long, elements::el_types>(118, elements::el_types::GHEX118),
      std::pair<long, elements::el_types>(119, elements::el_types::GHEX119),
      std::pair<long, elements::el_types>(120, elements::el_types::GHEX120),
      std::pair<long, elements::el_types>(121, elements::el_types::GHEX121),
      std::pair<long, elements::el_types>(122, elements::el_types::GHEX122),
      std::pair<long, elements::el_types>(123, elements::el_types::GHEX123),
      std::pair<long, elements::el_types>(124, elements::el_types::GHEX124),
      std::pair<long, elements::el_types>(125, elements::el_types::GHEX125),
      std::pair<long, elements::el_types>(126, elements::el_types::GHEX126),
      std::pair<long, elements::el_types>(127, elements::el_types::GHEX127),
      std::pair<long, elements::el_types>(128, elements::el_types::GHEX128),
      std::pair<long, elements::el_types>(129, elements::el_types::GHEX129),
      std::pair<long, elements::el_types>(130, elements::el_types::GHEX130),
      std::pair<long, elements::el_types>(131, elements::el_types::GHEX131),
      std::pair<long, elements::el_types>(132, elements::el_types::GHEX132),
      std::pair<long, elements::el_types>(133, elements::el_types::GHEX133),
      std::pair<long, elements::el_types>(134, elements::el_types::GHEX134),
      std::pair<long, elements::el_types>(135, elements::el_types::GHEX135),
      std::pair<long, elements::el_types>(136, elements::el_types::GHEX136),
      std::pair<long, elements::el_types>(137, elements::el_types::GHEX137),
      std::pair<long, elements::el_types>(138, elements::el_types::GHEX138),
      std::pair<long, elements::el_types>(139, elements::el_types::GHEX139),
      std::pair<long, elements::el_types>(140, elements::el_types::GHEX140),
      std::pair<long, elements::el_types>(141, elements::el_types::GHEX141),
      std::pair<long, elements::el_types>(142, elements::el_types::GHEX142),
      std::pair<long, elements::el_types>(143, elements::el_types::GHEX143),
      std::pair<long, elements::el_types>(144, elements::el_types::GHEX144),
      std::pair<long, elements::el_types>(145, elements::el_types::GHEX145),
      std::pair<long, elements::el_types>(146, elements::el_types::GHEX146),
      std::pair<long, elements::el_types>(147, elements::el_types::GHEX147),
      std::pair<long, elements::el_types>(148, elements::el_types::GHEX148),
      std::pair<long, elements::el_types>(149, elements::el_types::GHEX149),
      std::pair<long, elements::el_types>(150, elements::el_types::GHEX150),
      std::pair<long, elements::el_types>(151, elements::el_types::GHEX151),
      std::pair<long, elements::el_types>(152, elements::el_types::GHEX152),
      std::pair<long, elements::el_types>(153, elements::el_types::GHEX153),
      std::pair<long, elements::el_types>(154, elements::el_types::GHEX154),
      std::pair<long, elements::el_types>(155, elements::el_types::GHEX155),
      std::pair<long, elements::el_types>(156, elements::el_types::GHEX156),
      std::pair<long, elements::el_types>(157, elements::el_types::GHEX157),
      std::pair<long, elements::el_types>(158, elements::el_types::GHEX158),
      std::pair<long, elements::el_types>(159, elements::el_types::GHEX159),
      std::pair<long, elements::el_types>(160, elements::el_types::GHEX160),
      std::pair<long, elements::el_types>(161, elements::el_types::GHEX161),
      std::pair<long, elements::el_types>(162, elements::el_types::GHEX162),
      std::pair<long, elements::el_types>(163, elements::el_types::GHEX163)};
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

            gelmnt1::gelmnt1(const std::list<std::string> &inp) :
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
               gelmnt1(-1, 0, elements::el_types::INVALID, {}) {}

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
            gelmnt1::card_type(void) const { return types::GELMNT1; }

            std::ostream &gelmnt1::put(std::ostream& os) const {
               if (this->ELTYP == elements::el_types::INVALID) return os;
               os << gelmnt1::head.format()
                  << this->_form_ELNOX.format(this->ELNOX)
                  << this->_form_ELNO.format(this->ELNO)
                  << this->_form_ELTYP.format(static_cast<long>(this->ELTYP))
                  << this->_form_ELTYAD.format(this->ELTYAD);
               size_t i = 5;
               for (auto p : this->NODIN) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << dnvgl::extfem::fem::types::card().format();
                  }
                  os << this->_form_NODIN.format(p);
               }
               return os << std::endl;
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
