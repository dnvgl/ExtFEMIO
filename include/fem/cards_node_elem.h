/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Nodal Data and Element Geometry Definition

   Detailed description
*/

// ID: $Id$

#pragma once

#ifndef _FEM_CARDS_NODE_ELEM_H_
#define _FEM_CARDS_NODE_ELEM_H_

#include<unordered_map>

#include "fem/elements.h"

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
/// `GBARM`: Cross Section Type Massive Bar
/**
   ## Format

   |         |         |       |         |         |
   | ------- | ------- | ----- | ------- | ------- |
   | `GBARM` | `GEONO` | `HZ`  | `BT`    | `BB`    |
   |         | `SFY`   | `SFZ` | `NLOBY` | `NLOBZ` |


   \image latex gbarm.eps "Massive bar"
   \image html gbarm.svg "Massive bar"
*/
                class gbarm : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_BT;
                    fem::types::entry_type<double>
                    static const _form_BB;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

/** Height of beam.
 */
                    double HZ;
/** Width of bar at top. For massive bars which are not able to have
    different widths at top and bottom this variable is used as the
    width of the beam.
*/
                    double BT;
/** Width of bar at bottom.
 */
                    double BB;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` is SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` is SHARZ(MOD)).
*/
                    double SFZ;
/** Number of integration points in Y’ direction (optional)
 */
                    long NLOBY;
/** Number of integration points in Z’ direction (optional)
 */
                    long NLOBZ;

                    gbarm(std::vector<std::string> const&, size_t const);
                    gbarm();
                    gbarm(long const GEONO,
                          double const HZ, double const BT, double const BB,
                          double const SFY, double const SFZ,
                          long const NLOBY, long const NLOBZ);
                    gbarm(long const GEONO,
                          double const HZ, double const BT, double const BB,
                          double const SFY, double const SFZ) :
                            gbarm(GEONO, HZ, BT, BB, SFY, SFZ, 0, 0) {};
                    gbarm(long const GEONO,
                          double const HZ, double const BT, double const BB) :
                            gbarm(GEONO, HZ, BT, BB, 1., 1., 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const BT, double const BB,
                        double const SFY, double const SFZ,
                        long const NLOBY, long const NLOBZ);
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const BT, double const BB,
                        double const SFY, double const SFZ) {
                        return this->gbarm::operator()(
                            GEONO, HZ, BT, BB, SFY, SFZ, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const BT, double const BB) {
                        return this->gbarm::operator()(
                            GEONO, HZ, BT, BB, 1., 1., 0, 0);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GBEAMG`: General Beam Element Data
/**
   ## Format

   |          |          |          |         |         |
   | -------- | -------- | -------- | ------- | ------- |
   | `GBEAMG` | `GEONO`  | *void*   | `AREA`  | `IX`    |
   |          | `IY`     | `IZ`     | `IYZ`   | `WXMIN` |
   |          | `WYMIN`  | `WZMIN`  | `SHARY` | `SHARZ` |
   |          | `SHCENY` | `SHCENZ` | `SY`    | `SZ`    |

   The succeding data concern the cross section at a specific local node.

   If `GBEAMG` is used for `ELTYP` 10(Truss element) only the first
   record may be on the interface.
*/
                class gbeamg : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_AREA;
                    fem::types::entry_type<double>
                    static const _form_IX;
                    fem::types::entry_type<double>
                    static const _form_IY;
                    fem::types::entry_type<double>
                    static const _form_IZ;
                    fem::types::entry_type<double>
                    static const _form_IYZ;
                    fem::types::entry_type<double>
                    static const _form_WXMIN;
                    fem::types::entry_type<double>
                    static const _form_WYMIN;
                    fem::types::entry_type<double>
                    static const _form_WZMIN;
                    fem::types::entry_type<double>
                    static const _form_SHARY;
                    fem::types::entry_type<double>
                    static const _form_SHARZ;
                    fem::types::entry_type<double>
                    static const _form_SHCENY;
                    fem::types::entry_type<double>
                    static const _form_SHCENZ;
                    fem::types::entry_type<double>
                    static const _form_SY;
                    fem::types::entry_type<double>
                    static const _form_SZ;

                public:

/** Cross section area.
 */
                    double AREA;
/** Torsional moment of inertia about the shear center.
 */
                    double IX;
/** Moment of inertia about the *y* axis \f$= ∫z² dA\f$.
 */
                    double IY;
/** Moment of inertia about the *z* axis \f$= ∫y² dA\f$.
 */
                    double IZ;
/** Product of inertia about *y* and *z* axis \f$= ∫yz dA\f$.
 */
                    double IYZ;
/** Minimum torsional section modulus about shear center(=IX/rmax for
    a PIPE element).
*/
                    double WXMIN;
/** Minimum sectionmodulus about *y* axis \f$= IY/zmax\f$.
 */
                    double WYMIN;
/** Minimum sectionmodulus about *z* axis = \f$IZ/ymax\f$.
 */
                    double WZMIN;
/** Shear area in the direction of *y* axis. If zero, shear is not
    included.
 */
                    double SHARY;
/** Shear area in the direction of *z* axis. If zero, shear is not
    included.
*/
                    double SHARZ;
/** Shear center location *y* component.
 */
                    double SHCENY;
/** Shear center location *z* component
 */
                    double SHCENZ;
/** Static area moment about *y*-axis \f$= ∫z dA\f$.
 */
                    double SY;
/** Static area moment about *z*-axis \f$= ∫y dA\f$
 */
                    double SZ;

                    gbeamg(std::vector<std::string> const&, size_t const);

                    gbeamg();

                    gbeamg(
                        long const GEONO,
                        double const AREA,
                        double const IX, double const IY, double const IZ,
                        double const IYZ,
                        double const WXMIN, double const WYMIN,
                        double const WZMIN,
                        double const SHARY, double const SHARZ,
                        double const SHCENY, double const SHCENZ,
                        double const SY, double const SZ);

                    gbeamg(long const GEONO, double const AREA);

                    gbeamg(double const AREA);

                    using beam_prop::operator();
                    card const &operator()(
                        long const GEONO,
                        double const AREA,
                        double const IX, double const IY, double const IZ,
                        double const IYZ,
                        double const WXMIN, double const WYMIN,
                        double const WZMIN,
                        double const SHARY, double const SHARZ,
                        double const SHCENY, double const SHCENZ,
                        double const SY, double const SZ);
                    card const &operator()(
                        long const GEONO, double const AREA);
                    card const &operator()(double const AREA);

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GBOX`: Cross Section Type Box Beam
/**
   ## Format

   |          |          |          |         |         |
   | -------- | -------- | -------- | ------- | ------- |
   | `GBOX`   | `GEONO`  | `HZ`     | `TY`    | `TB`    |
   |          | `TT`     | `BY`     | `SFY`   | `SFZ`   |
   | `NLOBY`  | `NLOBZ`  |          |         |         |

   \image latex gbox.eps "Box beam"
   \image html gbox.svg "Box beam"
 */

                class gbox : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_TB;
                    fem::types::entry_type<double>
                    static const _form_TT;
                    fem::types::entry_type<double>
                    static const _form_BY;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

// /** Geometry type number, i.e. reference number used for element
//     data definition of geometry properties (Cross sectional
//     properties) of beams.
// */
//                     long GEONO;
/** Height of beam at current location
 */
                    double HZ;
/** Thickness of vertical walls (webs) of box section
*/
                    double TY;
/** Thickness of bottom flange
*/
                    double TB;
/** Thickness of top flange
 */
                    double TT;
/** Width of box beam
 */
                    double BY;
/** Factors modifying the shear areas calculated by the preprocessor
    program such that the modified shear areas are respectively,

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear areas on GBEAMG are SHARY(MOD) and SHARZ(MOD)).
*/
                    double SFY;
/** Factors modifying the shear areas calculated by the preprocessor
    program such that the modified shear areas are respectively,

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear areas on GBEAMG are SHARY(MOD) and SHARZ(MOD)).
*/
                    double SFZ;
/* Number of integration points in each horizontal wall (flange) of
   beam (optional)
 */
                    long NLOBY;
/** Number of integration points in each vertical wall (web) of beam (optional) */
                    long NLOBZ;

                    gbox();
                    gbox(std::vector<std::string> const&, size_t const);
                    gbox(long const GEONO,
                         double const HZ, double const TY, double const TB,
                         double const TT, double const BY,
                         double const SFY, double const SFZ,
                         long const NLOBY, long const NLOBZ);
                    gbox(long const GEONO,
                         double const HZ, double const TY, double const TB,
                         double const TT, double const BY,
                         double const SFY, double const SFZ) :
                            gbox(GEONO, HZ, TY, TB, TT, BY, SFY, SFZ, 0, 0) {};
                    gbox(long const GEONO,
                         double const HZ, double const TY, double const TB,
                         double const TT, double const BY) :
                            gbox(GEONO, HZ, TY, TB, TT, BY, 1., 1., 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const TB,
                        double const TT, double const BY,
                        double const SFY, double const SFZ,
                        long const NLOBY, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const TB,
                        double const TT, double const BY,
                        double const SFY, double const SFZ) {
                        return this->gbox::operator()(
                            GEONO, HZ, TY, TB, TT, BY, SFY, SFZ, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const TB,
                        double const TT, double const BY) {
                        return this->gbox::operator()(
                            GEONO, HZ, TY, TB, TT, BY, 1., 1., 0, 0);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GCHAN`: Cross Section Type Channel Beam
/**
   ## Format

   |          |          |          |         |          |
   | -------- | -------- | -------- | ------- | -------- |
   | `GCHAN`  | `GEONO`  | `HZ`     | `TY`    | `BY`     |
   |          | `TZ`     | `SFY`    | `SFZ`   |          |
   |          | `K`      | `NLOBY`  | `NLOBZ` |          |


   \image latex gchan.eps "Channel beam"
   \image html gchan.svg "Channel beam"
 */

                class gchan : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BY;
                    fem::types::entry_type<double>
                    static const _form_TZ;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_K;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:


// /** GEONO Geometry type number, i.e. reference number used for element
//     data definition of geometry properties (cross sectional
//     properties) of beams.
//  */
//                     long GEONO;
/// Height of beam at current location.
                    double HZ;
/// Thickness of beam web.
                    double TY;
/// Width of top and bottom flange.
                    double BY;
/// Thickness of top and bottom flange.
                    double TZ;
/** Factors modifying the shear areas calculated by the preprocessor
    program such that the modified shear areas are respectively,

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear areas on GBEAMG are SHARY(MOD) and SHARZ(MOD)).
*/
                    double SFY;
/** Factors modifying the shear areas calculated by the preprocessor
    program such that the modified shear areas are respectively,

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear areas on GBEAMG are SHARY(MOD) and SHARZ(MOD)).
*/
                    double SFZ;
/** Web orientation:

      =0 - web located in the negative local y-direction (and
           consequently flange in the postitive y’-direction)

      =1 - web located in the positive local y-direction (and
           consequently flange in the negative y’-direction)
 */
                    long K;
/// Number of integration points in each flange (optional)
                    long NLOBY;
/// Number of integration points in beam web (optional)
                    long NLOBZ;

                    gchan();
                    gchan(std::vector<std::string> const&, size_t const);
                    gchan(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TZ, double const SFY, double const SFZ,
                          long const K, long const NLOBY, long const NLOBZ);
                    gchan(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TZ, double const SFY, double const SFZ,
                          long const K) :
                            gchan(GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, 0, 0) {};
                    gchan(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TZ, long const K) :
                            gchan(GEONO, HZ, TY, BY, TZ, 1., 1., K, 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ, double const SFY, double const SFZ,
                        long const K, long const NLOBY, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ, double const SFY, double const SFZ,
                        long const K) {
                        return this->gchan::operator()(
                            GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ, long const K) {
                        return this->gchan::operator()(
                            GEONO, HZ, TY, BY, TZ, 1., 1., K, 0, 0);
                    };

                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GCHANR`: Cross Section Type Channel Beam with Inside Curvature
/**
   ## Format

   |          |          |          |         |          |
   | -------- | -------- | -------- | ------- | -------- |
   | `GCHANR` | `GEONO`  | `HZ`     | `TY`    | `BY`     |
   |          | `TZ`     | `SFY`    | `SFZ`   |          |
   |          | `K`      | `R`      | `NLOBY`  | `NLOBZ` |


   \image latex gchanr.eps "Channel beam with Inside Curvature"
   \image html gchanr.svg "Channel beam with Inside Curvature"
 */

                class gchanr : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BY;
                    fem::types::entry_type<double>
                    static const _form_TZ;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_K;
                    fem::types::entry_type<double>
                    static const _form_R;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

// /** Geometry type number, i.e. reference number used for element data definition of geometry
//     properties (cross sectional properties) of beams.
// */
//                     long GEONO;
/// Height of beam at current location.
                    double HZ;
/// Thickness of beam web.
                    double TY;
/// Width of top and bottom flange.
                    double BY;
/// Thickness of top and bottom flange.
                    double TZ;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear areas on `GBEAMG` are SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear areas on `GBEAMG` are SHARZ(MOD)).
*/
                    double SFZ;
/** Web orientation:

      =0 - web located in the negative local y-direction (and
           consequently flange in the postitive y’-direction)

      =1 - web located in the positive local y-direction (and
           consequently flange in the negative y’-direction)
 */
                    long K;
/// Radius of inside curvature.
                    double R;
/// Number of integration points in each flange (optional)
                    long NLOBY;
/// Number of integration points in beam web (optional)
                    long NLOBZ;

                    gchanr();
                    gchanr(std::vector<std::string> const&, size_t const);
                    gchanr(long const GEONO,
                           double const HZ, double const TY, double const BY,
                           double const TZ, double const SFY, double const SFZ,
                           long const K, double const R,
                           long const NLOBY, long const NLOBZ);
                    gchanr(long const GEONO,
                           double const HZ, double const TY, double const BY,
                           double const TZ, double const SFY, double const SFZ,
                           long const K, double const R) :
                            gchanr(GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, R, 0, 0) {};
                    gchanr(long const GEONO,
                           double const HZ, double const TY, double const BY,
                           double const TZ, long const K, double const R) :
                    gchanr(GEONO, HZ, TY, BY, TZ, 1., 1., K, R, 0, 0) {};
                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ, double const SFY, double const SFZ,
                        long const K, double const R,
                        long const NLOBY, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ, double const SFY, double const SFZ,
                        long const K, double const R) {
                        return this->gchanr::operator()(
                            GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, R, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ, long const K, double const R) {
                        return this->gchanr::operator()(
                            GEONO, HZ, TY, BY, TZ, 1., 1., K, R, 0, 0);
                    };
                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GCOORD`: Nodal Coordinates
/**
   ## Format

   |          |          |          |         |          |
   | -------- | -------- | -------- | ------- | -------- |
   | `GCOORD` | `NODENO` | `XCOORD` | `YCOORD`| `ZCOORD` |
*/
                class gcoord : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_NODENO;
                    fem::types::entry_type<double>
                    static const _form_XCOORD;
                    fem::types::entry_type<double>
                    static const _form_YCOORD;
                    fem::types::entry_type<double>
                    static const _form_ZCOORD;

                public:

/** Program defined(internal) node number
 */
                    long NODENO;
/** Cartesian *X*-coordinates of node `NODENO`.
 */
                    double XCOORD;
/** Cartesian *Y*-coordinates of node `NODENO`.
 */
                    double YCOORD;
/** Cartesian `Z`-coordinates of node `NODENO`.
 */
                    double ZCOORD;

                    gcoord();
                    gcoord(std::vector<std::string> const&, size_t const);
                    gcoord(
                        long const NODENO,
                        double const XCOORD, double const YCOORD,
                        double const ZCOORD);

                    using card::operator();
                    card const &operator()(
                        long const NODENO,
                        double const XCOORD, double const YCOORD,
                        double const ZCOORD);

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GDOBO`: Section Type Double Bottom
/**
   ## Format

   |          |          |          |         |          |
   | -------- | -------- | -------- | ------- | -------- |
   | `GDOBO`  | `GEONO`  | `HZ`     | `TY`    | `BY`     |
   |          | `TT`     | `TB`     | `SFY`   | `SFZ`    |
   |          | `NLOBY`  | `NLOBZ`  |         |          |


   \image latex gdobo.eps "Double Bottom"
   \image html gdobo.svg "Double Bottom"
 */

                class gdobo : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BY;
                    fem::types::entry_type<double>
                    static const _form_TT;
                    fem::types::entry_type<double>
                    static const _form_TB;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

// /** Geometry type number, i.e. reference number used for element data
//     definition of geometry properties (Cross sectional properties) of
//     beams.
//  */
//                     double GEONO;
/// Height of beam.
                    double HZ;
/// Thickness of beam web.
                    double TY;
/// Effective width of plates.
                    double BY;
/// Thickness of top plate.
                    double TT;
/// Thickness of bottom plate.
                    double TB;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` is SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` is SHARZ(MOD)).
*/
                    double SFZ;
/// Number of integration points in each flange (optional)
                    long NLOBY;
/// Number of integration points in beam web (optional)
                    long NLOBZ;


                    gdobo();
                    gdobo(std::vector<std::string> const&, size_t const);
                    gdobo(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TT, double const TB,
                          double const SFY, double const SFZ,
                          long const NLOBY, long const NLOBZ);
                    gdobo(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TT, double const TB,
                          double const SFY, double const SFZ) :
                            gdobo(GEONO, HZ, TY, BY, TT, TB, SFY, SFZ, 0, 0) {};
                    gdobo(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TT, double const TB) :
                            gdobo(GEONO, HZ, TY, BY, TT, TB, 1., 1., 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TT, double const TB,
                        double const SFY, double const SFZ,
                        long const NLOBY, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TT, double const TB,
                        double const SFY, double const SFZ) {
                        return this->gdobo::operator()(
                            GEONO, HZ, TY, BY, TT, TB, SFY, SFZ, 0, 0);
                    };
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TT, double const TB) {
                        return this->gdobo::operator()(
                            GEONO, HZ, TY, BY, TT, TB, 1., 1., 0, 0);
                    };

                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GECC`: Eccentricities
/**
   ## Format:

   |        |         |        |         |        |
   |------- | ------- | ------ | ------- | ------ |
   | `GECC` | `ECCNO` | `IOPT` | `EX/EZ` | `(EY)` |
   |        | `(EZ)`  |        |         |        |
*/
                class gecc : public __base::eccno {
                public:
/// Define ECC input.
                    enum class ecc_opt {
                        Z_ONLY= 1, XYZ = 2, UNDEF_TYPE=-999
                    };

                private:

                    fem::types::card static const head;

                    // dnvgl::extfem::fem::types::entry_type<long>
                    // static const _form_ECCNO;
                    fem::types::entry_type<long>
                    static const _form_IOPT;
                    fem::types::entry_type<double>
                    static const _form_EX;
                    fem::types::entry_type<double>
                    static const _form_EY;
                    fem::types::entry_type<double>
                    static const _form_EZ;

                public:
// /** Eccentricity number, referenced to on record `GELREF1`.
//  */
//                     long ECCNO;
/** Option for number of eccentricity components specified.

      = 1: Only local Z-component of eccentricity specified. X and Y
           components are 0.0

      = 2: Local X, Y and Z component of eccentricity specified.
*/
                    ecc_opt IOPT;
/** *x* component of eccentricity vector given in superelement
    coordinate system, the vector points from the global node towards
    the local element node.
*/
                    double EX;
/** *y* component of eccentricity vector given in superelement
    coordinate system, the vector points from the global node towards
    the local element node.
*/
                    double EY;
/** *z* component of eccentricity vector given in superelement
    coordinate system, the vector points from the global node towards
    the local element node.
*/
                    double EZ;

                    gecc();
                    gecc(std::vector<std::string> const&, size_t const);
                    gecc(long const ECCNO, ecc_opt IOPT,
                         double const EX, double const EY, double const EZ);
                    gecc(long const ECCNO,
                         double const EX, double const EY, double const EZ) :
                            gecc(ECCNO, ecc_opt::XYZ, EX, EY, EZ) {};
                    gecc(long const ECCNO, std::vector<double> const &pos) :
                            gecc(ECCNO, ecc_opt::XYZ,
                                 pos.at(0), pos.at(1), pos.at(2)) {};
                    gecc(double const EX, double const EY, double const EZ) :
                            gecc(0, ecc_opt::XYZ, EX, EY, EZ) {};
                    explicit gecc(std::vector<double> const &pos) :
                            gecc(0, ecc_opt::XYZ,
                                 pos.at(0), pos.at(1), pos.at(2)) {};
                    gecc(long const ECCNO, double const EZ) :
                            gecc(ECCNO, ecc_opt::Z_ONLY, 0., 0., EZ) {};
                    explicit gecc(double const EZ) :
                            gecc(0, ecc_opt::Z_ONLY, 0., 0., EZ) {};
                    explicit gecc(gecc const *that) :
                            gecc(that->ECCNO, that->IOPT,
                                 that->EX, that->EY, that->EZ) {};

                    using card::operator();
                    card const &operator() (
                        long const ECCNO, ecc_opt IOPT,
                        double const EX, double const EY, double const EZ);
                    card const &operator() (
                        long const ECCNO,
                        double const EX, double const EY, double const EZ) {
                        return this->gecc::operator()(
                            ECCNO, ecc_opt::XYZ, EX, EY, EZ);
                    };
                    card const &operator() (
                        long const ECCNO, std::vector<double> const &pos) {
                        return this->gecc::operator()(
                            ECCNO, ecc_opt::XYZ,
                            pos.at(0), pos.at(1), pos.at(2));
                    };
                    card const &operator() (
                        double const EX, double const EY, double const EZ) {
                        return this->gecc::operator()(
                            0, ecc_opt::XYZ, EX, EY, EZ);
                    };
                    card const &operator() (
                        std::vector<double> const &pos) {
                        return this->gecc::operator()(
                            0, ecc_opt::XYZ, pos.at(0), pos.at(1), pos.at(2));
                    };
                    card const &operator() (
                        long const ECCNO, double const EZ) {
                        return this->gecc::operator()(
                            ECCNO, ecc_opt::Z_ONLY, 0., 0., EZ);
                    };
                    card const &operator() (double const EZ) {
                        return this->gecc::operator()(
                            0, ecc_opt::Z_ONLY, 0., 0., EZ);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GECCEN`: Eccentricities
/**
   ## Format:

   |          |         |      |      |      |
   |--------- | ------- | ---- | ---- | ---- |
   | `GECCEN` | `ECCNO` | `EX` | `EY` | `EZ` |
*/
                class geccen : public __base::eccno {

                private:

                    fem::types::card static const head;

                    // dnvgl::extfem::fem::types::entry_type<long>
                    // static const _form_ECCNO;
                    fem::types::entry_type<double>
                    static const _form_EX;
                    fem::types::entry_type<double>
                    static const _form_EY;
                    fem::types::entry_type<double>
                    static const _form_EZ;

                public:
// /** Eccentricity number, referenced to on record `GELREF1`.
//  */
//                     long ECCNO;
/** *x* component of eccentricity vector given in superelement
    coordinate system, the vector points from the global node towards
    the local element node.
*/
                    double EX;
/** *y* component of eccentricity vector given in superelement
    coordinate system, the vector points from the global node towards
    the local element node.
*/
                    double EY;
/** *z* component of eccentricity vector given in superelement
    coordinate system, the vector points from the global node towards
    the local element node.
*/
                    double EZ;

                    geccen();
                    geccen(std::vector<std::string> const&, size_t const);
                    geccen(long const ECCNO,
                           double const EX, double const EY, double const EZ);
                    geccen(long const ECCNO, std::vector<double> const &pos) :
                            geccen(ECCNO, pos.at(0), pos.at(1), pos.at(2)) {};
                    geccen(double const EX, double const EY, double const EZ) :
                            geccen(0, EX, EY, EZ) {};
                    geccen(std::vector<double> const &pos) :
                            geccen(0, pos.at(0), pos.at(1), pos.at(2)) {};
                    geccen(geccen const*);

                    using card::operator();
                    card const &operator() (
                        long const ECCNO,
                        double const EX, double const EY, double const EZ) = delete;
                    card const &operator() (
                        long const ECCNO, std::vector<double> const &pos) = delete;
                    card const &operator() (
                        double const EX, double const EY, double const EZ) = delete;
                    card const &operator() (
                        std::vector<double> const &pos) = delete;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GELMNT1`: Element Data Definition
/**
   ## Format

   |           |                       |                       |                       |          |
   | --------- | --------------------- | --------------------- | --------------------- | -------- |
   | `GELMNT1` | `ELNOX`               | `ELNO`                | `ELTYP`               | `ELTYAD` |
   |           | `NODIN`<sub>`1`</sub> | `NODIN`<sub>`2`</sub> | ...                   | ...      |
   |           | ...                   | ...                   | `NODIN`<sub>`N`</sub> |          |
*/
                class gelmnt1 : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_ELNOX;
                    fem::types::entry_type<long>
                    static const _form_ELNO;
                    fem::types::entry_type<long>
                    static const _form_ELTYP;
                    fem::types::entry_type<long>
                    static const _form_ELTYAD;
                    fem::types::entry_type<long>
                    static const _form_NODIN;

                    std::unordered_map<long, const elements::el_types>
                    static const eltyp_map;

                public:

/** External element number(specified or controlled by user).
 */
                    long ELNOX;
/** Internal element number(generated by program)
 */
                    long ELNO;
/** Element type number. Refer to chapter 5 in file format
    documentation for description of legal type no. For element type
    no. 70(’matrix element’) all relevant element data are stored as
    stiffness, mass, damping matrices a.s.o. See the AMATRIX record
    for more information.
*/
                    elements::el_types ELTYP;
/** Additional information related to element type.

      - For membrane elements used to specify plane stress / plane
         strain conditions

           =0: Plane stress

           =1: Plane strain

      - For two noded beam elements used to specify structural /
        non-structural elements:

          =0: Structural beam

          =1: Non structural beam

     - For general matrix element(elem. type 70) used to specify
       number of nodes

         = `NNOD` Number of nodes on the matrix element
*/
                    long ELTYAD;
/** Internal node numbers in the assembly, to which this element is
    connected.

    The sequence of the node numbers is in accordance with the local
    node numbering of the basic element.

    By ’internal node numbers’ is meant the node numbering of the
    entire superelement of which the element `ELNOX` is a part. The
    internal node number refers to the node number generated by the
    program. The program-defined element number ranges from 1 up to
    number of elements. The sequence of the records will correspond to
    the program-defined element numbering, `ELNO`.
*/
                    std::vector<long> NODIN;

                    gelmnt1();
                    gelmnt1(std::vector<std::string> const&, size_t const);
                    gelmnt1(long const ELNOX, long const ELNO,
                            fem::elements::el_types const &ELTYP,
                            long const ELTYAD,
                            std::vector<long> const &NODIN);
                    gelmnt1(long const ELNOX, long const ELNO,
                            fem::elements::el_types const &ELTYP,
                            std::vector<long> const &NODIN);

                    using card::operator();
                    card const &operator()(
                        long const ELNOX, long const ELNO,
                        fem::elements::el_types const &ELTYP,
                        long const ELTYAD,
                        std::vector<long> const &NODIN);
                    card const &operator()(
                        long const ELNOX, long const ELNO,
                        fem::elements::el_types const &ELTYP,
                        std::vector<long> const &NODIN);

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GELREF1`: Reference to Element Data
/**
   ## Format

   |           |              |              |              |                |
   | --------- | ------------ | ------------ | ------------ | -------------- |
   | `GELREF1` | `ELNO`       | `MATNO`      | `ADDNO`      | `INTNO`        |
   |           | `MINTNO`     | `STRANO`     | `STRENO`     | `STREPONO`     |
   |           | `GEONO/OPT`  | `FIXNO/OPT`  | `ECCNO/OPT`  | `TRANSNO/OPT`  |
   |           | `GEONO`(1)   | ...          | `GEONO`(*N*) | `FIXNO`(1)     |
   |           | ...          | `FIXNO`(1)   | `ECCNO`(1)   | ...            |
   |           | `ECCNO`(*N*) | `TRANSNO`(1) | ...          | `TRANSNO`(*N*) |

   Shortest version:

   |           |              |              |              |                |
   | --------- | ------------ | ------------ | ------------ | -------------- |
   | `GELREF1` | `ELNO`       | `MATNO`      | `ADDNO`      | `INTNO`        |
   |           | `MINTNO`     | `STRANO`     | `STRENO`     | `STREPONO`     |
   |           | `GEONO/OPT`  | `FIXNO/OPT`  | `ECCNO/OPT`  | `TRANSNO/OPT`  |
*/

                class gelref1 : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_ELNO;
                    fem::types::entry_type<long>
                    static const _form_MATNO;
                    fem::types::entry_type<long>
                    static const _form_ADDNO;
                    fem::types::entry_type<long>
                    static const _form_INTNO;
                    fem::types::entry_type<long>
                    static const _form_MINTNO;
                    fem::types::entry_type<long>
                    static const _form_STRANO;
                    fem::types::entry_type<long>
                    static const _form_STRENO;
                    fem::types::entry_type<long>
                    static const _form_STREPONO;
                    fem::types::entry_type<long>
                    static const _form_GEONO_OPT;
                    fem::types::entry_type<long>
                    static const _form_FIXNO_OPT;
                    fem::types::entry_type<long>
                    static const _form_ECCNO_OPT;
                    fem::types::entry_type<long>
                    static const _form_TRANSNO_OPT;
                    fem::types::entry_type<long>
                    static const _form_GEONO;
                    fem::types::entry_type<long>
                    static const _form_FIXNO;
                    fem::types::entry_type<long>
                    static const _form_ECCNO;
                    fem::types::entry_type<long>
                    static const _form_TRANSNO;

                public:
/** Internal element number(generated by the program).
 */
                    long ELNO;
/** Material number

      - =0 no material data attached to the element
*/
                    long MATNO;
/** Additional data type number, i.e. number referring to additional
    data specification

      - =0 no additional data attached to the element
*/
                    long ADDNO;
/** Integration station reference number for stiffness matrix, i.e.
    number referring to the specification of integration stations. An
    integration station is defined as:

      - an assembly of integration points over a cross section of a
        1-dimensional(beam or bar) element,

      - an assembly of integration points on a line through the
        thickness of a 2-dimensional element,

        - one single integration point for a 3-dimensional element.
          For further explanation see record `GELINT`.

    `INTNO` = 0: Default values of the analysis program are employed.
*/
                    long INTNO;
/** Integration station reference number for mass and damping
    matrices. Integration station, see `INTNO`.

    `MINTNO` = 0: Default values of the analysis program are employed.
*/
                    long MINTNO;
/** Initial strain number, i.e. number referring to the specification
    of initial strains. The data type containing these data is not yet
    defined.
*/
                    long STRANO;
/** Initial stress number, i.e. number referring to the specification
    of initial stresses. The data type containing these data is not
    yet defined.
*/
                    long STRENO;
/** Stresspoint specification reference number. See record `GELSTRP`
    for further information.
*/
                    long STREPONO;
/** Geometry reference number or option for geometry reference number
    specified later in this record sequence.

    - >0: The geometry reference number(the same for all nodes in the
      element). `GEONO`(1), ..., `GEONO`(*N*) will not be specified.

    - =0: No geometry data is given, i.e. neither here nor on
      `GEONO`(1), ..., `GEONO`(*N*).

    - =-1: Reference numbers to geometry data are specified later in
      this record sequence for all nodes, i.e. all `GEONO`(1), ...,
      `GEONO`(*N*) will be given.
*/
                    long GEONO_OPT;
/** Fixation reference number or option for fixation reference numbers
    specified later in this record sequence. The meaning assigned to
    the values of `FIXNO_OPT` corresponds to those for `GEONO_OPT`.
*/
                    long FIXNO_OPT;
/** Eccentricity reference number or option for eccentricity reference
    numbers specified later in this record sequence. The meaning
    assigned to the values of `ECCNO_OPT` corresponds to those for
    `GEONO_OPT`.
*/
                    long ECCNO_OPT;
/** Reference number for local coordinate system specification or
    option for specification of local nodal coordinate systems later
    in this record sequence. Refers to `GUNIVEC` or `BNTRCOS` record.
    The meaning assigned to the values of `TRANSNO_OPT` corresponds to
    those for `GEONO_OPT`.
*/
                    long TRANSNO_OPT;
/** Geometry reference number for the local nodes of the element.
 */
                    std::vector<long> GEONO;
/** Number referring to the specification of degree of fixation(Data
    type `BELFIX`). `FIXNO`[0] is the reference number for the 1st
    local node of the element, FIXNO[*i*-1] will be the reference
    number for the *i*’th local node.
*/
                    std::vector<long> FIXNO;
/** Eccentricity number for the local nodes of the element, i.e.
    number referring to the specification of eccentricities.
*/
                    std::vector<long> ECCNO;
/** Number referring to the specification of the local element
    coordinate system for the local nodes of the element. Refers to
    `BNTRCOS` or `GUNIVEC` record depending on element type.
*/
                    std::vector<long> TRANSNO;

                    gelref1();
                    gelref1(std::vector<std::string> const&, size_t const);
                    gelref1(long const ELNO, long const MATNO,
                            long const ADDNO, long const INTNO,
                            long const MINTNO, long const STRANO,
                            long const STRENO, long const STREPONO,
                            long const GEONO_OPT, long const FIXNO_OPT,
                            long const ECCNO_OPT, long const TRANSNO_OPT,
                            std::vector<long> const &GEONO={},
                            std::vector<long> const &FIXNO={},
                            std::vector<long> const &ECCNO={},
                            std::vector<long> const &TRANSNO={});

                    using card::operator();
                    card const &operator()(
                        long const ELNO, long const MATNO,
                        long const ADDNO, long const INTNO,
                        long const MINTNO, long const STRANO,
                        long const STRENO, long const STREPONO,
                        long const GEONO_OPT, long const FIXNO_OPT,
                        long const ECCNO_OPT, long const TRANSNO_OPT,
                        std::vector<long> const &GEONO={},
                        std::vector<long> const &FIXNO={},
                        std::vector<long> const &ECCNO={},
                        std::vector<long> const &TRANSNO={});

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GELTH`: Thickness of Two-dimensional Elements
/**
   ## Format:

   |         |         |      |        |   |
   | ------- | ------- | ---- | ------ | - |
   | `GELTH` | `GEONO` | `TH` | `NINT` |   |
*/
                class gelth : public __base::geoprop {

                private:

                    fem::types::card static const head;

                    // dnvgl::extfem::fem::types::entry_type<long>
                    // static const _form_GEONO;
                    fem::types::entry_type<double>
                    static const _form_TH;
                    fem::types::entry_type<long>
                    static const _form_NINT;

                public:

// /** Geometry type number, i.e. referenced to by `GELREF1`.
//  */
//                     long GEONO;
/** Thickness of the element, measured in a specific node.
 */
                    double TH;
/** Number of integration points through thickness.
 */
                    long NINT;

                    gelth();
                    gelth(std::vector<std::string> const&, size_t const);
                    gelth(long const GEONO, double const TH,
                          long const NINT=0);
                    gelth(double const TH, long const NINT=0);

                    using geoprop::operator();
                    card const &operator()(
                        long const GEONO, double const TH,
                        long const NINT=0);
                    card const &operator()(
                        double const TH, long const NINT=0);

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GIORH`: Cross Section Type I or H Beam
/**
   ## Format:

   |         |         |          |          |         |
   | ------- | ------- | -------- | -------- | ------- |
   | `GIORH` | `GEONO` | `HZ`     | `TY`     | `BT`    |
   |         | `TT`    | `BB`     | `TB`     | `SFY`   |
   |         | `SFZ`   | `NLOBYT` | `NLOBYB` | `NLOBZ` |

   \image latex giorh.eps "I or H beam"
   \image html giorh.svg "I or H beam"
*/
                class giorh : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BT;
                    fem::types::entry_type<double>
                    static const _form_TT;
                    fem::types::entry_type<double>
                    static const _form_BB;
                    fem::types::entry_type<double>
                    static const _form_TB;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NLOBYT;
                    fem::types::entry_type<long>
                    static const _form_NLOBYB;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

/** Height of beam at current location
 */
                    double HZ;
/** Thickness of beam web
 */
                    double TY;
/** Width of top flange
 */
                    double BT;
/** Thickness of top flange
 */
                    double TT;
/** Width of bottom flange
 */
                    double BB;
/** Thickness of bottom flange
 */
                    double TB;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear areas on `GBEAMG` are SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear areas on `GBEAMG` are SHARZ(MOD)).
*/
                    double SFZ;
/** Number of integration points in top flange (optional)
 */
                    long NLOBYT;
/** Number of integration points in bottom flange (optional)
 */
                    long NLOBYB;
/** Number of integration points in beam web(optional)
 */
                    long NLOBZ;

                    giorh();
                    giorh(std::vector<std::string> const&, size_t const);
                    giorh(long const GEONO,
                          double const HZ, double const TY, double const BT,
                          double const TT, double const BB, double const TB,
                          double const SFY, double const SFZ,
                          long const NLOBYT, long const NLOBYB,
                          long const NLOBZ);
                    giorh(long const GEONO,
                          double const HZ, double const TY, double const BT,
                          double const TT, double const BB, double const TB,
                          double const SFY, double const SFZ) :
                            giorh(GEONO, HZ, TY, BT, TT, BB, TB, SFY, SFZ,
                                  0, 0, 0) {};
                    giorh(long const GEONO,
                          double const HZ, double const TY, double const BT,
                          double const TT, double const BB, double const TB) :
                            giorh(GEONO, HZ, TY, BT, TT, BB, TB, 1., 1.,
                                  0, 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BT,
                        double const TT, double const BB, double const TB,
                        double const SFY, double const SFZ,
                        long const NLOBYT, long const NLOBYB,
                        long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BT,
                        double const TT, double const BB, double const TB,
                        double const SFY, double const SFZ) {
                        return this->giorh::operator()(
                            GEONO, HZ, TY, BT, TT, BB, TB, SFY, SFZ, 0, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BT,
                        double const TT, double const BB, double const TB) {
                        return this->giorh::operator()(
                            GEONO, HZ, TY, BT, TT, BB, TB, 1., 1., 0, 0, 0);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GIORHR`: Cross Section Type I or H Beam with Inside Curvature
/**
   ## Format:

   |          |          |         |          |          |
   | -------- | -------- | ------- | -------- | -------- |
   | `GIORHR` | `GEONO`  | `HZ`    | `TY`     | `BT`     |
   |          | `TT`     | `BB`    | `TB`     | `SFY`    |
   |          | `SFZ`    | `RT`    | `RB`     | `NLOBYT` |
   |          | `NLOBYB` | `NLOBZ` |          |          |

   \image latex giorhr.eps "I or H beam with Inside Curvature"
   \image html giorhr.svg "I or H beam with Inside Curvature"
*/
                class giorhr : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BT;
                    fem::types::entry_type<double>
                    static const _form_TT;
                    fem::types::entry_type<double>
                    static const _form_BB;
                    fem::types::entry_type<double>
                    static const _form_TB;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<double>
                    static const _form_RT;
                    fem::types::entry_type<double>
                    static const _form_RB;
                    fem::types::entry_type<long>
                    static const _form_NLOBYT;
                    fem::types::entry_type<long>
                    static const _form_NLOBYB;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

// /** Beam stress type number, i.e. reference number used for element
//     data definition of cross sectional properties of beams.
//  */
//                     long GEONO;
/// Height of beam at current location
                    double HZ;
/// Thickness of beam web
                    double TY;
/// Width of top flange
                    double BT;
/// Thickness of top flange
                    double TT;
/// Width of bottom flange
                    double BB;
/// Thickness of bottom flange
                    double TB;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` os SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFZ;
/// Radius of inside curvature at top
                    double RT;
/// Radius of inside curvature at bottom
                    double RB;
/// Number of integration points in top flange (optional)
                    long NLOBYT;
/// Number of integration points in bottom flange (optional)
                    long NLOBYB;
/// Number of integration points in beam web (optional)
                    long NLOBZ;

                    giorhr() = default;
                    giorhr(std::vector<std::string> const&, size_t const);
                    giorhr(long const GEONO,
                           double const HZ, double const TY, double const BT,
                           double const TT, double const BB, double const TB,
                           double const SFY, double const SFZ,
                           double RT, double RB,
                           long const NLOBYT, long const NLOBYB,
                           long const NLOBZ);
                    giorhr(long const GEONO,
                           double const HZ, double const TY, double const BT,
                           double const TT, double const BB, double const TB,
                           double const SFY, double const SFZ,
                           double RT, double RB) :
                            giorhr(GEONO, HZ, TY, BT, TT, BB, TB, SFY, SFZ,
                                   RT, RB, 0, 0, 0) {};
                    giorhr(long const GEONO,
                           double const HZ, double const TY, double const BT,
                           double const TT, double const BB, double const TB,
                           double RT, double RB) :
                            giorhr(GEONO, HZ, TY, BT, TT, BB, TB, 1., 1.,
                                   RT, RB, 0, 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BT,
                        double const TT, double const BB, double const TB,
                        double const SFY, double const SFZ,
                        double RT, double RB,
                        long const NLOBYT, long const NLOBYB, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BT,
                        double const TT, double const BB, double const TB,
                        double const SFY, double const SFZ,
                        double RT, double RB) {
                        return this->giorhr::operator()(
                            GEONO, HZ, TY, BT, TT, BB, TB, SFY, SFZ, RT, RB, 0,
                            0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BT,
                        double const TT, double const BB, double const TB,
                        double RT, double RB) {
                        return this->giorhr::operator()(
                            GEONO, HZ, TY, BT, TT, BB, TB, 1., 1., RT, RB,
                            0, 0, 0);
                    };

                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GLSEC`: Cross Section Type I or H Beam
/**
   ## Format:

   |         |         |          |       |      |
   | ------- | ------- | -------- | ----- | ---- |
   | `GLSEC` | `GEONO` | `HZ`     | `TY`  | `BY` |
   |         | `TZ`    | `SFY`    | `SFZ` | `K`  |
   |         | `NLOBY` | `NLOBZ`  |       |      |

   \image latex glsec.eps "I or H beam"
   \image html glsec.svg "I or H beam"
*/
                class glsec : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BY;
                    fem::types::entry_type<double>
                    static const _form_TZ;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<bool>
                    static const _form_K;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

/** Height of beam at current location.
 */
                    double HZ;
/** Thickness of beam web.
 */
                    double TY;
/** Width of flange.
 */
                    double BY;
/** Thickness of flange.
 */
                    double TZ;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` os SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFZ;
/** Web orientation:

      =0: web located in the negative local *y*-direction (and
          consequently flange in the positive *y*’-direction)

      =1: web located in the positive local *y*-direction (and
          consequently flange in the negative *y*’-direction)
*/
                    bool K;
/** Number of integration points in beam flange (optional)
 */
                    long NLOBY;
/** Number of integration points in beam web(optional)
 */
                    long NLOBZ;

                    glsec();
                    glsec(std::vector<std::string> const&, size_t const);
                    glsec(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TZ,
                          double const SFY, double const SFZ,
                          bool const K,
                          long const NLOBY, long const NLOBZ);
                    glsec(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TZ,
                          double const SFY, double const SFZ,
                          bool const K) :
                            glsec(GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, 0, 0) {};
                    glsec(long const GEONO,
                          double const HZ, double const TY, double const BY,
                          double const TZ,
                          bool const K) :
                            glsec(GEONO, HZ, TY, BY, TZ, 1., 1., K, 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ,
                        double const SFY, double const SFZ,
                        bool const K,
                        long const NLOBY, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ,
                        double const SFY, double const SFZ,
                        bool const K) {
                        return this->glsec::operator()(
                            GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY, double const BY,
                        double const TZ,
                        bool const K) {
                        return this->glsec::operator()(
                            GEONO, HZ, TY, BY, TZ, 1., 1., K, 0, 0);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GLSECR`: Cross Section Type I or H Beam with Inside Curvature
/**
   ## Format:

   |          |         |         |         |      |
   | -------- | ------- | ------- | ------- | ---- |
   | `GLSECR` | `GEONO` | `HZ`    | `TY`    | `BY` |
   |          | `TZ`    | `SFY`   | `SFZ`   | `K`  |
   |          | `R`     | `NLOBY` | `NLOBZ` |      |

   \image latex glsecr.eps "I or H beam with Inside Curvature"
   \image html glsecr.svg "I or H beam with Inside Curvature"
*/
                class glsecr : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BY;
                    fem::types::entry_type<double>
                    static const _form_TZ;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_K;
                    fem::types::entry_type<double>
                    static const _form_R;
                    fem::types::entry_type<long>
                    static const _form_NLOBY;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:

// /** Geometry type number, i.e. reference number used for element data
//     definition of geometry properties (Cross sectional properties) of
//     beams.
//  */
//                     long GEONO;
/// Height of beam at current location.
                    double HZ;
/// Thickness of beam web.
                    double TY;
/// Width of flange.
                    double BY;
/// Thickness of flange.
                    double TZ;
/** Factor modifying the shear area calculated by the
    preprocessor program such that the modified shear
    area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` os SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFZ;
/* Web orientation:

     = 0 - web located in the negative local y-direction (and
           consequently flange in the postitive y’-direction)

     = 1 - web located in the positive local y-direction (and
           consequently flange in the negative y’-direction)
 */
                    long  K;
/// Radius of inside curvature
                    double R;
/// Number of integration points in beam flange (optional)
                    long NLOBY;
/// Number of integration points in beam web (optional)
                    long NLOBZ;

                    glsecr();
                    glsecr(std::vector<std::string> const&, size_t const);
                    glsecr(long const GEONO,
                           double const HZ, double const TY,
                           double const BY, double const TZ,
                           double const SFY, double const SFZ,
                           long const K, double const R,
                           long const NLOBY, long const NLOBZ);
                    glsecr(long const GEONO,
                           double const HZ, double const TY,
                           double const BY, double const TZ,
                           double const SFY, double const SFZ,
                           long const K, double const R) :
                            glsecr(GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, R,
                                   0, 0) {};
                    glsecr(long const GEONO,
                           double const HZ, double const TY,
                           double const BY, double const TZ,
                           long const K, double const R) :
                            glsecr(GEONO, HZ, TY, BY, TZ, 1., 1., K, R,
                                   0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY,
                        double const BY, double const TZ,
                        double const SFY, double const SFZ,
                        long const K, double const R,
                        long const NLOBY, long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY,
                        double const BY, double const TZ,
                        double const SFY, double const SFZ,
                        long const K, double const R) {
                        return this->glsecr::operator()(
                            GEONO, HZ, TY, BY, TZ, SFY, SFZ, K, R, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY,
                        double const BY, double const TZ,
                        long const K, double const R) {
                        return this->glsecr::operator()(
                            GEONO, HZ, TY, BY, TZ, 1., 1., K, R, 0, 0);
                    };

                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };


/// `GNODE`: Correspondence between External and Internal Node
/// Numbering and Number of Degrees of Freedom of Each Node
/**
   ## Format

   |         |         |          |        |        |
   | ------- | ------- | -------- | ------ | ------ |
   | `GNODE` | `NODEX` | `NODENO` | `NDOF` | `ODOF` |

   There will be one record with the identifier `GNODE` for each node.
   The sequence of the records will correspond to the internal node
   number, `NODENO`.

   Example: `NDOF`=3, `ODOF`=135 means 3 degrees of freedom in *x*, *z*
   and *Ry* direction respectively in the superelement’s coordinate
   system, unless a local nodal coordinate system is specified(see the
   `BNDOF` and `BNTRCOS` record).
*/
                class gnode : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_NODEX;
                    fem::types::entry_type<long>
                    static const _form_NODENO;
                    fem::types::entry_type<long>
                    static const _form_NDOF;
                    fem::types::entry_type<std::vector<int> >
                    static const _form_ODOF;

                public:

/** External node number(specified or controlled by user).
 */
                    long NODEX;
/** Internal node number defined by the program(may be generated by
    internal node numbering optimalizer). The internal node numbers
    range from 1 up to number of nodes.
*/
                    long NODENO;
/** Number of degrees of freedom of nodal point `NODENO`.
 */
                    long NDOF;
/** Order of degrees of freedom. `NDOF` digits.
 */
                    std::vector<int> ODOF;

                    gnode();
                    gnode(std::vector<std::string> const&, size_t const);
                    gnode(long const NODEX, long const NODENO,
                          long const NDOF, std::vector<int> const &ODOF);
                    gnode(long const NODEX, long const NODENO,
                          std::vector<int> const &ODOF);
                    ~gnode();

                    using card::operator();
                    card const &operator()(
                        long const NODEX, long const NODENO,
                        long const NDOF, std::vector<int> const &ODOF);
                    card const &operator()(
                        long const NODEX, long const NODENO,
                        std::vector<int> const &ODOF);

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GPIPE`: Cross Section Type Tube
/**
   ## Format:

   |         |         |          |        |        |
   | ------- | ------- | -------- | ------ | ------ |
   | `GPIPE` | `GEONO` | `DI`     | `DY`   | `T`    |
   |         | `SFY`   | `SFZ`    | `NDIR` | `NRAD` |

   \image latex gpipe.eps "Tube"
   \image html gpipe.svg "Tube"
*/
                class gpipe : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_DI;
                    fem::types::entry_type<double>
                    static const _form_DY;
                    fem::types::entry_type<double>
                    static const _form_T;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NCIR;
                    fem::types::entry_type<long>
                    static const _form_NRAD;

                public:

/** Inner diameter of tube.
 */
                    double DI;
/** Outer diameter of tube(mandatory).
 */
                    double DY;
/** Thickness of tube(not necessary if DI is given).
 */
                    double T;
/** Factor modifying the shear area calculated by the
    preprocessor program such that the modified shear
    area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` os SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFZ;
/** Number of integration points in circumferential direction(optional)
 */
                    long NCIR;
/** Number of integration points in radial direction(optional)
 */
                    long NRAD;

                    gpipe();
                    gpipe(std::vector<std::string> const&, size_t const);
                    gpipe(long const GEONO,
                          double const DI, double const DY, double const T,
                          double const SFY, double const SFZ,
                          long const NDIR, long const NRAD);
                    gpipe(long const GEONO,
                          double const DI, double const DY, double const T,
                          double const SFY, double const SFZ) :
                            gpipe(GEONO, DI, DY, T, SFY, SFZ, 0, 0) {};
                    gpipe(long const GEONO,
                          double const DI, double const DY, double const T) :
                            gpipe(GEONO, DI, DY, T, 1., 1., 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const DI, double const DY, double const T,
                        double const SFY, double const SFZ,
                        long const NDIR, long const NRAD);
                    card const inline &operator() (
                        long const GEONO,
                        double const DI, double const DY, double const T,
                        double const SFY, double const SFZ) {
                        return this->gpipe::operator()(
                            GEONO, DI, DY, T, SFY, SFZ, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const DI, double const DY, double const T) {
                        return this->gpipe::operator()(
                            GEONO, DI, DY, T, 1., 1., 0, 0);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GSETMEMB`: set(group) of Nodes or Elements(Members)
/**
   ## Format:

   |            |                        |                        |                            |                        |
   | ---------- | ---------------------- | ---------------------- | -------------------------- | ---------------------- |
   | `GSETMEMB` | `NFIELD`               | `ISREF`                | `INDEX`                    | `ISTYPE`               |
   |            | `ISORIG`               | `IRMEMB`<sub>`1`</sub> | `IRMEMB`<sub>`2`</sub>     | `IRMEMB`<sub>`3`</sub> |
   |            | `IRMEMB`<sub>`4`</sub> | ...                    | `IRMEMB`<sub>`NMEMB`</sub> |                        |

   This record together with the name and description of a set record(TDSETNAM) constitutes the set(group)
   datatype.

   ### Comments:

   The set datatype consists of one name and description of set record
   (`TDSETNAM`) and one or more set member records(`GSETMEMB`).

   It should be noted that a set may have its set members distributed
   over several set member records(`GSETMEMB`) all having the same set
   identification number(`ISREF`) and consequently also the same
   `TDSETNAM` record. The total number of set members will then be the
   sum of the number of set members(`NMEMB`) for each of the set
   records.

   ### Restrictions:

   - Only one set type(ISTYPE) for same set identification number
   (`ISREF`) is allowed.

   - If several records for the same set identification number
   (`ISREF`), record numbering must be strictly sequential; 1 <
   `INDEX` < `NINDEX`, where `NINDEX` is number of records per set.

   - A set member(number) should only be included once in the list.
*/
                class gsetmemb : public __base::card {

                public:

/** Define the possible set types.
 */
                    enum class types {
                        NODE_SET = 1, ELEM_SET = 2, UNDEF_TYPE=-999
                    };
/** Define the possible set origins
 */
                    enum class origins {
                        UNDEF_ORIGIN = 0,
                        POINT_ORIGIN = 1,
                        LINE_OR_CURVE_ORIGIN = 2,
                        SURFACE_ORIGIN = 3,
                        BODY_ORIGIN = 4
                    };

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_NFIELD;
                    fem::types::entry_type<long>
                    static const _form_ISREF;
                    fem::types::entry_type<long>
                    static const _form_INDEX;
                    fem::types::entry_type<long>
                    static const _form_ISTYPE;
                    fem::types::entry_type<long>
                    static const _form_ISORIG;
                    fem::types::entry_type<long>
                    static const _form_IRMEMB;

                    std::unordered_map<long, types> static const types_map;
                    types static to_types(long const);
                    std::unordered_map<long, origins> static const origins_map;
                    origins static to_origins(long const);

                public:

/** Number of data fields on this record(maximum is 1024)
 */
                    long NFIELD;
/** Internal set identification number as defined on the name and
    description of a set record (`TDSETNAM`).
 */
                    long ISREF;
/** Sequential record number for current set(`ISREF`). Each set may
    consist of one or more `GSETMEMB` records with same set
    identification number (`ISREF`). `INDEX` must be strictly
    increasing from 1 and upwards till number of `GSETMEMB` records
    for this set of members(nodes or elements).
*/
                    long INDEX;
/** set type

      =1: , set of nodes

      =2: , set of elements

    Set Type(`ISTYPE`) and interpretation of set Member Number(`IRMEMB`)

      | `ISTYPE` | Description     | Interpretation of `IRMEMB`        |
      | -------: | --------------- | --------------------------------- |
      | 1        | set of Nodes    | Internal Node Number(`IINOD`)    |
      | 2        | set of Elements | Internal Element Number(`IELNO`) |
*/
                    types ISTYPE;
/** set origin type

      = 0:, undefined origin

      = 1:, point

      = 2:, line(or curve)

      = 3:, surface

      = 4:, body
*/
                    origins ISORIG;
/** `NMEMB` set member numbers on this record.

    `NMEMB` is number of set members on the current record. `NMEMB` =
    `NFIELD` - 5
*/
                    std::vector<long> IRMEMB;

                    gsetmemb();
                    gsetmemb(std::vector<std::string> const&, size_t const);
                    gsetmemb(long const NFIELD, long const ISREF,
                             long const INDEX, types const ISTYPE,
                             origins const ISORIG,
                             std::vector<long> const &IRMEMB={});
                    gsetmemb(long const ISREF,
                             long const INDEX,
                             types const ISTYPE,
                             origins const ISORIG,
                             std::vector<long> const &IRMEMB={});
                    gsetmemb(long const ISREF,
                             types const ISTYPE,
                             origins const ISORIG,
                             std::vector<long> const &IRMEMB={});

                    using card::operator();
                    card const &operator() (
                        long const NFIELD, long const ISREF, long const INDEX,
                        types const ISTYPE, origins const ISORIG,
                        std::vector<long> const &IRMEMB={}) = delete;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GTONP`: Cross Section Type I or H Beam with Inside Curvature
/**
   ## Format:

   |         |         |          |          |         |
   | ------- | ------- | -------- | -------- | ------- |
   | `GTONP` | `GEONO` | `HZ`     | `TY`     | `BT`    |
   |         | `TT`    | `BP`     | `TP`     | `SFY`   |
   |         | `SFZ`   | `NLOBYT` | `NLOBYB` | `NLOBZ` |

   \image latex gtonp.eps "T on Plate"
   \image html gtonp.svg "T on Plate"
*/
                class gtonp : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BT;
                    fem::types::entry_type<double>
                    static const _form_TT;
                    fem::types::entry_type<double>
                    static const _form_BP;
                    fem::types::entry_type<double>
                    static const _form_TP;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NLOBYT;
                    fem::types::entry_type<long>
                    static const _form_NLOBYB;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;

                public:


// /** Geometry type number, i.e. reference number used for element data
//     definiton of geometry properties (Cross sectional properties) of
//     beams.
//  */
//                     long GEONO;
/// Height of beam
                    double HZ;
/// Thickness of beam web.
                    double TY;
///  Width of top flange.
                    double BT;
/// Thickness of top flange.
                    double TT;
/// Effective width of plate.
                    double BP;
/// Thickness of plate.
                    double TP;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFZ;
/// Number of integration points in top flange (optional)
                    long NLOBYT;
/// Number of integration points in bottom flange (optional)
                    long NLOBYB;
/// Number of integration points in beam web (optional)
                    long NLOBZ;

                    gtonp();
                    gtonp(std::vector<std::string> const&, size_t const);
                    gtonp(long const GEONO,
                          double HZ, double TY, double BT, double TT,
                          double BP, double TP,
                          double SFY, double SFZ,
                          long NLOBYT, long NLOBYB, long NLOBZ);
                    gtonp(long const GEONO,
                          double HZ, double TY, double BT, double TT,
                          double BP, double TP,
                          double SFY, double SFZ) :
                            gtonp(GEONO, HZ, TY, BT, TT, BP, TP, SFY, SFZ,
                                  0, 0, 0) {};
                    gtonp(long const GEONO,
                          double HZ, double TY, double BT, double TT,
                          double BP, double TP) :
                            gtonp(GEONO, HZ, TY, BT, TT, BP, TP, 1., 1.,
                                  0, 0, 0) {};

                    using beam_prop::operator();
                    card const &operator() (
                        long GEONO,
                        double HZ, double TY, double BT, double TT, double BP,
                        double TP,
                        double SFY, double SFZ,
                        long NLOBYT, long NLOBYB, long NLOBZ);
                    card const inline &operator() (
                        long GEONO,
                        double HZ, double TY, double BT, double TT, double BP,
                        double TP,
                        double SFY, double SFZ) {
                        return this->gtonp::operator()(
                            GEONO, HZ, TY, BT, TT, BP, TP, SFY, SFZ, 0, 0, 0);
                    };
                    card const inline &operator() (
                        long GEONO,
                        double HZ, double TY, double BT, double TT, double BP,
                        double TP) {
                        return this->gtonp::operator()(
                            GEONO, HZ, TY, BT, TT, BP, TP, 1., 1., 0, 0, 0);
                    };

                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GUNIVEC`: Specification of Local Element Coordinate System
/**
   ## Format:

   |           |           |        |        |        |
   | --------- | --------- | ------ | ------ | ------ |
   | `GUNIVEC` | `TRANSNO` | `UNIX` | `UNIY` | `UNIZ` |

   The `GUNIVEC` records are used for beam elements only, i.e. basic
   element types 2, 15 and 23. Other basic element types may refer to
   `BNTRCOS` records. No ambiguity thus exists if both a `GUNIVEC` and
   `BNTRCOS` record have same `TRANSNO`, but they should preferably have
   separate numbering(`TRANSNO`) to avoid possible program problems.
*/
                class gunivec : public __base::transno {

                private:

                    fem::types::card static const head;

                    // dnvgl::extfem::fem::types::entry_type<long>
                    // static const _form_TRANSNO;
                    fem::types::entry_type<double>
                    static const _form_UNIX;
                    fem::types::entry_type<double>
                    static const _form_UNIY;
                    fem::types::entry_type<double>
                    static const _form_UNIZ;

                public:

// /** Unit vector number, referenced to on record `GELREF1`.
//  */
//                     long TRANSNO;
/** *x* component of Unit vector given in superelement coordinate
    system along the local z-axis(reference axis in z-direction) of
    the element in the particular node.
*/
                    double UNIX;
 /** *y* component of Unit vector given in superelement coordinate
     system along the local z-axis(reference axis in z-direction) of
     the element in the particular node.
 */
                    double UNIY;
/** *z* component of Unit vector given in superelement coordinate
    system along the local z-axis(reference axis in z-direction) of
    the element in the particular node.
*/
                    double UNIZ;

                    gunivec(std::vector<std::string> const&, size_t const);
                    gunivec();
                    gunivec(long const TRANSNO,
                            double const UNIX, double const UNIY,
                            double const UNIZ);
                    gunivec(double const UNIX, double const UNIY,
                            double const UNIZ);

                    using transno::operator();
                    card const &operator() (
                        long const TRANSNO, double const UNIX,
                        double const UNIY, double const UNIZ);
                    card const &operator() (
                        double const UNIX, double const UNIY,
                        double const UNIZ);

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `GUSYI`: Cross Section Type Unsymmetrical I-Beam
/**
   ## Format:

   |         |          |         |       |          |
   | ------- | -------- | ------- | ----- | -------- |
   | `GUSYI` | `GEONO`  | `HZ`    | `TY`  | `BT`     |
   |         | `B1`     | `TT`    | `BB`  | `B2`     |
   |         | `TB`     | `SFY`   | `SFZ` | `NLOBYT` |
   |         | `NLOBYB` | `NLOBZ` |       |          |

   \image latex gusyi.eps "Unsymmetrical I-Beam"
   \image html gusyi.svg "Unsymmetrical I-Beam"
*/
                class gusyi : public __base::beam_prop {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<double>
                    static const _form_HZ;
                    fem::types::entry_type<double>
                    static const _form_TY;
                    fem::types::entry_type<double>
                    static const _form_BT;
                    fem::types::entry_type<double>
                    static const _form_B1;
                    fem::types::entry_type<double>
                    static const _form_TT;
                    fem::types::entry_type<double>
                    static const _form_BB;
                    fem::types::entry_type<double>
                    static const _form_B2;
                    fem::types::entry_type<double>
                    static const _form_TB;
                    fem::types::entry_type<double>
                    static const _form_SFY;
                    fem::types::entry_type<double>
                    static const _form_SFZ;
                    fem::types::entry_type<long>
                    static const _form_NLOBYT;
                    fem::types::entry_type<long>
                    static const _form_NLOBYB;
                    fem::types::entry_type<long>
                    static const _form_NLOBZ;


                public:

/** Height of beam
 */
                    double HZ;
/** Thickness of beam web
 */
                    double TY;
/** Width of top flange
 */
                    double BT;
/** Width of half top-flange in positive local y-direction
 */
                    double B1;
/** Thickness of top flange
 */
                    double TT;
/** Width of bottom flange
 */
                    double BB;
/** Width of half bottom-flange in positive local y-direction
 */
                    double B2;
/** Thickness of bottom flange
 */
                    double TB;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARY(MOD) = SHARY(PROG) · SFY
      \f]

    (The shear area on `GBEAMG` os SHARY(MOD)).
*/
                    double SFY;
/** Factor modifying the shear area calculated by the preprocessor
    program such that the modified shear area is

      \f[
      SHARZ(MOD) = SHARZ(PROG) · SFZ
      \f]

    (The shear area on `GBEAMG` os SHARZ(MOD)).
*/
                    double SFZ;
/** Number of integration points in top flange(optional)
 */
                    long NLOBYT;
/** Number of integration points in bottom flange(optional)
 */
                    long NLOBYB;
/** Number of integration points in beam web(optional)
 */
                    long NLOBZ;

                    gusyi();
                    gusyi(std::vector<std::string> const&, size_t const);
                    gusyi(long const GEONO,
                          double const HZ, double const TY, double const BT,
                          double const B1, double const TT, double const BB,
                          double const B2, double const TB,
                          double const SFY, double const SFZ,
                          long const NLOBYT, long const NLOBYB, long const NLOBZ);
                    gusyi(long const GEONO,
                          double const HZ, double const TY, double const BT,
                          double const B1, double const TT, double const BB,
                          double const B2, double const TB,
                          double const SFY, double const SFZ);
                    gusyi(long const GEONO,
                          double const HZ, double const TY, double const BT,
                          double const B1, double const TT, double const BB,
                          double const B2, double const TB);

                    using beam_prop::operator();
                    card const &operator() (
                        long const GEONO,
                        double const HZ, double const TY,
                        double const BT, double const B1, double const TT,
                        double const BB, double const B2, double const TB,
                        double const SFY, double const SFZ,
                        long const NLOBYT, long const NLOBYB,
                        long const NLOBZ);
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY,
                        double const BT, double const B1, double const TT,
                        double const BB, double const B2, double const TB,
                        double const SFY, double const SFZ) {
                        return this->gusyi::operator()(
                            GEONO, HZ, TY, BT, B1, TT, BB, B2, TB,
                            SFY, SFZ, 0, 0, 0);
                    };
                    card const inline &operator() (
                        long const GEONO,
                        double const HZ, double const TY,
                        double const BT, double const B1, double const TT,
                        double const BB, double const B2, double const TB) {
                        return this->gusyi::operator()(
                            GEONO, HZ, TY, BT, B1, TT, BB, B2, TB,
                            1., 1., 0, 0, 0);
                    };

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };
            }
        }
    }
}


#endif // _FEM_CARDS_NODE_ELEM_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_cards --use-colour no)"
// coding: utf-8
// End:
