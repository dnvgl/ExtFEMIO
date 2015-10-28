// Copyright © 2015 by DNV GL SE

// Classes for the different Nastran BDF cards dealing with loads.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20151016_BDF_CARDS_LOADS
#define _BERHOL20151016_BDF_CARDS_LOADS

#include <memory>

namespace bdf {

  namespace cards {


    class momforce_base : public card {
      // Base class for handling forces and moments.

    private:

      static const bdf::types::entry_type<long> _SID;
      static const bdf::types::entry_type<long> _G;
      static const bdf::types::entry_type<long> _CID;
      static const bdf::types::entry_type<double> _F;
      static const bdf::types::entry_type<double> _N1;
      static const bdf::types::entry_type<double> _N2;
      static const bdf::types::entry_type<double> _N3;

    public:

      std::unique_ptr<long> SID;
      std::unique_ptr<long> G;
      std::unique_ptr<long> CID;
      std::unique_ptr<double> F;
      std::unique_ptr<double> N1;
      std::unique_ptr<double> N2;
      std::unique_ptr<double> N3;

    protected:

      DllExport momforce_base(const std::deque<std::string> &inp);
      DllExport momforce_base(long &SID, long &G, long &CID,
                              double &F,
                              double &N1, double &N2, double &N3);

      DllExport const std::ostream& operator << (std::ostream& os) const;
    };

    /*
Handle Nastran Bulk FORCE entries.

Static Force

Defines a static concentrated force at a grid point by specifying a
vector.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| FORCE | SID   | G     | CID   | F     | N1    | N2    | N3    |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``SID``
  Load set identification number. (Integer > 0)
``G``
  Grid point identification number. (Integer > 0)
``CID``
  Coordinate system identification number. (Integer > 0; Default = 0)
``F``
  Scale factor. (Real)
``Ni``
  Components of a vector measured in coordinate system defined by CID.
  (Real; at least one Ni ≠ 0.0.)
     */

    class force : public momforce_base {
      // Handle Nastran Bulk FORCE entries.

    public:

      DllExport force(const std::deque<std::string> &inp) :
        momforce_base(inp) {};

      DllExport force(long &SID, long &G, long &CID,
                      double &F,
                      double &N1, double &N2, double &N3) :
        momforce_base(SID, G, CID, F, N1, N2, N3) {};

      DllExport const bdf::cards::types card_type(void) const {
        return FORCE;
      };

      DllExport const std::ostream& operator << (std::ostream& os) const;
    };

    /*
Handle Nastran Bulk MOMENT entries.

Static Force

Defines a static concentrated force at a grid point by specifying a
vector.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|MOMENT | SID   | G     | CID   | F     | N1    | N2    | N3    |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``SID``
  Load set identification number. (Integer > 0)
``G``
  Grid point identification number. (Integer > 0)
``CID``
  Coordinate system identification number. (Integer > 0; Default = 0)
``F``
  Scale factor. (Real)
``Ni``
  Components of a vector measured in coordinate system defined by CID.
  (Real; at least one Ni ≠ 0.0.)
     */

    class moment : public momforce_base {
      // Handle Nastran Bulk MOMENT entries.

    public:

      DllExport moment(const std::deque<std::string> &inp) :
        momforce_base(inp) {};
      DllExport moment(long &SID, long &G, long &CID,
                      double &F,
                      double &N1, double &N2, double &N3) :
        momforce_base(SID, G, CID, F, N1, N2, N3) {};

      DllExport const bdf::cards::types card_type(void) const {
        return MOMENT;
      };

      DllExport const std::ostream& operator << (std::ostream& os) const;
    };

/*
Handle Nastran Bulk LOAD entries.

Static Load Combination (Superposition)

Defines a static load as a linear combination of load sets defined via
FORCE, MOMENT, FORCE1, MOMENT1, FORCE2, MOMENT2, DAREA (if these
entries have been converted), PLOAD, PLOAD1, PLOAD2, PLOAD4, PLOADX1,
SLOAD, RFORCE, and GRAV entries.

Format:
.......

+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
| LOAD  | SID   | S     | S1    | L1    | S2    | L2    | S3    | L3    |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+
|       | S4    | L4    | -etc.-|       |       |       |       |       |    |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+----+

Description:
............

``SID``
  Load set identification number. (Integer > 0)
``S``
  Overall scale factor. (Real)
``Si``
  Scale factor on Li. (Real)
``Li``
  Load set identification numbers defined on entry types listed above.
  (Integer > 0)
 */
    class load : public card {

    public:

      DllExport load(const std::deque<std::string> &inp);

      DllExport load(long &SID, long &S,
                     std::deque<double> &Si, std::deque<long> &Li);

      DllExport const bdf::cards::types card_type(void) const {
        return LOAD;
      };

      DllExport const std::ostream& operator << (std::ostream& os) const;
    };
  }
}

#endif // _BERHOL20151016_BDF_CARDS_LOADS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
