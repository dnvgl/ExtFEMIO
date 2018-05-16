/**
   \file
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
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <memory>

#include "extfem_misc.h"

#if (__GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))) || \
    (_MSC_VER && _MSC_VER <= 1700)
#include "my_c++14.h"
#endif

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/types.h"

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace cards {
                enum class types;
                typedef std::pair<bdf::types::base const*, void const*>
                format_entry;
                class comment;
            }
        }
    }
}

std::ostream &operator<< (
    std::ostream& os, dnvgl::extfem::bdf::cards::types const cardtype);

dnvgl::extfem::bdf::cards::format_entry
*format(const std::unique_ptr<dnvgl::extfem::bdf::types::card> &);

dnvgl::extfem::bdf::cards::format_entry
*format(std::string const &);

dnvgl::extfem::bdf::cards::format_entry
*format(const std::unique_ptr<dnvgl::extfem::bdf::types::empty>&);

template <typename _Ty>
dnvgl::extfem::bdf::cards::format_entry
*format(dnvgl::extfem::bdf::types::entry_type<_Ty> const&,
        _Ty const*);

template <typename _Ty>
dnvgl::extfem::bdf::cards::format_entry
*format(dnvgl::extfem::bdf::types::entry_type<_Ty> const&,
        dnvgl::extfem::bdf::types::entry_value<_Ty> const&);

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            void reset_statics();
            namespace cards {
                void extern(*note_report)(std::string const &);
                void extern(*info_report)(std::string const &);
                void extern(*warn_report)(std::string const &);
                void extern(*error_report)(std::string const &);
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
                           //!< structural element that may be
                           //!< nonlinear or < frequency dependent.
                    CBUSH1D, //!< Defines the connectivity of a
                    //!< one-dimensional spring and viscous damper
                    //!< element.
                    PBUSH,//!< Defines the nominal property values for
                          //!< a generalized spring-and-damper
                          //!< structural element.
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
                    PROPERTY, //!< # Internal Data
                    //!< base class for property
                    BEAM_BASE, //!< base class for beam/bar property
                    //!< description
                    BAR_PROP, //!< base class for bar property
                    //!< description
                    BEAM_PROP, //!< base class for beam property description
                    CAXIFi, //!< Defines an axisymmetric fluid element that
                    //!< connects i = 2, 3, or 4 fluid points.
                    COMMENT, //!< comment lines
                    DELETE,
                    ABINFL,
                    ACC,
                    ACCEL,
                    ACCEL1,
                    ACCMETR,
                    ACCSSPT,
                    ACLOAD,
                    ACMODL,
                    ACPEMCP,
                    ACSRCE,
                    ACTIVAT,
                    ACTRIM,
                    ADAPT,
                    ADUMi,
                    AECOMP,
                    AECOMPL,
                    AEDW,
                    AEFACT,
                    AEFORCE,
                    AEGRID,
                    AELINK,
                    AELIST,
                    AELISTC,
                    AEPARM,
                    AEPRESS,
                    AEQUAD4,
                    AERO,
                    AEROS,
                    AESCALE,
                    AESTAT,
                    AESURF,
                    AESURFS,
                    AETRIA3,
                    AIRBAG,
                    ALIASM,
                    ASET,
                    ASET1,
                    AXIC,
                    AXIF,
                    AXSLOT,
                    BAROR,
                    BARRIER,
                    BCBDPRP,
                    BCBMRAD,
                    BCBODY,
                    BCBODY1,
                    BCBOX,
                    BCBZIER,
                    BCGM700,
                    BCGRID,
                    BCHANGE,
                    BCMATL,
                    BCMOVE,
                    BCNURB2,
                    BCNURBS,
                    BCONECT,
                    BCONP,
                    BCONPRG,
                    BCONPRP,
                    BCONUDS,
                    BCPARA,
                    BCPATCH,
                    BCPFLG,
                    BCPROP,
                    BCPROP1,
                    BCRIGID,
                    BCRGSRF,
                    BCSCAP,
                    BCSEG,
                    BCTABLE,
                    BCTABL1,
                    BCTRIM,
                    BDYLIST,
                    BDYFORC,
                    BDYOR,
                    BDYRELX,
                    BEADVAR,
                    BEAMOR,
                    BFRlC,
                    BIAS,
                    BJOIN,
                    BLDOUT,
                    BLSEG,
                    BNDFIX,
                    BNDFIX1,
                    BNDFREE,
                    BNDFRE1,
                    BNDGRID,
                    BOLT,
                    BOUTPUT,
                    BRKSQL,
                    BSET,
                    BSET1,
                    BSQUEAL,
                    BSURF,
                    BWIDTH,
                    CACINF3,
                    CACINF4,
                    CAMPBLL,
                    CAXISYM,
                    CBARAO,
                    CBEAM3,
                    CBELT,
                    CBUSH2D,
                    CDUMi,
                    CFAST,
                    CFLUIDi,
                    CIFHEX,
                    CIFPENT,
                    CIFQDX,
                    CIFQUAD,
                    CINTC,
                    CLOAD,
                    CMARKB2,
                    CMARKN1,
                    CMREBAI,
                    CMREBAR,
                    CNTRUDS,
                    COHESIV,
                    CONCTL,
                    CONSPOT,
                    CONTRLT,
                    CONV,
                    CONV3,
                    CONVM,
                    CORD1C,
                    CORD1R,
                    CORD1RX,
                    CORD1S,
                    CORD2C,
                    CORD2R,
                    CORD2RX,
                    CORD2S,
                    CORD3G,
                    CORD3R,
                    CORD3RX,
                    COUOPT,
                    COUP1FL,
                    COUPINT,
                    COUPLE,
                    CREEP,
                    CROSSEC,
                    CSEAM,
                    CSET,
                    CSET1,
                    CSPH,
                    CSPR,
                    CSSCHD,
                    CSSHL,
                    CSSHLH,
                    CSSHLM,
                    CSSHLP,
                    CSUPER,
                    CSUPEXT,
                    CTQUAD,
                    CTTRIA,
                    CWELD,
                    CYAX,
                    CYJOIN,
                    CYLINDR,
                    CYSUP,
                    CYSYM,
                    D2R0000,
                    D2RAUTO,
                    D2RINER,
                    DAMPGBL,
                    DAMPING,
                    DAMPMAS,
                    DAMPSTF,
                    DAREA,
                    DBEXSSS,
                    DBREG,
                    DCONADD,
                    DCONSTR,
                    DDVAL,
                    DEACTEL,
                    DEFORM,
                    DEFUSET,
                    DELAY,
                    DEQATN,
                    DESVAR,
                    DETSPH,
                    DIVERG,
                    DLINK,
                    DLOAD,
                    DMI,
                    DMIAX,
                    DMIG,
                    DMIGOUT,
                    DMIGROT,
                    DMIJ,
                    DMIJI,
                    DMIK,
                    DOPTPRM,
                    DPHASE,
                    DRESP1,
                    DRESP2,
                    DRESP3,
                    DSCREEN,
                    DTABLE,
                    DTABLE2,
                    DTI,
                    DVBSHAP,
                    DVCREL1,
                    DVCREL2,
                    DVGRID,
                    DVLREL1,
                    DVMREL1,
                    DVMREL2,
                    DVPREL1,
                    DVPREL2,
                    DVSHAP,
                    DVPSURF,
                    DYCHANG,
                    DYDELEM,
                    DYFSISW,
                    DYPARAM,
                    DYRIGSW,
                    DYTERMT,
                    DYTIMHS,
                    ECHOOFF,
                    ECHOON,
                    EIGB,
                    EIGC,
                    EIGP,
                    EIGR,
                    EIGRL,
                    ELEMUDS,
                    ELIST,
                    ENDDYNA,
                    ENTUDS,
                    EOSGAM,
                    EOSGRUN,
                    EOSIG,
                    EOSJWL,
                    EOSMG,
                    EOSMG2,
                    EOSPOL,
                    EOSTAB,
                    EOSTABC,
                    EOSTAIT,
                    EOSUDS,
                    EPOINT,
                    ERPPNL,
                    EULFOR,
                    EULFOR1,
                    EULFREG,
                    EXPLSV,
                    EXTRN,
                    FAILJC,
                    FAILMPS,
                    FAILUDS,
                    FBADLAY,
                    FBALOAD,
                    FBAPHAS,
                    FBODYLD,
                    FBODYSB,
                    FEEDGE,
                    FEFACE,
                    FFCONTR,
                    FLFACT,
                    FLOW,
                    FLOWDEF,
                    FLOWSPH,
                    FLOWT,
                    FLOWUDS,
                    FLSYM,
                    FLUTTER,
                    FORCE1,
                    FORCE2,
                    FORCEAX,
                    FREEPT,
                    FREQ,
                    FREQ1,
                    FREQ2,
                    FREQ3,
                    FREQ4,
                    FREQ5,
                    FRFCOMP,
                    FRFCONN,
                    FRFFLEX,
                    FRFRELS,
                    FRFSPC1,
                    FRFXIT,
                    FRFXIT1,
                    FSICTRL,
                    FSLIST,
                    FTGDEF,
                    FTGEVNT,
                    FTGLOAD,
                    FTGPARM,
                    FTGSEQ,
                    GBAG,
                    GBAGCOU,
                    GENUDS,
                    GMBC,
                    GMBNDC,
                    GMBNDS,
                    GMCONV,
                    GMCORD,
                    GMCURV,
                    GMLOAD,
                    GMNURB,
                    GMQVOL,
                    GMSPC,
                    GMSURF,
                    GRDSET,
                    GRIA,
                    GRIDA,
                    GRIDB,
                    GRIDF,
                    GRIDS,
                    GUST,
                    HADACRI,
                    HADAPTL,
                    HEATLOS,
                    HGSUPPR,
                    HTRCONV,
                    HTRRAD,
                    HYBDAMP,
                    HYDSTAT,
                    INCLUDE,
                    INFLCG,
                    INFLFRC,
                    INFLGAS,
                    INFLHB,
                    INFLTNK,
                    INFLTR,
                    INITGAS,
                    IPSTRAIN,
                    IPSTRN,
                    ISTRESS,
                    ISTRNSH,
                    ISTRNSO,
                    ISTRNTS,
                    ISTRSBE,
                    ISTRSSH,
                    ISTRSSO,
                    ISTRSSS,
                    ISTRSTS,
                    ITER,
                    LEAKAGE,
                    LOADCLID,
                    LOADCNAM,
                    LOADCSUB,
                    LOADCYH,
                    LOADCYN,
                    LOADCYT,
                    LOADOF,
                    LOADT,
                    LORENZI,
                    LSEQ,
                    MACREEP,
                    MARCIN,
                    MARCOUT,
                    MARPRN,
                    MAT3,
                    MAT4,
                    MAT5,
                    MAT8,
                    MAT9,
                    MAT10,
                    MATD001,
                    MATD2AN,
                    MATD2OR,
                    MATD003,
                    MATD004,
                    MATD005,
                    MATD006,
                    MATD007,
                    MATD009,
                    MATD010,
                    MATD012,
                    MATD013,
                    MATD014,
                    MATD015,
                    MATD016,
                    MATD018,
                    MATD019,
                    MATD020,
                    MATD20M,
                    MATD021,
                    MATD022,
                    MATD024,
                    MATD025,
                    MATD026,
                    MATD027,
                    MATD028,
                    MATD029,
                    MATD030,
                    MATD031,
                    MATD032,
                    MATD034,
                    MATD036,
                    MATD037,
                    MATD038,
                    MATD039,
                    MATD040,
                    MATD053,
                    MATD054,
                    MATD057,
                    MATD058,
                    MATD059,
                    MATD062,
                    MATD063,
                    MATD064,
                    MATD065,
                    MATD066,
                    MATD067,
                    MATD068,
                    MATD069,
                    MATD070,
                    MATD071,
                    MATD072,
                    MATD72R,
                    MATD073,
                    MATD074,
                    MATD076,
                    MATD077,
                    MATD77H,
                    MATD77O,
                    MATD078,
                    MATD080,
                    MATD081,
                    MATD083,
                    MATD084,
                    MATD087,
                    MATD089,
                    MATD091,
                    MATD092,
                    MATD093,
                    MATD094,
                    MATD095,
                    MATD096,
                    MATD097,
                    MATD098,
                    MATD099,
                    MATD100,
                    MATD106,
                    MATD107,
                    MATD110,
                    MATD111,
                    MATD112,
                    MATD114,
                    MATD115,
                    MATD116,
                    MATD119,
                    MATD120,
                    MATD12J,
                    MATD12R,
                    MATD121,
                    MATD123,
                    MATD124,
                    MATD126,
                    MATD127,
                    MATD128,
                    MATD129,
                    MATD130,
                    MATD143,
                    MATD145,
                    MATD147,
                    MATD155,
                    MATD156,
                    MATD158,
                    MATD159,
                    MATD163,
                    MATD164,
                    MATD170,
                    MATD173,
                    MATD176,
                    MATD181,
                    MATD184,
                    MATD185,
                    MATD186,
                    MATD188,
                    MATD190,
                    MATD193,
                    MATD196,
                    MATD224,
                    MATD266,
                    MATD272,
                    MATDB01,
                    MATDERO,
                    MATDEUL,
                    MATDIGI,
                    MATDMG,
                    MATDS01,
                    MATDS02,
                    MATDS03,
                    MATDS04,
                    MATDS05,
                    MATDS06,
                    MATDS07,
                    MATDS08,
                    MATDS13,
                    MATDS14,
                    MATDS15,
                    MATDT01,
                    MATDT02,
                    MATDT03,
                    MATDT04,
                    MATDT05,
                    MATDT06,
                    MATDSW1,
                    MATDSW2,
                    MATDSW3,
                    MATDSW4,
                    MATDSW5,
                    MATEP,
                    MATF,
                    MATF1,
                    MATFTG,
                    MATG,
                    MATHE,
                    MATHED,
                    MATHP,
                    MATNLE,
                    MATORT,
                    MATPE1,
                    MATRIG,
                    MATS1,
                    MATS3,
                    MATS8,
                    MATSMA,
                    MATSORT,
                    MATT1,
                    MATT2,
                    MATT3,
                    MATT4,
                    MATT5,
                    MATT8,
                    MATT9,
                    MATTEP,
                    MATTF,
                    MATTG,
                    MATTHE,
                    MATTORT,
                    MATTUSR,
                    MATTVE,
                    MATUDS,
                    MATUSR,
                    MATVE,
                    MATVP,
                    MAUXCMD,
                    MBOLT,
                    MBOLTUS,
                    MCHSTAT,
                    MCOHE,
                    MDELAM,
                    MDLPRM,
                    MDMIAUX,
                    MDMIOUT,
                    MESH,
                    MESUPER,
                    METADATA,
                    MFLUID,
                    MGRSPR,
                    MINSTAT,
                    MISLAND,
                    MIXTURE,
                    MKAERO1,
                    MKAERO2,
                    MLAYOUT,
                    MNF600,
                    MODTRAK,
                    MOMAX,
                    MOMENT1,
                    MOMENT2,
                    MONCARL,
                    MONCNCM,
                    MONDSP1,
                    MONGRP,
                    MONPNT1,
                    MONPNT2,
                    MONPNT3,
                    MONSUM,
                    MONSUM1,
                    MONSUMT,
                    MPC,
                    MPCADD,
                    MPCAX,
                    MPCD,
                    MPCREEP,
                    MPCY,
                    MPHEAT,
                    MPROCS,
                    MREVERS,
                    MRSSCON,
                    MSTACK,
                    MT16SEL,
                    MT16SPL,
                    MTABRV,
                    MTCREEP,
                    MTHERM,
                    NLADAPT,
                    NLAUTO,
                    NLCYSYM,
                    NLDAMP,
                    NLFREQ,
                    NLFREQ1,
                    NLHARM,
                    NLHEATC,
                    NLMOPTS,
                    NLOUT,
                    NLOUTUD,
                    NLPARM,
                    NLPCI,
                    NLRGAP,
                    NLRSFD,
                    NLSTEP,
                    NLSTRAT,
                    NOLIN1,
                    NOLIN2,
                    NOLIN3,
                    NOLIN4,
                    NSM,
                    NSM1,
                    NSMADD,
                    NSML,
                    NSML1,
                    NTHICK,
                    OMIT,
                    OMIT1,
                    OMITAX,
                    OUTPUT,
                    OUTRCV,
                    PAABSF,
                    PACABS,
                    PACBAR,
                    PACINF,
                    PAERO1,
                    PAERO2,
                    PAERO3,
                    PAERO4,
                    PAERO5,
                    PANEL,
                    PARAMARC,
                    PAXISYM,
                    PAXSYMH,
                    PBARN1,
                    PBCOMP,
                    PBDISCR,
                    PBEAM3,
                    PBEAM71,
                    PBEAMD,
                    PBELTD,
                    PBEMN1,
                    PBEND,
                    PBMARB6,
                    PBMNUM6,
                    PBMSECT,
                    PBRSECT,
                    PBSPOT,
                    PBUSH1D,
                    PBUSH2D,
                    PBUSHT,
                    PCOHE,
                    PCOMP,
                    PCOMPA,
                    PCOMPF,
                    PCOMPG,
                    PCOMPLS,
                    PCONEAX,
                    PCONV,
                    PCONVM,
                    PCONV1,
                    PDAMP,
                    PDAMP5,
                    PDAMPT,
                    PDUMi,
                    PELAS,
                    PELAS1,
                    PELAST,
                    PERMEAB,
                    PERMGBG,
                    PEULER,
                    PEULER1,
                    PFAST,
                    PFTG,
                    PGAP,
                    PHBDY,
                    PINTC,
                    PINTS,
                    PLBLAST,
                    PLCOMP,
                    PLOAD,
                    PLOAD1,
                    PLOAD2,
                    PLOAD4,
                    PLOADB3,
                    PLOADX1,
                    PLPLANE,
                    PLSOLID,
                    PMARKER,
                    PMASS,
                    PMINC,
                    PMREBAI,
                    PMREBAR,
                    POINT,
                    POINTAX,
                    PORFCPL,
                    PORFGBG,
                    PORFLOW,
                    PORFLWT,
                    PORHOLE,
                    PORHYDS,
                    PORUDS,
                    PRAC2D,
                    PRAC3D,
                    PRESAX,
                    PRESPT,
                    PRESTRS,
                    PRIMx,
                    PRJCON,
                    PRODN1,
                    PSEAM,
                    PSET,
                    PSHEAR,
                    PSHEARN,
                    PSHELL1,
                    PSHELLD,
                    PSHLN1,
                    PSHLN2,
                    PSLDN1,
                    PSOLID,
                    PSOLIDD,
                    PSPH,
                    PSPRMAT,
                    PSSHL,
                    PTSHELL,
                    PTUBE,
                    PVAL,
                    PVISC,
                    PWELD,
                    QBDY1,
                    QBDY2,
                    QBDY3,
                    QBDY4,
                    QHBDY,
                    QSET,
                    QSET1,
                    QVECT,
                    QVOL,
                    RADBC,
                    RADBC2,
                    RADBND,
                    RADC,
                    RADCAV,
                    RADCOL,
                    RADCT,
                    RADLST,
                    RADM,
                    RADMT,
                    RADMTX,
                    RADSET,
                    RANDPS,
                    RANDT1,
                    RBAX3D,
                    RBE2D,
                    RBE2A,
                    RBE2F,
                    RBE2GS,
                    RBE3U,
                    RBJOINT,
                    RBJSTIF,
                    RCONN,
                    RCPARM,
                    RCROSS,
                    RELEASE,
                    RESTART,
                    RFORCE,
                    RGYRO,
                    RINGAX,
                    RINGFL,
                    RLOAD1,
                    RLOAD2,
                    ROTHYBD,
                    ROTOR,
                    ROTORAX,
                    ROTORG,
                    ROTORSE,
                    RSPINR,
                    RSPINT,
                    RVDOF,
                    RVDOF1,
                    SANGLE,
                    SBPRET,
                    SBRETR,
                    SBSENSR,
                    SBSLPR,
                    SEBNDRY,
                    SEBSET,
                    SEBSET1,
                    SEBULK,
                    SECONCT,
                    SECSET,
                    SECSET1,
                    SECTAX,
                    SEDLINK,
                    SEDRSP2,
                    SEDRSP3,
                    SEELT,
                    SEEXCLD,
                    SELABEL,
                    SELOC,
                    SEMPLN,
                    SENQSET,
                    SEQGP,
                    SEQROUT,
                    SEQSEP,
                    SEQSET,
                    SEQSET1,
                    SESET,
                    SESUP,
                    SET1,
                    SET2,
                    SET3,
                    SET4,
                    SETREE,
                    SEUSET,
                    SEUSET1,
                    SHREL,
                    SHRPOL,
                    SHRUDS,
                    SLBDY,
                    SLOAD,
                    SLOADN1,
                    SNORM,
                    SOL2SPH,
                    SPBLND1,
                    SPBLND2,
                    SPC,
                    SPC1,
                    SPCADD,
                    SPCAX,
                    SPCD,
                    SPCD2,
                    SPCNR,
                    SPCOFF,
                    SPCOFF1,
                    SPCR,
                    SPHDEF,
                    SPHERE,
                    SPHSYM,
                    SPLINE6,
                    SPLINE7,
                    SPLINEX,
                    SPLINRB,
                    SPOINT,
                    SPRBCK,
                    SPRELAX,
                    SPWRS,
                    STOCHAS,
                    SUPAX,
                    SUPORT,
                    SUPORT1,
                    SUPORT6,
                    SURFINI,
                    SWLDPRM,
                    TABD1MD,
                    TABDMP1,
                    TABISTR,
                    TABL3D,
                    TABLE3D,
                    TABLED1,
                    TABLED2,
                    TABLED3,
                    TABLED4,
                    TABLED5,
                    TABLEHT,
                    TABLEDR,
                    TABLEH1,
                    TABLEL1,
                    TABLEM1,
                    TABLEM2,
                    TABLEM3,
                    TABLEM4,
                    TABLES1,
                    TABLEST,
                    TABLFTG,
                    TABRND1,
                    TABRNDG,
                    TABSCTL,
                    TEMP,
                    TEMPAX,
                    TEMPB3,
                    TEMPBC,
                    TEMPD,
                    TEMPF,
                    TEMPN1,
                    TEMPP1,
                    TEMPP3,
                    TEMPRB,
                    TERMIN,
                    TF,
                    THPAD,
                    TIC,
                    TICD,
                    TICEL,
                    TICEUDS,
                    TICEUL1,
                    TICREG,
                    TICVAL,
                    TIC3,
                    TIM2PSD,
                    TIMNAT,
                    TIMNVH,
                    TIMSML,
                    TIRE1,
                    TLOAD1,
                    TLOAD2,
                    TMPSET,
                    TODYNA,
                    TOMVAR,
                    TOPVAR,
                    TRIM,
                    TRIM2,
                    TRMCPL,
                    TSTEP,
                    TSTEPNL,
                    TTEMP,
                    UDNAME,
                    UDSESV,
                    UNBALNC,
                    UNGLUE,
                    USET,
                    USET1,
                    USRSUB6,
                    UXVEC,
                    VCCT,
                    VIEW,
                    VIEW3D,
                    VIEWEX,
                    WALL,
                    WALLGEO,
                    WEAR,
                    WETELME,
                    WETELMG,
                    WETLOAD,
                    WETSURF,
                    YLDHY,
                    YLDJC,
                    YLDMC,
                    YLDMSS,
                    YLDPOL,
                    YLDRPL,
                    YLDSG,
                    YLDTM,
                    YLDUDS,
                    YLDVM,
                    YLDZA,
                    UNKNOWN //!< unknown card
                };

                namespace __base {
                    /**
                     * \brief Base class for all classes representing BDF cards.
                     */
                    class card : public extfem::__base::outline {
                        /**
                         * \brief Two character strings for continuation lines in Free Form Format cards.
                         */
                        virtual bool keep_all_entries() const;
                        static const std::set<char> free_form_cont;
                        static const std::map<std::string, types> cardtype_map;
                    protected:
                        static dnvgl::extfem::bdf::types::empty empty;
                        static bdf::types::card head;
                        static std::string format_outlist(
                            const std::list<std::unique_ptr<format_entry> >&,
                            bool keep_all_entries=false);
                        std::ostream &put(std::ostream&) const override;
                        virtual void collect_outdata(
                            std::list<std::unique_ptr<format_entry> >&) const = 0;
                        virtual card const &operator()(std::list<std::string> const &) = 0;
                        virtual void read(std::list<std::string> const &) = 0;
                        virtual void check_data() = 0;
                    public:
                        card() = default;
                        ~card() = default;
                        explicit card(const std::list<std::string> &);
                        friend format_entry *::format(
                            std::unique_ptr<dnvgl::extfem::bdf::types::card>
                            const &);
                        friend format_entry *::format(std::string const &);
                        friend format_entry *::format(
                            std::unique_ptr<
                            dnvgl::extfem::bdf::types::empty> const&);
                        template <typename _Ty> friend format_entry *::format(
                            dnvgl::extfem::bdf::types::entry_type<_Ty> const&,
                            _Ty const*);
                        template <typename _Ty> friend format_entry *::format(
                            dnvgl::extfem::bdf::types::entry_type<_Ty> const&,
                            dnvgl::extfem::bdf::types::entry_value<_Ty> const&);
                        static void card_split(
                            std::list<std::string> const &,
                            std::list<std::string>&);
                        /**
                         * \brief returns the card type of the current card.
                         * \return Current card type.
                         */
                        virtual types card_type() const = 0;
                        void static reset();
                    };
                }

                class unknown : public __base::card {
                public:
                    std::vector<std::string> content;
                    unknown() = default;
                    ~unknown() = default;
                    explicit unknown(const std::list<std::string> &inp);
                    types card_type() const override;
                    void read(const std::list<std::string> &inp) override;
                    card const &operator()(std::list<std::string> const &) override;
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
                };

                class comment : public __base::card {
                public:
                    /*!
                      Comment test
                    */
                    std::list<std::string> content;
                    /*! Syntax extension to BDF recognized by
                      ExtFEMIO: if one of 235, 315, 355, 390, or 460
                      appears in a comment the value shall be used as
                      yield stress for the next material definition.
                    */
                    static std::shared_ptr<double> yield;
                    comment() = default;
                    ~comment();
                    explicit comment(std::list<std::string> const &inp);
                    explicit comment(
                        std::vector<std::string> const &inp,
                        double *yield=nullptr);
                    explicit comment(
                        std::string const *content,
                        double *yield=nullptr);
                    explicit comment(
                        std::string const &content,
                        double *yield=nullptr);
                    types card_type() const override;
                    card const &operator()(
                        std::list<std::string> const &inp) override;
                    card const &operator()(
                        std::vector<std::string> const &content,
                        double *yield=nullptr);
                    card const &operator()(
                        std::string const *content,
                        double *yield=nullptr);
                    card const &operator()(
                        std::string const &content,
                        double *yield=nullptr);
                    void static clear_yield();
                private:
                    /*!
                      Store yield stress on a per comment base to
                      allow correct output.
                    */
                    std::shared_ptr<double> __yield = nullptr;
                    std::ostream &put(std::ostream&) const override;
                    void read(std::list<std::string> const &inp) override;
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&)
                        const override;
                    void check_data() override;
                protected:
                    /*!
                      Regular expression to identify yield stress
                      definitions in comments.
                    */
#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex
#else
                    std::regex
#endif
                    static find_yield;
                private:
                    void static to_yield(std::string const);
                };
            }
        }
    }
}

inline dnvgl::extfem::bdf::cards::format_entry
*format(dnvgl::extfem::bdf::types::card const &formatter) {
    return new dnvgl::extfem::bdf::cards::format_entry(
        const_cast<dnvgl::extfem::bdf::types::card*>(&formatter), nullptr);
}

inline dnvgl::extfem::bdf::cards::format_entry
*format(std::string const &val) {
    return new dnvgl::extfem::bdf::cards::format_entry(
        new dnvgl::extfem::bdf::types::rstring(val), nullptr);
}

inline dnvgl::extfem::bdf::cards::format_entry
*format(dnvgl::extfem::bdf::types::empty const &formatter) {
    return new dnvgl::extfem::bdf::cards::format_entry(
        static_cast<dnvgl::extfem::bdf::types::base const*>(&formatter), nullptr);
}

template <typename _Ty> inline
dnvgl::extfem::bdf::cards::format_entry
*format(dnvgl::extfem::bdf::types::entry_type<_Ty> const &formatter,
        _Ty const *val) {
    return new dnvgl::extfem::bdf::cards::format_entry(
        static_cast<dnvgl::extfem::bdf::types::base const*>(&formatter),
        static_cast<void const*>(val));
}

template <typename _Ty> inline
dnvgl::extfem::bdf::cards::format_entry
*format(dnvgl::extfem::bdf::types::entry_type<_Ty> const &formatter,
        dnvgl::extfem::bdf::types::entry_value<_Ty> const &val) {
    return new dnvgl::extfem::bdf::cards::format_entry(
        static_cast<dnvgl::extfem::bdf::types::base const*>(&formatter),
        static_cast<void const*>(&val));
}

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace cards {
/// Handle Nastran Bulk `ENDDATA` entries.
/** # Bulk Data Delimiter

    Designates the end of the Bulk Data Section.

    # Format

    | 1          | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
    | ---------- | - | - | - | - | - | - | - | - | -- |
    | `ENDDATA`  |   |   |   |   |   |   |   |   |    |
*/
                class enddata : public __base::card {
                    static bdf::types::card head;
                    using __base::card::format_outlist;
                public:
                    enddata() = default;
                    ~enddata() = default;
                    explicit enddata(const std::list<std::string> &);
                    types card_type() const override;
                    void read(std::list<std::string> const &) override;
                    card const &operator()(std::list<std::string> const &) override;
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
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
                    static bdf::types::card head;
                    using __base::card::format_outlist;
                    static bdf::types::entry_type<long> form_ID;
                    static bdf::types::entry_type<long> form_CP;
                    static bdf::types::entry_type<double> form_X1;
                    static bdf::types::entry_type<double> form_X2;
                    static bdf::types::entry_type<double> form_X3;
                    static bdf::types::entry_type<long> form_CD;
                    static bdf::types::entry_type<std::vector<int> > form_PS;
                    static bdf::types::entry_type<long> form_SEID;
                public:
                    /** Grid point identification number. (0 < Integer <
                        100000000)
                    */
                    bdf::types::entry_value<long> ID;
                    /** Identification number of coordinate system in which the
                        location of the grid point is defined. (Integer > 0 or
                        blank)
                    */
                    bdf::types::entry_value<long> CP;
                    /** *x* Location of the grid point in coordinate system CP.
                        (Real; Default = 0.0)
                    */
                    bdf::types::entry_value<double> X1;
                    /** *y* Location of the grid point in coordinate system CP.
                        (Real; Default = 0.0)
                    */
                    bdf::types::entry_value<double> X2;
                    /** *z* Location of the grid point in coordinate system CP.
                        (Real; Default = 0.0)
                    */
                    bdf::types::entry_value<double> X3;
                    /** Identification number of coordinate system in which the
                        displacements, degrees-of-freedom, constraints, and
                        solution std::lists are defined at the grid point.
                        (Integer > -1 or blank)
                    */
                    bdf::types::entry_value<long> CD;
                    /** Permanent single-point constraints associated with the
                        grid point. (Any of the Integers 1 through 6 with no
                        embedded blanks, or blank.)
                    */
                    bdf::types::entry_value<std::vector<int> > PS;
                    /** Superelement identification number. (Integer > 0;
                        Default = 0)
                    */
                    bdf::types::entry_value<long> SEID;
                    grid() = default;
                    ~grid() = default;
                    explicit grid(const std::list<std::string> &);
                    grid(long const *ID, long const *CP,
                         double const *X1, double const *X2, double const *X3,
                         long const *CD=nullptr,
                         std::vector<int> const *PS=nullptr,
                         long const *SEID=nullptr);
                    grid(long const &ID, long const &CP,
                         double const &X1, double const &X2, double const &X3);
                    types card_type() const override;
                    void read(const std::list<std::string> &) override;
                    card const &operator()(const std::list<std::string> &) override;
                    card const &operator()(
                        long const *ID, long const *CP,
                        double const *X1, double const *X2, double const *X3,
                        long const *CD=nullptr,
                        std::vector<int> const *PS=nullptr,
                        long const *SEID=nullptr);
                    card const &operator()(
                        long const &ID, long const &CP,
                        double const &X1, double const &X2, double const &X3);
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
                };

                namespace __base {
/// Base class for material definitions
                    class mat : public card {
                    protected:
                        static bdf::types::entry_type<long> form_MID;
                        static bdf::types::entry_type<double> form_G;
                        static bdf::types::entry_type<double> form_RHO;
                        static bdf::types::entry_type<double> form_A;
                        static bdf::types::entry_type<double> form_TREF;
                        static bdf::types::entry_type<double> form_GE;
                        static bdf::types::entry_type<double> form_ST;
                        static bdf::types::entry_type<double> form_SC;
                        static bdf::types::entry_type<double> form_SS;
                        static bdf::types::entry_type<long> form_MCSID;
                    public:
                        /** Material identification number. (Integer > 0)
                         */
                        bdf::types::entry_value<long> MID;
                        /** Mass density. See Remark 5. (Real)
                         */
                        bdf::types::entry_value<double> RHO;
                        /** Reference temperature for the calculation of thermal
                            loads, or a temperature-dependent thermal expansion
                            coefficient. (Real; Default = 0.0 if `A` is specified.)
                        */
                        bdf::types::entry_value<double> TREF;
                        /** Structural element damping coefficient. (Real)
                         */
                        bdf::types::entry_value<double> GE;
                        /** Stress limits for tension is optionally supplied, used
                            only to compute margins of safety in certain elements;
                            and have no effect on the computational procedures.
                            (Real > 0.0 or blank)
                        */
                        bdf::types::entry_value<double> ST;
                        /** Stress limits for compression is optionally supplied,
                            used only to compute margins of safety in certain
                            elements; and have no effect on the computational
                            procedures. (Real > 0.0 or blank)
                        */
                        bdf::types::entry_value<double> SC;
                        /** Stress limits for shear is optionally supplied, used
                            only to compute margins of safety in certain elements;
                            and have no effect on the computational procedures.
                            (Real > 0.0 or blank)
                        */
                        bdf::types::entry_value<double> SS;
                        /** Material coordinate system identification number. Used
                            only for `PARAM,CURV` processing. (Integer > 0 or blank)
                        */
                        bdf::types::entry_value<long> MCSID;
                        /** extra values taken from comments
                         */
                        struct {
                            /// yield stress
                            std::shared_ptr<double> yield{nullptr};
                        } extra;
                    protected:
                        mat() = default;
                    public:
                        ~mat() = default;
                    protected:
                        explicit mat(const std::list<std::string> &);
                        explicit mat(long *MID, double *RHO=nullptr,
                            double *TREF=nullptr, double *GE=nullptr,
                            double *ST=nullptr, double *SC=nullptr,
                            double *SS=nullptr, long *MCSID=nullptr);
                        void operator() (
                            long *MID, double *RHO=nullptr,
                            double *TREF=nullptr, double *GE=nullptr,
                            double *ST=nullptr, double *SC=nullptr,
                            double *SS=nullptr, long *MCSID=nullptr);
                        virtual void check_data() override;
                        void read(std::list<std::string> const &) override;
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
                    static bdf::types::card head;
                    using __base::card::format_outlist;
                    using __base::mat::form_MID;
                    using __base::mat::form_G;
                    using __base::mat::form_RHO;
                    using __base::mat::form_A;
                    using __base::mat::form_TREF;
                    using __base::mat::form_GE;
                    using __base::mat::form_ST;
                    using __base::mat::form_SC;
                    using __base::mat::form_SS;
                    using __base::mat::form_MCSID;
                    // static const dnvgl::extfem::bdf::types::entry_type<long> form_MID;
                    static bdf::types::entry_type<double> form_E;
                    // static const dnvgl::extfem::bdf::types::entry_type<double> form_G;
                    static bdf::types::entry_type<double> form_NU;
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
                    bdf::types::entry_value<double> E;
                    /** Shear modulus. (Real > 0.0 or blank)
                     */
                    bdf::types::entry_value<double> G;
                    /** Poisson’s ratio. (-1.0 < Real < 0.5 or blank)
                     */
                    bdf::types::entry_value<double> NU;
                    /** Thermal expansion coefficient. (Real)
                     */
                    bdf::types::entry_value<double> A;
                    mat1() = default;
                    ~mat1() = default;
                    explicit mat1(const std::list<std::string> &);
                    mat1(long *MID, double *E, double *G, double *NU,
                         double *RHO=nullptr, double *A=nullptr,
                         double *TREF=nullptr, double *GE=nullptr,
                         double *ST=nullptr, double *SC=nullptr,
                         double *SS=nullptr, long *MCSID=nullptr);
                    card const &operator() (
                        long *MID, double *E, double *G, double *NU,
                        double *RHO=nullptr, double *A=nullptr,
                        double *TREF=nullptr, double *GE=nullptr,
                        double *ST=nullptr, double *SC=nullptr,
                        double *SS=nullptr, long *MCSID=nullptr);
                    /**
                     * \brief returns the card type of the current card.
                     * \return Current card type.
                     */
                    types card_type() const override;
                    void read(std::list<std::string> const &) override;
                    card const &operator()(std::list<std::string> const &) override;
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
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
    |       % | 6.5-6 | 6.5-6 |  | -500. | 0.002 | 20.+5 |       |       |    |
    |        | 1003  |       |   |       |       |       |       |       |    |
*/
                class mat2 : public __base::mat {
                    // NASTRAN `BDF` `MAT2` representation.
                    static bdf::types::card head;
                    using __base::card::format_outlist;
                    using __base::mat::form_MID;
                    using __base::mat::form_G;
                    using __base::mat::form_RHO;
                    using __base::mat::form_A;
                    using __base::mat::form_TREF;
                    using __base::mat::form_GE;
                    using __base::mat::form_ST;
                    using __base::mat::form_SC;
                    using __base::mat::form_SS;
                    using __base::mat::form_MCSID;
                    // static bdf::types::entry_type<long> form_MID;
                    // static bdf::types::entry_type<double> form_G;
                    // static bdf::types::entry_type<double> form_RHO;
                    // static bdf::types::entry_type<double> form_A;
                    // static bdf::types::entry_type<double> form_TREF;
                    // static bdf::types::entry_type<double> form_GE;
                    // static bdf::types::entry_type<double> form_ST;
                    // static bdf::types::entry_type<double> form_SC;
                    // static bdf::types::entry_type<double> form_SS;
                    // static bdf::types::entry_type<long> form_MCSID;
                public:
                    /** The material property matrix. (Real)
                     */
                    bdf::types::entry_value<double> G11;
                    bdf::types::entry_value<double> G12;
                    bdf::types::entry_value<double> G13;
                    bdf::types::entry_value<double> G22;
                    bdf::types::entry_value<double> G23;
                    bdf::types::entry_value<double> G33;
                    /** Thermal expansion coefficient vector. (Real)
                     */
                    bdf::types::entry_value<double> A1;
                    bdf::types::entry_value<double> A2;
                    bdf::types::entry_value<double> A3;
                    mat2() = default;
                    ~mat2() = default;
                    explicit mat2(const std::list<std::string> &);
                    mat2(long *MID,
                         double *G11, double *G12, double *G13, double *G22,
                         double *G23, double *G33,
                         double *RHO,
                         double *A1, double *A2, double *A3,
                         double *TREF, double *GE,
                         double *ST=nullptr, double *SC=nullptr,
                         double *SS=nullptr,
                         long *MCSID=nullptr);
                    card const &operator() (
                        long *MID,
                        double *G11, double *G12, double *G13, double *G22,
                        double *G23, double *G33,
                        double *RHO,
                        double *A1, double *A2, double *A3,
                        double *TREF, double *GE,
                        double *ST=nullptr, double *SC=nullptr,
                        double *SS=nullptr,
                        long *MCSID=nullptr);
                    types card_type() const override;
                    void read(std::list<std::string> const &) override;
                    card const &operator()(std::list<std::string> const &) override;
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
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
                    static bdf::types::card head;
                    using __base::card::format_outlist;
                    static bdf::types::entry_type<std::string> form_N;
                    static bdf::types::entry_type<long> form_IVAL;
                    static bdf::types::entry_type<double> form_RVAL;
                    static bdf::types::entry_type<std::string> form_CVAL;
                    static bdf::types::entry_type<std::complex<double> > form_CPLXVAL;
                public:
                    enum class value_type {is_CHAR, is_INT, is_REAL, is_CPLX};
                    value_type ValueType = value_type::is_CHAR;
                    /** Parameter name (one to eight alphanumeric
                        characters, the first of which is alphabetic).
                    */
                    bdf::types::entry_value<std::string> N;
                    /** Parameter value based on parameter type:
                        | `V1` | `V1`  |
                        | long | blank |
                    */
                    bdf::types::entry_value<long> IVAL;
                    /** Parameter value based on parameter type:
                        | `V1`   | `V1`  |
                        | double | blank |
                    */
                    bdf::types::entry_value<double> RVAL;
                    /** Parameter value based on parameter type:
                        | `V1` | `V1`  |
                        | char | blank |
                    */
                    bdf::types::entry_value<std::string> CVAL;
                    /** Parameter value based on parameter type:
                        | `V1`   | `V1`   |
                        | double | double |
                    */
                    bdf::types::entry_value<std::complex<double> > CPLXVAL;
                private:
                    explicit param(std::string const&);
                public:
                    param() = default;
                    ~param() = default;
                    explicit param(std::list<std::string> const&);
                    param(std::string&, long);
                    param(std::string&, double);
                    param(std::string&, std::string&);
                    param(std::string&, std::complex<double>&);
                    param(std::string&, double, double);
                    types card_type() const override;
                    void read(std::list<std::string> const &) override;
                    card const &operator()(std::list<std::string> const &) override;
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
                };
            }
        }
    }
}

// ReSharper disable CppUnusedIncludeDirective
#include "bdf/cards_properties.h"
#include "bdf/cards_elements.h"
#include "bdf/cards_loads.h"
#include "bdf/cards_dummy.h"
// ReSharper restore CppUnusedIncludeDirective

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
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
