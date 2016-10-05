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
   \file fem/elements.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015, 2016 by DNV GL SE
   \brief Element card representation for Sesam FEM.

   Detailed description
*/

// ID: $Id$

#include "fem/cards.h"

#ifndef _FEM_ELEMENTS_H_
#define _FEM_ELEMENTS_H_

#include <my_c++14.h>

#include <set>

#line 35 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace elements {

            enum class el_types {
               BEPS = 2,
               CSTA = 3,
               RPBQ = 5,
               ILST = 6,
               IQQE = 8,
               LQUA = 9,
               TESS = 10,
               GMAS = 11,
               GLMA = 12,
               GLDA = 13,
               BEAS = 15,
               AXIS = 16,
               AXDA = 17,
               GSPR = 18,
               GDAM = 19,
               IHEX = 20,
               LHEX = 21,
               SECB = 22,
               BTSS = 23,
               FQUS_FFQ = 24,
               FTRS_FFTR = 25,
               SCTS = 26,
               MCTS = 27,
               SCQS = 28,
               MCQS = 29,
               IPRI = 30,
               ITET = 31,
               TPRI = 32,
               TETR = 33,
               LCTS = 34,
               LCQS = 35,
               TRS1 = 36,
               TRS2 = 37,
               TRS3 = 38,
               GLSH = 40,
               AXCS = 41,
               AXLQ = 42,
               AXLS = 43,
               AXQQ = 44,
               PILS = 45,
               PCAB = 46,
               PSPR = 47,
               ADVA_4 = 48,
               ADVA_2 = 49,
               CTCP = 51,
               CTCL = 52,
               CTAL = 53,
               CTCC = 54,
               CTAQ = 55,
               CTLQ = 56,
               CTCQ = 57,
               CTMQ = 58,
               HCQS = 61,
               SLQS = 66,
               SLTS = 67,
               SLCB = 68,
               MATR = 70,
               GHEX100 = 100,
               GHEX101 = 101,
               GHEX102 = 102,
               GHEX103 = 103,
               GHEX104 = 104,
               GHEX105 = 105,
               GHEX106 = 106,
               GHEX107 = 107,
               GHEX108 = 108,
               GHEX109 = 109,
               GHEX110 = 110,
               GHEX111 = 111,
               GHEX112 = 112,
               GHEX113 = 113,
               GHEX114 = 114,
               GHEX115 = 115,
               GHEX116 = 116,
               GHEX117 = 117,
               GHEX118 = 118,
               GHEX119 = 119,
               GHEX120 = 120,
               GHEX121 = 121,
               GHEX122 = 122,
               GHEX123 = 123,
               GHEX124 = 124,
               GHEX125 = 125,
               GHEX126 = 126,
               GHEX127 = 127,
               GHEX128 = 128,
               GHEX129 = 129,
               GHEX130 = 130,
               GHEX131 = 131,
               GHEX132 = 132,
               GHEX133 = 133,
               GHEX134 = 134,
               GHEX135 = 135,
               GHEX136 = 136,
               GHEX137 = 137,
               GHEX138 = 138,
               GHEX139 = 139,
               GHEX140 = 140,
               GHEX141 = 141,
               GHEX142 = 142,
               GHEX143 = 143,
               GHEX144 = 144,
               GHEX145 = 145,
               GHEX146 = 146,
               GHEX147 = 147,
               GHEX148 = 148,
               GHEX149 = 149,
               GHEX150 = 150,
               GHEX151 = 151,
               GHEX152 = 152,
               GHEX153 = 153,
               GHEX154 = 154,
               GHEX155 = 155,
               GHEX156 = 156,
               GHEX157 = 157,
               GHEX158 = 158,
               GHEX159 = 159,
               GHEX160 = 160,
               GHEX161 = 161,
               GHEX162 = 162,
               GHEX163 = 163,
               INVALID=-1, UNDEFINED=-2};
#line 45 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            enum class el_processor {
               general, Preframe, Prefem, Sestra, ADVANCE,
               Framework, Launch, Platework, Pretube,
               Splice, Wadam, Wajac,
               Poseidon};

            namespace __base {
            /** Base class for FEM element representation.
             */
               class elem {

               private:

                  static cards::gelmnt1 d_gelmnt1;
                  static cards::gelref1 d_gelref1;

               protected:
                  el_types static const type;
                  elem(void);
                  elem(long const elno,
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
                       std::vector<long> const csys);
                  __base::elem const &operator() (
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
                     std::vector<long> const csys);

               public:
                  elem(dnvgl::extfem::fem::cards::gelmnt1 const*);
                  elem(dnvgl::extfem::fem::cards::gelref1 const*);
                  elem(elem const*);

                  cards::__base::card const &gelmnt1(void) const;
                  cards::__base::card const &gelref1(void) const;


                  /** Element number ->
                      dnvgl::extfem::fem::cards::gelmnt1::ELNOX
                  */
                  long eleno;
                  /** internal element identifier ->
                      dnvgl::extfem::fem::cards::gelmnt1::ELNO, ->
                      dnvgl::extfem::fem::cards::gelref1::ELNO
                  */
                  long elident;
                  /** Additional element information ->
                      dnvgl::extfem::fem::cards::gelmnt1::ELTYAD
                  */
                  long el_add;
                  /** node references for element ->
                      dnvgl::extfem::fem::cards::gelmnt1::NODIN
                  */
                  std::vector<long> nodes;
                  /** Material reference ->
                      dnvgl::extfem::fem::cards::gelref1::MATNO
                  */
                  long matref;
                  /** additional data type number ->
                      dnvgl::extfem::fem::cards::gelref1::ADDNO
                  */
                  long add_no;
                  /** Integration station reference for stiffness
                      matrix-> dnvgl::extfem::fem::cards::gelref1::INTNO
                  */
                  long intno;
                  /** Integration station reference for mass and damping
                      matrices->
                      dnvgl::extfem::fem::cards::gelref1::INTNO
                  */
                  long mass_intno;
                  /** Reference to initial strain information (unused).
                      -> dnvgl::extfem::fem::cards::gelref1::STRANO
                  */
                  long i_strain_ref;
                  /** Reference to initial stress information (unused).
                      -> dnvgl::extfem::fem::cards::gelref1::STRENO
                  */
                  long i_stress_ref;
                  /** Reference to stresspoint definition ->
                      dnvgl::extfem::fem::cards::gelref1::STREPONO
                  */
                  long strpoint_ref;
                  /** Geometry information reference for element. ->
                      dnvgl::extfem::fem::cards::gelref1::GEONO_OPT /
                      dnvgl::extfem::fem::cards::gelref1::GEONO
                  */
                  std::vector<long> section;
                  /** Fixation information reference for element. ->
                      dnvgl::extfem::fem::cards::gelref1::FIXNO_OPT /
                      dnvgl::extfem::fem::cards::gelref1::FIXNO
                  */
                  std::vector<long> fixations;
                  /** Eccentricity information reference for element. ->
                      dnvgl::extfem::fem::cards::gelref1::ECCNO_OPT /
                      dnvgl::extfem::fem::cards::gelref1::ECCNO
                  */
                  std::vector<long> eccentrities;
                  /** Local coordinate system information reference for
                      element. ->
                      dnvgl::extfem::fem::cards::gelref1::TRANSNO_OPT /
                      dnvgl::extfem::fem::cards::gelref1::TRANSNO
                  */
                  std::vector<long> csys;

                  virtual void add(dnvgl::extfem::fem::cards::gelref1 const*);
                  virtual void add(dnvgl::extfem::fem::cards::gelmnt1 const*);

                  virtual long nnodes(void) const = 0;

                  virtual el_types get_type(void) const = 0;

                  friend std::ostream &operator<<(std::ostream&, elem const &);
               };

               /** Base thin shell element definitions
                */
               class fem_thin_shell : public __base::elem {
               public:
                  fem_thin_shell(void);
                  fem_thin_shell(
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
                     std::vector<long> const csys);
                  fem_thin_shell(dnvgl::extfem::fem::cards::gelmnt1 const*);
                  fem_thin_shell(dnvgl::extfem::fem::cards::gelref1 const*);
                  fem_thin_shell(__base::elem const*);
                  using elem::operator();
               };
            }

            class undef : public __base::elem {
            public:
               undef (void);
               undef(dnvgl::extfem::fem::cards::gelref1 const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
            };


#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2-D, 2 Node Beam
             */
            class beps : public __base::elem {
            public:
               beps(void);
               beps(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               beps(dnvgl::extfem::fem::cards::gelmnt1 const*);
               beps(dnvgl::extfem::fem::cards::gelref1 const*);
               beps( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Plane Constant Strain Triangle
             */
            class csta : public __base::elem {
            public:
               csta(void);
               csta(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               csta(dnvgl::extfem::fem::cards::gelmnt1 const*);
               csta(dnvgl::extfem::fem::cards::gelref1 const*);
               csta( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Rect. Plate. Bending Modes
             */
            class rpbq : public __base::elem {
            public:
               rpbq(void);
               rpbq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               rpbq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               rpbq(dnvgl::extfem::fem::cards::gelref1 const*);
               rpbq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Plane Lin. Strain Triangle
             */
            class ilst : public __base::elem {
            public:
               ilst(void);
               ilst(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ilst(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ilst(dnvgl::extfem::fem::cards::gelref1 const*);
               ilst( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Plane Quadrilateral Membrane Element
             */
            class iqqe : public __base::elem {
            public:
               iqqe(void);
               iqqe(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               iqqe(dnvgl::extfem::fem::cards::gelmnt1 const*);
               iqqe(dnvgl::extfem::fem::cards::gelref1 const*);
               iqqe( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Plane Quadrilateral Membrane Element
             */
            class lqua : public __base::elem {
            public:
               lqua(void);
               lqua(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               lqua(dnvgl::extfem::fem::cards::gelmnt1 const*);
               lqua(dnvgl::extfem::fem::cards::gelref1 const*);
               lqua( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Truss Element
             */
            class tess : public __base::elem {
            public:
               tess(void);
               tess(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               tess(dnvgl::extfem::fem::cards::gelmnt1 const*);
               tess(dnvgl::extfem::fem::cards::gelref1 const*);
               tess( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 1-Noded Mass-Matrix
             */
            class gmas : public __base::elem {
            public:
               gmas(void);
               gmas(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               gmas(dnvgl::extfem::fem::cards::gelmnt1 const*);
               gmas(dnvgl::extfem::fem::cards::gelref1 const*);
               gmas( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2-Noded Mass-Matrix
             */
            class glma : public __base::elem {
            public:
               glma(void);
               glma(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               glma(dnvgl::extfem::fem::cards::gelmnt1 const*);
               glma(dnvgl::extfem::fem::cards::gelref1 const*);
               glma( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2-Noded Damping-Matrix
             */
            class glda : public __base::elem {
            public:
               glda(void);
               glda(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               glda(dnvgl::extfem::fem::cards::gelmnt1 const*);
               glda(dnvgl::extfem::fem::cards::gelref1 const*);
               glda( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 3-D, 2 Node Beam
             */
            class beas : public __base::elem {
            public:
               beas(void);
               beas(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               beas(dnvgl::extfem::fem::cards::gelmnt1 const*);
               beas(dnvgl::extfem::fem::cards::gelref1 const*);
               beas( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Axial Spring
             */
            class axis : public __base::elem {
            public:
               axis(void);
               axis(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               axis(dnvgl::extfem::fem::cards::gelmnt1 const*);
               axis(dnvgl::extfem::fem::cards::gelref1 const*);
               axis( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Axial Damper
             */
            class axda : public __base::elem {
            public:
               axda(void);
               axda(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               axda(dnvgl::extfem::fem::cards::gelmnt1 const*);
               axda(dnvgl::extfem::fem::cards::gelref1 const*);
               axda( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Spring to Ground
             */
            class gspr : public __base::elem {
            public:
               gspr(void);
               gspr(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               gspr(dnvgl::extfem::fem::cards::gelmnt1 const*);
               gspr(dnvgl::extfem::fem::cards::gelref1 const*);
               gspr( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Damper to Ground
             */
            class gdam : public __base::elem {
            public:
               gdam(void);
               gdam(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               gdam(dnvgl::extfem::fem::cards::gelmnt1 const*);
               gdam(dnvgl::extfem::fem::cards::gelref1 const*);
               gdam( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Isoparametric Hexahedron
             */
            class ihex : public __base::elem {
            public:
               ihex(void);
               ihex(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ihex(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ihex(dnvgl::extfem::fem::cards::gelref1 const*);
               ihex( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Linear Hexahedron
             */
            class lhex : public __base::elem {
            public:
               lhex(void);
               lhex(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               lhex(dnvgl::extfem::fem::cards::gelmnt1 const*);
               lhex(dnvgl::extfem::fem::cards::gelref1 const*);
               lhex( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparametric Curved Beam
             */
            class secb : public __base::elem {
            public:
               secb(void);
               secb(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               secb(dnvgl::extfem::fem::cards::gelmnt1 const*);
               secb(dnvgl::extfem::fem::cards::gelref1 const*);
               secb( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Curved Beam
             */
            class btss : public __base::elem {
            public:
               btss(void);
               btss(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               btss(dnvgl::extfem::fem::cards::gelmnt1 const*);
               btss(dnvgl::extfem::fem::cards::gelref1 const*);
               btss( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Flat Quadrilateral Thin Shell / Free Formulation Quadrilateral Shell
             */
            class fqus_ffq : public __base::fem_thin_shell {
            public:
               fqus_ffq(void);
               fqus_ffq(long const elno,
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
                       std::vector<long> const csys);
               using fem_thin_shell::operator();
               fqus_ffq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               fqus_ffq(dnvgl::extfem::fem::cards::gelref1 const*);
               fqus_ffq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /**  Flat Triangular Thin Shell / Free Formulation Triangular Shell
             */
            class ftrs_fftr : public __base::fem_thin_shell {
            public:
               ftrs_fftr(void);
               ftrs_fftr(long const elno,
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
                       std::vector<long> const csys);
               using fem_thin_shell::operator();
               ftrs_fftr(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ftrs_fftr(dnvgl::extfem::fem::cards::gelref1 const*);
               ftrs_fftr( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparametric Curved Triangular Thick Shell
             */
            class scts : public __base::elem {
            public:
               scts(void);
               scts(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               scts(dnvgl::extfem::fem::cards::gelmnt1 const*);
               scts(dnvgl::extfem::fem::cards::gelref1 const*);
               scts( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparam. Curved Triang. Thick Sandwich Elem.
             */
            class mcts : public __base::elem {
            public:
               mcts(void);
               mcts(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               mcts(dnvgl::extfem::fem::cards::gelmnt1 const*);
               mcts(dnvgl::extfem::fem::cards::gelref1 const*);
               mcts( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparametric Curved Quadrilateral Thick Shell
             */
            class scqs : public __base::elem {
            public:
               scqs(void);
               scqs(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               scqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
               scqs(dnvgl::extfem::fem::cards::gelref1 const*);
               scqs( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparam. Curved Quadr. Thick Sandwich Elem.
             */
            class mcqs : public __base::elem {
            public:
               mcqs(void);
               mcqs(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               mcqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
               mcqs(dnvgl::extfem::fem::cards::gelref1 const*);
               mcqs( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Isoparametric Triangular Prism
             */
            class ipri : public __base::elem {
            public:
               ipri(void);
               ipri(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ipri(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ipri(dnvgl::extfem::fem::cards::gelref1 const*);
               ipri( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Isoparametric Tetrahedron
             */
            class itet : public __base::elem {
            public:
               itet(void);
               itet(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               itet(dnvgl::extfem::fem::cards::gelmnt1 const*);
               itet(dnvgl::extfem::fem::cards::gelref1 const*);
               itet( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Triangular Prism
             */
            class tpri : public __base::elem {
            public:
               tpri(void);
               tpri(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               tpri(dnvgl::extfem::fem::cards::gelmnt1 const*);
               tpri(dnvgl::extfem::fem::cards::gelref1 const*);
               tpri( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Tetrahedron
             */
            class tetr : public __base::elem {
            public:
               tetr(void);
               tetr(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               tetr(dnvgl::extfem::fem::cards::gelmnt1 const*);
               tetr(dnvgl::extfem::fem::cards::gelref1 const*);
               tetr( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparam. Layered Curved Triangular Thick Shell
             */
            class lcts : public __base::elem {
            public:
               lcts(void);
               lcts(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               lcts(dnvgl::extfem::fem::cards::gelmnt1 const*);
               lcts(dnvgl::extfem::fem::cards::gelref1 const*);
               lcts( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Subparam. Layered Curved Quadrilat. Thick Shell
             */
            class lcqs : public __base::elem {
            public:
               lcqs(void);
               lcqs(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               lcqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
               lcqs(dnvgl::extfem::fem::cards::gelref1 const*);
               lcqs( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2nd Order Hexahed. Transition Elem., Solid / Shell
             */
            class trs1 : public __base::elem {
            public:
               trs1(void);
               trs1(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               trs1(dnvgl::extfem::fem::cards::gelmnt1 const*);
               trs1(dnvgl::extfem::fem::cards::gelref1 const*);
               trs1( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2nd Order Hexahed. Transition Elem., Solid / Shell
             */
            class trs2 : public __base::elem {
            public:
               trs2(void);
               trs2(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               trs2(dnvgl::extfem::fem::cards::gelmnt1 const*);
               trs2(dnvgl::extfem::fem::cards::gelref1 const*);
               trs2( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2nd Order Hexahed. Transition Elem., Solid / Shell
             */
            class trs3 : public __base::elem {
            public:
               trs3(void);
               trs3(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               trs3(dnvgl::extfem::fem::cards::gelmnt1 const*);
               trs3(dnvgl::extfem::fem::cards::gelref1 const*);
               trs3( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Spring / Shim Element
             */
            class glsh : public __base::elem {
            public:
               glsh(void);
               glsh(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               glsh(dnvgl::extfem::fem::cards::gelmnt1 const*);
               glsh(dnvgl::extfem::fem::cards::gelref1 const*);
               glsh( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Axisymmetric Constant Strain Triangle
             */
            class axcs : public __base::elem {
            public:
               axcs(void);
               axcs(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               axcs(dnvgl::extfem::fem::cards::gelmnt1 const*);
               axcs(dnvgl::extfem::fem::cards::gelref1 const*);
               axcs( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Axisymmetric Quadrilateral
             */
            class axlq : public __base::elem {
            public:
               axlq(void);
               axlq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               axlq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               axlq(dnvgl::extfem::fem::cards::gelref1 const*);
               axlq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Axisymmetric Linear Strain Triangle
             */
            class axls : public __base::elem {
            public:
               axls(void);
               axls(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               axls(dnvgl::extfem::fem::cards::gelmnt1 const*);
               axls(dnvgl::extfem::fem::cards::gelref1 const*);
               axls( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Axisymmetric Linear Strain Quadrilateral
             */
            class axqq : public __base::elem {
            public:
               axqq(void);
               axqq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               axqq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               axqq(dnvgl::extfem::fem::cards::gelref1 const*);
               axqq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Pile / Soil
             */
            class pils : public __base::elem {
            public:
               pils(void);
               pils(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               pils(dnvgl::extfem::fem::cards::gelmnt1 const*);
               pils(dnvgl::extfem::fem::cards::gelref1 const*);
               pils( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Plane Cable-Bar Element
             */
            class pcab : public __base::elem {
            public:
               pcab(void);
               pcab(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               pcab(dnvgl::extfem::fem::cards::gelmnt1 const*);
               pcab(dnvgl::extfem::fem::cards::gelref1 const*);
               pcab( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Plane Spring Element
             */
            class pspr : public __base::elem {
            public:
               pspr(void);
               pspr(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               pspr(dnvgl::extfem::fem::cards::gelmnt1 const*);
               pspr(dnvgl::extfem::fem::cards::gelref1 const*);
               pspr( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 4-node Contact Element with triangular Shape
             */
            class adva_4 : public __base::elem {
            public:
               adva_4(void);
               adva_4(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               adva_4(dnvgl::extfem::fem::cards::gelmnt1 const*);
               adva_4(dnvgl::extfem::fem::cards::gelref1 const*);
               adva_4( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2-Noded Link Element
             */
            class adva_2 : public __base::elem {
            public:
               adva_2(void);
               adva_2(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               adva_2(dnvgl::extfem::fem::cards::gelmnt1 const*);
               adva_2(dnvgl::extfem::fem::cards::gelref1 const*);
               adva_2( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 2-Noded Contact Element
             */
            class ctcp : public __base::elem {
            public:
               ctcp(void);
               ctcp(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctcp(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctcp(dnvgl::extfem::fem::cards::gelref1 const*);
               ctcp( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 4-Noded Contact Element
             */
            class ctcl : public __base::elem {
            public:
               ctcl(void);
               ctcl(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctcl(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctcl(dnvgl::extfem::fem::cards::gelref1 const*);
               ctcl( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 4-Noded Axisymmetric Contact Element
             */
            class ctal : public __base::elem {
            public:
               ctal(void);
               ctal(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctal(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctal(dnvgl::extfem::fem::cards::gelref1 const*);
               ctal( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 6-Noded Contact Element
             */
            class ctcc : public __base::elem {
            public:
               ctcc(void);
               ctcc(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctcc(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctcc(dnvgl::extfem::fem::cards::gelref1 const*);
               ctcc( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 6-Noded (3+3) Axisymmetric Contact Element
             */
            class ctaq : public __base::elem {
            public:
               ctaq(void);
               ctaq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctaq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctaq(dnvgl::extfem::fem::cards::gelref1 const*);
               ctaq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 8-Noded (4+4) Contact Element
             */
            class ctlq : public __base::elem {
            public:
               ctlq(void);
               ctlq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctlq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctlq(dnvgl::extfem::fem::cards::gelref1 const*);
               ctlq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 16-Noded (8+8) Contact Element
             */
            class ctcq : public __base::elem {
            public:
               ctcq(void);
               ctcq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctcq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctcq(dnvgl::extfem::fem::cards::gelref1 const*);
               ctcq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 18-Noded (9+9) Contact Element
             */
            class ctmq : public __base::elem {
            public:
               ctmq(void);
               ctmq(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ctmq(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ctmq(dnvgl::extfem::fem::cards::gelref1 const*);
               ctmq( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** 9-Noded Shell Element
             */
            class hcqs : public __base::elem {
            public:
               hcqs(void);
               hcqs(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               hcqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
               hcqs(dnvgl::extfem::fem::cards::gelref1 const*);
               hcqs( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)
             */
            class slqs : public __base::elem {
            public:
               slqs(void);
               slqs(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               slqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
               slqs(dnvgl::extfem::fem::cards::gelref1 const*);
               slqs( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Semiloof Triangular Curved Thin Shell (24 d.o.fs)
             */
            class slts : public __base::elem {
            public:
               slts(void);
               slts(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               slts(dnvgl::extfem::fem::cards::gelmnt1 const*);
               slts(dnvgl::extfem::fem::cards::gelref1 const*);
               slts( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Semiloof Curved Beam (11 d.o.fs)
             */
            class slcb : public __base::elem {
            public:
               slcb(void);
               slcb(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               slcb(dnvgl::extfem::fem::cards::gelmnt1 const*);
               slcb(dnvgl::extfem::fem::cards::gelref1 const*);
               slcb( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Matrix Element with arbitrary no. of nodes (/n/)
             */
            class matr : public __base::elem {
            public:
               matr(void);
               matr(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               matr(dnvgl::extfem::fem::cards::gelmnt1 const*);
               matr(dnvgl::extfem::fem::cards::gelref1 const*);
               matr( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 27 at pos 21
             */
            class ghex100 : public __base::elem {
            public:
               ghex100(void);
               ghex100(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex100(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex100(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex100( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 27 at pos 22
             */
            class ghex101 : public __base::elem {
            public:
               ghex101(void);
               ghex101(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex101(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex101(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex101( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 27 at pos 22
             */
            class ghex102 : public __base::elem {
            public:
               ghex102(void);
               ghex102(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex102(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex102(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex102( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 27 at pos 23
             */
            class ghex103 : public __base::elem {
            public:
               ghex103(void);
               ghex103(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex103(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex103(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex103( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 27 at pos 22
             */
            class ghex104 : public __base::elem {
            public:
               ghex104(void);
               ghex104(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex104(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex104(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex104( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
             */
            class ghex105 : public __base::elem {
            public:
               ghex105(void);
               ghex105(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex105(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex105(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex105( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
             */
            class ghex106 : public __base::elem {
            public:
               ghex106(void);
               ghex106(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex106(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex106(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex106( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 27 at pos 24
             */
            class ghex107 : public __base::elem {
            public:
               ghex107(void);
               ghex107(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex107(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex107(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex107( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 27 at pos 22
             */
            class ghex108 : public __base::elem {
            public:
               ghex108(void);
               ghex108(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex108(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex108(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex108( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex109 : public __base::elem {
            public:
               ghex109(void);
               ghex109(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex109(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex109(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex109( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex110 : public __base::elem {
            public:
               ghex110(void);
               ghex110(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex110(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex110(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex110( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
             */
            class ghex111 : public __base::elem {
            public:
               ghex111(void);
               ghex111(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex111(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex111(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex111( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex112 : public __base::elem {
            public:
               ghex112(void);
               ghex112(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex112(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex112(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex112( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
             */
            class ghex113 : public __base::elem {
            public:
               ghex113(void);
               ghex113(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex113(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex113(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex113( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
             */
            class ghex114 : public __base::elem {
            public:
               ghex114(void);
               ghex114(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex114(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex114(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex114( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 27 at pos 25
             */
            class ghex115 : public __base::elem {
            public:
               ghex115(void);
               ghex115(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex115(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex115(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex115( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 27 at pos 22
             */
            class ghex116 : public __base::elem {
            public:
               ghex116(void);
               ghex116(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex116(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex116(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex116( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex117 : public __base::elem {
            public:
               ghex117(void);
               ghex117(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex117(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex117(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex117( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex118 : public __base::elem {
            public:
               ghex118(void);
               ghex118(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex118(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex118(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex118( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex119 : public __base::elem {
            public:
               ghex119(void);
               ghex119(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex119(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex119(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex119( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex120 : public __base::elem {
            public:
               ghex120(void);
               ghex120(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex120(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex120(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex120( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex121 : public __base::elem {
            public:
               ghex121(void);
               ghex121(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex121(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex121(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex121( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex122 : public __base::elem {
            public:
               ghex122(void);
               ghex122(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex122(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex122(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex122( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex123 : public __base::elem {
            public:
               ghex123(void);
               ghex123(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex123(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex123(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex123( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex124 : public __base::elem {
            public:
               ghex124(void);
               ghex124(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex124(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex124(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex124( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex125 : public __base::elem {
            public:
               ghex125(void);
               ghex125(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex125(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex125(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex125( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex126 : public __base::elem {
            public:
               ghex126(void);
               ghex126(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex126(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex126(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex126( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex127 : public __base::elem {
            public:
               ghex127(void);
               ghex127(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex127(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex127(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex127( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex128 : public __base::elem {
            public:
               ghex128(void);
               ghex128(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex128(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex128(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex128( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex129 : public __base::elem {
            public:
               ghex129(void);
               ghex129(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex129(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex129(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex129( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex130 : public __base::elem {
            public:
               ghex130(void);
               ghex130(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex130(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex130(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex130( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 25 at pos 25
                    - node 27 at pos 26
             */
            class ghex131 : public __base::elem {
            public:
               ghex131(void);
               ghex131(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex131(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex131(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex131( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 26 at pos 21
                    - node 27 at pos 22
             */
            class ghex132 : public __base::elem {
            public:
               ghex132(void);
               ghex132(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex132(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex132(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex132( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex133 : public __base::elem {
            public:
               ghex133(void);
               ghex133(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex133(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex133(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex133( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex134 : public __base::elem {
            public:
               ghex134(void);
               ghex134(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex134(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex134(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex134( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex135 : public __base::elem {
            public:
               ghex135(void);
               ghex135(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex135(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex135(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex135( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex136 : public __base::elem {
            public:
               ghex136(void);
               ghex136(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex136(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex136(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex136( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex137 : public __base::elem {
            public:
               ghex137(void);
               ghex137(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex137(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex137(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex137( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex138 : public __base::elem {
            public:
               ghex138(void);
               ghex138(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex138(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex138(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex138( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex139 : public __base::elem {
            public:
               ghex139(void);
               ghex139(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex139(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex139(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex139( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex140 : public __base::elem {
            public:
               ghex140(void);
               ghex140(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex140(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex140(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex140( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex141 : public __base::elem {
            public:
               ghex141(void);
               ghex141(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex141(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex141(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex141( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex142 : public __base::elem {
            public:
               ghex142(void);
               ghex142(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex142(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex142(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex142( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex143 : public __base::elem {
            public:
               ghex143(void);
               ghex143(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex143(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex143(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex143( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex144 : public __base::elem {
            public:
               ghex144(void);
               ghex144(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex144(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex144(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex144( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex145 : public __base::elem {
            public:
               ghex145(void);
               ghex145(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex145(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex145(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex145( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex146 : public __base::elem {
            public:
               ghex146(void);
               ghex146(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex146(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex146(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex146( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex147 : public __base::elem {
            public:
               ghex147(void);
               ghex147(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex147(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex147(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex147( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex148 : public __base::elem {
            public:
               ghex148(void);
               ghex148(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex148(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex148(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex148( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex149 : public __base::elem {
            public:
               ghex149(void);
               ghex149(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex149(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex149(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex149( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex150 : public __base::elem {
            public:
               ghex150(void);
               ghex150(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex150(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex150(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex150( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex151 : public __base::elem {
            public:
               ghex151(void);
               ghex151(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex151(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex151(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex151( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex152 : public __base::elem {
            public:
               ghex152(void);
               ghex152(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex152(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex152(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex152( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex153 : public __base::elem {
            public:
               ghex153(void);
               ghex153(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex153(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex153(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex153( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex154 : public __base::elem {
            public:
               ghex154(void);
               ghex154(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex154(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex154(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex154( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex155 : public __base::elem {
            public:
               ghex155(void);
               ghex155(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex155(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex155(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex155( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex156 : public __base::elem {
            public:
               ghex156(void);
               ghex156(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex156(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex156(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex156( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex157 : public __base::elem {
            public:
               ghex157(void);
               ghex157(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex157(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex157(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex157( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex158 : public __base::elem {
            public:
               ghex158(void);
               ghex158(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex158(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex158(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex158( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex159 : public __base::elem {
            public:
               ghex159(void);
               ghex159(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex159(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex159(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex159( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex160 : public __base::elem {
            public:
               ghex160(void);
               ghex160(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex160(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex160(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex160( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex161 : public __base::elem {
            public:
               ghex161(void);
               ghex161(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex161(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex161(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex161( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex162 : public __base::elem {
            public:
               ghex162(void);
               ghex162(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex162(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex162(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex162( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 221 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 25 at pos 25
                    - node 26 at pos 26
                    - node 27 at pos 27
             */
            class ghex163 : public __base::elem {
            public:
               ghex163(void);
               ghex163(long const elno,
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
                       std::vector<long> const csys);
               using elem::operator();
               ghex163(dnvgl::extfem::fem::cards::gelmnt1 const*);
               ghex163(dnvgl::extfem::fem::cards::gelref1 const*);
               ghex163( __base::elem const*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               std::set<el_processor> static const processors;
            };

#line 251 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
            /** Dispatch element class instance for `id`
             */
            void dispatch(std::unique_ptr<__base::elem>&,
               cards::gelmnt1 const *data);

            /** Match element type id to element type name.
             */
            std::string name_elem(dnvgl::extfem::fem::elements::el_types const &);
         }
      }
   }
}

#endif // _FEM_ELEMENTS_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End: