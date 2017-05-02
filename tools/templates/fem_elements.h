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

#pragma once

{% line %}

#ifndef _FEM_ELEMENTS_H_
#define _FEM_ELEMENTS_H_

#if (__GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))) || \
    (_MSC_VER && _MSC_VER <= 1700)
#include "my_c++14.h"
#endif

#include <set>

{% line %}

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
                    {% for name, val in enums %}{{ name }} = {{ val }},
                    {% line %}
                    {% endfor %}INVALID=-1, UNDEFINED=-2};
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

                        long static get_eleno();
                        long static get_eleno(long const eleno);
                        long static get_elident();
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

                        explicit elem(dnvgl::extfem::fem::cards::gelmnt1 const*);

                        explicit elem(dnvgl::extfem::fem::cards::gelref1 const*);

                        explicit elem(elem const*);

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

                        virtual void add(dnvgl::extfem::fem::cards::gelref1 const*);
                        virtual void add(dnvgl::extfem::fem::cards::gelmnt1 const*);

                        virtual long nnodes() const = 0;

                        virtual el_types get_type() const = 0;

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
                    undef () = default;
                    explicit undef(dnvgl::extfem::fem::cards::gelref1 const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                };
                {% for elem, vals in elements %}
{% line %}
                /** {{ vals.doc }}
                 */
                class {{ elem }} : public __base::{{ vals.base }} {
                public:
                    {{ elem }}() = default;
                    {{ elem }}(
                        long const eleno, long const elident, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    {{ elem }}(
                        long const eleno, long const el_add,
                        std::vector<long> const &nodes, long const matref,
                        long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    {{ elem }}(
                        long const el_add, std::vector<long> const &nodes,
                        long const matref, long const add_no, long const intno,
                        long const mass_intno, long const i_strain_ref,
                        long const i_stressef, long const strpoint_ref,
                        std::vector<long> const &sections={},
                        std::vector<long> const &fixations={},
                        std::vector<long> const &eccentrities={},
                        std::vector<long> const &csys={});
                    explicit {{ elem }}(dnvgl::extfem::fem::cards::gelmnt1 const*);
                    explicit {{ elem }}(dnvgl::extfem::fem::cards::gelref1 const*);
                    explicit {{ elem }}(__base::elem const*);
                    long nnodes() const override;
                    el_types get_type() const override;
                    std::set<el_processor> static const processors;
                    using elem::operator();
                    using elem::add;
                };
                {% endfor %}
{% line %}
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
