/**
   \file bdf/cards_properties.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for BDF element property cards.

   Detailed description
*/


// ID: $Id$

#if !defined _BDF_CARDS_PROPERTIES_H_
#define _BDF_CARDS_PROPERTIES_H_

#include <memory>

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

/// Handle Nastran Bulk `PSHELL` entries.
/** # Shell Element Property

Defines the membrane, bending, transverse shear, and coupling
properties of thin shell elements.

# Format

| 1        | 2     | 3      | 4      | 5      | 6          | 7      | 8      | 9     | 10 |
| -------- | ----- | ------ | ------ | ------ | ---------- | ------ | ------ | ----- | -- |
| `PSHELL` | `PID` | `MID1` | `T`    | `MID2` | `12I/T**3` | `MID3` | `TS/T` | `NSM` |    |
|          | `Z1`  | `Z2`   | `MID4` |        |            |        |        |       |    |
*/
            class pshell : public __base::card {
               // Handle Nastran Bulk PSHELL entries.

            private:

               static const dnvgl::extfem::bdf::types::entry_type<long> form_PID;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_MID1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_T;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_MID2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_12I_T__3; // 12 I / T**3
               static const dnvgl::extfem::bdf::types::entry_type<long> form_MID3;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_TS_T; // TS / T
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSM;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_Z1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_Z2;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_MID4;

            public:

               /** Property identification number. (Integer > 0)
                */
               dnvgl::extfem::bdf::types::entry_value<long> PID;
               /** Material identification number for the membrane.
                   (Integer > 0 or blank)
               */
               dnvgl::extfem::bdf::types::entry_value<long> MID1;
               /** Default membrane thickness for `Ti` on the
                   connection entry. If `T` is blank then the
                   thickness must be specified for `Ti` on the
                   `CQUAD4`, `CTRIA3`, `CQUAD8`, and `CTRIA6` entries.
                   (Real or blank)
               */
               dnvgl::extfem::bdf::types::entry_value<double> T;
               /** Material identification number for bending.
                   (Integer > -1 or blank)
               */
               dnvgl::extfem::bdf::types::entry_value<long> MID2;
               /** 12 `I`/ `T`³ : Bending moment of inertia ratio, 12
                   `I` / `T`³. Ratio of the actual bending moment inertia
                   of the shell, `I`, to the bending moment of inertia of a
                   homogeneous shell, `T`³/12. The default value is for a
                   homogeneous shell. (Real > 0.0; Default = 1.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> x12I_T__3;
               /** Material identification number for transverse
                   shear. (Integer > 0 or blank; unless `MID2` > 0,
                   must be blank.)
               */
               dnvgl::extfem::bdf::types::entry_value<long> MID3;
               /** Transverse shear thickness ratio, `T_S`/`T`. Ratio
                   of the shear thickness, (`T_S`), to the membrane
                   thickness of the shell, `T`. The default value is
                   for a homogeneous shell. (Real > 0.0; Default =
                   .833333)
               */
               dnvgl::extfem::bdf::types::entry_value<double> TS_T; // TS / T
               /** Nonstructural mass per unit area. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> NSM;
               /** Fiber distances for stress calculations. The
                   positive direction is determined by the right-hand
                   rule, and the order in which the grid points are
                   listed on the connection entry. See Remark 11. for
                   defaults. (Real or blank)
               */
               dnvgl::extfem::bdf::types::entry_value<double> Z1;
               /** Fiber distances for stress calculations. The
                   positive direction is determined by the right-hand
                   rule, and the order in which the grid points are
                   listed on the connection entry. See Remark 11. for
                   defaults. (Real or blank)
               */
               dnvgl::extfem::bdf::types::entry_value<double> Z2;
               /** Material identification number for membrane-bending
                   coupling. See Remarks 6. and 13. (Integer > 0 or
                   blank, must be blank unless `MID1` > 0 and `MID2` >
                   0, may not equal `MID1` or `MID2`.)
               */
               dnvgl::extfem::bdf::types::entry_value<long> MID4;

               pshell(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return PSHELL; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };

            namespace __base {
               class beam_base : public card {

               protected:

                  static const dnvgl::extfem::bdf::types::entry_type<long> form_PID;
                  static const dnvgl::extfem::bdf::types::entry_type<long> form_MID;

                  beam_base(const std::list<std::string> &inp) :
                     __base::card(inp) {};

               public:

                  dnvgl::extfem::bdf::types::entry_value<long> PID;
                  dnvgl::extfem::bdf::types::entry_value<long> MID;

                  const dnvgl::extfem::bdf::cards::types
                  card_type(void) const { return BEAM_BASE; };
               };

               class beam_prop : public beam_base {
                  // base class for beam property classes.
               protected:

                  beam_prop(const std::list<std::string> &inp) :
                     beam_base(inp) {};

               public:

                  const dnvgl::extfem::bdf::cards::types card_type(void) const { return BEAM_PROP; };
               };
            }

/// Handle Nastran Bulk `PBEAM` entries.
/** # Beam Property

Defines the properties of a beam element (`CBEAM` entry). This element
may be used to model tapered beams.

# Format

(Note: n = number of dimensions and m = number of intermediate stations)

| 1       | 2       | 3       | 4       | 5       | 6       | 7        | 8       | 9        | 10 |
| ------- | ------- | ------- | ------- | ------- | ------- | -------- | ------- | -------- | -- |
| `PBEAM` | `PID`   | `MID`   | `A(A)`  | `I1(A)` | `I2(A)` | `I12(A)` | `J(A)`  | `NSM(A)` |    |
|         | `C1(A)` | `C2(A)` | `D1(A)` | `D2(A)` | `E1(A)` | `E2(A)`  | `F1(A)` | `F2(A)`  |    |

The next two continuations are repeated for each intermediate station
as described in Remark 5. and `SO` and `X/XB` must be specified.

| 1 | 2    | 3      | 4    | 5    | 6    | 7     | 8    | 9     | 10 |
| - | ---- | ------ | ---- | ---- | ---- | ----- | ---- | ----- | -- |
|   | `SO` | `X/XB` | `A`  | `I1` | `I2` | `I12` | `J`  | `NSM` |    |
|   | `C1` | `C2`   | `D1` | `D2` | `E1` | `E2`  | `F1` | `F2`  |    |

The last two continuations are:

| 1 | 2       | 3       | 4       | 5       | 6        | 7        | 8       | 9        | 10 |
| - | ------- | ------- | ------- | ------- | -------- | -------- | ------- | -------- | -- |
|   | `K1`    | `K2`    | `S1`    | `S2`    | `NSI(A)` | `NSI(B)` | `CW(A)` | `CW(B)`  |    |
|   | `M1(A)` | `M2(A)` | `M1(B)` | `M2(B)` | `N1(A)`  | `N2(A)`  | `N1(B)` | `N2(B)`  |    |
*/
               class pbeam : public __base::beam_prop {
               // Handle Nastran Bulk PBEAM entries.

            private:

               static const dnvgl::extfem::bdf::types::entry_type<double> form_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_I1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_I2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_I12;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_J;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSM;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_C1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_C2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_D1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_D2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_E1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_E2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_F1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_F2;
               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_SO;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_X_XB;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_K1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_K2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_S1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_S2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSI_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSI_B;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_CW_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_CW_B;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_M1_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_M2_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_M1_B;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_M2_B;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_N1_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_N2_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_N1_B;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_N2_B;

            public:

               // fields that might appear more than once

               /** Area of the beam cross section at the various
                   stations. (Real > 0.0)
               */
               std::list<double> A;
               /** Area moment of inertia at the various stations for
                   bending in plane 1 about the neutral axis. (Real >
                   0.0)
               */
               std::list<double> I1;
               /** Area moment of inertia at the various stations for
                   bending in plane 2 about the neutral axis. (Real >
                   0.0)
               */
               std::list<double> I2;
               /** Area product of inertia at the various stations. (Real)
                */
               std::list<double> I12;
               /** Torsional stiffness parameter at the various
                   stations. (Real >= 0.0 but > 0.0 if warping is
                   present)
               */
               std::list<double> J;
               /** Nonstructural mass per unit length at the various
                   stations. (Real, Default=0.0)
               */
               std::list<double> NSM;
               /** *y* coordinate for location of first stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> C1;
               /** *z* coordinate for location of first stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> C2;
               /** *y* coordinate for location of second stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> D1;
               /** *z* coordinate for location of second stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> D2;
               /** *y* coordinate for location of third stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> E1;
               /** *z* coordinate for location of third stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> E2;
               /** *y* coordinate for location of fourth stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> F1;
               /** *z* coordinate for location of fourth stress
                   recovery point at the various stations. (Real;
                   Default: 0)
               */
               std::list<double> F2;
               /** Stress output request option at the various
                   stations. (Character)

                   - `YES` --- Stresses recovered at points `Ci`,
                   `Di`, `Ei`, and `Fi` on the next continuation.

                   - `YESA` --- Stresses recovered at points with the
                   same *y* and *z* location as end `A`.

                   - `NO` --- No stresses or forces are recovered.
               */
               std::list<dnvgl::extfem::bdf::types::entry_value<std::string> > SO;
               /** `X/XB` : Distance from end `A` in the element
                   coordinate system divided by the length of the
                   element. (Real > 0.0)
               */
               std::list<double> X_XB;
               /** Shear stiffness factor *K* in *KxAxG* for plane 1.
                   (Real, Default = 1.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> K1;
               /** Shear stiffness factor *K* in *K*A*G* for plane 2.
                   (Real, Default = 1.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> K2;
               /** Shear relief coefficient due to taper for plane 1.
                   Ignored for beam p-elements. (Real, Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> S1;
               /** Shear relief coefficient due to taper for plane 2.
                   Ignored for beam p-elements. (Real, Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> S2;
               /** Nonstructural mass moment of inertia per unit
                   length about nonstructural mass center of gravity
                   at end `A`. (Real, Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> NSI_A;
               /** Nonstructural mass moment of inertia per unit length
                   about nonstructural mass center of gravity at end `B`.
                   (Real, Default = 0.0, same as end `A`)
               */
               dnvgl::extfem::bdf::types::entry_value<double> NSI_B;
               /** Warping coefficient for end `A`. Ignored for beam
                   p-elements. (Real, Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> CW_A;
               /** Warping coefficient for end `B`. Ignored for beam
                   p-elements. (Real, Default = 0.0, same as end `A`)
               */
               dnvgl::extfem::bdf::types::entry_value<double> CW_B;
               /** *y* coordinates of center of gravity of
                   nonstructural mass for end `A`. (Real, Default =
                   0.0 (no offset from shear center))
               */
               dnvgl::extfem::bdf::types::entry_value<double> M1_A;
               /** *z* coordinates of center of gravity of
                   nonstructural mass for end `A`. (Real, Default =
                   0.0 (no offset from shear center))
               */
               dnvgl::extfem::bdf::types::entry_value<double> M2_A;
               /** *y* coordinates of center of gravity of
                   nonstructural mass for end `B`. (Real, Default =
                   0.0 (no offset from shear center), same values as
                   end `A`)
               */
               dnvgl::extfem::bdf::types::entry_value<double> M1_B;
               /** *z* coordinates of center of gravity of
                   nonstructural mass for end `B`. (Real, Default =
                   0.0 (no offset from shear center), same values as
                   end `A`)
               */
               dnvgl::extfem::bdf::types::entry_value<double> M2_B;
               /** *y* coordinates of neutral axis for end `A`. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> N1_A;
               /** *z* coordinates of neutral axis for end `A`. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> N2_A;
               /** *y* coordinates of neutral axis for end `B`. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> N1_B;
               /** *z* coordinates of neutral axis for end `B`. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> N2_B;

               pbeam(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return PBEAM; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };

            namespace __base {
               class l_geom {

               protected:

                  l_geom () {};

                  static const std::set<std::string> dimnum1;
                  static const std::set<std::string> dimnum2;
                  static const std::set<std::string> dimnum3;
                  static const std::set<std::string> dimnum4;
                  static const std::set<std::string> dimnum5;
                  static const std::set<std::string> dimnum6;
                  static const std::set<std::string> dimnum10;
               };
            }

/// Handle Nastran Bulk `PBEAML` entries.
/** # Beam Cross-Section Property

Defines the properties of a beam element by cross-sectional
dimensions.

# Format

(Note: n = number of dimensions and m = number of intermediate stations)

| 1       | 2         | 3         | 4        | 5         | 6         | 7         | 8         | 9         | 10 |
| ------- | --------- | --------- | -------- | --------- | --------- | --------- | --------- | --------- | -- |
| `PBEAML`| `PID`     | `MID`     | `GROUP`  | `TYPE`    |           |           |           |           |    |
|         | `DIM1(A)` | `DIM2(A)` | *etc.*   | `DIMn(A)` | `NSM(A)`  | `SO(1)`   | `X(1)/XB` | `DIM1(1)` |    |
|         | `DIM2(1)` | *etc.*    | `DIMn(1)`| `NSM(1)`  | `SO(2)`   | `X(2)/XB` | `DIM1(2)` | `DIM2(2)` |    |
|         | *etc.*    | `DIMn(2)` | `NSM(m)` | *etc.*    | `SO(m)`   | `X(m)/XB` | `DIM1(m)` | *etc.*    |    |
|         | `DIMn(m)` | `NSM(m)`  | `SO(B)`  | 1.0       | `DIM1(B)` | `DIM2(B)` | *etc.*    | `DIMn(B)` |    |
|         |           | `NSM(B)`  |          |           |           |           |           |           |    |
*/
            class pbeaml : public __base::beam_prop, private __base::l_geom {
               // Handle Nastran Bulk PBEAML entries.

            private:

               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_GROUP;
               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_TYPE;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_DIM;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSM;
               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_SO;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_X_XB;

            public:
               /** Cross-section group. (Character; Default =
                * `MSCBML0`)
                */
               dnvgl::extfem::bdf::types::entry_value<std::string> GROUP;
               /** Cross-section shape. (Character: `ROD`, `TUBE`,
                   `L`, `I`, `CHAN`, `T`, `BOX`, `BAR`, `CROSS`, `H`,
                   `T1`, `I1`, `CHAN1`, `Z`, `CHAN2`, `T2`, `BOX1`,
                   `HEXA`, `HAT`, `HAT1`, `DBOX` for GROUP =
                   `MSCBML0`)
               */
               dnvgl::extfem::bdf::types::entry_value<std::string> TYPE;
               /** Cross-section dimensions at end `A`, intermediate
                   station *j* and end `B`. (Real > 0.0 for `GROUP` =
                   `MSCBML0`)
               */
               std::deque<std::list<double> > DIM;
               /** Nonstructural mass per unit length. (Default = 0.0)
                */
               std::list<double> NSM;
               /** Stress output request option for intermediate
                   station *j* and end `B`. (Character; Default =
                   `YES`):

                   - `YES` --- Stresses recovered at all points on
                   next continuation and shown in Figure 8-116 as
                   `C`, `D`, `E`, and `F`.

                   - `NO` --- No stresses or forces are recovered.
               */
               std::list<std::string> SO;
               /** `X(j)/XB` : Distance from end `A` to intermediate
                   station *j* in the element coordinate system
                   divided by the length of the element. (Real>0.0;
                   Default = 1.0)
               */
               std::list<double> X_XB;

               pbeaml(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return PBEAML; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };

            namespace __base {
/// Base class for `pbar` and `pbarl`.
               class bar_prop : public card {

               protected:
                  static const dnvgl::extfem::bdf::types::entry_type<long> form_PID;
                  static const dnvgl::extfem::bdf::types::entry_type<long> form_MID;

               public:

                  /// `PID` : Property identification number. (Integer >
                  /// 0)
                  dnvgl::extfem::bdf::types::entry_value<long> PID;
                  /// `MID` : Material identification number. (Integer >
                  /// 0)
                  dnvgl::extfem::bdf::types::entry_value<long> MID;

                  const dnvgl::extfem::bdf::cards::types
                  card_type(void) const { return BAR_PROP; };

                  bar_prop(const std::list<std::string> &inp) :
                     card(inp) {};
               };
            }

/// Handle Nastran Bulk `PBAR` entries.
/** # Simple Beam Property

Defines the properties of a simple beam element (`CBAR` entry).

# Format

(Note: n = number of dimensions and m = number of intermediate
stations)

| 1      | 2     | 3     | 4     | 5    | 6    | 7    | 8        | 9    | 10 |
| ------ | ----- | ----- | ----- | ---- | ---- | ---- | -------- | ---- | -- |
| `PBAR` | `PID` | `MID` | `A`   | `I1` | `I2` | `J`  | `NSM(A)` |      |    |
|        | `C1`  | `C2`  | `D1`  | `D2` | `E1` | `E2` | `F1`     | `F2` |    |
|        | `K1`  | `K2`  | `I12` |      |      |      |          |      |    |
*/

            class pbar : public __base::bar_prop {

            private:

               static const dnvgl::extfem::bdf::types::entry_type<double> form_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_I1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_I2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_J;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSM;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_C1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_C2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_D1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_D2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_E1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_E2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_F1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_F2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_K1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_K2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_I12;

            public:

               /** Area of bar coss section. (Real; Default = 0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> A;
               /** Area moments of inertia. (Real; `I1` >= 0;
                   Default=0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> I1;
               /** Area moments of inertia. (Real; `I2` >= 0;
                   Default=0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> I2;
               /** Torsional constant. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> J;
               /** Nonstructural mass per unit length. (Real,
                   Default=0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> NSM;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> C1;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> C2;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> D1;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> D2;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> E1;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> E2;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> F1;
               /** Stress recovery coefficient. (Real; Default=0.0)
                */
               dnvgl::extfem::bdf::types::entry_value<double> F2;
               /** Area factor for shear. (Real or blank)
                */
               dnvgl::extfem::bdf::types::entry_value<double> K1;
               /** Area factor for shear. (Real or blank)
                */
               dnvgl::extfem::bdf::types::entry_value<double> K2;
               /** Area moments of inertia. (Real; `I1`*`I2` > `I12`²;
                   Default=0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> I12;

               pbar(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return PBAR; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };

/// Handle Nastran Bulk `PBARL` entries.
/** # Simple Beam Cross-Section Property

Defines the properties of a simple beam element (`CBAR` entry) by
cross-sectional dimensions.

# Format

(Note: n = number of dimensions and m = number of intermediate stations)

| 1       | 2      | 3        | 4       | 5      | 6      | 7      | 8      | 9      | 10 |
| ------- | ------ | -------- | ------- | ------ | ------ | ------ | ------ | ------ | -- |
| `PBARL` | `PID`  | `MID`    | `GROUP` | `TYPE` |        |        |        |        |    |
|         | `DIM1` | `DIM2`   | `DIM3`  | `DIM4` | `DIM5` | `DIM6` | `DIM7` | `DIM8` |    |
|         | `DIM9` | *etc.*   | `NSM`   |        |        |        |        |        |    |
*/
            class pbarl : public __base::bar_prop, private __base::l_geom {

            private:

               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_GROUP;
               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_TYPE;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_DIM;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSM;

            public:

               /** Cross-section group. (Character; Default =
                   `MSCBML0`)
               */
               dnvgl::extfem::bdf::types::entry_value<std::string> GROUP;
               /** Cross-section shape. (Character: `ROD`, `TUBE`,
                   `L`, `I`, `CHAN`, `T`, `BOX`, `BAR`, `CROSS`, `H`,
                   `T1`, `I1`, `CHAN1`, `Z`, `CHAN2`, `T2`, `BOX1`,
                   `HEXA`, `HAT`, `HAT1`, `DBOX` for GROUP =
                   `MSCBML0`)
               */
               dnvgl::extfem::bdf::types::entry_value<std::string> TYPE;
               /** Cross-section dimensions. (Real > 0.0 for `GROUP` =
                   `MSCBML0`)
               */
               std::list<double> DIM;
               /** Nonstructural mass per unit length. `NSM` is
                   specified after the last `DIMi`. (Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> NSM;

               pbarl(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return PBARL; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };

/// Handle Nastran Bulk `PROD` entries.
/** # Rod Property

Defines the properties of a rod element (`CROD` entry).

# Format

| 1       | 2     | 3     | 4   | 5   | 6   | 7     | 8 | 9 | 10 |
| ------- | ----- | ----- | --- | --- | --- | ----- | - | - | -- |
| `PROD`  | `PID` | `MID` | `A` | `J` | `C` | `NSM` |   |   |    |
*/
            class prod : public __base::card {

            private:

               static const dnvgl::extfem::bdf::types::entry_type<long> form_PID;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_MID;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_A;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_J;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_C;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NSM;

            public:

               /** Property identification number. (Integer > 0)
                */
               dnvgl::extfem::bdf::types::entry_value<long> PID;
               /** Material identification number. See Remarks 2.
                   and 3. (Integer > 0)
               */
               dnvgl::extfem::bdf::types::entry_value<long> MID;
               /** Area of the rod. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> A;
               /** Torsional constant. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> J;
               /** Coefficient to determine torsional stress. (Real;
                   Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> C;
               /** Nonstructural mass per unit length. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> NSM;

               prod(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return PROD; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> > &res) const;
            };
         }
      }
   }
}

#endif // _BDF_CARDS_PROPERTIES_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// coding: utf-8
// End:
