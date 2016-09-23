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

#include "config.h"

#include "bdf/types.h"

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

            void extern const(*note_report)(std::string const &);
            void extern const(*info_report)(std::string const &);
            void extern const(*warn_report)(std::string const &);
            void extern const(*error_report)(std::string const &);

            /**
               \brief Unique identifier for each class representing a BDF card.

               These are used to identify the classes that are returned from
               `dispatch` as `card` superclass.
               */
            enum class types {
               GRID, //!< # Geometry
                     //!< ## Grid Points
                     //!< Grid Point
               CBAR, //!< # Elements
                     //!< ##Line Elements
                     //!< Simple Beam Element Connection
               CBEAM, //!< Beam Element Connection
               CBEND, //!< Defines a curved beam, curved pipe, or
                      //!< elbow element.
               CONROD, //!< Defines a rod element without reference to
                       //!< a property entry.
               CROD, //!< Rod Element Connection
               CTUBE, //!< Defines a tension-compression-torsion tube
                      //!< element.
               PBAR, //!< Simple Beam Property
               PBARL, //!< Simple Beam Cross-Section Property
               PBEAM, //!< Beam Property
               PBEAML, //!< Beam Cross-Section Property
               PROD, //!< Rod Property
               CQUAD, //!< ## Surface Elements
                      //!< Defines a plane strain quadrilateral element
                      //!< with up to nine grid points for use in fully
                      //!< nonlinear (i.e., large strain and large
                      //!< rotation) hyperelastic analysis.
               CQUAD4, //!< Fully Nonlinear Axisymmetric Element
               CQUAD8, //!< Defines a curved quadrilateral shell or
                       //!< plane strain element with eight grid points.
               CQUADR, //!< Defines an isoparametric membrane and
                       //!< bending quadrilateral plate element. This
                       //!< element has a normal rotational
                       //!< degrees-of-freedom. It is a companion to
                       //!< the `CTRIAR` element.
               CSHEAR, //!< Defines a shear panel element.
               CTRIA3, //!< Triangular Plate Element Connection
               CTRIA6, //!< Defines a curved triangular shell element
                       //!< or plane strain with six grid points.
               CTRIAR, //!< Defines an isoparametric membrane-bending
                       //!< triangular plate element. This element
                       //!< has a normal rotational degrees-of-freedom.
                       //!< It is a companion to the `CQUADR` element.
               PSHELL, //!< Shell Element Property
               CHEXA, //!< ## Solid Elements
                      //!< Defines the connections of the six-sided
                      //!< solid element with eight to twenty grid
                      //!< points.
               CPENTA, //!< Defines the connections of a five-sided
                       //!< solid element with six to fifteen grid points.
               CTETRA, //!< Defines the connections of the four-sided
                       //!< solid element with four to ten grid points.
               CBUSH, //!< ## Scalar and Bushing Elements
                      //!< Defines a generalized spring-and-damper
                      //!< structural element that may be nonlinear or
                      //!< frequency dependent.
               CBUSH1D, //!< Defines the connectivity of a
                        //!< one-dimensional spring and viscous damper
                        //!< element.
               CELAS1, //!< Scalar Spring Connection
               CELAS2, //!< Defines a scalar spring element without
                       //!< reference to a property entry.
               CELAS3, //!< Defines a scalar spring element that
                       //!< connects only to scalar points.
               CELAS4, //!< Defines a scalar spring element that is
                       //!< connected only to scalar points, without
                       //!< reference to a property entry.
               GENEL, //!< Defines a general element.
               // PELAS, //!< Scalar Elastic Property
               GMINTC, //!< ## p-element Interface Elements
                       //!< Defines an interface element along a curve
                       //!< interface between boundaries of multiple
                       //!< subdomains. Typically, the boundaries will
                       //!< consist of edges of p-shell subdomains but
                       //!< also may consist of p-beam subdomains or
                       //!< edges of p-solid subdomains.
               GMINTS, //!< Defines an interface element along a
                       //!< surface interface between boundaries of
                       //!< multiple subdomains. Typically, the
                       //!< boundaries will consist of faces of
                       //!< p-solid subdomains, but also may consist
                       //!< of p-shell subdomains.
               CCONEAX, //!< ## Axisymmetric Elements
                        //!< Defines a conical shell element.
               CQUADX, //!< Defines an axisymmetric quadrilateral
                       //!< element with up to nine grid points for
                       //!< use in fully nonlinear (i.e., large strain
                       //!< and large rotations) hyperelastic analysis.
               CTRIAX, //!< Defines an axisymmetric triangular element
                       //!< with up to 6 grid points for use in fully
                       //!< nonlinear (i.e., large strain and large
                       //!< rotations) hyperelastic analysis.
               CTRIAX6, //!< Defines an isoparametric and axisymmetric
                        //!< triangular cross section ring element with
                        //!< midside grid points.
               RBAR, //!< ## Rigid Elements
                     //!< Defines a rigid bar with six
                     //!< degrees-of-freedom at each end.
               RBAR1, //!< Alternative format for RBAR.
               RBE1, //!< Defines a rigid body connected to an
                     //!< arbitrary number of grid points.
               RBE2, //!< Defines a rigid body with independent
                     //!< degrees-of-freedom that are specified at a
                     //!< single grid point and with dependent
                     //!< degrees-of-freedom that are specified at an
                     //!< arbitrary number of grid points.
               RBE3, //!< Defines the motion at a reference grid point
                     //!< as the weighted average of the motions at
                     //!< a set of other grid points.
               RJOINT, //!< Defines a rigid joint element connecting
                       //!< two coinciding grid points.
               RROD, //!< Defines a pin-ended element that is rigid in
                     //!< translation.
               RSPLINE, //!< Defines multipoint constraints for the
                        //!< interpolation of displacements at grid
                        //!< points.
               RSSCON, //!< Defines multipoint constraints to model
                       //!< clamped connections of shell-to-solid
                       //!< elements.
               RTRPLT, //!< Defines a rigid triangular plate.
               RTRPLT1, //!< Alternative format to define a rigid
                        //!< triangular plate element connecting three
                        //!< grid points.
               CMASS1, //!< ## Mass Elements
                       //!< Defines a scalar mass element.
               CMASS2, //!< Scalar Mass Property and Connection
               CMASS3, //!< Defines a scalar mass element that is
                       //!< connected only to scalar points.
               CMASS4, //!< Scalar Mass Property and Connection to
                       //!< Scalar Points Only
               CONM1, //!< Defines a 6 x 6 symmetric mass matrix at a
                      //!< geometric grid point.
               CONM2, //!< Defines a concentrated mass at a grid point.
               CDAMP1, //!< ## Damping Elements
                       //!< Defines a scalar damper element.
               CDAMP2, //!< Defines a scalar damper element without
                       //!< reference to a material or property entry.
               CDAMP3, //!< Defines a scalar damper element that is
                       //!< connected only to scalar points.
               CDAMP4, //!< Defines a scalar damper element that
                       //!< connected only to scalar points and without
                       //!< reference to a material or property entry.
               CDAMP5, //!< Defines a damping element that refers to a
                       //!< material property entry and connection to
                       //!< grid or scalar points. This element is
                       //!< intended for heat transfer analysis only.
               CVISC, //!< Defines a viscous damper element.
               CAABSF, //!< ## Fluid and Acoustic Elements
                       //!< Frequency-Dependent Acoustic Absorber Element
               CAXIF2, //!< Defines an axisymmetric fluid element that
                       //!< connects i = 2 fluid points.
               CAXIF3, //!< Defines an axisymmetric fluid element that
                       //!< connects i = 3 fluid points.
               CAXIF4, //!< Defines an axisymmetric fluid element that
                       //!< connects i = 4 fluid points.
               CFLUID2, //!< Defines three types of fluid elements for
                        //!< an axisymmetric fluid model.
               CFLUID3, //!< Defines three types of fluid elements for
                        //!< an axisymmetric fluid model.
               CFLUID4, //!< Defines three types of fluid elements for
                        //!< an axisymmetric fluid model.
               CHACAB, //!< Defines the acoustic absorber element in
                       //!< coupled fluid-structural analysis.
               CHACBR, //!< Defines the acoustic barrier element.
               CSLOT3, //!< Defines an element connecting three points
                       //!< that solves the wave equation in two
                       //!< dimensions. Used in the acoustic cavity
                       //!< analysis for the definition of evenly
                       //!< spaced radial slots.
               CSLOT4, //!< Defines an element connecting four points
                       //!< that solves the wave equation in two
                       //!< dimensions. Used in acoustic cavity analysis
                       //!< for the definition of evenly spaced radial
                       //!< slots.
               CHBDYE, //!< ## Heat Transfer Elements
                       //!< Defines a boundary condition surface
                       //!< element with reference to a heat
                       //!< conduction element.
               CHBDYG, //!< Defines a boundary condition surface
                       //!< element  without reference to a property
                       //!< entry.
               CHBDYP, //!< Defines a boundary condition surface
                       //!< element with reference to a `PHBDY` entry.
               CDUM1, //!< ## Dummy Elements
                      //!< Defines a dummy element
               CDUM2, //!< Defines a dummy element
               CDUM3, //!< Defines a dummy element
               CDUM4, //!< Defines a dummy element
               CDUM5, //!< Defines a dummy element
               CDUM6, //!< Defines a dummy element
               CDUM7, //!< Defines a dummy element
               CDUM8, //!< Defines a dummy element
               CDUM9, //!< Defines a dummy element
               PLOTEL, //!< Defines a one-dimensional dummy element
                       //!< for use in plotting.
               CGAP, //!< ## Contact or Gap Elements
                     //!< Defines a gap or friction element.
               CRAC2D, //!< Defines a two-dimensional crack tip element.
               CRAC3D, //!< Defines a three-dimensional crack tip element.
               CAERO1, //!< ## Aerodynamic Elements
                       //!< Aerodynamic Panel Element Connection
               CAERO2, //!< Defines aerodynamic slender body and
                       //!< interference elements for Doublet-Lattice
                       //!< aerodynamics.
               CAERO3, //!< Defines the aerodynamic edges of a Mach
                       //!< Box lifting surface. If no cranks are
                       //!< present, this entry defines the aerodynamic
                       //!< Mach Box lifting surface.
               CAERO4, //!< Defines an aerodynamic macro element for
                       //!< Strip theory.
               CAERO5, //!< Defines an aerodynamic macro element for
                       //!<  Piston theory.
               SPLINE1, //!< Defines a surface spline force
                        //!<  interpolating motion and/or forces for
                        //!< aeroelastic problems on aerodynamic
                        //!< geometries defined by regular arrays of
                        //!< aerodynamic points.
               SPLINE2, //!< Defines a beam spline for interpolating
                        //!< motion and/or forces for aeroelastic
                        //!< problems on aerodynamic geometries defined
                        //!< by regular arrays of aerodynamic points.
               SPLINE3, //!< Defines a constraint equation for
                        //!< aeroelastic problems. Useful for control
                        //!< surface constraints.
               SPLINE4, //!<  Defines a curved surface spline for
                        //!< interpolating motion and/or forces for
                        //!< aeroelastic problems on general
                        //!< aerodynamic geometries using either the
                        //!< Infinite Plate, Thin Plate or Finite
                        //!< Plate splining method.
               SPLINE5, //!< Defines a 1D beam spline for interpolating
                        //!< motion and/or forces for aeroelastic
                        //!< problems on aerodynamic geometries defined
                        //!< by irregular arrays of aerodynamic points.
                        //!< The interpolating beam supports axial
                        //!< rotation and bending in the yz-plane.
               MAT1, //!< # Materials
                     //!< ## Isotropic
                     //!< Isotropic Material Property Definition
               MAT2, //!< ## Anisotropic
                     //!< Shell Element Anisotropic Material Property
                     //!< Definition
               GRAV, //!< # Loads
                     //!< ## Static Loads
                     //!< Acceleration or Gravity Load
               FORCE, //!< Element Force Output or Particle Velocity Request
               LOAD, //!< External Static Load set Selection
               MOMENT, //!< Static Moment
               ENDDATA, //!< # Miscellaneous
                        //!< ## End of Input
                        //!< Bulk Data Delimiter
               CDAMP1D, //!< # MSC.Nastran Explicit Nonlinear (SOL 700)
                        //!< ## Dampers/Springs
                        //!< Scalar Damper Connection for SOL 700 Only
               CDAMP2D, //!< Defines a scalar damper connection for use
                        //!< in SOL 700 only.
               CELAS1D, //!< Defines a scalar spring connection for
                        //!< use in SOL 700 only.
               CELAS2D, //!< Defines a scalar spring connection for
                        //!< use in SOL 700 only.
               CBUTT, //!< ## Welds
                      //!< Defines a butt weld in the LS-Dyna style for
                      //!< use in SOL 700 only. Replaces `CWELD` for
                      //!< SOL 700.
               COMBWLD, //!< Defines a complex or combined weld in the
                        //!< ls-dyna style for use in SOL 700 only.
                        //!< Replaces `CWELD` for SOL 700.
               CCRSFIL, //!< Defines a cross-fillet weld in the
                        //!< LS-Dyna style for use in SOL 700 only.
                        //!< Replaces `CWELD` for SOL 700.
               CFILLET, //!< Defines a fillet weld in the LS-Dyna
                        //!< style for use in SOL 700. Replaces `CWELD`
                        //!< for SOL 700.
               CSPOT, //!< Defines a complex or combined weld in the
                      //!< ls-dyna style for use in SOL 700 only.
                      //!< Replaces CWELD for SOL 700.
               RBE3D, //!< ## Rigid Elements
                      //!< Defines rigid interpolation constraints in
                      //!< the MSC. Dytran style. Used in MSC.Nastran
                      //!< Implicit Nonlinear (SOL 700) only.
               PARAM, //!< Parameter
               ELEMENT, //!< # Internal Data
                        //!< base class for elements
               BEAM_BASE, //!< base class for beam/bar property
                          //!< description
               BAR_PROP, //!< base class for bar property
                          //!< description
               BEAM_PROP, //!< base class for beam property description
               CAXIFi, //!< Defines an axisymmetric fluid element that
                       //!< connects i = 2, 3, or 4 fluid points.
               UNKNOWN, //!< undknown card
            };

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

                  virtual card const *operator() (std::list<std::string> const &);

                  virtual void read(std::list<std::string> const &) = 0;

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
            format(dnvgl::extfem::bdf::types::card const &formatter) {
               return std::make_unique<format_entry>(
                  (dnvgl::extfem::bdf::types::card*)&formatter, nullptr);
            };

            inline std::unique_ptr<format_entry>
            format(dnvgl::extfem::bdf::types::empty const &formatter) {
               return std::make_unique<format_entry>(
                  (dnvgl::extfem::bdf::types::base*)&formatter, nullptr);
            };

            template <class _Ty> inline
            std::unique_ptr<format_entry>
            __base::format(dnvgl::extfem::bdf::types::entry_type<_Ty> const &formatter,
                   _Ty const *val) {
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

               unknown(const std::list<std::string> &inp);

               const dnvgl::extfem::bdf::cards::types card_type(void) const;

               virtual void read(const std::list<std::string> &inp);

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

               virtual void read(std::list<std::string> const &);

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
               card_type(void) const;

               virtual void read(const std::list<std::string> &);

               const card *operator() (long const &ID, long const &CP,
                                       double const &X1, double const &X2, double const &X3);

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
               card_type(void) const;

               virtual void read(std::list<std::string> const &);

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
               card_type(void) const;

               virtual void read(std::list<std::string> const &);

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

               enum class value_type {is_CHAR, is_INT, is_REAL, is_CPLX};

               value_type value_type;

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

               const dnvgl::extfem::bdf::cards::types card_type(void) const;

               virtual void read(std::list<std::string> const &);

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
