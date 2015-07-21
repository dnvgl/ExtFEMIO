// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for BDF element type cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150714_BDF_CARDS_ELEMENTS
#define _BERHOL20150714_BDF_CARDS_ELEMENTS

#include <memory>

namespace bdf {

  using namespace types;

  namespace cards {

    // Base class for `ctria3' and `cquad4'.
    class bdf_shell : public bdf_card {

    protected:

      static bdf_int _EID;
      static bdf_int _PID;
      static bdf_int _G1;
      static bdf_int _G2;
      static bdf_int _G3;
      static bdf_int _MCID;
      static bdf_float _THETA;
      static bdf_float _ZOFFS;
      static bdf_int _TFLAG;
      static bdf_float _T1;
      static bdf_float _T2;
      static bdf_float _T3;

      DllExport bdf_shell(const ::std::deque<::std::string> &inp) :
        bdf_card(inp) {};

    public:

      typedef enum {has_MCID, has_THETA} CHOOSE_MCID_THETA;

      CHOOSE_MCID_THETA choose_mcid_theta;

      ::std::unique_ptr<long> EID;
      ::std::unique_ptr<long> PID;
      ::std::unique_ptr<long> G1;
      ::std::unique_ptr<long> G2;
      ::std::unique_ptr<long> G3;
      ::std::unique_ptr<long> MCID;
      ::std::unique_ptr<double> THETA;
      ::std::unique_ptr<double> ZOFFS;
      ::std::unique_ptr<long> TFLAG;
      ::std::unique_ptr<double> T1;
      ::std::unique_ptr<double> T2;
      ::std::unique_ptr<double> T3;
    };

/*
Handle Nastran Bulk CTRIA3 entries.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| CTRIA3| EID   | PID   | G1    | G2    | G3    | THETA | ZOFFS |       |    |
|       |       |       |       |       |       | or    |       |       |    |
|       |       |       |       |       |       | MCID  |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       |       | TFLAG | T1    | T2    | T3    |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``EID``
  Element identification number. (Integer > 0)
``PID``
  Property identification number of a ``PSHELL``, ``PCOMP`` or
  ``PLPLANE`` entry. (Integer > 0; Default = ``EID``)
``Gi``
  Grid point identification numbers of connection points. (Integers > 0,
  all unique)

``THETA``
  Material property orientation angle in degrees. ``THETA`` is ignored
  for hyperelastic elements. (Real; Default = 0.0)
``MCID``
  Material coordinate system identification number. The x-axis of the
  material coordinate system is determined by projecting the x-axis of
  the ``MCID`` coordinate system (defined by the ``CORDij`` entry or
  zero for the basic coordinate system) onto the surface of the
  element. ``MCID`` is ignored for hyperelastic elements. (Integer >
  0; if blank, then ``THETA`` = 0.0 is assumed.)
``ZOFFS``
  Offset from the surface of grid points to the element reference
  plane. ``ZOFFS`` is ignored for hyperelastic elements. (Real)
``TFLAG``
  An integer flag, signifying the meaning of the ``Ti``
  values. (Integer 0, 1, or blank)
``Ti``
  Membrane thickness of element at grid points G1 through G4. If
  ``TFLAG`` zero or blank, then ``Ti`` are actual user specified
  thickness. (Real > 0.0 or blank, not all zero.) If ``TFLAG`` one,
  then the ``Ti`` are fraction relative to the ``T`` value of the
  ``PSHELL``. (Real > 0.0 or blank; not all zero. Default = 1.0)
  ``Ti`` are ignored for hyperelastic elements.
 */

    class ctria3 : public bdf_shell {
      // NASTRAN ``BDF`` ``CTRIA3`` representation.

    public:

      DllExport ctria3(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return CTRIA3; };

    };

/*
Handle Nastran Bulk CQUAD4 entries.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|CQUAD4 | EID   | PID   | G1    | G2    | G3    | G4    | THETA | ZOFFS |    |
|       |       |       |       |       |       |       | or    |       |    |
|       |       |       |       |       |       |       | MCID  |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       |TFLAG  | T1    | T2    | T3    | T4    |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``EID``
  Element identification number. (Integer > 0)
``PID``
  Property identification number of a ``PSHELL``, ``PCOMP``, or
  ``PLPLANE`` entry. (Integer > 0; Default = ``EID``)
``Gi``
  Grid point identification numbers of connection points. (Integers
  > 0, all unique.)
``THETA``
  Material property orientation angle in degrees. ``THETA`` is
  ignored for hyperelastic elements. (Real; Default = 0.0)
``MCID``
  Material coordinate system identification number. The x-axis of
  the material coordinate system is determined by projecting the
  x-axis of the ``MCID`` coordinate system (defined by the
  ``CORDij`` entry or zero for the basic coordinate system) onto the
  surface of the element. ``MCID`` is ignored for hyperelastic
  elements. (Integer > 0; If blank, then ``THETA`` = 0.0 is
  assumed.)
``ZOFFS``
  Offset from the surface of grid points to the element reference
  plane.  ``ZOFFS`` is ignored for hyperelastic elements. (Real)
``TFLAG``
  An integer flag, signifying the meaning of the Ti values. (Integer
  0, 1, or blank)
``Ti``
  Membrane thickness of element at grid points ``G1`` through
  ``G4``. If ``TFLAG`` is zero or blank, then ``Ti`` are actual user
  specified thicknesses.  (Real > 0.0 or blank, not all zero.) If
  ''TFLAG`` is one, then the ``Ti`` are fractions relative to the
  ``T`` value of the ``PSHELL``.  (Real > 0.0 or blank, not all
  zero. Default = 1.0) ``Ti`` are ignored for hyperelastic elements.
 */

    class cquad4 : public bdf_shell {
      // NASTRAN ``BDF`` ``CQUAD4`` representation.

    private:

      static bdf_int _G4;
      static bdf_float _T4;

    public:

      ::std::unique_ptr<long> G4;
      ::std::unique_ptr<double> T4;

      DllExport cquad4(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return CQUAD4; };

    };

  }
}

#endif // _BERHOL20150714_BDF_CARDS_ELEMENTS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
