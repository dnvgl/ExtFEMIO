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

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace header {
            namespace __base {
               class entry {

               public:

                  entry () {};

                  virtual const std::ostream& operator<<(std::ostream&) const = 0;
               };
            }
            namespace exec {

/**
# `SOL`: Execute a Solution Sequence

Specifies the solution sequence or main subDMAP to be executed.

## Format:

\f$
SOL \left\{
\begin{array}{x}
n\\
subDMAP-name
\end{array}
\right\}
[ SOLIN = obj-DBset NOEXE ] \f$

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
                  friend std::ostream&
                  operator<<(std::ostream &, const sol&);

               private:

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
                  cend();
                  const std::ostream& operator<<(std::ostream&) const;
                  friend std::ostream&
                  operator<<(std::ostream &, const cend&);
               };
            };

            namespace case_ {
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
                  friend std::ostream&
                  operator<<(std::ostream &, const title&);
               };

/**

# `ECHO`: Bulk Data Echo Request

Controls echo (i.e., printout) of the Bulk Data.

## Format:

\f$ \text{ECHO} = \left\{
\begin{array}{c}
\text{SORT} \left(\left[\text{EXCEPT}\right\]\text{cdni}, ...\right)\right]\\
\text{UNSORT}\\
\text{BOTH}\\
\text{NONE}
\end{array}, \text{PUNCH}\left[\left(
\begin{array}{c}
\text{SORT}\\
\text{BOTH}\\
\text{NEWBULK}
\end{array}, \right)\right]\right\}
\f$

## Examples:

ECHO=NOSORT
ECHO=BOTH
ECHO=PUNCH, SORT (MAT1, PARAM)
ECHO=SORT (EXCEPT DMI, DMIG)
ECHO=BOTH,PUNCH,FILE
Describer

Meaning

UNSORT

The unsorted Bulk Data will be printed. If SORT is not also
specified, the sorted Bulk Data will not be printed.

SORT

The sorted (arranged in alphanumeric order) Bulk Data will be
printed.

cdni,...

Bulk Data entry names to be included, or excluded by EXCEPT, in
the sorted echo printout. The PUNCH file is not affected by cdni.

EXCEPT

Exclude cdni Bulk Data entries from sorted echo printout. See
Remark 6.

BOTH

Both sorted and unsorted Bulk Data will be printed. This is
equivalent to ECHO=SORT, UNSORT.

NONE

Neither sorted nor unsorted Bulk Data will be printed.

PUNCH

The entire Bulk Data will be written to the punch file.

FILE

The entire Bulk Data Echo will be written to the separate file with a
default suffix of .BECHO in *.f06 form. User-defined filename must
be specified in ASSIGN statement.

NEWBULK

In SOL 200, a comlete unsorted Bulk Data file is written to the punch
file with updated design model entries.

4A
4B
CASE

OUTPUT

4C
X-Y PLOT

5
PARAM

6
CODES

7
SETS

8
BULK

252

ECHO
Bulk Data Echo Request

Remarks:

1
nastran

2
FMS

3
EXEC

4A
4B
CASE

OUTPUT

4C
X-Y PLOT

5
PARAM

6
CODES

7
SETS

8
BULK

1. If no ECHO command appears, a sorted Bulk Data will be printed.
2. Comments will appear at the front of the sorted file if ECHO=PUNCH.
3. Portions of the unsorted Bulk Data can be selectively echoed by including the
commands ECHOON and ECHOOFF at various places within the Bulk Data.
ECHOOFF stops the unsorted echo until an ECHOON command is
encountered. Many such pairs of commands may be used. The ECHOON
and ECHOOFF command may be used in the Executive and Case Control
Sections; however, ECHOOF should not be the first entry and continuation
entries are not handled correctly.
4. If the SORT (cdni,...) is specified in a restart in SOLs 101 through 200, then
the continuation entries will not be printed.
5. If the SORT (cdni,...) describer is used, then it must appear as the last
describer, as in the example above.
6. If EXCEPT is specified then it must be specified before all cdni. All Bulk Data
entry types will be listed except those given for cdn1, cdn2, etc. If EXCEPT is
not specified, then only those Bulk Data entry types listed under cdn1, cdn2,
etc. will be listed.

*/
               class echo : public __base::entry {
               public:
                  std::string oper;
                  echo(std::string const& ="NONE");
                  const std::ostream& operator<<(std::ostream&) const;
                  friend std::ostream&
                  operator<<(std::ostream &, const echo&);
               };

/**
# `SUBCASE`: Subcase Delimiter

Delimits and identifies a subcase.

## Format:

SUBCASE=n

## Example:

SUBCASE=101

## Remarks:

1. The subcase identification number, n, must be greater than all
   previous subcase identification numbers.

2. Plot requests and RANDPS requests refer to n.

3. See the `MODES` command for use of this command in normal modes
   analysis.

4. If a comment follows n, then the first few characters of the
   comment will appear in the subcase label in the upper right-hand
   corner of the output.
*/
               class subcase : public __base::entry {
               public:
                  /** Subcase identification number. (Integer>0)
                   */
                  long n;

                  subcase(long const&);
                  const std::ostream& operator<<(std::ostream&) const;
                  friend std::ostream&
                  operator<<(std::ostream &, const subcase&);
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
