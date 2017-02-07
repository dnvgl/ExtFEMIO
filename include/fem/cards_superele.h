/**
   \file fem/cards_superele.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Super-Element Hierarchy Information in Highest Level T-File.

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
                class hierarch : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NFIELD;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_IHREF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ISELTY;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_INDSEL;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ISLEVL;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ITREF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_IHPREF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NSUB;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_IHSREF;

                public:

/** No. of data fields on this record (including this field).
 */
                    long NFIELD;
/** Hierarchy reference number. Number 1 is reserved for the top level
    superelement. In SESAM, PRESEL (super-element pre-processor) is
    writing the `HIERARCH` records and defining a unique number
    (`IHREF`) for each appearance of the different superelements
*/
                    long IHREF;
/** Superelement type number.
 */
                    long ISELTY;
/** Superelement index number. Superelement index in case of repeated
    superelements. If superelement is not repeated, `INDSEL`=1 must be
    used.
*/
                    long INDSEL;
/** Super-element level.
 */
                    long ISLEVL;
/** Reference to record `HSUPTRAN`, defining super-element
    transformation between actual super-element and parent
    super-element.
*/
                    long ITREF;
/** Reference to `HIERARCH` record of parent super-element.
 */
                    long IHPREF;
/** No. of sub-elements in this super-element.
 */
                    long NSUB;
/** Reference to `HIERARCH` record for sub-element number /i/.
 */
                    std::vector<long> IHSREFi;

                    hierarch(std::vector<std::string> const&, size_t const);

                    hierarch(void);

                    hierarch(
                        long const NFIELD, long const IHREF, long const ISELTY,
                        long const INDSEL, long const ISLEVL, long const ITREF,
                        long const IHPREF, long const NSUB,
                        std::vector<long> const &IHSREF);

                    hierarch(
                        long const NFIELD, long const IHREF, long const ISELTY,
                        long const INDSEL, long const ISLEVL, long const ITREF,
                        long const IHPREF, std::vector<long> const &IHSREF);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        const std::vector<std::string>&, size_t const);
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
                class hsupstat : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NFIELD;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ISELTY;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NIDOF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NRDOF;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NBAND;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NELT;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_LINDEP;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_RELOADC;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_COMPLC;

                public:

/** No. of data fields on this record (including this field).
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
/** Estimated bandwidth of the internal degrees freedoms. The
    estimated bandwidth shall be equal to -1 if no bandwidth
    information exists.
*/
                    long NBAND;
/** Estimated number of elements. The estimated number of elements is
    only required for first level superelements.
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

                    hsupstat(std::vector<std::string> const&, size_t const);

                    hsupstat(void);

                    hsupstat(
                        long const NFIELD, long const ISELTY, long const NIDOF,
                        long const NRDOF, long const NBAND, long const NELT,
                        long const LINDEP, long const RELOADC,
                        long const COMPLC);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        const std::vector<std::string>&, size_t const);
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
                class hsuptran : public __base::card {

                private:

                    dnvgl::extfem::fem::types::card static const head;

                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_NFIELD;
                    dnvgl::extfem::fem::types::entry_type<long>
                    static const _form_ITREF;
                    dnvgl::extfem::fem::types::entry_type<double>
                    static const _form_T;

                public:

/** No. of data fields on this record (including this field).
 */
                    long NFIELD;
/** Reference to the HSUPTRAN record (from the HIERARCH record).
 */
                    long ITREF;
/** Term with index ’i’,’j’ of the transformation matrix between
    actual super-element and parent superelement, defined by:

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
      T_{11}& T_{12}& T_{13}& T_{14}\                   \
      T_{21}& T_{22}& T_{23}& T_{24}\                   \
      T_{31}& T_{32}& T_{33}& T_{34}\                   \
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

                    hsuptran(std::vector<std::string> const&, size_t const);

                    hsuptran(void);

                    hsuptran(
                        long const NFIELD, long const ITREF, double const T11,
                        double const T21, double const T31, double const T41,
                        double const T12, double const T22, double const T32,
                        double const T42, double const T13, double const T23,
                        double const T33, double const T43, double const T14,
                        double const T24, double const T34, double const T44);

                    hsuptran(
                        long const NFIELD, long const ITREF,
                        double const T[4][4]);
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

#endif // _FEM_CARDS_LOADS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
