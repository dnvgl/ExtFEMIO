/**
  \file header.h
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2016 by DNV GL SE
  \brief classes for defining NASTAN header

  Detailed description
*/

/* ID: $Id\$
 */

#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <sstream>
#include <list>
#include <memory>

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace header {
            namespace __base {
               class entry {
               public:
                  entry (void);
                  virtual std::ostream const &operator<<(std::ostream&) const = 0;
                  friend std::ostream const &operator<<(std::ostream &os, entry const &val);
               private:
                  virtual std::ostream const &put(std::ostream&) const = 0;
               };
            }

            /// Executive Control Statements
            namespace executive_control {

/**
# `SOL`: Execute a Solution Sequence

Specifies the solution sequence or main subDMAP to be executed.

## Format:

\f[
\text{\texttt{SOL}} \left\{
\begin{array}{c}
n\\
\text{subDMAP-name}
\end{array}
\right\}
\left[ \text{\texttt{SOLIN}} = \text{obj-DBset} \text{NOEXE} \right]
\f]

## Remarks:

1. If `SOLIN` keyword is not given and if there are no `LINK`
   statements within the input data, the program will perform an
   automatic link. The program will first collect the objects created
   in the current run by the `COMPILE` statement and the remaining
   objects stored in the MSCOBJ DBset. The program will then perform
   an automatic link of the collected objects.

2. If the `SOLIN` keyword is not given but a LINK statement is
   provided, the `SOLIN` default will be obtained from the `SOLOUT`
   keyword on the `LINK` statement.

3. The `OSCAR` (Operation Sequence Control ARray) defines the problem
   solution sequence. The `OSCAR` consists of a sequence of entries
   with each entry containing all of the information needed to execute
   one step of the problem solution. The `OSCAR` is generated from
   information supplied by the user’s entries in the Executive Control
   Section.

4. The `SOLIN` keyword will skip the automatic link and execute the
   `OSCAR` on the specified DBset.

5. The `DOMAINSOLVER` may be used in conjunction with Solution
   Sequences 101, 103, 108, and 111 to select domain decomposition
   solution methods.

6. Only `SOL <n>` is currently supported.
*/

               class sol : public __base::entry {
               public:
                  typedef enum {
                     /** Statics with Options:
                           Linear Steady State Heat Transfer
                           Alternate Reduction
                           Inertia Relief */
                     SESTATIC=101,
                     /// Normal Modes
                     SEMODES =103,
                     /** Buckling with options:
                           Static Analysis
                           Alternate Reduction
                           Inertia Relief */
                     SEBUCKL =105,
                     /// Nonlinear or Linear Statics
                     NLSTATIC=106,
                     /// Direct Complex Eigenvalues
                     SEDCEIG =107,
                     /// Direct Frequency Response
                     SEDFREQ =108,
                     /// Direct Transient Response
                     SEDTRAN =109,
                     /// Modal Complex Eigenvalues
                     SEMCEIG =110,
                     /// Modal Frequency Response
                     SEMFREQ =111,
                     /// Modal Transient Response
                     SEMTRAN =112,
                     /** Cyclic Statics with Option:
                         Alternate Reduction */
                     CYCSTATX=114,
                     /// Cyclic Normal Modes
                     CYCMODE =115,
                     /// Cyclic Buckling
                     CYCBUCKL=116,
                     /// Cyclic Direct Frequency Response
                     CYCFREQ =118,
                     /// Nonlinear or Linear Transient Response
                     NLTRAN  =129,
                     /// Static Aeroelastic Response
                     AESTAT  =144,
                     /// Aerodynamic Flutter
                     SEFLUTTR=145,
                     /// Aeroelastic Response
                     SEAERO  =146,
                     /** Static Structural and/or Steady State Heat
                         Transfer Analysis with Options:
                           Linear or Nonlinear Analysis */
                     NLSCSH  =153,
                     /** Transient Structural and/or Transient Heat
                         Transfer Analysis with Options:
                           Linear or Nonlinear Analysis */
                     NLTCSH  =159,
                     /** Database Transfer, “Output Description” on
                         page 373 of the MSC.Nastran Reference
                         Guide. */
                     DBTRANS =190,
                     /// Design Optimization
                     DESOPT  =200,
                     /// Nonlinear static and transient analysis
                     NONLIN  =400} sol_no_type;
                  sol_no_type sol_no;
                  sol(sol_no_type const &sol_no=SESTATIC);
                  sol(long const&);
                  const std::ostream& operator<<(std::ostream&) const;

               private:

                  std::ostream const &put(std::ostream&) const;
                  class sol_no_type_conv {
                  public:
                     static sol_no_type from_long(long const&);
                     static long to_long (sol_no_type const&);
                  };
               };

/**

# `CEND`: End of Executive Control Delimiter

Designates the end of the Executive Control Section.

## Format:

`CEND?

## Remark:

1. `CEND` is an optional statement. If CEND is not specified, then the
   program will automatically insert one.
*/
               class cend : public __base::entry {
               public:
                  cend(void);
                  const std::ostream& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };
            };

            namespace case_control {
/**
# `TITLE`: Output Title

Defines a character string that will appear on the first heading line
of each page of MSC.Nastran printer output.

## Format:

  `TITLE=title`

## Remarks:

1. If this command appears under a `SUBCASE` command, then the title
   appears in the output for that subcase only.

2. If this command appears before all `SUBCASE` commands, then the
   title is used in all subcases without a `TITLE` command.

3. If no `TITLE` command is present, then the title line will contain
   data and page numbers only.

4. The title also appears on plotter output.
*/
               class title : public __base::entry {
               public:
                  std::string name;
                  title(std::string const&);
                  const std::ostream& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

/**

# `ECHO`: Bulk Data Echo Request

Controls echo (i.e., printout) of the Bulk Data.

## Format:

\f[
\text{\texttt{ECHO}} = \left\{
\begin{array}{c}
\left[\text{\texttt{SORT}} \left(\left[\text{\texttt{EXCEPT}}\right]\text{cdni}, \dots\right)\right]\\
\text{\texttt{UNSORT}}\\
\text{\texttt{BOTH}}\\
\text{\texttt{NONE}}\\
\text{\texttt{FILE}}
\end{array}, \text{\texttt{PUNCH}}\left[\left(
\begin{array}{c}
\text{\texttt{SORT}}\\
\text{\texttt{BOTH}}\\
\text{\texttt{NEWBULK}}
\end{array} \right)\right]\right\}
\f]

## Examples:

\code{.unparsed}
ECHO=UNSORT
ECHO=BOTH
ECHO=PUNCH, SORT (MAT1, PARAM)
ECHO=SORT (EXCEPT DMI, DMIG)
ECHO=BOTH,PUNCH,FILE
\endcode

## Remarks:

1. If no `ECHO` command appears, a sorted Bulk Data will be printed.

2. Comments will appear at the front of the sorted file if
   `ECHO=PUNCH`.

3. Portions of the unsorted Bulk Data can be selectively echoed by
   including the commands `ECHOON` and `ECHOOFF` at various places
   within the Bulk Data. `ECHOOFF` stops the unsorted echo until an
   `ECHOON` command is encountered. Many such pairs of commands may be
   used. The `ECHOON` and `ECHOOFF` command may be used in the
   Executive and Case Control Sections; however, `ECHOOF` should not
   be the first entry and continuation entries are not handled
   correctly.

4. If the `SORT` (cdni,...) is specified in a restart in `SOL`s 101
   through 200, then the continuation entries will not be printed.

5. If the `SORT` (cdni,...) describer is used, then it must appear as
   the last describer, as in the example above.

6. If `EXCEPT` is specified then it must be specified before all cdni.
   All Bulk Data entry types will be listed except those given for
   cdn1, cdn2, etc. If `EXCEPT` is not specified, then only those Bulk
   Data entry types listed under `cdn1`, `cdn2`, etc. will be listed.
*/
               class echo : public __base::entry {
               public:
                  class describer {
                  protected:
                     describer(void);
                  public:
                     virtual std::string const str(void) const = 0;
                  };

                  /** The unsorted Bulk Data will be printed. If
                      `SORT` is not also specified, the sorted Bulk
                      Data will not be printed.
                  */
                  class unsort : public describer {
                  public:
                     unsort(void);
                     virtual std::string const str(void) const;
                  };

                  /** The sorted (arranged in alphanumeric order) Bulk
                      Data will be printed.
                  */
                  class sort : public describer {
                  public:
                     class cdni_entry {
                     private:
                        std::string name;
                        bool except;

                     public:
                     /* cdni, \f$ \dots \f$

                        Bulk Data entry names to be included, or
                        excluded by `EXCEPT`, in the sorted echo
                        printout. The `PUNCH` file is not affected by
                        *cdni*.

                        `EXCEPT`

                        Exclude cdni Bulk Data entries from sorted
                        echo printout. See Remark 6.
                     */
                        cdni_entry(
                           std::string const &name, bool const except=false);
                        virtual std::string const str(void) const;
                     };

                  private:
                     std::list<cdni_entry> cdni;

                  public:
                     sort(std::list<cdni_entry> const &);
                     virtual std::string const str(void) const;
                  };

                  /** Both sorted and unsorted Bulk Data will be
                      printed. This is equivalent to `ECHO=SORT,
                      UNSORT`.
                  */
                  class both : public describer {
                  public:
                     both(void);
                     virtual std::string const str(void) const;
                  };

                  /** Neither sorted nor unsorted Bulk Data will be
                      printed.
                   */
                  class none : public describer {
                  public:
                     none(void);
                     virtual std::string const str(void) const;
                  };

                  /**
                     The entire Bulk Data will be written to the punch file.
                  */
                  class punch : public describer {
                  public:
                     typedef enum {
                        SORT,
                        BOTH,
                        /** In `SOL 200`, a comlete unsorted Bulk Data
                            file is written to the punch file with
                            updated design model entries.
                        */
                        NEWBULK} option_type;

                  private:
                     std::list<option_type> options;

                  public:
                     punch(std::list<option_type> const &options={});
                     virtual std::string const str(void) const;
                  };

                  /** The entire Bulk Data Echo will be written to
                      the separate file with a default suffix of
                      `.BECHO` in `*.f06` form. User-defined
                      filename must be specified in `ASSIGN`
                      statement.
                   */
                  class file : public describer {
                  public:
                     file(void);
                     virtual std::string const str(void) const;
                  };

               private:
                  std::list<std::unique_ptr<describer> > oper;

               public:
                  echo(std::list<describer*> const &oper={});
                  const std::ostream& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

/**
# `DISPLACEMENT`: Displacement Output Request

Requests the form and type of displacement or pressure vector output.
Note: `PRESSURE` and `VECTOR` are equivalent commands.

## Format:

\f[
\begin{split}
\text{\texttt{DISPLACEMENT}}
\left[(\left[
\begin{array}{c}
\text{\texttt{SORT1}}\\
\text{\texttt{SORT2}}
\end{array}\right],
\left[
\begin{array}{c}
\text{\texttt{PRINT}, \texttt{PUNCH}}\\
\text{\texttt{PLOT}}
\end{array}\right],
\left[
\begin{array}{c}
\text{\texttt{REAL} or \texttt{IMAG}}\\
\text{\texttt{PHASE}}
\end{array}\right]
\left[
\begin{array}{c}
\text{\texttt{PSDF}, \texttt{ATOC}, \texttt{CRMS}}\\
\text{\texttt{RALL}}
\end{array}\right],\right.\\\left.
\left[\begin{array}{c}
\text{\texttt{RPRINT}}\\
\text{\texttt{NORPRINT}}
\end{array}, \text{\texttt{RPUNCH}}\right] , [ \text{\texttt{CID}}],
\left[\begin{array}{c}
\text{\texttt{TM}} = f\\
\text{\texttt{T1}} = f, \text{\texttt{T2}} = f, \text{\texttt{T3}} = f
\end{array}\right],
\left[\begin{array}{c}
\text{\texttt{RM}} = f\\
\text{\texttt{R1}} = f, \text{\texttt{R2}} = f, \text{\texttt{R3}} = f
\end{array}\right])\right] =
\left\{\begin{array}{c}
\text{\texttt{ALL}}\\
n\\
\text{\texttt{NONE}}
\end{array}
\right\}
\end{split}
\f]

## Examples:

\code{.unparsed}
DISPLACEMENT=5
DISPLACEMENTS(REAL)=ALL
DISPLACEMENT(SORT2, PUNCH, REAL)=ALL
DISPLACEMENT(SORT2, PRINT, PSDF, CRMS, RPUNCH)=20
DISPLACEMENT(PRINT, RALL, NORPRINT)=ALL
DISP (T1=1.-3, T3=1.-2) = ALL
DISP (TM=1.-3, PRINT,PLOT) = ALL
DISP (TM=1.-3,PRINT,PLOT,SORT2) = 20
\endcode

## Remarks:

1. Both `PRINT` and `PUNCH` may be requested.

2. The defaults for `SORT1` and `SORT2` depend on the type of analysis:

  - `SORT1` is the default in static analysis, frequency response,
    steady state heat transfer analysis, real and complex eigenvalue
    analysis, flutter analysis, and buckling analysis.

  - `SORT2` is the default in transient response analysis (structural
    and heat transfer). `SORT2` is not available for real eigenvalue
    (including buckling), complex eigenvalue, or flutter analysis. If
    `SORT1` is selected in a transient solution for one or more of the
    commands `ACCE`, `DISP`, `ENTH`, `FORC`, `HDOT`, `MPCF`, `OLOA`,
    `SPCF`, `STRA`, `STRE`, and `VELO` then the remaining commands
    will also be output in `SORT1` format. If `SORT2` is selected in a
    frequency response solution for one or more of the commands
    `ACCE`, `DISP`, `FORC`, `MPCF`, `OLOA`, `SPCF`, `STRA`, `STRE`,
    and `VELO` then the remaining commands will also be output in
    `SORT2` format.

  - `XY` plot requests forces `SORT2` and overrides `SORT1` requests!

3. `VECTOR` and `PRESSURE` are alternate forms and are entirely
    equivalent to ` DISPLACEMENT`.

4. `DISPLACEMENT=NONE` overrides an overall output request.

5. The `PLOT` option is used when curve plots are desired in the
   magnitude/phase representation and no printer output request is
   present for magnitude/phase representation.

6. The units of translation are the same as the units of length of the
   model. Rotations are in units of radians.

7. Displacement results are output in the global coordinate system
   (see field `CD` on the `GRID` Bulk Data entry).

8. The option of` PSDF`, `ATOC`, `CRMS`, and `RALL`, or any
   combination of them, can be selected for random analysis. The
   results can be either printed in the `.f06? file or punched in the
   punch file, or output in both files.

9. Note that the `CID` keyword affects only grid point related output,
   such as `DISPlacement`, `VELOcity`, `ACCEleration`, `OLOAD`,
   `SPCForce` and `MPCForce`. In addition, `CID` keyword needs to
   appear only once in a grid related output request anywhere in the
   Case Control Section to turn on the printing algorithm.

10. Displacement components may be selected to control filtering to
   reduce the amount of output produced. When magnitudes are selected,
   the component values are ignored. Only a single positive value for
   f can be supplied and comparisons are performed in the global
   reference frame. Comparisons are performed after the SET
   intersection is performed against the domain. Selection of this
   option does not effect the `MAXMIN(GRID)` operations. Scalar
   comparisons are performed using the minimum of all supplied values
   for the filters. Complex vector magnitudes follow a derivation
   using a deterministic interpretation for frequency response.

11. When using filters the compound usage of the verbs` PRINT, PLOT`
   is allowed. The entries in the printed output are the entries that
   exceed any threshold, while the remaining entries within the SET
   are marked as plot to allow for post-processing operations. When
   SORT2 is selected, then print, plot must be used to allow for table
   transpose operations to occur. When any entry in the SORT2 format
   is above the threshold, all values for time or frequency will be
   printed for the grid.
*/
               class displacement : public __base::entry {
               public:
                  class describer {
                  protected:
                     describer(void);
                  public:
                     virtual std::string const str(void) const = 0;
                  };

                  /** Output will be presented as a tabular listing of
                      grid points for each load, frequency,
                      eigenvalue, or time, depending on the solution
                      sequence.
                  */
                  class sort1 : public describer {
                  public:
                     sort1(void);
                     virtual std::string const str(void) const;
                  };

                  /** Output will be presented as a tabular listing of
                      load, frequency or time for each grid point.
                   */
                  class sort2 : public describer {
                  public:
                     sort2(void);
                     virtual std::string const str(void) const;
                  };

                  /** The printer will be the output medium.
                   */
                  class print : public describer {
                  public:
                     print(void);
                     virtual std::string const str(void) const;
                  };

                  /** The punch file will be the output medium.
                   */
                  class punch : public describer {
                  public:
                     punch(void);
                     virtual std::string const str(void) const;
                  };

                  /** Generates, but does not print, displacement
                      data.
                  */
                  class plot : public describer {
                  public:
                     plot(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests rectangular format (real and imaginary)
                      of complex output. Use of either `REAL` or
                      `IMAG` yields the same output.
                  */
                  class real : public describer {
                  public:
                     real(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests rectangular format (real and imaginary) of
                      complex output. Use of either `REAL` or `IMAG` yields
                      the same output.
                  */
                  class imag : public describer {
                  public:
                     imag(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests polar format (magnitude and phase) of
                      complex output. Phase output is in degrees.
                  */
                  class phase : public describer {
                  public:
                     phase(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests the power spectral density function be
                      calculated for random analysis post-processing.
                      Request must be made above the subcase level and
                      `RANDOM` must be selected in the Case Control.
                      See Remark 8.
                  */
                  class psdf : public describer {
                  public:
                     psdf(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests the autocorrelation function be
                      calculated for random analysis post-processing.
                      Request must be made above the subcase level and
                      `RANDOM` must be selected in the Case Control.
                      See Remark 8.
                  */
                  class atoc : public describer {
                  public:
                     atoc(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests the cumulative root mean square
                      function be calculated for random analysis
                      post-processing. Request must be made above the
                      subcase level and `RANDOM` must be selected in
                      the Case Control. See Remark 8.
                  */
                  class crms : public describer {
                  public:
                     crms(void);
                     virtual std::string const str(void) const;
                  };

                  /** Request all of `PSDF`, `ATOC` and `CRMS` be
                      calculated for random analysis post-processing.
                      Request must be made above the subcase level and
                      `RANDOM` must be selected in the Case Control.
                      See Remark 8.
                  */
                  class rall : public describer {
                  public:
                     rall(void);
                     virtual std::string const str(void) const;
                  };

                  /** Writes random analysis results in the print file
                      (Default)
                  */
                  class rprint : public describer {
                  public:
                     rprint(void);
                     virtual std::string const str(void) const;
                  };

                  /** Disables the writing of random analysis results
                      in the print file.
                  */
                  class noprint : public describer {
                  public:
                     noprint(void);
                     virtual std::string const str(void) const;
                  };


                  /** Writes random analysis results in the punch
                      file.
                  */
                  class rpunch : public describer {
                  public:
                     rpunch(void);
                     virtual std::string const str(void) const;
                  };

                  /** Request to print output coordinate system ID in
                      printed output file, `F06` file.
                  */
                  class cid : public describer {
                  public:
                     cid(void);
                     virtual std::string const str(void) const;
                  };

                  /** Translational Magnitude Filter
                   */
                  class tm : public describer {
                  private:
                     double value;
                  public:
                     tm(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Translational Component Filters
                   */
                  class t1 : public describer {
                  private:
                     double value;
                  public:
                     t1(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Translational Component Filters
                   */
                  class t2 : public describer {
                  private:
                     double value;
                  public:
                     t2(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Translational Component Filters
                   */
                  class t3 : public describer {
                  private:
                     double value;
                  public:
                     t3(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Rotational Magnitude Filters
                   */
                  class rm : public describer {
                  private:
                     double value;
                  public:
                     rm(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Rotational Component Filters
                   */
                  class r1 : public describer {
                  private:
                     double value;
                  public:
                     r1(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Rotational Component Filters
                   */
                  class r2 : public describer {
                  private:
                     double value;
                  public:
                     r2(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Rotational Component Filters
                   */
                  class r3 : public describer {
                  private:
                     double value;
                  public:
                     r3(double &);
                     virtual std::string const str(void) const;
                  };

                  /** Filter value (Real > 0.0)
                   */
                  class f : public describer {
                  private:
                     double value;
                  public:
                     f(double &);
                     virtual std::string const str(void) const;
                  };

                  typedef enum {
                     /** Displacements for all points will be output.
                      */
                     ALL,
                     /** Displacement for no points will be output.
                      */
                     NONE,
                     /** Set identification of a previously appearing
                         `SET` command. Only displacements of points
                         with identification numbers that appear on
                         this `SET` command will be output.
                         (Integer>0)
                      */
                     n} restype;
               private:
                  std::list<std::unique_ptr<describer> > describers;
                  restype res;
                  long res_n;
                  displacement(std::list<describer*> const &, restype const &res, long const &);
               public:
                  displacement(std::list<describer*> const &, restype const &res=NONE);
                  displacement(std::list<describer*> const &, long const &);
                  const std::ostream& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

/** # `SPCFORCES`: Single-Point Forces of Constraint Output Request


Requests the form and type of single-point force of constraint vector
output.

## Format:

\f[
\begin{split}
\text{\texttt{SPFORCES}} \left[ ( \left[
\begin{array}{c}
\text{\texttt{SORT1}}\\
\text{\texttt{SORT2}}
\end{array}\right],
\left[
\begin{array}{c}
\text{\texttt{PRINT}}, \text{\texttt{PUNCH}}\\
\text{\texttt{PLOT}}
\end{array}\right],
\left[
\begin{array}{c}
\text{\texttt{REAL} or \texttt{NOZPRINT}}\\
\text{\texttt{PHASE}}
\end{array}\right]
\left[
\begin{array}{c}
\text{\texttt{PSDF}, \texttt{ATOC}, \texttt{CRMS}}\\
\text{or \texttt{RALL}}
\end{array}\right]\right.\\\left.
\left[
\begin{array}{c}
\text{\texttt{RPRINT}}\\
\text{\texttt{NORPRINT}}
\end{array}, \text{\texttt{RPUNCH}}\right],
\left[\text{\texttt{CID}}\right])\right] =
\left\{
\begin{array}{c}
\text{\texttt{ALL}}\\
n\\
\text{\texttt{NONE}}
\end{array}\right\}
\end{split}
\f]

Examples:

\code{.unparsed}
SPCFORCES = 5
SPCFORCES(SORT2, PUNCH, PRINT, IMAG) = ALL
SPCFORCES(PHASE) = NONE
SPCFORCES(SORT2, PRINT, PSDF, CRMS, RPUNCH)=20
SPCFORCES(PRINT, RALL, NORPRINT)=ALL
\endcode


## Remarks:

1. Both `PRINT` and `PUNCH` may be requested.

2. See Remark 2 under `displacement` for a discussion of `SORT1` and
   `SORT2`. In the `SORT1` format only nonzero values will be output.

3. In a statics problem, a request for `SORT2` causes loads at all
    points (zero and nonzero) to be output.

4. `SPCFORCES=NONE` overrides an overall output request.

5. In `SORT1` format, `SPCFORCES`s recovered at consecutively numbered
   scalar points are printed in groups of six (sextets) per line of
   output. But if a scalar point is not consecutively numbered, then
   it will begin a new sextet on a new line of output. If a sextet can
   be formed and all values are zero, then the line will not be
   printed. If a sextet cannot be formed, then zero values may be
   output.

6. `SPCFORCES` results are output in the global coordinate system (see
   field `CD` on the `GRID` Bulk Data entry).

7. In `SOL`s 129 and 159, `SPCFORCES` results do not include the
   effects of mass and damping elements.

8. In all solution sequences except `SOL`s 129 and 159, `SPCFORCES`
   results do include the effects of mass and damping, except damping
   selected by `SDAMPING` command. `PARAM,DYNSPCF,OLD` may be
   specified to obtain `SPCFORCES` results, which do not include mass
   and damping effects.

9. In inertia relief analysis, the `SPCFORCES` output is interpreted
   differently for `SOL`s 1, 101 and 200:

   - In `SOL` 1, the `SPCFORCE` output reflects the effects due to the
     applied loads only and not the inertial loads.

   - In `SOL`s 101 and 200, the `SPCFORCE` output includes both the
     effects due to inertial loads and applied loads.

10. The option of `PSDF`, `ATOC`, `CRMS` and `RALL`, or any
   combination of them, can be selected for random analysis. The
   results can be either printed in the `.f06` file or punched in the
   punch file, or output in both files.

11. Note that the `CID` keyword affects only grid point related
   output, such as `DISPlacement`, `VELOcity`, `ACCEleration`,
   `OLOAD`, `SPCForce` and `MPCForce`. In addition, `CID` keyword
   needs to appear only once in a grid related output request anywhere
   in the Case Control Section to turn on the printing algorithm.
*/
               class spcforces : public __base::entry {
               public:
                  class describer {
                  protected:
                     describer(void);
                  public:
                     virtual std::string const str(void) const = 0;
                  };


               /** Output will be presented as a tabular listing of
                   grid points for each load, frequency, eigenvalue,
                   or time, depending on the solution sequence.
               */
                  class sort1 : public describer {
                  public:
                     sort1(void);
                     virtual std::string const str(void) const;
                  };

                  /** Output will be presented as a tabular listing of
                      frequency or time for each grid point.
                  */
                  class sort2 : public describer {
                  public:
                     sort2(void);
                     virtual std::string const str(void) const;
                  };

                  /** The printer will be the output medium.
                   */
                  class print : public describer {
                  public:
                     print(void);
                     virtual std::string const str(void) const;
                  };

                  /** The punch file will be the output medium.
                   */
                  class punch : public describer {
                  public:
                     punch(void);
                     virtual std::string const str(void) const;
                  };
                  /** Generates, but does not print, single-point
                      forces of constraint.
                   */
                  class plot : public describer {
                  public:
                     plot(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests rectangular format (real and imaginary)
                      of complex output. Use of either `REAL` or
                      `IMAG` yields the same output.
                  */
                  class real : public describer {
                  public:
                     real(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests rectangular format (real and imaginary)
                      of complex output. Use of either `REAL` or
                      `IMAG` yields the same output.
                   */
                  class imag : public describer {
                  public:
                     imag(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests polar format (magnitude and phase) of
                      complex output. Phase output is in degrees.
                  */
                  class phase : public describer {
                  public:
                     phase(void);
                     virtual std::string const str(void) const;
                  };
                  /** Print only non-zero SPCForces appearing in
                      `SORT2` output. This keyword does not affect
                      `SORT1` output.
                   */
                  class nozprint : public describer {
                  public:
                     nozprint(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests the power spectral density function be
                      calculated and stored in the database for random
                      analysis post-processing. Request must be made
                      above the subcase level and `RANDOM` must be
                      selected in the Case Control.
                  */
                  class psdf : public describer {
                  public:
                     psdf(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests the autocorrelation function be
                      calculated and stored in the database for random
                      analysis post-processing. Request must be made
                      above the subcase level and `RANDOM` must be
                      selected in the Case Control.
                  */
                  class atoc : public describer {
                  public:
                     atoc(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests the cumulative root mean square
                      function be calculated for random analysis
                      post-processing. Request must be made above the
                      subcase level and `RANDOM` must be selected in the
                      Case Control.
                  */
                  class crms : public describer {
                  public:
                     crms(void);
                     virtual std::string const str(void) const;
                  };
                  /** Requests all of `PSDF`, `ATOC` and `CRMS` be
                      calculated for random analysis post-processing.
                      Request must be made above the subcase level and
                      `RANDOM` must be selected in the Case Control.
                  */
                  class rall : public describer {
                  public:
                     rall(void);
                     virtual std::string const str(void) const;
                  };
                  /** Writes random analysis results in the print
                      file. (Default)
                  */
                  class rprint : public describer {
                  public:
                     rprint(void);
                     virtual std::string const str(void) const;
                  };
                  /** Disables the writing of random analysis results
                      in the print file.

                   */
                  class norprint : public describer {
                  public:
                     norprint(void);
                     virtual std::string const str(void) const;
                  };
                  /** Writes random analysis results in the punch
                      file.

                   */
                  class rpunch : public describer {
                  public:
                     rpunch(void);
                     virtual std::string const str(void) const;
                  };
                  /** Request to print output coordinate system ID in
                      printed output file, `F06` file.
                  */
                  class cid : public describer {
                  public:
                     cid(void);
                     virtual std::string const str(void) const;
                  };
                  typedef enum {
                     /** Single-point forces of constraint for all
                         points will be output. See Remarks 2. and 5.
                     */
                     ALL,
                     /** Single-point forces of constraint for no
                         points will be output.
                     */
                     NONE,
                     /** Set identification of a previously appearing
                         `SET` command. Only single-point forces
                         constraint for points with identification
                         numbers that appear on this SET command will
                         be output. (Integer>0)
                     */
                     n} restype;
               private:
                  std::list<std::unique_ptr<describer> > describers;
                  restype res;
                  long res_n;
                  spcforces(std::list<describer*> const &, restype const &res, long const &);
               public:
                  spcforces(std::list<describer*> const &, restype const &res=NONE);
                  spcforces(std::list<describer*> const &, long const &res);
                  std::ostream const& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

/** # `STRESS`: Element Stress Output Request

Requests the form and type of element stress output. Note: `ELSTRESS`
is an equivalent command.

## Format:

\f[
\begin{split}
\text{\texttt{STRESS}} \left[ ( \left[
\begin{array}{c}
\text{\texttt{SORT1}}\\
\text{\texttt{SORT2}}
\end{array}\right], \left[
\begin{array}{c}
\text{\texttt{PRINT}, \texttt{PUNCH}}\\
\text{\texttt{PLOT}}
\end{array}\right], \left[
\begin{array}{c}
\text{\texttt{REAL} or \texttt{IMAG}}\\
\text{\texttt{PHASE}}
\end{array}\right], \left[
\begin{array}{c}
\text{\texttt{VONMISES}}\\
\text{\texttt{MAXS} or \texttt{SHEAR}}
\end{array}\right], \right.\\
\left.\left[
\begin{array}{c}
\text{\texttt{CENTER}}\\
\text{\texttt{CUBIC}}\\
\text{\texttt{SGAGE}}\\
\text{\texttt{CORNER} or \texttt{BILIN}}
\end{array}\right], \left[
\begin{array}{c}\text{\texttt{PSDF}, \texttt{ATOC}, \texttt{CRMS}}\\
\text{or \texttt{RALL}}
\end{array}\right], \left[
\begin{array}{c}
\text{\texttt{RPRINT}}\\
\text{\texttt{NORPRINT}}
\end{array}\text{, \texttt{RPUNCH}}\right])\right] = \left\{
\begin{array}{c}
\text{\texttt{ALL}}\\
n\\
\text{\texttt{NONE}}
\end{array}\right\}
\end{split}
\f]

Examples:

\code{.unparsed}
DISPLACEMENT=5
STRESS=5
STRESS(CORNER)=ALL
STRESS (SORT1,PRINT,PUNCH,PHASE)=15
STRESS(PLOT)=ALL
STRESS(PRINT, PSDF, CRMS, RPUNCH)=20
STRESS(PRINT, RALL, NORPRINT)=ALL
\endcode

Remarks:

1. Both `PRINT` and `PUNCH` may be requested.

2. `ALL` should not be used in a transient problem due to excessive
   output.

3. See Remark 2 under “`DISPLACEMENT`” for a discussion of
`SORT1` and `SORT2`.

4. `ELSTRESS` is an alternate form and is entirely equivalent to
   `STRESS`.

5. `STRESS=NONE= overrides an overall output request.

6. The `PLOT` option is used when contour plots of stresses are
   requested but no printer output of stresses is desired. However in
   nonlinear analysis, the nonlinear stresses will still be printed
   unless `NLSTRESS(PLOT)` is specified.

7. The `VONMISES` option is ignored for ply stresses.

8. The `VONMISES`, `MAXS`, and `SHEAR` options are ignored in the
   complex eigenvalue and frequency response solution sequences.

9. The options ?CENTER`, `CORNER`, `CUBIC`, `SGAGE`, and `BILIN` are
   recognized only in the first subcase and determine the option to be
   used in all subsequent subcases with the `STRESS`, `STRAIN`, and
   `FORCE` commands. (In superelement analysis, the first subcase
   refers to the first subcase of each superelement. Therefore, it is
   recommended that these options be specified above all subcases.)
   Consequently, options specified in subcases other than the first
   subcase will be ignored. See also Remark 8 under the “`FORCE`”
   command for further discussion.

10. For composite ply output, the grid point option for `CQUAD4`
   elements will be reset to the default option (`CENTER`).

11. `MAXS` for shell elements is not an equivalent stress.

12. The option of `PSDF`, `ATOC`, `CRMS`, and `RALL`, or any
    combination of them, can be selected for random analysis. The
    results can be either printed in the .f06 file or punched in the
    punch file, or output in both files.
*/
               class stress : public __base::entry {

                                 public:
                  class describer {
                  protected:
                     describer(void);
                  public:
                     virtual std::string const str(void) const = 0;
                  };

                  /** Output will be presented as a tabular listing of
                      elements for each load, frequency, eigenvalue,
                      or time, depending on the solution sequence.
                  */
                  class sort1 : public describer {
                  public:
                     sort1(void);
                     virtual std::string const str(void) const;
                  };

                  /** Output will be presented as a tabular listing of
                      frequency or time for each element type.
                  */
                  class sort2 : public describer {
                  public:
                     sort2(void);
                     virtual std::string const str(void) const;
                  };

                  /** The printer will be the output medium.
                  */
                  class print : public describer {
                  public:
                     print(void);
                     virtual std::string const str(void) const;
                  };

                  /** The punch file will be the output medium.
                  */
                  class punch : public describer {
                  public:
                     punch(void);
                     virtual std::string const str(void) const;
                  };

                  /** Generates stresses for requested set but no
                      printer output.
                  */
                  class plot : public describer {
                  public:
                     plot(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests rectangular format (real and imaginary)
                      of complex output. Use of either `REAL` or
                      `IMAG` yields the same output.
                  */
                  class real : public describer {
                  public:
                     real(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests rectangular format (real and imaginary)
                      of complex output. Use of either `REAL` or
                      `IMAG` yields the same output.
                  */
                  class imag : public describer {
                  public:
                     imag(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests polar format (magnitude and phase) of
                      complex output. Phase output is in degrees.
                  */
                  class phase : public describer {
                  public:
                     phase(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests the power spectral density function be
                      calculated and stored in the database for random
                      analysis post-processing. Request must be made
                      above the subcase level and `RANDOM` must be
                      selected in the Case Control.
                  */
                  class psdf : public describer {
                  public:
                     psdf(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests the autocorrelation function be
                      calculated and stored in the database for random
                      analysis post-processing. Request must be made
                      above the subcase level and `RANDOM` must be
                      selected in the Case Control.
                  */
                  class atoc : public describer {
                  public:
                     atoc(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests the cumulative root mean square
                      function be calculated for random analysis
                      post-processing. Request must be made above the
                      subcase level and `RANDOM` must be selected in
                      the Case Control.
                  */
                  class crms : public describer {
                  public:
                     crms(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests all of `PSDF`, `ATOC`, and `CRMS` be
                      calculated for random analysis post-processing.
                      Request must be made above the subcase level and
                      `RANDOM` must be selected in the Case Control.
                  */
                  class rall : public describer {
                  public:
                     rall(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests von Mises stress.
                  */
                  class vonmises : public describer {
                  public:
                     vonmises(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests maximum shear in the plane for shell
                      elements and octahedral stress for solid
                      elements.
                  */
                  class maxs : public describer {
                  public:
                     maxs(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests maximum shear in the plane for shell
                      elements and octahedral stress for solid
                      elements.
                  */
                  class shear : public describer {
                  public:
                     shear(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests `CQUAD4`, `QUADR` and `TRIAR` element
                      stresses at the center only. The default for
                      `QUAD4` is `CENTER`. The default for ?QUADR` and
                      `TRIAR` is `CORNER`.
                  */
                  class center : public describer {
                  public:
                     center(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests `CQUAD4` element stresses at the center
                      and grid points using strain gage approach with
                      cubic bending correction.
                  */
                  class cubic : public describer {
                  public:
                     cubic(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests `CQUAD4` element stresses at center and
                      grid points using strain gage approach.
                  */
                  class sgage : public describer {
                  public:
                     sgage(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests `CQUAD4`, `QUADR`, amd `TRIAR` element
                      stresses at center and grid points using
                      bilinear extrapolation.
                  */
                  class corner : public describer {
                  public:
                     corner(void);
                     virtual std::string const str(void) const;
                  };

                  /** Requests `CQUAD4`, `QUADR`, amd `TRIAR` element
                      stresses at center and grid points using
                      bilinear extrapolation.
                  */
                  class bilin : public describer {
                  public:
                     bilin(void);
                     virtual std::string const str(void) const;
                  };

                  /** Writes random analysis results in the print
                      file. (Default)
                  */
                  class rprint : public describer {
                  public:
                     rprint(void);
                     virtual std::string const str(void) const;
                  };

                  /** Disables the writing of random analysis results
                      in the print file.
                  */
                  class norprint : public describer {
                  public:
                     norprint(void);
                     virtual std::string const str(void) const;
                  };

                  /** Writes random analysis results in the punch
                      file.
                  */
                  class rpunch : public describer {
                  public:
                        rpunch(void);
                     virtual std::string const str(void) const;
                     };

               public:
                  typedef enum {
                     /** Stresses for all elements will be output.
                      */
                     ALL,
                     /** Set identification of a previously appearing
                         SET command. Only stresses for elements with
                         identification numbers that appear on this
                         SET command will be output. (Integer >0)
                     */
                     n,
                     /** No element stress will be output.
                      */
                     NONE} restype;
               private:
                  std::list<std::unique_ptr<describer> > describers;
                  restype res;
                  long res_n;
                  stress(std::list<describer*> const &, restype const &, long const &);
               public:
                  stress(std::list<describer*> const &, restype const &res=NONE);
                  stress(std::list<describer*> const &, long const &);
                  std::ostream const& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

                  /** ## `LOAD`: External Static Load Set Selection

Selects an external static load set.

### Format:

`LOAD`=n

Example:

\code{.unparsed}
LOAD=15
\endcode

### Remarks:

1. A `GRAV` entry cannot have the same set identification number as
   any of the other loading entry types. If it is desired to apply a
   gravity load along with other static loads, a `LOAD` Bulk Data
   entry must be used.

2. `LOAD` is only applicable in linear and nonlinear statics, inertia
   relief, differential stiffness, buckling, and heat transfer
   problems.

3. The total load applied will be the sum of external (`LOAD`),
   thermal (`TEMP(LOAD)`), element deformation (`DEFORM`), and
   constrained displacement (`SPC`) loads.

4. Static, thermal, and element deformation loads should have unique
   set identification numbers.
                  */
             class load : public __base::entry {
             private:
                /** Set identification of at least one external load
                    Bulk Data entry. The set identification must
                    appear on at least one `FORCE`, `FORCE1`,
                    `FORCE2`, `FORCEAX`, `GRAV`, `MOMAX`, `MOMENT`,
                    `MOMENT1`, `MOMENT2`, `LOAD`, `PLOAD`, `PLOAD1`,
                    `PLOAD2`, `PLOAD4`, `PLOADX`, `QVOL`, `QVECT`,
                    `QHBDY`, `QBDY1`, `QBDY2`, `QBDY3`, `PRESAX`,
                    `RFORCE`, `SPCD`, or `SLOAD` entry. (Integer>0)
                */
                long n;

             public:
                load(long const &);
                virtual const std::ostream& operator<<(std::ostream&) const;
             private:
                std::ostream const &put(std::ostream&) const;
             };


/** ## `SUBTITLE`: Output Subtitle

Defines a subtitle that will appear on the second heading line of each
page of printer output.

### Format:

`SUBTITLE`=subtitle


### Example:

\code{.unparsed}
SUBTITLE=PROBLEM NO. 5-1A
\endcode

### Description of Describers and their Meaning

#### subtitle

Any character string.

### Remarks:

1. `SUBTITLE` appearing under a `SUBCASE` command will appear in the
   output for that subcase only.

2. `SUBTITLE` appearing before all `SUBCASE` commands will appear in
   the output for all subcases except those in Remark 1.

3. If no `SUBTITLE` command is present, the subtitle line will be
   blank.

4. The subtitle also appears on plotter output.
                  */
               class subtitle : public __base::entry {
               private:
                  std::string title;

               public:
                  subtitle(std::string const &);
                  virtual const std::ostream& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

/**
# `SUBCASE`: Subcase Delimiter

Delimits and identifies a subcase.

## Format:

`SUBCASE` = /n/

## Example:

\code{.unparsed}
SUBCASE=101
\endcode

## Remarks:

1. The subcase identification number, /n/, must be greater than all
   previous subcase identification numbers.

2. Plot requests and RANDPS requests refer to n.

3. See the `MODES` command for use of this command in normal modes
   analysis.

4. If a comment follows n, then the first few characters of the
   comment will appear in the subcase label in the upper right-hand
   corner of the output.
*/
               class subcase : public __base::entry {
               private:
                  /** Subcase identification number. (Integer>0)
                   */
                  long n;
                  std::string subtitle;

               private:
                  /// Maximum n used yet, use for automatic selection of n
                  long static max_n;

               public:

                  subcase(void);
                  subcase(long const &);
                  const std::ostream& operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

/** # `BEGIN BULK`: Case Control and Bulk Data Delimiter

Designates the end of the Case Control Section and/or the beginning of
a Bulk Data Section.

Format:

\f[
\text{\texttt{BEGIN}} \left[ \text{\texttt{BULK}} \right]
\left[
\begin{array}{c}
\text{\texttt{AUXMODEL}} = \text{auxmid}\\
\text{\texttt{SUPER}} = \text{seid}\\
\end{array}\right]
\f]

Examples:
\code{.unparsed}
BEGIN BULK
BEGIN AUXMODEL=22
\endcode

## Description of Describers and their Meaning

### `AUXMODEL`

Indicates the beginning of an auxiliary model Bulk Data Section.

### auxmid

Auxiliary model identification number. (Integer>0)

### `SUPER`

Indicates the beginning of partitioned superelement Bulk Data Section.

### seid

Superelement identification number. (Integer>0)

## Remarks:

1. `BEGIN BULK` is not required. If not specified, then the program
   will automatically insert one.

2. For an auxiliary model, `AUXMID` is referenced by the `AUXMODEL`
  Case Control command.

3. Partitioned Bulk Data Sections defined by `BEGIN SUPER` are used to
   define only one superelement each. Bulk Data commands which define
   superelements are ignored in partitioned Bulk Data Sections.
   Superelements specified by a `BEGIN SUPER` entry can be
   automatically attached to other superelements based on relative
   location of grid points. For connection to the downstream
   superelement, the global coordinate directions of the attachment
   grid points of the upstream superelement will be internally
   transformed to the global coordinate directions of the grid points
   of the downstream superelement. For displacement data recovery, the
   output will be in the original global coordinate directions.

4. The `BEGIN SUPER` or `BEGIN AUXMODEL` Bulk Data must lie between
   `BEGIN BULK` and `ENDDATA` entries.

                */
               class begin_bulk : public __base::entry {
               public:
                  begin_bulk(void);
                  std::ostream const &operator<<(std::ostream&) const;
               private:
                  std::ostream const &put(std::ostream&) const;
               };

            };
         }
      }
   }
}

#endif // _HEADER_H_

/*
  Local Variables:
  mode: c++
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../.. check -j8"
  coding: utf-8
  End:
 */
