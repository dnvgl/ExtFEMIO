// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for BDF element property cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150721_BDF_CARDS_PROPERTIES
#define _BERHOL20150721_BDF_CARDS_PROPERTIES

#include <memory>

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

      static bdf_int _PID;
      static bdf_int _MID1;
      static bdf_float _T;
      static bdf_int _MID2;
      static bdf_float _12I_T__3; // 12 I / T**3
      static bdf_int _MID3;
      static bdf_float _TS_T; // TS / T
      static bdf_float _NSM;
      static bdf_float _Z1;
      static bdf_float _Z2;
      static bdf_int _MID4;

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
