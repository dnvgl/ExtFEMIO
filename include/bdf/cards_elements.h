/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for BDF element type cards.

   Detailed description
*/

// ID: $Id$

#if !defined _BDF_CARDS_ELEMENTS_H_
#define _BDF_CARDS_ELEMENTS_H_

#include <memory>

#if !defined(_BDF_CARDS_H_)
#error include "bdf/cards.h" instead
#endif


namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace cards {
                namespace __base {

                    /// Base class for elements.
                    class element : public __base::card {
                    protected:
                        bdf::types::entry_type<long> static form_EID;
                    public:
                        /** Element identification number. (Integer > 0)
                         */
                        bdf::types::entry_value<long> EID;
                        explicit element(std::list<std::string> const&);
                        ~element() = default;
                        void static reset();
                    protected:
                        element() = default;
                        explicit element(long const *EID);
                        virtual card const &operator() (long const *EID);
                        card const &operator() (
                            const std::list<std::string>&) override;
                        void read(std::list<std::string> const&) override;
                        void check_data() override;
                        types card_type() const override;
                        void collect_outdata(
                            std::list<std::unique_ptr<format_entry>>&) const override;
                    };

                    /// Base class for `ctria3` and `cquad4`.
                    class shell : public __base::element {
                    protected:
                        // bdf::types::entry_type<long> static form_EID;
                        bdf::types::entry_type<long> static form_PID;
                        bdf::types::entry_type<long> static form_G1;
                        bdf::types::entry_type<long> static form_G2;
                        bdf::types::entry_type<long> static form_G3;
                        bdf::types::entry_type<long> static form_G4;
                        bdf::types::entry_type<long> static form_MCID;
                        bdf::types::entry_type<double> static form_THETA;
                        bdf::types::entry_type<double> static form_ZOFFS;
                        bdf::types::entry_type<long> static form_TFLAG;
                        bdf::types::entry_type<double> static form_T1;
                        bdf::types::entry_type<double> static form_T2;
                        bdf::types::entry_type<double> static form_T3;
                        bdf::types::entry_type<double> static form_T4;
                        explicit shell(std::list<std::string> const &);
                        explicit shell(long *);
                        void check_data() override;
                    public:
                        enum class CHOOSE_MCID_THETA {
                            has_MCID, has_THETA, UNDEF
                        };
                        CHOOSE_MCID_THETA choose_mcid_theta;
                        // /** Element identification number. (Integer > 0)
                        //  */
                        // bdf::types::entry_value<long> EID;
                        /** Property identification number of a `PSHELL`,
                            `PCOMP` or `PLPLANE` entry. (Integer > 0; Default =
                            `EID`)
                            */
                        bdf::types::entry_value<long> PID;
                        /** Grid point identification numbers of first
                            connection point. (Integers > 0, all unique)
                            */
                        bdf::types::entry_value<long> G1;
                        /** Grid point identification numbers of second
                            connection point. (Integers > 0, all unique)
                            */
                        bdf::types::entry_value<long> G2;
                        /** Grid point identification numbers of third
                            connection point. (Integers > 0, all unique)
                            */
                        bdf::types::entry_value<long> G3;
                        /** Grid point identification numbers of fourth
                            connection point. (Integers > 0, all unique)
                            */
                        bdf::types::entry_value<long> G4;
                        /** Material property orientation angle in degrees.
                            `THETA` is ignored for hyperelastic elements.
                            (Real; Default = 0.0)
                            */
                        bdf::types::entry_value<double> THETA;
                        /** Material coordinate system identification number.
                            The x-axis of the material coordinate system is
                            determined by projecting the x-axis of the `MCID`
                            coordinate system (defined by the `CORDij` entry or
                            zero for the basic coordinate system) onto the
                            surface of the element. `MCID` is ignored for
                            hyperelastic elements. (Integer > 0; if blank, then
                            `THETA` = 0.0 is assumed.)
                            */
                        bdf::types::entry_value<long> MCID;
                        /** Offset from the surface of grid points to the
                            element reference plane. `ZOFFS` is ignored for
                            hyperelastic elements. (Real)
                            */
                        bdf::types::entry_value<double> ZOFFS;
                        /** An integer flag, signifying the meaning of the `Ti`
                            values. (Integer 0, 1, or blank)
                            */
                        bdf::types::entry_value<long> TFLAG;
                        /** Membrane thickness of element at grid point G1. If
                            `TFLAG` zero or blank, then `T1` is actual user
                            specified thickness. (Real > 0.0 or blank, not all
                            zero.) If `TFLAG` one, then the `T1` is fraction
                            relative to the `T` value of the `PSHELL`. (Real >
                            0.0 or blank; not all zero. Default = 1.0) `T1` is
                            ignored for hyperelastic elements.
                            */
                        bdf::types::entry_value<double> T1;
                        /** Membrane thickness of element at grid point G2. If
                            `TFLAG` zero or blank, then `T2` is actual user
                            specified thickness. (Real > 0.0 or blank, not all
                            zero.) If `TFLAG` one, then the `T2` is fraction
                            relative to the `T` value of the `PSHELL`. (Real >
                            0.0 or blank; not all zero. Default = 1.0) `T2` is
                            ignored for hyperelastic elements.
                            */
                        bdf::types::entry_value<double> T2;
                        /** Membrane thickness of element at grid point G3. If
                            `TFLAG` zero or blank, then `T3` is actual user
                            specified thickness. (Real > 0.0 or blank, not all
                            zero.) If `TFLAG` one, then the `T3` is fraction
                            relative to the `T` value of the `PSHELL`. (Real >
                            0.0 or blank; not all zero. Default = 1.0) `T3` is
                            ignored for hyperelastic elements.
                            */
                        bdf::types::entry_value<double> T3;
                        /** Membrane thickness of element at grid point G4. If
                            `TFLAG` zero or blank, then `T4` is actual user
                            specified thickness. (Real > 0.0 or blank, not all
                            zero.) If `TFLAG` one, then the `T4` is fraction
                            relative to the `T` value of the `PSHELL`. (Real >
                            0.0 or blank; not all zero. Default = 1.0) `T4` is
                            ignored for hyperelastic elements.
                            */
                        bdf::types::entry_value<double> T4;
                    protected:
                        shell() = default;
                    public:
                        ~shell() = default;
                    protected:
                        shell(long *EID, long *PID,
                              long *G1, long *G2, long *G3, long *G4,
                              double *THETA, double *ZOFFS, long *TFLAG,
                              double *T1, double *T2, double *T3, double *T4);
                        shell(long *EID, long *PID,
                              long *G1, long *G2, long *G3, long *G4,
                              long *MCID, double *ZOFFS, long *TFLAG,
                              double *T1, double *T2, double *T3, double *T4);
                        virtual card const &operator() (
                            long const *EID, long const *PID,
                            long const *G1, long const *G2,
                            long const *G3, long const *G4,
                            double const *THETA,
                            double const *ZOFFS,
                            long const *TFLAG,
                            double const *T1, double const *T2,
                            double const *T3, double const *T4);
                        virtual card const &operator() (
                            long const *EID, long const *PID,
                            long const *G1, long const *G2,
                            long const *G3, long const *G4,
                            long const *MCID,
                            double const *ZOFFS, const long *TFLAG,
                            double const *T1, double const *T2,
                            double const *T3, double const *T4);
                        using element::put;
                        using element::read;
                    };
                }
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
                class ctria3 : public __base::shell {
                    static bdf::types::card head;
                    using __base::element::form_EID;
                    using __base::shell::form_PID;
                    using __base::shell::form_G1;
                    using __base::shell::form_G2;
                    using __base::shell::form_G3;
                    using __base::shell::form_G4;
                    using __base::shell::form_MCID;
                    using __base::shell::form_THETA;
                    using __base::shell::form_ZOFFS;
                    using __base::shell::form_TFLAG;
                    using __base::shell::form_T1;
                    using __base::shell::form_T2;
                    using __base::shell::form_T3;
                    using __base::shell::form_T4;
                    using __base::card::format_outlist;
                public:
                    ctria3() = default;
                    ~ctria3() = default;
                    explicit ctria3(std::list<std::string> const&);
                    ctria3(long *EID, long *PID, long *G1, long *G2, long *G3,
                           double *THETA=nullptr, double *ZOFFS=nullptr,
                           long *TFLAG=nullptr,
                           double *T1=nullptr, double *T2=nullptr,
                           double *T3=nullptr);
                    ctria3(long *EID, long *PID, long *G1, long *G2, long *G3,
                           long *MCID, double *ZOFFS=nullptr,
                           long *TFLAG=nullptr,
                           double *T1=nullptr, double *T2=nullptr,
                           double *T3=nullptr);
                    void read(std::list<std::string> const&) override;
                    card const &operator() (const std::list<std::string> &) override;
                    types card_type() const override;
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *G1, long const *G2, long const *G3,
                        double const *THETA=nullptr,
                        double const *ZOFFS=nullptr,
                        long const *TFLAG=nullptr,
                        double const *T1=nullptr, double const *T2=nullptr,
                        double const *T3=nullptr);
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *G1, long const *G2, long const *G3,
                        long const *MCID,
                        double const *ZOFFS=nullptr,
                        long const *TFLAG=nullptr,
                        double const *T1=nullptr, double const *T2=nullptr,
                        double const *T3=nullptr);
                private:
                    using shell::put;
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
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
                class cquad4 : public __base::shell {
                    static bdf::types::card head;
                    using __base::element::form_EID;
                    using __base::shell::form_PID;
                    using __base::shell::form_G1;
                    using __base::shell::form_G2;
                    using __base::shell::form_G3;
                    using __base::shell::form_G4;
                    using __base::shell::form_MCID;
                    using __base::shell::form_THETA;
                    using __base::shell::form_ZOFFS;
                    using __base::shell::form_TFLAG;
                    using __base::shell::form_T1;
                    using __base::shell::form_T2;
                    using __base::shell::form_T3;
                    using __base::shell::form_T4;
                    using __base::card::format_outlist;
                public:
                    cquad4() = default;
                    ~cquad4() = default;
                    explicit cquad4(std::list<std::string> const&);
                    cquad4(long *EID, long *PID,
                           long *G1, long *G2, long *G3, long *G4,
                           double *THETA=nullptr, double *ZOFFS=nullptr,
                           long *TFLAG=nullptr,
                           double *T1=nullptr, double *T2=nullptr,
                           double *T3=nullptr, double *T4=nullptr);
                    cquad4(long *EID, long *PID,
                           long *G1, long *G2, long *G3, long *G4,
                           long *MCID,
                           double *ZOFFS=nullptr,
                           long *TFLAG=nullptr,
                           double *T1=nullptr, double *T2=nullptr,
                           double *T3=nullptr, double *T4=nullptr);
                    void read(std::list<std::string> const&) override;
                    card const &operator() (const std::list<std::string> &) override;
                    types card_type() const override;
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *G1, long const *G2,
                        long const *G3, long const *G4,
                        double const *THETA=nullptr,
                        double const *ZOFFS=nullptr,
                        long const *TFLAG=nullptr,
                        double const *T1=nullptr, double const *T2=nullptr,
                        double const *T3=nullptr, double const *T4=nullptr) override;
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *G1, long const *G2,
                        long const *G3, long const *G4,
                        long const *MCID,
                        double const *ZOFFS=nullptr,
                        long const *TFLAG=nullptr,
                        double const *T1=nullptr, double const *T2=nullptr,
                        double const *T3=nullptr, double const *T4=nullptr) override;
                private:
                    using shell::put;
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
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
                class cbeam : public __base::element {
                    static bdf::types::card head;
                    using __base::element::form_EID;
                    using __base::card::format_outlist;
                    // bdf::types::entry_type<long> static form_EID;
                    bdf::types::entry_type<long> static form_PID;
                    bdf::types::entry_type<long> static form_GA;
                    bdf::types::entry_type<long> static form_GB;
                    bdf::types::entry_type<double> static form_X1;
                    bdf::types::entry_type<long> static form_G0;
                    bdf::types::entry_type<double> static form_X2;
                    bdf::types::entry_type<double> static form_X3;
                    bdf::types::entry_type<double> static form_BIT;
                    bdf::types::entry_type<std::string> static form_OFFT;
                    bdf::types::entry_type<std::vector<int> > static form_PA;
                    bdf::types::entry_type<std::vector<int> > static form_PB;
                    bdf::types::entry_type<double> static form_W1A;
                    bdf::types::entry_type<double> static form_W2A;
                    bdf::types::entry_type<double> static form_W3A;
                    bdf::types::entry_type<double> static form_W1B;
                    bdf::types::entry_type<double> static form_W2B;
                    bdf::types::entry_type<double> static form_W3B;
                    bdf::types::entry_type<long> static form_SA;
                    bdf::types::entry_type<long> static form_SB;
                public:
                    /** Flag to store whether direction node or direction
                        vector was std::set for cross section direction.
                        */
                    enum class CHOOSE_DIR_CODE {
                        UNDEF,
                        /// Element has direction vector entry
                        has_DVEC,
                        /// Element direction defined by direction code
                        has_DCODE
                    };
                    CHOOSE_DIR_CODE choose_dir_code;
                    /** Flag to store whether 'OFFT' or 'BIT' was std::set.
                     */
                    enum class CHOOSE_OFFT_BIT {
                        UNDEF,
                        /// `OFFT` is std::set for element
                        has_OFFT,
                        /// `BIT` is std::set for element
                        has_BIT
                    };
                    CHOOSE_OFFT_BIT choose_offt_bit;

                    // /** Unique element identification number. (0 <
                    //     Integer < 100,000,000)
                    // */
                    // bdf::types::entry_value<long> EID;
                    using __base::element::EID;
                    /** Property identification number of `PBEAM`, `PBCOMP`
                        or `PBEAML` entry. (Integer > 0; Default = `EID`)
                        */
                    bdf::types::entry_value<long> PID;
                    /** First grid point identification numbers of
                        connection points. (Integer > 0)
                        */
                    bdf::types::entry_value<long> GA;
                    /** Second grid point identification numbers of
                        connection points. (Integer > 0)
                        */
                    bdf::types::entry_value<long> GB;
                    /** First components of orientation vector , from `GA`,
                        in the displacement coordinate system at `GA`
                        (default), or in the basic coordinate system.
                        (Real)
                        */
                    bdf::types::entry_value<double> X1;
                    /** Alternate method to supply the orientation vector
                        using grid point `G0`. Direction of is from `GA` to
                        G0. is then transferred to End `A`. (Integer > 0;
                        or `GB`)
                        */
                    bdf::types::entry_value<long> G0;
                    /** Second components of orientation vector , from
                        `GA`, in the displacement coordinate system at `GA`
                        (default), or in the basic coordinate system.
                        (Real)
                        */
                    bdf::types::entry_value<double> X2;
                    /** Third components of orientation vector , from `GA`,
                        in the displacement coordinate system at `GA`
                        (default), or in the basic coordinate system.
                        (Real)
                        */
                    bdf::types::entry_value<double> X3;
                    /** Built-in twist of the cross-sectional axes about
                        the beam axis at end `B` relative to end `A`. For
                        beam p-elements only. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> BIT;
                    /** Offset vector interpretation flag. (Character or
                        blank)
                        */
                    bdf::types::entry_value<std::string> OFFT;
                    /** Pin flags for beam end `A`, respectively; used to
                        remove connections between the grid point and
                        selected degrees-offreedom of the beam. The
                        degrees-of-freedom are defined in the element’s
                        coordinate system and the pin flags are applied at
                        the offset ends of the beam. The beam must have
                        stiffness associated with the `PA` and `PB`
                        degrees-of-freedom to be released by the pin flags.
                        For example, if `PA` = 4, the `PBEAM` entry must
                        have a nonzero value for `J`, the torsional
                        stiffness. (Up to five of the unique Integers 1
                        through 6 with no embedded blanks.) Pin flags are
                        not allowed for beam p-elements.
                        */
                    bdf::types::entry_value<std::vector<int> > PA;
                    /** Pin flags for beam end `B`, respectively; used to
                        remove connections between the grid point and
                        selected degrees-offreedom of the beam. The
                        degrees-of-freedom are defined in the element’s
                        coordinate system and the pin flags are applied at
                        the offset ends of the beam. The beam must have
                        stiffness associated with the `PA` and `PB`
                        degrees-of-freedom to be released by the pin flags.
                        For example, if `PA` = 4, the `PBEAM` entry must
                        have a nonzero value for `J`, the torsional
                        stiffness. (Up to five of the unique Integers 1
                        through 6 with no embedded blanks.) Pin flags are
                        not allowed for beam p-elements.
                        */
                    bdf::types::entry_value<std::vector<int> > PB;
                    /** *x* Components of offset vectors from the grid
                        points to the end points of the axis of the shear
                        center at beam end `A`. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> W1A;
                    /** *y* Components of offset vectors from the grid
                        points to the end points of the axis of the shear
                        center at beam end `A`. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> W2A;
                    /** *z* Components of offset vectors from the grid
                        points to the end points of the axis of the shear
                        center at beam end `A`. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> W3A;
                    /** *x* Components of offset vectors from the grid
                        points to the end points of the axis of the shear
                        center at beam end `B`. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> W1B;
                    /** *y* Components of offset vectors from the grid
                        points to the end points of the axis of the shear
                        center at beam end `B`. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> W2B;
                    /** *z* Components of offset vectors from the grid
                        points to the end points of the axis of the shear
                        center at beam end `B`. (Real; Default = 0.0)
                        */
                    bdf::types::entry_value<double> W3B;
                    /** Scalar or grid point identification numbers for the
                        end `A`. The degrees-of-freedom at these points are
                        the warping variables . `SA` and `SB` cannot be
                        specified for beam p-elements. (Integers > 0 or
                        blank)
                        */
                    bdf::types::entry_value<long> SA;
                    /** Scalar or grid point identification numbers for the
                        end `B`. The degrees-of-freedom at these points are
                        the warping variables . `SA` and `SB` cannot be
                        specified for beam p-elements. (Integers > 0 or
                        blank)
                        */
                    bdf::types::entry_value<long> SB;
                    cbeam() = default;
                    ~cbeam() = default;
                    explicit cbeam(std::list<std::string> const &inp);
                    cbeam(long *EID, long *PID, long *GA, long *GB,
                          double *X1, double *X2, double *X3,
                          std::string *OFFT=nullptr,
                          std::vector<int> *PA=nullptr,
                          std::vector<int> *PB=nullptr,
                          double *W1A=nullptr, double *W2A=nullptr,
                          double *W3A=nullptr, double *W1B=nullptr,
                          double *W2B=nullptr, double *W3B=nullptr,
                          long *SA=nullptr, long *SB=nullptr);
                    cbeam(long *EID, long *PID, long *GA, long *GB,
                          double *X1, double *X2, double *X3,
                          double *BIT,
                          std::vector<int> *PA=nullptr,
                          std::vector<int> *PB=nullptr,
                          double *W1A=nullptr, double *W2A=nullptr,
                          double *W3A=nullptr, double *W1B=nullptr,
                          double *W2B=nullptr, double *W3B=nullptr,
                          long *SA=nullptr, long *SB=nullptr);
                    cbeam(long *EID, long *PID, long *GA, long *GB, long *G0,
                          std::string *OFFT=nullptr,
                          std::vector<int>  *PA=nullptr,
                          std::vector<int> *PB=nullptr,
                          double *W1A=nullptr, double *W2A=nullptr,
                          double *W3A=nullptr, double *W1B=nullptr,
                          double *W2B=nullptr, double *W3B=nullptr,
                          long *SA=nullptr, long *SB=nullptr);
                    cbeam(long *EID, long *PID, long *GA, long *GB, long *G0,
                          double *BIT,
                          std::vector<int> *PA=nullptr,
                          std::vector<int> *PB=nullptr,
                          double *W1A=nullptr, double *W2A=nullptr,
                          double *W3A=nullptr, double *W1B=nullptr,
                          double *W2B=nullptr, double *W3B=nullptr,
                          long *SA=nullptr, long *SB=nullptr);
                    types card_type() const override;
                    void read(std::list<std::string> const&) override;
                    card const &operator() (const std::list<std::string> &) override;
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *GA, long const *GB,
                        double const *X1,
                        double const *X2,
                        double const *X3,
                        std::string const *OFFT=nullptr,
                        std::vector<int> const *PA=nullptr,
                        std::vector<int> const *PB=nullptr,
                        double const *W1A=nullptr, double const *W2A=nullptr,
                        double const *W3A=nullptr, double const *W1B=nullptr,
                        double const *W2B=nullptr, double const *W3B=nullptr,
                        long const *SA=nullptr, long const *SB=nullptr);
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *GA, long const *GB,
                        double const *X1,
                        double const *X2,
                        double const *X3,
                        double const *BIT,
                        std::vector<int> const *PA=nullptr,
                        std::vector<int> const *PB=nullptr,
                        double const *W1A=nullptr, double const *W2A=nullptr,
                        double const *W3A=nullptr, double const *W1B=nullptr,
                        double const *W2B=nullptr, double const *W3B=nullptr,
                        long const *SA=nullptr, long const *SB=nullptr);
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *GA, long const *GB,
                        long const *G0,
                        std::string const *OFFT=nullptr,
                        std::vector<int> const *PA=nullptr,
                        std::vector<int> const *PB=nullptr,
                        double const *W1A=nullptr, double const *W2A=nullptr,
                        double const *W3A=nullptr, double const *W1B=nullptr,
                        double const *W2B=nullptr, double const *W3B=nullptr,
                        long const *SA=nullptr, long const *SB=nullptr);
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *GA, long const *GB,
                        long const *G0,
                        double const *BIT,
                        std::vector<int> const *PA=nullptr,
                        std::vector<int> const *PB=nullptr,
                        double const *W1A=nullptr, double const *W2A=nullptr,
                        double const *W3A=nullptr, double const *W1B=nullptr,
                        double const *W2B=nullptr, double const *W3B=nullptr,
                        long const *SA=nullptr, long const *SB=nullptr);
                private:
                    using card::put;
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
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
                class cbar : public __base::element {
                    static bdf::types::card head;
                    using __base::element::form_EID;
                    using __base::card::format_outlist;
                    // bdf::types::entry_type<long> static form_EID;
                    bdf::types::entry_type<long> static form_PID;
                    bdf::types::entry_type<long> static form_GA;
                    bdf::types::entry_type<long> static form_GB;
                    bdf::types::entry_type<double> static form_X1;
                    bdf::types::entry_type<long> static form_G0;
                    bdf::types::entry_type<double> static form_X2;
                    bdf::types::entry_type<double> static form_X3;
                    bdf::types::entry_type<std::string> static form_OFFT;
                    bdf::types::entry_type<std::vector<int> > static form_PA;
                    bdf::types::entry_type<std::vector<int> > static form_PB;
                    bdf::types::entry_type<double> static form_W1A;
                    bdf::types::entry_type<double> static form_W2A;
                    bdf::types::entry_type<double> static form_W3A;
                    bdf::types::entry_type<double> static form_W1B;
                    bdf::types::entry_type<double> static form_W2B;
                    bdf::types::entry_type<double> static form_W3B;
                public:
                    types card_type() const override;
                    /** Flag to store whether direction node or direction
                        vector was std::set for cross section direction.
                        */
                    enum class CHOOSE_DIR_CODE {
                        UNDEF,
                        has_DVEC, //!< Element has direction vector entry
                        has_DCODE //!< Element direction defined by direction code
                    };
                    CHOOSE_DIR_CODE choose_dir_code;
                    // /** Unique element identification number. (0 <
                    //     Integer < 100,000,000)
                    // */
                    // bdf::types::entry_value<long> EID;
                    /** Property identification number of a `PBAR` or
                        `PBARL` entry. (Integer > 0 or blank*; Default =
                        `EID` unless `BAROR` entry has nonzero entry in
                        field 3.)
                        */
                    bdf::types::entry_value<long> PID;
                    /** Grid point identification numbers of connection
                        point at `A` side of beam. (Integer > 0; `GA` ≠
                        `GB` )
                        */
                    bdf::types::entry_value<long> GA;
                    /** Grid point identification numbers of connection
                        point at `B` side of beam. (Integer > 0; `GA` ≠
                        `GB` )
                        */
                    bdf::types::entry_value<long> GB;
                    /** *x* components of orientation vector *v* , from
                        `GA`, in the displacement coordinate system at `GA`
                        (default), or in the basic coordinate system. See
                        Remark 8. (Real)
                        */
                    bdf::types::entry_value<double> X1;
                    /** Alternate method to supply the orientation
                        vector *v* using grid point `G0`. The direction of
                        *v* is from `GA` to `G0`. 'v* is then translated to
                        End `A`. (Integer > 0; `G0` ≠ `GA` or `GB`)
                        */
                    bdf::types::entry_value<long> G0;
                    /** *y* components of orientation vector *v* , from
                        `GA`, in the displacement coordinate system at `GA`
                        (default), or in the basic coordinate system. See
                        Remark 8. (Real)
                        */
                    bdf::types::entry_value<double> X2;
                    /** *z* components of orientation vector *v* , from
                        `GA`, in the displacement coordinate system at `GA`
                        (default), or in the basic coordinate system. See
                        Remark 8. (Real)
                        */
                    bdf::types::entry_value<double> X3;
                    /** Offset vector interpretation flag. (character or
                        blank) See Remark 8.
                        */
                    bdf::types::entry_value<std::string> OFFT;
                    /** Pin flags for bar ends `A`. Used to remove
                        connections between the grid point and selected
                        degrees-of-freedom of the bar. The
                        degrees-of-freedom are defined in the element’s
                        coordinate system (see Figure 8-8). The bar must
                        have stiffness associated with the `PA`
                        degrees-of-freedom to be released by the pin flags.
                        For example, if `PA` = 4 is specified, the `PBAR`
                        entry must have a value for `J`, the torsional
                        stiffness. (Up to 5 of the unique Integers 1
                        through 6 anywhere in the field with no embedded
                        blanks; Integer > 0.)
                        */
                    bdf::types::entry_value<std::vector<int> > PA;
                    /** Pin flags for bar ends `B`. Used to remove
                        connections between the grid point and selected
                        degrees-of-freedom of the bar. The
                        degrees-of-freedom are defined in the element’s
                        coordinate system (see Figure 8-8). The bar must
                        have stiffness associated with the `PB`
                        degrees-of-freedom to be released by the pin flags.
                        For example, if `PB` = 4 is specified, the `PBAR`
                        entry must have a value for `J`, the torsional
                        stiffness. (Up to 5 of the unique Integers 1
                        through 6 anywhere in the field with no embedded
                        blanks; Integer > 0.)
                        */
                    bdf::types::entry_value<std::vector<int> > PB;
                    /** *x* components of offset vectors \f$w_a\f$ and
                        \f$w_b\f$, respectively (see Figure 8-8) in
                        displacement coordinate systems (or in element
                        system depending upon the content of the `OFFT`
                        field), at point `GA`. See Remark 7. and 8. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> W1A;
                    /** *y* components of offset vectors \f$w_a\f$ and
                        \f$w_b\f$, respectively (see Figure 8-8) in
                        displacement coordinate systems (or in element
                        system depending upon the content of the `OFFT`
                        field), at point `GA`. See Remark 7. and 8. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> W2A;
                    /** *z* components of offset vectors \f$w_a\f$ and
                        \f$w_b\f$, respectively (see Figure 8-8) in
                        displacement coordinate systems (or in element
                        system depending upon the content of the `OFFT`
                        field), at point `GA`. See Remark 7. and 8. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> W3A;
                    /** *x* components of offset vectors \f$w_a\f$ and
                        \f$w_b\f$, respectively (see Figure 8-8) in
                        displacement coordinate systems (or in element
                        system depending upon the content of the `OFFT`
                        field), at point `GB`. See Remark 7. and 8. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> W1B;
                    /** *y* components of offset vectors \f$w_a\f$ and
                        \f$w_b\f$, respectively (see Figure 8-8) in
                        displacement coordinate systems (or in element
                        system depending upon the content of the `OFFT`
                        field), at point `GB`. See Remark 7. and 8. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> W2B;
                    /** *z* components of offset vectors \f$w_a\f$ and
                        \f$w_b\f$, respectively (see Figure 8-8) in
                        displacement coordinate systems (or in element
                        system depending upon the content of the `OFFT`
                        field), at point `GB`. See Remark 7. and 8. (Real;
                        Default = 0.0)
                        */
                    bdf::types::entry_value<double> W3B;
                    cbar() = default;
                    ~cbar() = default;
                    explicit cbar(std::list<std::string> const &inp);
                    cbar(long *EID, long *PID, long *GA, long *GB,
                         double *X1, double *X2, double *X3,
                         std::string *OFFT=nullptr,
                         std::vector<int> *PA=nullptr,
                         std::vector<int> *PB=nullptr,
                         double *W1A=nullptr, double *W2A=nullptr,
                         double *W3A=nullptr, double *W1B=nullptr,
                         double *W2B=nullptr, double *W3B=nullptr);
                    cbar(long *EID, long *PID,
                         long *GA, long *GB, long *G0,
                         std::string *OFFT=nullptr,
                         std::vector<int> *PA=nullptr,
                         std::vector<int> *PB=nullptr,
                         double *W1A=nullptr, double *W2A=nullptr,
                         double *W3A=nullptr, double *W1B=nullptr,
                         double *W2B=nullptr, double *W3B=nullptr);
                    void read(std::list<std::string> const &) override;
                    card const &operator() (const std::list<std::string> &) override;
                    /**
                     * \brief Returns instance with new values.
                     * \param EID
                     * \param PID
                     * \param GA
                     * \param GB
                     * \param G0
                     * \param OFFT
                     * \param PA
                     * \param PB
                     * \param W1A
                     * \param W2A
                     * \param W3A
                     * \param W1B
                     * \param W2B
                     * \param W3B
                     * \return
                     */
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *GA, long const *GB,
                        long const *G0,
                        std::string const *OFFT=nullptr,
                        std::vector<int> const *PA=nullptr,
                        std::vector<int> const *PB=nullptr,
                        double const *W1A=nullptr, double const *W2A=nullptr,
                        double const *W3A=nullptr, double const *W1B=nullptr,
                        double const *W2B=nullptr, double const *W3B=nullptr);
                    /**
                     * \brief Returns instance with new values.
                     * \param EID
                     * \param PID
                     * \param GA
                     * \param GB
                     * \param X1
                     * \param X2
                     * \param X3
                     * \param OFFT
                     * \param PA
                     * \param PB
                     * \param W1A
                     * \param W2A
                     * \param W3A
                     * \param W1B
                     * \param W2B
                     * \param W3B
                     * \return
                     */
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *GA, long const *GB,
                        double const *X1, double const *X2, double const *X3,
                        std::string const *OFFT=nullptr,
                        std::vector<int> const *PA=nullptr,
                        std::vector<int> const *PB=nullptr,
                        double const *W1A=nullptr, double const *W2A=nullptr,
                        double const *W3A=nullptr, double const *W1B=nullptr,
                        double const *W2B=nullptr, double const *W3B=nullptr);
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry> >&) const override;
                    void check_data() override;
                };

                /// Handle Nastran Bulk `CROD` entries.
                /** # Rod Element Connection

                    Defines a tension-compression-torsion element.

                    # Format

                    | 1       | 2     | 3     | 4    | 5    | 6 | 7 | 8 | 9 | 10 |
                    | ------- | ----- | ----- | ---- | ---- | - | - | - | - | -- |
                    | `CROD`  | `EID` | `PID` | `G1` | `G2` |   |   |   |   |    |
                    */
                class crod : public __base::element {
                    static bdf::types::card head;
                    using __base::element::form_EID;
                    using __base::card::format_outlist;
                    // bdf::types::entry_type<long> static form_EID;
                    bdf::types::entry_type<long> static form_PID;
                    bdf::types::entry_type<long> static form_G1;
                    bdf::types::entry_type<long> static form_G2;
                public:
                    // /** Element identification number. (Integer > 0)
                    //  */
                    // bdf::types::entry_value<long> EID;
                    /** Property identification number of a `PROD` entry.
                        (Integer > 0; Default = `EID`)
                        */
                    bdf::types::entry_value<long> PID;
                    /** Grid point identification number of first connection
                        point. (Integer > 0; `G1` ≠ `G2`)
                        */
                    bdf::types::entry_value<long> G1;
                    /** Grid point identification number of second connection
                        point. (Integer > 0; `G1` ≠ `G2`)
                        */
                    bdf::types::entry_value<long> G2;
                    crod() = default;
                    ~crod() = default;
                    explicit crod(std::list<std::string> const &inp);
                    crod(long *EID, long *PID, long *G1, long *G2);
                    /**
                     * \brief Card type indicator.
                     * \return
                     */
                    types card_type() const override;
                    void read(std::list<std::string> const &) override;
                    card const &operator() (const std::list<std::string> &) override;
                    /**
                     * \brief Return instance with changed values.
                     * \param EID
                     * \param PID
                     * \param G1
                     * \param G2
                     * \return
                     */
                    card const &operator() (
                        long const *EID, long const *PID,
                        long const *G1, long const *G2);
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry>>&) const override;
                    void check_data() override;
                };

                /// Handle Nastran Bulk `CBUSH` entries.
                /** # Generalized Spring-and-Damper Connection.

                    Defines a generalized spring-and-damper structural
                    element that may be nonlinear or frequency
                    dependent.

                    # Format

                    | 1       | 2     | 3      | 4    | 5    | 6         | 7    | 8    | 9     | 10 |
                    | ------- | ----- | ------ | ---- | ---- | --------- | ---- | ---- | ----- | -- |
                    | `CBUSH` | `EID` | `PID`  | `GA` | `GB` | `GO`/`X1` | `X2` | `X3` | `CID` |    |
                    |         | `S`   | `OCID` | `S1` | `S2` | `S3`      |      |      |       |    |

                    # Example 1

                    Noncoincident grid points.

                    | 1       | 2  | 3 | 4 | 5   | 6  | 7 | 8 | 9 | 10 |
                    | ------- | -- | - | - | --- | -- | - | - | - | -- |
                    | `CBUSH` | 39 | 6 | 1 | 100 | 57 |   |   |   |    |

                    # Example 2:

                    `GB` not specified.

                    | 1       | 2  | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
                    | ------- | -- | - | - | - | - | - | - | - | -- |
                    | `CBUSH` | 39 | 6 | 1 |   |   |   |   | 0 |    |

                    # Example 3:

                    Coincident grid points (GA=GB).

                    | 1       | 2  | 3 | 4 | 5   | 6 | 7 | 8 | 9 | 10 |
                    | ------- | -- | - | - | --- | - | - | - | - | -- |
                    | `CBUSH` | 39 | 6 | 1 | 100 | 7 |   |   | 6 |    |

                    # Example 4:

                    Noncoincident grid points with fields 6 through 9
                    blank and a spring-damper offset.

                    | 1       | 2    | 3  | 4  | 5   | 6   | 7 | 8 | 9 | 10 |
                    | ------- | ---- | -- | -- | --- | --- | - | - | - | -- |
                    | `CBUSH` | 39   | 6  | 1  | 600 |     |   |   |   |    |
                    |         | 0.25 | 10 | 0. | 10. | 10. |   |   |   |    |
                */
                class cbush : public __base::element {
                    static bdf::types::card head;
                    using __base::element::form_EID;
                    using __base::card::format_outlist;
                    // bdf::types::entry_type<long> static form_EID;
                    bdf::types::entry_type<long> static form_PID;
                    bdf::types::entry_type<long> static form_GA;
                    bdf::types::entry_type<long> static form_GB;
                    bdf::types::entry_type<long> static form_GO;
                    bdf::types::entry_type<double> static form_X1;
                    bdf::types::entry_type<double> static form_X2;
                    bdf::types::entry_type<double> static form_X3;
                    bdf::types::entry_type<long> static form_CID;
                    bdf::types::entry_type<double> static form_S;
                    bdf::types::entry_type<long> static form_OCID;
                    bdf::types::entry_type<double> static form_S1;
                    bdf::types::entry_type<double> static form_S2;
                    bdf::types::entry_type<double> static form_S3;
                public:
                    /**
                     * \brief Card type indicator.
                     * \return
                     */
                    types card_type() const override;
                    /** Flag to store whether orientation vector is
                        given at all , and if given whether they are
                        defined by means of an extra node (`GO`), or
                        via means of a direction vector
                        (`X1`,`X2`,`X3`).
                    */
                    enum class CHOOSE_DIR_CODE {
                        UNDEF,
                        has_DVEC, //!< Element has direction vector entry
                        has_DNODE //!< Element direction defined by direction node
                    };
                    CHOOSE_DIR_CODE choose_dir_code;
                    // /** Element identification number.
                    //      (0 < Integer < 100,000,000)
                    //  */
                    // bdf::types::entry_value<long> EID;
                    using __base::element::EID;
                    /** Property identification number of a `PBUSH`
                        entry. (Integer > 0; Default = `EID`)
                    */
                    bdf::types::entry_value<long> PID;
                    /** Grid point identification number of first
                        connection point. See Remark 6. (Integer > 0)
                    */
                    bdf::types::entry_value<long> GA;
                    /** Grid point identification number of second
                        connection point. See Remark 6. (Integer > 0)
                    */
                    bdf::types::entry_value<long> GB;
                    /** First component of orientation vector v, from
                        `GA`, in the displacement coordinate system at
                        `GA`. (Real)
                    */
                    bdf::types::entry_value<double> X1;
                    /** Second component of orientation vector v, from
                        `GA`, in the displacement coordinate system at
                        `GA`. (Real)
                    */
                    bdf::types::entry_value<double> X2;
                    /** Third component of orientation vector v, from
                        `GA`, in the displacement coordinate system at
                        `GA`. (Real)
                    */
                    bdf::types::entry_value<double> X3;
                    /** Alternate method to supply vector v using grid
                        point GO. Direction of v is from `GA` to `GO`.
                        v is then transferred to End `A`. See Remark
                        3. (Integer > 0)
                    */
                    bdf::types::entry_value<long> GO;
                    /** Element coordinate system identification. A 0
                        means the basic coordinate system. If `CID` is
                        blank, then the element coordinate system is
                        determined from `GO` or `Xi`. See Figure 8-17
                        and Remark 3. (Integer > 0 or blank)
                    */
                    bdf::types::entry_value<long> CID;
                    /** Location of spring damper. See Figure 8-17.
                        (0.0 < Real < 1.0; Default = 0.5)
                    */
                    bdf::types::entry_value<double> S;
                    /** Coordinate system identification of
                        spring-damper offset. See Remark 9. (Integer >
                        -1; Default = -1, which means the offset point
                        lies on the line between `GA` and `GB`
                        according to Figure 8-17)
                    */
                    bdf::types::entry_value<long> OCID;
                    /** First components of spring-damper offset in
                        the `OCID` coordinate system if `OCID` > 0.
                        See Figure 8-18 and Remark 9. (Real)
                    */
                    bdf::types::entry_value<double> S1;
                    /** Second components of spring-damper offset in
                        the `OCID` coordinate system if `OCID` > 0.
                        See Figure 8-18 and Remark 9. (Real)
                    */
                    bdf::types::entry_value<double> S2;
                    /** Third components of spring-damper offset in
                        the `OCID` coordinate system if `OCID` > 0.
                        See Figure 8-18 and Remark 9. (Real)
                    */
                    bdf::types::entry_value<double> S3;

                    cbush() = default;
                    ~cbush() = default;
                    explicit cbush(std::list<std::string> const &inp);
                    cbush(long *EID, long *PID, long *GA, long *GB=nullptr,
                          double *X1=nullptr, double *X2=nullptr, double *X3=nullptr,
                          long *GO=nullptr,
                          long *CID=nullptr,
                          double *S=nullptr, long *OCID=nullptr,
                          double *S1=nullptr, double *S2=nullptr,
                          double *S3=nullptr);
                    void read(std::list<std::string> const &) override;
                    card const &operator() (const std::list<std::string> &) override;
                    /**
                     * \brief Return instance with changed values.
                     */
                    card const &operator() (
                        long *EID, long *PID, long *GA, long *GB=nullptr,
                        double *X1=nullptr, double *X2=nullptr, double *X3=nullptr,
                        long *GO=nullptr,
                        long *CID=nullptr,
                        double *S=nullptr, long *OCID=nullptr,
                        double *S1=nullptr, double *S2=nullptr,
                        double *S3=nullptr);
                private:
                    void collect_outdata(
                        std::list<std::unique_ptr<format_entry>>&) const override;
                    void check_data() override;
                };
            }
        }
    }
}

#endif // _BDF_CARDS_ELEMENTS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
