/**
   \file fem/fem_elements.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for FEm elements.

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

#include "my_c++14.h"
#include "fem/cards.h"
#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem::elements;

void dnvgl::extfem::fem::elements::dispatch(
   std::unique_ptr<__base> &res, const dnvgl::extfem::fem::cards::gelmnt1 *data) {

   switch (data->ELTYP) {
   case BEPS: res = std::make_unique<beps>(data); break;
   case CSTA: res = std::make_unique<csta>(data); break;
   case RPBQ: res = std::make_unique<rpbq>(data); break;
   case ILST: res = std::make_unique<ilst>(data); break;
   case IQQE: res = std::make_unique<iqqe>(data); break;
   case LQUA: res = std::make_unique<lqua>(data); break;
   case TESS: res = std::make_unique<tess>(data); break;
   case GMAS: res = std::make_unique<gmas>(data); break;
   case GLMA: res = std::make_unique<glma>(data); break;
   case GLDA: res = std::make_unique<glda>(data); break;
   case BEAS: res = std::make_unique<beas>(data); break;
   case AXIS: res = std::make_unique<axis>(data); break;
   case AXDA: res = std::make_unique<axda>(data); break;
   case GSPR: res = std::make_unique<gspr>(data); break;
   case GDAM: res = std::make_unique<gdam>(data); break;
   case IHEX: res = std::make_unique<ihex>(data); break;
   case LHEX: res = std::make_unique<lhex>(data); break;
   case SECB: res = std::make_unique<secb>(data); break;
   case BTSS: res = std::make_unique<btss>(data); break;
   case FQUS_FFQ: res = std::make_unique<fqus_ffq>(data); break;
   case FTRS_FFTR: res = std::make_unique<ftrs_fftr>(data); break;
   case SCTS: res = std::make_unique<scts>(data); break;
   case MCTS: res = std::make_unique<mcts>(data); break;
   case SCQS: res = std::make_unique<scqs>(data); break;
   case MCQS: res = std::make_unique<mcqs>(data); break;
   case IPRI: res = std::make_unique<ipri>(data); break;
   case ITET: res = std::make_unique<itet>(data); break;
   case TPRI: res = std::make_unique<tpri>(data); break;
   case TETR: res = std::make_unique<tetr>(data); break;
   case LCTS: res = std::make_unique<lcts>(data); break;
   case LCQS: res = std::make_unique<lcqs>(data); break;
   case TRS1: res = std::make_unique<trs1>(data); break;
   case TRS2: res = std::make_unique<trs2>(data); break;
   case TRS3: res = std::make_unique<trs3>(data); break;
   case GLSH: res = std::make_unique<glsh>(data); break;
   case AXCS: res = std::make_unique<axcs>(data); break;
   case AXLQ: res = std::make_unique<axlq>(data); break;
   case AXLS: res = std::make_unique<axls>(data); break;
   case AXQQ: res = std::make_unique<axqq>(data); break;
   case PILS: res = std::make_unique<pils>(data); break;
   case PCAB: res = std::make_unique<pcab>(data); break;
   case PSPR: res = std::make_unique<pspr>(data); break;
   case ADVA_4: res = std::make_unique<adva_4>(data); break;
   case ADVA_2: res = std::make_unique<adva_2>(data); break;
   case CTCP: res = std::make_unique<ctcp>(data); break;
   case CTCL: res = std::make_unique<ctcl>(data); break;
   case CTAL: res = std::make_unique<ctal>(data); break;
   case CTCC: res = std::make_unique<ctcc>(data); break;
   case CTAQ: res = std::make_unique<ctaq>(data); break;
   case CTLQ: res = std::make_unique<ctlq>(data); break;
   case CTCQ: res = std::make_unique<ctcq>(data); break;
   case CTMQ: res = std::make_unique<ctmq>(data); break;
   case HCQS: res = std::make_unique<hcqs>(data); break;
   case SLQS: res = std::make_unique<slqs>(data); break;
   case SLTS: res = std::make_unique<slts>(data); break;
   case SLCB: res = std::make_unique<slcb>(data); break;
   case MATR: res = std::make_unique<matr>(data); break;
   case GHEX100: res = std::make_unique<ghex100>(data); break;
   case GHEX101: res = std::make_unique<ghex101>(data); break;
   case GHEX102: res = std::make_unique<ghex102>(data); break;
   case GHEX103: res = std::make_unique<ghex103>(data); break;
   case GHEX104: res = std::make_unique<ghex104>(data); break;
   case GHEX105: res = std::make_unique<ghex105>(data); break;
   case GHEX106: res = std::make_unique<ghex106>(data); break;
   case GHEX107: res = std::make_unique<ghex107>(data); break;
   case GHEX108: res = std::make_unique<ghex108>(data); break;
   case GHEX109: res = std::make_unique<ghex109>(data); break;
   case GHEX110: res = std::make_unique<ghex110>(data); break;
   case GHEX111: res = std::make_unique<ghex111>(data); break;
   case GHEX112: res = std::make_unique<ghex112>(data); break;
   case GHEX113: res = std::make_unique<ghex113>(data); break;
   case GHEX114: res = std::make_unique<ghex114>(data); break;
   case GHEX115: res = std::make_unique<ghex115>(data); break;
   case GHEX116: res = std::make_unique<ghex116>(data); break;
   case GHEX117: res = std::make_unique<ghex117>(data); break;
   case GHEX118: res = std::make_unique<ghex118>(data); break;
   case GHEX119: res = std::make_unique<ghex119>(data); break;
   case GHEX120: res = std::make_unique<ghex120>(data); break;
   case GHEX121: res = std::make_unique<ghex121>(data); break;
   case GHEX122: res = std::make_unique<ghex122>(data); break;
   case GHEX123: res = std::make_unique<ghex123>(data); break;
   case GHEX124: res = std::make_unique<ghex124>(data); break;
   case GHEX125: res = std::make_unique<ghex125>(data); break;
   case GHEX126: res = std::make_unique<ghex126>(data); break;
   case GHEX127: res = std::make_unique<ghex127>(data); break;
   case GHEX128: res = std::make_unique<ghex128>(data); break;
   case GHEX129: res = std::make_unique<ghex129>(data); break;
   case GHEX130: res = std::make_unique<ghex130>(data); break;
   case GHEX131: res = std::make_unique<ghex131>(data); break;
   case GHEX132: res = std::make_unique<ghex132>(data); break;
   case GHEX133: res = std::make_unique<ghex133>(data); break;
   case GHEX134: res = std::make_unique<ghex134>(data); break;
   case GHEX135: res = std::make_unique<ghex135>(data); break;
   case GHEX136: res = std::make_unique<ghex136>(data); break;
   case GHEX137: res = std::make_unique<ghex137>(data); break;
   case GHEX138: res = std::make_unique<ghex138>(data); break;
   case GHEX139: res = std::make_unique<ghex139>(data); break;
   case GHEX140: res = std::make_unique<ghex140>(data); break;
   case GHEX141: res = std::make_unique<ghex141>(data); break;
   case GHEX142: res = std::make_unique<ghex142>(data); break;
   case GHEX143: res = std::make_unique<ghex143>(data); break;
   case GHEX144: res = std::make_unique<ghex144>(data); break;
   case GHEX145: res = std::make_unique<ghex145>(data); break;
   case GHEX146: res = std::make_unique<ghex146>(data); break;
   case GHEX147: res = std::make_unique<ghex147>(data); break;
   case GHEX148: res = std::make_unique<ghex148>(data); break;
   case GHEX149: res = std::make_unique<ghex149>(data); break;
   case GHEX150: res = std::make_unique<ghex150>(data); break;
   case GHEX151: res = std::make_unique<ghex151>(data); break;
   case GHEX152: res = std::make_unique<ghex152>(data); break;
   case GHEX153: res = std::make_unique<ghex153>(data); break;
   case GHEX154: res = std::make_unique<ghex154>(data); break;
   case GHEX155: res = std::make_unique<ghex155>(data); break;
   case GHEX156: res = std::make_unique<ghex156>(data); break;
   case GHEX157: res = std::make_unique<ghex157>(data); break;
   case GHEX158: res = std::make_unique<ghex158>(data); break;
   case GHEX159: res = std::make_unique<ghex159>(data); break;
   case GHEX160: res = std::make_unique<ghex160>(data); break;
   case GHEX161: res = std::make_unique<ghex161>(data); break;
   case GHEX162: res = std::make_unique<ghex162>(data); break;
   case GHEX163: res = std::make_unique<ghex163>(data); break;
   case UNDEFINED: res = std::make_unique<undef>(); break;
   };
}

std::string dnvgl::extfem::fem::elements::name_elem(dnvgl::extfem::fem::elements::el_types const &type) {
   switch (type) {
      case BEPS: return "BEPS";
      case CSTA: return "CSTA";
      case RPBQ: return "RPBQ";
      case ILST: return "ILST";
      case IQQE: return "IQQE";
      case LQUA: return "LQUA";
      case TESS: return "TESS";
      case GMAS: return "GMAS";
      case GLMA: return "GLMA";
      case GLDA: return "GLDA";
      case BEAS: return "BEAS";
      case AXIS: return "AXIS";
      case AXDA: return "AXDA";
      case GSPR: return "GSPR";
      case GDAM: return "GDAM";
      case IHEX: return "IHEX";
      case LHEX: return "LHEX";
      case SECB: return "SECB";
      case BTSS: return "BTSS";
      case FQUS_FFQ: return "FQUS_FFQ";
      case FTRS_FFTR: return "FTRS_FFTR";
      case SCTS: return "SCTS";
      case MCTS: return "MCTS";
      case SCQS: return "SCQS";
      case MCQS: return "MCQS";
      case IPRI: return "IPRI";
      case ITET: return "ITET";
      case TPRI: return "TPRI";
      case TETR: return "TETR";
      case LCTS: return "LCTS";
      case LCQS: return "LCQS";
      case TRS1: return "TRS1";
      case TRS2: return "TRS2";
      case TRS3: return "TRS3";
      case GLSH: return "GLSH";
      case AXCS: return "AXCS";
      case AXLQ: return "AXLQ";
      case AXLS: return "AXLS";
      case AXQQ: return "AXQQ";
      case PILS: return "PILS";
      case PCAB: return "PCAB";
      case PSPR: return "PSPR";
      case ADVA_4: return "ADVA_4";
      case ADVA_2: return "ADVA_2";
      case CTCP: return "CTCP";
      case CTCL: return "CTCL";
      case CTAL: return "CTAL";
      case CTCC: return "CTCC";
      case CTAQ: return "CTAQ";
      case CTLQ: return "CTLQ";
      case CTCQ: return "CTCQ";
      case CTMQ: return "CTMQ";
      case HCQS: return "HCQS";
      case SLQS: return "SLQS";
      case SLTS: return "SLTS";
      case SLCB: return "SLCB";
      case MATR: return "MATR";
      case GHEX100: return "GHEX100";
      case GHEX101: return "GHEX101";
      case GHEX102: return "GHEX102";
      case GHEX103: return "GHEX103";
      case GHEX104: return "GHEX104";
      case GHEX105: return "GHEX105";
      case GHEX106: return "GHEX106";
      case GHEX107: return "GHEX107";
      case GHEX108: return "GHEX108";
      case GHEX109: return "GHEX109";
      case GHEX110: return "GHEX110";
      case GHEX111: return "GHEX111";
      case GHEX112: return "GHEX112";
      case GHEX113: return "GHEX113";
      case GHEX114: return "GHEX114";
      case GHEX115: return "GHEX115";
      case GHEX116: return "GHEX116";
      case GHEX117: return "GHEX117";
      case GHEX118: return "GHEX118";
      case GHEX119: return "GHEX119";
      case GHEX120: return "GHEX120";
      case GHEX121: return "GHEX121";
      case GHEX122: return "GHEX122";
      case GHEX123: return "GHEX123";
      case GHEX124: return "GHEX124";
      case GHEX125: return "GHEX125";
      case GHEX126: return "GHEX126";
      case GHEX127: return "GHEX127";
      case GHEX128: return "GHEX128";
      case GHEX129: return "GHEX129";
      case GHEX130: return "GHEX130";
      case GHEX131: return "GHEX131";
      case GHEX132: return "GHEX132";
      case GHEX133: return "GHEX133";
      case GHEX134: return "GHEX134";
      case GHEX135: return "GHEX135";
      case GHEX136: return "GHEX136";
      case GHEX137: return "GHEX137";
      case GHEX138: return "GHEX138";
      case GHEX139: return "GHEX139";
      case GHEX140: return "GHEX140";
      case GHEX141: return "GHEX141";
      case GHEX142: return "GHEX142";
      case GHEX143: return "GHEX143";
      case GHEX144: return "GHEX144";
      case GHEX145: return "GHEX145";
      case GHEX146: return "GHEX146";
      case GHEX147: return "GHEX147";
      case GHEX148: return "GHEX148";
      case GHEX149: return "GHEX149";
      case GHEX150: return "GHEX150";
      case GHEX151: return "GHEX151";
      case GHEX152: return "GHEX152";
      case GHEX153: return "GHEX153";
      case GHEX154: return "GHEX154";
      case GHEX155: return "GHEX155";
      case GHEX156: return "GHEX156";
      case GHEX157: return "GHEX157";
      case GHEX158: return "GHEX158";
      case GHEX159: return "GHEX159";
      case GHEX160: return "GHEX160";
      case GHEX161: return "GHEX161";
      case GHEX162: return "GHEX162";
      case GHEX163: return "GHEX163";
      case UNDEFINED: return "UNDEFINED";
      }
      return "";
};

undef::undef (void) {}

const long undef::nnodes = -1;

el_types undef::get_type(void) { return UNDEFINED; }

__base::__base(dnvgl::extfem::fem::cards::gelmnt1 const *data) :
   eleno(data->ELNOX), elident(data->ELNO), el_add(data->ELTYAD),
   nodes(data->NODIN.begin(), data->NODIN.end()),
   matref(-1), add_no(0),
   intno(0), mass_intno(0), i_strain_ref(0),
   i_stress_ref(0), strpoint_ref(0),
   section(), fixations(), eccentrities(),
   csys()
{}

__base::__base(dnvgl::extfem::fem::cards::gelref1 const *data) :
   eleno(0), elident(data->ELNO), el_add(0),
   nodes(),
   matref(data->MATNO), add_no(data->ADDNO),
   intno(data->INTNO), mass_intno(data->INTNO), i_strain_ref(data->STRANO),
   i_stress_ref(data->STRENO), strpoint_ref(data->STREPONO),
   section(data->GEONO.begin(), data->GEONO.end()),
   fixations(data->FIXNO.begin(), data->FIXNO.end()),
   eccentrities(data->ECCNO.begin(), data->ECCNO.end()),
   csys(data->TRANSNO.begin(), data->TRANSNO.end())
{}

__base::__base(__base const *data) {
   this->eleno = data->eleno;
   this->elident = data->elident;
   this->el_add = data->el_add;
   this->nodes = data->nodes;
   this->matref = data->matref;
   this->add_no = data->add_no;
   this->intno = data->intno;
   this->mass_intno = data->mass_intno;
   this->i_strain_ref = data->i_strain_ref;
   this->i_stress_ref = data->i_stress_ref;
   this->strpoint_ref = data->strpoint_ref;
   this->section = data->section;
   this->fixations = data->fixations;
   this->eccentrities = data->eccentrities;
   this->csys = data->csys;
}

__base::__base(void) {}

void __base::add(dnvgl::extfem::fem::cards::gelmnt1 const *data) {
   this->eleno = data->ELNOX;
   this->elident = data->ELNO;
   this->el_add = data->ELTYAD;
   this->nodes = data->NODIN;
}

void __base::add(dnvgl::extfem::fem::cards::gelref1 const *data) {
   this->elident = data->ELNO;
   this->matref = data->MATNO;
   this->add_no = data->ADDNO;
   this->intno = data->INTNO;
   this->mass_intno = data->INTNO;
   this->i_strain_ref = data->STRANO;
   this->i_stress_ref = data->STRENO;
   this->strpoint_ref = data->STREPONO;
   this->section = data->GEONO;
   this->fixations = data->FIXNO;
   this->eccentrities = data->ECCNO;
   this->csys = data->TRANSNO;
}

el_types __base::get_type(void) {
   return UNDEFINED;
}

undef::undef(const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
