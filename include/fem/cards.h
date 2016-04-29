/**
   \file fem/cards.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Classes for the differen Sesame FEM cards.

   Detailed description
*/

// ID: $Id$

#pragma once

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
            class gelmnt1;
            class gelref1;
            class gbeamg;
            class misosel;
            // class beiste;
         }
      }
   }
}

#include "fem/elements.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            extern const void(*note_report)(std::string const &);
            extern const void(*info_report)(std::string const &);
            extern const void(*warn_report)(std::string const &);
            extern const void(*error_report)(std::string const &);

            /**
               \brief Name the different cards.
            */
            typedef enum types {
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
               /// Cross Section Type Massive Bar
               GBARM,
               /// General Beam Element Data
               GBEAMG,
               /// Eccentricities
               GECCEN,
               /// Thickness of Two-dimensional Elements
               GELTH,
               /// Cross Section Type I or H Beam
               GIORH,
               /// Cross Section Type L-Section
               GLSEC,
               /// Cross Section Type Tube
               GPIPE,
               /// Cross Section Type Unsymmetrical I-Beam
               GUSYI,
               /// Flexible Joint/Hinge
               BELFIX,
               /// Nodes with Linear Dependence
               BLDEP,
               /// Nodes with Boundary Conditions
               BNBCD,
               /// Nodes with Prescribed Displacements and
               /// Accelerations
               BNDISPL,
               /// Nodes with Loads
               BNLOAD,
               /// Element to Ground
               MGSPRNG,
               /// set (group) of Nodes or Elements (Members)
               GSETMEMB,
               /// Specification of Local Element Coordinate
               /// System
               GUNIVEC,
               /// Isotropy, Linear Elastic Structural Analysis
               MISOSEL,
               /// Name and Description of a set (group)
               TDSETNAM,
               /// Name and Description of a Super-Element.
               TDSUPNAM,
               /// User supplied Text
               TEXT,
               /// Name of Load
               TDLOAD,
               /// Subelement Load Description
               BSELL,
               /// Subelement Description with Simple Correspondence
               /// between Degrees of Freedom of Subelement and
               /// Relevant Assembly
               GELMNT2,
               /// Superelement Statistical Information
               HSUPSTAT,
               /// Superelement Transformations
               HSUPTRAN,
               /// Superelement Hierarchy Description
               HIERARCH,
               /// Elements with Surface Loads
               BEUSLO
            } types;

            class card {

            private:

               /// two character strings for continuation lines in Free Form
               /// Format cards.
               static const std::set<char> free_form_cont;

               static const std::map<std::string, types> cardtype_map;

            protected:

               static dnvgl::extfem::fem::types::empty empty;

               static dnvgl::extfem::fem::types::card head;

            public:

               static void
               card_split(std::deque<std::string> const &, std::deque<std::string>&);

               card (std::deque<std::string> const &);
               card ();

               virtual const dnvgl::extfem::fem::cards::types
               card_type(void) const = 0;

               virtual const std::ostream&
               operator<< (std::ostream&) const = 0;
            };

            class unknown : public card {

            public:

               unknown(std::deque<std::string> const &inp);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               std::deque<std::string> content;

               friend  std::ostream&
               operator<< (std::ostream&, unknown const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `DATE`: Date and Program Information
/**
## Format

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

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_TYPE;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_SUBTYPE;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NRECS;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NBYTE;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_CONT;

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
               std::deque<std::string> CONT;

               date(std::deque<std::string> const &);

               date(void);

               date(
                  long const &TYPE, long const &SUBTYPE,
                  long const &NRECS, long const &NBYTE,
                  std::deque<std::string> const &CONT);

               date(
                  long const &TYPE, long const &SUBTYPE,
                  std::deque<std::string> const &CONT);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, date const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GCOORD`: Nodal Coordinates
/**
## Format

|          |          |          |         |          |
| -------- | -------- | -------- | ------- | -------- |
| `GCOORD` | `NODENO` | `XCOORD` | `YCOORD`| `ZCOORD` |
*/
            class gcoord : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               static const
               dnvgl::extfem::fem::types::entry_type<long> _form_NODENO;
               static const
               dnvgl::extfem::fem::types::entry_type<double> _form_XCOORD;
               static const
               dnvgl::extfem::fem::types::entry_type<double> _form_YCOORD;
               static const
               dnvgl::extfem::fem::types::entry_type<double> _form_ZCOORD;

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

               gcoord(std::deque<std::string> const &);

               gcoord(void);

               gcoord(
                  long const &NODENO,
                  double const &XCOORD, double const &YCOORD, double const &ZCOORD);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gcoord const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
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

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODEX;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODENO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDOF;
               dnvgl::extfem::fem::types::entry_type<std::deque<int>> static const _form_ODOF;

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
               std::deque<int> ODOF;

               gnode(std::deque<std::string> const &);

               gnode(void);

               gnode(
                  long const &NODEX, long const &NODENO,
                  long const &NDOF, std::deque<int> const &ODOF);

               gnode(
                  long const &NODEX, long const &NODENO,
                  std::deque<int> const &ODOF);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gnode const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
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

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_SLEVEL;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_SELTYP;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_SELMOD;

            public:

               typedef enum {DIM_2D=2, DIM_3D=3, INVALID=-1} mod_type;


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
               mod_type SELMOD;

               ident(std::deque<std::string> const &);

               ident(void);

               ident(
                  long const &SLEVEL, long const &SELTYP,
                  mod_type const &SELMOD);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, ident const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
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

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_CONT;

            public:

               /** Superelement level.

                   - = 0 (Default). This is also end of the file.

                   - = 1 The superelements are concatenated on one file.
                   More superelements follows.

                   - = 2 Last superelement in a structure for a
                   concatenated file.
               */
               long CONT;

               iend(std::deque<std::string> const &);

               iend(void);

               iend(long const &CONT);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, iend const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GELMNT1`: Element Data Definition
/**
## Format

|           |                       |                       |                       |          |
| --------- | --------------------- | --------------------- | --------------------- | -------- |
| `GELMNT1` | `ELNOX`               | `ELNO`                | `ELTYP`               | `ELTYAD` |
|           | `NODIN`<sub>`1`</sub> | `NODIN`<sub>`2`</sub> | ...                   | ...      |
|           | ...                   | ...                   | `NODIN`<sub>`N`</sub> |          |
*/
            class gelmnt1 : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_ELNOX;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ELNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ELTYP;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ELTYAD;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODIN;

               static const std::map<long, dnvgl::extfem::fem::elements::el_types> eltyp_map;

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
               dnvgl::extfem::fem::elements::el_types ELTYP;
               /** Additional information related to element type.

                   - For membrane elements used to specify plane stress /
                   plane strain conditions

                     =0: Plane stress

                     =1: Plane strain

                   - For two noded beam elements used to specify
                   structural / non-structural elements:

                     =0: Structural beam

                     =1: Non structural beam

                   - For general matrix element (elem. type 70) used to
                   specify number of nodes

                     = `NNOD` Number of nodes on the matrix element
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
               std::deque<long> NODIN;

               gelmnt1(std::deque<std::string> const &);

               gelmnt1(void);

               gelmnt1(
                  long const &ELNOX, long const &ELNO,
                  dnvgl::extfem::fem::elements::el_types const &ELTYP, long const &ELTYAD,
                  std::deque<long> const &NODIN);

               gelmnt1(
                  long const &ELNOX, long const &ELNO,
                  dnvgl::extfem::fem::elements::el_types const &ELTYP,
                  std::deque<long> const &NODIN);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gelmnt1 const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

            /// `GELREF1`: Reference to Element Data
/**
## Format

|           |              |              |              |                |
| --------- | ------------ | ------------ | ------------ | -------------- |
| `GELREF1` | `ELNO`       | `MATNO`      | `ADDNO`      | `INTNO`        |
|           | `MINTNO`     | `STRANO`     | `STRENO`     | `STREPONO`     |
|           | `GEONO/OPT`  | `FIXNO/OPT`  | `ECCNO/OPT`  | `TRANSNO/OPT`  |
|           | `GEONO`(1)   | ...          | `GEONO`(*N*) | `FIXNO`(1)     |
|           | ...          | `FIXNO`(1)   | `ECCNO`(1)   | ...            |
|           | `ECCNO`(*N*) | `TRANSNO`(1) | ...          | `TRANSNO`(*N*) |

Shortest version:

|           |              |              |              |                |
| --------- | ------------ | ------------ | ------------ | -------------- |
| `GELREF1` | `ELNO`       | `MATNO`      | `ADDNO`      | `INTNO`        |
|           | `MINTNO`     | `STRANO`     | `STRENO`     | `STREPONO`     |
|           | `GEONO/OPT`  | `FIXNO/OPT`  | `ECCNO/OPT`  | `TRANSNO/OPT`  |
*/

            class gelref1 : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_ELNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_MATNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ADDNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_INTNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_MINTNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_STRANO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_STRENO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_STREPONO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_GEONO_OPT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_FIXNO_OPT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ECCNO_OPT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_TRANSNO_OPT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_GEONO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_FIXNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ECCNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_TRANSNO;

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
                   `GEONO`(1), ..., `GEONO`(*N*) will not be specified.

                   - =0: No geometry data is given, i.e. neither here nor
                   on `GEONO`(1), ..., `GEONO`(*N*).

                   - =-1: Reference numbers to geometry data are specified
                   later in this record sequence for all nodes, i.e. all
                   `GEONO`(1), ..., `GEONO`(*N*) will be given.
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
               std::deque<long> GEONO;
               /** Number referring to the specification of degree of
                   fixation (Data type `BELFIX`). `FIXNO`[0] is the reference
                   number for the 1st local node of the element, FIXNO[*i*-1]
                   will be the reference number for the *i*’th local node.
               */
               std::deque<long> FIXNO;
               /** Eccentricity number for the local nodes of the element,
                   i.e. number referring to the specification of
                   eccentricities.
               */
               std::deque<long> ECCNO;
               /** Number referring to the specification of the local
                   element coordinate system for the local nodes of the
                   element. Refers to `BNTRCOS` or `GUNIVEC` record
                   depending on element type.
               */
               std::deque<long> TRANSNO;

               gelref1(std::deque<std::string> const &);

               gelref1(void);

               gelref1(
                  long const &ELNO, long const &MATNO,
                  long const &ADDNO, long const &INTNO,
                  long const &MINTNO, long const &STRANO,
                  long const &STRENO, long const &STREPONO,
                  long const &GEONO_OPT, long const &FIXNO_OPT,
                  long const &ECCNO_OPT, long const &TRANSNO_OPT,
                  std::deque<long> const &GEONO={},
                  std::deque<long> const &FIXNO={},
                  std::deque<long> const &ECCNO={},
                  std::deque<long> const &TRANSNO={});

               const dnvgl::extfem::fem::cards::types
                  card_type(void) const;

               friend  std::ostream&
                  operator<< (std::ostream&, gelref1 const &);

               const std::ostream&
                  operator<< (std::ostream& os) const;
            };

/// Base class for FEM beam property describing classes.
            class BeamProp : public card {

               BeamProp();

            protected:

               dnvgl::extfem::fem::types::entry_type<long> static const _form_GEONO;

               BeamProp(long const &GEONO);

            public:

               /** Geometry type number, i.e. reference number used
                   for element data definition of geometry properties
                   (Cross sectional properties) of beams.
                */
               long GEONO;

               BeamProp(std::deque<std::string> const&);

               const virtual dnvgl::extfem::fem::cards::types
                  card_type(void) const = 0;
            };

/// `GBARM`: Cross Section Type Massive Bar
/**
## Format

|         |         |       |         |         |
| ------- | ------- | ----- | ------- | ------- |
| `GBARM` | `GEONO` | `HZ`  | `BT`    | `BB`    |
|         | `SFY`   | `SFZ` | `NLOBY` | `NLOBZ` |


\image latex gbarm.eps "Massive bar"
\image html gbarm.svg "Massive bar"
*/
            class gbarm : public BeamProp {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<double> static const _form_HZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BT;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BB;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFZ;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBY;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBZ;

            public:

               /** Height of beam.
                */
               double HZ;
               /** Width of bar at top. For massive bars which are not
                   able to have different widths at top and bottom
                   this variable is used as the width of the beam.
                */
               double BT;
               /** Width of bar at bottom.
                */
               double BB;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                     SHARY(MOD) = SHARY(PROG) · SFY
                   \f]

                   (The shear area on `GBEAMG` is SHARY(MOD)).

                */
               double SFY;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                     SHARZ(MOD) = SHARZ(PROG) · SFZ
                   \f]

                   (The shear area on `GBEAMG` is SHARZ(MOD)).
                */
               double SFZ;
               /** Number of integration points in Y’ direction
                   (optional)
                */
               long NLOBY;
               /** Number of integration points in Z’ direction
                   (optional)
                */
               long NLOBZ;

               gbarm(std::deque<std::string> const &);

               gbarm(void);

               gbarm(
                  long const &GEONO,
                  double const &HZ, double const &BT, double const &BB,
                  double const &SFY, double const &SFZ,
                  long const &NLOBY, long const &NLOBZ);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gbarm const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GBEAMG`: General Beam Element Data
/**
## Format

|          |          |          |         |         |
| -------- | -------- | -------- | ------- | ------- |
| `GBEAMG` | `GEONO`  | *void*   | `AREA`  | `IX`    |
|          | `IY`     | `IZ`     | `IYZ`   | `WXMIN` |
|          | `WYMIN`  | `WZMIN`  | `SHARY` | `SHARZ` |
|          | `SHCENY` | `SHCENZ` | `SY`    | `SZ`    |

The succeding data concern the cross section at a specific local node.

If `GBEAMG` is used for `ELTYP` 10 (Truss element) only the first
record may be on the interface.
*/
            class gbeamg : public BeamProp {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<double> static const _form_AREA;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_IX;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_IY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_IZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_IYZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_WXMIN;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_WYMIN;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_WZMIN;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SHARY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SHARZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SHCENY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SHCENZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SZ;

            public:

               /** Cross section area.
                */
               double AREA;
               /** Torsional moment of inertia about the shear center.
                */
               double IX;
               /** Moment of inertia about the *y* axis \f$= ∫z² dA\f$.
                */
               double IY;
               /** Moment of inertia about the *z* axis \f$= ∫y² dA\f$.
                */
               double IZ;
               /** Product of inertia about *y* and *z* axis \f$= ∫yz dA\f$.
                */
               double IYZ;
               /** Minimum torsional section modulus about shear
                   center (=IX/rmax for a PIPE element).
                */
               double WXMIN;
               /** Minimum sectionmodulus about *y* axis \f$= IY/zmax\f$.
                */
               double WYMIN;
               /** Minimum sectionmodulus about *z* axis = \f$IZ/ymax\f$.
                */
               double WZMIN;
               /** Shear area in the direction of *y* axis. If zero,
                   shear is not included.
                */
               double SHARY;
               /** Shear area in the direction of *z* axis. If zero,
                   shear is not included.
                */
               double SHARZ;
               /** Shear center location *y* component.
                */
               double SHCENY;
               /** Shear center location *z* component
                */
               double SHCENZ;
               /** Static area moment about *y*-axis \f$= ∫z dA\f$.
                */
               double SY;
               /** Static area moment about *z*-axis \f$= ∫y dA\f$
                */
               double SZ;

               gbeamg(std::deque<std::string> const &);

               gbeamg(void);

               gbeamg(
                  long const &GEONO,
                  double const &AREA,
                  double const &IX, double const &IY, double const &IZ, double const &IYZ,
                  double const &WXMIN, double const &WYMIN, double const &WZMIN,
                  double const &SHARY, double const &SHARZ,
                  double const &SHCENY, double const &SHCENZ,
                  double const &SY, double const &SZ);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gbeamg const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GECCEN`: Eccentricities
/**
## Format:

|          |         |      |      |      |
|--------- | ------- | ---- | ---- | ---- |
| `GECCEN` | `ECCNO` | `EX` | `EY` | `EZ` |
*/
            class geccen : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_ECCNO;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_EX;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_EY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_EZ;

            public:
               /** Eccentricity number, referenced to on record
                   `GELREF1`.
               */
               long ECCNO;
               /** *x* component of eccentricity vector given in
                   superelement coordinate system, the vector points
                   from the global node towards the local element
                   node.
                */
               double EX;
               /** *y* component of eccentricity vector given in
                   superelement coordinate system, the vector points
                   from the global node towards the local element
                   node.
                */
               double EY;
               /** *z* component of eccentricity vector given in
                   superelement coordinate system, the vector points
                   from the global node towards the local element
                   node.
                */
               double EZ;

               geccen(std::deque<std::string> const &);

               geccen(void);

               geccen(long const &ECCNO,
                      double const &EX, double const &EY, double const &EZ);

               geccen(geccen const *);

               const dnvgl::extfem::fem::cards::types
                  card_type(void) const;

               friend  std::ostream&
                  operator<< (std::ostream&, geccen const &);

               const std::ostream&
                  operator<< (std::ostream& os) const;
            };

/// `GELTH`: Thickness of Two-dimensional Elements
/**
## Format:

|         |         |      |        |   |
| ------- | ------- | ---- | ------ | - |
| `GELTH` | `GEONO` | `TH` | `NINT` |   |
*/
            class gelth : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_GEONO;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TH;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NINT;

            public:

               /** Geometry type number, i.e. referenced to by
                   `GELREF1`.
                */
               long GEONO;
               /** Thickness of the element, measured in a specific
                   node.
                */
               double TH;
               /** Number of integration points through thickness.
                */
               long NINT;

               gelth(std::deque<std::string> const &);

               gelth(void);

               gelth(
                  long const &GEONO, double const &TH, long const &NINT=0);

               const dnvgl::extfem::fem::cards::types
                  card_type(void) const;

               friend  std::ostream&
                  operator<< (std::ostream&, gelth const &);

               const std::ostream&
                  operator<< (std::ostream& os) const;
            };

/// `GIORH`: Cross Section Type I or H Beam
/**
## Format:

|         |         |          |          |         |
| ------- | ------- | -------- | -------- | ------- |
| `GIORH` | `GEONO` | `HZ`     | `TY`     | `BT`    |
|         | `TT`    | `BB`     | `TB`     | `SFY`   |
|         | `SFZ`   | `NLOBYT` | `NLOBYB` | `NLOBZ` |

\image latex giorh.eps "I or H beam"
\image html giorh.svg "I or H beam"
*/
            class giorh : public BeamProp {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<double> static const _form_HZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BT;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TT;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BB;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TB;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFZ;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBYT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBYB;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBZ;

            public:

               /** Height of beam at current location
                */
               double HZ;
               /** Thickness of beam web
                */
               double TY;
               /** Width of top flange
                */
               double BT;
               /** Thickness of top flange
                */
               double TT;
               /** Width of bottom flange
                */
               double BB;
               /** Thickness of bottom flange
                */
               double TB;
                /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                     SHARY(MOD) = SHARY(PROG) · SFY
                   \f]

                   (The shear areas on `GBEAMG` are SHARY(MOD)).
                */
               double SFY;
                /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                     SHARZ(MOD) = SHARZ(PROG) · SFZ
                   \f]

                   (The shear areas on `GBEAMG` are SHARZ(MOD)).
                */
               double SFZ;
               /** Number of integration points in top flange
                   (optional) */
               long NLOBYT;
               /** Number of integration points in bottom flange
                   (optional)
               */
               long NLOBYB;
               /** Number of integration points in beam web (optional)
                */
               long NLOBZ;

               giorh(std::deque<std::string> const &);

               giorh(void);

               giorh(
                long const &GEONO,
                double const &HZ, double const &TY, double const &BT,
                double const &TT, double const &BB, double const &TB,
                double const &SFY, double const &SFZ,
                long const &NLOBYT=0, long const &NLOBYB=0, long const &NLOBZ=0);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, giorh const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GLSEC`: Cross Section Type I or H Beam
/**
## Format:

|         |         |          |       |      |
| ------- | ------- | -------- | ----- | ---- |
| `GLSEC` | `GEONO` | `HZ`     | `TY`  | `BY` |
|         | `TZ`    | `SFY`    | `SFZ` | `K`  |
|         | `NLOBY` | `NLOBZ`  |       |      |

\image latex glsec.eps "I or H beam"
\image html glsec.svg "I or H beam"
*/
            class glsec : public BeamProp {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<double> static const _form_HZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFZ;
               dnvgl::extfem::fem::types::entry_type<bool> static const _form_K;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBY;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBZ;

            public:

               /** Height of beam at current location.
                */
               double HZ;
               /** Thickness of beam web.
                */
               double TY;
               /** Width of flange.
                */
               double BY;
               /** Thickness of flange.
                */
               double TZ;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                   SHARY(MOD) = SHARY(PROG) · SFY
                   \f]

                   (The shear area on `GBEAMG` os SHARY(MOD)).
               */
               double SFY;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                   SHARZ(MOD) = SHARZ(PROG) · SFZ
                   \f]

                   (The shear area on `GBEAMG` os SHARZ(MOD)).
               */
               double SFZ;
               /** Web orientation:

                     =0: web located in the negative local *y*-direction
                         (and consequently flange in the
                         positive *y*’-direction)

                     =1: web located in the positive local *y*-direction
                         (and consequently flange in the
                         negative *y*’-direction)
                */
               bool K;
               /** Number of integration points in beam flange
                   (optional)
               */
               long NLOBY;
               /** Number of integration points in beam web (optional)
                */
               long NLOBZ;

               glsec(std::deque<std::string> const &);

               glsec(void);

               glsec(
                long const &GEONO,
                double const &HZ, double const &TY, double const &BY,
                double const &TZ,
                double const &SFY, double const &SFZ,
                bool const &K,
                long const &NLOBY=0, long const &NLOBZ=0);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, glsec const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GPIPE`: Cross Section Type Tube
/**
## Format:

|         |         |          |        |        |
| ------- | ------- | -------- | ------ | ------ |
| `GPIPE` | `GEONO` | `DI`     | `DY`   | `T`    |
|         | `SFY`   | `SFZ`    | `NDIR` | `NRAD` |

\image latex gpipe.eps "Tube"
\image html gpipe.svg "Tube"
*/
            class gpipe : public BeamProp {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<double> static const _form_DI;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_DY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_T;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFZ;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NCIR;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NRAD;

            public:

               /** Inner diameter of tube.
                */
               double DI;
               /** Outer diameter of tube (mandatory).
                */
               double DY;
               /** Thickness of tube (not necessary if DI is given).
                */
               double T;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                   SHARY(MOD) = SHARY(PROG) · SFY
                   \f]

                   (The shear area on `GBEAMG` os SHARY(MOD)).
               */
               double SFY;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                   SHARZ(MOD) = SHARZ(PROG) · SFZ
                   \f]

                   (The shear area on `GBEAMG` os SHARZ(MOD)).
               */
               double SFZ;
               /** Number of integration points in circumferential direction (optional)
                */
               long NCIR;
               /** Number of integration points in radial direction (optional)
                */
               long NRAD;

               gpipe(std::deque<std::string> const &);

               gpipe(void);

               gpipe(
                long const &GEONO,
                double const &DI, double const &DY, double const &T,
                double const &SFY, double const &SFZ,
                long const &NDIR=0, long const &NRAD=0);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gpipe const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GUSYI`: Cross Section Type Unsymmetrical I-Beam
/**
## Format:

|         |          |         |       |          |
| ------- | -------- | ------- | ----- | -------- |
| `GUSYI` | `GEONO`  | `HZ`    | `TY`  | `BT`     |
|         | `B1`     | `TT`    | `BB`  | `B2`     |
|         | `TB`     | `SFY`   | `SFZ` | `NLOBYT` |
|         | `NLOBYB` | `NLOBZ` |       |          |

\image latex gusyi.eps "Unsymmetrical I-Beam"
\image html gusyi.svg "Unsymmetrical I-Beam"
*/
            class gusyi : public BeamProp {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<double> static const _form_HZ;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BT;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_B1;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TT;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_BB;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_B2;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_TB;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_SFZ;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBYT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBYB;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NLOBZ;


            public:

               /** Height of beam
                */
               double HZ;
               /** Thickness of beam web
                */
               double TY;
               /** Width of top flange
                */
               double BT;
               /** Width of half top-flange in positive local y-direction
                */
               double B1;
               /** Thickness of top flange
                */
               double TT;
               /** Width of bottom flange
                */
               double BB;
               /** Width of half bottom-flange in positive local y-direction
                */
               double B2;
               /** Thickness of bottom flange
                */
               double TB;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                   SHARY(MOD) = SHARY(PROG) · SFY
                   \f]

                   (The shear area on `GBEAMG` os SHARY(MOD)).
               */
               double SFY;
               /** Factor modifying the shear area calculated by the
                   preprocessor program such that the modified shear
                   area is

                   \f[
                   SHARZ(MOD) = SHARZ(PROG) · SFZ
                   \f]

                   (The shear area on `GBEAMG` os SHARZ(MOD)).
               */
               double SFZ;
               /** Number of integration points in top flange (optional)
                */
               long NLOBYT;
               /** Number of integration points in bottom flange (optional)
                */
               long NLOBYB;
               /** Number of integration points in beam web (optional)
                */
               long NLOBZ;

               gusyi(std::deque<std::string> const &);

               gusyi(void);

               gusyi(
                  long const &GEONO,
                  double const &HZ, double const &TY,
                  double const &BT, double const &B1, double const &TT,
                  double const &BB, double const &B2, double const &TB,
                  double const &SFY, double const &SFZ,
                  long const &NLOBYT=0, long const &NLOBYB=0, long const &NLOBZ=0);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gusyi const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `BELFIX`: Flexible Joint/Hinge
/**
## Format:

|          |         |        |         |        |
| -------- | ------- | ------ | ------- | ------ |
| `BELFIX` | `FIXNO` | `OPT`  | `TRANO` | *void* |
|          | `A(1)`  | `A(2)` | `A(3)`  | `A(4)` |
|          | `A(5)`  | `A(6)` |         |        |
*/
            class belfix : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_FIXNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_OPT;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_TRANO;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_A;

            public:

               typedef enum n_opt {
                  INVALID = -1, FIXATION = 1, SPRING = 2} n_opt;

               /** Fixation number to a node.
                   =FIXNO= is referenced to from =GELREF=.
                */
               long FIXNO;

               /**
                  =FIXATION: A(i) = ai is a value between 0 and 1, and
                             gives the degree of fixation
                             (connectivity) to degree of freedom
                             number i in the node. The extreme values
                             of a is described by:

                     a = 0, fully released

                     a = 1, fully connected

                  =SPRING: A(i) = Ci is the interelement elastic
                          spring stiffness to degree of freedom number
                          i in the node. The degrees of freedom which
                          are neither flexible nor free will be given
                          Ci = -1 (instead of Ci = ∞). The relation
                          between Ci and ai is

                             ai = Ci / ( kii + Ci) ≥ 0.0

                          where kii is the diagonal term of the
                          element stiffness matrix corresponding to
                          degree of freedom number i of the current
                          node.
                */
               n_opt OPT;
               /**

                  = -1: The fixation/flexibility (=A(i)) is given in
                        the superelement coordinate system.

                  =0: A(i) is given in the local element coordinate
                      system

                  >0: A(i) is given in a local coordinate system
                   defined by `TRANO`, which refers to a
                   transformation matrix given on record `BNTRCOS`.
                   The transformation matrix is defined by
                   transformation from global to local system.
               */
               long TRANO;
               /** See above (under the explanation of `OPT`).
                */
               std::deque<double> A;

               belfix(std::deque<std::string> const&);

               belfix(void);

               belfix(long const &FIXNO,
                      n_opt const &OPT,
                      long const &TRANO,
                      std::deque<double> const &A);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, belfix const &);

               const std::ostream&
               operator<< (std::ostream& os) const;

               std::string pos_string(void) const;
            };

/// `BLDEP`: Nodes with Linear Dependence
/**
## Format:

|         |                           |                             |                             |        |
| ------- | ------------------------- | --------------------------- | --------------------------- | ------ |
| `BLDEP` | `NODENO`                  | `CNOD`                      | `NDDOF`                     | `NDEP` |
|         | `DEPDOF`<sub>`1`</sub>    | `INDEPDOF`<sub>`1`</sub>    | `b`<sub>`DEP1,INDEP1`</sub> |        |
|         | `DEPDOF`<sub>`2`</sub>    | `INDEPDOF`<sub>`2`</sub>    | `b`<sub>`DEP2,INDEP2`</sub> |        |
|         | ...                       | ...                         | ...                         |        |
|         | `DEPDOF`<sub>`NDEP`</sub> | `INDEPDOF`<sub>`NDEP`</sub> | `b`<sub>`DEPn,INDEPn`</sub> |        |

Each line specifies one dependent degree of freedom which is dependent
on the independent node’s specified degree of freedom with the
factor *b<sub>i,j</sub>*. The degrees of freedom must also be specified on
`BNBCD`-records as linear dependent (3) for the dependent node, and as
retained (4) for the independent node.

A node may be dependent on many nodes. For each combination of
`NODENO` and `CNOD` a new record, starting with the identifier
`BLDEP`, is given.

The same combination of `NODENO` and `CNOD` may occur only once.

When node transformations have been specified for any of the nodes
implied in the linear dependence, the degrees of freedom refers to the
transformed local coordinate system.

Multipoint constraints (2nd and higher order dependence) may be
specifed through more `BLDEP` records with the same linear dependent
node and different independent nodes. The factors *b<sub>i,j</sub>*
may be found as Lagrange multiplicators or coefficients (Lagrange
interpolation polynomial). For 2nd order dependence this may as well
be specified on one BQDP record.
*/
            class bldep : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODENO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CNOD;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDDOF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDEP;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_DEPDOF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_INDEPDOF;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_b;

            public:

               /** Internal node number of the dependent node.
                */
               long NODENO;
               /** Internal node number of an independent node.
                */
               long CNOD;
               /** Number of dependent degrees of freedom of node
                   `NODENO`. When not specified, `NDDOF` is equal to
                   `NDEP`.
               */
               long NDDOF;
               /** Number of triplets with `DEPDOF`, `INDEPDOF` and
                   `b`<sub>*i,j*</sub>
               */
               long NDEP;
               /** Dependent node’s degree of freedom.
                */
               std::deque<long> DEPDOF;
               /** Independent node’s degree of freedom.
                */
               std::deque<long> INDEPDOF;
               /** The contribution of the *j*’th degree of freedom of
                   the independent node to the *i*’th degree of
                   freedom of the dependent node.
               */
               std::deque<double> b;

               bldep(std::deque<std::string> const &);

               bldep(void);

               bldep(long const &NODENO,
                     long const &CNOD,
                     long const &NDDOF,
                     long const &NDEP,
                     std::deque<long> const &DEPDOF,
                     std::deque<long> const &INDEPDOF,
                     std::deque<double> const &b);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, bldep const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `BNBCD`: Nodes with Boundary Conditions
/**
## Format:

|         |          |        |                        |                     |
| ------- | -------- | ------ | ---------------------- | ------------------- |
| `BNBCD` | `NODENO` | `NDOF` | `FIX`<sub>`1`</sub>    | `FIX`<sub>`2`</sub> |
|         | ...      | ...    | `FIX`<sub>`NDOF`</sub> |                     |

The codes of `FIX`<sub>`1`</sub>, `FIX`<sub>`2`</sub>, ...,
`FIX`<sub>`NDOF`</sub> are:

   =0: free to stay

   =1: fixed at zero displacement, temperature, etc.

   =2: prescribed displacement, temperature, different from zero

   =3: linearly dependent

   =4: retained degree of freedom.

The code `FIX` = 2 just indicates specified condition for the relevant
degree of freedom. Whether it is displacement, first time derivative
of the displacement etc. is defined on the `BNDISPL` record. Degrees
of freedom with `FIX` = 2 which are not defined on the `BNDISPL`
record will be fixed (have zero displacement, velocity and
acceleration).

The nodes (degrees of freedom) with `FIX` = 4 are called supernodes
(super degrees of freedom). The supernode sequence numbering is
according to the increasing order of their internal node number.
*/
            class bnbcd : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODENO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDOF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_FIX;

            public:

               /** Internal node number of nodes with specified
                   boundary condition.
                */
               long NODENO;
               /** Number of degrees of freedom.
                */
               long NDOF;
               /** Specification of boundary condition codes of
                   relevant degrees of freedom.
               */
               std::deque<long> FIX;

               bnbcd(std::deque<std::string> const &);

               bnbcd(void);

               bnbcd(long const &NODENO,
                     long const &NDOF,
                     std::deque<long> const &FIX);

               bnbcd(long const &NODENO,
                     std::deque<long> const &FIX);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, bnbcd const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `BNDISPL`: Nodes with Prescribed Displacements and Accelerations
/**
## Format:

|           |                       |                          |                       |                          |
| --------- | --------------------- | ------------------------ | --------------------- | ------------------------ |
| `BNDISPL` | `LLC`                 | `DTYPE`                  | `COMPLEX`             |                          |
|           | `NODENO`              | `NDOF`                   | `RDISP`<sub>`1`</sub> | `RDISP`<sub>`2`</sub>    |
|           | ...                   | ...                      | ...                   | `RDISP`<sub>`NDOF`</sub> |
|           | `IDISP`<sub>`1`</sub> | `IDISP`<sub>`2`</sub>    | ...                   | ...                      |
|           | ...                   | `IDISP`<sub>`NDOF`</sub> |                       |                          |

`RDISP` and `IDISP` refer to the transformed coordinate system if the
node `NODENO` is transformed, else to the global coordinate system of
the superelement.

The imaginary numbers follow immediately after the real numbers, i.e.
there are no blank fields between the last real part and the first
imaginary part.

If phase shift is not specified, the fields or positions
`IDISP`<sub>`1`</sub>, `IDISP`<sub>`2`</sub>, etc. are left out.
*/
            class bndispl : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_LLC;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_DTYPE;
               dnvgl::extfem::fem::types::entry_type<bool> static const _form_COMPLX;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODENO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDOF;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_RDISP;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_IDISP;

            public:

               /** Local load case number (positive integer number).
                */
               long LLC;
               /** Type of boundary condition.

                   =1: specified displacement

                   =3: specified acceleration
               */
               long DTYPE;
               /** Phase shift definition.

                   =false: no phase shift

                   =true: phase shift
               */
               bool COMPLX;
               /** Program defined node number.
                */
               long NODENO;
               /** Number of degrees of freedom at the node NODENO.
                */
               long NDOF;
               /** The real part of the specified boundary condition
                   with respect to the rspt. degree of freedom.
               */
               std::deque<double> RDISP;
               /** The imagenary part of the specified boundary
                   condition with respect to the rspt. degree of
                   freedom.
               */
               std::deque<double> IDISP;

               bndispl(std::deque<std::string> const &);

               bndispl(void);

               bndispl(long const &LLC,
                       long const &DTYPE,
                       bool const &COMPLX,
                       long const &NODENO,
                       long const &NDOF,
                       std::deque<double> const &RDISP,
                       std::deque<double> const &IDISP={});

               bndispl(long const &LLC,
                       long const &DTYPE,
                       bool const &COMPLX,
                       long const &NODENO,
                       std::deque<double> const &RDISP,
                       std::deque<double> const &IDISP={});

               bndispl(long const &LLC,
                       long const &DTYPE,
                       long const &NODENO,
                       long const &NDOF,
                       std::deque<double> const &RDISP,
                       std::deque<double> const &IDISP={});

               bndispl(long const &LLC,
                       long const &DTYPE,
                       long const &NODENO,
                       std::deque<double> const &RDISP,
                       std::deque<double> const &IDISP={});

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, bndispl const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `BNLOAD`: Nodes with Loads
/**
## Format:

|          |                          |                         |                          |                       |
| -------- | ------------------------ | ----------------------- | ------------------------ | --------------------- |
| `BNLOAD` | `LLC`                    | `LOTYP`                 | `COMPLEX`                |                       |
|          | `NODENO`                 | `NDOF`                  | `RLOAD`<sub>`1`</sub>    | `RLOAD`<sub>`2`</sub> |
|          | ...                      | ...                     | `RLOAD`<sub>`NDOF`</sub> | `ILOAD`<sub>`1`</sub> |
|          | `ILOAD`<sub>`2`</sub>    | ...                     | ...                      | ...                   |
|          | `ILOAD`<sub>`NDOF`</sub> |                         |                          |                       |

The imaginary numbers follow immediately after the real numbers, i.e.
there are no blank fields between the last real part and the first
imaginary part.

If phase shift is not specified, i.e. `COMPLX` == false, the fields or
positions `ILOAD`<sub>`1`</sub>, `ILOAD`<sub>`2`</sub>, etc. are left
out.
*/
            class bnload : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_LLC;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_LOTYP;
               dnvgl::extfem::fem::types::entry_type<bool> static const _form_COMPLX;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NODENO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDOF;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_RLOAD;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_ILOAD;

            public:

               /** Local load case number (positive integer number).
                */
               long LLC;
               /** Load type at node `NODENO`. Usually not of interest
                   to linear programs.

                     =0: not decided whether conservative or
                         non-conservative load

                     =1: conservative load

                     =-1: non-conservative load
               */
               long LOTYP;
               /** Phase shift definition.

                   =false: no phase shift

                   =true: phase shift
               */
               bool COMPLX;
               /** Program defined node number.
                */
               long NODENO;
               /** Number of degrees of freedom at the node NODENO.
                */
               long NDOF;
               /** The real part of the load with respect to the rspt.
                   degree of freedom.
               */
               std::deque<double> RLOAD;
               /** The imaginary part of the load with respect to the
                   rspt. degree of freedom. (Only if `COMPLX` == true).
               */
               std::deque<double> ILOAD;

               bnload(std::deque<std::string> const &);

               bnload(void);

               bnload(long const &LLC,
                      long const &LOTYP,
                      bool const &COMPLX,
                      long const &NODENO,
                      long const &NDOF,
                      std::deque<double> const &RLOAD,
                      std::deque<double> const &ILOAD={});

               bnload(long const &LLC,
                      long const &LOTYP,
                      bool const &COMPLX,
                      long const &NODENO,
                      std::deque<double> const &RLOAD,
                      std::deque<double> const &ILOAD={});

               bnload(long const &LLC,
                      long const &LOTYP,
                      long const &NODENO,
                      long const &NDOF,
                      std::deque<double> const &RLOAD,
                      std::deque<double> const &ILOAD={});

               bnload(long const &LLC,
                      long const &LOTYP,
                      long const &NODENO,
                      std::deque<double> const &RLOAD,
                      std::deque<double> const &ILOAD={});

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, bnload const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `MGSPRNG`: Element to Ground
/**
## Format:

|           |           |        |              |                 |
| --------- | --------- | ------ | ------------ | --------------- |
| `MGSPRNG` | `MATNO`   | `NDOF` | `K(1, 1)`    | `K(2, 1)`       |
|           | ...       | ...    | `K(NDOF, 1)` | `K(2, 2)`       |
|           | `K(3, 2)` | ...    | ...          | `K(NDOF, 2)`    |
|           | `K(3, 3)` | ...    | ...          | `K(NDOF, NDOF)` |

The (*i*, *j*)’th element of the stiffness matrix corresponds to the
force to be given in the *i*’th d.o.f. to get a unit displacement in
the *j*’th d.o.f.
*/
            class mgsprng : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_MATNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDOF;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_K;

            public:

               /** Material number, i.e. reference number referenced
                   to by the element specification.
               */
               long MATNO;
               /** Number of degrees of freedom of the node.
                */
               long NDOF;
               /** Elements of the stiffness matrix (only elements on
                   and below the main diagonal are stored, i.e.
                   symmetric stiffness matrix assumed). The elements
                   are referred to a local coordinate system if
                   defined (by `TRANSNO` on `GELREF1`), otherwise to
                   the global coordinate system of the superelement.
               */
               std::deque<std::deque<double>> K;

               mgsprng(std::deque<std::string> const &);

               mgsprng(void);

               mgsprng(long const &MATNO,
                       long const &NDOR,
                       std::deque<std::deque<double>> const &K);

               mgsprng(long const &MATNO,
                       std::deque<std::deque<double>> const &K);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, mgsprng const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GSETMEMB`: set (group) of Nodes or Elements (Members)
/**
## Format:

|            |                        |                        |                            |                        |
| ---------- | ---------------------- | ---------------------- | -------------------------- | ---------------------- |
| `GSETMEMB` | `NFIELD`               | `ISREF`                | `INDEX`                    | `ISTYPE`               |
|            | `ISORIG`               | `IRMEMB`<sub>`1`</sub> | `IRMEMB`<sub>`2`</sub>     | `IRMEMB`<sub>`3`</sub> |
|            | `IRMEMB`<sub>`4`</sub> | ...                    | `IRMEMB`<sub>`NMEMB`</sub> |                        |

This record together with the name and description of a set record (TDSETNAM) constitutes the set (group)
datatype.

### Comments:

The set datatype consists of one name and description of set record
(`TDSETNAM`) and one or more set member records (`GSETMEMB`).

It should be noted that a set may have its set members distributed
over several set member records (`GSETMEMB`) all having the same set
identification number (`ISREF`) and consequently also the same
`TDSETNAM` record. The total number of set members will then be the
sum of the number of set members (`NMEMB`) for each of the set
records.

### Restrictions:

  - Only one set type (ISTYPE) for same set identification number
    (`ISREF`) is allowed.

  - If several records for the same set identification number
    (`ISREF`), record numbering must be strictly sequential; 1 <
    `INDEX` < `NINDEX`, where `NINDEX` is number of records per set.

  - A set member (number) should only be included once in the list.
*/
            class gsetmemb : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NFIELD;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ISREF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_INDEX;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ISTYPE;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ISORIG;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_IRMEMB;

            public:

               /** Number of data fields on this record (maximum is
                   1024)
               */
               long NFIELD;
               /** Internal set identification number as defined on
                   the name and description of a set record
                   (`TDSETNAM`).
               */
               long ISREF;
               /** Sequential record number for current set (`ISREF`).
                   Each set may consist of one or more `GSETMEMB`
                   records with same set identification number
                   (`ISREF`). `INDEX` must be strictly increasing from
                   1 and upwards till number of `GSETMEMB` records for
                   this set of members (nodes or elements).
               */
               long INDEX;
               /** set type

                     =1: , set of nodes

                     =2: , set of elements

Set Type (`ISTYPE`) and interpretation of set Member Number (`IRMEMB`)

| `ISTYPE` | Description     | Interpretation of `IRMEMB`        |
| -------: | --------------- | --------------------------------- |
| 1        | set of Nodes    | Internal Node Number (`IINOD`)    |
| 2        | set of Elements | Internal Element Number (`IELNO`) |
               */
               long ISTYPE;
               /** set origin type

                    = 0:, undefined origin

                    = 1:, point

                    = 2:, line (or curve)

                    = 3:, surface

                    = 4:, body
               */
               long ISORIG;
               /** `NMEMB` set member numbers on this record.

                   `NMEMB` is number of set members on the current
                   record. `NMEMB` = `NFIELD` - 5
               */
               std::deque<long> IRMEMB;

               gsetmemb(std::deque<std::string> const &);

               gsetmemb(void);

               gsetmemb(long const &NFIELD,
                        long const &ISREF,
                        long const &INDEX,
                        long const &ISTYPE,
                        long const &ISORIG,
                        std::deque<long> const &IRMEMB);

               gsetmemb(long const &NFIELD,
                        long const &ISREF,
                        long const &INDEX,
                        long const &ISTYPE,
                        long const &ISORIG);

               gsetmemb(long const &ISREF,
                        long const &INDEX,
                        long const &ISTYPE,
                        long const &ISORIG,
                        std::deque<long> const &IRMEMB);

               gsetmemb(long const &ISREF,
                        long const &INDEX,
                        long const &ISTYPE,
                        long const &ISORIG);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gsetmemb const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `GUNIVEC`: Specification of Local Element Coordinate System
/**
## Format:

|           |           |        |        |        |
| --------- | --------- | ------ | ------ | ------ |
| `GUNIVEC` | `TRANSNO` | `UNIX` | `UNIY` | `UNIZ` |

The `GUNIVEC` records are used for beam elements only, i.e. basic
element types 2, 15 and 23. Other basic element types may refer to
`BNTRCOS` records. No ambiguity thus exists if both a `GUNIVEC` and
`BNTRCOS` record have same `TRANSNO`, but they should preferably have
separate numbering (`TRANSNO`) to avoid possible program problems.
*/
            class gunivec : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_TRANSNO;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_UNIX;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_UNIY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_UNIZ;

            public:

               /** Unit vector number, referenced to on record `GELREF1`.
                */
               long TRANSNO;
               /** *x* component of Unit vector given in superelement
                   coordinate system along the local z-axis (reference
                   axis in z-direction) of the element in the
                   particular node.
               */
               double UNIX;
               /** *y* component of Unit vector given in superelement
                   coordinate system along the local z-axis (reference
                   axis in z-direction) of the element in the
                   particular node.
               */
               double UNIY;
               /** *z* component of Unit vector given in superelement
                   coordinate system along the local z-axis (reference
                   axis in z-direction) of the element in the
                   particular node.
               */
               double UNIZ;

               gunivec(std::deque<std::string> const &);

               gunivec(void);

               gunivec(long const &TRANSNO,
                       double const &UNIX,
                       double const &UNIY,
                       double const &UNIZ);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, gunivec const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `MISOSEL`: Isotropy, Linear Elastic Structural Analysis
/**
## Format:

|           |         |         |         |         |
| --------- | ------- | ------- | ------- | ------- |
| `MISOSEL` | `MATNO` | `YOUNG` | `POISS` | `RHO`   |
|           | `DAMP`  | `ALPHA` | `DUMMY` | `YIELD` |
*/
            class misosel : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_MATNO;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_YOUNG;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_POISS;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_RHO;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_DAMP;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_ALPHA;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_DUMMY;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_YIELD;

            public:
               /** Material number, i.e. reference number referenced
                   to by the element specification.
                */
               long MATNO;
               /** Young’s modulus.
                */
               double YOUNG;
               /** Poisson’s ratio.
                */
               double POISS;
               /** Density.
                */
               double RHO;
               /** Specific damping.
                */
               double DAMP;
               /** Thermal expansion coefficient.
                */
               double ALPHA;
               /** *Unknown value, not documented!!*
                */
               double DUMMY;
               /** Yield stress value for this material.
                */
               double YIELD;

               misosel(std::deque<std::string> const &);

               misosel(void);

               misosel(long const &MATNO,
                       double const &YOUNG,
                       double const &POISS,
                       double const &RHO,
                       double const &DAMP,
                       double const &ALPHA,
                       double const &DUMMY=0.,
                       double const &YIELD=0.);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, misosel const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `TDSETNAM`: Name and Description of a set (group)
/**
## Format

|            |          |         |          |          |
| ---------- | -------- | ------- | -------- | -------- |
| `TDSETNAM` | `NFIELD` | `ISREF` | `CODNAM` | `CODTXT` |
|            | \<set name\>                       | | | |
|            | \<text line\>                      | | | |
|            | ...                                | | | |
|            | \<text line\>                      | | | |

This record together with the set of nodes or elements record(s)
(`GSETMEMB`) constitutes the set (group) datatype.
*/
            class tdsetnam : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NFIELD;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ISREF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CODNAM;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CODTXT;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_SET_NAME;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_CONT;

               bool nlnam;
               long ncnam;
               long nltxt;
               long nctxt;

            public:

               /** Number of numeric data fields on this record before
                * text data (MAX = 1024).
                */
               long NFIELD;
               /** Internal set identification number. Legal range [1,
                   `NSET`], where `NSET` is number of sets which is
                   equeal to number of "Name and Description of a set"
                   records (`TDSETNAM`). Two `TDSETNAM` records may
                   not have identical set identification numbers
                   (`ISREF`).
               */
               long ISREF;
               /** Coded dimension of set name:

                     \f[
                       \mathtt{CODNAM} = \mathtt{NLNAM} * 100 + \mathtt{NCNAM}.
                     \f]

                   The inverse relation will then be

                     - `NLNAM` - number of physical records used for
                       storing of set name.

                       Legal range = [0,1]

                         - = 0, no name defined

                         - = 1, name is defined

                       `NLNAM` = integer part of (`CODNAM` / 100)

                     - `NCNAM` - number of characters in set name.

                        Legal range = [0,64]

                        `NCNAM` = remaindering of (`CODNAM` / 100)
               */
               long CODNAM;
               /** Coded dimension of set description text:

                     \f[
                       \mathtt{CODTXT} = \mathtt{NLTXT} * 100 + \mathtt{NCTXT}.
                     \f]

                   The inverse relation will then be:

                     - `NLTXT` - number of physical records used for
                       storing of set description text. Legal range =
                       [0,5]

                       - = 0, no description text defined

                       - ≥ 1, number of physical records with
                         description text

                       `NLTXT` = integer part of (`CODTXT` / 100)


                     - `NCTXT` - number of characters per physical set
                       description text record. Legal range = [0,64]

                       `NCTXT` = remaindering of (`CODTXT` / 100)
               */
               long CODTXT;

               std::string SET_NAME;
               std::deque<std::string> CONT;

               tdsetnam(std::deque<std::string> const &);

               tdsetnam(void);

               tdsetnam(long const &NFIELD,
                        long const &ISREF,
                        long const &CODNAM,
                        long const &CODTXT,
                        std::string const &SET_NAME,
                        std::deque<std::string> const &CONT);

               tdsetnam(long const &ISREF,
                        std::string const &SET_NAME,
                        std::deque<std::string> const &CONT);

               tdsetnam(long const &NFIELD,
                        long const &ISREF,
                        long const &CODNAM,
                        std::string const &SET_NAME);

               tdsetnam(long const &ISREF,
                        std::string const &SET_NAME);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, tdsetnam const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `TDSUPNAM`: Name and Description of a Super-Element
/**
## Format

|            |          |         |          |          |
| ---------- | -------- | ------- | -------- | -------- |
| `TDSUPNAM` | `NFIELD` | `IHREF` | `CODNAM` | `CODTXT` |
|            | \<set name\  >                     | | | |
|            | \<text line\>                      | | | |
|            | ...                                | | | |
|            | \<text line\>                      | | | |

This record will associate a name with a super-element in the
super-element hierarchy.
*/
            class tdsupnam : public card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NFIELD;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_IHREF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CODNAM;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CODTXT;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_SUP_NAME;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_CONT;

               bool nlnam;
               long ncnam;
               long nltxt;
               long nctxt;

            public:

               /** Number of numeric data fields on this record before
                * text data (MAX = 1024).
                */
               long NFIELD;
               /** Hierarchy reference number. Number 1 is reserved
                   for the top level superelement. In SESAM, PRESEL
                   (super-element pre-processor) is writing the
                   HIERARCH records and defining a unique number
                   (IHREF) for each appearance of the differenet
                   superelements.

                   \image latex tdsupnam.eps "Superelement hierarchy with 3 levels."
                   \image html tdsupnam.svg "Superelement hierarchy with 3 levels."
               */
               long IHREF;
               /** Coded dimension of set name:

                     \f[
                       \mathtt{CODNAM} = \mathtt{NLNAM} * 100 + \mathtt{NCNAM}.
                     \f]

                   The inverse relation will then be

                     - `NLNAM` - number of physical records used for
                       storing of set name.

                       Legal range = [0,1]

                         - = 0, no name defined

                         - = 1, name is defined

                       `NLNAM` = integer part of (`CODNAM` / 100)

                     - `NCNAM` - number of characters in set name.

                        Legal range = [0,64]

                        `NCNAM` = remaindering of (`CODNAM` / 100)
               */
               long CODNAM;
               /** Coded dimension of set description text:

                     \f[
                       \mathtt{CODTXT} = \mathtt{NLTXT} * 100 + \mathtt{NCTXT}.
                     \f]

                   The inverse relation will then be:

                     - `NLTXT` - number of physical records used for
                       storing of set description text. Legal range =
                       [0,5]

                       - = 0, no description text defined

                       - ≥ 1, number of physical records with
                       description text

                       `NLTXT` = integer part of (`CODTXT` / 100)


                       - `NCTXT` - number of characters per physical set
                       description text record. Legal range = [0,64]

                       `NCTXT` = remaindering of (`CODTXT` / 100)
               */
               long CODTXT;

               std::string SUP_NAME;
               std::deque<std::string> CONT;

               tdsupnam(std::deque<std::string> const &);

               tdsupnam(void);

               tdsupnam(long const &NFIELD,
                        long const &IHREF,
                        long const &CODNAM,
                        long const &CODTXT,
                        std::string const &SUP_NAME,
                        std::deque<std::string> const &CONT);

               tdsupnam(long const &IHREF,
                        std::string const &SUP_NAME,
                        std::deque<std::string> const &CONT);

               tdsupnam(long const &NFIELD,
                        long const &IHREF,
                        long const &CODNAM,
                        std::string const &SUP_NAME);

               tdsupnam(long const &IHREF,
                        std::string const &SUP_NAME);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, tdsupnam const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// `TEXT`: User supplied Text
/**
## Format

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

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_TYPE;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_SUBTYPE;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NRECS;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NBYTE;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_CONT;

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
               std::deque<std::string> CONT;

               text(std::deque<std::string> const &);

               text(void);

               text(long const &TYPE, long const &SUBTYPE,
                    long const &NRECS, long const &NBYTE,
                    std::deque<std::string> const &CONT);

               text(long const &TYPE, long const &SUBTYPE,
                    std::deque<std::string> const &CONT);

               const dnvgl::extfem::fem::cards::types
               card_type(void) const;

               friend  std::ostream&
               operator<< (std::ostream&, text const &);

               const std::ostream&
               operator<< (std::ostream& os) const;
            };
         }
      }
   }
}

#include "fem/elements.h"
#include "fem/cards_properties.h"
#include "fem/cards_loads.h"
#include "fem/cards_superele.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {
            void dispatch(
               std::deque<std::string> const &,
               std::unique_ptr<dnvgl::extfem::fem::cards::card>&);
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
