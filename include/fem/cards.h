// Copyright © 2015 by DNV GL SE#

// Classes for the differen Sesame FEM cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20151111_CARDS
#define _BERHOL20151111_CARDS

#include <deque>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <memory>

#include "extfem_misc.h"

#include <my_c++14.h>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "fem/types.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace cards {

        typedef enum {
          UNKNOWN,
          /// Date and Program Information
          DATE,
          /// Correspondence between External and Internal
          /// Node Numbering, and Number of Degrees of
          /// Freedom of Each Node
          GNODE,
          // /// Nodal Coordinates
          // GCOORD,
          /// Identification of Superelements
          IDENT,
          // /// Element Data Definition
          // GELMNT1,
          // /// Reference to Element Data
          // GELREF1,
          // /// Cross Section Type Massive Bar
          // GBARM,
          // /// General Beam Element Data
          // GBEAMG,
          // /// Eccentricities
          // GECCEN,
          // /// Thickness of Two-dimensional Elements
          // GELTH,
          // /// Cross Section Type I or H Beam
          // GIORH,
          // /// Cross Section Type L-Section
          // GLSEC,
          // /// Cross Section Type Tube
          // GPIPE,
          // /// Nodes with Linear Dependence
          // BLDEP,
          // /// Nodes with Boundary Conditions
          // BNBCD,
          // /// Nodes with Prescribed Displacements and
          // /// Accelerations
          // BNDISPL,
          // /// Nodes with Loads
          // BNLOAD,
          // /// Element to Ground
          // MGSPRNG,
          // /// End of a Superelement
          // IEND,
          // /// Set (group) of Nodes or Elements (Members)
          // GSETMEMB,
          // /// Specification of Local Element Coordinate
          // /// System
          // GUNIVEC,
          // /// Isotropy, Linear Elastic Structural Analysis
          // MISOSEL,
          // /// Name and Description of a Set (group)
          // TDSETNAM,
          /// User supplied Text
          TEXT,
          // /// *not documented*
          // TDLOAD,
        } types;

        class card {

        private:

          /// two character strings for continuation lines in Free Form
          /// Format cards.
          static const ::std::set<char> free_form_cont;

          static const ::std::map<::std::string, types> cardtype_map;

        protected:

          static ::dnvgl::extfem::fem::types::empty empty;

          static ::dnvgl::extfem::fem::types::card head;

        public:

          DllExport static ::std::deque<::std::string>
          card_split(::std::deque<::std::string> const &);

          DllExport card (const ::std::deque<::std::string> &);
          DllExport card ();

          virtual const ::dnvgl::extfem::fem::cards::types card_type(void) const = 0;
          virtual const ::std::ostream& operator<<(::std::ostream&) const = 0;
        };

        class unknown : public card {

        public:

          DllExport unknown(const ::std::deque<::std::string> &inp) :
            card(inp), content(inp) {};

          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const { return UNKNOWN; }

          ::std::deque<::std::string> content;

          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const {
            throw errors::error("can't write UNKNOWN.");
            return os;
          };

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const unknown&);
        };

        /// `DATE`: Date and Program Information
/**
## Format

|       |               |               |               |               |
| ----- | ------------- | ------------- | ------------- | ------------- |
| DATE  | TYPE          | SUBTYPE       | NRECS         | NBYTE         |
|       | \<text lines\>                                             ||||
|       | \<text lines\>                                             ||||

The identifier is used to transfer date and program information on the
Interface File.

The following NRECS records must be read in A format, 72 characters
per record.

## Description

- `TYPE` : Value giving information on how to use this text.

    - = 1 Text concerning current superelement.

    - = 2 Text concerning children of current superelement (not
          implemented).

- `SUBTYPE` :

    - = 0 If current superelement (TYPE = 1).

    - > 0 Subelement no. referring to the current superelement (only if
          TYPE = 2).

- `NRECS` : Number of records to be read in A-format, `NRECS` ≥ 1.

- `NBYTE` : Number of significant bytes on the text records, 1 ≤
  `NBYTE` ≤ 72.

   The eight first bytes on the text records shall be filled with
   blanks.

Example of format of `DATE` record as used in SESAM:

~~~{txt}
DATE      0.10000000E+01  0.00000000E+00  0.40000000E+01  0.72000000E+02
        DATE:     23-MAY-86           TIME:         13:53:03
        PROGRAM:  SESAM WALOCO        VERSION:      5.1-0 15-MAY-86
        COMPUTER: VAX VMS V4.3        INSTALLATION: VERITEC
        USERID:   999XXXX             ACCOUNT:      ZZZZZZZ

------------------------------------------------------------------------
123456789.123456789.123456789.123456789.123456789.123456789.123456789.12
         1         2         3         4         5         6         7
------------------------------------------------------------------------
~~~
*/
        class date : public card {

        private:

          static const ::dnvgl::extfem::fem::types::card head;

          static const ::dnvgl::extfem::fem::types::entry_type<long> _TYPE;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SUBTYPE;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _NRECS;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _NBYTE;
          static const ::dnvgl::extfem::fem::types::entry_type<::std::string> _CONT;

        public:

          long TYPE;
          long SUBTYPE;
          long NRECS;
          long NBYTE;
          ::std::deque<::std::string> CONT;

          DllExport date(const ::std::deque<::std::string>&);

          DllExport date(
            const long *TYPE, const long *SUBTYPE,
            const long *NRECS, const long *NBYTE,
            const ::std::deque<::std::string> *CONT) :
            TYPE(*TYPE), SUBTYPE(*SUBTYPE), NRECS(*NRECS),
            NBYTE(*NBYTE), CONT(*CONT) {};

          DllExport date(
            const long *TYPE, const long *SUBTYPE,
            const ::std::deque<::std::string> *CONT) :
            TYPE(*TYPE), SUBTYPE(*SUBTYPE), CONT(*CONT) {
            NRECS = static_cast<long>(CONT->size());
            NBYTE = 0;
            for (auto &p : *CONT)
              NBYTE = (NBYTE < (long)p.size()) ? (long)p.size() : NBYTE;
          };

          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const;

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const date&);
          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const;
        };

        /// `GNODE`: Correspondence between External and Internal Node Numbering and Number of Degrees of Freedom of Each Node
/**
## Format

|       |               |               |               |               |
| ----- | ------------- | ------------- | ------------- | ------------- |
| GNODE | NODEX         | NODENO        | NDOF          | ODOF          |

## Description

- `NODEX` : External node number (specified or controlled by user).

- `NODENO` : Internal node number defined by the program (may be
  generated by internal node numbering optimalizer). The internal node
  numbers range from 1 up to number of nodes.

- `NDOF` : Number of degrees of freedom of nodal point `NODENO`.

- `ODOF` : Order of degrees of freedom. `NDOF` digits.

  Example: `NDOF`=3, `ODOF`=135 means 3 degrees of freedom in x, z and
  Ry direction respectively in the superelement’s coordinate system,
  unless a local nodal coordinate system is specified (see the `BNDOF`
  and `BNTRCOS` record).

There will be one record with the identifier `GNODE` for each node.
The sequence of the records will correspond to the internal node
number, `NODENO`.
 */
        class gnode : public card {

        private:

          static const ::dnvgl::extfem::fem::types::card head;

          static const ::dnvgl::extfem::fem::types::entry_type<long> _NODEX;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SUBTYPE;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _NRECS;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _NBYTE;
          static const ::dnvgl::extfem::fem::types::entry_type<::std::string> _CONT;

        public:

          long TYPE;
          long SUBTYPE;
          long NRECS;
          long NBYTE;
          ::std::deque<::std::string> CONT;

          DllExport gnode(const ::std::deque<::std::string>&);

          DllExport gnode(
            const long *TYPE, const long *SUBTYPE,
            const long *NRECS, const long *NBYTE,
            const ::std::deque<::std::string> *CONT) :
            TYPE(*TYPE), SUBTYPE(*SUBTYPE), NRECS(*NRECS),
            NBYTE(*NBYTE), CONT(*CONT) {};

          DllExport gnode(
            const long *TYPE, const long *SUBTYPE,
            const ::std::deque<::std::string> *CONT) :
            TYPE(*TYPE), SUBTYPE(*SUBTYPE), CONT(*CONT) {
            NRECS = static_cast<long>(CONT->size());
            NBYTE = 0;
            for (auto &p : *CONT)
              NBYTE = (NBYTE < (long)p.size()) ? (long)p.size() : NBYTE;
          };

          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const;

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const gnode&);
          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const;
        };

        /// `IDENT`: Identification of Superelements
/**
## Format

|       |               |               |               |               |
| ----- | ------------- | ------------- | ------------- | ------------- |
| IDENT | SLEVEL        | SELTYP        | SELMOD        |               |

## Description

- `SLEVEL` : Superelement level.

  The level of a superelement is defined as the highest level number
  among its subelements plus 1. (Basic elements, i.e. beams, shells,
  springs, etc. have level zero.)

- `SELTYP` : Superelement type number.

- `SELMOD` : Superelement model dimension

  - = 2,      2-dimensional model

  - = 0 or 3, 3-dimensional model.
*/
        class ident : public card {

        private:

          static const ::dnvgl::extfem::fem::types::card head;

          static const ::dnvgl::extfem::fem::types::entry_type<long> _SLEVEL;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SELTYP;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SELMOD;

        public:

          long SLEVEL;
          long SELTYP;
          long SELMOD;

          DllExport ident(const ::std::deque<::std::string>&);

          DllExport ident(
            const long *iSLEVEL, const long *iSELTYP,
            const long *iSELMOD) {
            SLEVEL = *iSLEVEL;
            SELTYP = *iSELTYP;
            SELMOD = *iSELMOD;
          };


          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const { return IDENT; };

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const ident&);
          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const;
        };

        /// `TEXT`: User supplied Text
/**
# Format

|       |               |               |               |               |
| ----- | ------------- | ------------- | ------------- | ------------- |
| TEXT  | TYPE          | SUBTYPE       | NRECS         | NBYTE         |
|       | \<text lines\>                                             ||||

The identifier is used to transfer text-strings on the interface file.
The following NRECS records must be read in A-format, 72 characters
per ecord.

# Description

- `TYPE` : Value giving information of how to use this text

    - = 1 Texts describing this analysis/global text

    - = 2 Texts concerning current superelement

    - = 3 Text concerning specific load cases

    - ≥ 4 The meaning of text to be mutually agreed on by preprosessor
        and analysis program

- `SUBTYPE` : Value giving additional information to `TYPE`

  Example: For `TYPE` = 3, `SUBTYPE` gives load case number

- `NRECS` : Number of records following to be read in A-format.
  `NRECS` ≥ 1

- `NBYTE` : Number of significant bytes (characters) on the following
  `NRECS` records. 1 ≤ `NBYTE` ≤ 72

  The eight first bytes on the text records shall be filled with
  blanks.
 */
        class text : public card {

        private:

          static const ::dnvgl::extfem::fem::types::card head;

          static const ::dnvgl::extfem::fem::types::entry_type<long> _TYPE;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SUBTYPE;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _NRECS;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _NBYTE;
          static const ::dnvgl::extfem::fem::types::entry_type<::std::string> _CONT;

        public:

          long TYPE;
          long SUBTYPE;
          long NRECS;
          long NBYTE;
          ::std::deque<::std::string> CONT;

          DllExport text(const ::std::deque<::std::string>&);

          DllExport text(
            const long *TYPE, const long *SUBTYPE,
            const long *NRECS, const long *NBYTE,
            const ::std::deque<::std::string> *CONT) :
            TYPE(*TYPE), SUBTYPE(*SUBTYPE), NRECS(*NRECS),
            NBYTE(*NBYTE), CONT(*CONT) {};

          DllExport text(
            const long *TYPE, const long *SUBTYPE,
            const ::std::deque<::std::string> *CONT) :
            TYPE(*TYPE), SUBTYPE(*SUBTYPE), CONT(*CONT) {
            NRECS = static_cast<long>(CONT->size());
            NBYTE = 0;
            for (auto &p : *CONT)
              NBYTE = (NBYTE < (long)p.size()) ? (long)p.size() : NBYTE;
          };

          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const;

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const text&);
          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const;
        };
      }
    }
  }
}

#include "fem/cards_elements.h"
#include "fem/cards_properties.h"
#include "fem/cards_loads.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace cards {
        DllExport ::std::unique_ptr<card> dispatch(const ::std::deque<::std::string> &);
      }
    }
  }
}
#endif // _BERHOL20151111_CARDS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// coding: utf-8
// End:
