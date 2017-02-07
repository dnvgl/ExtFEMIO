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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory>

#include "extfem_misc.h"

#include <my_c++14.h>

#include "config.h"

#include "fem/types.h"

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

#include "fem/elements.h"

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

                        dnvgl::extfem::fem::types::empty static const empty;

                        dnvgl::extfem::fem::types::card static const head;

                    public:

                        size_t static card_split(
                            std::vector<std::string> const&, size_t const,
                            std::vector<std::string>&);

                        card(std::vector<std::string> const&, size_t const);
                        card(void);

                        virtual ~card(void);

                        virtual void read(
                            std::vector<std::string> const&, size_t const) = 0;

                        virtual __base::card const &operator() (
                            std::vector<std::string> const&, size_t const);

                        virtual dnvgl::extfem::fem::cards::types const
                        card_type(void) const = 0;
                    };

/// Base class for geometric properties.
                    class geoprop : public card {
                    private:

                        std::unordered_set<long> static used_geono;
                        long static geono_maxset;

                    protected:

                        void set_geono(long const GEONO=0);

                        dnvgl::extfem::fem::types::entry_type<long>
                        static const _form_GEONO;

                        geoprop(void);
                        geoprop(long const GEONO);
                        geoprop(std::vector<std::string> const&, size_t const);

                        virtual void read(
                            std::vector<std::string> const&, size_t const);

                        virtual __base::card const &operator() (
                            std::vector<std::string> const&, size_t const);

                    public:

/** Geometry type number, i.e. reference number used for element data
    definition of geometry properties (Cross sectional properties) of
    beams.
*/
                        long GEONO;

                        static void reset_geono(void);

                        virtual dnvgl::extfem::fem::cards::types const
                        card_type(void) const = 0;
                    };

/// Base class for cards describing transformed coordinate systems
/// (BNTRCOS, GUNIVEC).
                    class transno : public card {
                    private:

                        std::unordered_set<long> static used_transno;
                        long static transno_maxset;

                    protected:

                        void set_transno(long const TRANSNO=0);

                        dnvgl::extfem::fem::types::entry_type<long>
                        static const _form_TRANSNO;

                        transno(void);
                        transno(long const TRANSNO);
                        transno(std::vector<std::string> const&, size_t const);

                        virtual void read(
                            std::vector<std::string> const&, size_t const);

                        using __base::card::operator();

                    public:

/** Transformation system number, i.e. reference number used for
    element data describing th local cross section coordinate system
    for beams.
*/
                        long TRANSNO;

                        static void reset_transno(void);

                        virtual dnvgl::extfem::fem::cards::types const
                        card_type(void) const = 0;
                    };

/// Base class for FEM beam property describing classes.
                    class beam_prop : public geoprop {

                    private:

                        std::unordered_set<long> static used_gbeamg;
                        std::unordered_set<long> static used_cross_desc;

                    protected:

                        beam_prop(void);
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

                        static void reset_geono(void);

                        virtual dnvgl::extfem::fem::cards::types const
                        card_type(void) const = 0;
                    };

/// Base class for material cards.
                    class material : public card {
                    protected:

                        dnvgl::extfem::fem::types::entry_type<long>
                        static const _form_MATNO;

                        material(void);
                        material(long const MATNO);
                        material(
                            std::vector<std::string> const&, size_t const);

                        virtual void read(
                            std::vector<std::string> const&, size_t const);

                        virtual __base::card const &operator() (
                            std::vector<std::string> const&, size_t const);

                    public:

/** Material number, i.e. reference number referenced to by the
    element specification.
*/
                        long MATNO;

                        virtual dnvgl::extfem::fem::cards::types const
                        card_type(void) const = 0;

                    };
                }

                class unknown : public __base::card {

                public:

                    unknown(std::vector<std::string> const&, size_t const);

                    dnvgl::extfem::fem::cards::types const
                    card_type(void) const;

                    std::vector<std::string> content;

                protected:

                    virtual std::ostream &put(std::ostream&) const;

                    virtual void read(
                        std::vector<std::string> const&, size_t const);
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
