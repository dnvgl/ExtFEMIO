/**
  \file cards_superele.h
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2016 by DNV GL SE
  \brief Cards describing super elements for Sesam FEM files.

  Detailed description
*/

/* ID: $Id\$
 */

#ifndef _FEM_CARDS_SUPERELE_H_
#define _FEM_CARDS_SUPERELE_H_

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

/// `BSELL`: Subelement Load Description
/**
## Format

|         |        |         |        |         |
| ------- | ------ | ------- | ------ | ------- |
| `BSELL` | `LC`   | `SUBNO` |        |         |
|         | `LLC1` | `FACT1` | `LLC2` | `FACT2` |
|         | ...    | ...     | `LLCN` | `FACTN` |
*/
            class bsell : public card {


               static const dnvgl::extfem::fem::types::card head;

               static const dnvgl::extfem::fem::types::entry_type<long> _form_LC;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_SUBNO;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_LLC;
               static const dnvgl::extfem::fem::types::entry_type<double> _form_FACT;

            public:

               /** Global load case number (positive integer number).
                */
               long LC;
               /** Subelement number of the superelement in question.
               */
               long SUBNO;
               /** Local load cases included in the global load case LC.
                */
               std::deque<long> LLC;
               /** Scaling factors for the local load cases.
               */
               std::deque<double> FACT;

               bsell(const std::deque<std::string>&);

               bsell(const long &LC,
                     const long &SUBNO,
                     const std::deque<long> &LLC,
                     const std::deque<double> &FACT);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, const bsell&);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };


/// `GELMNT2`: Subelement Description with Simple Correspondence
//             between Degrees of Freedom of Subelement and Relevant Assembly
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
            class gelmnt2 : public card {

            private:

               static const dnvgl::extfem::fem::types::card head;

               static const dnvgl::extfem::fem::types::entry_type<long> _form_SUBNO;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_SLEVEL;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_STYPE;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_ADDNO;
               static const dnvgl::extfem::fem::types::entry_type<double> _form_T;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NNOD;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NOD;

            public:
               /** Subelement number within the relevant assembly
                   which this superelement is part of.
                */
               long SUBNO;
               /** Superelement level. Should be identical to `SLEVEL`
                   on the `IDENT` record for this subelement.
                */
               long SLEVEL;
               /** Superelement type of the subelement in question.
                */
               long STYPE;
               /** Additional data type number, i.e. reference number
                   referring to additional data specifications.
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
                         T_{11}& T_{12}& T_{13}& T_{14}\\
                         T_{21}& T_{22}& T_{23}& T_{24}\\
                         T_{31}& T_{32}& T_{33}& T_{34}\\
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

                     The 9 terms (cosines) of the first submatrix are
                     due to a possible rotation and/or mirroring of
                     the subelement in question.

                     The three terms of the second submatrix are the
                     coordinates of the origin of the global
                     (assembly) coordinate system in the local
                     coordinate system.
                */
               double T[4][4];
               /** Number of nodes of the subelement in question.
                */
               long NNOD;
               /** Node numbers of the subelement in question.

                   @note The sequence of the nodes defined on this
                          record must be in ascending order of the
                          internal node numbers of the supernodes on
                          the level below. If this is not the case the
                          coupling of the superelements will be wrong.
               */
               std::deque<long> NOD;

               gelmnt2(const std::deque<std::string>&);

               gelmnt2(const long &SUBNO,
                       const long &SLEVEL,
                       const long &STYPE,
                       const long &ADDNO,
                       const double T[4][4],
                       const long &NNOD,
                       const std::deque<long> &NOD);

               gelmnt2(const long &SUBNO,
                       const long &SLEVEL,
                       const long &STYPE,
                       const long &ADDNO,
                       const double T[4][4],
                       const std::deque<long> &NOD);

               gelmnt2(const long &SUBNO,
                       const long &SLEVEL,
                       const long &STYPE,
                       const long &ADDNO,
                       const double &T11,
                       const double &T21,
                       const double &T31,
                       const double &T12,
                       const double &T22,
                       const double &T32,
                       const double &T13,
                       const double &T23,
                       const double &T33,
                       const double &T14,
                       const double &T24,
                       const double &T34,
                       const long &NNOD,
                       const std::deque<long> &NOD);

               gelmnt2(const long &SUBNO,
                       const long &SLEVEL,
                       const long &STYPE,
                       const long &ADDNO,
                       const double &T11,
                       const double &T21,
                       const double &T31,
                       const double &T12,
                       const double &T22,
                       const double &T32,
                       const double &T13,
                       const double &T23,
                       const double &T33,
                       const double &T14,
                       const double &T24,
                       const double &T34,
                       const std::deque<long> &NOD);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, const gelmnt2&);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `HSUPSTAT`: Superelement Statistical Information
/**
## Format

|            |          |          |          |           |
| ---------- | -------- | -------- | -------- | --------- |
| `HSUPSTAT` | `NFIELD` | `ISELTY` | `NIDOF`  | `NRDOF`   |
|            | `NBAND`  | `NELT`   | `LINDEP` | `RELOADC` |
|            | `COMPLC` |          |          |           |

This record lists statistical information about superelements. All the
`HSUPSTAT` records are written in the highest level (top-level)
T-file. The `HSUPSTAT` record is referenced from the `HIERARCH` record
through the superelement type number (`ISELTY`).

*/
            class hsupstat : public card {

            private:

               static const dnvgl::extfem::fem::types::card head;

               static const dnvgl::extfem::fem::types::entry_type<long> _form_NFIELD;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_ISELTY;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NIDOF;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NRDOF;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NBAND;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NELT;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_LINDEP;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_RELOADC;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_COMPLC;

            public:

               /** No. of data fields on this record (including this
                   field).
               */
               long NFIELD;
               /** Superelement type number.
                */
               long ISELTY;
               /** Estimated number of internal degrees of freedoms.
                */
               long NIDOF;
               /** Estimated number of retained degrees of freedoms.
                */
               long NRDOF;
               /** Estimated bandwidth of the internal degrees
                   freedoms. The estimated bandwidth shall be equal to
                   -1 if no bandwidth information exists.
                */
               long NBAND;
               /** Estimated number of elements. The estimated number
                   of elements is only required for first level
                   superelements.
                */
               long NELT;
               /** If LINDEP > 0, this superelement has linear dependent nodes.
                */
               long LINDEP;
               /** Number of real loadcases.
                */
               long RELOADC;
               /** Number of complex loadcases.
                */
               long COMPLC;

               hsupstat(const std::deque<std::string>&);

               hsupstat(const long &NFIELD,
                        const long &ISELTY,
                        const long &NIDOF,
                        const long &NRDOF,
                        const long &NBAND,
                        const long &NELT,
                        const long &LINDEP,
                        const long &RELOADC,
                        const long &COMPLC);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, const hsupstat&);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `HSUPTRAN`: Superelement Transformations
/**
## Format

|            |          |         |       |       |
| ---------- | -------- | ------- | ----- | ----- |
| `HSUPTRAN` | `NFIELD` | `ITREF` | `T11` | `T21` |
|            | `T31`    | `T41`   | `T12` | `T22` |
|            | `T32`    | `T42`   | `T13` | `T23` |
|            | `T33`    | `T43`   | `T14` | `T24` |
|            | `T34`    | `T44`   |       |       |

This record is defining the super-element transformation between
actual super-element and parent superelement. All the `HSUPTRAN`
records are written in the highest level (top-level) T-file. The
`HSUPTRAN` record is referenced from the `HIERARCH` record through the
superelement transformation reference number, `ITREF`.

*/
            class hsuptran : public card {

            private:

               static const dnvgl::extfem::fem::types::card head;

               static const dnvgl::extfem::fem::types::entry_type<long> _form_NFIELD;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_ITREF;
               static const dnvgl::extfem::fem::types::entry_type<double> _form_T;

            public:

               /** No. of data fields on this record (including this
                   field).
                */
               long NFIELD;
               /** Reference to the HSUPTRAN record (from the HIERARCH record).
                */
               long ITREF;
               /** Term with index ’i’,’j’ of the transformation
                   matrix between actual super-element and parent
                   superelement, defined by:
                   \f[
                   X’_\text{actual} = T·X_\text{parent}
                   \f]
                   Superelement transformation:
                     \f[
                       \left[
                       \begin{array}{c}
                         X' \\ Y' \\ Z' \\ 1
                       \end{array}
                       \right] = \left[
                       \begin{array}{cccc}
                         T_{11}& T_{12}& T_{13}& T_{14}\\
                         T_{21}& T_{22}& T_{23}& T_{24}\\
                         T_{31}& T_{32}& T_{33}& T_{34}\\
                         0& 0& 0& 1
                       \end{array}
                       \right] \times \left[
                       \begin{array}{c}
                         X \\ Y \\ Z \\ 1
                       \end{array}
                       \right]
                     \f]
                     \f[
                       \left[
                       \begin{array}{c}
                         X' \\ Y' \\ Z'
                       \end{array}
                       \right] = \text{Coordinate system of actual superelement.}
                     \f]
                     \f[
                       \left[
                       \begin{array}{c}
                         X \\ Y \\ Z
                       \end{array}
                       \right] = \text{Coordinate system of parent superelement.}
                     \f]
                     \f[
                       \left[
                       \begin{array}{c}
                         T_{14} \\ T_{24} \\ T_{34}
                       \end{array}
                       \right] =
                       \left[
                       \begin{array}{c}
                         DX \\ DY \\ DZ
                       \end{array}
                       \right] = \text{Displacement terms of superelement transformation}
                     \f]
                */
               double T[4][4];

               hsuptran(const std::deque<std::string>&);

               hsuptran(const long &NFIELD,
                        const long &ITREF,
                        const double &T11,
                        const double &T21,
                        const double &T31,
                        const double &T41,
                        const double &T12,
                        const double &T22,
                        const double &T32,
                        const double &T42,
                        const double &T13,
                        const double &T23,
                        const double &T33,
                        const double &T43,
                        const double &T14,
                        const double &T24,
                        const double &T34,
                        const double &T44);

               hsuptran(const long &NFIELD,
                        const long &ITREF,
                        const double T[4][4]);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, const hsuptran&);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `HIERARCH`: Superelement Hierarchy Description
/**
## Format

|            |                      |         |                           |          |
| ---------- | -------------------- | ------- | ------------------------- | -------- |
| `HIERARCH` | `NFIELD`             | `IHREF` | `ISELTY`                  | `INDSEL` |
|            | `ISLEVL`             | `ITREF` | `IHPREF`                  | `NSUB`   |
|            | `IHSREF`<sub>1</sub> | ...     | `IHSREF`<sub>`NSUB`</sub> |          |

This record is defining the super-element transformation between
actual super-element and parent superelement. All the `HIERARCH`
records are written in the highest level (top-level) T-file. The
`HIERARCH` record is referenced from the `HIERARCH` record through the
superelement transformation reference number, `ITREF`.


\image latex hierarch.eps "Superelement hierarchy with 3 levels."
\image html hierarch.svg "Superelement hierarchy with 3 levels."

@note **Example:**

   @par
   Superelement hierarchy with 3 levels. Contents of the
   `HIERARCH` records.

   @par
   | `IHREF` | `ISLEVL` | `IHPREF` | `NSUB` | `IHSREF`<sub>1</sub> | `IHSREF`<sub>2</sub> |
   | ------- | -------- | -------- | ------ | -------------------- | -------------------- |
   | 1       | 3        | 0        | 2      | `N2`                 | `N5`                 |
   | `N2`    | 2        | 1        | 2      | `N3`                 | `N4`                 |
   | `N3`    | 1        | `N2`     | 0      |                      |                      |
   | `N4`    | 1        | `N2`     | 0      |                      |                      |
   | `N5`    | 1        | 1        | 0      |                      |                      |

   @par
   Number of `HIERARCH`records needed to represent this example = 5.
   The above values would be used in the 5 `HIERARCH` records. Note
   that `N2`, `N3`, `N4` & `N5` may take any values as long as they
   are unique.
*/
            class hierarch : public card {

            private:

               static const dnvgl::extfem::fem::types::card head;

               static const dnvgl::extfem::fem::types::entry_type<long> _form_NFIELD;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_IHREF;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_ISELTY;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_INDSEL;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_ISLEVL;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_ITREF;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_IHPREF;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_NSUB;
               static const dnvgl::extfem::fem::types::entry_type<long> _form_IHSREF;

            public:

               /** No. of data fields on this record (including this
                   field).
               */
               long NFIELD;
               /** Hierarchy reference number. Number 1 is reserved
                   for the top level superelement. In SESAM, PRESEL
                   (super-element pre-processor) is writing the
                   `HIERARCH` records and defining a unique number
                   (`IHREF`) for each appearance of the different
                   superelements
                */
               long IHREF;
               /** Superelement type number.
                */
               long ISELTY;
               /** Superelement index number. Superelement index in
                   case of repeated superelements. If superelement is
                   not repeated, `INDSEL`=1 must be used.
                */
               long INDSEL;
               /** Super-element level.
                */
               long ISLEVL;
               /** Reference to record `HSUPTRAN`, defining
                   super-element transformation between actual
                   super-element and parent super-element.
                */
               long ITREF;
               /** Reference to `HIERARCH` record of parent
                   super-element.
                */
               long IHPREF;
               /** No. of sub-elements in this super-element.
                */
               long NSUB;
               /** Reference to `HIERARCH` record for sub-element
                   number /i/.
                */
               std::deque<long> IHSREFi;

               hierarch(const std::deque<std::string>&);

               hierarch(const long &NFIELD,
                        const long &IHREF,
                        const long &ISELTY,
                        const long &INDSEL,
                        const long &ISLEVL,
                        const long &ITREF,
                        const long &IHPREF,
                        const long &NSUB,
                        const std::deque<long> &IHSREF);

               hierarch(const long &NFIELD,
                        const long &IHREF,
                        const long &ISELTY,
                        const long &INDSEL,
                        const long &ISLEVL,
                        const long &ITREF,
                        const long &IHPREF,
                        const std::deque<long> &IHSREF);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, const hierarch&);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };
         }
      }
   }
}

#endif // _FEM_CARDS_LOADS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// coding: utf-8
// End:
