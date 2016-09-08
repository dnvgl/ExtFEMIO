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

#include <list>
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

            extern const void(*note_report)(std::string const &);
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
               /// Acceleration or Gravity Load
               GRAV,
               /// External Static Load set Selection
               LOAD,
               /// Bulk Data Delimiter
               ENDDATA,
               /// base class for beam/bar property description
               BEAM_BASE,
               /// base class for bar property description
               BAR_PROP,
               /// base class for beam property description
               BEAM_PROP,
               /// Parameter
               PARAM,
            } types;

            typedef std::pair<dnvgl::extfem::bdf::types::base*, void*> format_entry;

            namespace __base {
/**
   \brief Base class for all classes representing BDF cards.
*/
               class card : public extfem::__base::outline {

               private:

/**
   \brief Two character strings for continuation lines in Free Form
   Format cards.
*/
                  static const std::set<char> free_form_cont;

                  static const std::map<std::string, types> cardtype_map;

               protected:

                  static dnvgl::extfem::bdf::types::empty empty;

                  static dnvgl::extfem::bdf::types::card head;

                  std::string format_outlist(
                     const std::list<std::unique_ptr<format_entry> >&) const;

                  virtual std::ostream &put(std::ostream&) const;

                  virtual void collect_outdata(
                     std::list<std::unique_ptr<format_entry> >&) const = 0;

               public:

                  friend inline
                  std::unique_ptr<format_entry>
                  format(const std::unique_ptr<dnvgl::extfem::bdf::types::card> &);

                  friend inline
                  std::unique_ptr<format_entry>
                  format(const std::unique_ptr<dnvgl::extfem::bdf::types::empty>&);

                  template <class _Ty> friend inline
                  std::unique_ptr<format_entry>
                  format(const dnvgl::extfem::bdf::types::entry_type<_Ty>&,
                         const _Ty *);

                  template <class _Ty> friend inline
                  std::unique_ptr<format_entry>
                  format(const dnvgl::extfem::bdf::types::entry_type<_Ty>&,
                         const dnvgl::extfem::bdf::types::entry_value<_Ty>&);

                  static void
                  card_split(std::list<std::string> const &, std::list<std::string>&);

                  card (const std::list<std::string> &);
                  card ();

                  virtual dnvgl::extfem::bdf::cards::types const card_type(void) const = 0;
               };
            }

            using __base::format;

            inline std::unique_ptr<format_entry>
            format(const dnvgl::extfem::bdf::types::card &formatter) {
               return std::make_unique<format_entry>(
                  (dnvgl::extfem::bdf::types::card*)&formatter, (void*)NULL);
            };

            inline std::unique_ptr<format_entry>
            format(const dnvgl::extfem::bdf::types::empty &formatter) {
               return std::make_unique<format_entry>(
                  (dnvgl::extfem::bdf::types::base*)&formatter, (void*)NULL);
            };

            template <class _Ty> inline
            std::unique_ptr<format_entry>
            __base::format(const dnvgl::extfem::bdf::types::entry_type<_Ty> &formatter,
                   const _Ty *val) {
               return std::make_unique<format_entry>(
                  (dnvgl::extfem::bdf::types::base*)&formatter,
                  (void*)val);
            };

            template <class _Ty> inline
            std::unique_ptr<format_entry>
            __base::format(const dnvgl::extfem::bdf::types::entry_type<_Ty> &formatter,
                   const dnvgl::extfem::bdf::types::entry_value<_Ty> &val) {
               return std::make_unique<format_entry>(
                  (dnvgl::extfem::bdf::types::base*)&formatter,
                  (void*)&val);
            };

            class unknown : public __base::card {

            public:

               std::list<std::string> content;

               unknown(const std::list<std::string> &inp) :
                  card(inp), content(inp) {};

               const dnvgl::extfem::bdf::cards::types card_type(void) const;

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
            };

/// Handle Nastran Bulk `ENDDATA` entries.
/** # Bulk Data Delimiter

Designates the end of the Bulk Data Section.

# Format

| 1          | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| ---------- | - | - | - | - | - | - | - | - | -- |
| `ENDDATA`  |   |   |   |   |   |   |   |   |    |
*/
            class enddata : public __base::card {

            private:

               static bdf::types::card head;

            public:

               enddata(const std::list<std::string> &);

               enddata(void);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const;

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
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
            class grid : public __base::card {

            private:

               static dnvgl::extfem::bdf::types::card head;

               static const dnvgl::extfem::bdf::types::entry_type<long> form_ID;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_CP;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_X1;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_X2;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_X3;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_CD;
               static const dnvgl::extfem::bdf::types::entry_type<std::list<int> > form_PS;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_SEID;

            public:

               /** Grid point identification number. (0 < Integer <
                   100000000)
               */
               dnvgl::extfem::bdf::types::entry_value<long> ID;
               /** Identification number of coordinate system in which the
                   location of the grid point is defined. (Integer > 0 or
                   blank)
               */
               dnvgl::extfem::bdf::types::entry_value<long> CP;
               /** *x* Location of the grid point in coordinate system CP.
                   (Real; Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> X1;
               /** *y* Location of the grid point in coordinate system CP.
                   (Real; Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> X2;
               /** *z* Location of the grid point in coordinate system CP.
                   (Real; Default = 0.0)
               */
               dnvgl::extfem::bdf::types::entry_value<double> X3;
               /** Identification number of coordinate system in which the
                   displacements, degrees-of-freedom, constraints, and
                   solution std::lists are defined at the grid point.
                   (Integer > -1 or blank)
               */
               dnvgl::extfem::bdf::types::entry_value<long> CD;
               /** Permanent single-point constraints associated with the
                   grid point. (Any of the Integers 1 through 6 with no
                   embedded blanks, or blank.)
               */
               dnvgl::extfem::bdf::types::entry_value<std::list<int> > PS;
               /** Superelement identification number. (Integer > 0;
                   Default = 0)
               */
               dnvgl::extfem::bdf::types::entry_value<long> SEID;

               grid(const std::list<std::string> &);
               grid(long &ID, long &CP, double &X1, double &X2, double &X3);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return GRID; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
            };

            namespace __base {
/// Base class for material definitions
               class mat : public card {

               protected:

                  static const dnvgl::extfem::bdf::types::entry_type<long> form_MID;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_G;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_RHO;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_A;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_TREF;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_GE;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_ST;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_SC;
                  static const dnvgl::extfem::bdf::types::entry_type<double> form_SS;
                  static const dnvgl::extfem::bdf::types::entry_type<long> form_MCSID;

               public:

                  /** Material identification number. (Integer > 0)
                   */
                  dnvgl::extfem::bdf::types::entry_value<long> MID;
                  /** Mass density. See Remark 5. (Real)
                   */
                  dnvgl::extfem::bdf::types::entry_value<double> RHO;
                  /** Reference temperature for the calculation of thermal
                      loads, or a temperature-dependent thermal expansion
                      coefficient. (Real; Default = 0.0 if `A` is specified.)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> TREF;
                  /** Structural element damping coefficient. (Real)
                   */
                  dnvgl::extfem::bdf::types::entry_value<double> GE;
                  /** Stress limits for tension is optionally supplied, used
                      only to compute margins of safety in certain elements;
                      and have no effect on the computational procedures.
                      (Real > 0.0 or blank)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> ST;
                  /** Stress limits for compression is optionally supplied,
                      used only to compute margins of safety in certain
                      elements; and have no effect on the computational
                      procedures. (Real > 0.0 or blank)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> SC;
                  /** Stress limits for shear is optionally supplied, used
                      only to compute margins of safety in certain elements;
                      and have no effect on the computational procedures.
                      (Real > 0.0 or blank)
                  */
                  dnvgl::extfem::bdf::types::entry_value<double> SS;
                  /** Material coordinate system identification number. Used
                      only for `PARAM,CURV` processing. (Integer > 0 or blank)
                  */
                  dnvgl::extfem::bdf::types::entry_value<long> MCSID;

                  mat(const std::list<std::string> &);
                  mat();
               };
            }

/// Handle Nastran Bulk `MAT1` entries.
/** # Isotropic Material Property Definition

Defines the material properties for linear isotropic materials.

# Format

| 1      | 2     | 3    | 4    | 5       | 6     | 7   | 8      | 9    | 10 |
| ------ | ----- | ---- | ---- | ------- | ----- | --- | ------ | ---- | -- |
| `MAT1` | `MID` | `E`  | `G`  | `NU`    | `RHO` | `A` | `TREF` | `GE` |    |
|        | `ST`  | `SC` | `SS` | `MCSID` |       |     |        |      |    |
*/
            class mat1 : public __base::mat {
               // NASTRAN `BDF` `MAT1` representation.

            private:

               static dnvgl::extfem::bdf::types::card head;

               // static const dnvgl::extfem::bdf::types::entry_type<long> form_MID;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_E;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_G;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_NU;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_RHO;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_A;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_TREF;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_GE;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_ST;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_SC;
               // static const dnvgl::extfem::bdf::types::entry_type<double> form_SS;
               // static const dnvgl::extfem::bdf::types::entry_type<long> form_MCSID;

            public:

               /** Young’s modulus. (Real > 0.0 or blank)
                */
               dnvgl::extfem::bdf::types::entry_value<double> E;
               /** Shear modulus. (Real > 0.0 or blank)
                */
               dnvgl::extfem::bdf::types::entry_value<double> G;
               /** Poisson’s ratio. (-1.0 < Real < 0.5 or blank)
                */
               dnvgl::extfem::bdf::types::entry_value<double> NU;
               /** Thermal expansion coefficient. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> A;

               mat1(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return MAT1; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
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

# Example:

| 1      | 2     | 3     | 4 | 5     | 6     | 7     | 8     | 9     | 10 |
| ------ | ----- | ----- | - | ----- | ----- | ----- | ----- | ----- | -- |
| `MAT2` | 13    | 6.2+3 |   |       | 6.2+3 |       | 5.1+3 | 0.056 |    |
|        | 6.5-6 | 6.5-6 |   | -500. | 0.002 | 20.+5 |       |       |    |
|        | 1003  |       |   |       |       |       |       |       |    |
*/

            class mat2 : public __base::mat {
               // NASTRAN `BDF` `MAT2` representation.

            private:

               static dnvgl::extfem::bdf::types::card head;

            public:

               /** The material property matrix. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> G11;
               dnvgl::extfem::bdf::types::entry_value<double> G12;
               dnvgl::extfem::bdf::types::entry_value<double> G13;
               dnvgl::extfem::bdf::types::entry_value<double> G22;
               dnvgl::extfem::bdf::types::entry_value<double> G23;
               dnvgl::extfem::bdf::types::entry_value<double> G33;
               /** Thermal expansion coefficient vector. (Real)
                */
               dnvgl::extfem::bdf::types::entry_value<double> A1;
               dnvgl::extfem::bdf::types::entry_value<double> A2;
               dnvgl::extfem::bdf::types::entry_value<double> A3;

               mat2(const std::list<std::string> &);

               const dnvgl::extfem::bdf::cards::types
               card_type(void) const { return MAT2; };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
            };

/// Handle Nastran Bulk PARAM entries.
/** # Parameter

Specifies values for parameters used in solution sequences or
user-written DMAP programs.

# Format:

| 1       | 2   | 3    | 4    | 5 | 6 | 7 | 8 | 9 | 10 |
| ------- | --- | ---- | ---- | - | - | - | - | - | -- |
| `PARAM` | `N` | `V1` | `V2` |   |   |   |   |   |    |


# Example:

| 1       | 2      | 3   | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| ------- | ------ | --- | - | - | - | - | - | - | -- |
| `PARAM` | `IRES` | `1` |   |   |   |   |   |   |    |



# Remarks:
1. See “Parameters” on page 603 for a list of parameters used in solution
sequences that may be set by the user on PARAM entries.
2. If the large field entry format is used, the second physical entry must be
present, even though fields 6 through 9 are blank.

 */
            class param : public __base::card {
            private:

               static dnvgl::extfem::bdf::types::card head;
               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_N;
               static const dnvgl::extfem::bdf::types::entry_type<long> form_IVAL;
               static const dnvgl::extfem::bdf::types::entry_type<double> form_RVAL;
               static const dnvgl::extfem::bdf::types::entry_type<std::string> form_CVAL;
               static const dnvgl::extfem::bdf::types::entry_type<std::complex<double> > form_CPLXVAL;

            public:

               typedef enum {is_CHAR, is_INT, is_REAL, is_CPLX} VALUE_TYPE;

               VALUE_TYPE value_type;

               /** Parameter name (one to eight alphanumeric
                   characters, the first of which is alphabetic).
               */
               dnvgl::extfem::bdf::types::entry_value<std::string> N;
               /** Parameter value based on parameter type:
                   | `V1` | `V1`  |
                   | long | blank |
               */
               dnvgl::extfem::bdf::types::entry_value<long> IVAL;
               /** Parameter value based on parameter type:
                   | `V1`   | `V1`  |
                   | double | blank |
               */
               dnvgl::extfem::bdf::types::entry_value<double> RVAL;
               /** Parameter value based on parameter type:
                   | `V1` | `V1`  |
                   | char | blank |
               */
               dnvgl::extfem::bdf::types::entry_value<std::string> CVAL;
               /** Parameter value based on parameter type:
                   | `V1`   | `V1`   |
                   | double | double |
               */
               dnvgl::extfem::bdf::types::entry_value<std::complex<double> > CPLXVAL;

            private:
               param();

               param(std::string const&);

            public:
               param(std::list<std::string> const&);

               param(std::string const&, long const&);

               param(std::string const&, double const&);

               param(std::string const&, std::string const&);

               param(std::string const&, std::complex<double> const&);

               param(std::string const&, double const&, double const&);

               const dnvgl::extfem::bdf::cards::types card_type(void) const {
                  return PARAM;
               };

            private:

               virtual void collect_outdata(
                  std::list<std::unique_ptr<format_entry> >&) const;
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
               const std::list<std::string>&,
               std::unique_ptr<__base::card>&);
         }
      }
   }
}

#endif // _BDF_CARDS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
