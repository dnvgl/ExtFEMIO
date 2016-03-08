/**
   \file fem/elements.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Element card representation for Sesam FEM.

   Detailed description
*/

// ID: $Id$

#include "fem/cards.h"

#ifndef _FEM_ELEMENTS_H_
#define _FEM_ELEMENTS_H_

#include <my_c++14.h>

#include <set>

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace elements {

            typedef enum {BEPS = 2, CSTA = 3, RPBQ = 5, ILST = 6,
                          IQQE = 8, LQUA = 9, TESS = 10, GMAS = 11,
                          GLMA = 12, GLDA = 13, BEAS = 15, AXIS = 16,
                          AXDA = 17, GSPR = 18, GDAM = 19, IHEX = 20,
                          LHEX = 21, SECB = 22, BTSS = 23,
                          FQUS_FFQ = 24, FTRS_FFTR = 25, SCTS = 26,
                          MCTS = 27, SCQS = 28, MCQS = 29, IPRI = 30,
                          ITET = 31, TPRI = 32, TETR = 33, LCTS = 34,
                          LCQS = 35, TRS1 = 36, TRS2 = 37, TRS3 = 38,
                          GLSH = 40, AXCS = 41, AXLQ = 42, AXLS = 43,
                          AXQQ = 44, PILS = 45, PCAB = 46, PSPR = 47,
                          ADVA_4 = 48, ADVA_2 = 49, CTCP = 51,
                          CTCL = 52, CTAL = 53, CTCC = 54, CTAQ = 55,
                          CTLQ = 56, CTCQ = 57, CTMQ = 58, HCQS = 61,
                          SLQS = 66, SLTS = 67, SLCB = 68, MATR = 70,
                          GHEX100 = 100, GHEX101 = 101, GHEX102 = 102,
                          GHEX103 = 103, GHEX104 = 104, GHEX105 = 105,
                          GHEX106 = 106, GHEX107 = 107, GHEX108 = 108,
                          GHEX109 = 109, GHEX110 = 110, GHEX111 = 111,
                          GHEX112 = 112, GHEX113 = 113, GHEX114 = 114,
                          GHEX115 = 115, GHEX116 = 116, GHEX117 = 117,
                          GHEX118 = 118, GHEX119 = 119, GHEX120 = 120,
                          GHEX121 = 121, GHEX122 = 122, GHEX123 = 123,
                          GHEX124 = 124, GHEX125 = 125, GHEX126 = 126,
                          GHEX127 = 127, GHEX128 = 128, GHEX129 = 129,
                          GHEX130 = 130, GHEX131 = 131, GHEX132 = 132,
                          GHEX133 = 133, GHEX134 = 134, GHEX135 = 135,
                          GHEX136 = 136, GHEX137 = 137, GHEX138 = 138,
                          GHEX139 = 139, GHEX140 = 140, GHEX141 = 141,
                          GHEX142 = 142, GHEX143 = 143, GHEX144 = 144,
                          GHEX145 = 145, GHEX146 = 146, GHEX147 = 147,
                          GHEX148 = 148, GHEX149 = 149, GHEX150 = 150,
                          GHEX151 = 151, GHEX152 = 152, GHEX153 = 153,
                          GHEX154 = 154, GHEX155 = 155, GHEX156 = 156,
                          GHEX157 = 157, GHEX158 = 158, GHEX159 = 159,
                          GHEX160 = 160, GHEX161 = 161, GHEX162 = 162,
                          GHEX163 = 163,
                          UNDEFINED=-1} el_types;

            typedef enum {general, Preframe, Prefem, Sestra, ADVANCE,
                          Framework, Launch, Platework, Pretube,
                          Splice, Wadam, Wajac,
                          Poseidon} el_processor;

            /** Base class for FEM element representation.
             */
            class __base {
            protected:
               static const el_types type;
               __base(void);
            public:
               __base(const dnvgl::extfem::fem::cards::gelmnt1*);
               __base(const dnvgl::extfem::fem::cards::gelref1*);
               __base(const __base*);

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
               std::deque<long> nodes;
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
               std::deque<long> section;
               /** Fixation information reference for element. ->
                   dnvgl::extfem::fem::cards::gelref1::FIXNO_OPT /
                   dnvgl::extfem::fem::cards::gelref1::FIXNO
               */
               std::deque<long> fixations;
               /** Eccentricity information reference for element. ->
                   dnvgl::extfem::fem::cards::gelref1::ECCNO_OPT /
                   dnvgl::extfem::fem::cards::gelref1::ECCNO
               */
               std::deque<long> eccentrities;
               /** Local coordinate system information reference for
                   element. ->
                   dnvgl::extfem::fem::cards::gelref1::TRANSNO_OPT /
                   dnvgl::extfem::fem::cards::gelref1::TRANSNO
               */
               std::deque<long> csys;

               virtual void add(dnvgl::extfem::fem::cards::gelref1 const*);
               virtual void add(dnvgl::extfem::fem::cards::gelmnt1 const*);
               virtual void add(const dnvgl::extfem::fem::cards::gelref1&);
               virtual void add(const dnvgl::extfem::fem::cards::gbeamg&);
               virtual void add(const dnvgl::extfem::fem::cards::misosel&);

               virtual el_types get_type(void) const = 0;
            };

            class undef : public __base {
            public:
               undef (void);
               static const long nnodes;
               el_types get_type(void) const;
            };

            /** 2-D, 2 Node Beam
             */
            class beps : public __base {
            public:
               beps(const dnvgl::extfem::fem::cards::gelmnt1*);
               beps(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Plane Constant Strain Triangle
             */
            class csta : public __base {
            public:
               csta(const dnvgl::extfem::fem::cards::gelmnt1*);
               csta(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Rect. Plate. Bending Modes
             */
            class rpbq : public __base {
            public:
               rpbq(const dnvgl::extfem::fem::cards::gelmnt1*);
               rpbq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Plane Lin. Strain Triangle
             */
            class ilst : public __base {
            public:
               ilst(const dnvgl::extfem::fem::cards::gelmnt1*);
               ilst(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Plane Quadrilateral Membrane Element
             */
            class iqqe : public __base {
            public:
               iqqe(const dnvgl::extfem::fem::cards::gelmnt1*);
               iqqe(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Plane Quadrilateral Membrane Element
             */
            class lqua : public __base {
            public:
               lqua(const dnvgl::extfem::fem::cards::gelmnt1*);
               lqua(const dnvgl::extfem::fem::cards::gelref1*);
               lqua(const __base*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Truss Element
             */
            class tess : public __base {
            public:
               tess(const dnvgl::extfem::fem::cards::gelmnt1*);
               tess(const dnvgl::extfem::fem::cards::gelref1*);
               tess(const __base*);
               //void add(const dnvgl::extfem::fem::cards::gelmnt1*);
               //void add(const dnvgl::extfem::fem::cards::gelref1*);
               //void add(const dnvgl::extfem::fem::cards::gelref1&);
               //void add(const dnvgl::extfem::fem::cards::gbeamg&);
               //void add(const dnvgl::extfem::fem::cards::misosel&);
               // void add(const dnvgl::extfem::fem::cards::beiste&);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 1-Noded Mass-Matrix
             */
            class gmas : public __base {
            public:
               gmas(const dnvgl::extfem::fem::cards::gelmnt1*);
               gmas(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2-Noded Mass-Matrix
             */
            class glma : public __base {
            public:
               glma(const dnvgl::extfem::fem::cards::gelmnt1*);
               glma(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2-Noded Damping-Matrix
             */
            class glda : public __base {
            public:
               glda(const dnvgl::extfem::fem::cards::gelmnt1*);
               glda(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 3-D, 2 Node Beam
             */
            class beas : public __base {
            public:
               beas(const dnvgl::extfem::fem::cards::gelmnt1*);
               beas(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Axial Spring
             */
            class axis : public __base {
            public:
               axis(const dnvgl::extfem::fem::cards::gelmnt1*);
               axis(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Axial Damper
             */
            class axda : public __base {
            public:
               axda(const dnvgl::extfem::fem::cards::gelmnt1*);
               axda(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Spring to Ground
             */
            class gspr : public __base {
            public:
               gspr(const dnvgl::extfem::fem::cards::gelmnt1*);
               gspr(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Damper to Ground
             */
            class gdam : public __base {
            public:
               gdam(const dnvgl::extfem::fem::cards::gelmnt1*);
               gdam(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Isoparametric Hexahedron
             */
            class ihex : public __base {
            public:
               ihex(const dnvgl::extfem::fem::cards::gelmnt1*);
               ihex(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Linear Hexahedron
             */
            class lhex : public __base {
            public:
               lhex(const dnvgl::extfem::fem::cards::gelmnt1*);
               lhex(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparametric Curved Beam
             */
            class secb : public __base {
            public:
               secb(const dnvgl::extfem::fem::cards::gelmnt1*);
               secb(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Curved Beam
             */
            class btss : public __base {
            public:
               btss(const dnvgl::extfem::fem::cards::gelmnt1*);
               btss(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Flat Quadrilateral Thin Shell (FQUS) or Free Formulation
                Quadrilateral Shell (FQQ)
            */
            class fqus_ffq : public __base {
            public:
               fqus_ffq(const dnvgl::extfem::fem::cards::gelmnt1*);
               fqus_ffq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Flat Triangular Thin Shell (FTRS) or Free Formulation
                Triangular Shell (FFTR)
            */
            class ftrs_fftr : public __base {
            public:
               ftrs_fftr(const dnvgl::extfem::fem::cards::gelmnt1*);
               ftrs_fftr(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparametric Curved Triangular Thick Shell
             */
            class scts : public __base {
            public:
               scts(const dnvgl::extfem::fem::cards::gelmnt1*);
               scts(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparam. Curved Triang. Thick Sandwich Elem.
             */
            class mcts : public __base {
            public:
               mcts(const dnvgl::extfem::fem::cards::gelmnt1*);
               mcts(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparametric Curved Quadrilateral Thick Shell
             */
            class scqs : public __base {
            public:
               scqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               scqs(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparam. Curved Quadr. Thick Sandwich Elem.
             */
            class mcqs : public __base {
            public:
               mcqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               mcqs(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Isoparametric Triangular Prism
             */
            class ipri : public __base {
            public:
               ipri(const dnvgl::extfem::fem::cards::gelmnt1*);
               ipri(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Isoparametric Tetrahedron
             */
            class itet : public __base {
            public:
               itet(const dnvgl::extfem::fem::cards::gelmnt1*);
               itet(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Triangular Prism
             */
            class tpri : public __base {
            public:
               tpri(const dnvgl::extfem::fem::cards::gelmnt1*);
               tpri(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Tetrahedron
             */
            class tetr : public __base {
            public:
               tetr(const dnvgl::extfem::fem::cards::gelmnt1*);
               tetr(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparam. Layered Curved Triangular Thick Shell
             */
            class lcts : public __base {
            public:
               lcts(const dnvgl::extfem::fem::cards::gelmnt1*);
               lcts(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Subparam. Layered Curved Quadrilat. Thick Shell
             */
            class lcqs : public __base {
            public:
               lcqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               lcqs(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2nd Order Hexahed. Transition Elem., Solid / Shell
             */
            class trs1 : public __base {
            public:
               trs1(const dnvgl::extfem::fem::cards::gelmnt1*);
               trs1(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2nd Order Hexahed. Transition Elem., Solid / Shell
             */
            class trs2 : public __base {
            public:
               trs2(const dnvgl::extfem::fem::cards::gelmnt1*);
               trs2(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2nd Order Hexahed. Transition Elem., Solid / Shell
             */
            class trs3 : public __base {
            public:
               trs3(const dnvgl::extfem::fem::cards::gelmnt1*);
               trs3(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Spring / Shim Element
             */
            class glsh : public __base {
            public:
               glsh(const dnvgl::extfem::fem::cards::gelmnt1*);
               glsh(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Axisymmetric Constant Strain Triangle
             */
            class axcs : public __base {
            public:
               axcs(const dnvgl::extfem::fem::cards::gelmnt1*);
               axcs(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Axisymmetric Quadrilateral
             */
            class axlq : public __base {
            public:
               axlq(const dnvgl::extfem::fem::cards::gelmnt1*);
               axlq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Axisymmetric Linear Strain Triangle
             */
            class axls : public __base {
            public:
               axls(const dnvgl::extfem::fem::cards::gelmnt1*);
               axls(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Axisymmetric Linear Strain Quadrilateral
             */
            class axqq : public __base {
            public:
               axqq(const dnvgl::extfem::fem::cards::gelmnt1*);
               axqq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Pile / Soil
             */
            class pils : public __base {
            public:
               pils(const dnvgl::extfem::fem::cards::gelmnt1*);
               pils(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Plane Cable-Bar Element
             */
            class pcab : public __base {
            public:
               pcab(const dnvgl::extfem::fem::cards::gelmnt1*);
               pcab(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Plane Spring Element
             */
            class pspr : public __base {
            public:
               pspr(const dnvgl::extfem::fem::cards::gelmnt1*);
               pspr(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 4-node Contact Element with triangular Shape for ADVANCE.
             */
            class adva_4 : public __base {
            public:
               adva_4(const dnvgl::extfem::fem::cards::gelmnt1*);
               adva_4(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2-Noded Link Element for ADVANCE.
             */
            class adva_2 : public __base {
            public:
               adva_2(const dnvgl::extfem::fem::cards::gelmnt1*);
               adva_2(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 2-Noded Contact Element
             */
            class ctcp : public __base {
            public:
               ctcp(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcp(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 4-Noded Contact Element
             */
            class ctcl : public __base {
            public:
               ctcl(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcl(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 4-Noded Axisymmetric Contact Element
             */
            class ctal : public __base {
            public:
               ctal(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctal(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 6-Noded Contact Element
             */
            class ctcc : public __base {
            public:
               ctcc(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcc(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 6-Noded (3+3) Axisymmetric Contact Element
             */
            class ctaq : public __base {
            public:
               ctaq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctaq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 8-Noded (4+4) Contact Element
             */
            class ctlq : public __base {
            public:
               ctlq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctlq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 16-Noded (8+8) Contact Element
             */
            class ctcq : public __base {
            public:
               ctcq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 18-Noded (9+9) Contact Element
             */
            class ctmq : public __base {
            public:
               ctmq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctmq(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** 9-Noded Shell Element
             */
            class hcqs : public __base {
            public:
               hcqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               hcqs(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)
             */
            class slqs : public __base {
            public:
               slqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               slqs(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Semiloof Triangular Curved Thin Shell (24 d.o.fs)
             */
            class slts : public __base {
            public:
               slts(const dnvgl::extfem::fem::cards::gelmnt1*);
               slts(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Semiloof Curved Beam (11 d.o.fs)
             */
            class slcb : public __base {
            public:
               slcb(const dnvgl::extfem::fem::cards::gelmnt1*);
               slcb(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Matrix Element with arbitrary no. of nodes (/n/)
             */
            class matr : public __base {
            public:
               matr(const dnvgl::extfem::fem::cards::gelmnt1*);
               matr(const dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron
             */
            class ghex : public __base {
            public:
               ghex(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex(const dnvgl::extfem::fem::cards::gelref1*);
               ghex(const __base*);
               virtual el_types get_type(void) const = 0;
            };

            /** Dispatch element class instance for `id`
             */
            void dispatch(std::unique_ptr<__base>&,
               const dnvgl::extfem::fem::cards::gelmnt1 *data);
         }
      }
   }
}

#include "elements_ghex.h"

#endif // _FEM_ELEMENTS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
