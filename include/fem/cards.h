/**
   \file fem/cards.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Classes for the differen Sesame FEM cards.

   Detailed description
*/

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _FEM_CARDS_H_
#define _FEM_CARDS_H_

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

            /**
               \brief Name the different cards.
            */
            typedef enum {
               UNKNOWN,
               /// Date and Program Information
               DATE,
               /// Nodal Coordinates
               GCOORD,
               /// Correspondence between External and Internal
               /// Node Numbering, and Number of Degrees of
               /// Freedom of Each Node
               GNODE,
               /// Identification of Superelements
               IDENT,
               /// End of a Superelement
               IEND,
               /// Element Data Definition
               GELMNT1,
               /// Reference to Element Data
               GELREF1,
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
# Format

|         |        |           |         |         |
| ------- | ------ | --------- | ------- | ------- |
| `DATE`  | `TYPE` | `SUBTYPE` | `NRECS` | `NBYTE` |
|         | \<text lines\>                   | | | |
|         | \<text lines\>                   | | | |

The identifier is used to transfer date and program information on the
Interface File.

The following NRECS records must be read in A format, 72 characters
per record.

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

               /** Value giving information on how to use this text.

                   - = 1 Text concerning current superelement.

                   - = 2 Text concerning children of current superelement
                   (not implemented).
               */
               long TYPE;
               /**
                  - = 0 If current superelement (TYPE = 1).

                  - > 0 Subelement no. referring to the current
                  superelement (only if TYPE = 2).
               */
               long SUBTYPE;
               /** Number of records to be read in A-format, `NRECS` ≥ 1.
                */
               long NRECS;
               /** Number of significant bytes on the text records, 1 ≤
                   `NBYTE` ≤ 72.
               */
               long NBYTE;
               /** Text lines

                   The eight first bytes on the text records shall be
                   filled with blanks.
               */
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

            /// `GCOORD`: Nodal Coordinates
/**
# Format

|          |          |          |         |          |
| -------- | -------- | -------- | ------- | -------- |
| `GCOORD` | `NODENO` | `XCOORD` | `YCOORD`| `ZCOORD` |
*/
            class gcoord : public card {

            private:

               static const ::dnvgl::extfem::fem::types::card head;

               static const
               ::dnvgl::extfem::fem::types::entry_type<long> _NODENO;
               static const
               ::dnvgl::extfem::fem::types::entry_type<double> _XCOORD;
               static const
               ::dnvgl::extfem::fem::types::entry_type<double> _YCOORD;
               static const
               ::dnvgl::extfem::fem::types::entry_type<double> _ZCOORD;

            public:

               /** Program defined (internal) node number
                */
               long NODENO;
               /** Cartesian *X*-coordinates of node `NODENO`.
                */
               double XCOORD;
               /** Cartesian *Y*-coordinates of node `NODENO`.
                */
               double YCOORD;
               /** Cartesian `Z`-coordinates of node `NODENO`.
                */
               double ZCOORD;


               DllExport gcoord(const ::std::deque<::std::string>&);

               DllExport gcoord(
                  const long *NODENO,
                  const double *XCOORD, const double *YCOORD, const double *ZCOORD);

               DllExport const ::dnvgl::extfem::fem::cards::types
               card_type(void) const;

               DllExport friend ::std::ostream&
               operator<< (::std::ostream&, const gcoord&);
               DllExport const ::std::ostream&
               operator<< (::std::ostream& os) const;
            };
            /// `GNODE`: Correspondence between External and Internal Node Numbering and Number of Degrees of Freedom of Each Node
/**
## Format

|         |         |          |        |        |
| ------- | ------- | -------- | ------ | ------ |
| `GNODE` | `NODEX` | `NODENO` | `NDOF` | `ODOF` |

There will be one record with the identifier `GNODE` for each node.
The sequence of the records will correspond to the internal node
number, `NODENO`.

Example: `NDOF`=3, `ODOF`=135 means 3 degrees of freedom in *x*, *z*
and *Ry* direction respectively in the superelement’s coordinate
system, unless a local nodal coordinate system is specified (see the
`BNDOF` and `BNTRCOS` record).
*/
            class gnode : public card {

            private:

               static const ::dnvgl::extfem::fem::types::card head;

               static const ::dnvgl::extfem::fem::types::entry_type<long> _NODEX;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _NODENO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _NDOF;
               static const ::dnvgl::extfem::fem::types::entry_type<::std::deque<int>> _ODOF;

            public:

               /** External node number (specified or controlled by user).
                */
               long NODEX;
               /** Internal node number defined by the program (may be
                   generated by internal node numbering optimalizer). The
                   internal node numbers range from 1 up to number of
                   nodes.
               */
               long NODENO;
               /** Number of degrees of freedom of nodal point `NODENO`.
                */
               long NDOF;
               /** Order of degrees of freedom. `NDOF` digits.
                */
               ::std::deque<int> ODOF;

               DllExport gnode(const ::std::deque<::std::string>&);

               DllExport gnode(
                  const long *NODEX, const long *NODENO,
                  const long *NDOF, const ::std::deque<int> *ODOF);

               DllExport gnode(
                  const long *NODEX, const long *NODENO,
                  const ::std::deque<int> *ODOF);

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

   |         |          |          |          |   |
   | ------- | -------- | -------- | -------- | - |
   | `IDENT` | `SLEVEL` | `SELTYP` | `SELMOD` |   |
*/
            class ident : public card {

            private:

               static const ::dnvgl::extfem::fem::types::card head;

               static const ::dnvgl::extfem::fem::types::entry_type<long> _SLEVEL;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _SELTYP;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _SELMOD;

            public:

               /** Superelement level.

                   The level of a superelement is defined as the highest
                   level number among its subelements plus 1. (Basic
                   elements, i.e. beams, shells, springs, etc. have level
                   zero.)
               */
               long SLEVEL;
               /** Superelement type number.
                */
               long SELTYP;
               /** Superelement model dimension

                   - = 2,      2-dimensional model

                   - = 0 or 3, 3-dimensional model.
               */
               long SELMOD;

               DllExport ident(const ::std::deque<::std::string>&);

               DllExport ident(
                  const long *SLEVEL, const long *SELTYP,
                  const long *SELMOD) :
                  SLEVEL(*SLEVEL), SELTYP(*SELTYP), SELMOD(*SELMOD) { };


               DllExport const ::dnvgl::extfem::fem::cards::types
               card_type(void) const { return IDENT; };

               DllExport friend ::std::ostream&
               operator<< (::std::ostream&, const ident&);
               DllExport const ::std::ostream&
               operator<< (::std::ostream& os) const;
            };

            /// `IEND`: End of a Superelement
/**
   ## Format

   |         |        |   |   |   |
   | ------- | ------ | - | - | - |
   | `IEND`  | `CONT` |   |   |   |

   Defines end of a superelement.
*/
            class iend : public card {

            private:

               static const ::dnvgl::extfem::fem::types::card head;

               static const ::dnvgl::extfem::fem::types::entry_type<long> _CONT;

            public:

               /** Superelement level.

                   - = 0 (Default). This is also end of the file.

                   - = 1 The superelements are concatenated on one file.
                   More superelements follows.

                   - = 2 Last superelement in a structure for a
                   concatenated file.
               */
               long CONT;

               DllExport iend(const ::std::deque<::std::string>&);

               DllExport iend(
                  const long *CONT) : CONT(*CONT) { };


               DllExport const ::dnvgl::extfem::fem::cards::types
               card_type(void) const { return IEND; };

               DllExport friend ::std::ostream&
               operator<< (::std::ostream&, const iend&);
               DllExport const ::std::ostream&
               operator<< (::std::ostream& os) const;
            };

            /// `GELMNT1`: Element Data Definition
/**
   # Format

   |           |         |          |           |          |
   | --------- | ------- | -------- | --------- | -------- |
   | `GELMNT1` | `ELNOX` | `ELNO`   | `ELTYP`   | `ELTYAD` |
   |           | `NODIN1`| 'NODIN2` | \dots     | \dots    |
   |           | \dots   | \dots    | `NODIN(N) |          |
*/
            class gelmnt1 : public card {

            private:

               static const ::dnvgl::extfem::fem::types::card head;

               static const ::dnvgl::extfem::fem::types::entry_type<long> _ELNOX;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _ELNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _ELTYP;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _ELTYAD;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _NODIN;

            public:

               /** External element number (specified or controlled by
                   user). */
               long ELNOX;
               /** Internal element number (generated by program)
                */
               long ELNO;
               /** Element type number. Refer to chapter 5 in file format
                   documentation for description of legal type no. For
                   element type no. 70 (’matrix element’) all relevant
                   element data are stored as stiffness, mass, damping
                   matrices a.s.o. See the AMATRIX record for more
                   information.
               */
               long ELTYP;
               /** Additional information related to element type.

                   - For membrane elements used to specify plane stress /
                   plane strain conditions

                   - =0: Plane stress
                   - =1: Plane strain

                   - For two noded beam elements used to specify
                   structural / non-structural elements:

                   - =0: Structural beam
                   - =1: Non structural beam

                   - For general matrix element (elem. type 70) used to
                   specify number of nodes

                   - = `NNOD` Number of nodes on the matrix element
               */
               long ELTYAD;
               /** Internal node numbers in the assembly, to which this
                   element is connected.

                   The sequence of the node numbers is in accordance with the
                   local node numbering of the basic element.

                   By ’internal node numbers’ is meant the node numbering of
                   the entire superelement of which the element `ELNOX` is a
                   part. The internal node number refers to the node number
                   generated by the program. The program-defined element
                   number ranges from 1 up to number of elements. The sequence
                   of the records will correspond to the program-defined
                   element numbering, `ELNO`.
               */
               ::std::deque<long> NODIN;

               DllExport gelmnt1(const ::std::deque<::std::string>&);

               DllExport gelmnt1(
                  const long *ELNOX, const long *ELNO,
                  const long *ELTYP, const long *ELTYAD,
                  const ::std::deque<long> *NODIN);

               DllExport const ::dnvgl::extfem::fem::cards::types
               card_type(void) const;

               DllExport friend ::std::ostream&
               operator<< (::std::ostream&, const gelmnt1&);
               DllExport const ::std::ostream&
               operator<< (::std::ostream& os) const;
            };

            /// `GELREF1`: Reference to Element Data
/**
   # Format

   |           |              |              |              |                |
   | --------- | ------------ | ------------ | ------------ | -------------- |
   | `GELREF1` | `ELNO`       | `MATNO`      | `ADDNO`      | `INTNO`        |
   |           | `MINTNO`     | `STRANO`     | `STRENO`     | `STREPONO`     |
   |           | `GEONO/OPT`  | `FIXNO/OPT`  | `ECCNO/OPT`  | `TRANSNO/OPT`  |
   |           | `GEONO`(1)   | \dots        | `GEONO`(*N*) | `FIXNO`(1)     |
   |           | \dots        | `FIXNO`(1)   | `ECCNO`(1)   | \dots          |
   |           | `ECCNO`(*N*) | `TRANSNO`(1) | \dots        | `TRANSNO`(*N*) |

   Shortest version:

   |           |              |              |              |                |
   | --------- | ------------ | ------------ | ------------ | -------------- |
   | `GELREF1` | `ELNO`       | `MATNO`      | `ADDNO`      | `INTNO`        |
   |           | `MINTNO`     | `STRANO`     | `STRENO`     | `STREPONO`     |
   |           | `GEONO/OPT`  | `FIXNO/OPT`  | `ECCNO/OPT`  | `TRANSNO/OPT`  |
*/

            class gelref1 : public card {

            private:

               static const ::dnvgl::extfem::fem::types::card head;

               static const ::dnvgl::extfem::fem::types::entry_type<long> _ELNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _MATNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _ADDNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _INTNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _MINTNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _STRANO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _STRENO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _STREPONO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _GEONO_OPT;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _FIXNO_OPT;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _ECCNO_OPT;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _TRANSNO_OPT;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _GEONO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _FIXNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _ECCNO;
               static const ::dnvgl::extfem::fem::types::entry_type<long> _TRANSNO;

            public:

               /** Internal element number (generated by the program).
                */
               long ELNO;
               /** Material number

                   - =0 no material data attached to the element
               */
               long MATNO;
               /** Additional data type number, i.e. number referring to
                   additional data specification

                   - =0 no additional data attached to the element
               */
               long ADDNO;
               /** Integration station reference number for stiffness
                   matrix, i.e. number referring to the specification of
                   integration stations. An integration station is defined
                   as:

                   - an assembly of integration points over a cross section
                   of a 1-dimensional (beam or bar) element,

                   - an assembly of integration points on a line through
                   the thickness of a 2-dimensional element,

                   - one single integration point for a 3-dimensional
                   element. For further explanation see record `GELINT`.

                   `INTNO` = 0: Default values of the analysis program are
                   employed.
               */
               long INTNO;
               /** Integration station reference number for mass and
                   damping matrices. Integration station, see `INTNO`.

                   `MINTNO` = 0: Default values of the analysis program are
                   employed.
               */
               long MINTNO;
               /** Initial strain number, i.e. number referring to the
                   specification of initial strains. The data type
                   containing these data is not yet defined.
               */
               long STRANO;
               /** Initial stress number, i.e. number referring to the
                   specification of initial stresses. The data type
                   containing these data is not yet defined.
               */
               long STRENO;
               /** Stresspoint specification reference number. See record
                   `GELSTRP` for further information.
               */
               long STREPONO;
               /** Geometry reference number or option for geometry
                   reference number specified later in this record
                   sequence.

                   - >0: The geometry reference number (the same for all nodes in the element).
                   `GEONO`(1), \dots, `GEONO`(*N*) will not be specified.

                   - =0: No geometry data is given, i.e. neither here nor
                   on `GEONO`(1), ¸dots, `GEONO`(*N*).

                   - =-1: Reference numbers to geometry data are specified
                   later in this record sequence for all nodes, i.e. all
                   `GEONO`(1), \dots, `GEONO`(*N*) will be given.
               */
               long GEONO_OPT;
               /** Fixation reference number or option for fixation
                   reference numbers specified later in this record
                   sequence. The meaning assigned to the values of
                   `FIXNO_OPT` corresponds to those for `GEONO_OPT`.
               */
               long FIXNO_OPT;
               /** Eccentricity reference number or option for eccentricity
                   reference numbers specified later in this record
                   sequence. The meaning assigned to the values of
                   `ECCNO_OPT` corresponds to those for `GEONO_OPT`.
               */
               long ECCNO_OPT;
               /** Reference number for local coordinate system
                   specification or option for specification of local nodal
                   coordinate systems later in this record sequence. Refers
                   to `GUNIVEC` or `BNTRCOS` record. The meaning assigned
                   to the values of `TRANSNO_OPT` corresponds to those for
                   `GEONO_OPT`.
               */
               long TRANSNO_OPT;
               /** Geometry reference number for the local nodes of the
                   element.
               */
               ::std::deque<long> GEONO;
               /** Number referring to the specification of degree of
                   fixation (Data type `BELFIX`). `FIXNO`[0] is the reference
                   number for the 1st local node of the element, FIXNO[*i*-1]
                   will be the reference number for the *i*’th local node.
               */
               ::std::deque<long> FIXNO;
               /** Eccentricity number for the local nodes of the element,
                   i.e. number referring to the specification of
                   eccentricities.
               */
               ::std::deque<long> ECCNO;
               /** Number referring to the specification of the local
                   element coordinate system for the local nodes of the
                   element. Refers to `BNTRCOS` or `GUNIVEC` record
                   depending on element type.
               */
               ::std::deque<long> TRANSNO;

               DllExport gelref1(const ::std::deque<::std::string>&);

               DllExport gelref1(
                  const long *ELNO, const long *MATNO,
                  const long *ADDNO, const long *INTNO,
                  const long *MINTNO, const long *STRANO,
                  const long *STRENO, const long *STREPONO,
                  const long *GEONO_OPT, const long *FIXNO_OPT,
                  const long *ECCNO_OPT, const long *TRANSNO_OPT,
                  const ::std::deque<long> *GEONO=nullptr,
                  const ::std::deque<long> *FIXNO=nullptr,
                  const ::std::deque<long> *ECCNO=nullptr,
                  const ::std::deque<long> *TRANSNO=nullptr);

               DllExport const ::dnvgl::extfem::fem::cards::types
               card_type(void) const;

               DllExport friend ::std::ostream&
               operator<< (::std::ostream&, const gelref1&);
               DllExport const ::std::ostream&
               operator<< (::std::ostream& os) const;
            };


            /// `TEXT`: User supplied Text
/**
   # Format

   |         |        |           |         |         |
   | ------- | ------ | --------- | ------- | ------- |
   | `TEXT`  | `TYPE` | `SUBTYPE` | `NRECS` | `NBYTE` |
   |         | \<text lines\>                   | | | |

   The identifier is used to transfer text-strings on the interface file.
   The following NRECS records must be read in A-format, 72 characters
   per record.
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

               /** Value giving information of how to use this text

                   - = 1 Texts describing this analysis/global text

                   - = 2 Texts concerning current superelement

                   - = 3 Text concerning specific load cases

                   - ≥ 4 The meaning of text to be mutually agreed on by
                   preprosessor and analysis program
               */
               long TYPE;
               /** Value giving additional information to `TYPE`

                   Example: For `TYPE` = 3, `SUBTYPE` gives load case
                   number
               */
               long SUBTYPE;
               /** Number of records following to be read in A-format.
                   `NRECS` ≥ 1
               */
               long NRECS;
               /** Number of significant bytes (characters) on the
                   following `NRECS` records. 1 ≤ `NBYTE` ≤ 72
               */
               long NBYTE;
               /** Text lines

                   The eight first bytes on the text records shall be
                   filled with blanks.
               */
               ::std::deque<::std::string> CONT;

               DllExport text(const ::std::deque<::std::string>&);

               DllExport text(
                  const long *TYPE, const long *SUBTYPE,
                  const long *NRECS, const long *NBYTE,
                  const ::std::deque<::std::string> *CONT);

               DllExport text(
                  const long *TYPE, const long *SUBTYPE,
                  const ::std::deque<::std::string> *CONT);

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

#include "fem/elements.h"
#include "fem/cards_properties.h"
#include "fem/cards_loads.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {
            DllExport void
            dispatch(const ::std::deque<::std::string>&,
                     ::std::unique_ptr<card>&);
         }
      }
   }
}
#endif // _FEM_CARDS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// coding: utf-8
// End:
