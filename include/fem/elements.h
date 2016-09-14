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

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace elements {

            typedef enum {
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
               INVALID=-1, UNDEFINED=-2} el_types;

            typedef enum {general, Preframe, Prefem, Sestra, ADVANCE,
                          Framework, Launch, Platework, Pretube,
                          Splice, Wadam, Wajac,
                          Poseidon} el_processor;

            namespace __base {
            /** Base class for FEM element representation.
             */
               class elem {

               protected:
                  static const el_types type;
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

               public:
                  elem(const dnvgl::extfem::fem::cards::gelmnt1*);
                  elem(const dnvgl::extfem::fem::cards::gelref1*);
                  elem(const elem*);

                  dnvgl::extfem::fem::cards::gelmnt1 gelmnt1(void) const;
                  dnvgl::extfem::fem::cards::gelref1 gelref1(void) const;


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
                  fem_thin_shell(long const elno,
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
                  fem_thin_shell(const dnvgl::extfem::fem::cards::gelmnt1*);
                  fem_thin_shell(const dnvgl::extfem::fem::cards::gelref1*);
                  fem_thin_shell(const __base::elem*);
               };
            }

            class undef : public __base::elem {
            public:
               undef (void);
               undef(const dnvgl::extfem::fem::cards::gelref1*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
            };


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
               beps(const dnvgl::extfem::fem::cards::gelmnt1*);
               beps(const dnvgl::extfem::fem::cards::gelref1*);
               beps(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               csta(const dnvgl::extfem::fem::cards::gelmnt1*);
               csta(const dnvgl::extfem::fem::cards::gelref1*);
               csta(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               rpbq(const dnvgl::extfem::fem::cards::gelmnt1*);
               rpbq(const dnvgl::extfem::fem::cards::gelref1*);
               rpbq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ilst(const dnvgl::extfem::fem::cards::gelmnt1*);
               ilst(const dnvgl::extfem::fem::cards::gelref1*);
               ilst(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               iqqe(const dnvgl::extfem::fem::cards::gelmnt1*);
               iqqe(const dnvgl::extfem::fem::cards::gelref1*);
               iqqe(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               lqua(const dnvgl::extfem::fem::cards::gelmnt1*);
               lqua(const dnvgl::extfem::fem::cards::gelref1*);
               lqua(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               tess(const dnvgl::extfem::fem::cards::gelmnt1*);
               tess(const dnvgl::extfem::fem::cards::gelref1*);
               tess(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               gmas(const dnvgl::extfem::fem::cards::gelmnt1*);
               gmas(const dnvgl::extfem::fem::cards::gelref1*);
               gmas(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               glma(const dnvgl::extfem::fem::cards::gelmnt1*);
               glma(const dnvgl::extfem::fem::cards::gelref1*);
               glma(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               glda(const dnvgl::extfem::fem::cards::gelmnt1*);
               glda(const dnvgl::extfem::fem::cards::gelref1*);
               glda(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               beas(const dnvgl::extfem::fem::cards::gelmnt1*);
               beas(const dnvgl::extfem::fem::cards::gelref1*);
               beas(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               axis(const dnvgl::extfem::fem::cards::gelmnt1*);
               axis(const dnvgl::extfem::fem::cards::gelref1*);
               axis(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               axda(const dnvgl::extfem::fem::cards::gelmnt1*);
               axda(const dnvgl::extfem::fem::cards::gelref1*);
               axda(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               gspr(const dnvgl::extfem::fem::cards::gelmnt1*);
               gspr(const dnvgl::extfem::fem::cards::gelref1*);
               gspr(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               gdam(const dnvgl::extfem::fem::cards::gelmnt1*);
               gdam(const dnvgl::extfem::fem::cards::gelref1*);
               gdam(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ihex(const dnvgl::extfem::fem::cards::gelmnt1*);
               ihex(const dnvgl::extfem::fem::cards::gelref1*);
               ihex(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               lhex(const dnvgl::extfem::fem::cards::gelmnt1*);
               lhex(const dnvgl::extfem::fem::cards::gelref1*);
               lhex(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               secb(const dnvgl::extfem::fem::cards::gelmnt1*);
               secb(const dnvgl::extfem::fem::cards::gelref1*);
               secb(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               btss(const dnvgl::extfem::fem::cards::gelmnt1*);
               btss(const dnvgl::extfem::fem::cards::gelref1*);
               btss(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               fqus_ffq(const dnvgl::extfem::fem::cards::gelmnt1*);
               fqus_ffq(const dnvgl::extfem::fem::cards::gelref1*);
               fqus_ffq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ftrs_fftr(const dnvgl::extfem::fem::cards::gelmnt1*);
               ftrs_fftr(const dnvgl::extfem::fem::cards::gelref1*);
               ftrs_fftr(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               scts(const dnvgl::extfem::fem::cards::gelmnt1*);
               scts(const dnvgl::extfem::fem::cards::gelref1*);
               scts(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               mcts(const dnvgl::extfem::fem::cards::gelmnt1*);
               mcts(const dnvgl::extfem::fem::cards::gelref1*);
               mcts(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               scqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               scqs(const dnvgl::extfem::fem::cards::gelref1*);
               scqs(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               mcqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               mcqs(const dnvgl::extfem::fem::cards::gelref1*);
               mcqs(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ipri(const dnvgl::extfem::fem::cards::gelmnt1*);
               ipri(const dnvgl::extfem::fem::cards::gelref1*);
               ipri(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               itet(const dnvgl::extfem::fem::cards::gelmnt1*);
               itet(const dnvgl::extfem::fem::cards::gelref1*);
               itet(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               tpri(const dnvgl::extfem::fem::cards::gelmnt1*);
               tpri(const dnvgl::extfem::fem::cards::gelref1*);
               tpri(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               tetr(const dnvgl::extfem::fem::cards::gelmnt1*);
               tetr(const dnvgl::extfem::fem::cards::gelref1*);
               tetr(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               lcts(const dnvgl::extfem::fem::cards::gelmnt1*);
               lcts(const dnvgl::extfem::fem::cards::gelref1*);
               lcts(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               lcqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               lcqs(const dnvgl::extfem::fem::cards::gelref1*);
               lcqs(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               trs1(const dnvgl::extfem::fem::cards::gelmnt1*);
               trs1(const dnvgl::extfem::fem::cards::gelref1*);
               trs1(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               trs2(const dnvgl::extfem::fem::cards::gelmnt1*);
               trs2(const dnvgl::extfem::fem::cards::gelref1*);
               trs2(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               trs3(const dnvgl::extfem::fem::cards::gelmnt1*);
               trs3(const dnvgl::extfem::fem::cards::gelref1*);
               trs3(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               glsh(const dnvgl::extfem::fem::cards::gelmnt1*);
               glsh(const dnvgl::extfem::fem::cards::gelref1*);
               glsh(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               axcs(const dnvgl::extfem::fem::cards::gelmnt1*);
               axcs(const dnvgl::extfem::fem::cards::gelref1*);
               axcs(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               axlq(const dnvgl::extfem::fem::cards::gelmnt1*);
               axlq(const dnvgl::extfem::fem::cards::gelref1*);
               axlq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               axls(const dnvgl::extfem::fem::cards::gelmnt1*);
               axls(const dnvgl::extfem::fem::cards::gelref1*);
               axls(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               axqq(const dnvgl::extfem::fem::cards::gelmnt1*);
               axqq(const dnvgl::extfem::fem::cards::gelref1*);
               axqq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               pils(const dnvgl::extfem::fem::cards::gelmnt1*);
               pils(const dnvgl::extfem::fem::cards::gelref1*);
               pils(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               pcab(const dnvgl::extfem::fem::cards::gelmnt1*);
               pcab(const dnvgl::extfem::fem::cards::gelref1*);
               pcab(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               pspr(const dnvgl::extfem::fem::cards::gelmnt1*);
               pspr(const dnvgl::extfem::fem::cards::gelref1*);
               pspr(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               adva_4(const dnvgl::extfem::fem::cards::gelmnt1*);
               adva_4(const dnvgl::extfem::fem::cards::gelref1*);
               adva_4(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               adva_2(const dnvgl::extfem::fem::cards::gelmnt1*);
               adva_2(const dnvgl::extfem::fem::cards::gelref1*);
               adva_2(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctcp(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcp(const dnvgl::extfem::fem::cards::gelref1*);
               ctcp(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctcl(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcl(const dnvgl::extfem::fem::cards::gelref1*);
               ctcl(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctal(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctal(const dnvgl::extfem::fem::cards::gelref1*);
               ctal(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctcc(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcc(const dnvgl::extfem::fem::cards::gelref1*);
               ctcc(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctaq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctaq(const dnvgl::extfem::fem::cards::gelref1*);
               ctaq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctlq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctlq(const dnvgl::extfem::fem::cards::gelref1*);
               ctlq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctcq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctcq(const dnvgl::extfem::fem::cards::gelref1*);
               ctcq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ctmq(const dnvgl::extfem::fem::cards::gelmnt1*);
               ctmq(const dnvgl::extfem::fem::cards::gelref1*);
               ctmq(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               hcqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               hcqs(const dnvgl::extfem::fem::cards::gelref1*);
               hcqs(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               slqs(const dnvgl::extfem::fem::cards::gelmnt1*);
               slqs(const dnvgl::extfem::fem::cards::gelref1*);
               slqs(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               slts(const dnvgl::extfem::fem::cards::gelmnt1*);
               slts(const dnvgl::extfem::fem::cards::gelref1*);
               slts(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               slcb(const dnvgl::extfem::fem::cards::gelmnt1*);
               slcb(const dnvgl::extfem::fem::cards::gelref1*);
               slcb(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               matr(const dnvgl::extfem::fem::cards::gelmnt1*);
               matr(const dnvgl::extfem::fem::cards::gelref1*);
               matr(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex100(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex100(const dnvgl::extfem::fem::cards::gelref1*);
               ghex100(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex101(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex101(const dnvgl::extfem::fem::cards::gelref1*);
               ghex101(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex102(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex102(const dnvgl::extfem::fem::cards::gelref1*);
               ghex102(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex103(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex103(const dnvgl::extfem::fem::cards::gelref1*);
               ghex103(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex104(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex104(const dnvgl::extfem::fem::cards::gelref1*);
               ghex104(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex105(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex105(const dnvgl::extfem::fem::cards::gelref1*);
               ghex105(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex106(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex106(const dnvgl::extfem::fem::cards::gelref1*);
               ghex106(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex107(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex107(const dnvgl::extfem::fem::cards::gelref1*);
               ghex107(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex108(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex108(const dnvgl::extfem::fem::cards::gelref1*);
               ghex108(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex109(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex109(const dnvgl::extfem::fem::cards::gelref1*);
               ghex109(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex110(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex110(const dnvgl::extfem::fem::cards::gelref1*);
               ghex110(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex111(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex111(const dnvgl::extfem::fem::cards::gelref1*);
               ghex111(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex112(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex112(const dnvgl::extfem::fem::cards::gelref1*);
               ghex112(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex113(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex113(const dnvgl::extfem::fem::cards::gelref1*);
               ghex113(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex114(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex114(const dnvgl::extfem::fem::cards::gelref1*);
               ghex114(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex115(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex115(const dnvgl::extfem::fem::cards::gelref1*);
               ghex115(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex116(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex116(const dnvgl::extfem::fem::cards::gelref1*);
               ghex116(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex117(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex117(const dnvgl::extfem::fem::cards::gelref1*);
               ghex117(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex118(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex118(const dnvgl::extfem::fem::cards::gelref1*);
               ghex118(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex119(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex119(const dnvgl::extfem::fem::cards::gelref1*);
               ghex119(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex120(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex120(const dnvgl::extfem::fem::cards::gelref1*);
               ghex120(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex121(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex121(const dnvgl::extfem::fem::cards::gelref1*);
               ghex121(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex122(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex122(const dnvgl::extfem::fem::cards::gelref1*);
               ghex122(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex123(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex123(const dnvgl::extfem::fem::cards::gelref1*);
               ghex123(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex124(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex124(const dnvgl::extfem::fem::cards::gelref1*);
               ghex124(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex125(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex125(const dnvgl::extfem::fem::cards::gelref1*);
               ghex125(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex126(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex126(const dnvgl::extfem::fem::cards::gelref1*);
               ghex126(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex127(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex127(const dnvgl::extfem::fem::cards::gelref1*);
               ghex127(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex128(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex128(const dnvgl::extfem::fem::cards::gelref1*);
               ghex128(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex129(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex129(const dnvgl::extfem::fem::cards::gelref1*);
               ghex129(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex130(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex130(const dnvgl::extfem::fem::cards::gelref1*);
               ghex130(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex131(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex131(const dnvgl::extfem::fem::cards::gelref1*);
               ghex131(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex132(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex132(const dnvgl::extfem::fem::cards::gelref1*);
               ghex132(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex133(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex133(const dnvgl::extfem::fem::cards::gelref1*);
               ghex133(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex134(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex134(const dnvgl::extfem::fem::cards::gelref1*);
               ghex134(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex135(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex135(const dnvgl::extfem::fem::cards::gelref1*);
               ghex135(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex136(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex136(const dnvgl::extfem::fem::cards::gelref1*);
               ghex136(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex137(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex137(const dnvgl::extfem::fem::cards::gelref1*);
               ghex137(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex138(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex138(const dnvgl::extfem::fem::cards::gelref1*);
               ghex138(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex139(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex139(const dnvgl::extfem::fem::cards::gelref1*);
               ghex139(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex140(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex140(const dnvgl::extfem::fem::cards::gelref1*);
               ghex140(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex141(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex141(const dnvgl::extfem::fem::cards::gelref1*);
               ghex141(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex142(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex142(const dnvgl::extfem::fem::cards::gelref1*);
               ghex142(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex143(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex143(const dnvgl::extfem::fem::cards::gelref1*);
               ghex143(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex144(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex144(const dnvgl::extfem::fem::cards::gelref1*);
               ghex144(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex145(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex145(const dnvgl::extfem::fem::cards::gelref1*);
               ghex145(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex146(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex146(const dnvgl::extfem::fem::cards::gelref1*);
               ghex146(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex147(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex147(const dnvgl::extfem::fem::cards::gelref1*);
               ghex147(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex148(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex148(const dnvgl::extfem::fem::cards::gelref1*);
               ghex148(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex149(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex149(const dnvgl::extfem::fem::cards::gelref1*);
               ghex149(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex150(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex150(const dnvgl::extfem::fem::cards::gelref1*);
               ghex150(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex151(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex151(const dnvgl::extfem::fem::cards::gelref1*);
               ghex151(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex152(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex152(const dnvgl::extfem::fem::cards::gelref1*);
               ghex152(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex153(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex153(const dnvgl::extfem::fem::cards::gelref1*);
               ghex153(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex154(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex154(const dnvgl::extfem::fem::cards::gelref1*);
               ghex154(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex155(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex155(const dnvgl::extfem::fem::cards::gelref1*);
               ghex155(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex156(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex156(const dnvgl::extfem::fem::cards::gelref1*);
               ghex156(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex157(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex157(const dnvgl::extfem::fem::cards::gelref1*);
               ghex157(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex158(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex158(const dnvgl::extfem::fem::cards::gelref1*);
               ghex158(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex159(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex159(const dnvgl::extfem::fem::cards::gelref1*);
               ghex159(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex160(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex160(const dnvgl::extfem::fem::cards::gelref1*);
               ghex160(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex161(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex161(const dnvgl::extfem::fem::cards::gelref1*);
               ghex161(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex162(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex162(const dnvgl::extfem::fem::cards::gelref1*);
               ghex162(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

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
               ghex163(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex163(const dnvgl::extfem::fem::cards::gelref1*);
               ghex163(const __base::elem*);
               virtual long nnodes(void) const;
               el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** Dispatch element class instance for `id`
             */
            void dispatch(std::unique_ptr<__base::elem>&,
               const cards::gelmnt1 *data);

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