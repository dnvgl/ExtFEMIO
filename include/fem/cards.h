/**
   \file fem/cards.h
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
                namespace __base {
                    class card;
                }
                class gelmnt1;
                class gelref1;
            }
        }
    }
}

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {

                void extern(*note_report)(std::string const&);
                void extern(*info_report)(std::string const&);
                void extern(*warn_report)(std::string const&);
                void extern(*error_report)(std::string const&);

/**
   \brief Name the different cards.
*/
                enum class types {
                    UNKNOWN,
/// Date and Program Information
                    DATE,
/// Nodal Coordinates
                    GCOORD,
/// Correspondence between External and Internal Node Numbering, and
/// Number of Degrees of Freedom of Each Node
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
/// Local Eccentricities
                    GECC,
/// Eccentricities
                    GECCEN,
/// Thickness of Two-dimensional Elements
                    GELTH,
/// Cross Section Type Box Beam
                    GBOX,
/// Cross Section Type Channel Beam
                    GCHAN,
/// Cross Section Type Channel Beam
                    GCHANR,
/// Section Type Double Bottom
                    GDOBO,
/// Cross Section Type I or H Beam
                    GIORH,
/// Cross Section Type I or H Beam with Inside Curvature
                    GIORHR,
/// Cross Section Type L-Section
                    GLSEC,
/// Cross Section Type L-Section with Inside Curvature
                    GLSECR,
/// Cross Section Type Tube
                    GPIPE,
/// Cross Section T on Plate
                    GTONP,
/// Cross Section Type Unsymmetrical I-Beam
                    GUSYI,
/// Flexible Joint/Hinge
                    BELFIX,
/// Nodes with Linear Dependence
                    BLDEP,
/// Nodes with Boundary Conditions
                    BNBCD,
/// Nodes with Prescribed Displacements and Accelerations
                    BNDISPL,
/// Nodes with Loads
                    BNLOAD,
/// Element to Ground
                    MGSPRNG,
/// set(group) of Nodes or Elements(Members)
                    GSETMEMB,
/// Specification of Local Element Coordinate System
                    GUNIVEC,
/// Isotropy, Linear Elastic Structural Analysis
                    MISOSEL,
/// Anisotropy, Linear Elastic Structural Analysis, 2-D Membrane
/// Elements and 2-D Thin Shell Elements
                    MORSMEL,
/// Name and Description of a set(group)
                    TDSETNAM,
/// Name and Description of a Super-Element.
                    TDSUPNAM,
/// User supplied Text
                    TEXT,
/// Name of Load
                    TDLOAD,
/// Subelement Load Description
                    BSELL,
/// Subelement Description with Simple Correspondence between Degrees
/// of Freedom of Subelement and Relevant Assembly
                    GELMNT2,
/// Superelement Statistical Information
                    HSUPSTAT,
/// Superelement Transformations
                    HSUPTRAN,
/// Superelement Hierarchy Description
                    HIERARCH,
/// Elements with Surface Loads
                    BEUSLO
                };

                namespace __base {
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
                        card();

                        virtual ~card();

                        virtual void read(
                            std::vector<std::string> const&, size_t const) = 0;

                        virtual card const &operator() (
                            std::vector<std::string> const&, size_t const);

                        virtual types
                        card_type() const = 0;
                    };

/// Base class for geometric properties.
                    class geoprop : public card {
                    private:

                        std::unordered_set<long> static used_geono;
                        long static geono_maxset;

                    protected:

                        void set_geono(long const GEONO=0);

                        fem::types::entry_type<long>
                        static const _form_GEONO;

                        geoprop();
                        geoprop(long const GEONO);
                        geoprop(std::vector<std::string> const&, size_t const);

                        void read(
                            std::vector<std::string> const&, size_t const) override;

                        card const &operator() (
                            std::vector<std::string> const&, size_t const) override;

                    public:

/** Geometry type number, i.e. reference number used for element data
    definition of geometry properties (Cross sectional properties) of
    beams.
*/
                        long GEONO;

                        static void reset_geono();

                        virtual types
                        card_type() const override = 0;
                    };

/// Base class for cards describing transformed coordinate systems
/// (BNTRCOS, GUNIVEC).
                    class transno : public card {
                    private:

                        std::unordered_set<long> static used_transno;
                        long static transno_maxset;

                    protected:

                        void set_transno(long const TRANSNO=0);

                        fem::types::entry_type<long>
                        static const _form_TRANSNO;

                        transno();
                        transno(long const TRANSNO);
                        transno(std::vector<std::string> const&, size_t const);

                        void read(
                            std::vector<std::string> const&, size_t const) override;

                        using card::operator();

                    public:

/** Transformation system number, i.e. reference number used for
    element data describing th local cross section coordinate system
    for beams.
*/
                        long TRANSNO;

                        static void reset_transno();

                        virtual types
                        card_type() const override = 0;
                    };

/// Base class for cards describing eccentrities (GECC, GECCEN).
                    class eccno : public card {
                    private:

                        std::unordered_set<long> static used_eccno;
                        long static eccno_maxset;

                    protected:

                        void set_eccno(long const ECCNO=0);

                        fem::types::entry_type<long>
                        static const _form_ECCNO;

                        eccno();
                        eccno(long const ECCNO);
                        eccno(std::vector<std::string> const&, size_t const);

                        void read(
                            std::vector<std::string> const&, size_t const) override;

                        using card::operator();

                    public:

/** Eccentricity number, referenced to on record `GELREF1`.
 */
                        long ECCNO;

                        static void reset_eccno();

                        virtual types
                        card_type() const override = 0;
                    };

/// Base class for FEM beam property describing classes.
                    class beam_prop : public geoprop {

                    private:

                        std::unordered_set<long> static used_gbeamg;
                        std::unordered_set<long> static used_cross_desc;

                    protected:

                        beam_prop();
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

/// Base class for material cards.
                    class material : public card {
                    protected:

                        fem::types::entry_type<long>
                        static const _form_MATNO;

                        material() : card(), MATNO(0) {};
                        explicit material(long const MATNO);
                        material(
                            std::vector<std::string> const&, size_t const);

                        void read(
                            std::vector<std::string> const&, size_t const) override;

                        card const &operator() (
                            std::vector<std::string> const&, size_t const) override;

                    public:

/** Material number, i.e. reference number referenced to by the
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

#include "fem/elements.h"
#include "fem/cards_ident.h"
#include "fem/cards_bounds.h"
#include "fem/cards_node_elem.h"
#include "fem/cards_mat.h"
#include "fem/card_hl_node_elem.h"
#include "fem/cards_superele.h"

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
