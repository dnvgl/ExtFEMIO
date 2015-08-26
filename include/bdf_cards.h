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
#include <memory>

#include <my_c++14.h>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

#ifdef _MSC_VER
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

namespace bdf {

  using namespace types;

  namespace cards {

    typedef enum {
      UNKNOWN,
      GRID,
      MAT1,
      CTRIA3, CQUAD4, PSHELL,
      CBEAM, PBEAM, PBEAML,
      CBAR, PBAR, PBARL,
      CROD, PROD,
      ENDDATA
    } types;

    class bdf_card {

    private:

      // two character strings for continuation lines in Free Form
      // Format cards.
      static const ::std::set<char> free_form_cont;

    public:

      DllExport static ::std::deque<::std::string>
      card_split(::std::deque<::std::string> const &);

#ifndef _MSC_VER
      DllExport bdf_card () = delete;
#endif
      DllExport bdf_card (const ::std::deque<::std::string> &);

      virtual ::bdf::cards::types card(void) = 0;

    };

    class unknown : public bdf_card {

    public:

      DllExport unknown(const ::std::deque<::std::string> &inp) :
        bdf_card(inp), content(inp) {};

      DllExport ::bdf::cards::types card(void) { return UNKNOWN; }

      ::std::deque<::std::string> content;

    };

    class enddata : public bdf_card {

      /*
      NASTRAN ``BDF`` ``ENDDATA`` representation.
      */

    public:

      DllExport enddata(const ::std::deque<::std::string> &inp) :
        bdf_card(inp) {};

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

    private:

      static entry_type<long> _ID;
      static entry_type<long> _CP;
      static entry_type<double> _X1;
      static entry_type<double> _X2;
      static entry_type<double> _X3;
      static entry_type<long> _CD;
      static entry_type<::std::deque<int>> _PS;
      static entry_type<long> _SEID;

    public:

      ::std::unique_ptr<long> ID;
      ::std::unique_ptr<long> CP;
      ::std::unique_ptr<double> X1;
      ::std::unique_ptr<double> X2;
      ::std::unique_ptr<double> X3;
      ::std::unique_ptr<long> CD;
      ::std::unique_ptr<::std::deque<int>> PS;
      ::std::unique_ptr<long> SEID;

      DllExport grid(const ::std::deque<::std::string> &);

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

    private:

      static entry_type<long> _MID;
      static entry_type<double> _E;
      static entry_type<double> _G;
      static entry_type<double> _NU;
      static entry_type<double> _RHO;
      static entry_type<double> _A;
      static entry_type<double> _TREF;
      static entry_type<double> _GE;
      static entry_type<double> _ST;
      static entry_type<double> _SC;
      static entry_type<double> _SS;
      static entry_type<long> _MCSID;

    public:

      ::std::unique_ptr<long> MID;
      ::std::unique_ptr<double> E;
      ::std::unique_ptr<double> G;
      ::std::unique_ptr<double> NU;
      ::std::unique_ptr<double> RHO;
      ::std::unique_ptr<double> A;
      ::std::unique_ptr<double> TREF;
      ::std::unique_ptr<double> GE;
      ::std::unique_ptr<double> ST;
      ::std::unique_ptr<double> SC;
      ::std::unique_ptr<double> SS;
      ::std::unique_ptr<long> MCSID;

      DllExport mat1(const ::std::deque<::std::string> &);

      DllExport ::bdf::cards::types card(void) { return MAT1; };

    };

  }

}

#include "bdf_cards_elements.h"
#include "bdf_cards_properties.h"

namespace bdf {
  namespace cards {

    DllExport bdf_card *dispatch(
      const ::std::deque<::std::string> &);

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
