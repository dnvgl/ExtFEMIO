/**
   \file bdf/cards_loads.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Classes for the different Nastran BDF cards dealing with loads.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _BDF_CARDS_LOADS_H_
#define _BDF_CARDS_LOADS_H_

#include <memory>

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {
            namespace __base {

/// Base class for handling forces and moments.
               class momforce : public __base::card {

               protected:

                  static const dnvgl::extfem::bdf::types::entry_type<long> form_SID;
                  static const dnvgl::extfem::bdf::types::entry_type<long> form_G;
                  static const dnvgl::extfem::bdf::types::entry_type<long> form_CID;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_F;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_N1;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_N2;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_N3;

               public:

                  /** Load std::set identification number. (Integer > 0)
                   */
                  dnvgl::extfem::bdf::types::entry_value<long> SID;
                  /** Grid point identification number. (Integer > 0)
                   */
                  dnvgl::extfem::bdf::types::entry_value<long> G;
                  /** Coordinate system identification number. (Integer > 0;
                      Default = 0)
                  */
                  dnvgl::extfem::bdf::types::entry_value<long> CID;
                  /** Scale factor. (Real)
                   */
                  dnvgl::extfem::bdf::types::entry_value<double> F;
                  /** *x* components of a vector measured in coordinate system
                      defined by `CID`. (Real; at least one `Ni` ≠ 0.0.)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> N1;
                  /** *y* components of a vector measured in coordinate system
                      defined by `CID`. (Real; at least one `Ni` ≠ 0.0.)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> N2;
                  /** *z* components of a vector measured in coordinate system
                      defined by `CID`. (Real; at least one `Ni` ≠ 0.0.)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> N3;

               protected:

                  momforce(const std::list<std::string> &inp);

                  momforce(
                     const long *SID, const long *G, const long *CID,
                     const double *F,
                     const double *N1, const double *N2, const double *N3);

                  virtual std::unique_ptr<format_entry> get_head(void) const = 0;

                  virtual void collect_outdata (
                     std::list<std::unique_ptr<format_entry> > &) const;
               };
            }

/// Handle Nastran Bulk `FORCE` entries.
/** # Static Force

Defines a static concentrated force at a grid point by specifying a
vector.

# Format

| 1       | 2     | 3   | 4     | 5   | 6    | 7    | 8    | 9 | 10 |
| ------- | ----- | --- | ----- | --- | ---- | ---- | ---- | - | -- |
| `FORCE` | `SID` | `G` | `CID` | `F` | `N1` | `N2` | `N3` |   |    |
*/
            class force : public __base::momforce {
               // Handle Nastran Bulk FORCE entries.

            private:

               static dnvgl::extfem::bdf::types::card head;

            public:

               force(const std::list<std::string> &inp) :
                  __base::momforce(inp) {};

               force(
                  const long *SID, const long *G, const long *CID,
                  const double *F,
                  const double *N1, const double *N2=nullptr, const double *N3=nullptr) :
                  __base::momforce(SID, G, CID, F, N1, N2, N3) {};

               const dnvgl::extfem::bdf::cards::types card_type(void) const;

            private:

               virtual std::unique_ptr<format_entry> get_head(void) const;

               using __base::momforce::collect_outdata;
            };

/// Handle Nastran Bulk `MOMENT` entries.
/** # Static Force

Defines a static concentrated force at a grid point by specifying a
vector.

## Format

| 1        | 2     | 3   | 4     | 5   | 6    | 7    | 8    | 9 | 10 |
| -------- | ----- | --- | ----- | --- | ---- | ---- | ---- | - | -- |
| `MOMENT` | `SID` | `G` | `CID` | `F` | `N1` | `N2` | `N3` |   |    |
*/
            class moment : public __base::momforce {
               // Handle Nastran Bulk MOMENT entries.

            private:

               static dnvgl::extfem::bdf::types::card head;

            public:

               moment(const std::list<std::string> &inp) :
                  __base::momforce(inp) {};

               moment(
                  const long *SID, const long *G, const long *CID,
                  const double *F,
                  const double *N1, const double *N2=nullptr, const double *N3=nullptr) :
                  __base::momforce(SID, G, CID, F, N1, N2, N3) {};

               dnvgl::extfem::bdf::cards::types const card_type(void) const;

            private:

               virtual std::unique_ptr<format_entry> get_head(void) const;

               using __base::momforce::collect_outdata;
            };

/// Handle Nastran Bulk GRAV entries.
/** # Parameter

Acceleration or Gravity Load

Defines acceleration vectors for gravity or other acceleration loading.

# Format:

| 1      | 2     | 3     | 4   | 5    | 6    | 7    | 8    | 9 | 10 |
| ------ | ----- | ----- | --- | ---- | ---- | ---- | ---- | - | -- |
| `GRAV` | `SID` | `CID` | `A` | `N1` | `N2` | `N3` | `MB` |   |    |

# Example:

| 1      | 2 | 3 | 4    | 5   | 6   | 7    | 8 | 9 | 10 |
| ------ | - | - | ---- | --- | --- | ---- | - | - | -- |
| `GRAV` | 1 | 3 | 32.2 | 0.0 | 0.0 | -1.0 |   |   |    |

# Remarks:

1. The acceleration vector is defined by \f$\vec{a} = \vec{A}N\f$ ,
   where \f$N\f$ is the vector defined by (\f$N1\f$, \f$N2\f$,
   \f$N3\f$). The magnitude of a is equal to \f$A\f$ times the
   magnitude of \f$N\f$. The static loads generated by this entry are
   in the direction of \f$a\f$.

2. A `CID` of zero references the basic coordinate system.

3. Acceleration or gravity loads may be combined with “simple loads”
   (e.g., `FORCE`, `MOMENT`) only by specification on a `LOAD` entry.
   That is, the `SID? on a `GRAV` entry may not be the same as that on
   a simple load entry.

4. In the static solution sequences, the load set `ID` must be
   selected by the Case Control command `LOAD` = `SID`. In the dynamic
   solution sequences, `SID` must be referenced in the `LID` field of
   an `LSEQ` entry, which in turn must be selected by the Case Control
   command `LOADSET`.

5. At most nine `GRAV` entries can be selected in a given run either
   by Case Control or the `LOAD` Bulk Data entry. Multiples or
   reflections of a given acceleration or gravity load can be
   economically accomplished by use of the `LOAD` Bulk Data entry.

6. In cyclic symmetry solution sequences, the `T3` axis of the
   coordinate system referenced in field 3 must be parallel to the
   axis of symmetry. In dihedral cyclic symmetry (where `STYPE = "DIH"`
   on the `CYSYM` entry), the `T1` axis must, in addition, be parallel to
   Side 1 of segment 1R of the model.

7. For image superelements, the coordinate system must be rotated if
   the image is rotated relative to its primary superelement.

8. Acceleration or gravity loads do not include effects due to mass on
   scalar points.

9. The `RFORCE` entry may be used to specify rotational accelerations.

10. The coordinate systems in the main Bulk Data Section are defined
    relative to the assembly basic coordinate system which is fixed.
    This feature is useful when a superelement defined by a
    partitioned Bulk Data Section is rotated or mirrored and the
    gravity load is more conveniently defined in terms of coordinates
    which are fixed.
*/
            class grav : public __base::card {
               static dnvgl::extfem::bdf::types::card head;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_SID;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_CID;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_Ni;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_MB;

            public:
               /** Set identification number. (Integer > 0)
                */
               dnvgl::extfem::bdf::types::entry_value<long> SID;
               /** Coordinate system identification number. (Integer > 0; Default = 0)
                */
               dnvgl::extfem::bdf::types::entry_value<long> CID;
               /** Acceleration vector scale factor. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> A;
               /** Acceleration vector components measured in coordinate system CID.
                   (Real; at least one Ni ≠ 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> N1;
               /** Acceleration vector components measured in coordinate system CID.
                   (Real; at least one Ni ≠ 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> N2;
               /** Acceleration vector components measured in coordinate system CID.
                   (Real; at least one Ni ≠ 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> N3;
               /** Indicates whether the CID coordinate system is
                   defined in the main Bulk Data Section (`MB` = -1)
                   or the partitioned superelement Bulk Data Section
                   (`MB` = 0). Coordinate systems referenced in the
                   main Bulk Data Section are considered stationary
                   with respect to the assembly basic coordinate
                   system. See Remark 10. (Integer; Default = 0)
               */
               dnvgl::extfem::bdf::types::entry_value<long> MB;

            private:
               grav();

               grav(std::string const&);

            public:
               grav(std::list<std::string> const&);

               grav(long const *SID, long const *CID,
                    double const *A,
                    double const *N1, double const*N2, double const *N3,
                    long const *MB=0);

               grav(long const *SID, long const *CID,
                    double const *A,
                    std::vector<double> const *N,
                    long const *MB=NULL);

               const dnvgl::extfem::bdf::cards::types card_type(void) const;

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
            };

/// Handle Nastran Bulk `LOAD` entries.
/** # Static Load Combination (Superposition)

Defines a static load as a linear combination of load std::sets defined via
`FORCE`, `MOMENT`, `FORCE1`, `MOMENT1`, `FORCE2`, `MOMENT2`, `DAREA`
(if these entries have been converted), `PLOAD`, `PLOAD1`, `PLOAD2`,
`PLOAD4`, `PLOADX1`, `SLOAD`, `RFORCE`, and `GRAV` entries.

# Format

| 1      | 2     | 3    | 4      | 5    | 6    | 7    | 8    | 9    | 10 |
| ------ | ----- | ---- | ------ | ---- | ---- | ---- | ---- | ---- | -- |
| `LOAD` | `SID` | `S`  | `S1`   | `L1` | `S2` | `L2` | `S3` | `L3` |    |
|        | `S4`  | `L4` | *etc.* |      |      |      |      |      |    |
*/
            class load : public __base::card {

            private:

               static dnvgl::extfem::bdf::types::card head;

               static const dnvgl::extfem::bdf::types::entry_type<long> form_SID;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_S;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_Si;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_Li;

            public:

               /** Load std::set identification number. (Integer > 0)
                */
               dnvgl::extfem::bdf::types::entry_value<long> SID;
               /* Overall scale factor. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> S;
               /** Scale factor on `Li`. (Real)
                */
               std::list<double> Si;
               /** Load std::set identification numbers defined on entry types
                   listed above. (Integer > 0)
               */
               std::list<long> Li;

               load(const std::list<std::string> &inp);

               load(const long *SID, const double *S,
                  const std::list<double> *Si,
                  const std::list<long> *Li);

               const dnvgl::extfem::bdf::cards::types card_type(void) const;

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };
         }
      }
   }
}

#endif // _BDF_CARDS_LOADS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
