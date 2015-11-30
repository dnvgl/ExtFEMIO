/**
   \file bdf/cards_loads.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Classes for the different Nastran BDF cards dealing with loads.

   Detailed description
*/

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BDF_CARDS_LOADS_H_
#define _BDF_CARDS_LOADS_H_

#include <memory>

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

/// Base class for handling forces and moments.
            class momforce_base : public card {

            private:

               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_SID;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_G;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_CID;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_F;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_N1;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_N2;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_N3;

            public:

               /** Load set identification number. (Integer > 0)
                */
               ::dnvgl::extfem::bdf::types::entry_value<long> SID;
               /** Grid point identification number. (Integer > 0)
                */
               ::dnvgl::extfem::bdf::types::entry_value<long> G;
               /** Coordinate system identification number. (Integer > 0;
                   Default = 0)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> CID;
               /** Scale factor. (Real)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> F;
               /** *x* components of a vector measured in coordinate system
                   defined by `CID`. (Real; at least one `Ni` ≠ 0.0.)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> N1;
               /** *y* components of a vector measured in coordinate system
                   defined by `CID`. (Real; at least one `Ni` ≠ 0.0.)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> N2;
               /** *z* components of a vector measured in coordinate system
                   defined by `CID`. (Real; at least one `Ni` ≠ 0.0.)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> N3;

            protected:

               void add_collect(::std::deque<::std::unique_ptr<format_entry>>&,
                                const momforce_base&) const;

               DllExport momforce_base(const ::std::deque<::std::string> &inp);
               DllExport momforce_base(
                  const long *SID, const long *G, const long *CID,
                  const double *F,
                  const double *N1, const double *N2, const double *N3);

               DllExport const ::std::ostream& operator << (::std::ostream& os) const;
            };

/// Handle Nastran Bulk `FORCE` entries.
/** # Static Force

Defines a static concentrated force at a grid point by specifying a
vector.

# Format

| 1       | 2     | 3   | 4     | 5   | 6    | 7    | 8    | 9 | 10 |
| ------- | ----- | --- | ----- | --- | ---- | ---- | ---- | - | -- |
| `FORCE` | `SID` | `G` | `CID` | `F` | `N1` | `N2` | `N3` |   |    |
*/
            class force : public momforce_base {
               // Handle Nastran Bulk FORCE entries.

            private:

               static ::dnvgl::extfem::bdf::types::card head;

            public:

               DllExport force(const ::std::deque<::std::string> &inp) :
                  momforce_base(inp) {};

               DllExport force(
                  const long *SID, const long *G, const long *CID,
                  const double *F,
                  const double *N1, const double *N2=nullptr, const double *N3=nullptr) :
                  momforce_base(SID, G, CID, F, N1, N2, N3) {};

               DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
                  return FORCE;
               };

               DllExport friend ::std::ostream& operator<<(::std::ostream&, const force&);
               DllExport const ::std::ostream& operator << (::std::ostream& os) const;
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
            class moment : public momforce_base {
               // Handle Nastran Bulk MOMENT entries.

            private:

               static ::dnvgl::extfem::bdf::types::card head;

            public:

               DllExport moment(const ::std::deque<::std::string> &inp) :
                  momforce_base(inp) {};
               DllExport moment(
                  const long *SID, const long *G, const long *CID,
                  const double *F,
                  const double *N1, const double *N2=nullptr, const double *N3=nullptr) :
                  momforce_base(SID, G, CID, F, N1, N2, N3) {};

               DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
                  return MOMENT;
               };

               DllExport friend ::std::ostream& operator<< (::std::ostream&, const moment&);
               DllExport const ::std::ostream& operator<< (::std::ostream& os) const;
            };

/// Handle Nastran Bulk `LOAD` entries.
/** # Static Load Combination (Superposition)

Defines a static load as a linear combination of load sets defined via
`FORCE`, `MOMENT`, `FORCE1`, `MOMENT1`, `FORCE2`, `MOMENT2`, `DAREA`
(if these entries have been converted), `PLOAD`, `PLOAD1`, `PLOAD2`,
`PLOAD4`, `PLOADX1`, `SLOAD`, `RFORCE`, and `GRAV` entries.

# Format

| 1      | 2     | 3    | 4      | 5    | 6    | 7    | 8    | 9    | 10 |
| ------ | ----- | ---- | ------ | ---- | ---- | ---- | ---- | ---- | -- |
| `LOAD` | `SID` | `S`  | `S1`   | `L1` | `S2` | `L2` | `S3` | `L3` |    |
|        | `S4`  | `L4` | *etc.* |      |      |      |      |      |    |
*/
            class load : public card {

            private:

               static ::dnvgl::extfem::bdf::types::card head;

               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_SID;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_S;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_Si;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_Li;

            public:

               /** Load set identification number. (Integer > 0)
                */
               ::dnvgl::extfem::bdf::types::entry_value<long> SID;
               /* Overall scale factor. (Real)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> S;
               /** Scale factor on `Li`. (Real)
                */
               ::std::deque<double> Si;
               /** Load set identification numbers defined on entry types
                   listed above. (Integer > 0)
               */
               ::std::deque<long> Li;

               DllExport load(const ::std::deque<::std::string> &inp);

               DllExport load(const long *SID, const double *S,
                              const ::std::deque<double> *Si,
                              const ::std::deque<long> *Li);

               DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
                  return LOAD;
               };

               DllExport friend ::std::ostream&
               operator<<(::std::ostream&, const load&);
               DllExport const ::std::ostream&
               operator << (::std::ostream& os) const;
            };
         }
      }
   }
}

#endif // _BDF_CARDS_LOADS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
