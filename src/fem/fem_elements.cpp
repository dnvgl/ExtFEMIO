/*
   #####     #    #     # #######   ###   ####### #     #   ###
  #     #   # #   #     #    #       #    #     # ##    #   ###
  #        #   #  #     #    #       #    #     # # #   #   ###
  #       #     # #     #    #       #    #     # #  #  #    #
  #       ####### #     #    #       #    #     # #   # #
  #     # #     # #     #    #       #    #     # #    ##   ###
   #####  #     #  #####     #      ###   ####### #     #   ###

   Automatically generated source file. Contact author if changes are
   required.
 */

/**
   \file fem/fem_elements.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for FEM elements.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_elements[]
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

namespace dnvgl {
   namespace extfem {
      namespace fem {

         using namespace cards;

         namespace elements {

            void dispatch(
               std::unique_ptr<__base::elem> &res, const cards::gelmnt1 *data) {

               switch (data->ELTYP) {
               case el_types::BEPS: res = std::make_unique<beps>(data); break;
               case el_types::CSTA: res = std::make_unique<csta>(data); break;
               case el_types::RPBQ: res = std::make_unique<rpbq>(data); break;
               case el_types::ILST: res = std::make_unique<ilst>(data); break;
               case el_types::IQQE: res = std::make_unique<iqqe>(data); break;
               case el_types::LQUA: res = std::make_unique<lqua>(data); break;
               case el_types::TESS: res = std::make_unique<tess>(data); break;
               case el_types::GMAS: res = std::make_unique<gmas>(data); break;
               case el_types::GLMA: res = std::make_unique<glma>(data); break;
               case el_types::GLDA: res = std::make_unique<glda>(data); break;
               case el_types::BEAS: res = std::make_unique<beas>(data); break;
               case el_types::AXIS: res = std::make_unique<axis>(data); break;
               case el_types::AXDA: res = std::make_unique<axda>(data); break;
               case el_types::GSPR: res = std::make_unique<gspr>(data); break;
               case el_types::GDAM: res = std::make_unique<gdam>(data); break;
               case el_types::IHEX: res = std::make_unique<ihex>(data); break;
               case el_types::LHEX: res = std::make_unique<lhex>(data); break;
               case el_types::SECB: res = std::make_unique<secb>(data); break;
               case el_types::BTSS: res = std::make_unique<btss>(data); break;
               case el_types::FQUS_FFQ: res = std::make_unique<fqus_ffq>(data); break;
               case el_types::FTRS_FFTR: res = std::make_unique<ftrs_fftr>(data); break;
               case el_types::SCTS: res = std::make_unique<scts>(data); break;
               case el_types::MCTS: res = std::make_unique<mcts>(data); break;
               case el_types::SCQS: res = std::make_unique<scqs>(data); break;
               case el_types::MCQS: res = std::make_unique<mcqs>(data); break;
               case el_types::IPRI: res = std::make_unique<ipri>(data); break;
               case el_types::ITET: res = std::make_unique<itet>(data); break;
               case el_types::TPRI: res = std::make_unique<tpri>(data); break;
               case el_types::TETR: res = std::make_unique<tetr>(data); break;
               case el_types::LCTS: res = std::make_unique<lcts>(data); break;
               case el_types::LCQS: res = std::make_unique<lcqs>(data); break;
               case el_types::TRS1: res = std::make_unique<trs1>(data); break;
               case el_types::TRS2: res = std::make_unique<trs2>(data); break;
               case el_types::TRS3: res = std::make_unique<trs3>(data); break;
               case el_types::GLSH: res = std::make_unique<glsh>(data); break;
               case el_types::AXCS: res = std::make_unique<axcs>(data); break;
               case el_types::AXLQ: res = std::make_unique<axlq>(data); break;
               case el_types::AXLS: res = std::make_unique<axls>(data); break;
               case el_types::AXQQ: res = std::make_unique<axqq>(data); break;
               case el_types::PILS: res = std::make_unique<pils>(data); break;
               case el_types::PCAB: res = std::make_unique<pcab>(data); break;
               case el_types::PSPR: res = std::make_unique<pspr>(data); break;
               case el_types::ADVA_4: res = std::make_unique<adva_4>(data); break;
               case el_types::ADVA_2: res = std::make_unique<adva_2>(data); break;
               case el_types::CTCP: res = std::make_unique<ctcp>(data); break;
               case el_types::CTCL: res = std::make_unique<ctcl>(data); break;
               case el_types::CTAL: res = std::make_unique<ctal>(data); break;
               case el_types::CTCC: res = std::make_unique<ctcc>(data); break;
               case el_types::CTAQ: res = std::make_unique<ctaq>(data); break;
               case el_types::CTLQ: res = std::make_unique<ctlq>(data); break;
               case el_types::CTCQ: res = std::make_unique<ctcq>(data); break;
               case el_types::CTMQ: res = std::make_unique<ctmq>(data); break;
               case el_types::HCQS: res = std::make_unique<hcqs>(data); break;
               case el_types::SLQS: res = std::make_unique<slqs>(data); break;
               case el_types::SLTS: res = std::make_unique<slts>(data); break;
               case el_types::SLCB: res = std::make_unique<slcb>(data); break;
               case el_types::MATR: res = std::make_unique<matr>(data); break;
               case el_types::GHEX100: res = std::make_unique<ghex100>(data); break;
               case el_types::GHEX101: res = std::make_unique<ghex101>(data); break;
               case el_types::GHEX102: res = std::make_unique<ghex102>(data); break;
               case el_types::GHEX103: res = std::make_unique<ghex103>(data); break;
               case el_types::GHEX104: res = std::make_unique<ghex104>(data); break;
               case el_types::GHEX105: res = std::make_unique<ghex105>(data); break;
               case el_types::GHEX106: res = std::make_unique<ghex106>(data); break;
               case el_types::GHEX107: res = std::make_unique<ghex107>(data); break;
               case el_types::GHEX108: res = std::make_unique<ghex108>(data); break;
               case el_types::GHEX109: res = std::make_unique<ghex109>(data); break;
               case el_types::GHEX110: res = std::make_unique<ghex110>(data); break;
               case el_types::GHEX111: res = std::make_unique<ghex111>(data); break;
               case el_types::GHEX112: res = std::make_unique<ghex112>(data); break;
               case el_types::GHEX113: res = std::make_unique<ghex113>(data); break;
               case el_types::GHEX114: res = std::make_unique<ghex114>(data); break;
               case el_types::GHEX115: res = std::make_unique<ghex115>(data); break;
               case el_types::GHEX116: res = std::make_unique<ghex116>(data); break;
               case el_types::GHEX117: res = std::make_unique<ghex117>(data); break;
               case el_types::GHEX118: res = std::make_unique<ghex118>(data); break;
               case el_types::GHEX119: res = std::make_unique<ghex119>(data); break;
               case el_types::GHEX120: res = std::make_unique<ghex120>(data); break;
               case el_types::GHEX121: res = std::make_unique<ghex121>(data); break;
               case el_types::GHEX122: res = std::make_unique<ghex122>(data); break;
               case el_types::GHEX123: res = std::make_unique<ghex123>(data); break;
               case el_types::GHEX124: res = std::make_unique<ghex124>(data); break;
               case el_types::GHEX125: res = std::make_unique<ghex125>(data); break;
               case el_types::GHEX126: res = std::make_unique<ghex126>(data); break;
               case el_types::GHEX127: res = std::make_unique<ghex127>(data); break;
               case el_types::GHEX128: res = std::make_unique<ghex128>(data); break;
               case el_types::GHEX129: res = std::make_unique<ghex129>(data); break;
               case el_types::GHEX130: res = std::make_unique<ghex130>(data); break;
               case el_types::GHEX131: res = std::make_unique<ghex131>(data); break;
               case el_types::GHEX132: res = std::make_unique<ghex132>(data); break;
               case el_types::GHEX133: res = std::make_unique<ghex133>(data); break;
               case el_types::GHEX134: res = std::make_unique<ghex134>(data); break;
               case el_types::GHEX135: res = std::make_unique<ghex135>(data); break;
               case el_types::GHEX136: res = std::make_unique<ghex136>(data); break;
               case el_types::GHEX137: res = std::make_unique<ghex137>(data); break;
               case el_types::GHEX138: res = std::make_unique<ghex138>(data); break;
               case el_types::GHEX139: res = std::make_unique<ghex139>(data); break;
               case el_types::GHEX140: res = std::make_unique<ghex140>(data); break;
               case el_types::GHEX141: res = std::make_unique<ghex141>(data); break;
               case el_types::GHEX142: res = std::make_unique<ghex142>(data); break;
               case el_types::GHEX143: res = std::make_unique<ghex143>(data); break;
               case el_types::GHEX144: res = std::make_unique<ghex144>(data); break;
               case el_types::GHEX145: res = std::make_unique<ghex145>(data); break;
               case el_types::GHEX146: res = std::make_unique<ghex146>(data); break;
               case el_types::GHEX147: res = std::make_unique<ghex147>(data); break;
               case el_types::GHEX148: res = std::make_unique<ghex148>(data); break;
               case el_types::GHEX149: res = std::make_unique<ghex149>(data); break;
               case el_types::GHEX150: res = std::make_unique<ghex150>(data); break;
               case el_types::GHEX151: res = std::make_unique<ghex151>(data); break;
               case el_types::GHEX152: res = std::make_unique<ghex152>(data); break;
               case el_types::GHEX153: res = std::make_unique<ghex153>(data); break;
               case el_types::GHEX154: res = std::make_unique<ghex154>(data); break;
               case el_types::GHEX155: res = std::make_unique<ghex155>(data); break;
               case el_types::GHEX156: res = std::make_unique<ghex156>(data); break;
               case el_types::GHEX157: res = std::make_unique<ghex157>(data); break;
               case el_types::GHEX158: res = std::make_unique<ghex158>(data); break;
               case el_types::GHEX159: res = std::make_unique<ghex159>(data); break;
               case el_types::GHEX160: res = std::make_unique<ghex160>(data); break;
               case el_types::GHEX161: res = std::make_unique<ghex161>(data); break;
               case el_types::GHEX162: res = std::make_unique<ghex162>(data); break;
               case el_types::GHEX163: res = std::make_unique<ghex163>(data); break;
               case el_types::UNDEFINED: res = std::make_unique<undef>(); break;
               case el_types::INVALID: throw errors::parse_error(
                  "GELMNT1", "invalid element type"); break;
               };
            }

            std::string name_elem(el_types const &type) {
               switch (type) {
               case el_types::BEPS: return "BEPS";
               case el_types::CSTA: return "CSTA";
               case el_types::RPBQ: return "RPBQ";
               case el_types::ILST: return "ILST";
               case el_types::IQQE: return "IQQE";
               case el_types::LQUA: return "LQUA";
               case el_types::TESS: return "TESS";
               case el_types::GMAS: return "GMAS";
               case el_types::GLMA: return "GLMA";
               case el_types::GLDA: return "GLDA";
               case el_types::BEAS: return "BEAS";
               case el_types::AXIS: return "AXIS";
               case el_types::AXDA: return "AXDA";
               case el_types::GSPR: return "GSPR";
               case el_types::GDAM: return "GDAM";
               case el_types::IHEX: return "IHEX";
               case el_types::LHEX: return "LHEX";
               case el_types::SECB: return "SECB";
               case el_types::BTSS: return "BTSS";
               case el_types::FQUS_FFQ: return "FQUS_FFQ";
               case el_types::FTRS_FFTR: return "FTRS_FFTR";
               case el_types::SCTS: return "SCTS";
               case el_types::MCTS: return "MCTS";
               case el_types::SCQS: return "SCQS";
               case el_types::MCQS: return "MCQS";
               case el_types::IPRI: return "IPRI";
               case el_types::ITET: return "ITET";
               case el_types::TPRI: return "TPRI";
               case el_types::TETR: return "TETR";
               case el_types::LCTS: return "LCTS";
               case el_types::LCQS: return "LCQS";
               case el_types::TRS1: return "TRS1";
               case el_types::TRS2: return "TRS2";
               case el_types::TRS3: return "TRS3";
               case el_types::GLSH: return "GLSH";
               case el_types::AXCS: return "AXCS";
               case el_types::AXLQ: return "AXLQ";
               case el_types::AXLS: return "AXLS";
               case el_types::AXQQ: return "AXQQ";
               case el_types::PILS: return "PILS";
               case el_types::PCAB: return "PCAB";
               case el_types::PSPR: return "PSPR";
               case el_types::ADVA_4: return "ADVA_4";
               case el_types::ADVA_2: return "ADVA_2";
               case el_types::CTCP: return "CTCP";
               case el_types::CTCL: return "CTCL";
               case el_types::CTAL: return "CTAL";
               case el_types::CTCC: return "CTCC";
               case el_types::CTAQ: return "CTAQ";
               case el_types::CTLQ: return "CTLQ";
               case el_types::CTCQ: return "CTCQ";
               case el_types::CTMQ: return "CTMQ";
               case el_types::HCQS: return "HCQS";
               case el_types::SLQS: return "SLQS";
               case el_types::SLTS: return "SLTS";
               case el_types::SLCB: return "SLCB";
               case el_types::MATR: return "MATR";
               case el_types::GHEX100: return "GHEX100";
               case el_types::GHEX101: return "GHEX101";
               case el_types::GHEX102: return "GHEX102";
               case el_types::GHEX103: return "GHEX103";
               case el_types::GHEX104: return "GHEX104";
               case el_types::GHEX105: return "GHEX105";
               case el_types::GHEX106: return "GHEX106";
               case el_types::GHEX107: return "GHEX107";
               case el_types::GHEX108: return "GHEX108";
               case el_types::GHEX109: return "GHEX109";
               case el_types::GHEX110: return "GHEX110";
               case el_types::GHEX111: return "GHEX111";
               case el_types::GHEX112: return "GHEX112";
               case el_types::GHEX113: return "GHEX113";
               case el_types::GHEX114: return "GHEX114";
               case el_types::GHEX115: return "GHEX115";
               case el_types::GHEX116: return "GHEX116";
               case el_types::GHEX117: return "GHEX117";
               case el_types::GHEX118: return "GHEX118";
               case el_types::GHEX119: return "GHEX119";
               case el_types::GHEX120: return "GHEX120";
               case el_types::GHEX121: return "GHEX121";
               case el_types::GHEX122: return "GHEX122";
               case el_types::GHEX123: return "GHEX123";
               case el_types::GHEX124: return "GHEX124";
               case el_types::GHEX125: return "GHEX125";
               case el_types::GHEX126: return "GHEX126";
               case el_types::GHEX127: return "GHEX127";
               case el_types::GHEX128: return "GHEX128";
               case el_types::GHEX129: return "GHEX129";
               case el_types::GHEX130: return "GHEX130";
               case el_types::GHEX131: return "GHEX131";
               case el_types::GHEX132: return "GHEX132";
               case el_types::GHEX133: return "GHEX133";
               case el_types::GHEX134: return "GHEX134";
               case el_types::GHEX135: return "GHEX135";
               case el_types::GHEX136: return "GHEX136";
               case el_types::GHEX137: return "GHEX137";
               case el_types::GHEX138: return "GHEX138";
               case el_types::GHEX139: return "GHEX139";
               case el_types::GHEX140: return "GHEX140";
               case el_types::GHEX141: return "GHEX141";
               case el_types::GHEX142: return "GHEX142";
               case el_types::GHEX143: return "GHEX143";
               case el_types::GHEX144: return "GHEX144";
               case el_types::GHEX145: return "GHEX145";
               case el_types::GHEX146: return "GHEX146";
               case el_types::GHEX147: return "GHEX147";
               case el_types::GHEX148: return "GHEX148";
               case el_types::GHEX149: return "GHEX149";
               case el_types::GHEX150: return "GHEX150";
               case el_types::GHEX151: return "GHEX151";
               case el_types::GHEX152: return "GHEX152";
               case el_types::GHEX153: return "GHEX153";
               case el_types::GHEX154: return "GHEX154";
               case el_types::GHEX155: return "GHEX155";
               case el_types::GHEX156: return "GHEX156";
               case el_types::GHEX157: return "GHEX157";
               case el_types::GHEX158: return "GHEX158";
               case el_types::GHEX159: return "GHEX159";
               case el_types::GHEX160: return "GHEX160";
               case el_types::GHEX161: return "GHEX161";
               case el_types::GHEX162: return "GHEX162";
               case el_types::GHEX163: return "GHEX163";
               case el_types::UNDEFINED: return "UNDEFINED";
               case el_types::INVALID: return "INVALID";
               }
               return "";
            };

            undef::undef (void) {}

            long undef::nnodes(void) const {return -1;}

            el_types undef::get_type(void) const {return el_types::UNDEFINED;}

            namespace __base {

               elem::elem(void) :
                  eleno(-1), elident(-1), el_add(-1), nodes({}),
                  matref(-1), add_no(-1), intno(-1), mass_intno(-1),
                  i_strain_ref(-1), i_stress_ref(-1),
                  strpoint_ref(-1), section({}),
                  fixations({}), eccentrities({}), csys({}) {}

               elem::elem(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  eleno(eleno), elident(elident), el_add(el_add),
                  nodes(nodes), matref(matref), add_no(add_no),
                  intno(intno), mass_intno(mass_intno),
                  i_strain_ref(i_strain_ref),
                  i_stress_ref(i_stress_ref),
                  strpoint_ref(strpoint_ref),
                  section(section), fixations(fixations),
                  eccentrities(eccentrities), csys(csys) {}

               elem::elem(cards::gelmnt1 const *data) :
                  matref(-1), add_no(0),
                  intno(0), mass_intno(0), i_strain_ref(0),
                  i_stress_ref(0), strpoint_ref(0),
                  section(), fixations(), eccentrities(),
                  csys() {
                  this->add(data);
               }

               elem::elem(cards::gelref1 const *data) :
                  eleno(0), el_add(0), nodes() {
                  this->add(data);
               }

               elem::elem(elem const *data) {
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

               void elem::add(cards::gelmnt1 const *data) {
                  this->eleno = data->ELNOX;
                  this->elident = data->ELNO;
                  this->el_add = data->ELTYAD;
                  this->nodes = data->NODIN;
               }

               void elem::add(cards::gelref1 const *data) {
                  this->elident = data->ELNO;
                  this->matref = data->MATNO;
                  this->add_no = data->ADDNO;
                  this->intno = data->INTNO;
                  this->mass_intno = data->MINTNO;
                  this->i_strain_ref = data->STRANO;
                  this->i_stress_ref = data->STRENO;
                  this->strpoint_ref = data->STREPONO;
                  if (data->GEONO_OPT == -1)
                     this->section = data->GEONO;
                  else if (data->GEONO_OPT != 0)
                     this->section.push_back(data->GEONO_OPT);
                  if (data->FIXNO_OPT == -1)
                     this->fixations = data->FIXNO;
                  else if (data->FIXNO_OPT != 0)
                     this->fixations.push_back(data->FIXNO_OPT);
                  if (data->ECCNO_OPT == -1)
                     this->eccentrities = data->ECCNO;
                  else if (data->ECCNO_OPT != 0)
                     this->eccentrities.push_back(data->ECCNO_OPT);
                  if (data->TRANSNO_OPT == -1)
                     this->csys = data->TRANSNO;
                  else if (data->TRANSNO_OPT != 0)
                     this->csys.push_back(data->TRANSNO_OPT);
               }

               cards::gelmnt1 elem::gelmnt1(void) const {
                  return cards::gelmnt1(this->eleno,   // ELNOX
                                        this->elident, // ELNO
                                        this->get_type(),
                                        this->el_add,  // ELTYAD
                                        this->nodes);  // NODIN
               }

               cards::gelref1 elem::gelref1(void) const {
                  long geono_opt;
                  long fixno_opt;
                  long eccno_opt;
                  long transno_opt;

                  if (this->section.size() == 0) {
                     geono_opt = 0;
                  } else if (this->section.size() == 1) {
                     geono_opt = this->section[0];
                  } else {
                     geono_opt = -1;
                  }
                  if (this->fixations.size() == 0) {
                     fixno_opt = 0;
                  } else if (this->fixations.size() == 1) {
                     fixno_opt = this->fixations[0];
                  } else {
                     fixno_opt = -1;
                  }
                  if (this->eccentrities.size() == 0) {
                     eccno_opt = 0;
                  } else if (this->eccentrities.size() == 1) {
                     eccno_opt = this->eccentrities[0];
                  } else {
                     eccno_opt = -1;
                  }
                  if (this->csys.size() == 0) {
                     transno_opt = 0;
                  } else if (this->csys.size() == 1) {
                     transno_opt = this->csys[0];
                  } else {
                     transno_opt = -1;
                  }

                  return cards::gelref1(
                     this->elident,      // ELNO
                     this->matref,       // MATNO
                     this->add_no,       // ADDNO
                     this->intno,        // INTNO;
                     this->mass_intno,   // MINTNO;
                     this->i_strain_ref, // STRANO;
                     this->i_stress_ref, // STRENO;
                     this->strpoint_ref, // STREPONO;
                     geono_opt,
                     fixno_opt,
                     eccno_opt,
                     transno_opt,
                     this->section.size() > 1 ? this->section : std::vector<long>({}),
                     this->fixations.size() > 1 ? this->fixations : std::vector<long>({}),
                     this->eccentrities.size() > 1 ? this->eccentrities : std::vector<long>({}),
                     this->csys.size() > 1 ? this->csys : std::vector<long>({}));
               }
            }

            undef::undef(const cards::gelref1 *data) :
               __base::elem(data) {}

            namespace __base {
               std::ostream &operator<<(std::ostream &os, __base::elem const &data) {
                  if (data.elident < 0) return os;
                  os << data.gelmnt1();
                  os << data.gelref1();
                  return os;
               }

/**
   \brief FEM element definition for fem_thin_shell.

   Flat Quadrilateral/Triangular Thin Shell / Free Formulation
   Quadrilateral/Triangular Shell
*/

               fem_thin_shell::fem_thin_shell(void) : elem() {}

               fem_thin_shell::fem_thin_shell(
                  long const elno,
                  long const elident,
                  long const el_add,
                  std::vector<long> const nodes,
                  long const matref,
                  long const add_no,
                  long const intno,
                  long const mass_intno,
                  long const i_strain_ref,
                  long const i_stressef,
                  long const strpoint_ref,
                  std::vector<long> const sections,
                  std::vector<long> const fixations,
                  std::vector<long> const eccentrities,
                  std::vector<long> const csys) :
                  elem (elno, elident, el_add, nodes, matref, add_no,
                        intno, mass_intno, i_strain_ref, i_stressef,
                        strpoint_ref, sections, fixations,
                        eccentrities, csys) {}

               fem_thin_shell::fem_thin_shell(cards::gelmnt1 const *data) :
                  elem(data) {}

               fem_thin_shell::fem_thin_shell(cards::gelref1 const *data) :
                  elem(data) {}

               fem_thin_shell::fem_thin_shell(__base::elem const *data) :
                  elem(data) {}
            }

/**
   \brief FEM element definition for beps.

   
*/

            namespace {
               const size_t beps_procs_len = 3;
               el_processor beps_procs[beps_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::ADVANCE };
            }

            long beps::nnodes(void) const {return 2;}

            el_types beps::get_type(void) const {return el_types::BEPS;}

            const std::set<el_processor> beps::processors(
               beps_procs, beps_procs+beps_procs_len);

            beps::beps(void) : elem() {}

            beps::beps(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            beps::beps(const cards::gelmnt1 *data) : elem(data) {}

            beps::beps(const cards::gelref1 *data) : elem(data) {}

            beps::beps(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for csta.

   
*/

            namespace {
               const size_t csta_procs_len = 4;
               el_processor csta_procs[csta_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE };
            }

            long csta::nnodes(void) const {return 3;}

            el_types csta::get_type(void) const {return el_types::CSTA;}

            const std::set<el_processor> csta::processors(
               csta_procs, csta_procs+csta_procs_len);

            csta::csta(void) : elem() {}

            csta::csta(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            csta::csta(const cards::gelmnt1 *data) : elem(data) {}

            csta::csta(const cards::gelref1 *data) : elem(data) {}

            csta::csta(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for rpbq.

   
*/

            namespace {
               const size_t rpbq_procs_len = 1;
               el_processor rpbq_procs[rpbq_procs_len] = { el_processor::general };
            }

            long rpbq::nnodes(void) const {return 4;}

            el_types rpbq::get_type(void) const {return el_types::RPBQ;}

            const std::set<el_processor> rpbq::processors(
               rpbq_procs, rpbq_procs+rpbq_procs_len);

            rpbq::rpbq(void) : elem() {}

            rpbq::rpbq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            rpbq::rpbq(const cards::gelmnt1 *data) : elem(data) {}

            rpbq::rpbq(const cards::gelref1 *data) : elem(data) {}

            rpbq::rpbq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ilst.

   
*/

            namespace {
               const size_t ilst_procs_len = 3;
               el_processor ilst_procs[ilst_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long ilst::nnodes(void) const {return 6;}

            el_types ilst::get_type(void) const {return el_types::ILST;}

            const std::set<el_processor> ilst::processors(
               ilst_procs, ilst_procs+ilst_procs_len);

            ilst::ilst(void) : elem() {}

            ilst::ilst(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ilst::ilst(const cards::gelmnt1 *data) : elem(data) {}

            ilst::ilst(const cards::gelref1 *data) : elem(data) {}

            ilst::ilst(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for iqqe.

   
*/

            namespace {
               const size_t iqqe_procs_len = 3;
               el_processor iqqe_procs[iqqe_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long iqqe::nnodes(void) const {return 8;}

            el_types iqqe::get_type(void) const {return el_types::IQQE;}

            const std::set<el_processor> iqqe::processors(
               iqqe_procs, iqqe_procs+iqqe_procs_len);

            iqqe::iqqe(void) : elem() {}

            iqqe::iqqe(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            iqqe::iqqe(const cards::gelmnt1 *data) : elem(data) {}

            iqqe::iqqe(const cards::gelref1 *data) : elem(data) {}

            iqqe::iqqe(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for lqua.

   
*/

            namespace {
               const size_t lqua_procs_len = 5;
               el_processor lqua_procs[lqua_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Poseidon };
            }

            long lqua::nnodes(void) const {return 4;}

            el_types lqua::get_type(void) const {return el_types::LQUA;}

            const std::set<el_processor> lqua::processors(
               lqua_procs, lqua_procs+lqua_procs_len);

            lqua::lqua(void) : elem() {}

            lqua::lqua(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            lqua::lqua(const cards::gelmnt1 *data) : elem(data) {}

            lqua::lqua(const cards::gelref1 *data) : elem(data) {}

            lqua::lqua(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for tess.

   
*/

            namespace {
               const size_t tess_procs_len = 6;
               el_processor tess_procs[tess_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Poseidon };
            }

            long tess::nnodes(void) const {return 2;}

            el_types tess::get_type(void) const {return el_types::TESS;}

            const std::set<el_processor> tess::processors(
               tess_procs, tess_procs+tess_procs_len);

            tess::tess(void) : elem() {}

            tess::tess(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            tess::tess(const cards::gelmnt1 *data) : elem(data) {}

            tess::tess(const cards::gelref1 *data) : elem(data) {}

            tess::tess(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for gmas.

   
*/

            namespace {
               const size_t gmas_procs_len = 4;
               el_processor gmas_procs[gmas_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Poseidon };
            }

            long gmas::nnodes(void) const {return 1;}

            el_types gmas::get_type(void) const {return el_types::GMAS;}

            const std::set<el_processor> gmas::processors(
               gmas_procs, gmas_procs+gmas_procs_len);

            gmas::gmas(void) : elem() {}

            gmas::gmas(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            gmas::gmas(const cards::gelmnt1 *data) : elem(data) {}

            gmas::gmas(const cards::gelref1 *data) : elem(data) {}

            gmas::gmas(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for glma.

   
*/

            namespace {
               const size_t glma_procs_len = 2;
               el_processor glma_procs[glma_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long glma::nnodes(void) const {return 2;}

            el_types glma::get_type(void) const {return el_types::GLMA;}

            const std::set<el_processor> glma::processors(
               glma_procs, glma_procs+glma_procs_len);

            glma::glma(void) : elem() {}

            glma::glma(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            glma::glma(const cards::gelmnt1 *data) : elem(data) {}

            glma::glma(const cards::gelref1 *data) : elem(data) {}

            glma::glma(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for glda.

   
*/

            namespace {
               const size_t glda_procs_len = 1;
               el_processor glda_procs[glda_procs_len] = { el_processor::general };
            }

            long glda::nnodes(void) const {return 2;}

            el_types glda::get_type(void) const {return el_types::GLDA;}

            const std::set<el_processor> glda::processors(
               glda_procs, glda_procs+glda_procs_len);

            glda::glda(void) : elem() {}

            glda::glda(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            glda::glda(const cards::gelmnt1 *data) : elem(data) {}

            glda::glda(const cards::gelref1 *data) : elem(data) {}

            glda::glda(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for beas.

   
*/

            namespace {
               const size_t beas_procs_len = 11;
               el_processor beas_procs[beas_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework, el_processor::Launch, el_processor::Platework, el_processor::Pretube, el_processor::Wadam, el_processor::Poseidon };
            }

            long beas::nnodes(void) const {return 2;}

            el_types beas::get_type(void) const {return el_types::BEAS;}

            const std::set<el_processor> beas::processors(
               beas_procs, beas_procs+beas_procs_len);

            beas::beas(void) : elem() {}

            beas::beas(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            beas::beas(const cards::gelmnt1 *data) : elem(data) {}

            beas::beas(const cards::gelref1 *data) : elem(data) {}

            beas::beas(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for axis.

   
*/

            namespace {
               const size_t axis_procs_len = 7;
               el_processor axis_procs[axis_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework, el_processor::Poseidon };
            }

            long axis::nnodes(void) const {return 2;}

            el_types axis::get_type(void) const {return el_types::AXIS;}

            const std::set<el_processor> axis::processors(
               axis_procs, axis_procs+axis_procs_len);

            axis::axis(void) : elem() {}

            axis::axis(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            axis::axis(const cards::gelmnt1 *data) : elem(data) {}

            axis::axis(const cards::gelref1 *data) : elem(data) {}

            axis::axis(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for axda.

   
*/

            namespace {
               const size_t axda_procs_len = 5;
               el_processor axda_procs[axda_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::Poseidon };
            }

            long axda::nnodes(void) const {return 2;}

            el_types axda::get_type(void) const {return el_types::AXDA;}

            const std::set<el_processor> axda::processors(
               axda_procs, axda_procs+axda_procs_len);

            axda::axda(void) : elem() {}

            axda::axda(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            axda::axda(const cards::gelmnt1 *data) : elem(data) {}

            axda::axda(const cards::gelref1 *data) : elem(data) {}

            axda::axda(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for gspr.

   
*/

            namespace {
               const size_t gspr_procs_len = 7;
               el_processor gspr_procs[gspr_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework, el_processor::Poseidon };
            }

            long gspr::nnodes(void) const {return 1;}

            el_types gspr::get_type(void) const {return el_types::GSPR;}

            const std::set<el_processor> gspr::processors(
               gspr_procs, gspr_procs+gspr_procs_len);

            gspr::gspr(void) : elem() {}

            gspr::gspr(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            gspr::gspr(const cards::gelmnt1 *data) : elem(data) {}

            gspr::gspr(const cards::gelref1 *data) : elem(data) {}

            gspr::gspr(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for gdam.

   
*/

            namespace {
               const size_t gdam_procs_len = 5;
               el_processor gdam_procs[gdam_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Prefem, el_processor::Sestra, el_processor::Poseidon };
            }

            long gdam::nnodes(void) const {return 1;}

            el_types gdam::get_type(void) const {return el_types::GDAM;}

            const std::set<el_processor> gdam::processors(
               gdam_procs, gdam_procs+gdam_procs_len);

            gdam::gdam(void) : elem() {}

            gdam::gdam(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            gdam::gdam(const cards::gelmnt1 *data) : elem(data) {}

            gdam::gdam(const cards::gelref1 *data) : elem(data) {}

            gdam::gdam(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ihex.

   
*/

            namespace {
               const size_t ihex_procs_len = 5;
               el_processor ihex_procs[ihex_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework };
            }

            long ihex::nnodes(void) const {return 20;}

            el_types ihex::get_type(void) const {return el_types::IHEX;}

            const std::set<el_processor> ihex::processors(
               ihex_procs, ihex_procs+ihex_procs_len);

            ihex::ihex(void) : elem() {}

            ihex::ihex(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ihex::ihex(const cards::gelmnt1 *data) : elem(data) {}

            ihex::ihex(const cards::gelref1 *data) : elem(data) {}

            ihex::ihex(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for lhex.

   
*/

            namespace {
               const size_t lhex_procs_len = 5;
               el_processor lhex_procs[lhex_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Framework };
            }

            long lhex::nnodes(void) const {return 8;}

            el_types lhex::get_type(void) const {return el_types::LHEX;}

            const std::set<el_processor> lhex::processors(
               lhex_procs, lhex_procs+lhex_procs_len);

            lhex::lhex(void) : elem() {}

            lhex::lhex(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            lhex::lhex(const cards::gelmnt1 *data) : elem(data) {}

            lhex::lhex(const cards::gelref1 *data) : elem(data) {}

            lhex::lhex(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for secb.

   
*/

            namespace {
               const size_t secb_procs_len = 1;
               el_processor secb_procs[secb_procs_len] = { el_processor::general };
            }

            long secb::nnodes(void) const {return 3;}

            el_types secb::get_type(void) const {return el_types::SECB;}

            const std::set<el_processor> secb::processors(
               secb_procs, secb_procs+secb_procs_len);

            secb::secb(void) : elem() {}

            secb::secb(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            secb::secb(const cards::gelmnt1 *data) : elem(data) {}

            secb::secb(const cards::gelref1 *data) : elem(data) {}

            secb::secb(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for btss.

   
*/

            namespace {
               const size_t btss_procs_len = 5;
               el_processor btss_procs[btss_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework, el_processor::Pretube };
            }

            long btss::nnodes(void) const {return 3;}

            el_types btss::get_type(void) const {return el_types::BTSS;}

            const std::set<el_processor> btss::processors(
               btss_procs, btss_procs+btss_procs_len);

            btss::btss(void) : elem() {}

            btss::btss(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            btss::btss(const cards::gelmnt1 *data) : elem(data) {}

            btss::btss(const cards::gelref1 *data) : elem(data) {}

            btss::btss(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for fqus_ffq.

   
*/

            namespace {
               const size_t fqus_ffq_procs_len = 7;
               el_processor fqus_ffq_procs[fqus_ffq_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Platework, el_processor::Pretube, el_processor::Poseidon };
            }

            long fqus_ffq::nnodes(void) const {return 4;}

            el_types fqus_ffq::get_type(void) const {return el_types::FQUS_FFQ;}

            const std::set<el_processor> fqus_ffq::processors(
               fqus_ffq_procs, fqus_ffq_procs+fqus_ffq_procs_len);

            fqus_ffq::fqus_ffq(void) : fem_thin_shell() {}

            fqus_ffq::fqus_ffq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  fem_thin_shell(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            fqus_ffq::fqus_ffq(const cards::gelmnt1 *data) : fem_thin_shell(data) {}

            fqus_ffq::fqus_ffq(const cards::gelref1 *data) : fem_thin_shell(data) {}

            fqus_ffq::fqus_ffq(const __base::elem *data) : __base::fem_thin_shell(data) {}/**
   \brief FEM element definition for ftrs_fftr.

   
*/

            namespace {
               const size_t ftrs_fftr_procs_len = 6;
               el_processor ftrs_fftr_procs[ftrs_fftr_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE, el_processor::Platework, el_processor::Poseidon };
            }

            long ftrs_fftr::nnodes(void) const {return 3;}

            el_types ftrs_fftr::get_type(void) const {return el_types::FTRS_FFTR;}

            const std::set<el_processor> ftrs_fftr::processors(
               ftrs_fftr_procs, ftrs_fftr_procs+ftrs_fftr_procs_len);

            ftrs_fftr::ftrs_fftr(void) : fem_thin_shell() {}

            ftrs_fftr::ftrs_fftr(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  fem_thin_shell(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ftrs_fftr::ftrs_fftr(const cards::gelmnt1 *data) : fem_thin_shell(data) {}

            ftrs_fftr::ftrs_fftr(const cards::gelref1 *data) : fem_thin_shell(data) {}

            ftrs_fftr::ftrs_fftr(const __base::elem *data) : __base::fem_thin_shell(data) {}/**
   \brief FEM element definition for scts.

   
*/

            namespace {
               const size_t scts_procs_len = 4;
               el_processor scts_procs[scts_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework };
            }

            long scts::nnodes(void) const {return 6;}

            el_types scts::get_type(void) const {return el_types::SCTS;}

            const std::set<el_processor> scts::processors(
               scts_procs, scts_procs+scts_procs_len);

            scts::scts(void) : elem() {}

            scts::scts(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            scts::scts(const cards::gelmnt1 *data) : elem(data) {}

            scts::scts(const cards::gelref1 *data) : elem(data) {}

            scts::scts(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for mcts.

   
*/

            namespace {
               const size_t mcts_procs_len = 3;
               el_processor mcts_procs[mcts_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long mcts::nnodes(void) const {return 6;}

            el_types mcts::get_type(void) const {return el_types::MCTS;}

            const std::set<el_processor> mcts::processors(
               mcts_procs, mcts_procs+mcts_procs_len);

            mcts::mcts(void) : elem() {}

            mcts::mcts(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            mcts::mcts(const cards::gelmnt1 *data) : elem(data) {}

            mcts::mcts(const cards::gelref1 *data) : elem(data) {}

            mcts::mcts(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for scqs.

   
*/

            namespace {
               const size_t scqs_procs_len = 5;
               el_processor scqs_procs[scqs_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework, el_processor::Pretube };
            }

            long scqs::nnodes(void) const {return 8;}

            el_types scqs::get_type(void) const {return el_types::SCQS;}

            const std::set<el_processor> scqs::processors(
               scqs_procs, scqs_procs+scqs_procs_len);

            scqs::scqs(void) : elem() {}

            scqs::scqs(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            scqs::scqs(const cards::gelmnt1 *data) : elem(data) {}

            scqs::scqs(const cards::gelref1 *data) : elem(data) {}

            scqs::scqs(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for mcqs.

   
*/

            namespace {
               const size_t mcqs_procs_len = 3;
               el_processor mcqs_procs[mcqs_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long mcqs::nnodes(void) const {return 8;}

            el_types mcqs::get_type(void) const {return el_types::MCQS;}

            const std::set<el_processor> mcqs::processors(
               mcqs_procs, mcqs_procs+mcqs_procs_len);

            mcqs::mcqs(void) : elem() {}

            mcqs::mcqs(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            mcqs::mcqs(const cards::gelmnt1 *data) : elem(data) {}

            mcqs::mcqs(const cards::gelref1 *data) : elem(data) {}

            mcqs::mcqs(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ipri.

   
*/

            namespace {
               const size_t ipri_procs_len = 4;
               el_processor ipri_procs[ipri_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE };
            }

            long ipri::nnodes(void) const {return 15;}

            el_types ipri::get_type(void) const {return el_types::IPRI;}

            const std::set<el_processor> ipri::processors(
               ipri_procs, ipri_procs+ipri_procs_len);

            ipri::ipri(void) : elem() {}

            ipri::ipri(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ipri::ipri(const cards::gelmnt1 *data) : elem(data) {}

            ipri::ipri(const cards::gelref1 *data) : elem(data) {}

            ipri::ipri(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for itet.

   
*/

            namespace {
               const size_t itet_procs_len = 2;
               el_processor itet_procs[itet_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long itet::nnodes(void) const {return 10;}

            el_types itet::get_type(void) const {return el_types::ITET;}

            const std::set<el_processor> itet::processors(
               itet_procs, itet_procs+itet_procs_len);

            itet::itet(void) : elem() {}

            itet::itet(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            itet::itet(const cards::gelmnt1 *data) : elem(data) {}

            itet::itet(const cards::gelref1 *data) : elem(data) {}

            itet::itet(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for tpri.

   
*/

            namespace {
               const size_t tpri_procs_len = 4;
               el_processor tpri_procs[tpri_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::Platework };
            }

            long tpri::nnodes(void) const {return 6;}

            el_types tpri::get_type(void) const {return el_types::TPRI;}

            const std::set<el_processor> tpri::processors(
               tpri_procs, tpri_procs+tpri_procs_len);

            tpri::tpri(void) : elem() {}

            tpri::tpri(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            tpri::tpri(const cards::gelmnt1 *data) : elem(data) {}

            tpri::tpri(const cards::gelref1 *data) : elem(data) {}

            tpri::tpri(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for tetr.

   
*/

            namespace {
               const size_t tetr_procs_len = 2;
               el_processor tetr_procs[tetr_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long tetr::nnodes(void) const {return 4;}

            el_types tetr::get_type(void) const {return el_types::TETR;}

            const std::set<el_processor> tetr::processors(
               tetr_procs, tetr_procs+tetr_procs_len);

            tetr::tetr(void) : elem() {}

            tetr::tetr(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            tetr::tetr(const cards::gelmnt1 *data) : elem(data) {}

            tetr::tetr(const cards::gelref1 *data) : elem(data) {}

            tetr::tetr(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for lcts.

   
*/

            namespace {
               const size_t lcts_procs_len = 3;
               el_processor lcts_procs[lcts_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long lcts::nnodes(void) const {return 6;}

            el_types lcts::get_type(void) const {return el_types::LCTS;}

            const std::set<el_processor> lcts::processors(
               lcts_procs, lcts_procs+lcts_procs_len);

            lcts::lcts(void) : elem() {}

            lcts::lcts(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            lcts::lcts(const cards::gelmnt1 *data) : elem(data) {}

            lcts::lcts(const cards::gelref1 *data) : elem(data) {}

            lcts::lcts(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for lcqs.

   
*/

            namespace {
               const size_t lcqs_procs_len = 3;
               el_processor lcqs_procs[lcqs_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long lcqs::nnodes(void) const {return 8;}

            el_types lcqs::get_type(void) const {return el_types::LCQS;}

            const std::set<el_processor> lcqs::processors(
               lcqs_procs, lcqs_procs+lcqs_procs_len);

            lcqs::lcqs(void) : elem() {}

            lcqs::lcqs(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            lcqs::lcqs(const cards::gelmnt1 *data) : elem(data) {}

            lcqs::lcqs(const cards::gelref1 *data) : elem(data) {}

            lcqs::lcqs(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for trs1.

   
*/

            namespace {
               const size_t trs1_procs_len = 3;
               el_processor trs1_procs[trs1_procs_len] = { el_processor::general, el_processor::Sestra, el_processor::Pretube };
            }

            long trs1::nnodes(void) const {return 18;}

            el_types trs1::get_type(void) const {return el_types::TRS1;}

            const std::set<el_processor> trs1::processors(
               trs1_procs, trs1_procs+trs1_procs_len);

            trs1::trs1(void) : elem() {}

            trs1::trs1(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            trs1::trs1(const cards::gelmnt1 *data) : elem(data) {}

            trs1::trs1(const cards::gelref1 *data) : elem(data) {}

            trs1::trs1(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for trs2.

   
*/

            namespace {
               const size_t trs2_procs_len = 3;
               el_processor trs2_procs[trs2_procs_len] = { el_processor::general, el_processor::Sestra, el_processor::Pretube };
            }

            long trs2::nnodes(void) const {return 15;}

            el_types trs2::get_type(void) const {return el_types::TRS2;}

            const std::set<el_processor> trs2::processors(
               trs2_procs, trs2_procs+trs2_procs_len);

            trs2::trs2(void) : elem() {}

            trs2::trs2(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            trs2::trs2(const cards::gelmnt1 *data) : elem(data) {}

            trs2::trs2(const cards::gelref1 *data) : elem(data) {}

            trs2::trs2(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for trs3.

   
*/

            namespace {
               const size_t trs3_procs_len = 3;
               el_processor trs3_procs[trs3_procs_len] = { el_processor::general, el_processor::Sestra, el_processor::Pretube };
            }

            long trs3::nnodes(void) const {return 12;}

            el_types trs3::get_type(void) const {return el_types::TRS3;}

            const std::set<el_processor> trs3::processors(
               trs3_procs, trs3_procs+trs3_procs_len);

            trs3::trs3(void) : elem() {}

            trs3::trs3(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            trs3::trs3(const cards::gelmnt1 *data) : elem(data) {}

            trs3::trs3(const cards::gelref1 *data) : elem(data) {}

            trs3::trs3(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for glsh.

   
*/

            namespace {
               const size_t glsh_procs_len = 4;
               el_processor glsh_procs[glsh_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::Sestra, el_processor::Poseidon };
            }

            long glsh::nnodes(void) const {return 2;}

            el_types glsh::get_type(void) const {return el_types::GLSH;}

            const std::set<el_processor> glsh::processors(
               glsh_procs, glsh_procs+glsh_procs_len);

            glsh::glsh(void) : elem() {}

            glsh::glsh(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            glsh::glsh(const cards::gelmnt1 *data) : elem(data) {}

            glsh::glsh(const cards::gelref1 *data) : elem(data) {}

            glsh::glsh(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for axcs.

   
*/

            namespace {
               const size_t axcs_procs_len = 4;
               el_processor axcs_procs[axcs_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE };
            }

            long axcs::nnodes(void) const {return 3;}

            el_types axcs::get_type(void) const {return el_types::AXCS;}

            const std::set<el_processor> axcs::processors(
               axcs_procs, axcs_procs+axcs_procs_len);

            axcs::axcs(void) : elem() {}

            axcs::axcs(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            axcs::axcs(const cards::gelmnt1 *data) : elem(data) {}

            axcs::axcs(const cards::gelref1 *data) : elem(data) {}

            axcs::axcs(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for axlq.

   
*/

            namespace {
               const size_t axlq_procs_len = 4;
               el_processor axlq_procs[axlq_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra, el_processor::ADVANCE };
            }

            long axlq::nnodes(void) const {return 4;}

            el_types axlq::get_type(void) const {return el_types::AXLQ;}

            const std::set<el_processor> axlq::processors(
               axlq_procs, axlq_procs+axlq_procs_len);

            axlq::axlq(void) : elem() {}

            axlq::axlq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            axlq::axlq(const cards::gelmnt1 *data) : elem(data) {}

            axlq::axlq(const cards::gelref1 *data) : elem(data) {}

            axlq::axlq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for axls.

   
*/

            namespace {
               const size_t axls_procs_len = 3;
               el_processor axls_procs[axls_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long axls::nnodes(void) const {return 6;}

            el_types axls::get_type(void) const {return el_types::AXLS;}

            const std::set<el_processor> axls::processors(
               axls_procs, axls_procs+axls_procs_len);

            axls::axls(void) : elem() {}

            axls::axls(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            axls::axls(const cards::gelmnt1 *data) : elem(data) {}

            axls::axls(const cards::gelref1 *data) : elem(data) {}

            axls::axls(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for axqq.

   
*/

            namespace {
               const size_t axqq_procs_len = 3;
               el_processor axqq_procs[axqq_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Sestra };
            }

            long axqq::nnodes(void) const {return 8;}

            el_types axqq::get_type(void) const {return el_types::AXQQ;}

            const std::set<el_processor> axqq::processors(
               axqq_procs, axqq_procs+axqq_procs_len);

            axqq::axqq(void) : elem() {}

            axqq::axqq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            axqq::axqq(const cards::gelmnt1 *data) : elem(data) {}

            axqq::axqq(const cards::gelref1 *data) : elem(data) {}

            axqq::axqq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for pils.

   
*/

            namespace {
               const size_t pils_procs_len = 3;
               el_processor pils_procs[pils_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::ADVANCE };
            }

            long pils::nnodes(void) const {return 1;}

            el_types pils::get_type(void) const {return el_types::PILS;}

            const std::set<el_processor> pils::processors(
               pils_procs, pils_procs+pils_procs_len);

            pils::pils(void) : elem() {}

            pils::pils(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            pils::pils(const cards::gelmnt1 *data) : elem(data) {}

            pils::pils(const cards::gelref1 *data) : elem(data) {}

            pils::pils(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for pcab.

   
*/

            namespace {
               const size_t pcab_procs_len = 3;
               el_processor pcab_procs[pcab_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::ADVANCE };
            }

            long pcab::nnodes(void) const {return 2;}

            el_types pcab::get_type(void) const {return el_types::PCAB;}

            const std::set<el_processor> pcab::processors(
               pcab_procs, pcab_procs+pcab_procs_len);

            pcab::pcab(void) : elem() {}

            pcab::pcab(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            pcab::pcab(const cards::gelmnt1 *data) : elem(data) {}

            pcab::pcab(const cards::gelref1 *data) : elem(data) {}

            pcab::pcab(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for pspr.

   
*/

            namespace {
               const size_t pspr_procs_len = 3;
               el_processor pspr_procs[pspr_procs_len] = { el_processor::general, el_processor::Preframe, el_processor::ADVANCE };
            }

            long pspr::nnodes(void) const {return 1;}

            el_types pspr::get_type(void) const {return el_types::PSPR;}

            const std::set<el_processor> pspr::processors(
               pspr_procs, pspr_procs+pspr_procs_len);

            pspr::pspr(void) : elem() {}

            pspr::pspr(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            pspr::pspr(const cards::gelmnt1 *data) : elem(data) {}

            pspr::pspr(const cards::gelref1 *data) : elem(data) {}

            pspr::pspr(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for adva_4.

   
*/

            namespace {
               const size_t adva_4_procs_len = 2;
               el_processor adva_4_procs[adva_4_procs_len] = { el_processor::general, el_processor::ADVANCE };
            }

            long adva_4::nnodes(void) const {return 4;}

            el_types adva_4::get_type(void) const {return el_types::ADVA_4;}

            const std::set<el_processor> adva_4::processors(
               adva_4_procs, adva_4_procs+adva_4_procs_len);

            adva_4::adva_4(void) : elem() {}

            adva_4::adva_4(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            adva_4::adva_4(const cards::gelmnt1 *data) : elem(data) {}

            adva_4::adva_4(const cards::gelref1 *data) : elem(data) {}

            adva_4::adva_4(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for adva_2.

   
*/

            namespace {
               const size_t adva_2_procs_len = 2;
               el_processor adva_2_procs[adva_2_procs_len] = { el_processor::general, el_processor::ADVANCE };
            }

            long adva_2::nnodes(void) const {return 2;}

            el_types adva_2::get_type(void) const {return el_types::ADVA_2;}

            const std::set<el_processor> adva_2::processors(
               adva_2_procs, adva_2_procs+adva_2_procs_len);

            adva_2::adva_2(void) : elem() {}

            adva_2::adva_2(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            adva_2::adva_2(const cards::gelmnt1 *data) : elem(data) {}

            adva_2::adva_2(const cards::gelref1 *data) : elem(data) {}

            adva_2::adva_2(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctcp.

   
*/

            namespace {
               const size_t ctcp_procs_len = 1;
               el_processor ctcp_procs[ctcp_procs_len] = { el_processor::general };
            }

            long ctcp::nnodes(void) const {return 2;}

            el_types ctcp::get_type(void) const {return el_types::CTCP;}

            const std::set<el_processor> ctcp::processors(
               ctcp_procs, ctcp_procs+ctcp_procs_len);

            ctcp::ctcp(void) : elem() {}

            ctcp::ctcp(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctcp::ctcp(const cards::gelmnt1 *data) : elem(data) {}

            ctcp::ctcp(const cards::gelref1 *data) : elem(data) {}

            ctcp::ctcp(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctcl.

   
*/

            namespace {
               const size_t ctcl_procs_len = 1;
               el_processor ctcl_procs[ctcl_procs_len] = { el_processor::general };
            }

            long ctcl::nnodes(void) const {return 4;}

            el_types ctcl::get_type(void) const {return el_types::CTCL;}

            const std::set<el_processor> ctcl::processors(
               ctcl_procs, ctcl_procs+ctcl_procs_len);

            ctcl::ctcl(void) : elem() {}

            ctcl::ctcl(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctcl::ctcl(const cards::gelmnt1 *data) : elem(data) {}

            ctcl::ctcl(const cards::gelref1 *data) : elem(data) {}

            ctcl::ctcl(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctal.

   
*/

            namespace {
               const size_t ctal_procs_len = 1;
               el_processor ctal_procs[ctal_procs_len] = { el_processor::general };
            }

            long ctal::nnodes(void) const {return 4;}

            el_types ctal::get_type(void) const {return el_types::CTAL;}

            const std::set<el_processor> ctal::processors(
               ctal_procs, ctal_procs+ctal_procs_len);

            ctal::ctal(void) : elem() {}

            ctal::ctal(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctal::ctal(const cards::gelmnt1 *data) : elem(data) {}

            ctal::ctal(const cards::gelref1 *data) : elem(data) {}

            ctal::ctal(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctcc.

   
*/

            namespace {
               const size_t ctcc_procs_len = 1;
               el_processor ctcc_procs[ctcc_procs_len] = { el_processor::general };
            }

            long ctcc::nnodes(void) const {return 6;}

            el_types ctcc::get_type(void) const {return el_types::CTCC;}

            const std::set<el_processor> ctcc::processors(
               ctcc_procs, ctcc_procs+ctcc_procs_len);

            ctcc::ctcc(void) : elem() {}

            ctcc::ctcc(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctcc::ctcc(const cards::gelmnt1 *data) : elem(data) {}

            ctcc::ctcc(const cards::gelref1 *data) : elem(data) {}

            ctcc::ctcc(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctaq.

   
*/

            namespace {
               const size_t ctaq_procs_len = 2;
               el_processor ctaq_procs[ctaq_procs_len] = { el_processor::general, el_processor::Prefem };
            }

            long ctaq::nnodes(void) const {return 6;}

            el_types ctaq::get_type(void) const {return el_types::CTAQ;}

            const std::set<el_processor> ctaq::processors(
               ctaq_procs, ctaq_procs+ctaq_procs_len);

            ctaq::ctaq(void) : elem() {}

            ctaq::ctaq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctaq::ctaq(const cards::gelmnt1 *data) : elem(data) {}

            ctaq::ctaq(const cards::gelref1 *data) : elem(data) {}

            ctaq::ctaq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctlq.

   
*/

            namespace {
               const size_t ctlq_procs_len = 2;
               el_processor ctlq_procs[ctlq_procs_len] = { el_processor::general, el_processor::Pretube };
            }

            long ctlq::nnodes(void) const {return 8;}

            el_types ctlq::get_type(void) const {return el_types::CTLQ;}

            const std::set<el_processor> ctlq::processors(
               ctlq_procs, ctlq_procs+ctlq_procs_len);

            ctlq::ctlq(void) : elem() {}

            ctlq::ctlq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctlq::ctlq(const cards::gelmnt1 *data) : elem(data) {}

            ctlq::ctlq(const cards::gelref1 *data) : elem(data) {}

            ctlq::ctlq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctcq.

   
*/

            namespace {
               const size_t ctcq_procs_len = 3;
               el_processor ctcq_procs[ctcq_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Pretube };
            }

            long ctcq::nnodes(void) const {return 16;}

            el_types ctcq::get_type(void) const {return el_types::CTCQ;}

            const std::set<el_processor> ctcq::processors(
               ctcq_procs, ctcq_procs+ctcq_procs_len);

            ctcq::ctcq(void) : elem() {}

            ctcq::ctcq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctcq::ctcq(const cards::gelmnt1 *data) : elem(data) {}

            ctcq::ctcq(const cards::gelref1 *data) : elem(data) {}

            ctcq::ctcq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ctmq.

   
*/

            namespace {
               const size_t ctmq_procs_len = 2;
               el_processor ctmq_procs[ctmq_procs_len] = { el_processor::general, el_processor::Pretube };
            }

            long ctmq::nnodes(void) const {return 18;}

            el_types ctmq::get_type(void) const {return el_types::CTMQ;}

            const std::set<el_processor> ctmq::processors(
               ctmq_procs, ctmq_procs+ctmq_procs_len);

            ctmq::ctmq(void) : elem() {}

            ctmq::ctmq(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ctmq::ctmq(const cards::gelmnt1 *data) : elem(data) {}

            ctmq::ctmq(const cards::gelref1 *data) : elem(data) {}

            ctmq::ctmq(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for hcqs.

   
*/

            namespace {
               const size_t hcqs_procs_len = 3;
               el_processor hcqs_procs[hcqs_procs_len] = { el_processor::general, el_processor::Prefem, el_processor::Pretube };
            }

            long hcqs::nnodes(void) const {return 9;}

            el_types hcqs::get_type(void) const {return el_types::HCQS;}

            const std::set<el_processor> hcqs::processors(
               hcqs_procs, hcqs_procs+hcqs_procs_len);

            hcqs::hcqs(void) : elem() {}

            hcqs::hcqs(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            hcqs::hcqs(const cards::gelmnt1 *data) : elem(data) {}

            hcqs::hcqs(const cards::gelref1 *data) : elem(data) {}

            hcqs::hcqs(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for slqs.

   
*/

            namespace {
               const size_t slqs_procs_len = 1;
               el_processor slqs_procs[slqs_procs_len] = { el_processor::general };
            }

            long slqs::nnodes(void) const {return 8;}

            el_types slqs::get_type(void) const {return el_types::SLQS;}

            const std::set<el_processor> slqs::processors(
               slqs_procs, slqs_procs+slqs_procs_len);

            slqs::slqs(void) : elem() {}

            slqs::slqs(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            slqs::slqs(const cards::gelmnt1 *data) : elem(data) {}

            slqs::slqs(const cards::gelref1 *data) : elem(data) {}

            slqs::slqs(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for slts.

   
*/

            namespace {
               const size_t slts_procs_len = 1;
               el_processor slts_procs[slts_procs_len] = { el_processor::general };
            }

            long slts::nnodes(void) const {return 6;}

            el_types slts::get_type(void) const {return el_types::SLTS;}

            const std::set<el_processor> slts::processors(
               slts_procs, slts_procs+slts_procs_len);

            slts::slts(void) : elem() {}

            slts::slts(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            slts::slts(const cards::gelmnt1 *data) : elem(data) {}

            slts::slts(const cards::gelref1 *data) : elem(data) {}

            slts::slts(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for slcb.

   
*/

            namespace {
               const size_t slcb_procs_len = 1;
               el_processor slcb_procs[slcb_procs_len] = { el_processor::general };
            }

            long slcb::nnodes(void) const {return 3;}

            el_types slcb::get_type(void) const {return el_types::SLCB;}

            const std::set<el_processor> slcb::processors(
               slcb_procs, slcb_procs+slcb_procs_len);

            slcb::slcb(void) : elem() {}

            slcb::slcb(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            slcb::slcb(const cards::gelmnt1 *data) : elem(data) {}

            slcb::slcb(const cards::gelref1 *data) : elem(data) {}

            slcb::slcb(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for matr.

   
*/

            namespace {
               const size_t matr_procs_len = 3;
               el_processor matr_procs[matr_procs_len] = { el_processor::general, el_processor::ADVANCE, el_processor::Splice };
            }

            long matr::nnodes(void) const {return 0;}

            el_types matr::get_type(void) const {return el_types::MATR;}

            const std::set<el_processor> matr::processors(
               matr_procs, matr_procs+matr_procs_len);

            matr::matr(void) : elem() {}

            matr::matr(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            matr::matr(const cards::gelmnt1 *data) : elem(data) {}

            matr::matr(const cards::gelref1 *data) : elem(data) {}

            matr::matr(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex100.

   
*/

            namespace {
               const size_t ghex100_procs_len = 2;
               el_processor ghex100_procs[ghex100_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex100::nnodes(void) const {return 21;}

            el_types ghex100::get_type(void) const {return el_types::GHEX100;}

            const std::set<el_processor> ghex100::processors(
               ghex100_procs, ghex100_procs+ghex100_procs_len);

            ghex100::ghex100(void) : elem() {}

            ghex100::ghex100(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex100::ghex100(const cards::gelmnt1 *data) : elem(data) {}

            ghex100::ghex100(const cards::gelref1 *data) : elem(data) {}

            ghex100::ghex100(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex101.

   
*/

            namespace {
               const size_t ghex101_procs_len = 2;
               el_processor ghex101_procs[ghex101_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex101::nnodes(void) const {return 22;}

            el_types ghex101::get_type(void) const {return el_types::GHEX101;}

            const std::set<el_processor> ghex101::processors(
               ghex101_procs, ghex101_procs+ghex101_procs_len);

            ghex101::ghex101(void) : elem() {}

            ghex101::ghex101(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex101::ghex101(const cards::gelmnt1 *data) : elem(data) {}

            ghex101::ghex101(const cards::gelref1 *data) : elem(data) {}

            ghex101::ghex101(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex102.

   
*/

            namespace {
               const size_t ghex102_procs_len = 2;
               el_processor ghex102_procs[ghex102_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex102::nnodes(void) const {return 22;}

            el_types ghex102::get_type(void) const {return el_types::GHEX102;}

            const std::set<el_processor> ghex102::processors(
               ghex102_procs, ghex102_procs+ghex102_procs_len);

            ghex102::ghex102(void) : elem() {}

            ghex102::ghex102(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex102::ghex102(const cards::gelmnt1 *data) : elem(data) {}

            ghex102::ghex102(const cards::gelref1 *data) : elem(data) {}

            ghex102::ghex102(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex103.

   
*/

            namespace {
               const size_t ghex103_procs_len = 2;
               el_processor ghex103_procs[ghex103_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex103::nnodes(void) const {return 23;}

            el_types ghex103::get_type(void) const {return el_types::GHEX103;}

            const std::set<el_processor> ghex103::processors(
               ghex103_procs, ghex103_procs+ghex103_procs_len);

            ghex103::ghex103(void) : elem() {}

            ghex103::ghex103(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex103::ghex103(const cards::gelmnt1 *data) : elem(data) {}

            ghex103::ghex103(const cards::gelref1 *data) : elem(data) {}

            ghex103::ghex103(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex104.

   
*/

            namespace {
               const size_t ghex104_procs_len = 2;
               el_processor ghex104_procs[ghex104_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex104::nnodes(void) const {return 22;}

            el_types ghex104::get_type(void) const {return el_types::GHEX104;}

            const std::set<el_processor> ghex104::processors(
               ghex104_procs, ghex104_procs+ghex104_procs_len);

            ghex104::ghex104(void) : elem() {}

            ghex104::ghex104(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex104::ghex104(const cards::gelmnt1 *data) : elem(data) {}

            ghex104::ghex104(const cards::gelref1 *data) : elem(data) {}

            ghex104::ghex104(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex105.

   
*/

            namespace {
               const size_t ghex105_procs_len = 2;
               el_processor ghex105_procs[ghex105_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex105::nnodes(void) const {return 23;}

            el_types ghex105::get_type(void) const {return el_types::GHEX105;}

            const std::set<el_processor> ghex105::processors(
               ghex105_procs, ghex105_procs+ghex105_procs_len);

            ghex105::ghex105(void) : elem() {}

            ghex105::ghex105(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex105::ghex105(const cards::gelmnt1 *data) : elem(data) {}

            ghex105::ghex105(const cards::gelref1 *data) : elem(data) {}

            ghex105::ghex105(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex106.

   
*/

            namespace {
               const size_t ghex106_procs_len = 2;
               el_processor ghex106_procs[ghex106_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex106::nnodes(void) const {return 23;}

            el_types ghex106::get_type(void) const {return el_types::GHEX106;}

            const std::set<el_processor> ghex106::processors(
               ghex106_procs, ghex106_procs+ghex106_procs_len);

            ghex106::ghex106(void) : elem() {}

            ghex106::ghex106(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex106::ghex106(const cards::gelmnt1 *data) : elem(data) {}

            ghex106::ghex106(const cards::gelref1 *data) : elem(data) {}

            ghex106::ghex106(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex107.

   
*/

            namespace {
               const size_t ghex107_procs_len = 2;
               el_processor ghex107_procs[ghex107_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex107::nnodes(void) const {return 24;}

            el_types ghex107::get_type(void) const {return el_types::GHEX107;}

            const std::set<el_processor> ghex107::processors(
               ghex107_procs, ghex107_procs+ghex107_procs_len);

            ghex107::ghex107(void) : elem() {}

            ghex107::ghex107(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex107::ghex107(const cards::gelmnt1 *data) : elem(data) {}

            ghex107::ghex107(const cards::gelref1 *data) : elem(data) {}

            ghex107::ghex107(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex108.

   
*/

            namespace {
               const size_t ghex108_procs_len = 2;
               el_processor ghex108_procs[ghex108_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex108::nnodes(void) const {return 22;}

            el_types ghex108::get_type(void) const {return el_types::GHEX108;}

            const std::set<el_processor> ghex108::processors(
               ghex108_procs, ghex108_procs+ghex108_procs_len);

            ghex108::ghex108(void) : elem() {}

            ghex108::ghex108(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex108::ghex108(const cards::gelmnt1 *data) : elem(data) {}

            ghex108::ghex108(const cards::gelref1 *data) : elem(data) {}

            ghex108::ghex108(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex109.

   
*/

            namespace {
               const size_t ghex109_procs_len = 2;
               el_processor ghex109_procs[ghex109_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex109::nnodes(void) const {return 23;}

            el_types ghex109::get_type(void) const {return el_types::GHEX109;}

            const std::set<el_processor> ghex109::processors(
               ghex109_procs, ghex109_procs+ghex109_procs_len);

            ghex109::ghex109(void) : elem() {}

            ghex109::ghex109(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex109::ghex109(const cards::gelmnt1 *data) : elem(data) {}

            ghex109::ghex109(const cards::gelref1 *data) : elem(data) {}

            ghex109::ghex109(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex110.

   
*/

            namespace {
               const size_t ghex110_procs_len = 2;
               el_processor ghex110_procs[ghex110_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex110::nnodes(void) const {return 23;}

            el_types ghex110::get_type(void) const {return el_types::GHEX110;}

            const std::set<el_processor> ghex110::processors(
               ghex110_procs, ghex110_procs+ghex110_procs_len);

            ghex110::ghex110(void) : elem() {}

            ghex110::ghex110(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex110::ghex110(const cards::gelmnt1 *data) : elem(data) {}

            ghex110::ghex110(const cards::gelref1 *data) : elem(data) {}

            ghex110::ghex110(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex111.

   
*/

            namespace {
               const size_t ghex111_procs_len = 2;
               el_processor ghex111_procs[ghex111_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex111::nnodes(void) const {return 24;}

            el_types ghex111::get_type(void) const {return el_types::GHEX111;}

            const std::set<el_processor> ghex111::processors(
               ghex111_procs, ghex111_procs+ghex111_procs_len);

            ghex111::ghex111(void) : elem() {}

            ghex111::ghex111(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex111::ghex111(const cards::gelmnt1 *data) : elem(data) {}

            ghex111::ghex111(const cards::gelref1 *data) : elem(data) {}

            ghex111::ghex111(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex112.

   
*/

            namespace {
               const size_t ghex112_procs_len = 2;
               el_processor ghex112_procs[ghex112_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex112::nnodes(void) const {return 23;}

            el_types ghex112::get_type(void) const {return el_types::GHEX112;}

            const std::set<el_processor> ghex112::processors(
               ghex112_procs, ghex112_procs+ghex112_procs_len);

            ghex112::ghex112(void) : elem() {}

            ghex112::ghex112(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex112::ghex112(const cards::gelmnt1 *data) : elem(data) {}

            ghex112::ghex112(const cards::gelref1 *data) : elem(data) {}

            ghex112::ghex112(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex113.

   
*/

            namespace {
               const size_t ghex113_procs_len = 2;
               el_processor ghex113_procs[ghex113_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex113::nnodes(void) const {return 24;}

            el_types ghex113::get_type(void) const {return el_types::GHEX113;}

            const std::set<el_processor> ghex113::processors(
               ghex113_procs, ghex113_procs+ghex113_procs_len);

            ghex113::ghex113(void) : elem() {}

            ghex113::ghex113(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex113::ghex113(const cards::gelmnt1 *data) : elem(data) {}

            ghex113::ghex113(const cards::gelref1 *data) : elem(data) {}

            ghex113::ghex113(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex114.

   
*/

            namespace {
               const size_t ghex114_procs_len = 2;
               el_processor ghex114_procs[ghex114_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex114::nnodes(void) const {return 24;}

            el_types ghex114::get_type(void) const {return el_types::GHEX114;}

            const std::set<el_processor> ghex114::processors(
               ghex114_procs, ghex114_procs+ghex114_procs_len);

            ghex114::ghex114(void) : elem() {}

            ghex114::ghex114(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex114::ghex114(const cards::gelmnt1 *data) : elem(data) {}

            ghex114::ghex114(const cards::gelref1 *data) : elem(data) {}

            ghex114::ghex114(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex115.

   
*/

            namespace {
               const size_t ghex115_procs_len = 2;
               el_processor ghex115_procs[ghex115_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex115::nnodes(void) const {return 25;}

            el_types ghex115::get_type(void) const {return el_types::GHEX115;}

            const std::set<el_processor> ghex115::processors(
               ghex115_procs, ghex115_procs+ghex115_procs_len);

            ghex115::ghex115(void) : elem() {}

            ghex115::ghex115(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex115::ghex115(const cards::gelmnt1 *data) : elem(data) {}

            ghex115::ghex115(const cards::gelref1 *data) : elem(data) {}

            ghex115::ghex115(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex116.

   
*/

            namespace {
               const size_t ghex116_procs_len = 2;
               el_processor ghex116_procs[ghex116_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex116::nnodes(void) const {return 22;}

            el_types ghex116::get_type(void) const {return el_types::GHEX116;}

            const std::set<el_processor> ghex116::processors(
               ghex116_procs, ghex116_procs+ghex116_procs_len);

            ghex116::ghex116(void) : elem() {}

            ghex116::ghex116(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex116::ghex116(const cards::gelmnt1 *data) : elem(data) {}

            ghex116::ghex116(const cards::gelref1 *data) : elem(data) {}

            ghex116::ghex116(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex117.

   
*/

            namespace {
               const size_t ghex117_procs_len = 2;
               el_processor ghex117_procs[ghex117_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex117::nnodes(void) const {return 23;}

            el_types ghex117::get_type(void) const {return el_types::GHEX117;}

            const std::set<el_processor> ghex117::processors(
               ghex117_procs, ghex117_procs+ghex117_procs_len);

            ghex117::ghex117(void) : elem() {}

            ghex117::ghex117(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex117::ghex117(const cards::gelmnt1 *data) : elem(data) {}

            ghex117::ghex117(const cards::gelref1 *data) : elem(data) {}

            ghex117::ghex117(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex118.

   
*/

            namespace {
               const size_t ghex118_procs_len = 2;
               el_processor ghex118_procs[ghex118_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex118::nnodes(void) const {return 23;}

            el_types ghex118::get_type(void) const {return el_types::GHEX118;}

            const std::set<el_processor> ghex118::processors(
               ghex118_procs, ghex118_procs+ghex118_procs_len);

            ghex118::ghex118(void) : elem() {}

            ghex118::ghex118(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex118::ghex118(const cards::gelmnt1 *data) : elem(data) {}

            ghex118::ghex118(const cards::gelref1 *data) : elem(data) {}

            ghex118::ghex118(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex119.

   
*/

            namespace {
               const size_t ghex119_procs_len = 2;
               el_processor ghex119_procs[ghex119_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex119::nnodes(void) const {return 24;}

            el_types ghex119::get_type(void) const {return el_types::GHEX119;}

            const std::set<el_processor> ghex119::processors(
               ghex119_procs, ghex119_procs+ghex119_procs_len);

            ghex119::ghex119(void) : elem() {}

            ghex119::ghex119(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex119::ghex119(const cards::gelmnt1 *data) : elem(data) {}

            ghex119::ghex119(const cards::gelref1 *data) : elem(data) {}

            ghex119::ghex119(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex120.

   
*/

            namespace {
               const size_t ghex120_procs_len = 2;
               el_processor ghex120_procs[ghex120_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex120::nnodes(void) const {return 23;}

            el_types ghex120::get_type(void) const {return el_types::GHEX120;}

            const std::set<el_processor> ghex120::processors(
               ghex120_procs, ghex120_procs+ghex120_procs_len);

            ghex120::ghex120(void) : elem() {}

            ghex120::ghex120(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex120::ghex120(const cards::gelmnt1 *data) : elem(data) {}

            ghex120::ghex120(const cards::gelref1 *data) : elem(data) {}

            ghex120::ghex120(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex121.

   
*/

            namespace {
               const size_t ghex121_procs_len = 2;
               el_processor ghex121_procs[ghex121_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex121::nnodes(void) const {return 24;}

            el_types ghex121::get_type(void) const {return el_types::GHEX121;}

            const std::set<el_processor> ghex121::processors(
               ghex121_procs, ghex121_procs+ghex121_procs_len);

            ghex121::ghex121(void) : elem() {}

            ghex121::ghex121(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex121::ghex121(const cards::gelmnt1 *data) : elem(data) {}

            ghex121::ghex121(const cards::gelref1 *data) : elem(data) {}

            ghex121::ghex121(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex122.

   
*/

            namespace {
               const size_t ghex122_procs_len = 2;
               el_processor ghex122_procs[ghex122_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex122::nnodes(void) const {return 24;}

            el_types ghex122::get_type(void) const {return el_types::GHEX122;}

            const std::set<el_processor> ghex122::processors(
               ghex122_procs, ghex122_procs+ghex122_procs_len);

            ghex122::ghex122(void) : elem() {}

            ghex122::ghex122(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex122::ghex122(const cards::gelmnt1 *data) : elem(data) {}

            ghex122::ghex122(const cards::gelref1 *data) : elem(data) {}

            ghex122::ghex122(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex123.

   
*/

            namespace {
               const size_t ghex123_procs_len = 2;
               el_processor ghex123_procs[ghex123_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex123::nnodes(void) const {return 25;}

            el_types ghex123::get_type(void) const {return el_types::GHEX123;}

            const std::set<el_processor> ghex123::processors(
               ghex123_procs, ghex123_procs+ghex123_procs_len);

            ghex123::ghex123(void) : elem() {}

            ghex123::ghex123(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex123::ghex123(const cards::gelmnt1 *data) : elem(data) {}

            ghex123::ghex123(const cards::gelref1 *data) : elem(data) {}

            ghex123::ghex123(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex124.

   
*/

            namespace {
               const size_t ghex124_procs_len = 2;
               el_processor ghex124_procs[ghex124_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex124::nnodes(void) const {return 23;}

            el_types ghex124::get_type(void) const {return el_types::GHEX124;}

            const std::set<el_processor> ghex124::processors(
               ghex124_procs, ghex124_procs+ghex124_procs_len);

            ghex124::ghex124(void) : elem() {}

            ghex124::ghex124(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex124::ghex124(const cards::gelmnt1 *data) : elem(data) {}

            ghex124::ghex124(const cards::gelref1 *data) : elem(data) {}

            ghex124::ghex124(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex125.

   
*/

            namespace {
               const size_t ghex125_procs_len = 2;
               el_processor ghex125_procs[ghex125_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex125::nnodes(void) const {return 24;}

            el_types ghex125::get_type(void) const {return el_types::GHEX125;}

            const std::set<el_processor> ghex125::processors(
               ghex125_procs, ghex125_procs+ghex125_procs_len);

            ghex125::ghex125(void) : elem() {}

            ghex125::ghex125(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex125::ghex125(const cards::gelmnt1 *data) : elem(data) {}

            ghex125::ghex125(const cards::gelref1 *data) : elem(data) {}

            ghex125::ghex125(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex126.

   
*/

            namespace {
               const size_t ghex126_procs_len = 2;
               el_processor ghex126_procs[ghex126_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex126::nnodes(void) const {return 24;}

            el_types ghex126::get_type(void) const {return el_types::GHEX126;}

            const std::set<el_processor> ghex126::processors(
               ghex126_procs, ghex126_procs+ghex126_procs_len);

            ghex126::ghex126(void) : elem() {}

            ghex126::ghex126(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex126::ghex126(const cards::gelmnt1 *data) : elem(data) {}

            ghex126::ghex126(const cards::gelref1 *data) : elem(data) {}

            ghex126::ghex126(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex127.

   
*/

            namespace {
               const size_t ghex127_procs_len = 2;
               el_processor ghex127_procs[ghex127_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex127::nnodes(void) const {return 25;}

            el_types ghex127::get_type(void) const {return el_types::GHEX127;}

            const std::set<el_processor> ghex127::processors(
               ghex127_procs, ghex127_procs+ghex127_procs_len);

            ghex127::ghex127(void) : elem() {}

            ghex127::ghex127(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex127::ghex127(const cards::gelmnt1 *data) : elem(data) {}

            ghex127::ghex127(const cards::gelref1 *data) : elem(data) {}

            ghex127::ghex127(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex128.

   
*/

            namespace {
               const size_t ghex128_procs_len = 2;
               el_processor ghex128_procs[ghex128_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex128::nnodes(void) const {return 24;}

            el_types ghex128::get_type(void) const {return el_types::GHEX128;}

            const std::set<el_processor> ghex128::processors(
               ghex128_procs, ghex128_procs+ghex128_procs_len);

            ghex128::ghex128(void) : elem() {}

            ghex128::ghex128(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex128::ghex128(const cards::gelmnt1 *data) : elem(data) {}

            ghex128::ghex128(const cards::gelref1 *data) : elem(data) {}

            ghex128::ghex128(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex129.

   
*/

            namespace {
               const size_t ghex129_procs_len = 2;
               el_processor ghex129_procs[ghex129_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex129::nnodes(void) const {return 25;}

            el_types ghex129::get_type(void) const {return el_types::GHEX129;}

            const std::set<el_processor> ghex129::processors(
               ghex129_procs, ghex129_procs+ghex129_procs_len);

            ghex129::ghex129(void) : elem() {}

            ghex129::ghex129(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex129::ghex129(const cards::gelmnt1 *data) : elem(data) {}

            ghex129::ghex129(const cards::gelref1 *data) : elem(data) {}

            ghex129::ghex129(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex130.

   
*/

            namespace {
               const size_t ghex130_procs_len = 2;
               el_processor ghex130_procs[ghex130_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex130::nnodes(void) const {return 25;}

            el_types ghex130::get_type(void) const {return el_types::GHEX130;}

            const std::set<el_processor> ghex130::processors(
               ghex130_procs, ghex130_procs+ghex130_procs_len);

            ghex130::ghex130(void) : elem() {}

            ghex130::ghex130(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex130::ghex130(const cards::gelmnt1 *data) : elem(data) {}

            ghex130::ghex130(const cards::gelref1 *data) : elem(data) {}

            ghex130::ghex130(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex131.

   
*/

            namespace {
               const size_t ghex131_procs_len = 2;
               el_processor ghex131_procs[ghex131_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex131::nnodes(void) const {return 26;}

            el_types ghex131::get_type(void) const {return el_types::GHEX131;}

            const std::set<el_processor> ghex131::processors(
               ghex131_procs, ghex131_procs+ghex131_procs_len);

            ghex131::ghex131(void) : elem() {}

            ghex131::ghex131(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex131::ghex131(const cards::gelmnt1 *data) : elem(data) {}

            ghex131::ghex131(const cards::gelref1 *data) : elem(data) {}

            ghex131::ghex131(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex132.

   
*/

            namespace {
               const size_t ghex132_procs_len = 2;
               el_processor ghex132_procs[ghex132_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex132::nnodes(void) const {return 22;}

            el_types ghex132::get_type(void) const {return el_types::GHEX132;}

            const std::set<el_processor> ghex132::processors(
               ghex132_procs, ghex132_procs+ghex132_procs_len);

            ghex132::ghex132(void) : elem() {}

            ghex132::ghex132(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex132::ghex132(const cards::gelmnt1 *data) : elem(data) {}

            ghex132::ghex132(const cards::gelref1 *data) : elem(data) {}

            ghex132::ghex132(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex133.

   
*/

            namespace {
               const size_t ghex133_procs_len = 2;
               el_processor ghex133_procs[ghex133_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex133::nnodes(void) const {return 23;}

            el_types ghex133::get_type(void) const {return el_types::GHEX133;}

            const std::set<el_processor> ghex133::processors(
               ghex133_procs, ghex133_procs+ghex133_procs_len);

            ghex133::ghex133(void) : elem() {}

            ghex133::ghex133(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex133::ghex133(const cards::gelmnt1 *data) : elem(data) {}

            ghex133::ghex133(const cards::gelref1 *data) : elem(data) {}

            ghex133::ghex133(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex134.

   
*/

            namespace {
               const size_t ghex134_procs_len = 2;
               el_processor ghex134_procs[ghex134_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex134::nnodes(void) const {return 23;}

            el_types ghex134::get_type(void) const {return el_types::GHEX134;}

            const std::set<el_processor> ghex134::processors(
               ghex134_procs, ghex134_procs+ghex134_procs_len);

            ghex134::ghex134(void) : elem() {}

            ghex134::ghex134(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex134::ghex134(const cards::gelmnt1 *data) : elem(data) {}

            ghex134::ghex134(const cards::gelref1 *data) : elem(data) {}

            ghex134::ghex134(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex135.

   
*/

            namespace {
               const size_t ghex135_procs_len = 2;
               el_processor ghex135_procs[ghex135_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex135::nnodes(void) const {return 24;}

            el_types ghex135::get_type(void) const {return el_types::GHEX135;}

            const std::set<el_processor> ghex135::processors(
               ghex135_procs, ghex135_procs+ghex135_procs_len);

            ghex135::ghex135(void) : elem() {}

            ghex135::ghex135(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex135::ghex135(const cards::gelmnt1 *data) : elem(data) {}

            ghex135::ghex135(const cards::gelref1 *data) : elem(data) {}

            ghex135::ghex135(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex136.

   
*/

            namespace {
               const size_t ghex136_procs_len = 2;
               el_processor ghex136_procs[ghex136_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex136::nnodes(void) const {return 23;}

            el_types ghex136::get_type(void) const {return el_types::GHEX136;}

            const std::set<el_processor> ghex136::processors(
               ghex136_procs, ghex136_procs+ghex136_procs_len);

            ghex136::ghex136(void) : elem() {}

            ghex136::ghex136(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex136::ghex136(const cards::gelmnt1 *data) : elem(data) {}

            ghex136::ghex136(const cards::gelref1 *data) : elem(data) {}

            ghex136::ghex136(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex137.

   
*/

            namespace {
               const size_t ghex137_procs_len = 2;
               el_processor ghex137_procs[ghex137_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex137::nnodes(void) const {return 24;}

            el_types ghex137::get_type(void) const {return el_types::GHEX137;}

            const std::set<el_processor> ghex137::processors(
               ghex137_procs, ghex137_procs+ghex137_procs_len);

            ghex137::ghex137(void) : elem() {}

            ghex137::ghex137(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex137::ghex137(const cards::gelmnt1 *data) : elem(data) {}

            ghex137::ghex137(const cards::gelref1 *data) : elem(data) {}

            ghex137::ghex137(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex138.

   
*/

            namespace {
               const size_t ghex138_procs_len = 2;
               el_processor ghex138_procs[ghex138_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex138::nnodes(void) const {return 24;}

            el_types ghex138::get_type(void) const {return el_types::GHEX138;}

            const std::set<el_processor> ghex138::processors(
               ghex138_procs, ghex138_procs+ghex138_procs_len);

            ghex138::ghex138(void) : elem() {}

            ghex138::ghex138(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex138::ghex138(const cards::gelmnt1 *data) : elem(data) {}

            ghex138::ghex138(const cards::gelref1 *data) : elem(data) {}

            ghex138::ghex138(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex139.

   
*/

            namespace {
               const size_t ghex139_procs_len = 2;
               el_processor ghex139_procs[ghex139_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex139::nnodes(void) const {return 25;}

            el_types ghex139::get_type(void) const {return el_types::GHEX139;}

            const std::set<el_processor> ghex139::processors(
               ghex139_procs, ghex139_procs+ghex139_procs_len);

            ghex139::ghex139(void) : elem() {}

            ghex139::ghex139(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex139::ghex139(const cards::gelmnt1 *data) : elem(data) {}

            ghex139::ghex139(const cards::gelref1 *data) : elem(data) {}

            ghex139::ghex139(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex140.

   
*/

            namespace {
               const size_t ghex140_procs_len = 2;
               el_processor ghex140_procs[ghex140_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex140::nnodes(void) const {return 23;}

            el_types ghex140::get_type(void) const {return el_types::GHEX140;}

            const std::set<el_processor> ghex140::processors(
               ghex140_procs, ghex140_procs+ghex140_procs_len);

            ghex140::ghex140(void) : elem() {}

            ghex140::ghex140(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex140::ghex140(const cards::gelmnt1 *data) : elem(data) {}

            ghex140::ghex140(const cards::gelref1 *data) : elem(data) {}

            ghex140::ghex140(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex141.

   
*/

            namespace {
               const size_t ghex141_procs_len = 2;
               el_processor ghex141_procs[ghex141_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex141::nnodes(void) const {return 24;}

            el_types ghex141::get_type(void) const {return el_types::GHEX141;}

            const std::set<el_processor> ghex141::processors(
               ghex141_procs, ghex141_procs+ghex141_procs_len);

            ghex141::ghex141(void) : elem() {}

            ghex141::ghex141(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex141::ghex141(const cards::gelmnt1 *data) : elem(data) {}

            ghex141::ghex141(const cards::gelref1 *data) : elem(data) {}

            ghex141::ghex141(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex142.

   
*/

            namespace {
               const size_t ghex142_procs_len = 2;
               el_processor ghex142_procs[ghex142_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex142::nnodes(void) const {return 24;}

            el_types ghex142::get_type(void) const {return el_types::GHEX142;}

            const std::set<el_processor> ghex142::processors(
               ghex142_procs, ghex142_procs+ghex142_procs_len);

            ghex142::ghex142(void) : elem() {}

            ghex142::ghex142(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex142::ghex142(const cards::gelmnt1 *data) : elem(data) {}

            ghex142::ghex142(const cards::gelref1 *data) : elem(data) {}

            ghex142::ghex142(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex143.

   
*/

            namespace {
               const size_t ghex143_procs_len = 2;
               el_processor ghex143_procs[ghex143_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex143::nnodes(void) const {return 25;}

            el_types ghex143::get_type(void) const {return el_types::GHEX143;}

            const std::set<el_processor> ghex143::processors(
               ghex143_procs, ghex143_procs+ghex143_procs_len);

            ghex143::ghex143(void) : elem() {}

            ghex143::ghex143(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex143::ghex143(const cards::gelmnt1 *data) : elem(data) {}

            ghex143::ghex143(const cards::gelref1 *data) : elem(data) {}

            ghex143::ghex143(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex144.

   
*/

            namespace {
               const size_t ghex144_procs_len = 2;
               el_processor ghex144_procs[ghex144_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex144::nnodes(void) const {return 24;}

            el_types ghex144::get_type(void) const {return el_types::GHEX144;}

            const std::set<el_processor> ghex144::processors(
               ghex144_procs, ghex144_procs+ghex144_procs_len);

            ghex144::ghex144(void) : elem() {}

            ghex144::ghex144(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex144::ghex144(const cards::gelmnt1 *data) : elem(data) {}

            ghex144::ghex144(const cards::gelref1 *data) : elem(data) {}

            ghex144::ghex144(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex145.

   
*/

            namespace {
               const size_t ghex145_procs_len = 2;
               el_processor ghex145_procs[ghex145_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex145::nnodes(void) const {return 25;}

            el_types ghex145::get_type(void) const {return el_types::GHEX145;}

            const std::set<el_processor> ghex145::processors(
               ghex145_procs, ghex145_procs+ghex145_procs_len);

            ghex145::ghex145(void) : elem() {}

            ghex145::ghex145(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex145::ghex145(const cards::gelmnt1 *data) : elem(data) {}

            ghex145::ghex145(const cards::gelref1 *data) : elem(data) {}

            ghex145::ghex145(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex146.

   
*/

            namespace {
               const size_t ghex146_procs_len = 2;
               el_processor ghex146_procs[ghex146_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex146::nnodes(void) const {return 25;}

            el_types ghex146::get_type(void) const {return el_types::GHEX146;}

            const std::set<el_processor> ghex146::processors(
               ghex146_procs, ghex146_procs+ghex146_procs_len);

            ghex146::ghex146(void) : elem() {}

            ghex146::ghex146(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex146::ghex146(const cards::gelmnt1 *data) : elem(data) {}

            ghex146::ghex146(const cards::gelref1 *data) : elem(data) {}

            ghex146::ghex146(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex147.

   
*/

            namespace {
               const size_t ghex147_procs_len = 2;
               el_processor ghex147_procs[ghex147_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex147::nnodes(void) const {return 26;}

            el_types ghex147::get_type(void) const {return el_types::GHEX147;}

            const std::set<el_processor> ghex147::processors(
               ghex147_procs, ghex147_procs+ghex147_procs_len);

            ghex147::ghex147(void) : elem() {}

            ghex147::ghex147(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex147::ghex147(const cards::gelmnt1 *data) : elem(data) {}

            ghex147::ghex147(const cards::gelref1 *data) : elem(data) {}

            ghex147::ghex147(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex148.

   
*/

            namespace {
               const size_t ghex148_procs_len = 2;
               el_processor ghex148_procs[ghex148_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex148::nnodes(void) const {return 23;}

            el_types ghex148::get_type(void) const {return el_types::GHEX148;}

            const std::set<el_processor> ghex148::processors(
               ghex148_procs, ghex148_procs+ghex148_procs_len);

            ghex148::ghex148(void) : elem() {}

            ghex148::ghex148(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex148::ghex148(const cards::gelmnt1 *data) : elem(data) {}

            ghex148::ghex148(const cards::gelref1 *data) : elem(data) {}

            ghex148::ghex148(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex149.

   
*/

            namespace {
               const size_t ghex149_procs_len = 2;
               el_processor ghex149_procs[ghex149_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex149::nnodes(void) const {return 24;}

            el_types ghex149::get_type(void) const {return el_types::GHEX149;}

            const std::set<el_processor> ghex149::processors(
               ghex149_procs, ghex149_procs+ghex149_procs_len);

            ghex149::ghex149(void) : elem() {}

            ghex149::ghex149(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex149::ghex149(const cards::gelmnt1 *data) : elem(data) {}

            ghex149::ghex149(const cards::gelref1 *data) : elem(data) {}

            ghex149::ghex149(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex150.

   
*/

            namespace {
               const size_t ghex150_procs_len = 2;
               el_processor ghex150_procs[ghex150_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex150::nnodes(void) const {return 24;}

            el_types ghex150::get_type(void) const {return el_types::GHEX150;}

            const std::set<el_processor> ghex150::processors(
               ghex150_procs, ghex150_procs+ghex150_procs_len);

            ghex150::ghex150(void) : elem() {}

            ghex150::ghex150(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex150::ghex150(const cards::gelmnt1 *data) : elem(data) {}

            ghex150::ghex150(const cards::gelref1 *data) : elem(data) {}

            ghex150::ghex150(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex151.

   
*/

            namespace {
               const size_t ghex151_procs_len = 2;
               el_processor ghex151_procs[ghex151_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex151::nnodes(void) const {return 25;}

            el_types ghex151::get_type(void) const {return el_types::GHEX151;}

            const std::set<el_processor> ghex151::processors(
               ghex151_procs, ghex151_procs+ghex151_procs_len);

            ghex151::ghex151(void) : elem() {}

            ghex151::ghex151(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex151::ghex151(const cards::gelmnt1 *data) : elem(data) {}

            ghex151::ghex151(const cards::gelref1 *data) : elem(data) {}

            ghex151::ghex151(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex152.

   
*/

            namespace {
               const size_t ghex152_procs_len = 2;
               el_processor ghex152_procs[ghex152_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex152::nnodes(void) const {return 24;}

            el_types ghex152::get_type(void) const {return el_types::GHEX152;}

            const std::set<el_processor> ghex152::processors(
               ghex152_procs, ghex152_procs+ghex152_procs_len);

            ghex152::ghex152(void) : elem() {}

            ghex152::ghex152(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex152::ghex152(const cards::gelmnt1 *data) : elem(data) {}

            ghex152::ghex152(const cards::gelref1 *data) : elem(data) {}

            ghex152::ghex152(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex153.

   
*/

            namespace {
               const size_t ghex153_procs_len = 2;
               el_processor ghex153_procs[ghex153_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex153::nnodes(void) const {return 25;}

            el_types ghex153::get_type(void) const {return el_types::GHEX153;}

            const std::set<el_processor> ghex153::processors(
               ghex153_procs, ghex153_procs+ghex153_procs_len);

            ghex153::ghex153(void) : elem() {}

            ghex153::ghex153(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex153::ghex153(const cards::gelmnt1 *data) : elem(data) {}

            ghex153::ghex153(const cards::gelref1 *data) : elem(data) {}

            ghex153::ghex153(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex154.

   
*/

            namespace {
               const size_t ghex154_procs_len = 2;
               el_processor ghex154_procs[ghex154_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex154::nnodes(void) const {return 25;}

            el_types ghex154::get_type(void) const {return el_types::GHEX154;}

            const std::set<el_processor> ghex154::processors(
               ghex154_procs, ghex154_procs+ghex154_procs_len);

            ghex154::ghex154(void) : elem() {}

            ghex154::ghex154(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex154::ghex154(const cards::gelmnt1 *data) : elem(data) {}

            ghex154::ghex154(const cards::gelref1 *data) : elem(data) {}

            ghex154::ghex154(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex155.

   
*/

            namespace {
               const size_t ghex155_procs_len = 2;
               el_processor ghex155_procs[ghex155_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex155::nnodes(void) const {return 26;}

            el_types ghex155::get_type(void) const {return el_types::GHEX155;}

            const std::set<el_processor> ghex155::processors(
               ghex155_procs, ghex155_procs+ghex155_procs_len);

            ghex155::ghex155(void) : elem() {}

            ghex155::ghex155(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex155::ghex155(const cards::gelmnt1 *data) : elem(data) {}

            ghex155::ghex155(const cards::gelref1 *data) : elem(data) {}

            ghex155::ghex155(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex156.

   
*/

            namespace {
               const size_t ghex156_procs_len = 2;
               el_processor ghex156_procs[ghex156_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex156::nnodes(void) const {return 24;}

            el_types ghex156::get_type(void) const {return el_types::GHEX156;}

            const std::set<el_processor> ghex156::processors(
               ghex156_procs, ghex156_procs+ghex156_procs_len);

            ghex156::ghex156(void) : elem() {}

            ghex156::ghex156(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex156::ghex156(const cards::gelmnt1 *data) : elem(data) {}

            ghex156::ghex156(const cards::gelref1 *data) : elem(data) {}

            ghex156::ghex156(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex157.

   
*/

            namespace {
               const size_t ghex157_procs_len = 2;
               el_processor ghex157_procs[ghex157_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex157::nnodes(void) const {return 25;}

            el_types ghex157::get_type(void) const {return el_types::GHEX157;}

            const std::set<el_processor> ghex157::processors(
               ghex157_procs, ghex157_procs+ghex157_procs_len);

            ghex157::ghex157(void) : elem() {}

            ghex157::ghex157(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex157::ghex157(const cards::gelmnt1 *data) : elem(data) {}

            ghex157::ghex157(const cards::gelref1 *data) : elem(data) {}

            ghex157::ghex157(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex158.

   
*/

            namespace {
               const size_t ghex158_procs_len = 2;
               el_processor ghex158_procs[ghex158_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex158::nnodes(void) const {return 25;}

            el_types ghex158::get_type(void) const {return el_types::GHEX158;}

            const std::set<el_processor> ghex158::processors(
               ghex158_procs, ghex158_procs+ghex158_procs_len);

            ghex158::ghex158(void) : elem() {}

            ghex158::ghex158(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex158::ghex158(const cards::gelmnt1 *data) : elem(data) {}

            ghex158::ghex158(const cards::gelref1 *data) : elem(data) {}

            ghex158::ghex158(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex159.

   
*/

            namespace {
               const size_t ghex159_procs_len = 2;
               el_processor ghex159_procs[ghex159_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex159::nnodes(void) const {return 26;}

            el_types ghex159::get_type(void) const {return el_types::GHEX159;}

            const std::set<el_processor> ghex159::processors(
               ghex159_procs, ghex159_procs+ghex159_procs_len);

            ghex159::ghex159(void) : elem() {}

            ghex159::ghex159(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex159::ghex159(const cards::gelmnt1 *data) : elem(data) {}

            ghex159::ghex159(const cards::gelref1 *data) : elem(data) {}

            ghex159::ghex159(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex160.

   
*/

            namespace {
               const size_t ghex160_procs_len = 2;
               el_processor ghex160_procs[ghex160_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex160::nnodes(void) const {return 25;}

            el_types ghex160::get_type(void) const {return el_types::GHEX160;}

            const std::set<el_processor> ghex160::processors(
               ghex160_procs, ghex160_procs+ghex160_procs_len);

            ghex160::ghex160(void) : elem() {}

            ghex160::ghex160(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex160::ghex160(const cards::gelmnt1 *data) : elem(data) {}

            ghex160::ghex160(const cards::gelref1 *data) : elem(data) {}

            ghex160::ghex160(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex161.

   
*/

            namespace {
               const size_t ghex161_procs_len = 2;
               el_processor ghex161_procs[ghex161_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex161::nnodes(void) const {return 26;}

            el_types ghex161::get_type(void) const {return el_types::GHEX161;}

            const std::set<el_processor> ghex161::processors(
               ghex161_procs, ghex161_procs+ghex161_procs_len);

            ghex161::ghex161(void) : elem() {}

            ghex161::ghex161(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex161::ghex161(const cards::gelmnt1 *data) : elem(data) {}

            ghex161::ghex161(const cards::gelref1 *data) : elem(data) {}

            ghex161::ghex161(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex162.

   
*/

            namespace {
               const size_t ghex162_procs_len = 2;
               el_processor ghex162_procs[ghex162_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex162::nnodes(void) const {return 26;}

            el_types ghex162::get_type(void) const {return el_types::GHEX162;}

            const std::set<el_processor> ghex162::processors(
               ghex162_procs, ghex162_procs+ghex162_procs_len);

            ghex162::ghex162(void) : elem() {}

            ghex162::ghex162(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex162::ghex162(const cards::gelmnt1 *data) : elem(data) {}

            ghex162::ghex162(const cards::gelref1 *data) : elem(data) {}

            ghex162::ghex162(const __base::elem *data) : __base::elem(data) {}/**
   \brief FEM element definition for ghex163.

   
*/

            namespace {
               const size_t ghex163_procs_len = 2;
               el_processor ghex163_procs[ghex163_procs_len] = { el_processor::general, el_processor::Sestra };
            }

            long ghex163::nnodes(void) const {return 27;}

            el_types ghex163::get_type(void) const {return el_types::GHEX163;}

            const std::set<el_processor> ghex163::processors(
               ghex163_procs, ghex163_procs+ghex163_procs_len);

            ghex163::ghex163(void) : elem() {}

            ghex163::ghex163(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex163::ghex163(const cards::gelmnt1 *data) : elem(data) {}

            ghex163::ghex163(const cards::gelref1 *data) : elem(data) {}

            ghex163::ghex163(const __base::elem *data) : __base::elem(data) {}
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