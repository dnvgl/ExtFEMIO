// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for BDF element property cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150721_BDF_CARDS_PROPERTIES
#define _BERHOL20150721_BDF_CARDS_PROPERTIES

#include <memory>

#ifdef _C2
#undef _C2
#endif

namespace bdf {

  using namespace types;

  namespace cards {

    /*
Handle Nastran Bulk PSHELL entries.

Shell Element Property

Defines the membrane, bending, transverse shear, and coupling
properties of thin shell elements.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| PSHELL| PID   | MID1  | T     | MID2  | 12I/  | MID3  | TS/T  | NSM   |    |
|       |       |       |       |       | T**3  |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | Z1    | Z2    | MID4  |       |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+


Description:
............

``PID``
  Property identification number. (Integer > 0)
``MID1``
  Material identification number for the membrane. (Integer > 0 or blank)
``T``
  Default membrane thickness for ``Ti`` on the connection entry. If
  ``T`` is blank then the thickness must be specified for ``Ti`` on
  the ``CQUAD4``, ``CTRIA3``, ``CQUAD8``, and ``CTRIA6``
  entries. (Real or blank)
``MID2``
  Material identification number for bending. (Integer > -1 or blank)
``12I/T**3``
  Bending moment of inertia ratio, 12I/T³. Ratio of the actual bending
  moment inertia of the shell, I, to the bending moment of inertia of
  a homogeneous shell, T³/12. The default value is for a homogeneous
  shell.  (Real > 0.0; Default = 1.0)
``MID3``
  Material identification number for transverse shear. (Integer > 0 or
  blank; unless ``MID2`` > 0, must be blank.)
``TS/T``
  Transverse shear thickness ratio, T_S/T. Ratio of the shear
  thickness, (T_S), to the membrane thickness of the shell, T. The
  default value is for a homogeneous shell. (Real > 0.0; Default =
  .833333)
``NSM``
  Nonstructural mass per unit area. (Real)

*/

    class pshell : public bdf_card {
      // Handle Nastran Bulk PSHELL entries.

    private:

      static const entry_type<long> _PID;
      static const entry_type<long> _MID1;
      static const entry_type<double> _T;
      static const entry_type<long> _MID2;
      static const entry_type<double> _12I_T__3; // 12 I / T**3
      static const entry_type<long> _MID3;
      static const entry_type<double> _TS_T; // TS / T
      static const entry_type<double> _NSM;
      static const entry_type<double> _Z1;
      static const entry_type<double> _Z2;
      static const entry_type<long> _MID4;

    public:

      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> MID1;
      ::std::unique_ptr<double> T;
      ::std::unique_ptr<long> MID2;
      ::std::unique_ptr<double> x12I_T__3; // 12 I / T**3
      ::std::unique_ptr<long> MID3;
      ::std::unique_ptr<double> TS_T; // TS / T
      ::std::unique_ptr<double> NSM;
      ::std::unique_ptr<double> Z1;
      ::std::unique_ptr<double> Z2;
      ::std::unique_ptr<long> MID4;

      DllExport pshell(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return PSHELL; };

    };

/*
Handle Nastran Bulk PBEAM entries.

Format:
.......

(Note: n = number of dimensions and m = number of intermediate stations)

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| PBEAM | PID   | MID   | A(A)  | I1(A) | I2(A) |I12(A) | J(A)  |NSM(A) |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | C1(A) | C2(A) | D1(A) | D2(A) | E1(A) | E2(A) | F1(A) | F2(A) |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

The next two continuations are repeated for each intermediate station
as described in Remark 5. and ``SO`` and ``X/XB`` must be specified.

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | SO    | X/XB  | A     | I1    | I2    | I12   | J     | NSM   |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | C1    | C2    | D1    | D2    | E1    | E2    | F1    | F2    |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

The last two continuations are:

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | K1    | K2    | S1    | S2    |NSI(A) |NSI(B) | CW(A) | CW(B) |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | M1(A) | M2(A) | M1(B) | M2(B) | N1(A) | N2(A) | N1(B) | N2(B) |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``PID``
  Property identification number. (Integer > 0)
``MID``
  Material identification number. (Integer > 0)
``A(A)``
  Area of the beam cross section at end ``A``. (Real > 0.0)
``I1(A)``
  Area moment of inertia at end ``A`` for bending in plane 1 about the
  neutral axis. (Real > 0.0)
``I2(A)``
  Area moment of inertia at end ``A`` for bending in plane 2 about the
  neutral axis. (Real > 0.0)
``I12(A)``
  Area product of inertia at end ``A``. (Real)
``J(A)``
  Torsional stiffness parameter at end ``A``. (Real >= 0.0 but > 0.0 if
  warping is present)
``NSM(A)``
  Nonstructural mass per unit length at end ``A``. (Real, Default=0.0)
``Ci(A)``, ``Di(A)``, ``Ei(A)``, ``Fi(A)``
  The *y* and *z* locations (*i* = 1 corresponds to y and *i* = 2
  corresponds to *z*) in element coordinates relative to the shear
  center at end ``A`` for stress data recovery. (Real, Default: y = z
  = 0.0)
``SO``
  Stress output request option. (Character)

  ``YES``
    Stresses recovered at points ``Ci``, ``Di``, ``Ei``,
    and ``Fi`` on the next continuation.
  ``YESA``
    Stresses recovered at points with the same *y* and *z* location as
    end ``A``.
  ``NO``
    No stresses or forces are recovered.

``X/XB``
  Distance from end ``A`` in the element coordinate system divided by
  the length of the element. (Real > 0.0)
``A``, ``I1``, ``I2``, ``I12``, ``J``, ``NSM``
  Area, moments of inertia, torsional stiffness parameter, and
  nonstructural mass for the cross section located at *x*. (Real; J >
  0.0 if warping is present.)
``Ci``, ``Di``, ``Ei``, ``Fi``
  The *y* and *z* locations (*i = 1* corresponds to *y* and *i = 2*
  corresponds to z) in element coordinates relative to the shear
  center for the cross section located at ``X/XB``. The values are
  fiber locations for stress data recovery. Ignored for beam
  p-elements. (Real)
``K1``, ``K2``
  Shear stiffness factor *K* in *K*A*G* for plane 1 and plane
  2. (Real, Default = 1.0)
``S1``, ``S2``
  Shear relief coefficient due to taper for plane 1 and plane
  2. Ignored for beam p-elements.  (Real, Default = 0.0)
``NSI(A)``, ``NSI(B)``
  Nonstructural mass moment of inertia per unit length about
  nonstructural mass center of gravity at end ``A`` and end
  ``B``. (Real, Default = 0.0, same as end A)
``CW(A)``, ``CW(B)``
  Warping coefficient for end ``A`` and end ``B``. Ignored for beam
  p-elements. (Real, Default = 0.0, same as end ``A``)
``M1(A)``, ``M2(A)``, ``M1(B)``, ``M2(B)``
  *(y,z)* coordinates of center of gravity of nonstructural mass for
  end ``A`` and end ``B``. (Real, Default = 0.0 (no offset from shear
  center), same values as end ``A``)
``N1(A)``, ``N2(A)``, ``N1(B)``, ``N2(B)``
  *(y,z)* coordinates of neutral axis for end ``A`` and end
  ``B``. (Real)
 */

    class pbeam : public bdf_card {
      // Handle Nastran Bulk PBEAM entries.

    private:

      static const entry_type<long> _PID;
      static const entry_type<long> _MID;
      static const entry_type<double> _A;
      static const entry_type<double> _I1;
      static const entry_type<double> _I2;
      static const entry_type<double> _I12;
      static const entry_type<double> _J;
      static const entry_type<double> _NSM;
      static const entry_type<double> _C1;
      static const entry_type<double> _C2;
      static const entry_type<double> _D1;
      static const entry_type<double> _D2;
      static const entry_type<double> _E1;
      static const entry_type<double> _E2;
      static const entry_type<double> _F1;
      static const entry_type<double> _F2;
      static const entry_type<::std::string> _SO;
      static const entry_type<double> _X_XB;
      static const entry_type<double> _K1;
      static const entry_type<double> _K2;
      static const entry_type<double> _S1;
      static const entry_type<double> _S2;
      static const entry_type<double> _NSI_A;
      static const entry_type<double> _NSI_B;
      static const entry_type<double> _CW_A;
      static const entry_type<double> _CW_B;
      static const entry_type<double> _M1_A;
      static const entry_type<double> _M2_A;
      static const entry_type<double> _M1_B;
      static const entry_type<double> _M2_B;
      static const entry_type<double> _N1_A;
      static const entry_type<double> _N2_A;
      static const entry_type<double> _N1_B;
      static const entry_type<double> _N2_B;

    public:

      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> MID;
      // fields that might appear more than once
      ::std::deque<::std::unique_ptr<double>> A;
      ::std::deque<::std::unique_ptr<double>> I1;
      ::std::deque<::std::unique_ptr<double>> I2;
      ::std::deque<::std::unique_ptr<double>> I12;
      ::std::deque<::std::unique_ptr<double>> J;
      ::std::deque<::std::unique_ptr<double>> NSM;
      ::std::deque<::std::unique_ptr<double>> C1;
      ::std::deque<::std::unique_ptr<double>> C2;
      ::std::deque<::std::unique_ptr<double>> D1;
      ::std::deque<::std::unique_ptr<double>> D2;
      ::std::deque<::std::unique_ptr<double>> E1;
      ::std::deque<::std::unique_ptr<double>> E2;
      ::std::deque<::std::unique_ptr<double>> F1;
      ::std::deque<::std::unique_ptr<double>> F2;
      ::std::deque<::std::unique_ptr<::std::string>> SO;
      ::std::deque<::std::unique_ptr<double>> X_XB;
      // fields_finish
      ::std::unique_ptr<double> K1;
      ::std::unique_ptr<double> K2;
      ::std::unique_ptr<double> S1;
      ::std::unique_ptr<double> S2;
      ::std::unique_ptr<double> NSI_A;
      ::std::unique_ptr<double> NSI_B;
      ::std::unique_ptr<double> CW_A;
      ::std::unique_ptr<double> CW_B;
      ::std::unique_ptr<double> M1_A;
      ::std::unique_ptr<double> M2_A;
      ::std::unique_ptr<double> M1_B;
      ::std::unique_ptr<double> M2_B;
      ::std::unique_ptr<double> N1_A;
      ::std::unique_ptr<double> N2_A;
      ::std::unique_ptr<double> N1_B;
      ::std::unique_ptr<double> N2_B;

      DllExport pbeam(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return PBEAM; };

    };

    class l_geom {

    protected:

      l_geom () {};

      static const ::std::set<::std::string> dimnum1;
      static const ::std::set<::std::string> dimnum2;
      static const ::std::set<::std::string> dimnum3;
      static const ::std::set<::std::string> dimnum4;
      static const ::std::set<::std::string> dimnum5;
      static const ::std::set<::std::string> dimnum6;
      static const ::std::set<::std::string> dimnum10;
    };
/*
Handle Nastran Bulk PBEAML entries.

Format:
.......

(Note: n = number of dimensions and m = number of intermediate stations)

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| PBEAML| PID   | MID   | GROUP | TYPE  |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       |DIM1(A)|DIM2(A)| -etc.-|DIMn(A)| NSM(A)| SO(1) |X(1)/XB|DIM1(1)|    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       |DIM2(1)|-etc.- |DIMn(1)| NSM(1)| SO(2) |X(2)/XB|DIM1(2)|DIM2(2)|    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | -etc.-|DIMn(2)| NSM(m)| -etc.-| SO(m) |X(m)/XB|DIM1(m)| -etc.-|    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       |DIMn(m)| NSM(m)| SO(B) | 1.0   |DIM1(B)|DIM2(B)| -etc.-|DIMn(B)|    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       |       | NSM(B)|       |       |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``PID``
  Property identification number. (Integer > 0)
``MID``
  Material identification number. (Integer > 0)
``GROUP``
  Cross-section group. (Character; Default = ``MSCBML0``)
``TYPE``
  Cross-section shape. (Character: ``ROD``, ``TUBE``, ``L``, ``I``,
  ``CHAN``, ``T``, ``BOX``, ``BAR``, ``CROSS``, ``H``, ``T1``, ``I1``,
  ``CHAN1``, ``Z``, ``CHAN2``, ``T2``, ``BOX1``, ``HEXA``, ``HAT``,
  ``HAT1``, ``DBOX`` for GROUP = ``MSCBML0``)
``DIMi(j)``
  Cross-section dimensions at end ``A``, intermediate station *j* and
  end ``B``.  (Real > 0.0 for ``GROUP`` = ``MSCBML0``)
``NSM(j)``
  Nonstructural mass per unit length. (Default = 0.0)
``SO(j)``, ``SO(B)``
  Stress output request option for intermediate station j and end B.
  (Character; Default = ``YES``):

  ``YES``
    Stresses recovered at all points on next continuation and shown in
    Figure 8-116 as ``C``, ``D``, ``E``, and ``F``.
  ``NO``
    No stresses or forces are recovered.

``X(j)/XB``
  Distance from end ``A`` to intermediate station *j* in the element
  coordinate system divided by the length of the element. (Real>0.0;
  Default = 1.0)
 */

    class pbeaml : public bdf_card, private l_geom {
      // Handle Nastran Bulk PBEAML entries.

    private:

      static const entry_type<long> _PID;
      static const entry_type<long> _MID;
      static const entry_type<::std::string> _GROUP;
      static const entry_type<::std::string> _TYPE;
      static const entry_type<double> _DIM;
      static const entry_type<double> _NSM;
      static const entry_type<::std::string> _SO;
      static const entry_type<double> _X_XB;

    public:

      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> MID;
      ::std::unique_ptr<::std::string> GROUP;
      ::std::unique_ptr<::std::string> TYPE;
      // fields that might appear more than once
      ::std::deque<::std::deque<::std::unique_ptr<double>>*> DIM;
      ::std::deque<::std::unique_ptr<double>> NSM;
      ::std::deque<::std::unique_ptr<::std::string>> SO;
      ::std::deque<::std::unique_ptr<double>> X_XB;

      DllExport pbeaml(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return PBEAML; };

    };

/*
Handle Nastran Bulk PBAR entries.

Format:
.......

(Note: n = number of dimensions and m = number of intermediate stations)

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| PBAR  | PID   | MID   | A     | I1    | I2    | J     |NSM(A) |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | C1    | C2    | D1    | D2    | E1    | E2    | F1    | F2    |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | K1    | K2    | I12   |       |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``PID``
  Property identification number. (Integer > 0)
``MID``
  Material identification number. (Integer > 0)
``A``
  Area of bar coss section. (Real; Default = 0.0)
``I1``, ``I2``, ``I12``
  Area moments of inertia. (Real; I1 >= 0, I2 >= 0, I1*I2 > I12^2; Default=0.0)
``J``
  Torsional constant. (Real)
``NSM``
  Nonstructural mass per unit length. (Real, Default=0.0)
``Ci``, ``Di``, ``Ei``, ``Fi``
  Stress recovery coefficients. (Real; Default=0.0)
``K1``, ``K2``
  Area factor for shear. (Real or böank)
 */

    class pbar : public bdf_card {

    private:

      static const entry_type<long> _PID;
      static const entry_type<long> _MID;
      static const entry_type<double> _A;
      static const entry_type<double> _I1;
      static const entry_type<double> _I2;
      static const entry_type<double> _J;
      static const entry_type<double> _NSM;
      static const entry_type<double> _C1;
      static const entry_type<double> _C2;
      static const entry_type<double> _D1;
      static const entry_type<double> _D2;
      static const entry_type<double> _E1;
      static const entry_type<double> _E2;
      static const entry_type<double> _F1;
      static const entry_type<double> _F2;
      static const entry_type<double> _K1;
      static const entry_type<double> _K2;
      static const entry_type<double> _I12;

    public:

      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> MID;
      ::std::unique_ptr<double> A;
      ::std::unique_ptr<double> I1;
      ::std::unique_ptr<double> I2;
      ::std::unique_ptr<double> J;
      ::std::unique_ptr<double> NSM;
      ::std::unique_ptr<double> C1;
      ::std::unique_ptr<double> C2;
      ::std::unique_ptr<double> D1;
      ::std::unique_ptr<double> D2;
      ::std::unique_ptr<double> E1;
      ::std::unique_ptr<double> E2;
      ::std::unique_ptr<double> F1;
      ::std::unique_ptr<double> F2;
      ::std::unique_ptr<double> K1;
      ::std::unique_ptr<double> K2;
      ::std::unique_ptr<double> I12;

      DllExport pbar(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return PBAR; };
    };

/*
Handle Nastran Bulk PBARL entries.

Format:
.......

(Note: n = number of dimensions and m = number of intermediate stations)

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| PBARL | PID   | MID   | GROUP | TYPE  |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | DIM1  | DIM2  | DIM3  | DIM4  | DIM5  | DIM6  | DIM7  | DIM8  |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | DIM9  |-etc.- | NSM  )|       |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``PID``
  Property identification number. (Integer > 0)
``MID``
  Material identification number. (Integer > 0)
``GROUP``
  Cross-section group. (Character; Default = ``MSCBML0``)
``TYPE``
  Cross-section shape. (Character: ``ROD``, ``TUBE``, ``L``, ``I``,
  ``CHAN``, ``T``, ``BOX``, ``BAR``, ``CROSS``, ``H``, ``T1``, ``I1``,
  ``CHAN1``, ``Z``, ``CHAN2``, ``T2``, ``BOX1``, ``HEXA``, ``HAT``,
  ``HAT1``, ``DBOX`` for GROUP = ``MSCBML0``)
``DIMi``
  Cross-section dimensions.  (Real > 0.0 for ``GROUP`` = ``MSCBML0``)
``NSM``
  Nonstructural mass per unit length. ``NSM`` is specified after the
  last ``DIMi``. (Default = 0.0)
 */

    class pbarl : public bdf_card, private l_geom {
      // Handle Nastran Bulk PBARL entries.

    private:

      static const entry_type<long> _PID;
      static const entry_type<long> _MID;
      static const entry_type<::std::string> _GROUP;
      static const entry_type<::std::string> _TYPE;
      static const entry_type<double> _DIM;
      static const entry_type<double> _NSM;

    public:

      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> MID;
      ::std::unique_ptr<::std::string> GROUP;
      ::std::unique_ptr<::std::string> TYPE;
      ::std::deque<::std::unique_ptr<double>> DIM;
      ::std::unique_ptr<double> NSM;

      DllExport pbarl(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return PBARL; };
    };

/*
Handle Nastran Bulk PROD entries.

Rod Property

Defines the properties of a rod element (`CROD` entry).

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| PROD  | PID   | MID   | A     | J     | C     | NSM   |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``PID``
  Property identification number. (Integer > 0)
``MID``
  Material identification number. See Remarks 2. and 3. (Integer > 0)
``A``
  Area of the rod. (Real)
``J``
  Torsional constant. (Real)
``C``
  Coefficient to determine torsional stress. (Real; Default = 0.0)
``NSM``
  Nonstructural mass per unit length. (Real)
 */

    class prod : public bdf_card {
      // Handle Nastran Bulk PROD entries.

    private:

      static const entry_type<long> _PID;
      static const entry_type<long> _MID;
      static const entry_type<double> _A;
      static const entry_type<double> _J;
      static const entry_type<double> _C;
      static const entry_type<double> _NSM;

    public:

      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> MID;
      ::std::unique_ptr<double> A;
      ::std::unique_ptr<double> J;
      ::std::unique_ptr<double> C;
      ::std::unique_ptr<double> NSM;

      DllExport prod(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return PROD; };
    };
  }
}

#endif // _BERHOL20150721_BDF_CARDS_PROPERTIES

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
