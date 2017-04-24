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
#include <list>

// ReSharper disable once CppUnusedIncludeDirective
#include "bdf/cards.h"

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace cards {
                namespace __base {

                    class property : public __base::card {

                    protected:

                        bdf::types::entry_type<long> static const form_PID;

                    public:

                        /** Property identification number. (Integer > 0)
                         */
                        bdf::types::entry_value<long> PID;

                    protected:

                        property();

                        property(long const*);

                        property(std::list<std::string> const&);

                        virtual void read(std::list<std::string> const&) override;

                        virtual void check_data() const override;

                        card const &operator() (const std::list<std::string> &) override;

                        card const &operator() (long const*);
                    };
                }

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
                class pshell : public __base::property {
                    // Handle Nastran Bulk PSHELL entries.

                private:

                    bdf::types::card static head;

                    using __base::card::format_outlist;

                    using __base::property::form_PID;

                    bdf::types::entry_type<long> static const form_MID1;
                    bdf::types::entry_type<double> static const form_T;
                    bdf::types::entry_type<long> static const form_MID2;
                    bdf::types::entry_type<double> static const form_12I_T__3; // 12 I / T**3
                    bdf::types::entry_type<long> static const form_MID3;
                    bdf::types::entry_type<double> static const form_TS_T; // TS / T
                    bdf::types::entry_type<double> static const form_NSM;
                    bdf::types::entry_type<double> static const form_Z1;
                    bdf::types::entry_type<double> static const form_Z2;
                    bdf::types::entry_type<long> static const form_MID4;

                public:

                    using __base::property::PID;

                    bdf::types::entry_value<long> MID1;
                    /** Default membrane thickness for `Ti` on the
                        connection entry. If `T` is blank then the
                        thickness must be specified for `Ti` on the
                        `CQUAD4`, `CTRIA3`, `CQUAD8`, and `CTRIA6` entries.
                        (Real or blank)
                        */
                    bdf::types::entry_value<double> T;
                    /** Material identification number for bending.
                        (Integer > -1 or blank)
                        */
                    bdf::types::entry_value<long> MID2;
                    /** 12 `I`/ `T`³ : Bending moment of inertia ratio, 12
                        `I` / `T`³. Ratio of the actual bending moment inertia
                        of the shell, `I`, to the bending moment of inertia of a
                        homogeneous shell, `T`³/12. The default value is for a
                        homogeneous shell. (Real > 0.0; Default = 1.0)
                        */
                    bdf::types::entry_value<double> x12I_T__3;
                    /** Material identification number for transverse
                        shear. (Integer > 0 or blank; unless `MID2` > 0,
                        must be blank.)
                        */
                    bdf::types::entry_value<long> MID3;
                    /** Transverse shear thickness ratio, `T_S`/`T`. Ratio
                        of the shear thickness, (`T_S`), to the membrane
                        thickness of the shell, `T`. The default value is
                        for a homogeneous shell. (Real > 0.0; Default =
                        .833333)
                        */
                    bdf::types::entry_value<double> TS_T; // TS / T
                    /** Nonstructural mass per unit area. (Real)
                     */
                    bdf::types::entry_value<double> NSM;
                    /** Fiber distances for stress calculations. The
                        positive direction is determined by the right-hand
                        rule, and the order in which the grid points are
                        listed on the connection entry. See Remark 11. for
                        defaults. (Real or blank)
                        */
                    bdf::types::entry_value<double> Z1;
                    /** Fiber distances for stress calculations. The
                        positive direction is determined by the right-hand
                        rule, and the order in which the grid points are
                        listed on the connection entry. See Remark 11. for
                        defaults. (Real or blank)
                        */
                    bdf::types::entry_value<double> Z2;
                    /** Material identification number for membrane-bending
                        coupling. See Remarks 6. and 13. (Integer > 0 or
                        blank, must be blank unless `MID1` > 0 and `MID2` >
                        0, may not equal `MID1` or `MID2`.)
                        */
                    bdf::types::entry_value<long> MID4;

                    pshell();

                    pshell(std::list<std::string> const&);

                    pshell(
                        long const *PID, long const *MID1, double const *T = nullptr,
                        long const *MID2 = nullptr, double const *x12I_T__3 = nullptr, // 12 I / T**3
                        long const *MID3 = nullptr,
                        double const *TS_T = nullptr, // TS / T
                        double const *NSM = nullptr,
                        double const *Z1 = nullptr, double const *Z2 = nullptr,
                        long const *MID4 = nullptr);

                    /**
                      \brief returns the card type of the current card.
                      \return Current card type.
                      */
                    types card_type() const override;

                    card const &operator() (
                        long const *PID, long const *MID1, double const *T = nullptr,
                        long const *MID2 = nullptr, double const *x12I_T__3 = nullptr, // 12 I / T**3
                        long const *MID3 = nullptr,
                        double const *TS_T = nullptr, // TS / T
                        double const *NSM = nullptr,
                        double const *Z1 = nullptr, double const *Z2 = nullptr,
                        long const *MID4 = nullptr);

                    void read(std::list<std::string> const&) override;

                    card const &operator() (const std::list<std::string> &) override;

                private:

                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> > &res) const override;

                    void check_data() const override;
                };

                namespace __base {
                    class beam_base : public property {

                    protected:

                        using __base::property::form_PID;

                        using __base::property::PID;

                        bdf::types::entry_type<long> static const form_MID;

                        /// Material identification number. (Integer > 0)
                        bdf::types::entry_value<long> MID;

                        beam_base();

                        beam_base(std::list<std::string> const&);

                        beam_base(long const *PID, long const *MID);

                        card const &operator() (long const *PID, long const *MID);

                    public:

                        virtual types card_type() const override;
                    };

                    class beam_prop : public beam_base {
                        // base class for beam property classes.
                    protected:

                        using __base::beam_base::form_PID;
                        using __base::beam_base::form_MID;

                        using __base::beam_base::PID;
                        using __base::beam_base::MID;

                        beam_prop();

                        beam_prop(std::list<std::string> const&);

                        beam_prop(long const *PID, long const *MID);

                        card const &operator() (long const *PID, long const *MID);

                    public:

                        types card_type() const override;
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

                    bdf::types::card static head;

                    using __base::card::format_outlist;

                    using __base::property::form_PID;
                    using __base::beam_base::form_MID;

                    bdf::types::entry_type<double> static const form_A;
                    bdf::types::entry_type<double> static const form_I1;
                    bdf::types::entry_type<double> static const form_I2;
                    bdf::types::entry_type<double> static const form_I12;
                    bdf::types::entry_type<double> static const form_J;
                    bdf::types::entry_type<double> static const form_NSM;
                    bdf::types::entry_type<double> static const form_C1;
                    bdf::types::entry_type<double> static const form_C2;
                    bdf::types::entry_type<double> static const form_D1;
                    bdf::types::entry_type<double> static const form_D2;
                    bdf::types::entry_type<double> static const form_E1;
                    bdf::types::entry_type<double> static const form_E2;
                    bdf::types::entry_type<double> static const form_F1;
                    bdf::types::entry_type<double> static const form_F2;
                    bdf::types::entry_type<std::string> static const form_SO;
                    bdf::types::entry_type<double> static const form_X_XB;
                    bdf::types::entry_type<double> static const form_K1;
                    bdf::types::entry_type<double> static const form_K2;
                    bdf::types::entry_type<double> static const form_S1;
                    bdf::types::entry_type<double> static const form_S2;
                    bdf::types::entry_type<double> static const form_NSI_A;
                    bdf::types::entry_type<double> static const form_NSI_B;
                    bdf::types::entry_type<double> static const form_CW_A;
                    bdf::types::entry_type<double> static const form_CW_B;
                    bdf::types::entry_type<double> static const form_M1_A;
                    bdf::types::entry_type<double> static const form_M2_A;
                    bdf::types::entry_type<double> static const form_M1_B;
                    bdf::types::entry_type<double> static const form_M2_B;
                    bdf::types::entry_type<double> static const form_N1_A;
                    bdf::types::entry_type<double> static const form_N2_A;
                    bdf::types::entry_type<double> static const form_N1_B;
                    bdf::types::entry_type<double> static const form_N2_B;

                public:

                    using __base::beam_base::PID;
                    using __base::beam_base::MID;

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
                    std::list<bdf::types::entry_value<std::string> > SO;
                    /** `X/XB` : Distance from end `A` in the element
                        coordinate system divided by the length of the
                        element. (Real > 0.0)
                        */
                    std::list<double> X_XB;
                    /** Shear stiffness factor *K* in *KxAxG* for plane 1.
                        (Real, Default = 1.0)
                        */
                    bdf::types::entry_value<double> K1;
                    /** Shear stiffness factor *K* in *K*A*G* for plane 2.
                        (Real, Default = 1.0)
                        */
                    bdf::types::entry_value<double> K2;
                    /** Shear relief coefficient due to taper for plane 1.
                        Ignored for beam p-elements. (Real, Default = 0.0)
                        */
                    bdf::types::entry_value<double> S1;
                    /** Shear relief coefficient due to taper for plane 2.
                        Ignored for beam p-elements. (Real, Default = 0.0)
                        */
                    bdf::types::entry_value<double> S2;
                    /** Nonstructural mass moment of inertia per unit
                        length about nonstructural mass center of gravity
                        at end `A`. (Real, Default = 0.0)
                        */
                    bdf::types::entry_value<double> NSI_A;
                    /** Nonstructural mass moment of inertia per unit length
                        about nonstructural mass center of gravity at end `B`.
                        (Real, Default = 0.0, same as end `A`)
                        */
                    bdf::types::entry_value<double> NSI_B;
                    /** Warping coefficient for end `A`. Ignored for beam
                        p-elements. (Real, Default = 0.0)
                        */
                    bdf::types::entry_value<double> CW_A;
                    /** Warping coefficient for end `B`. Ignored for beam
                        p-elements. (Real, Default = 0.0, same as end `A`)
                        */
                    bdf::types::entry_value<double> CW_B;
                    /** *y* coordinates of center of gravity of
                        nonstructural mass for end `A`. (Real, Default =
                        0.0 (no offset from shear center))
                        */
                    bdf::types::entry_value<double> M1_A;
                    /** *z* coordinates of center of gravity of
                        nonstructural mass for end `A`. (Real, Default =
                        0.0 (no offset from shear center))
                        */
                    bdf::types::entry_value<double> M2_A;
                    /** *y* coordinates of center of gravity of
                        nonstructural mass for end `B`. (Real, Default =
                        0.0 (no offset from shear center), same values as
                        end `A`)
                        */
                    bdf::types::entry_value<double> M1_B;
                    /** *z* coordinates of center of gravity of
                        nonstructural mass for end `B`. (Real, Default =
                        0.0 (no offset from shear center), same values as
                        end `A`)
                        */
                    bdf::types::entry_value<double> M2_B;
                    /** *y* coordinates of neutral axis for end `A`. (Real)
                     */
                    bdf::types::entry_value<double> N1_A;
                    /** *z* coordinates of neutral axis for end `A`. (Real)
                     */
                    bdf::types::entry_value<double> N2_A;
                    /** *y* coordinates of neutral axis for end `B`. (Real)
                     */
                    bdf::types::entry_value<double> N1_B;
                    /** *z* coordinates of neutral axis for end `B`. (Real)
                     */
                    bdf::types::entry_value<double> N2_B;

                    pbeam();

                    pbeam(std::list<std::string> const&);

                    pbeam(long const *EID, long const *PID,
                          std::list<double> const *A,
                          std::list<double> const *I1,
                          std::list<double> const *I2,
                          std::list<double> const *I12=nullptr,
                          std::list<double> const *J=nullptr,
                          std::list<double> const *NSM=nullptr,
                          std::list<double> const *C1=nullptr,
                          std::list<double> const *C2=nullptr,
                          std::list<double> const *D1=nullptr,
                          std::list<double> const *D2=nullptr,
                          std::list<double> const *E1=nullptr,
                          std::list<double> const *E2=nullptr,
                          std::list<double> const *F1=nullptr,
                          std::list<double> const *F2=nullptr,
                          std::list<std::string> const *SO=nullptr,
                          std::list<double> const *X_XB=nullptr,
                          double const *K1=nullptr, double const *K2=nullptr,
                          double const *S1=nullptr, double const *S2=nullptr,
                          double const *NSI_A=nullptr, double const *NSI_B=nullptr,
                          double const *CW_A=nullptr, double const *CW_B=nullptr,
                          double const *M1_A=nullptr, double const *M2_A=nullptr,
                          double const *M1_B=nullptr, double const *M2_B=nullptr,
                          double const *N1_A=nullptr, double const *N2_A=nullptr,
                          double const *N1_B=nullptr, double const *N2_B=nullptr);

                    types card_type() const override;

                    void read(std::list<std::string> const &) override;

                    card const &operator() (const std::list<std::string> &) override;

                    card const &operator() (
                        long const *EID, long const *PID,
                        std::list<double> const *A,
                        std::list<double> const *I1,
                        std::list<double> const *I2,
                        std::list<double> const *I12=nullptr,
                        std::list<double> const *J=nullptr,
                        std::list<double> const *NSM=nullptr,
                        std::list<double> const *C1=nullptr,
                        std::list<double> const *C2=nullptr,
                        std::list<double> const *D1=nullptr,
                        std::list<double> const *D2=nullptr,
                        std::list<double> const *E1=nullptr,
                        std::list<double> const *E2=nullptr,
                        std::list<double> const *F1=nullptr,
                        std::list<double> const *F2=nullptr,
                        std::list<std::string> const *SO=nullptr,
                        std::list<double> const *X_XB=nullptr,
                        double const *K1=nullptr, double const *K2=nullptr,
                        double const *S1=nullptr, double const *S2=nullptr,
                        double const *NSI_A=nullptr, double const *NSI_B=nullptr,
                        double const *CW_A=nullptr, double const *CW_B=nullptr,
                        double const *M1_A=nullptr, double const *M2_A=nullptr,
                        double const *M1_B=nullptr, double const *M2_B=nullptr,
                        double const *N1_A=nullptr, double const *N2_A=nullptr,
                        double const *N1_B=nullptr, double const *N2_B=nullptr);

                private:

                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> > &res) const override;

                    void check_data() const override;
                };

                namespace __base {
                    class l_geom {

                    protected:

                        l_geom();

                        std::set<std::string> static const dimnum1;
                        std::set<std::string> static const dimnum2;
                        std::set<std::string> static const dimnum3;
                        std::set<std::string> static const dimnum4;
                        std::set<std::string> static const dimnum5;
                        std::set<std::string> static const dimnum6;
                        std::set<std::string> static const dimnum10;
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

                    bdf::types::card static head;

                    using __base::card::format_outlist;

                    using __base::property::form_PID;
                    using __base::beam_base::form_MID;

                    bdf::types::entry_type<std::string> static const form_GROUP;
                    bdf::types::entry_type<std::string> static const form_TYPE;
                    bdf::types::entry_type<double> static const form_DIM;
                    bdf::types::entry_type<double> static const form_NSM;
                    bdf::types::entry_type<std::string> static const form_SO;
                    bdf::types::entry_type<double> static const form_X_XB;

                    using l_geom::dimnum1;
                    using l_geom::dimnum2;
                    using l_geom::dimnum3;
                    using l_geom::dimnum4;
                    using l_geom::dimnum5;
                    using l_geom::dimnum6;
                    using l_geom::dimnum10;

                public:


                    using __base::property::PID;
                    using __base::beam_base::MID;

                    /** Cross-section group. (Character; Default =
                     * `MSCBML0`)
                     */
                    bdf::types::entry_value<std::string> GROUP;
                    /** Cross-section shape. (Character: `ROD`, `TUBE`,
                        `L`, `I`, `CHAN`, `T`, `BOX`, `BAR`, `CROSS`, `H`,
                        `T1`, `I1`, `CHAN1`, `Z`, `CHAN2`, `T2`, `BOX1`,
                        `HEXA`, `HAT`, `HAT1`, `DBOX` for GROUP =
                        `MSCBML0`)
                        */
                    bdf::types::entry_value<std::string> TYPE;
                    /** Cross-section dimensions at end `A`, intermediate
                        station *j* and end `B`. (Real > 0.0 for `GROUP` =
                        `MSCBML0`)
                        */
                    std::list<std::list<double> > DIM;
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

                    pbeaml(std::list<std::string> const&);

                    types card_type() const override;

                    void read(std::list<std::string> const &) override;

                    card const &operator() (const std::list<std::string> &) override;

                private:

                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> > &res) const override;

                    void check_data() const override;
                };

                namespace __base {
                    /// Base class for `pbar` and `pbarl`.
                    class bar_prop : public beam_base {

                    protected:

                        bar_prop(std::list<std::string> const&);

                    public:

                        types card_type() const override;
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

                    bdf::types::card static head;

                    using __base::card::format_outlist;

                    using __base::property::form_PID;
                    using __base::beam_base::form_MID;

                    bdf::types::entry_type<double> static const form_A;
                    bdf::types::entry_type<double> static const form_I1;
                    bdf::types::entry_type<double> static const form_I2;
                    bdf::types::entry_type<double> static const form_J;
                    bdf::types::entry_type<double> static const form_NSM;
                    bdf::types::entry_type<double> static const form_C1;
                    bdf::types::entry_type<double> static const form_C2;
                    bdf::types::entry_type<double> static const form_D1;
                    bdf::types::entry_type<double> static const form_D2;
                    bdf::types::entry_type<double> static const form_E1;
                    bdf::types::entry_type<double> static const form_E2;
                    bdf::types::entry_type<double> static const form_F1;
                    bdf::types::entry_type<double> static const form_F2;
                    bdf::types::entry_type<double> static const form_K1;
                    bdf::types::entry_type<double> static const form_K2;
                    bdf::types::entry_type<double> static const form_I12;

                public:

                    using __base::property::PID;
                    using __base::beam_base::MID;

                    /** Area of bar coss section. (Real; Default = 0.0)
                     */
                    bdf::types::entry_value<double> A;
                    /** Area moments of inertia. (Real; `I1` >= 0;
                        Default=0.0)
                     */
                    bdf::types::entry_value<double> I1;
                    /** Area moments of inertia. (Real; `I2` >= 0;
                        Default=0.0)
                     */
                    bdf::types::entry_value<double> I2;
                    /** Torsional constant. (Real)
                     */
                    bdf::types::entry_value<double> J;
                    /** Nonstructural mass per unit length. (Real,
                        Default=0.0)
                     */
                    bdf::types::entry_value<double> NSM;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> C1;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> C2;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> D1;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> D2;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> E1;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> E2;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> F1;
                    /** Stress recovery coefficient. (Real; Default=0.0)
                     */
                    bdf::types::entry_value<double> F2;
                    /** Area factor for shear. (Real or blank)
                     */
                    bdf::types::entry_value<double> K1;
                    /** Area factor for shear. (Real or blank)
                     */
                    bdf::types::entry_value<double> K2;
                    /** Area moments of inertia. (Real; `I1`*`I2` > `I12`²;
                        Default=0.0)
                     */
                    bdf::types::entry_value<double> I12;

                    pbar(std::list<std::string> const&);

                    types card_type() const override;

                    void read(std::list<std::string> const &) override;

                    card const &operator() (const std::list<std::string> &) override;

                private:

                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> > &res) const override;

                    void check_data() const override;
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

                    bdf::types::card static head;

                    using __base::card::format_outlist;

                    using __base::property::form_PID;
                    using __base::beam_base::form_MID;

                    bdf::types::entry_type<std::string> static const form_GROUP;
                    bdf::types::entry_type<std::string> static const form_TYPE;
                    bdf::types::entry_type<double> static const form_DIM;
                    bdf::types::entry_type<double> static const form_NSM;

                    using l_geom::dimnum1;
                    using l_geom::dimnum2;
                    using l_geom::dimnum3;
                    using l_geom::dimnum4;
                    using l_geom::dimnum5;
                    using l_geom::dimnum6;
                    using l_geom::dimnum10;

                public:

                    using __base::property::PID;
                    using __base::beam_base::MID;

                    /** Cross-section group. (Character; Default =
                        `MSCBML0`)
                        */
                    bdf::types::entry_value<std::string> GROUP;
                    /** Cross-section shape. (Character: `ROD`, `TUBE`,
                        `L`, `I`, `CHAN`, `T`, `BOX`, `BAR`, `CROSS`, `H`,
                        `T1`, `I1`, `CHAN1`, `Z`, `CHAN2`, `T2`, `BOX1`,
                        `HEXA`, `HAT`, `HAT1`, `DBOX` for GROUP =
                        `MSCBML0`)
                        */
                    bdf::types::entry_value<std::string> TYPE;
                    /** Cross-section dimensions. (Real > 0.0 for `GROUP` =
                        `MSCBML0`)
                        */
                    std::list<double> DIM;
                    /** Nonstructural mass per unit length. `NSM` is
                        specified after the last `DIMi`. (Default = 0.0)
                        */
                    bdf::types::entry_value<double> NSM;

                    pbarl(std::list<std::string> const&);

                    types card_type() const override;

                    void read(std::list<std::string> const &) override;

                    card const &operator() (const std::list<std::string> &) override;

                private:

                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> > &res) const override;

                    void check_data() const override;
                };

                /// Handle Nastran Bulk `PROD` entries.
                /** # Rod Property

                Defines the properties of a rod element (`CROD` entry).

                # Format

                | 1       | 2     | 3     | 4   | 5   | 6   | 7     | 8 | 9 | 10 |
                | ------- | ----- | ----- | --- | --- | --- | ----- | - | - | -- |
                | `PROD`  | `PID` | `MID` | `A` | `J` | `C` | `NSM` |   |   |    |
                */
                class prod : public __base::property {

                private:

                    bdf::types::card static head;

                    using __base::card::format_outlist;

                    using __base::property::form_PID;

                    bdf::types::entry_type<long> static const form_MID;
                    bdf::types::entry_type<double> static const form_A;
                    bdf::types::entry_type<double> static const form_J;
                    bdf::types::entry_type<double> static const form_C;
                    bdf::types::entry_type<double> static const form_NSM;

                public:

                    using __base::property::PID;

                    bdf::types::entry_value<long> MID;
                    /** Area of the rod. (Real)
                     */
                    bdf::types::entry_value<double> A;
                    /** Torsional constant. (Real)
                     */
                    bdf::types::entry_value<double> J;
                    /** Coefficient to determine torsional stress. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> C;
                    /** Nonstructural mass per unit length. (Real)
                     */
                    bdf::types::entry_value<double> NSM;

                    prod(std::list<std::string> const&);

                    types card_type() const override;

                    void read(std::list<std::string> const &) override;

                    card const &operator() (const std::list<std::string> &) override;

                private:

                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> > &res) const override;

                    void check_data() const override;
                };
                //         pelas
            }
        }
    }
}

#endif // _BDF_CARDS_PROPERTIES_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
