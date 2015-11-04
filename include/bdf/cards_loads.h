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

namespace dnvgl {
  namespace extfem {
    namespace bdf {
      namespace cards {

        class momforce_base : public card {
          // Base class for handling forces and moments.

        private:

          static const ::dnvgl::extfem::bdf::types::entry_type<long> _SID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _CID;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _F;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _N1;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _N2;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _N3;

        public:

          std::unique_ptr<long> SID;
          std::unique_ptr<long> G;
          std::unique_ptr<long> CID;
          std::unique_ptr<double> F;
          std::unique_ptr<double> N1;
          std::unique_ptr<double> N2;
          std::unique_ptr<double> N3;

        protected:

          void add_collect(std::deque<std::unique_ptr<format_entry>>&,
                           const momforce_base&) const;

          DllExport momforce_base(const std::deque<std::string> &inp);
          DllExport momforce_base(
            const long *SID, const long *G, const long *CID,
            const double *F,
            const double *N1, const double *N2, const double *N3);

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

        private:

          static std::unique_ptr<::dnvgl::extfem::bdf::types::base> head;

        public:

          DllExport force(const std::deque<std::string> &inp) :
            momforce_base(inp) {};

          DllExport force(
            const long *SID, const long *G, const long *CID,
            const double *F,
            const double *N1, const double *N2=nullptr, const double *N3=nullptr) :
            momforce_base(SID, G, CID, F, N1, N2, N3) {};

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
            return FORCE;
          };

          DllExport friend std::ostream& operator<<(std::ostream&, const force&);
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

        private:

          static std::unique_ptr<::dnvgl::extfem::bdf::types::base> head;

        public:

          DllExport moment(const std::deque<std::string> &inp) :
            momforce_base(inp) {};
          DllExport moment(
            const long *SID, const long *G, const long *CID,
            const double *F,
            const double *N1, const double *N2=nullptr, const double *N3=nullptr) :
            momforce_base(SID, G, CID, F, N1, N2, N3) {};

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
            return MOMENT;
          };

          DllExport friend std::ostream& operator<<(std::ostream&, const moment&);
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

        private:

          static const ::dnvgl::extfem::bdf::types::entry_type<long> _SID;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _S;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _Si;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _Li;

        public:

          std::unique_ptr<long> SID;
          std::unique_ptr<double> S;
          std::unique_ptr<std::deque<double>> Si;
          std::unique_ptr<std::deque<long>> Li;

          DllExport load(const std::deque<std::string> &inp);

          DllExport load(long &SID, double &S,
                         std::deque<double> &Si, std::deque<long> &Li);

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
            return LOAD;
          };

          DllExport const std::ostream& operator << (std::ostream& os) const;
        };
      }
    }
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
