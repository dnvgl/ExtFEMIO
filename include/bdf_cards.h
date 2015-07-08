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

    typedef enum {UNKNOWN, ENDDATA, GRID} types;

    class bdf_card {

    private:

// two character strings for continuation lines in Free Form
      // Format cards.
      static const ::std::set<char> free_form_cont;

    public:

      DllExport static ::std::deque<::std::string> card_split(::std::deque<::std::string>);

      DllExport bdf_card ();

      virtual ::bdf::cards::types card(void) = 0;

    };

    class unknown : public bdf_card {

    public:

      DllExport unknown(::std::deque<::std::string> inp) : content(inp) {};

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

      bdf_int ID;
      bdf_int CP;
      bdf_float X1;
      bdf_float X2;
      bdf_float X3;
      bdf_int CD;
      bdf_list<int> PS;
      bdf_int SEID;

      DllExport grid(::std::deque<::std::string>);

      DllExport ::bdf::cards::types card(void) { return GRID; };

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
// compile-command: "make -C .. check -j 7"
// coding: utf-8
// End:
