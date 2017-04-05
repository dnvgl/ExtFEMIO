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
                namespace __base {
                    class elem;
                }
            }
        }
    }
}

std::ostream &operator<<(
    std::ostream&, dnvgl::extfem::fem::elements::__base::elem const &);

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace elements {

                enum class el_types {
                    BEPS = 2,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CSTA = 3,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    RPBQ = 5,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    ILST = 6,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    IQQE = 8,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    LQUA = 9,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    TESS = 10,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GMAS = 11,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GLMA = 12,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GLDA = 13,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    BEAS = 15,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    AXIS = 16,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    AXDA = 17,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GSPR = 18,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GDAM = 19,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    IHEX = 20,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    LHEX = 21,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    SECB = 22,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    BTSS = 23,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    FQUS_FFQ = 24,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    FTRS_FFTR = 25,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    SCTS = 26,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    MCTS = 27,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    SCQS = 28,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    MCQS = 29,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    IPRI = 30,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    ITET = 31,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    TPRI = 32,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    TETR = 33,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    LCTS = 34,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    LCQS = 35,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    TRS1 = 36,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    TRS2 = 37,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    TRS3 = 38,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GLSH = 40,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    AXCS = 41,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    AXLQ = 42,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    AXLS = 43,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    AXQQ = 44,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    PILS = 45,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    PCAB = 46,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    PSPR = 47,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    ADVA_4 = 48,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    ADVA_2 = 49,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTCP = 51,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTCL = 52,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTAL = 53,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTCC = 54,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTAQ = 55,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTLQ = 56,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTCQ = 57,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    CTMQ = 58,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    HCQS = 61,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    SLQS = 66,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    SLTS = 67,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    SLCB = 68,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    MATR = 70,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX100 = 100,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX101 = 101,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX102 = 102,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX103 = 103,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX104 = 104,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX105 = 105,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX106 = 106,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX107 = 107,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX108 = 108,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX109 = 109,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX110 = 110,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX111 = 111,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX112 = 112,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX113 = 113,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX114 = 114,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX115 = 115,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX116 = 116,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX117 = 117,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX118 = 118,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX119 = 119,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX120 = 120,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX121 = 121,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX122 = 122,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX123 = 123,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX124 = 124,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX125 = 125,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX126 = 126,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX127 = 127,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX128 = 128,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX129 = 129,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX130 = 130,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX131 = 131,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX132 = 132,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX133 = 133,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX134 = 134,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX135 = 135,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX136 = 136,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX137 = 137,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX138 = 138,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX139 = 139,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX140 = 140,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX141 = 141,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX142 = 142,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX143 = 143,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX144 = 144,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX145 = 145,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX146 = 146,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX147 = 147,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX148 = 148,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX149 = 149,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX150 = 150,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX151 = 151,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX152 = 152,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX153 = 153,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX154 = 154,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX155 = 155,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX156 = 156,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX157 = 157,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX158 = 158,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX159 = 159,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX160 = 160,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX161 = 161,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX162 = 162,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    GHEX163 = 163,
                    #line 59 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                    INVALID=-1, UNDEFINED=-2};
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
                        static std::set<long> used_ids;
                        static long max_id;
                        static std::set<long> used_nos;
                        static long max_no;

                    protected:

                        long static const get_eleno();
                        long static get_eleno(long const eleno);
                        long static const get_elident();
                        long static get_elident(long const elident);
                        el_types static const type;

                        elem();

                        elem(long const eleno, long const elident,
                             long const el_add,
                             std::vector<long> const &nodes,
                             long const matref,
                             long const add_no=0, long const intno=0,
                             long const mass_intno=0, long const i_strain_ref=0,
                             long const i_stressef=0, long const strpoint_ref=0,
                             std::vector<long> const &sections={},
                             std::vector<long> const &fixations={},
                             std::vector<long> const &eccentrities={},
                             std::vector<long> const &csys={});

                        elem(long const eleno, long const el_add,
                             std::vector<long> const &nodes,
                             long const matref,
                             long const add_no=0, long const intno=0,
                             long const mass_intno=0, long const i_strain_ref=0,
                             long const i_stressef=0, long const strpoint_ref=0,
                             std::vector<long> const &sections={},
                             std::vector<long> const &fixations={},
                             std::vector<long> const &eccentrities={},
                             std::vector<long> const &csys={});

                        elem(long const el_add,
                             std::vector<long> const &nodes,
                             long const matref,
                             long const add_no=0, long const intno=0,
                             long const mass_intno=0, long const i_strain_ref=0,
                             long const i_stressef=0, long const strpoint_ref=0,
                             std::vector<long> const &sections={},
                             std::vector<long> const &fixations={},
                             std::vector<long> const &eccentrities={},
                             std::vector<long> const &csys={});

                        elem const &operator() (
                            long const eleno, long const elident,
                            long const el_add,
                            std::vector<long> const &nodes,
                            long const matref,
                            long const add_no=0, long const intno=0,
                            long const mass_intno=0, long const i_strain_ref=0,
                            long const i_stressef=0, long const strpoint_ref=0,
                            std::vector<long> const &sections={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});

                        elem const &operator() (
                            long const eleno, long const el_add,
                            std::vector<long> const &nodes,
                            long const matref,
                            long const add_no=0, long const intno=0,
                            long const mass_intno=0, long const i_strain_ref=0,
                            long const i_stressef=0, long const strpoint_ref=0,
                            std::vector<long> const &sections={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});

                        elem const &operator() (
                            std::vector<long> const &nodes,
                            long const matref,
                            long const add_no=0, long const intno=0,
                            long const mass_intno=0, long const i_strain_ref=0,
                            long const i_stressef=0, long const strpoint_ref=0,
                            std::vector<long> const &sections={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});

                        elem const &operator() (
                            long const eleno,
                            std::vector<long> const &nodes,
                            long const matref,
                            std::vector<long> const &sections={},
                            long const el_add=0,
                            long const add_no=0,
                            long const intno=0,
                            long const mass_intno=0,
                            long const i_strain_ref=0,
                            long const i_stressef=0,
                            long const strpoint_ref=0,
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});

                        elem const &operator() (
                            long const el_add,
                            std::vector<long> const &nodes,
                            long const matref,
                            long const add_no,
                            long const intno,
                            long const mass_intno,
                            long const i_strain_ref,
                            long const i_stress_ref,
                            long const strpoint_ref,
                            std::vector<long> const &section={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});

                        elem const &operator() (
                            std::vector<long> const &nodes,
                            long const matref,
                            std::vector<long> const &sections={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            long const el_add=0,
                            long const add_no=0,
                            long const intno=0,
                            long const mass_intno=0,
                            long const i_strain_ref=0,
                            long const i_stressef=0,
                            long const strpoint_ref=0,
                            std::vector<long> const &csys={});

                        elem const &set_values(
                            long const eleno, long const elident,
                            long const el_add,
                            std::vector<long> const &nodes,
                            long const matref,
                            long const add_no, long const intno,
                            long const mass_intno, long const i_strain_ref,
                            long const i_stressef, long const strpoint_ref,
                            std::vector<long> const &sections={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});


                    public:
                        elem(cards::gelmnt1 const*);
                        elem(cards::gelref1 const*);
                        elem(elem const*);
                        virtual ~elem();

                        cards::__base::card const &gelmnt1() const;
                        cards::__base::card const &gelref1() const;

                        /** Reset static values for id and no check */
                        void static reset();

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

                        virtual void add(cards::gelref1 const*);
                        virtual void add(cards::gelmnt1 const*);

                        virtual long nnodes() const = 0;

                        virtual el_types get_type() const = 0;

                        friend std::ostream &::operator<<(std::ostream&, elem const &);
                    };

                    /**
                       \brief FEM element definition for fem_thin_shell.

                       Flat Quadrilateral/Triangular Thin Shell / Free
                       Formulation Quadrilateral/Triangular Shell
                    */
                    class fem_thin_shell : public virtual elem {};
                }

                class undef : public __base::elem {
                public:
                    undef ();
                    undef(cards::gelref1 const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-D, 2 Node Beam
                 */
                class beps : public __base::elem {
                public:
                    beps();
                    beps(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    beps(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    beps(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    beps(cards::gelmnt1 const*);
                    beps(cards::gelref1 const*);
                    beps(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Constant Strain Triangle
                 */
                class csta : public __base::elem {
                public:
                    csta();
                    csta(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    csta(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    csta(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    csta(cards::gelmnt1 const*);
                    csta(cards::gelref1 const*);
                    csta(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Rect. Plate. Bending Modes
                 */
                class rpbq : public __base::elem {
                public:
                    rpbq();
                    rpbq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    rpbq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    rpbq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    rpbq(cards::gelmnt1 const*);
                    rpbq(cards::gelref1 const*);
                    rpbq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Lin. Strain Triangle
                 */
                class ilst : public __base::elem {
                public:
                    ilst();
                    ilst(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ilst(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ilst(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ilst(cards::gelmnt1 const*);
                    ilst(cards::gelref1 const*);
                    ilst(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Quadrilateral Membrane Element
                 */
                class iqqe : public __base::elem {
                public:
                    iqqe();
                    iqqe(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    iqqe(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    iqqe(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    iqqe(cards::gelmnt1 const*);
                    iqqe(cards::gelref1 const*);
                    iqqe(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Quadrilateral Membrane Element
                 */
                class lqua : public __base::elem {
                public:
                    lqua();
                    lqua(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lqua(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lqua(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lqua(cards::gelmnt1 const*);
                    lqua(cards::gelref1 const*);
                    lqua(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Truss Element
                 */
                class tess : public __base::elem {
                public:
                    tess();
                    tess(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tess(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tess(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tess(cards::gelmnt1 const*);
                    tess(cards::gelref1 const*);
                    tess(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 1-Noded Mass-Matrix
                 */
                class gmas : public __base::elem {
                public:
                    gmas();
                    gmas(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gmas(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gmas(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gmas(cards::gelmnt1 const*);
                    gmas(cards::gelref1 const*);
                    gmas(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Mass-Matrix
                 */
                class glma : public __base::elem {
                public:
                    glma();
                    glma(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glma(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glma(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glma(cards::gelmnt1 const*);
                    glma(cards::gelref1 const*);
                    glma(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Damping-Matrix
                 */
                class glda : public __base::elem {
                public:
                    glda();
                    glda(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glda(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glda(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glda(cards::gelmnt1 const*);
                    glda(cards::gelref1 const*);
                    glda(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 3-D, 2 Node Beam
                 */
                class beas : public __base::elem {
                public:
                    beas();
                    beas(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    beas(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    beas(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    beas(cards::gelmnt1 const*);
                    beas(cards::gelref1 const*);
                    beas(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axial Spring
                 */
                class axis : public __base::elem {
                public:
                    axis();
                    axis(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axis(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axis(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axis(cards::gelmnt1 const*);
                    axis(cards::gelref1 const*);
                    axis(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axial Damper
                 */
                class axda : public __base::elem {
                public:
                    axda();
                    axda(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axda(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axda(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axda(cards::gelmnt1 const*);
                    axda(cards::gelref1 const*);
                    axda(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Spring to Ground
                 */
                class gspr : public __base::elem {
                public:
                    gspr();
                    gspr(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gspr(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gspr(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gspr(cards::gelmnt1 const*);
                    gspr(cards::gelref1 const*);
                    gspr(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Damper to Ground
                 */
                class gdam : public __base::elem {
                public:
                    gdam();
                    gdam(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gdam(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gdam(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    gdam(cards::gelmnt1 const*);
                    gdam(cards::gelref1 const*);
                    gdam(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Isoparametric Hexahedron
                 */
                class ihex : public __base::elem {
                public:
                    ihex();
                    ihex(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ihex(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ihex(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ihex(cards::gelmnt1 const*);
                    ihex(cards::gelref1 const*);
                    ihex(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Linear Hexahedron
                 */
                class lhex : public __base::elem {
                public:
                    lhex();
                    lhex(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lhex(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lhex(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lhex(cards::gelmnt1 const*);
                    lhex(cards::gelref1 const*);
                    lhex(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparametric Curved Beam
                 */
                class secb : public __base::elem {
                public:
                    secb();
                    secb(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    secb(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    secb(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    secb(cards::gelmnt1 const*);
                    secb(cards::gelref1 const*);
                    secb(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Curved Beam
                 */
                class btss : public __base::elem {
                public:
                    btss();
                    btss(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    btss(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    btss(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    btss(cards::gelmnt1 const*);
                    btss(cards::gelref1 const*);
                    btss(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Flat Quadrilateral Thin Shell / Free Formulation Quadrilateral Shell
                 */
                class fqus_ffq : public __base::fem_thin_shell {
                public:
                    fqus_ffq();
                    fqus_ffq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    fqus_ffq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    fqus_ffq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    fqus_ffq(cards::gelmnt1 const*);
                    fqus_ffq(cards::gelref1 const*);
                    fqus_ffq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /**  Flat Triangular Thin Shell / Free Formulation Triangular Shell
                 */
                class ftrs_fftr : public __base::fem_thin_shell {
                public:
                    ftrs_fftr();
                    ftrs_fftr(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ftrs_fftr(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ftrs_fftr(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ftrs_fftr(cards::gelmnt1 const*);
                    ftrs_fftr(cards::gelref1 const*);
                    ftrs_fftr(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparametric Curved Triangular Thick Shell
                 */
                class scts : public __base::elem {
                public:
                    scts();
                    scts(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    scts(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    scts(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    scts(cards::gelmnt1 const*);
                    scts(cards::gelref1 const*);
                    scts(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Curved Triang. Thick Sandwich Elem.
                 */
                class mcts : public __base::elem {
                public:
                    mcts();
                    mcts(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    mcts(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    mcts(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    mcts(cards::gelmnt1 const*);
                    mcts(cards::gelref1 const*);
                    mcts(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparametric Curved Quadrilateral Thick Shell
                 */
                class scqs : public __base::elem {
                public:
                    scqs();
                    scqs(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    scqs(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    scqs(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    scqs(cards::gelmnt1 const*);
                    scqs(cards::gelref1 const*);
                    scqs(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Curved Quadr. Thick Sandwich Elem.
                 */
                class mcqs : public __base::elem {
                public:
                    mcqs();
                    mcqs(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    mcqs(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    mcqs(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    mcqs(cards::gelmnt1 const*);
                    mcqs(cards::gelref1 const*);
                    mcqs(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Isoparametric Triangular Prism
                 */
                class ipri : public __base::elem {
                public:
                    ipri();
                    ipri(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ipri(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ipri(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ipri(cards::gelmnt1 const*);
                    ipri(cards::gelref1 const*);
                    ipri(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Isoparametric Tetrahedron
                 */
                class itet : public __base::elem {
                public:
                    itet();
                    itet(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    itet(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    itet(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    itet(cards::gelmnt1 const*);
                    itet(cards::gelref1 const*);
                    itet(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Triangular Prism
                 */
                class tpri : public __base::elem {
                public:
                    tpri();
                    tpri(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tpri(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tpri(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tpri(cards::gelmnt1 const*);
                    tpri(cards::gelref1 const*);
                    tpri(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Tetrahedron
                 */
                class tetr : public __base::elem {
                public:
                    tetr();
                    tetr(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tetr(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tetr(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    tetr(cards::gelmnt1 const*);
                    tetr(cards::gelref1 const*);
                    tetr(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Layered Curved Triangular Thick Shell
                 */
                class lcts : public __base::elem {
                public:
                    lcts();
                    lcts(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lcts(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lcts(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lcts(cards::gelmnt1 const*);
                    lcts(cards::gelref1 const*);
                    lcts(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Layered Curved Quadrilat. Thick Shell
                 */
                class lcqs : public __base::elem {
                public:
                    lcqs();
                    lcqs(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lcqs(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lcqs(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    lcqs(cards::gelmnt1 const*);
                    lcqs(cards::gelref1 const*);
                    lcqs(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2nd Order Hexahed. Transition Elem., Solid / Shell
                 */
                class trs1 : public __base::elem {
                public:
                    trs1();
                    trs1(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs1(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs1(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs1(cards::gelmnt1 const*);
                    trs1(cards::gelref1 const*);
                    trs1(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2nd Order Hexahed. Transition Elem., Solid / Shell
                 */
                class trs2 : public __base::elem {
                public:
                    trs2();
                    trs2(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs2(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs2(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs2(cards::gelmnt1 const*);
                    trs2(cards::gelref1 const*);
                    trs2(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2nd Order Hexahed. Transition Elem., Solid / Shell
                 */
                class trs3 : public __base::elem {
                public:
                    trs3();
                    trs3(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs3(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs3(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    trs3(cards::gelmnt1 const*);
                    trs3(cards::gelref1 const*);
                    trs3(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Spring / Shim Element
                 */
                class glsh : public __base::elem {
                public:
                    glsh();
                    glsh(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glsh(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glsh(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    glsh(cards::gelmnt1 const*);
                    glsh(cards::gelref1 const*);
                    glsh(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Constant Strain Triangle
                 */
                class axcs : public __base::elem {
                public:
                    axcs();
                    axcs(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axcs(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axcs(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axcs(cards::gelmnt1 const*);
                    axcs(cards::gelref1 const*);
                    axcs(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Quadrilateral
                 */
                class axlq : public __base::elem {
                public:
                    axlq();
                    axlq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axlq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axlq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axlq(cards::gelmnt1 const*);
                    axlq(cards::gelref1 const*);
                    axlq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Linear Strain Triangle
                 */
                class axls : public __base::elem {
                public:
                    axls();
                    axls(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axls(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axls(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axls(cards::gelmnt1 const*);
                    axls(cards::gelref1 const*);
                    axls(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Linear Strain Quadrilateral
                 */
                class axqq : public __base::elem {
                public:
                    axqq();
                    axqq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axqq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axqq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    axqq(cards::gelmnt1 const*);
                    axqq(cards::gelref1 const*);
                    axqq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Pile / Soil
                 */
                class pils : public __base::elem {
                public:
                    pils();
                    pils(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pils(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pils(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pils(cards::gelmnt1 const*);
                    pils(cards::gelref1 const*);
                    pils(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Cable-Bar Element
                 */
                class pcab : public __base::elem {
                public:
                    pcab();
                    pcab(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pcab(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pcab(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pcab(cards::gelmnt1 const*);
                    pcab(cards::gelref1 const*);
                    pcab(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Spring Element
                 */
                class pspr : public __base::elem {
                public:
                    pspr();
                    pspr(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pspr(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pspr(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    pspr(cards::gelmnt1 const*);
                    pspr(cards::gelref1 const*);
                    pspr(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 4-node Contact Element with triangular Shape
                 */
                class adva_4 : public __base::elem {
                public:
                    adva_4();
                    adva_4(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    adva_4(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    adva_4(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    adva_4(cards::gelmnt1 const*);
                    adva_4(cards::gelref1 const*);
                    adva_4(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Link Element
                 */
                class adva_2 : public __base::elem {
                public:
                    adva_2();
                    adva_2(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    adva_2(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    adva_2(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    adva_2(cards::gelmnt1 const*);
                    adva_2(cards::gelref1 const*);
                    adva_2(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Contact Element
                 */
                class ctcp : public __base::elem {
                public:
                    ctcp();
                    ctcp(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcp(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcp(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcp(cards::gelmnt1 const*);
                    ctcp(cards::gelref1 const*);
                    ctcp(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 4-Noded Contact Element
                 */
                class ctcl : public __base::elem {
                public:
                    ctcl();
                    ctcl(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcl(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcl(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcl(cards::gelmnt1 const*);
                    ctcl(cards::gelref1 const*);
                    ctcl(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 4-Noded Axisymmetric Contact Element
                 */
                class ctal : public __base::elem {
                public:
                    ctal();
                    ctal(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctal(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctal(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctal(cards::gelmnt1 const*);
                    ctal(cards::gelref1 const*);
                    ctal(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 6-Noded Contact Element
                 */
                class ctcc : public __base::elem {
                public:
                    ctcc();
                    ctcc(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcc(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcc(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcc(cards::gelmnt1 const*);
                    ctcc(cards::gelref1 const*);
                    ctcc(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 6-Noded (3+3) Axisymmetric Contact Element
                 */
                class ctaq : public __base::elem {
                public:
                    ctaq();
                    ctaq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctaq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctaq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctaq(cards::gelmnt1 const*);
                    ctaq(cards::gelref1 const*);
                    ctaq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 8-Noded (4+4) Contact Element
                 */
                class ctlq : public __base::elem {
                public:
                    ctlq();
                    ctlq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctlq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctlq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctlq(cards::gelmnt1 const*);
                    ctlq(cards::gelref1 const*);
                    ctlq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 16-Noded (8+8) Contact Element
                 */
                class ctcq : public __base::elem {
                public:
                    ctcq();
                    ctcq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctcq(cards::gelmnt1 const*);
                    ctcq(cards::gelref1 const*);
                    ctcq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 18-Noded (9+9) Contact Element
                 */
                class ctmq : public __base::elem {
                public:
                    ctmq();
                    ctmq(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctmq(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctmq(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ctmq(cards::gelmnt1 const*);
                    ctmq(cards::gelref1 const*);
                    ctmq(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 9-Noded Shell Element
                 */
                class hcqs : public __base::elem {
                public:
                    hcqs();
                    hcqs(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    hcqs(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    hcqs(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    hcqs(cards::gelmnt1 const*);
                    hcqs(cards::gelref1 const*);
                    hcqs(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)
                 */
                class slqs : public __base::elem {
                public:
                    slqs();
                    slqs(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slqs(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slqs(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slqs(cards::gelmnt1 const*);
                    slqs(cards::gelref1 const*);
                    slqs(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Semiloof Triangular Curved Thin Shell (24 d.o.fs)
                 */
                class slts : public __base::elem {
                public:
                    slts();
                    slts(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slts(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slts(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slts(cards::gelmnt1 const*);
                    slts(cards::gelref1 const*);
                    slts(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Semiloof Curved Beam (11 d.o.fs)
                 */
                class slcb : public __base::elem {
                public:
                    slcb();
                    slcb(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slcb(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slcb(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    slcb(cards::gelmnt1 const*);
                    slcb(cards::gelref1 const*);
                    slcb(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Matrix Element with arbitrary no. of nodes (/n/)
                 */
                class matr : public __base::elem {
                public:
                    matr();
                    matr(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    matr(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    matr(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    matr(cards::gelmnt1 const*);
                    matr(cards::gelref1 const*);
                    matr(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 27 at pos 21
                 */
                class ghex100 : public __base::elem {
                public:
                    ghex100();
                    ghex100(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex100(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex100(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex100(cards::gelmnt1 const*);
                    ghex100(cards::gelref1 const*);
                    ghex100(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 27 at pos 22
                 */
                class ghex101 : public __base::elem {
                public:
                    ghex101();
                    ghex101(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex101(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex101(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex101(cards::gelmnt1 const*);
                    ghex101(cards::gelref1 const*);
                    ghex101(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 27 at pos 22
                 */
                class ghex102 : public __base::elem {
                public:
                    ghex102();
                    ghex102(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex102(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex102(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex102(cards::gelmnt1 const*);
                    ghex102(cards::gelref1 const*);
                    ghex102(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 27 at pos 23
                 */
                class ghex103 : public __base::elem {
                public:
                    ghex103();
                    ghex103(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex103(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex103(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex103(cards::gelmnt1 const*);
                    ghex103(cards::gelref1 const*);
                    ghex103(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 27 at pos 22
                 */
                class ghex104 : public __base::elem {
                public:
                    ghex104();
                    ghex104(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex104(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex104(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex104(cards::gelmnt1 const*);
                    ghex104(cards::gelref1 const*);
                    ghex104(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
                 */
                class ghex105 : public __base::elem {
                public:
                    ghex105();
                    ghex105(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex105(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex105(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex105(cards::gelmnt1 const*);
                    ghex105(cards::gelref1 const*);
                    ghex105(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
                 */
                class ghex106 : public __base::elem {
                public:
                    ghex106();
                    ghex106(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex106(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex106(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex106(cards::gelmnt1 const*);
                    ghex106(cards::gelref1 const*);
                    ghex106(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 27 at pos 24
                 */
                class ghex107 : public __base::elem {
                public:
                    ghex107();
                    ghex107(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex107(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex107(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex107(cards::gelmnt1 const*);
                    ghex107(cards::gelref1 const*);
                    ghex107(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 27 at pos 22
                 */
                class ghex108 : public __base::elem {
                public:
                    ghex108();
                    ghex108(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex108(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex108(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex108(cards::gelmnt1 const*);
                    ghex108(cards::gelref1 const*);
                    ghex108(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
                 */
                class ghex109 : public __base::elem {
                public:
                    ghex109();
                    ghex109(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex109(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex109(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex109(cards::gelmnt1 const*);
                    ghex109(cards::gelref1 const*);
                    ghex109(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
                 */
                class ghex110 : public __base::elem {
                public:
                    ghex110();
                    ghex110(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex110(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex110(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex110(cards::gelmnt1 const*);
                    ghex110(cards::gelref1 const*);
                    ghex110(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
                 */
                class ghex111 : public __base::elem {
                public:
                    ghex111();
                    ghex111(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex111(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex111(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex111(cards::gelmnt1 const*);
                    ghex111(cards::gelref1 const*);
                    ghex111(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
                 */
                class ghex112 : public __base::elem {
                public:
                    ghex112();
                    ghex112(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex112(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex112(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex112(cards::gelmnt1 const*);
                    ghex112(cards::gelref1 const*);
                    ghex112(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
                 */
                class ghex113 : public __base::elem {
                public:
                    ghex113();
                    ghex113(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex113(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex113(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex113(cards::gelmnt1 const*);
                    ghex113(cards::gelref1 const*);
                    ghex113(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
                 */
                class ghex114 : public __base::elem {
                public:
                    ghex114();
                    ghex114(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex114(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex114(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex114(cards::gelmnt1 const*);
                    ghex114(cards::gelref1 const*);
                    ghex114(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex115();
                    ghex115(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex115(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex115(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex115(cards::gelmnt1 const*);
                    ghex115(cards::gelref1 const*);
                    ghex115(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 27 at pos 22
                 */
                class ghex116 : public __base::elem {
                public:
                    ghex116();
                    ghex116(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex116(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex116(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex116(cards::gelmnt1 const*);
                    ghex116(cards::gelref1 const*);
                    ghex116(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
                 */
                class ghex117 : public __base::elem {
                public:
                    ghex117();
                    ghex117(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex117(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex117(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex117(cards::gelmnt1 const*);
                    ghex117(cards::gelref1 const*);
                    ghex117(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
                 */
                class ghex118 : public __base::elem {
                public:
                    ghex118();
                    ghex118(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex118(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex118(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex118(cards::gelmnt1 const*);
                    ghex118(cards::gelref1 const*);
                    ghex118(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
                 */
                class ghex119 : public __base::elem {
                public:
                    ghex119();
                    ghex119(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex119(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex119(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex119(cards::gelmnt1 const*);
                    ghex119(cards::gelref1 const*);
                    ghex119(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
                 */
                class ghex120 : public __base::elem {
                public:
                    ghex120();
                    ghex120(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex120(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex120(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex120(cards::gelmnt1 const*);
                    ghex120(cards::gelref1 const*);
                    ghex120(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
                 */
                class ghex121 : public __base::elem {
                public:
                    ghex121();
                    ghex121(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex121(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex121(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex121(cards::gelmnt1 const*);
                    ghex121(cards::gelref1 const*);
                    ghex121(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
                 */
                class ghex122 : public __base::elem {
                public:
                    ghex122();
                    ghex122(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex122(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex122(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex122(cards::gelmnt1 const*);
                    ghex122(cards::gelref1 const*);
                    ghex122(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex123();
                    ghex123(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex123(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex123(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex123(cards::gelmnt1 const*);
                    ghex123(cards::gelref1 const*);
                    ghex123(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
                 */
                class ghex124 : public __base::elem {
                public:
                    ghex124();
                    ghex124(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex124(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex124(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex124(cards::gelmnt1 const*);
                    ghex124(cards::gelref1 const*);
                    ghex124(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
                 */
                class ghex125 : public __base::elem {
                public:
                    ghex125();
                    ghex125(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex125(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex125(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex125(cards::gelmnt1 const*);
                    ghex125(cards::gelref1 const*);
                    ghex125(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
                 */
                class ghex126 : public __base::elem {
                public:
                    ghex126();
                    ghex126(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex126(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex126(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex126(cards::gelmnt1 const*);
                    ghex126(cards::gelref1 const*);
                    ghex126(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex127();
                    ghex127(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex127(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex127(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex127(cards::gelmnt1 const*);
                    ghex127(cards::gelref1 const*);
                    ghex127(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
                 */
                class ghex128 : public __base::elem {
                public:
                    ghex128();
                    ghex128(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex128(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex128(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex128(cards::gelmnt1 const*);
                    ghex128(cards::gelref1 const*);
                    ghex128(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex129();
                    ghex129(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex129(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex129(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex129(cards::gelmnt1 const*);
                    ghex129(cards::gelref1 const*);
                    ghex129(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex130();
                    ghex130(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex130(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex130(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex130(cards::gelmnt1 const*);
                    ghex130(cards::gelref1 const*);
                    ghex130(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex131();
                    ghex131(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex131(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex131(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex131(cards::gelmnt1 const*);
                    ghex131(cards::gelref1 const*);
                    ghex131(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 26 at pos 21
                    - node 27 at pos 22
                 */
                class ghex132 : public __base::elem {
                public:
                    ghex132();
                    ghex132(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex132(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex132(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex132(cards::gelmnt1 const*);
                    ghex132(cards::gelref1 const*);
                    ghex132(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
                 */
                class ghex133 : public __base::elem {
                public:
                    ghex133();
                    ghex133(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex133(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex133(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex133(cards::gelmnt1 const*);
                    ghex133(cards::gelref1 const*);
                    ghex133(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
                 */
                class ghex134 : public __base::elem {
                public:
                    ghex134();
                    ghex134(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex134(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex134(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex134(cards::gelmnt1 const*);
                    ghex134(cards::gelref1 const*);
                    ghex134(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex135 : public __base::elem {
                public:
                    ghex135();
                    ghex135(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex135(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex135(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex135(cards::gelmnt1 const*);
                    ghex135(cards::gelref1 const*);
                    ghex135(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
                 */
                class ghex136 : public __base::elem {
                public:
                    ghex136();
                    ghex136(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex136(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex136(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex136(cards::gelmnt1 const*);
                    ghex136(cards::gelref1 const*);
                    ghex136(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex137 : public __base::elem {
                public:
                    ghex137();
                    ghex137(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex137(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex137(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex137(cards::gelmnt1 const*);
                    ghex137(cards::gelref1 const*);
                    ghex137(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex138 : public __base::elem {
                public:
                    ghex138();
                    ghex138(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex138(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex138(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex138(cards::gelmnt1 const*);
                    ghex138(cards::gelref1 const*);
                    ghex138(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex139();
                    ghex139(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex139(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex139(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex139(cards::gelmnt1 const*);
                    ghex139(cards::gelref1 const*);
                    ghex139(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
                 */
                class ghex140 : public __base::elem {
                public:
                    ghex140();
                    ghex140(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex140(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex140(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex140(cards::gelmnt1 const*);
                    ghex140(cards::gelref1 const*);
                    ghex140(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex141 : public __base::elem {
                public:
                    ghex141();
                    ghex141(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex141(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex141(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex141(cards::gelmnt1 const*);
                    ghex141(cards::gelref1 const*);
                    ghex141(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex142 : public __base::elem {
                public:
                    ghex142();
                    ghex142(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex142(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex142(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex142(cards::gelmnt1 const*);
                    ghex142(cards::gelref1 const*);
                    ghex142(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex143();
                    ghex143(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex143(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex143(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex143(cards::gelmnt1 const*);
                    ghex143(cards::gelref1 const*);
                    ghex143(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex144 : public __base::elem {
                public:
                    ghex144();
                    ghex144(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex144(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex144(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex144(cards::gelmnt1 const*);
                    ghex144(cards::gelref1 const*);
                    ghex144(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex145();
                    ghex145(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex145(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex145(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex145(cards::gelmnt1 const*);
                    ghex145(cards::gelref1 const*);
                    ghex145(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex146();
                    ghex146(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex146(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex146(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex146(cards::gelmnt1 const*);
                    ghex146(cards::gelref1 const*);
                    ghex146(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex147();
                    ghex147(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex147(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex147(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex147(cards::gelmnt1 const*);
                    ghex147(cards::gelref1 const*);
                    ghex147(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
                 */
                class ghex148 : public __base::elem {
                public:
                    ghex148();
                    ghex148(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex148(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex148(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex148(cards::gelmnt1 const*);
                    ghex148(cards::gelref1 const*);
                    ghex148(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex149 : public __base::elem {
                public:
                    ghex149();
                    ghex149(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex149(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex149(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex149(cards::gelmnt1 const*);
                    ghex149(cards::gelref1 const*);
                    ghex149(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex150 : public __base::elem {
                public:
                    ghex150();
                    ghex150(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex150(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex150(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex150(cards::gelmnt1 const*);
                    ghex150(cards::gelref1 const*);
                    ghex150(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex151();
                    ghex151(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex151(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex151(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex151(cards::gelmnt1 const*);
                    ghex151(cards::gelref1 const*);
                    ghex151(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex152 : public __base::elem {
                public:
                    ghex152();
                    ghex152(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex152(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex152(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex152(cards::gelmnt1 const*);
                    ghex152(cards::gelref1 const*);
                    ghex152(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex153();
                    ghex153(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex153(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex153(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex153(cards::gelmnt1 const*);
                    ghex153(cards::gelref1 const*);
                    ghex153(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex154();
                    ghex154(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex154(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex154(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex154(cards::gelmnt1 const*);
                    ghex154(cards::gelref1 const*);
                    ghex154(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex155();
                    ghex155(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex155(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex155(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex155(cards::gelmnt1 const*);
                    ghex155(cards::gelref1 const*);
                    ghex155(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 26, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
                 */
                class ghex156 : public __base::elem {
                public:
                    ghex156();
                    ghex156(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex156(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex156(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex156(cards::gelmnt1 const*);
                    ghex156(cards::gelref1 const*);
                    ghex156(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex157();
                    ghex157(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex157(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex157(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex157(cards::gelmnt1 const*);
                    ghex157(cards::gelref1 const*);
                    ghex157(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex158();
                    ghex158(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex158(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex158(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex158(cards::gelmnt1 const*);
                    ghex158(cards::gelref1 const*);
                    ghex158(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex159();
                    ghex159(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex159(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex159(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex159(cards::gelmnt1 const*);
                    ghex159(cards::gelref1 const*);
                    ghex159(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex160();
                    ghex160(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex160(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex160(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex160(cards::gelmnt1 const*);
                    ghex160(cards::gelref1 const*);
                    ghex160(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex161();
                    ghex161(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex161(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex161(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex161(cards::gelmnt1 const*);
                    ghex161(cards::gelref1 const*);
                    ghex161(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex162();
                    ghex162(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex162(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex162(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex162(cards::gelmnt1 const*);
                    ghex162(cards::gelref1 const*);
                    ghex162(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
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
                    ghex163();
                    ghex163(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex163(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex163(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    ghex163(cards::gelmnt1 const*);
                    ghex163(cards::gelref1 const*);
                    ghex163(elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 373 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Dispatch element class instance for `id`
                 */
                void dispatch(
                    std::unique_ptr<__base::elem>&, cards::gelmnt1 const *data);

                /** Match element type id to element type name.
                 */
                std::string name_elem(
                    el_types const);
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
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_elements --use-colour no)"
// End: