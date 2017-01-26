/**
  \file cards_mat.h
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2017 by DNV GL SE
  \brief Material Data.

  Detailed description
*/

// ID: $Id$

#pragma once

#ifndef _FEM_CARDS_MAT_H_
#define _FEM_CARDS_MAT_H_

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
/// `MGSPRNG`: Element to Ground
/**
   ## Format:

   |           |           |        |              |                 |
   | --------- | --------- | ------ | ------------ | --------------- |
   | `MGSPRNG` | `MATNO`   | `NDOF` | `K(1, 1)`    | `K(2, 1)`       |
   |           | ...       | ...    | `K(NDOF, 1)` | `K(2, 2)`       |
   |           | `K(3, 2)` | ...    | ...          | `K(NDOF, 2)`    |
   |           | `K(3, 3)` | ...    | ...          | `K(NDOF, NDOF)` |

   The(*i*, *j*)’th element of the stiffness matrix corresponds to the
   force to be given in the *i*’th d.o.f. to get a unit displacement in
   the *j*’th d.o.f.
*/
                class mgsprng : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_MATNO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDOF;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_K;

                public:

/** Material number, i.e. reference number referenced to by the
    element specification.
*/
                    long MATNO;
/** Number of degrees of freedom of the node.
 */
                    long NDOF;
/** Elements of the stiffness matrix(only elements on and below the
    main diagonal are stored, i.e. symmetric stiffness matrix
    assumed). The elements are referred to a local coordinate system
    if defined(by `TRANSNO` on `GELREF1`), otherwise to the global
    coordinate system of the superelement.
*/
                    std::vector<std::vector<double> > K;

                    mgsprng(std::vector<std::string> const&, size_t const);

                    mgsprng(void);

                    mgsprng(long const MATNO,
                            long const NDOF,
                            std::vector<std::vector<double> > const &K);

                    mgsprng(long const MATNO,
                            std::vector<std::vector<double> > const &K);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };

/// `MISOSEL`: Isotropy, Linear Elastic Structural Analysis
/**
   ## Format:

   |           |         |         |         |         |
   | --------- | ------- | ------- | ------- | ------- |
   | `MISOSEL` | `MATNO` | `YOUNG` | `POISS` | `RHO`   |
   |           | `DAMP`  | `ALPHA` | `DUMMY` | `YIELD` |
*/
                class misosel : public  __base::material {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    // dnvgl::extfem::fem::types::entry_type<long>
                    // static const _form_MATNO;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_YOUNG;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_POISS;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_RHO;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_DAMP;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_ALPHA;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_DUMMY;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_YIELD;

                public:
// /* Material number, i.e. reference number referenced to by the element
//    specification.
// */
//                     long MATNO;
/** Young’s modulus.
 */
                    double YOUNG;
/** Poisson’s ratio.
 */
                    double POISS;
/** Density.
 */
                    double RHO;
/** Specific damping.
 */
                    double DAMP;
/** Thermal expansion coefficient.
 */
                    double ALPHA;
/** *Unknown value, not documented!!*
 */
                    double DUMMY;
/** Yield stress value for this material.
 */
                    double YIELD;

                    misosel(std::vector<std::string> const&, size_t const);

                    misosel(void);

                    misosel(long const MATNO,
                            double const YOUNG,
                            double const POISS,
                            double const RHO,
                            double const DAMP,
                            double const ALPHA,
                            double const DUMMY=0.,
                            double const YIELD=0.);

                    using material::operator();

                    virtual __base::card const &operator() (
                        std::vector<std::string> const&, size_t const);

                    __base::card const &operator()(
                        long const MATNO,
                        double const YOUNG,
                        double const POISS,
                        double const RHO,
                        double const DAMP,
                        double const ALPHA,
                        double const DUMMY=0.,
                        double const YIELD=0.);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };

/// `MORSMEL`: Anisotropy, Linear Elastic Structural Analysis,
///            2-D Membrane Elements and 2-D Thin Shell Elements
/**
   ## Format:

   |           |          |         |         |          |
   | --------- | -------- | ------- | ------- | -------- |
   | `MORSMEL` | `MATNO`  | `Q1`    | `Q2`    | `Q3`     |
   |           | `RHO`    | `D11`   | `D21`   | `D22`    |
   |           | `D31`    | `D32`   | `D33`   | `PS1`    |
   |           | `PS2`    | `DAMP1` | `DAMP2` | `ALPHA1` |
   |           | `ALPHA2` |         |         |          |

   @note The vector Q must not be perpendicular to any of the elements
*/
                class morsmel : public  __base::material {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    // dnvgl::extfem::fem::types::entry_type<long>
                    // static const _form_MATNO;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_Q1;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_Q2;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_Q3;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_RHO;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_D11;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_D21;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_D22;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_D31;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_D32;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_D33;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_PS1;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_PS2;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_DAMP1;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_DAMP2;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_ALPHA1;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_ALPHA2;

                public:

// /* Material number. Reference number referenced to by the element
//    specification. */
//                     long MATNO;
/** First component of global components of a vector Q indicating axes
    of anisotropy. The first principal axis of anisotropy is referred
    to the projection of Q on the membrane plane.
*/
                    double Q1;
/** Second component of global components of a vector Q indicating
    axes of anisotropy. The first principal axis of anisotropy is
    referred to the projection of Q on the membrane plane.
*/
                    double Q2;
/** Third component of global components of a vector Q indicating axes
    of anisotropy. The first principal axis of anisotropy is referred
    to the projection of Q on the membrane plane.
*/
                    double Q3;
/** Density
 */
                    double RHO;
/** Component of the lower triangular part of the general anisotropic
    elasticity matrix.

    In case of orthotropy, only D11, D21, D22 and D33 are nonzero.
*/
                    double D11;
/** Component of the lower triangular part of the general anisotropic
    elasticity matrix.
*/
                    double D21;
/** Component of the lower triangular part of the general anisotropic
    elasticity matrix.
*/
                    double D22;
/** Component of the lower triangular part of the general anisotropic
    elasticity matrix.
*/
                    double D31;
/** Component of the lower triangular part of the general anisotropic
    elasticity matrix.
*/
                    double D32;
/** Component of the lower triangular part of the general anisotropic
    elasticity matrix.
*/
                    double D33;
/** Only given for plane strain situation. The stress normal to the
    membrane plane(sn) is calculated as follows: sn = PS1·s1 + PS2·s2

    (For an isotropic material PS1 and PS2 equal Poisson’s ratio)
*/
                    double PS1;
/** Only given for plane strain situation. The stress normal to the
    membrane plane(sn) is calculated as follows: sn = PS1·s1 + PS2·s2

    (For an isotropic material PS1 and PS2 equal Poisson’s ratio)
*/
                    double PS2;
/** Specific damping along the 1. principal axis of anisotropy.
 */
                    double DAMP1;
/** Specific damping along the 2. principal axis of anisotropy.
 */
                    double DAMP2;
/** Thermal expansion coefficients along the 1. principal axis of
    anisotropy.
*/
                    double ALPHA1;
/** Thermal expansion coefficients along the 1. principal axis of
    anisotropy.
                    */
                    double ALPHA2;

                    morsmel(std::vector<std::string> const&, size_t const);

                    morsmel(void);

                    morsmel(long const MATNO,
                            double const Q1,
                            double const Q2,
                            double const Q3,
                            double const RHO,
                            double const D11,
                            double const D21,
                            double const D22,
                            double const D31,
                            double const D32,
                            double const D33,
                            double const PS1,
                            double const PS2,
                            double const DAMP1,
                            double const DAMP2,
                            double const ALPHA1,
                            double const ALPHA2);

                    virtual __base::card const &operator() (
                        std::vector<std::string> const&, size_t const);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };
            }
        }
    }
}


#endif // _FEM_CARDS_MAT_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test""
// coding: utf-8
// End:
