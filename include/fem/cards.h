/*!
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Classes for the different Sesame FEM cards.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _FEM_CARDS_H_
#define _FEM_CARDS_H_

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory>

#include "extfem_misc.h"

#if (__GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))) || \
    (_MSC_VER && _MSC_VER <= 1700)
#include "my_c++14.h"
#endif
#include "types.h"

#ifdef __GNUC__
#include "config.h"
#endif

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
                enum class types;
                namespace __base {
                    class card;
                }
                class gelmnt1;
                class gelref1;
            }
        }
    }
}

std::ostream &operator<< (
    std::ostream&, dnvgl::extfem::fem::cards::types const);

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
                void extern(*note_report)(std::string const&);
                void extern(*info_report)(std::string const&);
                void extern(*warn_report)(std::string const&);
                void extern(*error_report)(std::string const&);
//! \brief Name the different cards.
                enum class types {
                    UNKNOWN,
                    DATE, //< # Identification Data for Superelements and Text Data
                          //< Date and Program Information
                    IDENT, //< Identification of Superelements
                    IEND, //< End of a Superelement
                    TDMATER,//< Name of a Material Type
                    TDSECT,//< Name of a General Eccentric Sandwich Section
                    TDSETNAM, //< Name and Description of a set(group)
                    TDSUPNAM, //< Name and Description of a Super-Element.
                    TDLOAD, //< Name of Load
                    TEXT, //< User supplied Text
                    TSLAYER, //< Name of a General Eccentric Sandwich Type
                    ACFD, //< # Additional Element Data
                          //< General Crack Data
                    ADDATA, //< Additional User defined Basic Element Data
                    BEISTE, //< # Boundary Conditions, Loads and Point Masses
                            //< Elements with Initial Strain Due to
                            //< Thermal Expansion
                    BELFIX, //< Flexible Joint/Hinge
                    BELLAX, //< Surface Load on Axisymmetric Solids
                    BELLO2, //< Elements with Line Loads, Solid, 3-D
                            //< Shell, 2-D Shell-, Membrane and Curved
                            //< Beam Elements
                    BELOAD1, //< Beams with Line Loads
                    BEDRAG1, //< Hydrodynamic Drag and Damping from
                             //< Wave Load Program
                    BEMASS1, //< Hydrodynamic added Mass from Wave Load Program
                    BEUSLO, //< Elements with Surface Loads
                    BEUVLO, //< Elements with Volume Forces, 3-D
                            //< Solid, 2-D Shell and Membrane Elements
                    BEWAKIN, //< Wave Kinematics
                    BEWALO1, //< Element Loads from Wave Load Program
                    BGRAV, //< Gravitational Load (Constant of Gravity)
                    BLDEP, //< Nodes with Linear Dependence
                    BNACCLO, //< Nodes with Acceleration Load
                    BNBCD, //< Nodes with Boundary Conditions
                    BNDISPL, //< Nodes with Prescribed Displacements
                             //< and Accelerations
                    BNDOF, //< Nodes with Transformation
                    BNINCO, //< Nodes with Initial Conditions If
                            //< Arbitrary Time Dependent Loading
                    BNLOAD, //< Nodes with Loads
                    BNLOAX, //< Nodes with Loads (Line Load) for
                            //< Axisymmetric Solids
                    BNMASS, //< Nodes with Point Masses
                    BNTEMP, //< Nodes with Temperatures and
                            //< Derivatives for Temperatures
                    BNTRCOS, //< Transformation from Global to Local
                             //< Coordinate System, Direction Cosines
                    BNWALO, //< Node Loads from Wave Load Program
                    BRIGAC, //< Rigid Body Acceleration
                    BRIGDI, //< Rigid Body Displacement
                    BRIGVE, //< Rigid Body Velocity
                    BQDP, //< Nodes with Simple Quadratic Dependence
                    GBARM, //< # Nodal Data and Element Geometry Definition
                           //< Cross Section Type Massive Bar
                    GBEAMG, //< General Beam Element Data
                    GBOX, //< Cross Section Type Box Beam
                    GCHAN, //< Cross Section Type Channel Beam
                    GCHANR, //< Cross Section Type Channel Beam
                    GCOORD, //< Nodal Coordinates
                    GCROINT, //< Specification of Integration Points
                    GDOBO, //< Section Type Double Bottom
                    GECC, //< Local Eccentricities
                    GECCEN, //< Eccentricities
                    GELINT, //< Specification of Integration Stations
                    GELMNT1, //< Element Data Definition
                    GELREF1, //< Reference to Element Data
                    GELSTRP, //< Specification of Stress Points
                    GELTH, //< Thickness of Two-dimensional Elements
                    GIORH, //< Cross Section Type I or H Beam
                    GIORHR, //< Cross Section Type I or H Beam with
                            //< Inside Curvature
                    GLMASS, //< Modification of Diagonal Mass Matrices
                    GLSEC, //< Cross Section Type L-Section
                    GLSECR, //< Cross Section Type L-Section with
                            //< Inside Curvature
                    GNODE, //< Correspondence between External and
                           //< Internal Node Numbering, and Number of
                           //< Degrees of Freedom of Each Node
                    GPIPE, //< Cross Section Type Tube
                    GSEPxxxx, //< Separation Description
                    GSEPSPEC, //< Specified Separation Description
                    GSETMEMB, //< Set (group) of Nodes or Elements (Members)
                    GSLAYER, //< General Eccentric Sandwich Element
                    GSLxxxxx, //< Layer Description
                    GSLPLATE, //< Plate Layer Description
                    GSLSTIFF, //< Stiffener Layer Description
                    GTONP, //< Cross Section T on Plate
                    GUNIVEC, //< Specification of Local Element
                             //< Coordinate System
                    GUSYI, //< Cross Section Type Unsymmetrical I-Beam
                    MAXDMP, //< # Material Data
                            //< Axial Damper Between Two Nodal Points
                    MAXSPR, //< Axial Spring Between Two Nodal Points
                    MCNT, //< Material for Non-linear Contact Element
                    MGDAMP, //< Damping Element to Ground
                    MGLDAMP, //< General 2-noded Damping Element
                    MGLMASS, //< General 2-noded Mass Element
                    MGMASS, //< 1-Noded Mass element
                    MGSPRNG, //< Element to Ground
                    MISOAL, //< Isotropy, Linear Acoustic Field Problem
                    MISOEML, //< Isotropy, Linear Electro-magnetic Field Problem
                    MISOHL, //< Isotropy, Linear Heat Conduction Analysis
                    MISOHNL, //< Isotropy, Non-linear Heat Conduction Analysis
                    MISOPL, //< Non-linear Isotropic Material,
                            //< Material Types 1-4
                    MISOSEL, //< Isotropy, Linear Elastic Structural Analysis
                    MISTEL, //< Temperature Dependent Isotropic,
                            //< Linear Elastic Material
                    MORSMEL, //< Anisotropy, Linear Elastic Structural
                             //< Analysis, 2-D Membrane Elements and
                             //< 2-D Thin Shell Elements
                    MORSSEL, //< Anisotropy, Linear Elastic Structural
                             //< Analysis, 3-D One- and Multilayered
                             //< Thick Shell Elements
                    MORSSOL, //< Anisotropy, Linear Elastic Structural
                             //< Analysis, Solid Elements
                    MSHGLSP, //< General 2-noded Spring/Shim Element
                    MTEMP, //< Scaling Curve for Temperature Variation
                    MTENONL, //< Non-linear Material with Temperature Dependency
                    MTRMEL, //< Local Transformation of the Axes of
                            //< Anisotropy, 2-D Membrane Elements and
                            //< 2-D Thin Shell Elements
                    MTRSEL, //< Local Transformation of the Axes of
                            //< Anisotropy, 3-D Multilayered Thick Shell
                            //< Element
                    MTRSOL, //< Local Transformation of the Axes of
                            //< Anisotropy, Solid Elements
                    AMATRIX, //< # Higher Level Data
                             //< ## Additional Subelement Data
                             //< Matrix control Data for Stiffness,
                             //< Mass, Damping, Load and Resulting
                             //< Displacement Matrix / Vector
                    AMDACCL, //< Vector Data for Matrix Element
                             //< Acceleration Vector
                    AMDDAMP, //< Matrix Data for Matrix Element Damping Matrix
                    AMDDISP, //< Vector Data for Matrix Element
                             //< Displacement Vector
                    AMDFREQ, //< Frequency Definition for AMATRIX Records
                    AMDLOAD, //< Vector Data for Matrix Element Load Vector
                    AMDMASS, //< Matrix Data for Matrix Element Mass Matrix
                    AMDSTIFF, //< Matrix Data for Matrix Element
                              //< Stiffness Matrix
                    AMDVELO, //< Vector Data for Matrix Element Velocity Vector
                    BSELL, //< # Boundary Conditions, Loads and Point Masses
                           //< Subelement Load Description
                    GELMNT2, //< Subelement Description with Simple
                             //< Correspondence between Degrees of
                             //< Freedom of Subelement and Relevant
                             //< Assembly
                    HIERARCH, //< #Super-Element Hierarchy Information in Highest Level T-File
                              //< Superelement Hierarchy Description
                    HSUPSTAT, //< Superelement Statistical Information
                    HSUPTRAN, //< Superelement Transformations
                };

                namespace __base {
//! Base class for all BDF card representations with base functionality.
                    class card : public extfem::__base::outline {
                    private:
                        std::unordered_map<std::string, types>
                        static const cardtype_map;
                    protected:
                        fem::types::empty static const empty;
                        fem::types::card static const head;
                    public:
                        size_t static card_split(
                            std::vector<std::string> const&, size_t const,
                            std::vector<std::string>&);
                        card(std::vector<std::string> const&, size_t const) {};
                        card() = default;
                        virtual ~card() = default;
                        virtual void read(
                            std::vector<std::string> const&, size_t const) = 0;
                        virtual card const &operator() (
                            std::vector<std::string> const&, size_t const);
                        virtual types
                        card_type() const = 0;
                    };

//! Base class for geometric properties. Ensure GEONO is unique across
//! all geometric property describing cards.
                    class geoprop : public card {
                    private:
                        std::unordered_set<long> static used_geono;
                        long static geono_maxset;
                    protected:
                        void set_geono(long const GEONO=0);
                        fem::types::entry_type<long> static const _form_GEONO;
                        geoprop();
                        geoprop(long const GEONO);
                        geoprop(std::vector<std::string> const&, size_t const);
                        void read(
                            std::vector<std::string> const&, size_t const) override;
                        card const &operator() (
                            std::vector<std::string> const&, size_t const) override;
                    public:
/*! Geometry type number, i.e. reference number used for element data
    definition of geometry properties (Cross sectional properties) of
    beams.
*/
                        long GEONO;
                        static void reset_geono();
                        virtual types
                        card_type() const override = 0;
                    };

/*! Base class for cards describing transformed coordinate systems
  (BNTRCOS, GUNIVEC).
*/
                    class transno : public card {
                    private:
                        std::unordered_set<long> static used_transno;
                        long static transno_maxset;
                    protected:
                        void set_transno(long const TRANSNO=0);
                        fem::types::entry_type<long> static const _form_TRANSNO;
                        transno();
                        transno(long const TRANSNO);
                        transno(std::vector<std::string> const&, size_t const);
                        void read(
                            std::vector<std::string> const&, size_t const) override;
                        using card::operator();
                    public:
/*! Transformation system number, i.e. reference number used for
    element data describing th local cross section coordinate system
    for beams.
*/
                        long TRANSNO;
                        static void reset_transno();
                        virtual types
                        card_type() const override = 0;
                    };

//! Base class for cards describing eccentrities (GECC, GECCEN).
                    class eccno : public card {
                    private:
                        std::unordered_set<long> static used_eccno;
                        long static eccno_maxset;
                    protected:
                        void set_eccno(long const ECCNO=0);
                        fem::types::entry_type<long> static const _form_ECCNO;
                        eccno();
                        eccno(long const ECCNO);
                        eccno(std::vector<std::string> const&, size_t const);
                        void read(
                            std::vector<std::string> const&, size_t const) override;
                        using card::operator();
                    public:
/*! Eccentricity number, referenced to on record `GELREF1`.
 */
                        long ECCNO;
                        static void reset_eccno();
                        virtual types
                        card_type() const override = 0;
                    };

//! Base class for FEM beam property describing classes.
                    class beam_prop : public geoprop {
                    private:
                        std::unordered_set<long> static used_gbeamg;
                        std::unordered_set<long> static used_cross_desc;
                    protected:
                        beam_prop() = default;
                        beam_prop(long const GEONO, bool const=false);
                        beam_prop(
                            std::vector<std::string> const&, size_t const);
                        beam_prop(
                            std::vector<std::string> const&, size_t const,
                            bool const);
                        void set_geono(long const GEONO, bool const);
                        using geoprop::read;
                        void read(
                            std::vector<std::string> const &, size_t const,
                            bool const);
                        using geoprop::operator();
                    public:
                        static void reset_geono();
                        virtual types
                        card_type() const override = 0;
                    };

//! Base class for material cards.
                    class material : public card {
                    protected:
                        fem::types::entry_type<long> static const _form_MATNO;
                        material() : card(), MATNO(0) {};
                        explicit material(long const MATNO);
                        material(
                            std::vector<std::string> const&, size_t const);
                        void read(
                            std::vector<std::string> const&, size_t const) override;
                        card const &operator() (
                            std::vector<std::string> const&, size_t const) override;
                    public:
/*! Material number, i.e. reference number referenced to by the
    element specification.
*/
                        long MATNO;
                        virtual types
                        card_type() const override = 0;
                    };
                }

                class unknown : public __base::card {
                public:
                    unknown(std::vector<std::string> const&, size_t const);
                    types
                    card_type() const override;
                    std::vector<std::string> content;
                protected:
                    std::ostream &put(std::ostream&) const override;
                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };
            }
        }
    }
}

// ReSharper disable CppUnusedIncludeDirective
#include "fem/elements.h"
#include "fem/cards_ident.h"
#include "fem/cards_bounds.h"
#include "fem/cards_node_elem.h"
#include "fem/cards_mat.h"
#include "fem/card_hl_node_elem.h"
#include "fem/cards_superele.h"
// ReSharper restore CppUnusedIncludeDirective

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
                void dispatch(
                    std::vector<std::string> const&,
                    size_t entries,
                    std::unique_ptr<__base::card>&);
            }
        }
    }
}
#endif // _FEM_CARDS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test""
// coding: utf-8
// End:
