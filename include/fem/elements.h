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

                        long static const get_eleno(void);
                        long static get_eleno(long const eleno);
                        long static const get_elident();
                        long static get_elident(long const elident);
                        el_types static const type;

                        elem(void);

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

                        __base::elem const &operator() (
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

                        __base::elem const &operator() (
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

                        __base::elem const &operator() (
                            std::vector<long> const &nodes,
                            long const matref,
                            long const add_no=0, long const intno=0,
                            long const mass_intno=0, long const i_strain_ref=0,
                            long const i_stressef=0, long const strpoint_ref=0,
                            std::vector<long> const &sections={},
                            std::vector<long> const &fixations={},
                            std::vector<long> const &eccentrities={},
                            std::vector<long> const &csys={});

                        __base::elem const &operator() (
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

                        __base::elem const &operator() (
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

                        __base::elem const &operator() (
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

                        __base::elem const &set_values(
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
                        elem(dnvgl::extfem::fem::cards::gelmnt1 const*);
                        elem(dnvgl::extfem::fem::cards::gelref1 const*);
                        elem(elem const*);
                        virtual ~elem(void);

                        cards::__base::card const &gelmnt1(void) const;
                        cards::__base::card const &gelref1(void) const;

                        /** Reset static values for id and no check */
                        void static reset(void);

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

                        friend std::ostream &::operator<<(std::ostream&, elem const &);
                    };

                    /**
                       \brief FEM element definition for fem_thin_shell.

                       Flat Quadrilateral/Triangular Thin Shell / Free
                       Formulation Quadrilateral/Triangular Shell
                    */
                    class fem_thin_shell : public virtual __base::elem {};
                }

                class undef : public __base::elem {
                public:
                    undef (void);
                    undef(dnvgl::extfem::fem::cards::gelref1 const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-D, 2 Node Beam
                 */
                class beps : public __base::elem {
                public:
                    beps(void);
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
                    beps(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    beps(dnvgl::extfem::fem::cards::gelref1 const*);
                    beps(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Constant Strain Triangle
                 */
                class csta : public __base::elem {
                public:
                    csta(void);
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
                    csta(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    csta(dnvgl::extfem::fem::cards::gelref1 const*);
                    csta(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Rect. Plate. Bending Modes
                 */
                class rpbq : public __base::elem {
                public:
                    rpbq(void);
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
                    rpbq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    rpbq(dnvgl::extfem::fem::cards::gelref1 const*);
                    rpbq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Lin. Strain Triangle
                 */
                class ilst : public __base::elem {
                public:
                    ilst(void);
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
                    ilst(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ilst(dnvgl::extfem::fem::cards::gelref1 const*);
                    ilst(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Quadrilateral Membrane Element
                 */
                class iqqe : public __base::elem {
                public:
                    iqqe(void);
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
                    iqqe(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    iqqe(dnvgl::extfem::fem::cards::gelref1 const*);
                    iqqe(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Quadrilateral Membrane Element
                 */
                class lqua : public __base::elem {
                public:
                    lqua(void);
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
                    lqua(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    lqua(dnvgl::extfem::fem::cards::gelref1 const*);
                    lqua(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Truss Element
                 */
                class tess : public __base::elem {
                public:
                    tess(void);
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
                    tess(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    tess(dnvgl::extfem::fem::cards::gelref1 const*);
                    tess(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 1-Noded Mass-Matrix
                 */
                class gmas : public __base::elem {
                public:
                    gmas(void);
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
                    gmas(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    gmas(dnvgl::extfem::fem::cards::gelref1 const*);
                    gmas(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Mass-Matrix
                 */
                class glma : public __base::elem {
                public:
                    glma(void);
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
                    glma(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    glma(dnvgl::extfem::fem::cards::gelref1 const*);
                    glma(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Damping-Matrix
                 */
                class glda : public __base::elem {
                public:
                    glda(void);
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
                    glda(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    glda(dnvgl::extfem::fem::cards::gelref1 const*);
                    glda(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 3-D, 2 Node Beam
                 */
                class beas : public __base::elem {
                public:
                    beas(void);
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
                    beas(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    beas(dnvgl::extfem::fem::cards::gelref1 const*);
                    beas(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axial Spring
                 */
                class axis : public __base::elem {
                public:
                    axis(void);
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
                    axis(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    axis(dnvgl::extfem::fem::cards::gelref1 const*);
                    axis(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axial Damper
                 */
                class axda : public __base::elem {
                public:
                    axda(void);
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
                    axda(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    axda(dnvgl::extfem::fem::cards::gelref1 const*);
                    axda(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Spring to Ground
                 */
                class gspr : public __base::elem {
                public:
                    gspr(void);
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
                    gspr(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    gspr(dnvgl::extfem::fem::cards::gelref1 const*);
                    gspr(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Damper to Ground
                 */
                class gdam : public __base::elem {
                public:
                    gdam(void);
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
                    gdam(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    gdam(dnvgl::extfem::fem::cards::gelref1 const*);
                    gdam(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Isoparametric Hexahedron
                 */
                class ihex : public __base::elem {
                public:
                    ihex(void);
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
                    ihex(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ihex(dnvgl::extfem::fem::cards::gelref1 const*);
                    ihex(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Linear Hexahedron
                 */
                class lhex : public __base::elem {
                public:
                    lhex(void);
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
                    lhex(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    lhex(dnvgl::extfem::fem::cards::gelref1 const*);
                    lhex(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparametric Curved Beam
                 */
                class secb : public __base::elem {
                public:
                    secb(void);
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
                    secb(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    secb(dnvgl::extfem::fem::cards::gelref1 const*);
                    secb(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Curved Beam
                 */
                class btss : public __base::elem {
                public:
                    btss(void);
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
                    btss(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    btss(dnvgl::extfem::fem::cards::gelref1 const*);
                    btss(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Flat Quadrilateral Thin Shell / Free Formulation Quadrilateral Shell
                 */
                class fqus_ffq : public __base::fem_thin_shell {
                public:
                    fqus_ffq(void);
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
                    fqus_ffq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    fqus_ffq(dnvgl::extfem::fem::cards::gelref1 const*);
                    fqus_ffq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /**  Flat Triangular Thin Shell / Free Formulation Triangular Shell
                 */
                class ftrs_fftr : public __base::fem_thin_shell {
                public:
                    ftrs_fftr(void);
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
                    ftrs_fftr(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ftrs_fftr(dnvgl::extfem::fem::cards::gelref1 const*);
                    ftrs_fftr(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparametric Curved Triangular Thick Shell
                 */
                class scts : public __base::elem {
                public:
                    scts(void);
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
                    scts(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    scts(dnvgl::extfem::fem::cards::gelref1 const*);
                    scts(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Curved Triang. Thick Sandwich Elem.
                 */
                class mcts : public __base::elem {
                public:
                    mcts(void);
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
                    mcts(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    mcts(dnvgl::extfem::fem::cards::gelref1 const*);
                    mcts(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparametric Curved Quadrilateral Thick Shell
                 */
                class scqs : public __base::elem {
                public:
                    scqs(void);
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
                    scqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    scqs(dnvgl::extfem::fem::cards::gelref1 const*);
                    scqs(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Curved Quadr. Thick Sandwich Elem.
                 */
                class mcqs : public __base::elem {
                public:
                    mcqs(void);
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
                    mcqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    mcqs(dnvgl::extfem::fem::cards::gelref1 const*);
                    mcqs(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Isoparametric Triangular Prism
                 */
                class ipri : public __base::elem {
                public:
                    ipri(void);
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
                    ipri(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ipri(dnvgl::extfem::fem::cards::gelref1 const*);
                    ipri(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Isoparametric Tetrahedron
                 */
                class itet : public __base::elem {
                public:
                    itet(void);
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
                    itet(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    itet(dnvgl::extfem::fem::cards::gelref1 const*);
                    itet(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Triangular Prism
                 */
                class tpri : public __base::elem {
                public:
                    tpri(void);
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
                    tpri(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    tpri(dnvgl::extfem::fem::cards::gelref1 const*);
                    tpri(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Tetrahedron
                 */
                class tetr : public __base::elem {
                public:
                    tetr(void);
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
                    tetr(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    tetr(dnvgl::extfem::fem::cards::gelref1 const*);
                    tetr(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Layered Curved Triangular Thick Shell
                 */
                class lcts : public __base::elem {
                public:
                    lcts(void);
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
                    lcts(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    lcts(dnvgl::extfem::fem::cards::gelref1 const*);
                    lcts(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Subparam. Layered Curved Quadrilat. Thick Shell
                 */
                class lcqs : public __base::elem {
                public:
                    lcqs(void);
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
                    lcqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    lcqs(dnvgl::extfem::fem::cards::gelref1 const*);
                    lcqs(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2nd Order Hexahed. Transition Elem., Solid / Shell
                 */
                class trs1 : public __base::elem {
                public:
                    trs1(void);
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
                    trs1(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    trs1(dnvgl::extfem::fem::cards::gelref1 const*);
                    trs1(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2nd Order Hexahed. Transition Elem., Solid / Shell
                 */
                class trs2 : public __base::elem {
                public:
                    trs2(void);
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
                    trs2(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    trs2(dnvgl::extfem::fem::cards::gelref1 const*);
                    trs2(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2nd Order Hexahed. Transition Elem., Solid / Shell
                 */
                class trs3 : public __base::elem {
                public:
                    trs3(void);
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
                    trs3(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    trs3(dnvgl::extfem::fem::cards::gelref1 const*);
                    trs3(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Spring / Shim Element
                 */
                class glsh : public __base::elem {
                public:
                    glsh(void);
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
                    glsh(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    glsh(dnvgl::extfem::fem::cards::gelref1 const*);
                    glsh(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Constant Strain Triangle
                 */
                class axcs : public __base::elem {
                public:
                    axcs(void);
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
                    axcs(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    axcs(dnvgl::extfem::fem::cards::gelref1 const*);
                    axcs(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Quadrilateral
                 */
                class axlq : public __base::elem {
                public:
                    axlq(void);
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
                    axlq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    axlq(dnvgl::extfem::fem::cards::gelref1 const*);
                    axlq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Linear Strain Triangle
                 */
                class axls : public __base::elem {
                public:
                    axls(void);
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
                    axls(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    axls(dnvgl::extfem::fem::cards::gelref1 const*);
                    axls(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Axisymmetric Linear Strain Quadrilateral
                 */
                class axqq : public __base::elem {
                public:
                    axqq(void);
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
                    axqq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    axqq(dnvgl::extfem::fem::cards::gelref1 const*);
                    axqq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Pile / Soil
                 */
                class pils : public __base::elem {
                public:
                    pils(void);
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
                    pils(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    pils(dnvgl::extfem::fem::cards::gelref1 const*);
                    pils(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Cable-Bar Element
                 */
                class pcab : public __base::elem {
                public:
                    pcab(void);
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
                    pcab(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    pcab(dnvgl::extfem::fem::cards::gelref1 const*);
                    pcab(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Plane Spring Element
                 */
                class pspr : public __base::elem {
                public:
                    pspr(void);
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
                    pspr(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    pspr(dnvgl::extfem::fem::cards::gelref1 const*);
                    pspr(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 4-node Contact Element with triangular Shape
                 */
                class adva_4 : public __base::elem {
                public:
                    adva_4(void);
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
                    adva_4(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    adva_4(dnvgl::extfem::fem::cards::gelref1 const*);
                    adva_4(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Link Element
                 */
                class adva_2 : public __base::elem {
                public:
                    adva_2(void);
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
                    adva_2(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    adva_2(dnvgl::extfem::fem::cards::gelref1 const*);
                    adva_2(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 2-Noded Contact Element
                 */
                class ctcp : public __base::elem {
                public:
                    ctcp(void);
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
                    ctcp(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctcp(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctcp(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 4-Noded Contact Element
                 */
                class ctcl : public __base::elem {
                public:
                    ctcl(void);
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
                    ctcl(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctcl(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctcl(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 4-Noded Axisymmetric Contact Element
                 */
                class ctal : public __base::elem {
                public:
                    ctal(void);
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
                    ctal(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctal(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctal(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 6-Noded Contact Element
                 */
                class ctcc : public __base::elem {
                public:
                    ctcc(void);
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
                    ctcc(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctcc(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctcc(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 6-Noded (3+3) Axisymmetric Contact Element
                 */
                class ctaq : public __base::elem {
                public:
                    ctaq(void);
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
                    ctaq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctaq(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctaq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 8-Noded (4+4) Contact Element
                 */
                class ctlq : public __base::elem {
                public:
                    ctlq(void);
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
                    ctlq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctlq(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctlq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 16-Noded (8+8) Contact Element
                 */
                class ctcq : public __base::elem {
                public:
                    ctcq(void);
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
                    ctcq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctcq(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctcq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 18-Noded (9+9) Contact Element
                 */
                class ctmq : public __base::elem {
                public:
                    ctmq(void);
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
                    ctmq(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ctmq(dnvgl::extfem::fem::cards::gelref1 const*);
                    ctmq(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** 9-Noded Shell Element
                 */
                class hcqs : public __base::elem {
                public:
                    hcqs(void);
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
                    hcqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    hcqs(dnvgl::extfem::fem::cards::gelref1 const*);
                    hcqs(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)
                 */
                class slqs : public __base::elem {
                public:
                    slqs(void);
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
                    slqs(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    slqs(dnvgl::extfem::fem::cards::gelref1 const*);
                    slqs(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Semiloof Triangular Curved Thin Shell (24 d.o.fs)
                 */
                class slts : public __base::elem {
                public:
                    slts(void);
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
                    slts(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    slts(dnvgl::extfem::fem::cards::gelref1 const*);
                    slts(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** Semiloof Curved Beam (11 d.o.fs)
                 */
                class slcb : public __base::elem {
                public:
                    slcb(void);
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
                    slcb(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    slcb(dnvgl::extfem::fem::cards::gelref1 const*);
                    slcb(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                
#line 328 "/data/tmp/berhol/ExtFEMIO/tools/templates/fem_elements.h"
                /** General Matrix Element with arbitrary no. of nodes (/n/)
                 */
                class matr : public __base::elem {
                public:
                    matr(void);
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
                    matr(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    matr(dnvgl::extfem::fem::cards::gelref1 const*);
                    matr(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex100(void);
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
                    ghex100(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex100(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex100(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex101(void);
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
                    ghex101(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex101(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex101(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex102(void);
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
                    ghex102(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex102(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex102(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex103(void);
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
                    ghex103(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex103(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex103(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex104(void);
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
                    ghex104(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex104(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex104(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex105(void);
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
                    ghex105(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex105(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex105(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex106(void);
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
                    ghex106(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex106(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex106(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex107(void);
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
                    ghex107(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex107(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex107(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex108(void);
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
                    ghex108(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex108(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex108(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex109(void);
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
                    ghex109(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex109(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex109(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex110(void);
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
                    ghex110(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex110(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex110(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex111(void);
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
                    ghex111(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex111(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex111(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex112(void);
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
                    ghex112(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex112(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex112(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex113(void);
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
                    ghex113(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex113(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex113(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex114(void);
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
                    ghex114(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex114(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex114(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex115(void);
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
                    ghex115(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex115(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex115(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex116(void);
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
                    ghex116(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex116(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex116(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex117(void);
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
                    ghex117(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex117(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex117(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex118(void);
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
                    ghex118(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex118(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex118(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex119(void);
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
                    ghex119(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex119(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex119(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex120(void);
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
                    ghex120(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex120(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex120(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex121(void);
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
                    ghex121(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex121(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex121(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex122(void);
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
                    ghex122(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex122(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex122(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex123(void);
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
                    ghex123(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex123(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex123(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex124(void);
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
                    ghex124(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex124(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex124(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex125(void);
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
                    ghex125(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex125(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex125(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex126(void);
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
                    ghex126(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex126(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex126(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex127(void);
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
                    ghex127(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex127(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex127(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex128(void);
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
                    ghex128(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex128(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex128(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex129(void);
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
                    ghex129(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex129(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex129(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex130(void);
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
                    ghex130(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex130(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex130(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex131(void);
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
                    ghex131(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex131(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex131(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex132(void);
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
                    ghex132(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex132(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex132(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex133(void);
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
                    ghex133(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex133(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex133(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex134(void);
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
                    ghex134(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex134(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex134(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex135(void);
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
                    ghex135(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex135(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex135(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex136(void);
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
                    ghex136(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex136(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex136(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex137(void);
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
                    ghex137(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex137(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex137(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex138(void);
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
                    ghex138(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex138(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex138(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex139(void);
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
                    ghex139(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex139(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex139(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex140(void);
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
                    ghex140(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex140(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex140(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex141(void);
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
                    ghex141(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex141(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex141(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex142(void);
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
                    ghex142(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex142(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex142(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex143(void);
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
                    ghex143(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex143(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex143(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex144(void);
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
                    ghex144(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex144(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex144(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex145(void);
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
                    ghex145(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex145(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex145(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex146(void);
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
                    ghex146(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex146(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex146(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex147(void);
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
                    ghex147(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex147(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex147(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex148(void);
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
                    ghex148(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex148(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex148(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex149(void);
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
                    ghex149(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex149(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex149(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex150(void);
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
                    ghex150(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex150(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex150(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex151(void);
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
                    ghex151(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex151(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex151(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex152(void);
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
                    ghex152(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex152(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex152(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex153(void);
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
                    ghex153(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex153(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex153(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex154(void);
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
                    ghex154(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex154(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex154(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex155(void);
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
                    ghex155(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex155(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex155(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex156(void);
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
                    ghex156(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex156(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex156(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex157(void);
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
                    ghex157(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex157(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex157(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex158(void);
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
                    ghex158(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex158(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex158(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex159(void);
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
                    ghex159(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex159(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex159(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex160(void);
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
                    ghex160(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex160(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex160(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex161(void);
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
                    ghex161(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex161(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex161(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex162(void);
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
                    ghex162(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex162(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex162(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    ghex163(void);
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
                    ghex163(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    ghex163(dnvgl::extfem::fem::cards::gelref1 const*);
                    ghex163(__base::elem const*);
                    virtual long nnodes(void) const;
                    el_types get_type(void) const;
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
                    dnvgl::extfem::fem::elements::el_types const);
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