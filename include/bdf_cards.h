// Copyright © 2015 by DNV GL SE

// Classes for the different Nastran BDF cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20150630_BDF_CARDS
#define _BERHOL20150630_BDF_CARDS

#include <deque>
#include <string>
#include <set>
#include <map>
#include <utility>

#include "bdf_types.h"

#ifdef _MSC_VER
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

namespace bdf {

  using namespace types;

  namespace cards {

    typedef enum {UNKNOWN, ENDDATA, GRID, MID1} types;

    class bdf_card {

    private:

// two character strings for continuation lines in Free Form
      // Format cards.
      static const ::std::set<char> free_form_cont;

    public:

      DllExport static ::std::deque<::std::string>
      card_split(::std::deque<::std::string>);

      DllExport bdf_card ();

      virtual ::bdf::cards::types card(void) = 0;

    };

    class unknown : public bdf_card {

    public:

      DllExport unknown(::std::deque<::std::string> inp) :
        content(inp) {};

      DllExport ::bdf::cards::types card(void) { return UNKNOWN; }

      ::std::deque<::std::string> content;

    };

    class enddata : public bdf_card {

      /*
      NASTRAN ``BDF`` ``ENDDATA`` representation.
      */

    public:

      DllExport enddata(::std::deque<::std::string>) {};

      DllExport ::bdf::cards::types card(void) { return ENDDATA; };

    };

    class grid : public bdf_card {

      /*
Handle Nastran Bulk GRID entries.

Grid Point

Defines the location of a geometric grid point, the directions of its
displacement, and its permanent single-point constraints.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| GRID  | ID    | CP    | X1    | X2    | X3    | CD    | PS    | SEID  |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``ID``
  Grid point identification number. (0 < Integer < 100000000)
``CP``
  Identification number of coordinate system in which the location of
  the grid point is defined. (Integer > 0 or blank)
``X1``, ``X2``, ``X3``
  Location of the grid point in coordinate system CP. (Real; Default = 0.0)
``CD``
  Identification number of coordinate system in which the
  displacements, degrees-of-freedom, constraints, and solution deques
  are defined at the grid point. (Integer > -1 or blank)
``PS``
  Permanent single-point constraints associated with the grid
  point. (Any of the Integers 1 through 6 with no embedded blanks, or
  blank.)
``SEID``
  Superelement identification number. (Integer > 0; Default = 0)
      */

    public:

      static bdf_int _ID;
      static bdf_int _CP;
      static bdf_float _X1;
      static bdf_float _X2;
      static bdf_float _X3;
      static bdf_int _CD;
      static bdf_list<int> _PS;
      static bdf_int _SEID;

      long ID;
      long CP;
      double X1;
      double X2;
      double X3;
      long CD;
      ::std::deque<int>* PS;
      long SEID;

      DllExport grid(::std::deque<::std::string>);

      DllExport ::bdf::cards::types card(void) { return GRID; };

    };

/*
Handle Nastran Bulk MAT1 entries.

Isotropic Material Property Definition

Defines the material properties for linear isotropic materials.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| MAT1  | MID   | E     | G     | NU    | RHO   | A     | TREF  | GE    |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | ST    | SC    | SS    | MCSID |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``MID``
  Material identification number. (Integer > 0)
``E``
  Youn g’s modulus. (Real > 0.0 or blank)
``G``
  Shear modulus. (Real > 0.0 or blank)
``NU``
  Poisson’s ratio. (-1.0 < Real < 0.5 or blank)
``RHO``
  Mass density. See Remark 5. (Real)
``A``
  Thermal expansion coefficient. (Real)
``TREF``
  Reference temperature for the calculation of thermal loads, or a
  temperature-dependent thermal expansion coefficient. (Real; Default
  = 0.0 if A is specified.)
``GE``
  Structural element damping coefficient. (Real)
``ST``, ``SC``, ``SS``
  Stress limits for tension, compression, and shear are optionally
  supplied, used only to compute margins of safety in certain
  elements; and have no effect on the computational procedures. (Real
  > 0.0 or blank)
``MCSID``
  Material coordinate system identification number. Used only for
  ``PARAM,CURV`` processing.  (Integer > 0 or blank)
*/

    class mat1 : public bdf_card {
      // NASTRAN ``BDF`` ``MAT1`` representation.

    public:

      static bdf_int _MID;
      static bdf_float _E;
      static bdf_float _G;
      static bdf_float _NU;
      static bdf_float _RHO;
      static bdf_float _A;
      static bdf_float _TREF;
      static bdf_float _GE;
      static bdf_float _ST;
      static bdf_float _SC;
      static bdf_float _SS;
      static bdf_int _MCSID;

      long MID;
      double E;
      double G;
      double NU;
      double RHO;
      double A;
      double TREF;
      double GE;
      double ST;
      double SC;
      double  SS;
      long MCSID;

      DllExport mat1(::std::deque<::std::string>);

      DllExport ::bdf::cards::types card(void) { return MID1; };

    };

    DllExport bdf_card *dispatch(::std::deque<::std::string>);

  }

}

#endif // _BERHOL20150630_BDF_CARDS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
