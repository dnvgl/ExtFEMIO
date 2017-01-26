/**
  \file cards_bounds.h
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2017 by DNV GL SE
  \brief Boundary Conditions, Loads and Point Masses.

  Detailed description
*/

// ID: $Id$

#pragma once

#ifndef _FEM_CARDS_BOUNDS_H_
#define _FEM_CARDS_BOUNDS_H_

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
/// `BELFIX`: Flexible Joint/Hinge
/**
   ## Format:

   |          |         |        |         |        |
   | -------- | ------- | ------ | ------- | ------ |
   | `BELFIX` | `FIXNO` | `OPT`  | `TRANO` | *void* |
   |          | `A(1)`  | `A(2)` | `A(3)`  | `A(4)` |
   |          | `A(5)`  | `A(6)` |         |        |
*/
                class belfix : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_FIXNO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_OPT;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_TRANO;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_A;

                public:

                    enum class n_opt {
                        INVALID = -1,
                        FIXATION = 1, SPRING = 2,
                        FIXATION_END = 3, SPRING_END = 4}_opt;

/** Fixation number to a node.

    =FIXNO= is referenced to from =GELREF=.
*/
                    long FIXNO;
/**
      =FIXATION: A(i) = ai is a value between 0 and 1, and gives the
          degree of fixation (connectivity) to degree of freedom
          number i in the node. The extreme values of a is described
          by:

            a = 0, fully released

            a = 1, fully connected

      =SPRING: A(i) = Ci is the interelement elastic spring stiffness
          to degree of freedom number i in the node. The degrees of
          freedom which are neither flexible nor free will be given Ci
          = -1(instead of Ci = ∞). The relation between Ci and ai is

            ai = Ci /( kii + Ci) ≥ 0.0

          where kii is the diagonal term of the element stiffness
          matrix corresponding to degree of freedom number i of the
          current node.

      =FIXATION_END: As =OPT=FIXATION=, where the hinge is located at
          the end of the beam — and not at the node as for
          =OPT=FIXATION=. This option is thus relevant for eccentric
          beams.

      =SPRING_END: As =OPT=SPRING=, where the hinge is located at the
          end of the beam — and not at the node as for =OPT=SPRING=.
          This option is thus relevant for eccentric beams.
*/
                    n_opt OPT;
/**
      = -1: The fixation/flexibility(=A(i)) is given in the
          superelement coordinate system.

      =0: A(i) is given in the local element coordinate system

      >0: A(i) is given in a local coordinate system defined by
          `TRANO`, which refers to a transformation matrix given on
          record `BNTRCOS`. The transformation matrix is defined by
          transformation from global to local system.
*/
                    long TRANO;
/** See above(under the explanation of `OPT`).
 */
                    std::vector<double> A;

                    belfix(std::vector<std::string> const&, size_t const);

                    belfix(void);

                    belfix(long const FIXNO, n_opt const OPT, long const TRANO,
                           std::vector<double> const &A);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                    std::string pos_string(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };

/// `BEUSLO`: Elements with Surface Loads
/**
   ## Format

   |          |               |          |          |               |
   | -------- | ------------- | -------- | -------- | ------------- |
   | `BEUSLO` | `LLC`         | `LOTYP`  | `COMPLX` | `LAYER`       |
   |          | `ELNO`        | `NDOF`   | `INTNO`  | `SIDE`        |
   |          | `RLOAD1`      | `RLOAD2` | ...      | ...           |
   |          | `RLOAD(NDOF)` | `ILOAD1` | ...      | `ILOAD(NDOF)` |

   If phase shift is not specified, i.e. `COMPLX` = 0, the fields or
   positions `ILOAD1`, `ILOAD2`, etc. are left out.

   Normal pressure means that only one pressure component is specified
   for each node, and this pressure component is acting normal to the
   surface.

   For volume elements a positive value means normal pressure directed
   into the element. For shell elements, a positive value means normal
   pressure in the local /z/-direction.
*/
                class beuslo : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LLC;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LOTYP;
                    dnvgl::extfem::fem::types::entry_type<bool>
                    static const _form_COMPLX;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LAYER;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ELNO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDOF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_INTNO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_SIDE;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_RLOAD;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_ILOAD;


                public:

/** Local load case number (positive integer number).
 */
                    long LLC;
/** Load type.

      - =1: normal pressure, conservative load

      - =2: load given in component form, conservative load

      - =3: dummy hydro pressure, used to indicate the direction of
        hydrostatic / hydrodynamic pressure to be computed by a
        hydrodynamic load program.

      - =-1: normal pressure, non-conservative load

      - =-2: load given in component form, non-conservative load
*/
                    long LOTYP;
/** Phase shift definition.

      - =0: no phase shift

      - =1: phase shift
*/
                    bool COMPLX;
/** Layer number for elements with more than one layer. If `LAYER`
    equals 0, the surface load will be positioned in the shell layer
    (in opposition to a stiffener layer). If more than one shell layer
    and `LAYER` equals 0, the programs shall stop and give an error
    message. For elements which are treated as one layer in the load
    calculations (e.g. the sandwich element in SESTRA), `LAYER` does
    not have any meaning.
*/
                    long LAYER;
/** Internal element number (generated by the program).
 */
                    long ELNO;
/**
     - If `LOTYP` = 1: number of nodes of the specified element side

     - If `LOTYP` = 2: number of translational degrees of freedom of
       the specified element side

     - If `LOTYP` = 3: `NDOF` = 1
*/
                    long NDOF;
/** Integration station reference number. Referring to record
    `GELINT`. This reference is usually not used (=0). It means that
    the program performing the load calculation chooses integration
    points.
*/
                    long INTNO;
/** Side definition

    For shell elements:

      - =1: loads referred to element side where /z/=-1

      - =2: loads referred to element side where /z/= 0

      - =3: loads referred to element side where /z/= 1

    For solid elements:

    `SIDE` will be a six figures number for a hexahedron, a five
    figures number for a prism and a four figures number for a
    tetrahedron, consisting of zeroes with 1 for the side with load.
    For instance 000100 for a hexahedron means load on side no. 4.
*/
                    long SIDE;
/** The real part of the load with respect to the /i/th degree of
    freedom or /i/th node of the element side.
*/
                    std::vector<double> RLOADi;
/** The imaginary part of the load with respect to the /i/th degree of
    freedom or /i/th node of the element side.

    If `LOTYP`= 3, `RLOAD`= ±1.0 indicating which side the element
    pressure comes from. (+1 indicates shell element `SIDE`= 1
    (/z/=-1), -1 indicates shell element `SIDE`= 3 (/z/=1)). For
    solids when `LOTYP` = 3, `RLOAD` must be +1.0.
*/
                    std::vector<double> ILOADi;

                    beuslo(void);

                    beuslo(std::vector<std::string> const&, size_t const);

                    beuslo(
                        long const LLC, long const LOTYP, bool const COMPLX,
                        long const LAYER, long const ELNO, long const NDOF,
                        long const INTNO, long const SIDE,
                        std::vector<double> const &RLOAD,
                        std::vector<double> const &ILOAD = {});

                    beuslo(
                        long const LLC, long const LOTYP, bool const COMPLX,
                        long const LAYER, long const ELNO, long const INTNO,
                        long const SIDE, std::vector<double> const &RLOAD,
                        std::vector<double> const &ILOAD = {});

                    beuslo(
                        long const LLC, long const LOTYP, long const LAYER,
                        long const ELNO, long const NDOF, long const INTNO,
                           long const SIDE, std::vector<double> const &RLOAD,
                           std::vector<double> const &ILOAD = {});

                    beuslo(long const LLC, long const LOTYP, long const LAYER,
                           long const ELNO, long const INTNO, long const SIDE,
                           std::vector<double> const &RLOAD,
                           std::vector<double> const &ILOAD = {});

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        const std::vector<std::string>&, size_t const);
                };

/// `BLDEP`: Nodes with Linear Dependence
/**
   ## Format:

   |         |                           |                             |                             |        |
   | ------- | ------------------------- | --------------------------- | --------------------------- | ------ |
   | `BLDEP` | `NODENO`                  | `CNOD`                      | `NDDOF`                     | `NDEP` |
   |         | `DEPDOF`<sub>`1`</sub>    | `INDEPDOF`<sub>`1`</sub>    | `b`<sub>`DEP1,INDEP1`</sub> |        |
   |         | `DEPDOF`<sub>`2`</sub>    | `INDEPDOF`<sub>`2`</sub>    | `b`<sub>`DEP2,INDEP2`</sub> |        |
   |         | ...                       | ...                         | ...                         |        |
   |         | `DEPDOF`<sub>`NDEP`</sub> | `INDEPDOF`<sub>`NDEP`</sub> | `b`<sub>`DEPn,INDEPn`</sub> |        |

   Each line specifies one dependent degree of freedom which is dependent
   on the independent node’s specified degree of freedom with the
   factor *b<sub>i,j</sub>*. The degrees of freedom must also be specified on
   `BNBCD`-records as linear dependent(3) for the dependent node, and as
   retained(4) for the independent node.

   A node may be dependent on many nodes. For each combination of
   `NODENO` and `CNOD` a new record, starting with the identifier
   `BLDEP`, is given.

   The same combination of `NODENO` and `CNOD` may occur only once.

   When node transformations have been specified for any of the nodes
   implied in the linear dependence, the degrees of freedom refers to the
   transformed local coordinate system.

   Multipoint constraints(2nd and higher order dependence) may be
   specifed through more `BLDEP` records with the same linear dependent
   node and different independent nodes. The factors *b<sub>i,j</sub>*
   may be found as Lagrange multiplicators or coefficients(Lagrange
   interpolation polynomial). For 2nd order dependence this may as well
   be specified on one BQDP record.
*/
                class bldep : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NODENO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_CNOD;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDDOF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDEP;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_DEPDOF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_INDEPDOF;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_b;

                public:

/** Internal node number of the dependent node.
 */
                    long NODENO;
/** Internal node number of an independent node.
 */
                    long CNOD;
/** Number of dependent degrees of freedom of node `NODENO`. When not
    specified, `NDDOF` is equal to `NDEP`.
*/
                    long NDDOF;
/** Number of triplets with `DEPDOF`, `INDEPDOF` and
    `b`<sub>*i,j*</sub>
*/
                    long NDEP;
/** Dependent node’s degree of freedom.
 */
                    std::vector<long> DEPDOF;
/** Independent node’s degree of freedom.
 */
                    std::vector<long> INDEPDOF;
 /** The contribution of the *j*’th degree of freedom of the
     independent node to the *i*’th degree of freedom of the dependent
     node.
 */
                    std::vector<double> b;

                    bldep(std::vector<std::string> const&, size_t const);

                    bldep(void);

                    bldep(long const NODENO, long const CNOD, long const NDDOF,
                          long const NDEP, std::vector<long> const &DEPDOF,
                          std::vector<long> const &INDEPDOF,
                          std::vector<double> const &b);

                    bldep(long const NODENO, long const CNOD, long const NDDOF,
                          std::vector<long> const &DEPDOF,
                          std::vector<long> const &INDEPDOF,
                          std::vector<double> const &b);

                    bldep(long const NODENO, long const CNOD,
                          std::vector<long> const &DEPDOF,
                          std::vector<long> const &INDEPDOF,
                          std::vector<double> const &b);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };

/// `BNBCD`: Nodes with Boundary Conditions
/**
   ## Format:

   |         |          |        |                        |                     |
   | ------- | -------- | ------ | ---------------------- | ------------------- |
   | `BNBCD` | `NODENO` | `NDOF` | `FIX`<sub>`1`</sub>    | `FIX`<sub>`2`</sub> |
   |         | ...      | ...    | `FIX`<sub>`NDOF`</sub> |                     |

   The codes of `FIX`<sub>`1`</sub>, `FIX`<sub>`2`</sub>, ...,
   `FIX`<sub>`NDOF`</sub> are:

   =0: free to stay

   =1: fixed at zero displacement, temperature, etc.

   =2: prescribed displacement, temperature, different from zero

   =3: linearly dependent

   =4: retained degree of freedom.

   The code `FIX` = 2 just indicates specified condition for the relevant
   degree of freedom. Whether it is displacement, first time derivative
   of the displacement etc. is defined on the `BNDISPL` record. Degrees
   of freedom with `FIX` = 2 which are not defined on the `BNDISPL`
   record will be fixed(have zero displacement, velocity and
   acceleration).

   The nodes(degrees of freedom) with `FIX` = 4 are called supernodes
   (super degrees of freedom). The supernode sequence numbering is
   according to the increasing order of their internal node number.
*/
                class bnbcd : public __base::card {

                public:

                    enum class fix_key : int {
                        INVALID = -1,
/// free to stay
                        FREE = 0,
/// fixed at zero displacement, temperature, etc.
                        DISPL_FIX = 1,
/// prescribed displacement, temperature, different from zero
                        PRESCRIBED = 2,
/// linearly dependent
                        LINDEP = 3,
/// restrained degree of freedom
                        RETAINED = 4};

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NODENO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDOF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_FIX;

                    fix_key const fix_key_conv(long const) const;
                    fix_key const fix_key_conv(bool const) const;
                    long const fix_key_conv(fix_key const) const;

                public:

/** Internal node number of nodes with specified boundary condition.
 */
                    long NODENO;
/** Number of degrees of freedom.
 */
                    long NDOF;
/** Specification of boundary condition codes of relevant degrees of
    freedom.
*/
                    std::vector<fix_key> FIX;

                    bnbcd(std::vector<std::string> const&, size_t const);

                    bnbcd(void);

                    bnbcd(long const NODENO, long const NDOF,
                          std::vector<fix_key> const &FIX);

                    bnbcd(long const NODENO,
                          std::vector<fix_key> const &FIX);

                    bnbcd(long const NODENO,
                          fix_key const FIX1, fix_key const FIX2,
                          fix_key const FIX3, fix_key const FIX4,
                          fix_key const FIX5, fix_key const FIX6);

                    bnbcd(long const NODENO,
                          bool const FIX1, bool const FIX2,
                          bool const FIX3, bool const FIX4,
                          bool const FIX5, bool const FIX6);

                    using __base::card::operator();

                    __base::card const &operator()(
                        long const NODENO,
                        long const NDOF,
                        std::vector<fix_key> const &FIX);

                    __base::card const &operator()(
                        long const NODENO,
                        std::vector<fix_key> const &FIX);

                    __base::card const &operator()(
                        long const NODENO,
                        fix_key const FIX1, fix_key const FIX2,
                        fix_key const FIX3, fix_key const FIX4,
                        fix_key const FIX5, fix_key const FIX6);

                    __base::card const &operator()(
                        long const NODENO,
                        bool const FIX1, bool const FIX2,
                        bool const FIX3, bool const FIX4,
                        bool const FIX5, bool const FIX6);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(std::vector<std::string> const&, size_t const);
                };

/// `BNDISPL`: Nodes with Prescribed Displacements and Accelerations
/**
   ## Format:

   |           |                       |                          |                       |                          |
   | --------- | --------------------- | ------------------------ | --------------------- | ------------------------ |
   | `BNDISPL` | `LLC`                 | `DTYPE`                  | `COMPLEX`             |                          |
   |           | `NODENO`              | `NDOF`                   | `RDISP`<sub>`1`</sub> | `RDISP`<sub>`2`</sub>    |
   |           | ...                   | ...                      | ...                   | `RDISP`<sub>`NDOF`</sub> |
   |           | `IDISP`<sub>`1`</sub> | `IDISP`<sub>`2`</sub>    | ...                   | ...                      |
   |           | ...                   | `IDISP`<sub>`NDOF`</sub> |                       |                          |

   `RDISP` and `IDISP` refer to the transformed coordinate system if the
   node `NODENO` is transformed, else to the global coordinate system of
   the superelement.

   The imaginary numbers follow immediately after the real numbers, i.e.
   there are no blank fields between the last real part and the first
   imaginary part.

   If phase shift is not specified, the fields or positions
   `IDISP`<sub>`1`</sub>, `IDISP`<sub>`2`</sub>, etc. are left out.
*/
                class bndispl : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LLC;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_DTYPE;
                    dnvgl::extfem::fem::types::entry_type<bool>
                    static const _form_COMPLX;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NODENO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDOF;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_RDISP;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_IDISP;

                public:

/** Local load case number(positive integer number).
 */
                    long LLC;
/** Type of boundary condition.

      =1: specified displacement

      =3: specified acceleration
*/
                    long DTYPE;
/** Phase shift definition.

      =false: no phase shift

      =true: phase shift
*/
                    bool COMPLX;
/** Program defined node number.
 */
                    long NODENO;
/** Number of degrees of freedom at the node NODENO.
 */
                    long NDOF;
/** The real part of the specified boundary condition with respect to
    the rspt. degree of freedom.
*/
                    std::vector<double> RDISP;
/** The imagenary part of the specified boundary condition with
    respect to the rspt. degree of freedom.
*/
                    std::vector<double> IDISP;

                    bndispl(std::vector<std::string> const&, size_t const);

                    bndispl(void);

                    bndispl(long const LLC, long const DTYPE, bool const COMPLX,
                            long const NODENO, long const NDOF,
                            std::vector<double> const &RDISP,
                            std::vector<double> const &IDISP={});

                    bndispl(long const LLC, long const DTYPE, bool const COMPLX,
                            long const NODENO, std::vector<double> const &RDISP,
                            std::vector<double> const &IDISP={});

                    bndispl(long const LLC, long const DTYPE, long const NODENO,
                            long const NDOF, std::vector<double> const &RDISP,
                            std::vector<double> const &IDISP={});

                    bndispl(long const LLC, long const DTYPE, long const NODENO,
                            std::vector<double> const &RDISP,
                            std::vector<double> const &IDISP={});

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };

/// `BNLOAD`: Nodes with Loads
/**
   ## Format:

   |          |                          |                         |                          |                       |
   | -------- | ------------------------ | ----------------------- | ------------------------ | --------------------- |
   | `BNLOAD` | `LLC`                    | `LOTYP`                 | `COMPLEX`                |                       |
   |          | `NODENO`                 | `NDOF`                  | `RLOAD`<sub>`1`</sub>    | `RLOAD`<sub>`2`</sub> |
   |          | ...                      | ...                     | `RLOAD`<sub>`NDOF`</sub> | `ILOAD`<sub>`1`</sub> |
   |          | `ILOAD`<sub>`2`</sub>    | ...                     | ...                      | ...                   |
   |          | `ILOAD`<sub>`NDOF`</sub> |                         |                          |                       |

   The imaginary numbers follow immediately after the real numbers, i.e.
   there are no blank fields between the last real part and the first
   imaginary part.

   If phase shift is not specified, i.e. `COMPLX` == false, the fields or
   positions `ILOAD`<sub>`1`</sub>, `ILOAD`<sub>`2`</sub>, etc. are left
   out.
*/
                class bnload : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LLC;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LOTYP;
                    dnvgl::extfem::fem::types::entry_type<bool>
                    static const _form_COMPLX;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NODENO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NDOF;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_RLOAD;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_ILOAD;

                public:

/** Local load case number(positive integer number).
 */
                    long LLC;
/** Load type at node `NODENO`. Usually not of interest to linear
    programs.

      =0: not decided whether conservative or non-conservative load

      =1: conservative load

      =-1: non-conservative load
*/
                    long LOTYP;
/** Phase shift definition.

      =false: no phase shift

      =true: phase shift
*/
                    bool COMPLX;
/** Program defined node number.
 */
                    long NODENO;
/** Number of degrees of freedom at the node NODENO.
 */
                    long NDOF;
/** The real part of the load with respect to the rspt. degree of
    freedom.
*/
                    std::vector<double> RLOAD;
/** The imaginary part of the load with respect to the rspt. degree of
    freedom.(Only if `COMPLX` == true).
*/
                    std::vector<double> ILOAD;

                    bnload(std::vector<std::string> const&, size_t const);

                    bnload(void);

                    bnload(long const LLC, long const LOTYP, bool const COMPLX,
                           long const NODENO, long const NDOF,
                           std::vector<double> const &RLOAD,
                           std::vector<double> const &ILOAD={});

                    bnload(long const LLC, long const LOTYP, bool const COMPLX,
                           long const NODENO, std::vector<double> const &RLOAD,
                           std::vector<double> const &ILOAD={});

                    bnload(long const LLC, long const LOTYP, long const NODENO,
                           long const NDOF, std::vector<double> const &RLOAD,
                           std::vector<double> const &ILOAD={});

                    bnload(long const LLC, long const LOTYP, long const NODENO,
                           std::vector<double> const &RLOAD,
                           std::vector<double> const &ILOAD={});

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
                };

/// `BSELL`: Subelement Load Description
/**
   ## Format

   |         |        |         |        |         |
   | ------- | ------ | ------- | ------ | ------- |
   | `BSELL` | `LC`   | `SUBNO` |        |         |
   |         | `LLC1` | `FACT1` | `LLC2` | `FACT2` |
   |         | ...    | ...     | `LLCN` | `FACTN` |
*/
                class bsell : public __base::card {


                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LC;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_SUBNO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LLC;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_FACT;

                public:

/** Global load case number (positive integer number).
 */
                    long LC;
/** Subelement number of the superelement in question.
 */
                    long SUBNO;
/** Local load cases included in the global load case LC.
 */
                    std::vector<long> LLC;
/** Scaling factors for the local load cases.
 */
                    std::vector<double> FACT;

                    bsell(std::vector<std::string> const&, size_t const);

                    bsell(void);

                    bsell(long const LC, long const SUBNO,
                          std::vector<long> const &LLC,
                          std::vector<double> const &FACT);

                    using __base::card::operator();

                    __base::card const &operator()(
                        long const LC, long const SUBNO,
                        std::vector<long> const &LLC,
                        std::vector<double> const &FACT);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        const std::vector<std::string>&, size_t const);
                };
            }
        }
    }
}

#endif // _FEM_CARDS_BOUNDS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test""
// coding: utf-8
// End:
