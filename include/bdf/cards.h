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
#include "bdf/types.h"

#ifdef _MSC_VER
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

namespace bdf {
  namespace cards {

    typedef enum {
      UNKNOWN,
      GRID,
      MAT1,
      CTRIA3, CQUAD4, PSHELL,
      CBEAM, PBEAM, PBEAML, BEAM_PROP,
      CBAR, PBAR, PBARL, BAR_PROP, BEAM_BASE,
      CROD, PROD,
      FORCE, MOMENT, LOAD,
      ENDDATA
    } types;

    typedef enum {LONG, SHORT, FREE} out_form_type;

    class card {

    private:

      // two character strings for continuation lines in Free Form
      // Format cards.
      static const std::set<char> free_form_cont;

      static const std::map<std::string, types> cardtype_map;


    public:

      DllExport static std::deque<std::string>
      card_split(std::deque<std::string> const &);

      DllExport card (const std::deque<std::string> &);
      DllExport card ();

      virtual const bdf::cards::types card_type(void) const = 0;
      virtual const std::ostream& operator << (std::ostream& os) const = 0;

      static out_form_type out_form;

    };

    class unknown : public card {

    public:

      DllExport unknown(const std::deque<std::string> &inp) :
        card(inp), content(inp) {};

      DllExport const bdf::cards::types card_type(void) const { return UNKNOWN; }

      std::deque<std::string> content;

      DllExport const std::ostream& operator << (std::ostream& os) const {
        throw bdf_error("can't write UNKNOWN.");
        return os;
      };
    };

    class enddata : public card {

      /*
      NASTRAN ``BDF`` ``ENDDATA`` representation.
      */

    public:

      DllExport enddata(const std::deque<std::string> &inp) :
        card(inp) {};

      DllExport const bdf::cards::types card_type(void) const { return ENDDATA; };

      DllExport const std::ostream& operator << (std::ostream& os) const {
        os << "ENDDATA" << std::endl;
        return os;
      };
    };

    class grid : public card {

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

      static const bdf::types::entry_type<long> _ID;
      static const bdf::types::entry_type<long> _CP;
      static const bdf::types::entry_type<double> _X1;
      static const bdf::types::entry_type<double> _X2;
      static const bdf::types::entry_type<double> _X3;
      static const bdf::types::entry_type<long> _CD;
      static const bdf::types::entry_type<std::deque<int>> _PS;
      static const bdf::types::entry_type<long> _SEID;

    public:

      std::unique_ptr<long> ID;
      std::unique_ptr<long> CP;
      std::unique_ptr<double> X1;
      std::unique_ptr<double> X2;
      std::unique_ptr<double> X3;
      std::unique_ptr<long> CD;
      std::unique_ptr<std::deque<int>> PS;
      std::unique_ptr<long> SEID;

      DllExport grid(const std::deque<std::string> &);
      DllExport grid(long &ID, long &CP, double &X1, double &X2, double &X3);

      DllExport const bdf::cards::types card_type(void) const { return GRID; };

      DllExport const std::ostream& operator << (std::ostream& os) const;
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

    class mat1 : public card {
      // NASTRAN ``BDF`` ``MAT1`` representation.

    private:

      static const bdf::types::entry_type<long> _MID;
      static const bdf::types::entry_type<double> _E;
      static const bdf::types::entry_type<double> _G;
      static const bdf::types::entry_type<double> _NU;
      static const bdf::types::entry_type<double> _RHO;
      static const bdf::types::entry_type<double> _A;
      static const bdf::types::entry_type<double> _TREF;
      static const bdf::types::entry_type<double> _GE;
      static const bdf::types::entry_type<double> _ST;
      static const bdf::types::entry_type<double> _SC;
      static const bdf::types::entry_type<double> _SS;
      static const bdf::types::entry_type<long> _MCSID;

    public:

      std::unique_ptr<long> MID;
      std::unique_ptr<double> E;
      std::unique_ptr<double> G;
      std::unique_ptr<double> NU;
      std::unique_ptr<double> RHO;
      std::unique_ptr<double> A;
      std::unique_ptr<double> TREF;
      std::unique_ptr<double> GE;
      std::unique_ptr<double> ST;
      std::unique_ptr<double> SC;
      std::unique_ptr<double> SS;
      std::unique_ptr<long> MCSID;

      DllExport mat1(const std::deque<std::string> &);

      DllExport const bdf::cards::types card_type(void) const { return MAT1; };

      DllExport const std::ostream& operator << (std::ostream& os) const;
    };

  }

}

#include "bdf/cards_elements.h"
#include "bdf/cards_properties.h"
#include "bdf/cards_loads.h"

namespace bdf {
  namespace cards {

      DllExport std::unique_ptr<card> dispatch(const std::deque<std::string> &);

  }
}

#endif // _BERHOL20150630_BDF_CARDS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
