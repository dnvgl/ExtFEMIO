/**
   \file bdf/cards.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Classes for the different Nastran BDF cards.

   Eventually each BDF card that has to be written or read is provided
   with its own C++ class.
*/

// ID: $Id$

#pragma once

#if !defined _BDF_CARDS_H_
#define _BDF_CARDS_H_

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
#include "bdf/types.h"

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

            extern const void(*info_report)(std::string const &);
            extern const void(*warn_report)(std::string const &);
            extern const void(*error_report)(std::string const &);

            /**
               \brief Unique identifier for each class representing a BDF card.

               These are used to identify the classes that are returned from
               `dispatch` as `card` superclass.
               */
            typedef enum {
               /// undknown card
               UNKNOWN,
               /// Grid Point
               GRID,
               /// Isotropic Material Property Definition
               MAT1,
               /// Shell Element Anisotropic Material Property Definition
               MAT2,
               /// Triangular Plate Element Connection
               CTRIA3,
               /// Fully Nonlinear Axisymmetric Element
               CQUAD4,
               /// Shell Element Property
               PSHELL,
               /// Beam Element Connection
               CBEAM,
               /// Beam Property
               PBEAM,
               /// Beam Cross-Section Property
               PBEAML,
               /// Simple Beam Element Connection
               CBAR,
               /// Simple Beam Property
               PBAR,
               /// Simple Beam Cross-Section Property
               PBARL,
               /// Rod Element Connection
               CROD,
               /// Rod Property
               PROD,
               /// Element Force Output or Particle Velocity Request
               FORCE,
               /// Static Moment
               MOMENT,
               /// External Static Load Set Selection
               LOAD,
               /// Bulk Data Delimiter
               ENDDATA,
               /// base class for beam/bar property description
               BEAM_BASE,
               /// base class for bar property description
               BAR_PROP,
               /// base class for beam property description
               BEAM_PROP,
            } types;

            typedef std::pair<::dnvgl::extfem::bdf::types::base*, void*> format_entry;

/**
   \brief Base class for all classes representing BDF cards.
*/
            class card {

            private:

/**
   \brief Two character strings for continuation lines in Free Form
   Format cards.
*/
               static const std::set<char> free_form_cont;

               static const std::map<std::string, types> cardtype_map;

            protected:

               static ::dnvgl::extfem::bdf::types::empty empty;

               static ::dnvgl::extfem::bdf::types::card head;

               std::string format_outlist(
                  const std::deque<std::unique_ptr<format_entry>>&) const;

            public:

               friend inline
               std::unique_ptr<format_entry>
               format(const std::unique_ptr<::dnvgl::extfem::bdf::types::card> &formatter);

               friend inline
               std::unique_ptr<format_entry>
               format(const std::unique_ptr<::dnvgl::extfem::bdf::types::empty> &formatter);

               template <class _Ty> friend inline
               std::unique_ptr<format_entry>
               format(const ::dnvgl::extfem::bdf::types::entry_type<_Ty> &formatter,
                      const _Ty *val);

               static void
               card_split(std::deque<std::string> const &, std::deque<std::string> &);

               card (const std::deque<std::string> &);
               card ();

               virtual const ::dnvgl::extfem::bdf::cards::types card_type(void) const = 0;
               virtual const std::ostream& operator<<(std::ostream&) const = 0;
            };

            inline std::unique_ptr<format_entry>
            format(const ::dnvgl::extfem::bdf::types::card &formatter) {
               return std::make_unique<format_entry>(
                  (::dnvgl::extfem::bdf::types::card*)&formatter, (void*)NULL);
            };

            inline std::unique_ptr<format_entry>
            format(const ::dnvgl::extfem::bdf::types::empty &formatter) {
               return std::make_unique<format_entry>(
                  (::dnvgl::extfem::bdf::types::base*)&formatter, (void*)NULL);
            };

            template <class _Ty>
            inline std::unique_ptr<format_entry>
            format(const ::dnvgl::extfem::bdf::types::entry_type<_Ty> &formatter,
                   const _Ty *val) {
               return std::make_unique<format_entry>(
                  (::dnvgl::extfem::bdf::types::base*)&formatter,
                  (void*)val);
            };

            template <class _Ty>
            inline std::unique_ptr<format_entry>
            format(const ::dnvgl::extfem::bdf::types::entry_type<_Ty> &formatter,
                   const ::dnvgl::extfem::bdf::types::entry_value<_Ty> &val) {
               return std::make_unique<format_entry>(
                  (::dnvgl::extfem::bdf::types::base*)&formatter,
                  (void*)&val);
            };

            class unknown : public card{

            public:

               unknown(const std::deque<std::string> &inp) :
                  card(inp), content(inp) {};

               const ::dnvgl::extfem::bdf::cards::types card_type(void) const { return UNKNOWN; }

               std::deque<std::string> content;

               const std::ostream& operator << (std::ostream& os) const {
                  throw errors::error("can't write UNKNOWN.");
                  return os;
               };
            };

/// Handle Nastran Bulk `ENDDATA` entries.
/** # Bulk Data Delimiter

Designates the end of the Bulk Data Section.

# Format

| 1          | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| ---------- | - | - | - | - | - | - | - | - | -- |
| `ENDDATA`  |   |   |   |   |   |   |   |   |    |
*/
            class enddata : public card {

            private:

               static ::dnvgl::extfem::bdf::types::card head;

            public:

               enddata(const std::deque<std::string> &inp) :
                  card(inp) {};

               enddata() : card() {};

               const ::dnvgl::extfem::bdf::cards::types
               card_type(void) const { return ENDDATA; };

               const std::ostream& operator<< (std::ostream& os) const {
                  os << this;
                  return os;
               };

               friend std::ostream&
                  operator<<(std::ostream &, const enddata&);
            };

/// Handle Nastran Bulk `GRID` entries.
/** # Grid Point

Defines the location of a geometric grid point, the directions of its
displacement, and its permanent single-point constraints.

# Format

| 1       | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9      | 10 |
| ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ------ | -- |
| `GRID`  | `ID` | `CP` | `X1` | `X2` | `X3` | `CD` | `PS` | `SEID` |    |
*/
            class grid : public card {

            private:

               static ::dnvgl::extfem::bdf::types::card head;

               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_ID;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_CP;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_X1;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_X2;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_X3;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_CD;
               static const ::dnvgl::extfem::bdf::types::entry_type<std::deque<int>> form_PS;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_SEID;

            public:

               /** Grid point identification number. (0 < Integer <
                   100000000)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> ID;
               /** Identification number of coordinate system in which the
                   location of the grid point is defined. (Integer > 0 or
                   blank)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> CP;
               /** *x* Location of the grid point in coordinate system CP.
                   (Real; Default = 0.0)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> X1;
               /** *y* Location of the grid point in coordinate system CP.
                   (Real; Default = 0.0)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> X2;
               /** *z* Location of the grid point in coordinate system CP.
                   (Real; Default = 0.0)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> X3;
               /** Identification number of coordinate system in which the
                   displacements, degrees-of-freedom, constraints, and
                   solution deques are defined at the grid point.
                   (Integer > -1 or blank)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> CD;
               /** Permanent single-point constraints associated with the
                   grid point. (Any of the Integers 1 through 6 with no
                   embedded blanks, or blank.)
               */
               ::dnvgl::extfem::bdf::types::entry_value<std::deque<int>> PS;
               /** Superelement identification number. (Integer > 0;
                   Default = 0)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> SEID;

               grid(const std::deque<std::string> &);
               grid(long &ID, long &CP, double &X1, double &X2, double &X3);

               const ::dnvgl::extfem::bdf::cards::types
               card_type(void) const { return GRID; };

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// Base class for material definitions
            class mat : public card {

            protected:

               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_MID;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_G;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_RHO;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_A;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_TREF;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_GE;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_ST;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_SC;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_SS;
               static const ::dnvgl::extfem::bdf::types::entry_type<long> form_MCSID;

            public:

               /** Material identification number. (Integer > 0)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> MID;
               /** Mass density. See Remark 5. (Real)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> RHO;
               /** Reference temperature for the calculation of thermal
               loads, or a temperature-dependent thermal expansion
               coefficient. (Real; Default = 0.0 if `A` is specified.)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> TREF;
               /** Structural element damping coefficient. (Real)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> GE;
               /** Stress limits for tension is optionally supplied, used
               only to compute margins of safety in certain elements;
               and have no effect on the computational procedures.
               (Real > 0.0 or blank)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> ST;
               /** Stress limits for compression is optionally supplied,
               used only to compute margins of safety in certain
               elements; and have no effect on the computational
               procedures. (Real > 0.0 or blank)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> SC;
               /** Stress limits for shear is optionally supplied, used
               only to compute margins of safety in certain elements;
               and have no effect on the computational procedures.
               (Real > 0.0 or blank)
               */
               ::dnvgl::extfem::bdf::types::entry_value<double> SS;
               /** Material coordinate system identification number. Used
               only for `PARAM,CURV` processing. (Integer > 0 or blank)
               */
               ::dnvgl::extfem::bdf::types::entry_value<long> MCSID;

               mat(const std::deque<std::string> &);
               mat();
            };

/// Handle Nastran Bulk `MAT1` entries.
/** # Isotropic Material Property Definition

Defines the material properties for linear isotropic materials.

# Format

| 1      | 2     | 3    | 4    | 5       | 6     | 7   | 8      | 9    | 10 |
| ------ | ----- | ---- | ---- | ------- | ----- | --- | ------ | ---- | -- |
| `MAT1` | `MID` | `E`  | `G`  | `NU`    | `RHO` | `A` | `TREF` | `GE` |    |
|        | `ST`  | `SC` | `SS` | `MCSID` |       |     |        |      |    |
*/
            class mat1 : public mat {
               // NASTRAN `BDF` `MAT1` representation.

            private:

               static ::dnvgl::extfem::bdf::types::card head;

               // static const ::dnvgl::extfem::bdf::types::entry_type<long> form_MID;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_E;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_G;
               static const ::dnvgl::extfem::bdf::types::entry_type<double> form_NU;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_RHO;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_A;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_TREF;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_GE;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_ST;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_SC;
               // static const ::dnvgl::extfem::bdf::types::entry_type<double> form_SS;
               // static const ::dnvgl::extfem::bdf::types::entry_type<long> form_MCSID;

            public:

               /** Young’s modulus. (Real > 0.0 or blank)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> E;
               /** Shear modulus. (Real > 0.0 or blank)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> G;
               /** Poisson’s ratio. (-1.0 < Real < 0.5 or blank)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> NU;
               /** Thermal expansion coefficient. (Real)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> A;

               mat1(const std::deque<std::string> &);

               const ::dnvgl::extfem::bdf::cards::types
               card_type(void) const { return MAT1; };

               const std::ostream&
               operator<< (std::ostream& os) const;
            };

/// Handle Nastran Bulk MAT2 entries.
/** # Shell Element Anisotropic Material Property Definition

Defines the material properties for linear anisotropic materials for
two-dimensional elements.


# Format

| 1      | 2       | 3     | 4     | 5      | 6     | 7     | 8     | 9     | 10 |
| ------ | ------- | ----- | ----- | ------ | ----- | ----- | ----- | ----- | -- |
| `MAT2` | `MID`   | `G11` | `G12` | `G13`  | `G22` | `G23` | `G33` | `RHO` |    |
|        | `A1`    | `A2`  | `A3`  | `TREF` | `GE`  | `ST`  | `SC`  | `SS`  |    |
|        | `MCSID` |       |       |        |       |       |       |       |    |

Example:
........

| 1      | 2     | 3     | 4 | 5     | 6     | 7     | 8     | 9     | 10 |
| ------ | ----- | ----- | - | ----- | ----- | ----- | ----- | ----- | -- |
| `MAT2` | 13    | 6.2+3 |   |       | 6.2+3 |       | 5.1+3 | 0.056 |    |
|        | 6.5-6 | 6.5-6 |   | -500. | 0.002 | 20.+5 |       |       |    |
|        | 1003  |       |   |       |       |       |       |       |    |
*/

            class mat2 : public mat {
               // NASTRAN `BDF` `MAT2` representation.

            private:

               static ::dnvgl::extfem::bdf::types::card head;

            public:

               /** The material property matrix. (Real)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> G11;
               ::dnvgl::extfem::bdf::types::entry_value<double> G12;
               ::dnvgl::extfem::bdf::types::entry_value<double> G13;
               ::dnvgl::extfem::bdf::types::entry_value<double> G22;
               ::dnvgl::extfem::bdf::types::entry_value<double> G23;
               ::dnvgl::extfem::bdf::types::entry_value<double> G33;
               /** Thermal expansion coefficient vector. (Real)
                */
               ::dnvgl::extfem::bdf::types::entry_value<double> A1;
               ::dnvgl::extfem::bdf::types::entry_value<double> A2;
               ::dnvgl::extfem::bdf::types::entry_value<double> A3;

               mat2(const std::deque<std::string> &);

               const ::dnvgl::extfem::bdf::cards::types
               card_type(void) const { return MAT2; };

               const std::ostream&
               operator<< (std::ostream& os) const;
            };
         }
      }
   }
}

#include "bdf/cards_elements.h"
#include "bdf/cards_properties.h"
#include "bdf/cards_loads.h"

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {
            /** Dispatch instances of the different BDF card classes.
             */
            void
            dispatch(
               const std::deque<std::string>&, std::unique_ptr<card>&);
         }
      }
   }
}

#endif // _BDF_CARDS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
