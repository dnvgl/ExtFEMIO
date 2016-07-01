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
// compile-command: "make -C ../.. check -j8"
// coding: utf-8
// End:
