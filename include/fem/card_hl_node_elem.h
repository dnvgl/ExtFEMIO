/**
   \file card_hl_node_elem.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Nodal Data and Element Geometry Definition (Higher Level Data).

   Detailed description
*/

// ID: $Id$

#pragma once

#ifndef _FEM_HL_NODE_ELEM
#define _FEM_HL_NODE_ELEM

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
/// `GELMNT2`: Subelement Description with Simple Correspondence
//             between Degrees of Freedom of Subelement and Relevant
//             Assembly
/**
   ## Format

   |           |         |             |         |         |
   | --------- | ------- | ----------- | ------- | ------- |
   | `GELMNT2` | `SUBNO` | `SLEVEL`    | `STYPE` | `ADDNO` |
   |           | `T11`   | `T21`       | `T31`   | `T12`   |
   |           | `T22`   | `T32`       | `T13`   | `T23`   |
   |           | `T33`   | `T14`       | `T24`   | `T34`   |
   |           | `NNOD`  | `NOD1`      | `NOD2`  | ...     |
   |           | ...     | `NOD(NNOD)` |         |         |
*/
                class gelmnt2 : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_SUBNO;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_SLEVEL;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_STYPE;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ADDNO;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_T;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NNOD;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NOD;

                public:
 /** Subelement number within the relevant assembly which this
     superelement is part of.
 */
                    long SUBNO;
/** Superelement level. Should be identical to `SLEVEL` on the `IDENT`
    record for this subelement.
*/
                    long SLEVEL;
/** Superelement type of the subelement in question.
 */
                    long STYPE;
/** Additional data type number, i.e. reference number referring to
    additional data specifications.
*/
                    long ADDNO;
/** General transformation matrix.
      \f[
      \left[
      \begin{array}{c}
      x' \\ y' \\ z' \\ 1
      \end{array}
      \right] = \left[
      \begin{array}{cccc}
      T_{11}& T_{12}& T_{13}& T_{14}\                   \
      T_{21}& T_{22}& T_{23}& T_{24}\                   \
      T_{31}& T_{32}& T_{33}& T_{34}\                   \
      0& 0& 0& 1
      \end{array}
      \right] \times \left[
      \begin{array}{c}
      x \\ y \\ z \\ 1
      \end{array}
      \right]
      \f]
      were
      \f[
      \left[
      \begin{array}{c}
      x' \\ y' \\ z'
      \end{array}
      \right] = \text{subelement coordinate system,}
      \left[
      \begin{array}{c}
      x \\ y \\ z
      \end{array}
      \right] = \text{assembly coordinate system}
      \f]

      \image latex gelmnt2_T.eps "Subelement and assembly coordinate system"
      \image html gelmnt2_T.svg "Subelement and assembly coordinate system"

      The 9 terms (cosines) of the first submatrix are due to a
      possible rotation and/or mirroring of the subelement in
      question.

      The three terms of the second submatrix are the coordinates of
      the origin of the global (assembly) coordinate system in the
      local coordinate system.
*/
                    double T[4][4];
/** Number of nodes of the subelement in question.
 */
                    long NNOD;
/** Node numbers of the subelement in question.

    @note The sequence of the nodes defined on this record must be in
    ascending order of the internal node numbers of the supernodes on
    the level below. If this is not the case the coupling of the
    superelements will be wrong.
*/
                    std::vector<long> NOD;

                    gelmnt2(std::vector<std::string> const&, size_t const);

                    gelmnt2(void);

                    gelmnt2(
                        long const SUBNO, long const SLEVEL, long const STYPE,
                        long const ADDNO, const double T[4][4], long const NNOD,
                        std::vector<long> const &NOD);

                    gelmnt2(
                        long const SUBNO, long const SLEVEL, long const STYPE,
                        long const ADDNO, double const T[4][4],
                        std::vector<long> const &NOD);

                    gelmnt2(
                        long const SUBNO, long const SLEVEL, long const STYPE,
                        long const ADDNO, double const T11, double const T21,
                        double const T31, double const T12, double const T22,
                        double const T32, double const T13, double const T23,
                        double const T33, double const T14, double const T24,
                        double const T34, long const NNOD,
                        std::vector<long> const &NOD);

                    gelmnt2(
                        long const SUBNO, long const SLEVEL, long const STYPE,
                        long const ADDNO, double const T11, double const T21,
                        double const T31, double const T12, double const T22,
                        double const T32, double const T13, double const T23,
                        double const T33, double const T14, double const T24,
                        double const T34, std::vector<long> const &NOD);

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

#endif // _FEM_HL_NODE_ELEM

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
