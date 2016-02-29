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

using namespace ::dnvgl::extfem::fem::elements;

void dnvgl::extfem::fem::elements::dispatch(
   std::unique_ptr<__base> &res, const ::dnvgl::extfem::fem::cards::gelmnt1 *data) {

   switch (data->ELTYP) {
   case BEPS: res = ::std::make_unique<beps>(data); break;
   case CSTA: res = ::std::make_unique<csta>(data); break;
   case RPBQ: res = ::std::make_unique<rpbq>(data); break;
   case ILST: res = ::std::make_unique<ilst>(data); break;
   case IQQE: res = ::std::make_unique<iqqe>(data); break;
   case LQUA: res = ::std::make_unique<lqua>(data); break;
   case TESS: res = ::std::make_unique<tess>(data); break;
   case GMAS: res = ::std::make_unique<gmas>(data); break;
   case GLMA: res = ::std::make_unique<glma>(data); break;
   case GLDA: res = ::std::make_unique<glda>(data); break;
   case BEAS: res = ::std::make_unique<beas>(data); break;
   case AXIS: res = ::std::make_unique<axis>(data); break;
   case AXDA: res = ::std::make_unique<axda>(data); break;
   case GSPR: res = ::std::make_unique<gspr>(data); break;
   case GDAM: res = ::std::make_unique<gdam>(data); break;
   case IHEX: res = ::std::make_unique<ihex>(data); break;
   case LHEX: res = ::std::make_unique<lhex>(data); break;
   case SECB: res = ::std::make_unique<secb>(data); break;
   case BTSS: res = ::std::make_unique<btss>(data); break;
   case FQUS_FFQ: res = ::std::make_unique<fqus_ffq>(data); break;
   case FTRS_FFTR: res = ::std::make_unique<ftrs_fftr>(data); break;
   case SCTS: res = ::std::make_unique<scts>(data); break;
   case MCTS: res = ::std::make_unique<mcts>(data); break;
   case SCQS: res = ::std::make_unique<scqs>(data); break;
   case MCQS: res = ::std::make_unique<mcqs>(data); break;
   case IPRI: res = ::std::make_unique<ipri>(data); break;
   case ITET: res = ::std::make_unique<itet>(data); break;
   case TPRI: res = ::std::make_unique<tpri>(data); break;
   case TETR: res = ::std::make_unique<tetr>(data); break;
   case LCTS: res = ::std::make_unique<lcts>(data); break;
   case LCQS: res = ::std::make_unique<lcqs>(data); break;
   case TRS1: res = ::std::make_unique<trs1>(data); break;
   case TRS2: res = ::std::make_unique<trs2>(data); break;
   case TRS3: res = ::std::make_unique<trs3>(data); break;
   case GLSH: res = ::std::make_unique<glsh>(data); break;
   case AXCS: res = ::std::make_unique<axcs>(data); break;
   case AXLQ: res = ::std::make_unique<axlq>(data); break;
   case AXLS: res = ::std::make_unique<axls>(data); break;
   case AXQQ: res = ::std::make_unique<axqq>(data); break;
   case PILS: res = ::std::make_unique<pils>(data); break;
   case PCAB: res = ::std::make_unique<pcab>(data); break;
   case PSPR: res = ::std::make_unique<pspr>(data); break;
   case ADVA_4: res = ::std::make_unique<adva_4>(data); break;
   case ADVA_2: res = ::std::make_unique<adva_2>(data); break;
   case CTCP: res = ::std::make_unique<ctcp>(data); break;
   case CTCL: res = ::std::make_unique<ctcl>(data); break;
   case CTAL: res = ::std::make_unique<ctal>(data); break;
   case CTCC: res = ::std::make_unique<ctcc>(data); break;
   case CTAQ: res = ::std::make_unique<ctaq>(data); break;
   case CTLQ: res = ::std::make_unique<ctlq>(data); break;
   case CTCQ: res = ::std::make_unique<ctcq>(data); break;
   case CTMQ: res = ::std::make_unique<ctmq>(data); break;
   case HCQS: res = ::std::make_unique<hcqs>(data); break;
   case SLQS: res = ::std::make_unique<slqs>(data); break;
   case SLTS: res = ::std::make_unique<slts>(data); break;
   case SLCB: res = ::std::make_unique<slcb>(data); break;
   case MATR: res = ::std::make_unique<matr>(data); break;
   case GHEX100: res = ::std::make_unique<ghex100>(data); break;
   case GHEX101: res = ::std::make_unique<ghex101>(data); break;
   case GHEX102: res = ::std::make_unique<ghex102>(data); break;
   case GHEX103: res = ::std::make_unique<ghex103>(data); break;
   case GHEX104: res = ::std::make_unique<ghex104>(data); break;
   case GHEX105: res = ::std::make_unique<ghex105>(data); break;
   case GHEX106: res = ::std::make_unique<ghex106>(data); break;
   case GHEX107: res = ::std::make_unique<ghex107>(data); break;
   case GHEX108: res = ::std::make_unique<ghex108>(data); break;
   case GHEX109: res = ::std::make_unique<ghex109>(data); break;
   case GHEX110: res = ::std::make_unique<ghex110>(data); break;
   case GHEX111: res = ::std::make_unique<ghex111>(data); break;
   case GHEX112: res = ::std::make_unique<ghex112>(data); break;
   case GHEX113: res = ::std::make_unique<ghex113>(data); break;
   case GHEX114: res = ::std::make_unique<ghex114>(data); break;
   case GHEX115: res = ::std::make_unique<ghex115>(data); break;
   case GHEX116: res = ::std::make_unique<ghex116>(data); break;
   case GHEX117: res = ::std::make_unique<ghex117>(data); break;
   case GHEX118: res = ::std::make_unique<ghex118>(data); break;
   case GHEX119: res = ::std::make_unique<ghex119>(data); break;
   case GHEX120: res = ::std::make_unique<ghex120>(data); break;
   case GHEX121: res = ::std::make_unique<ghex121>(data); break;
   case GHEX122: res = ::std::make_unique<ghex122>(data); break;
   case GHEX123: res = ::std::make_unique<ghex123>(data); break;
   case GHEX124: res = ::std::make_unique<ghex124>(data); break;
   case GHEX125: res = ::std::make_unique<ghex125>(data); break;
   case GHEX126: res = ::std::make_unique<ghex126>(data); break;
   case GHEX127: res = ::std::make_unique<ghex127>(data); break;
   case GHEX128: res = ::std::make_unique<ghex128>(data); break;
   case GHEX129: res = ::std::make_unique<ghex129>(data); break;
   case GHEX130: res = ::std::make_unique<ghex130>(data); break;
   case GHEX131: res = ::std::make_unique<ghex131>(data); break;
   case GHEX132: res = ::std::make_unique<ghex132>(data); break;
   case GHEX133: res = ::std::make_unique<ghex133>(data); break;
   case GHEX134: res = ::std::make_unique<ghex134>(data); break;
   case GHEX135: res = ::std::make_unique<ghex135>(data); break;
   case GHEX136: res = ::std::make_unique<ghex136>(data); break;
   case GHEX137: res = ::std::make_unique<ghex137>(data); break;
   case GHEX138: res = ::std::make_unique<ghex138>(data); break;
   case GHEX139: res = ::std::make_unique<ghex139>(data); break;
   case GHEX140: res = ::std::make_unique<ghex140>(data); break;
   case GHEX141: res = ::std::make_unique<ghex141>(data); break;
   case GHEX142: res = ::std::make_unique<ghex142>(data); break;
   case GHEX143: res = ::std::make_unique<ghex143>(data); break;
   case GHEX144: res = ::std::make_unique<ghex144>(data); break;
   case GHEX145: res = ::std::make_unique<ghex145>(data); break;
   case GHEX146: res = ::std::make_unique<ghex146>(data); break;
   case GHEX147: res = ::std::make_unique<ghex147>(data); break;
   case GHEX148: res = ::std::make_unique<ghex148>(data); break;
   case GHEX149: res = ::std::make_unique<ghex149>(data); break;
   case GHEX150: res = ::std::make_unique<ghex150>(data); break;
   case GHEX151: res = ::std::make_unique<ghex151>(data); break;
   case GHEX152: res = ::std::make_unique<ghex152>(data); break;
   case GHEX153: res = ::std::make_unique<ghex153>(data); break;
   case GHEX154: res = ::std::make_unique<ghex154>(data); break;
   case GHEX155: res = ::std::make_unique<ghex155>(data); break;
   case GHEX156: res = ::std::make_unique<ghex156>(data); break;
   case GHEX157: res = ::std::make_unique<ghex157>(data); break;
   case GHEX158: res = ::std::make_unique<ghex158>(data); break;
   case GHEX159: res = ::std::make_unique<ghex159>(data); break;
   case GHEX160: res = ::std::make_unique<ghex160>(data); break;
   case GHEX161: res = ::std::make_unique<ghex161>(data); break;
   case GHEX162: res = ::std::make_unique<ghex162>(data); break;
   case GHEX163: res = ::std::make_unique<ghex163>(data); break;
   case UNDEFINED: res = ::std::make_unique<undef>(); break;
   };
}

undef::undef (void) {}

const long undef::nnodes = -1;

el_types undef::get_type(void) const { return UNDEFINED; }

__base::__base(dnvgl::extfem::fem::cards::gelmnt1 const *data) :
   eleno(data->ELNOX), elident(data->ELNO),
   nodes(data->NODIN.begin(), data->NODIN.end()) {}

__base::__base(dnvgl::extfem::fem::cards::gelref1 const *data) {}

__base::__base(__base const *data) {}

__base::__base(void) {}

void __base::add(dnvgl::extfem::fem::cards::gelmnt1 const *data) {}

void __base::add(dnvgl::extfem::fem::cards::gelref1 const *data) {}

ghex::ghex(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   __base(data) {}

ghex::ghex(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   __base(data) {}

ghex::ghex(const __base *p) :
   __base(p) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
