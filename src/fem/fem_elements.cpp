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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::dnvgl::extfem::fem::elements;


void dispatch(
   std::unique_ptr<__base>& res, const el_types &id, const ::dnvgl::extfem::fem::cards::gelmnt1 &data) {

   switch (id) {
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
   case GHEX163: res = ::std::make_unique<ghex163>(data); break;
   };
}

const long undef::nnodes = -1;

__base::__base(dnvgl::extfem::fem::cards::gelmnt1 const &data) {
   this->eleno = data.ELNOX;
   this->elident = data.ELNO;
   ::std::copy(data.NODIN.begin(), data.NODIN.end(), this->nodes.begin());
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
