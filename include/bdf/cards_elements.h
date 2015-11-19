// Copyright © 2015 by DNV GL SE

/// Definitions for BDF element type cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150714_BDF_CARDS_ELEMENTS
#define _BERHOL20150714_BDF_CARDS_ELEMENTS

#include <memory>

namespace dnvgl {
  namespace extfem {
    namespace bdf {
      namespace cards {

        /// Base class for `ctria3` and `cquad4`.
        class base_shell : public card {

        protected:

          static const ::dnvgl::extfem::bdf::types::entry_type<long> _EID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _PID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G1;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G2;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G3;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G4;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _MCID;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _THETA;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _ZOFFS;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _TFLAG;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _T1;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _T2;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _T3;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _T4;

          DllExport base_shell(const ::std::deque<::std::string> &inp) :
            card(inp) {};

        public:

          typedef enum {has_MCID, has_THETA} CHOOSE_MCID_THETA;

          CHOOSE_MCID_THETA choose_mcid_theta;

          /** Element identification number. (Integer > 0)
           */
          ::std::unique_ptr<long> EID;
          /** Property identification number of a `PSHELL`, `PCOMP` or
              `PLPLANE` entry. (Integer > 0; Default = `EID`)
          */
          ::std::unique_ptr<long> PID;
          /** Grid point identification numbers of first connection
              point. (Integers > 0, all unique)
          */
          ::std::unique_ptr<long> G1;
          /** Grid point identification numbers of second connection
              point. (Integers > 0, all unique)
          */
          ::std::unique_ptr<long> G2;
          /** Grid point identification numbers of third connection
              point. (Integers > 0, all unique)
          */
          ::std::unique_ptr<long> G3;
          /** Grid point identification numbers of fourth connection
              point. (Integers > 0, all unique)
          */
          ::std::unique_ptr<long> G4;
          /** Material property orientation angle in degrees. `THETA`
              is ignored for hyperelastic elements. (Real; Default =
              0.0)
          */
          ::std::unique_ptr<double> THETA;
          /** Material coordinate system identification number. The
              x-axis of the material coordinate system is determined
              by projecting the x-axis of the `MCID` coordinate system
              (defined by the `CORDij` entry or zero for the basic
              coordinate system) onto the surface of the element.
              `MCID` is ignored for hyperelastic elements. (Integer >
              0; if blank, then `THETA` = 0.0 is assumed.)
          */
          ::std::unique_ptr<long> MCID;
          /** Offset from the surface of grid points to the element
              reference plane. `ZOFFS` is ignored for hyperelastic
              elements. (Real)
          */
          ::std::unique_ptr<double> ZOFFS;
          /** An integer flag, signifying the meaning of the `Ti`
              values. (Integer 0, 1, or blank)
          */
          ::std::unique_ptr<long> TFLAG;
          /** Membrane thickness of element at grid point G1. If
              `TFLAG` zero or blank, then `T1` is actual user
              specified thickness. (Real > 0.0 or blank, not all
              zero.) If `TFLAG` one, then the `T1` is fraction
              relative to the `T` value of the `PSHELL`. (Real > 0.0
              or blank; not all zero. Default = 1.0) `T1` is ignored
              for hyperelastic elements.
          */
          ::std::unique_ptr<double> T1;
          /** Membrane thickness of element at grid point G2. If
              `TFLAG` zero or blank, then `T2` is actual user
              specified thickness. (Real > 0.0 or blank, not all
              zero.) If `TFLAG` one, then the `T2` is fraction
              relative to the `T` value of the `PSHELL`. (Real > 0.0
              or blank; not all zero. Default = 1.0) `T2` is ignored
              for hyperelastic elements.
          */
          ::std::unique_ptr<double> T2;
          /** Membrane thickness of element at grid point G3. If
              `TFLAG` zero or blank, then `T3` is actual user
              specified thickness. (Real > 0.0 or blank, not all
              zero.) If `TFLAG` one, then the `T3` is fraction
              relative to the `T` value of the `PSHELL`. (Real > 0.0
              or blank; not all zero. Default = 1.0) `T3` is ignored
              for hyperelastic elements.
          */
          ::std::unique_ptr<double> T3;
          /** Membrane thickness of element at grid point G4. If
              `TFLAG` zero or blank, then `T4` is actual user
              specified thickness. (Real > 0.0 or blank, not all
              zero.) If `TFLAG` one, then the `T4` is fraction
              relative to the `T` value of the `PSHELL`. (Real > 0.0
              or blank; not all zero. Default = 1.0) `T4` is ignored
              for hyperelastic elements.
          */
          ::std::unique_ptr<double> T4;
        };

        /// Handle Nastran Bulk `CTRIA3` entries.
/** # Triangular Plate Element Connection

Defines an isoparametric membrane-bending or plane strain triangular
plate element.

# Format

| 1        | 2     | 3       | 4    | 5    | 6    | 7                 | 8       | 9 | 10 |
| -------- | ----- | ------- | ---- | ---- | ---- | ----------------- | ------- | - | -- |
| `CTRIA3` | `EID` | `PID`   | `G1` | `G2` | `G3` | `THETA` or `MCID` | `ZOFFS` |   |    |
|          |       | `TFLAG` | `T1` | `T2` | `T3` |                   |         |   |    |
*/
        class ctria3 : public base_shell {

        private:

          static ::dnvgl::extfem::bdf::types::card head;

        public:

          DllExport ctria3(const ::std::deque<::std::string> &);

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const { return CTRIA3; };

          DllExport const ::std::ostream& operator << (::std::ostream& os) const;
        };

        /// Handle Nastran Bulk `CQUAD4` entries.
/** # Quadrilateral Plate Element Connection

Defines an isoparametric membrane-bending or plane strain
quadrilateral plate element.

# Format

| 1        | 2       | 3     | 4    | 5    | 6   | 7     | 8                 | 9       | 10 |
| -------- | ------- | ----- | ---- | ---- | ---- | ---- | ----------------- | ------- | -- |
| `CQUAD4` | `EID`   | `PID` | `G1` | `G2` | `G3` | `G4` | `THETA` or `MCID` | `ZOFFS` |    |
|          | `TFLAG` | `T1`  | `T2` | `T3` | `T4` |      |                   |         |    |
*/
        class cquad4 : public base_shell {
          // NASTRAN `BDF` `CQUAD4` representation.

        private:

          static ::dnvgl::extfem::bdf::types::card head;

        public:

          DllExport cquad4(const ::std::deque<::std::string> &);

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const { return CQUAD4; };

          DllExport const ::std::ostream& operator << (::std::ostream& os) const;
        };

        /// Handle Nastran Bulk `CBEAM` entries.
/** # Beam Element Connection

Defines a beam element.

# Format

| 1       | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9             | 10 |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ------------- | -- |
| `CBEAM` | `EID` | `PID` | `GA`  | `GB`  | `X1`  | `X2`  | `X3`  | `OFFT` / `BIT`|    |
|         | `PA`  | `PB`  | `W1A` | `W2A` | `W3A` | `W1B` | `W2B` | `W3B`         |    |
|         | `SA`  | `SB`  |       |       |       |       |       |               |    |

# Alternate Format

| 1       | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9             | 10 |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ------------- | -- |
| `CBEAM` | `EID` | `PID` | `GA`  | `GB`  | `G0`  |       |       | `OFFT` / `BIT`|    |
|         | `PA`  | `PB`  | `W1A` | `W2A` | `W3A` | `W1B` | `W2B` | `W3B`         |    |
|         | `SA`  | `SB`  |       |       |       |       |       |               |    |
*/
        class cbeam : public card {

        private:

          static ::dnvgl::extfem::bdf::types::card head;

          static const ::dnvgl::extfem::bdf::types::entry_type<long> _EID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _PID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _GA;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _GB;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _X1;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G0;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _X2;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _X3;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _BIT;
          static const ::dnvgl::extfem::bdf::types::entry_type<::std::string> _OFFT;
          static const ::dnvgl::extfem::bdf::types::entry_type<::std::deque<int>> _PA;
          static const ::dnvgl::extfem::bdf::types::entry_type<::std::deque<int>> _PB;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W1A;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W2A;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W3A;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W1B;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W2B;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W3B;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _SA;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _SB;

        public:

          DllExport cbeam(const ::std::deque<::std::string> &inp);

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const { return CBEAM; };

          /** Flag to store whether direction node or direction vector
              was set for cross section direction.
           */
          typedef enum {
            /// Element has direction vector entry
            has_DVEC,
            /// Element direction defined by direction code
            has_DCODE} CHOOSE_DIR_CODE;
          CHOOSE_DIR_CODE choose_dir_code;
          /** Flag to store whether 'OFFT' or 'BIT' was set.
           */
          typedef enum {
            /// `OFFT` is set for element
            has_OFFT,
            /// `BIT` is set for element
            has_BIT} CHOOSE_OFFT_BIT;
          CHOOSE_OFFT_BIT choose_offt_bit;

          /** Unique element identification number. (0 < Integer <
              100,000,000)
          */
          ::std::unique_ptr<long> EID;
          /** Property identification number of `PBEAM`, `PBCOMP` or
              `PBEAML` entry. (Integer > 0; Default = `EID`)
          */
          ::std::unique_ptr<long> PID;
          /** First grid point identification numbers of connection
              points. (Integer > 0)
          */
          ::std::unique_ptr<long> GA;
          /** Second grid point identification numbers of connection
              points. (Integer > 0)
          */
          ::std::unique_ptr<long> GB;
          /** First components of orientation vector , from `GA`, in
              the displacement coordinate system at `GA` (default), or
              in the basic coordinate system. (Real)
          */
          ::std::unique_ptr<double> X1;
          /** Alternate method to supply the orientation vector using
              grid point `G0`. Direction of is from `GA` to G0. is
              then transferred to End `A`. (Integer > 0; or `GB`)
          */
          ::std::unique_ptr<long> G0;
          /** Second components of orientation vector , from `GA`, in
              the displacement coordinate system at `GA` (default), or
              in the basic coordinate system. (Real)
          */
          ::std::unique_ptr<double> X2;
          /** Third components of orientation vector , from `GA`, in
              the displacement coordinate system at `GA` (default), or
              in the basic coordinate system. (Real)
          */
          ::std::unique_ptr<double> X3;
          /** Built-in twist of the cross-sectional axes about the
              beam axis at end `B` relative to end `A`. For beam
              p-elements only. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> BIT;
          /** Offset vector interpretation flag. (Character or blank)
           */
          ::std::unique_ptr<::std::string> OFFT;
          /** Pin flags for beam end `A`, respectively; used to remove
              connections between the grid point and selected
              degrees-offreedom of the beam. The degrees-of-freedom
              are defined in the element’s coordinate system and the
              pin flags are applied at the offset ends of the beam.
              The beam must have stiffness associated with the `PA`
              and `PB` degrees-of-freedom to be released by the pin
              flags. For example, if `PA` = 4, the `PBEAM` entry must
              have a nonzero value for `J`, the torsional stiffness.
              (Up to five of the unique Integers 1 through 6 with no
              embedded blanks.) Pin flags are not allowed for beam
              p-elements.
          */
          ::std::unique_ptr<::std::deque<int>> PA;
          /** Pin flags for beam end `B`, respectively; used to remove
              connections between the grid point and selected
              degrees-offreedom of the beam. The degrees-of-freedom
              are defined in the element’s coordinate system and the
              pin flags are applied at the offset ends of the beam.
              The beam must have stiffness associated with the `PA`
              and `PB` degrees-of-freedom to be released by the pin
              flags. For example, if `PA` = 4, the `PBEAM` entry must
              have a nonzero value for `J`, the torsional stiffness.
              (Up to five of the unique Integers 1 through 6 with no
              embedded blanks.) Pin flags are not allowed for beam
              p-elements.
          */
          ::std::unique_ptr<::std::deque<int>> PB;
          /** *x* Components of offset vectors from the grid points to
              the end points of the axis of the shear center at beam
              end `A`. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W1A;
          /** *y* Components of offset vectors from the grid points to
              the end points of the axis of the shear center at beam
              end `A`. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W2A;
          /** *z* Components of offset vectors from the grid points to
              the end points of the axis of the shear center at beam
              end `A`. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W3A;
          /** *x* Components of offset vectors from the grid points to
              the end points of the axis of the shear center at beam
              end `B`. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W1B;
          /** *y* Components of offset vectors from the grid points to
              the end points of the axis of the shear center at beam
              end `B`. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W2B;
          /** *z* Components of offset vectors from the grid points to
              the end points of the axis of the shear center at beam
              end `B`. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W3B;
          /** Scalar or grid point identification numbers for the end
              `A`. The degrees-of-freedom at these points are the
              warping variables . `SA` and `SB` cannot be specified
              for beam p-elements. (Integers > 0 or blank)
          */
          ::std::unique_ptr<long> SA;
          /** Scalar or grid point identification numbers for the end
              `B`. The degrees-of-freedom at these points are the
              warping variables . `SA` and `SB` cannot be specified
              for beam p-elements. (Integers > 0 or blank)
          */
          ::std::unique_ptr<long> SB;

          DllExport const ::std::ostream& operator << (::std::ostream& os) const;
        };

        /// Handle Nastran Bulk `CBAR` entries.
/** # Simple Beam Element Connection

Defines a simple beam element.

# Format

| 1       | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9      | 10 |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ------ | -- |
| `CBAR`  | `EID` | `PID` | `GA`  | `GB`  | `X1`  | `X2`  | `X3`  | `OFFT` |    |
|         | `PA`  | `PB`  | `W1A` | `W2A` | `W3A` | `W1B` | `W2B` | `W3B`  |    |

# Alternate Format

| 1       | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9      | 10 |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ------ | -- |
| `CBAR`  | `EID` | `PID` | `GA`  | `GB`  | `G0`  |       |       | `OFFT` |    |
|         | `PA`  | `PB`  | `W1A` | `W2A` | `W3A` | `W1B` | `W2B` | `W3B`  |    |
*/
        class cbar : public card {

        private:

          static ::dnvgl::extfem::bdf::types::card head;

          static const ::dnvgl::extfem::bdf::types::entry_type<long> _EID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _PID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _GA;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _GB;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _X1;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G0;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _X2;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _X3;
          static const ::dnvgl::extfem::bdf::types::entry_type<::std::string> _OFFT;
          static const ::dnvgl::extfem::bdf::types::entry_type<::std::deque<int>> _PA;
          static const ::dnvgl::extfem::bdf::types::entry_type<::std::deque<int>> _PB;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W1A;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W2A;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W3A;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W1B;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W2B;
          static const ::dnvgl::extfem::bdf::types::entry_type<double> _W3B;

        public:

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const {
            return CBAR;
          };

          /** Flag to store whether direction node or direction vector
              was set for cross section direction.
           */
          typedef enum {
            /// Element has direction vector entry
            has_DVEC,
            /// Element direction defined by direction code
            has_DCODE} CHOOSE_DIR_CODE;
          CHOOSE_DIR_CODE choose_dir_code;

          /** Unique element identification number. (0 < Integer <
              100,000,000)
          */
          ::std::unique_ptr<long> EID;
          /** Property identification number of a `PBAR` or `PBARL`
              entry. (Integer > 0 or blank*; Default = `EID` unless
              `BAROR` entry has nonzero entry in field 3.)
          */
          ::std::unique_ptr<long> PID;
          /** Grid point identification numbers of connection point at
              `A` side of beam. (Integer > 0; `GA` ≠ `GB` )
          */
          ::std::unique_ptr<long> GA;
          /** Grid point identification numbers of connection point at
              `B` side of beam. (Integer > 0; `GA` ≠ `GB` )
          */
          ::std::unique_ptr<long> GB;
          /** *x* components of orientation vector *v* , from `GA`, in
              the displacement coordinate system at `GA` (default), or
              in the basic coordinate system. See Remark 8. (Real)
          */
          ::std::unique_ptr<double> X1;
          /** Alternate method to supply the orientation vector *v*
              using grid point `G0`. The direction of *v* is from `GA`
              to `G0`. 'v* is then translated to End `A`. (Integer >
              0; `G0` ≠ `GA` or `GB`)
          */
          ::std::unique_ptr<long> G0;
          /** *y* components of orientation vector *v* , from `GA`, in
              the displacement coordinate system at `GA` (default), or
              in the basic coordinate system. See Remark 8. (Real)
          */
          ::std::unique_ptr<double> X2;
          /** *z* components of orientation vector *v* , from `GA`, in
              the displacement coordinate system at `GA` (default), or
              in the basic coordinate system. See Remark 8. (Real)
          */
          ::std::unique_ptr<double> X3;
          /** Offset vector interpretation flag. (character or blank)
              See Remark 8.
          */
          ::std::unique_ptr<::std::string> OFFT;
          /** Pin flags for bar ends `A`. Used to remove connections
              between the grid point and selected degrees-of-freedom
              of the bar. The degrees-of-freedom are defined in the
              element’s coordinate system (see Figure 8-8). The bar
              must have stiffness associated with the `PA`
              degrees-of-freedom to be released by the pin flags. For
              example, if `PA` = 4 is specified, the `PBAR` entry must
              have a value for `J`, the torsional stiffness. (Up to 5
              of the unique Integers 1 through 6 anywhere in the field
              with no embedded blanks; Integer > 0.)
          */
          ::std::unique_ptr<::std::deque<int>> PA;
          /** Pin flags for bar ends `B`. Used to remove connections
              between the grid point and selected degrees-of-freedom
              of the bar. The degrees-of-freedom are defined in the
              element’s coordinate system (see Figure 8-8). The bar
              must have stiffness associated with the `PB`
              degrees-of-freedom to be released by the pin flags. For
              example, if `PB` = 4 is specified, the `PBAR` entry must
              have a value for `J`, the torsional stiffness. (Up to 5
              of the unique Integers 1 through 6 anywhere in the field
              with no embedded blanks; Integer > 0.)
          */
          ::std::unique_ptr<::std::deque<int>> PB;
          /** *x* components of offset vectors \f$w_a\f$ and
              \f$w_b\f$, respectively (see Figure 8-8) in displacement
              coordinate systems (or in element system depending upon
              the content of the `OFFT` field), at point `GA`. See
              Remark 7. and 8. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W1A;
          /** *y* components of offset vectors \f$w_a\f$ and
              \f$w_b\f$, respectively (see Figure 8-8) in displacement
              coordinate systems (or in element system depending upon
              the content of the `OFFT` field), at point `GA`. See
              Remark 7. and 8. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W2A;
          /** *z* components of offset vectors \f$w_a\f$ and
              \f$w_b\f$, respectively (see Figure 8-8) in displacement
              coordinate systems (or in element system depending upon
              the content of the `OFFT` field), at point `GA`. See
              Remark 7. and 8. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W3A;
          /** *x* components of offset vectors \f$w_a\f$ and
              \f$w_b\f$, respectively (see Figure 8-8) in displacement
              coordinate systems (or in element system depending upon
              the content of the `OFFT` field), at point `GB`. See
              Remark 7. and 8. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W1B;
          /** *y* components of offset vectors \f$w_a\f$ and
              \f$w_b\f$, respectively (see Figure 8-8) in displacement
              coordinate systems (or in element system depending upon
              the content of the `OFFT` field), at point `GB`. See
              Remark 7. and 8. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W2B;
          /** *z* components of offset vectors \f$w_a\f$ and
              \f$w_b\f$, respectively (see Figure 8-8) in displacement
              coordinate systems (or in element system depending upon
              the content of the `OFFT` field), at point `GB`. See
              Remark 7. and 8. (Real; Default = 0.0)
          */
          ::std::unique_ptr<double> W3B;

          DllExport cbar(const ::std::deque<::std::string> &inp);

          DllExport cbar(
            const long *iEID, const long *iPID,
            const long *iGA, const long *iGB,
            const double *iX1, const double *iX2, const double *iX3,
            const ::std::string *iOFFT = nullptr,
            const ::std::deque<int> *iPA = nullptr, const ::std::deque<int> *iPB = nullptr,
            const double *iW1A = nullptr, const double *iW2A = nullptr,
            const double *iW3A = nullptr, const double *iW1B = nullptr,
            const double *iW2B = nullptr, const double *iW3B = nullptr) {
            choose_dir_code = has_DVEC;
            EID = ::std::make_unique<long>(*iEID);
            PID = ::std::make_unique<long>(*iPID);
            GA = ::std::make_unique<long>(*iGA);
            GB = ::std::make_unique<long>(*iGB);
            X1 = ::std::make_unique<double>(*iX1);
            X2 = ::std::make_unique<double>(*iX2);
            X3 = ::std::make_unique<double>(*iX3);
            OFFT = ::dnvgl::extfem::bdf::types::get_val<::std::string>(iOFFT);
            PA = ::dnvgl::extfem::bdf::types::get_val<::std::deque<int>>(iPA);
            PB = ::dnvgl::extfem::bdf::types::get_val<::std::deque<int>>(iPB);
            W1A = ::dnvgl::extfem::bdf::types::get_val<double>(iW1A);
            W2A = ::dnvgl::extfem::bdf::types::get_val<double>(iW2A);
            W3A = ::dnvgl::extfem::bdf::types::get_val<double>(iW3A);
            W1B = ::dnvgl::extfem::bdf::types::get_val<double>(iW1B);
            W2B = ::dnvgl::extfem::bdf::types::get_val<double>(iW2B);
            W3B = ::dnvgl::extfem::bdf::types::get_val<double>(iW3B);
          };

          DllExport cbar(
            const long *iEID, const long *iPID,
            const long *iGA, const long *iGB, const long *iG0,
            const ::std::string *iOFFT = nullptr,
            const ::std::deque<int> *iPA = nullptr, const ::std::deque<int> *iPB = nullptr,
            const double *iW1A = nullptr, const double *iW2A = nullptr,
            const double *iW3A = nullptr, const double *iW1B = nullptr,
            const double *iW2B = nullptr, const double *iW3B = nullptr) {
            choose_dir_code = has_DCODE;
            EID = ::std::make_unique<long>(*iEID);
            PID = ::std::make_unique<long>(*iPID);
            GA = ::std::make_unique<long>(*iGA);
            GB = ::std::make_unique<long>(*iGB);
            G0 = ::std::make_unique<long>(*iG0);
            OFFT = ::dnvgl::extfem::bdf::types::get_val<::std::string>(iOFFT);
            PA = ::dnvgl::extfem::bdf::types::get_val<::std::deque<int>>(iPA);
            PB = ::dnvgl::extfem::bdf::types::get_val<::std::deque<int>>(iPB);
            W1A = ::dnvgl::extfem::bdf::types::get_val<double>(iW1A);
            W2A = ::dnvgl::extfem::bdf::types::get_val<double>(iW2A);
            W3A = ::dnvgl::extfem::bdf::types::get_val<double>(iW3A);
            W1B = ::dnvgl::extfem::bdf::types::get_val<double>(iW1B);
            W2B = ::dnvgl::extfem::bdf::types::get_val<double>(iW2B);
            W3B = ::dnvgl::extfem::bdf::types::get_val<double>(iW3B);
          };

          DllExport friend ::std::ostream& operator<<(::std::ostream&, const cbar&);
          DllExport const ::std::ostream& operator<<(::std::ostream& os) const;
        };

        /// Handle Nastran Bulk `CROD` entries.
/** # Rod Element Connection

Defines a tension-compression-torsion element.

# Format

| 1       | 2     | 3     | 4    | 5    | 6 | 7 | 8 | 9 | 10 |
| ------- | ----- | ----- | ---- | ---- | - | - | - | - | -- |
| `CROD`  | `EID` | `PID` | `G1` | `G2` |   |   |   |   |    |
*/
        class crod : public card {

        private:

          static ::dnvgl::extfem::bdf::types::card head;

          static const ::dnvgl::extfem::bdf::types::entry_type<long> _EID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _PID;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G1;
          static const ::dnvgl::extfem::bdf::types::entry_type<long> _G2;

        public:

          DllExport crod(const ::std::deque<::std::string> &inp);

          DllExport const ::dnvgl::extfem::bdf::cards::types card_type(void) const { return CROD; };

          /** Element identification number. (Integer > 0)
           */
          ::std::unique_ptr<long> EID;
          /** Property identification number of a `PROD` entry. (Integer >
              0; Default = `EID`)
          */
          ::std::unique_ptr<long> PID;
          /** Grid point identification number of first connection
              point. (Integer > 0; `G1` ≠ `G2`)
          */
          ::std::unique_ptr<long> G1;
          /** Grid point identification number of second connection
              point. (Integer > 0; `G1` ≠ `G2`)
          */
          ::std::unique_ptr<long> G2;

          DllExport const ::std::ostream& operator << (::std::ostream& os) const;
        };
      }
    }
  }
}

#endif // _BERHOL20150714_BDF_CARDS_ELEMENTS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
