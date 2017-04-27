/**
  \file fem/cards_indent.h
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2017 by DNV GL SE
  \brief Identification data for Superelements and Text Data.

  Detailed description
*/

// ID: $Id$

#pragma once

#ifndef _FEM_CARDS_INDENT_H_
#define _FEM_CARDS_INDENT_H_

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace cards {
/// `DATE`: Date and Program Information
/**
   ## Format

   |         |        |           |         |         |
   | ------- | ------ | --------- | ------- | ------- |
   | `DATE`  | `TYPE` | `SUBTYPE` | `NRECS` | `NBYTE` |
   |         | \<text lines\>                   | | | |
   |         | \<text lines\>                   | | | |

   The identifier is used to transfer date and program information on the
   Interface File.

   The following NRECS records must be read in A format, 72 characters
   per record.

   Example of format of `DATE` record as used in SESAM:

   ~~~{txt}
   DATE      0.100000000e+01 0.000000000e+00 0.400000000e+01 0.72000000E+02
   DATE:     23-MAY-86           TIME:         13:53:03
   PROGRAM:  SESAM WALOCO        VERSION:      5.1-0 15-MAY-86
   COMPUTER: VAX VMS V4.3        INSTALLATION: VERITEC
   USERID:   999XXXX             ACCOUNT:      ZZZZZZZ

   ------------------------------------------------------------------------
   123456789.123456789.123456789.123456789.123456789.123456789.123456789.12
   1         2         3         4         5         6         7
   ------------------------------------------------------------------------
   ~~~
*/
                class date : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_TYPE;
                    fem::types::entry_type<long>
                    static const _form_SUBTYPE;
                    fem::types::entry_type<long>
                    static const _form_NRECS;
                    fem::types::entry_type<long>
                    static const _form_NBYTE;
                    fem::types::entry_type<std::string>
                    static const _form_CONT;

                public:

/** Value giving information on how to use this text.

      - = 1 Text concerning current superelement.

      - = 2 Text concerning children of current superelement (not
        implemented).
                    */
                    long TYPE;
/**
     - = 0 If current superelement(TYPE = 1).

     - > 0 Subelement no. referring to the current superelement(only
       if TYPE = 2).
*/
                    long SUBTYPE;
/** Number of records to be read in A-format, `NRECS` ≥ 1.
 */
                    long NRECS;
/** Number of significant bytes on the text records, 1 ≤
    `NBYTE` ≤ 72.
*/
                    long NBYTE;
/** Text lines

    The eight first bytes on the text records shall be filled with
    blanks.
*/
                    std::vector<std::string> CONT;

                    date(std::vector<std::string> const&, size_t const);

                    date();

                    date(long const TYPE, long const SUBTYPE,
                         long const NRECS, long const NBYTE,
                         std::vector<std::string> const &CONT);

                    date(long const TYPE, long const SUBTYPE,
                         std::vector<std::string> const &CONT);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `IDENT`: Identification of Superelements
/**
   ## Format

   |         |          |          |          |   |
   | ------- | -------- | -------- | -------- | - |
   | `IDENT` | `SLEVEL` | `SELTYP` | `SELMOD` |   |
*/
                class ident : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_SLEVEL;
                    fem::types::entry_type<long>
                    static const _form_SELTYP;
                    fem::types::entry_type<long>
                    static const _form_SELMOD;

                public:

                    enum class mod_type{DIM_2D=2, DIM_3D=3, INVALID=-1};

/** Superelement level.

    The level of a superelement is defined as the highest level number
    among its subelements plus 1.(Basic elements, i.e. beams, shells,
    springs, etc. have level zero.)
*/
                    long SLEVEL;
/** Superelement type number.
 */
                    long SELTYP;
/** Superelement model dimension

      - = 2,      2-dimensional model

      - = 0 or 3, 3-dimensional model.
*/
                    mod_type SELMOD;

                    ident(std::vector<std::string> const&, size_t const);

                    ident();

                    ident(long const SLEVEL, long const SELTYP,
                          mod_type const SELMOD);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `IEND`: End of a Superelement
/**
   ## Format

   |         |        |   |   |   |
   | ------- | ------ | - | - | - |
   | `IEND`  | `CONT` |   |   |   |

   Defines end of a superelement.
*/
                class iend : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_CONT;

                public:

/** Superelement level.

      - = 0(Default). This is also end of the file.

      - = 1 The superelements are concatenated on one file. More
        superelements follows.

      - = 2 Last superelement in a structure for a concatenated file.
*/
                    long CONT;

                    iend(std::vector<std::string> const&, size_t const);

                    iend();

                    explicit iend(long const CONT);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `TDSETNAM`: Name and Description of a set(group)
/**
   ## Format

   |            |          |         |          |          |
   | ---------- | -------- | ------- | -------- | -------- |
   | `TDSETNAM` | `NFIELD` | `ISREF` | `CODNAM` | `CODTXT` |
   |            | \<set name\>                       | | | |
   |            | \<text line\>                      | | | |
   |            | ...                                | | | |
   |            | \<text line\>                      | | | |

   This record together with the set of nodes or elements record(s)
   (`GSETMEMB`) constitutes the set(group) datatype.
*/
                class tdsetnam : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_NFIELD;
                    fem::types::entry_type<long>
                    static const _form_ISREF;
                    fem::types::entry_type<long>
                    static const _form_CODNAM;
                    fem::types::entry_type<long>
                    static const _form_CODTXT;
                    fem::types::entry_type<std::string>
                    static const _form_SET_NAME;
                    fem::types::entry_type<std::string>
                    static const _form_CONT;

                    bool nlnam;
                    long ncnam;
                    long nltxt;
                    long nctxt;

                public:

/** Number of numeric data fields on this record before text data (MAX
    = 1024).
*/
                    long NFIELD;
/** Internal set identification number. Legal range [1, `NSET`], where
    `NSET` is number of sets which is equeal to number of "Name and
    Description of a set" records(`TDSETNAM`). Two `TDSETNAM` records
    may not have identical set identification numbers (`ISREF`).
*/
                    long ISREF;
/** Coded dimension of set name:

      \f[
      \mathtt{CODNAM} = \mathtt{NLNAM} * 100 + \mathtt{NCNAM}.
      \f]

    The inverse relation will then be

      - `NLNAM` - number of physical records used for storing of set
        name.

        Legal range = [0,1]

          - = 0, no name defined

          - = 1, name is defined

        `NLNAM` = integer part of(`CODNAM` / 100)

      - `NCNAM` - number of characters in set name.

        Legal range = [0,64]

        `NCNAM` = remaindering of(`CODNAM` / 100)
*/
                    long CODNAM;
/** Coded dimension of set description text:

      \f[
      \mathtt{CODTXT} = \mathtt{NLTXT} * 100 + \mathtt{NCTXT}.
      \f]

    The inverse relation will then be:

      - `NLTXT` - number of physical records used for storing of set
        description text. Legal range = [0,5]

          - = 0, no description text defined

          - ≥ 1, number of physical records with description text

        `NLTXT` = integer part of(`CODTXT` / 100)

      - `NCTXT` - number of characters per physical set description
        text record. Legal range = [0,64]

        `NCTXT` = remaindering of(`CODTXT` / 100)
*/
                    long CODTXT;

                    std::string SET_NAME;
                    std::vector<std::string> CONT;

                    tdsetnam(std::vector<std::string> const&, size_t const);

                    tdsetnam();

                    tdsetnam(long const NFIELD,
                             long const ISREF,
                             long const CODNAM,
                             long const CODTXT,
                             std::string const &SET_NAME,
                             std::vector<std::string> const &CONT);

                    tdsetnam(long const ISREF,
                             std::string const &SET_NAME,
                             std::vector<std::string> const &CONT);

                    tdsetnam(long const NFIELD,
                             long const ISREF,
                             long const CODNAM,
                             std::string const &SET_NAME);

                    tdsetnam(long const ISREF,
                             std::string const &SET_NAME);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `TDSUPNAM`: Name and Description of a Super-Element
/**
   ## Format

   |            |          |         |          |          |
   | ---------- | -------- | ------- | -------- | -------- |
   | `TDSUPNAM` | `NFIELD` | `IHREF` | `CODNAM` | `CODTXT` |
   |            | \<set name\  >                     | | | |
   |            | \<text line\>                      | | | |
   |            | ...                                | | | |
   |            | \<text line\>                      | | | |

   This record will associate a name with a super-element in the
   super-element hierarchy.
*/
                class tdsupnam : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_NFIELD;
                    fem::types::entry_type<long>
                    static const _form_IHREF;
                    fem::types::entry_type<long>
                    static const _form_CODNAM;
                    fem::types::entry_type<long>
                    static const _form_CODTXT;
                    fem::types::entry_type<std::string>
                    static const _form_SUP_NAME;
                    fem::types::entry_type<std::string>
                    static const _form_CONT;

                    bool nlnam;
                    long ncnam;
                    long nltxt;
                    long nctxt;

                public:

/** Number of numeric data fields on this record before text data(MAX
    = 1024).
*/
                    long NFIELD;
/** Hierarchy reference number. Number 1 is reserved for the top level
    superelement. In SESAM, PRESEL (super-element pre-processor) is
    writing the HIERARCH records and defining a unique number (IHREF)
    for each appearance of the differenet superelements.

    \image latex tdsupnam.eps "Superelement hierarchy with 3 levels."
    \image html tdsupnam.svg "Superelement hierarchy with 3 levels."
*/
                    long IHREF;
/** Coded dimension of set name:

      \f[
      \mathtt{CODNAM} = \mathtt{NLNAM} * 100 + \mathtt{NCNAM}.
      \f]

    The inverse relation will then be

      - `NLNAM` - number of physical records used for storing of set
        name.

        Legal range = [0,1]

          - = 0, no name defined

          - = 1, name is defined

        `NLNAM` = integer part of(`CODNAM` / 100)

      - `NCNAM` - number of characters in set name.

        Legal range = [0,64]

        `NCNAM` = remaindering of(`CODNAM` / 100)
*/
                    long CODNAM;
/** Coded dimension of set description text:

      \f[
      \mathtt{CODTXT} = \mathtt{NLTXT} * 100 + \mathtt{NCTXT}.
      \f]

    The inverse relation will then be:

      - `NLTXT` - number of physical records used for storing of set
        description text.

        Legal range = [0,5]

          - = 0, no description text defined

          - ≥ 1, number of physical records with description text

        `NLTXT` = integer part of(`CODTXT` / 100)

      - `NCTXT` - number of characters per physical set description
        text record. Legal range = [0,64]

        `NCTXT` = remaindering of(`CODTXT` / 100)
*/
                    long CODTXT;

                    std::string SUP_NAME;
                    std::vector<std::string> CONT;

                    tdsupnam(std::vector<std::string> const&, size_t const);

                    tdsupnam();

                    tdsupnam(long const NFIELD,
                             long const IHREF,
                             long const CODNAM,
                             long const CODTXT,
                             std::string const &SUP_NAME,
                             std::vector<std::string> const &CONT);

                    tdsupnam(long const IHREF,
                             std::string const &SUP_NAME,
                             std::vector<std::string> const &CONT);

                    tdsupnam(long const NFIELD,
                             long const IHREF,
                             long const CODNAM,
                             std::string const &SUP_NAME);

                    tdsupnam(long const IHREF,
                             std::string const &SUP_NAME);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

/// `TEXT`: User supplied Text
/**
   ## Format

   |         |        |           |         |         |
   | ------- | ------ | --------- | ------- | ------- |
   | `TEXT`  | `TYPE` | `SUBTYPE` | `NRECS` | `NBYTE` |
   |         | \<text lines\>                   | | | |

   The identifier is used to transfer text-strings on the interface file.
   The following NRECS records must be read in A-format, 72 characters
   per record.
*/
                class text : public __base::card {

                private:

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_TYPE;
                    fem::types::entry_type<long>
                    static const _form_SUBTYPE;
                    fem::types::entry_type<long>
                    static const _form_NRECS;
                    fem::types::entry_type<long>
                    static const _form_NBYTE;
                    fem::types::entry_type<std::string>
                    static const _form_CONT;

                public:

/** Value giving information of how to use this text

      - = 1 Texts describing this analysis/global text

      - = 2 Texts concerning current superelement

      - = 3 Text concerning specific load cases

      - ≥ 4 The meaning of text to be mutually agreed on by
        preprosessor and analysis program
*/
                    long TYPE;
/** Value giving additional information to `TYPE`

    Example: For `TYPE` = 3, `SUBTYPE` gives load case number
*/
                    long SUBTYPE;
/** Number of records following to be read in A-format. `NRECS` ≥ 1
 */
                    long NRECS;
/** Number of significant bytes(characters) on the following `NRECS`
    records. 1 ≤ `NBYTE` ≤ 72
*/
                    long NBYTE;
/** Text lines

    The eight first bytes on the text records shall be filled with
    blanks.
*/
                    std::vector<std::string> CONT;

                    text(std::vector<std::string> const&, size_t const);

                    text();

                    text(long const TYPE, long const SUBTYPE,
                         long const NRECS, long const NBYTE,
                         std::vector<std::string> const &CONT);

                    text(long const TYPE, long const SUBTYPE,
                         std::vector<std::string> const &CONT);

                    using card::operator();

                    card const &operator()(
                        long const TYPE, long const SUBTYPE,
                        long const NRECS, long const NBYTE,
                        std::vector<std::string> const &CONT);

                    card const &operator()(
                        long const TYPE, long const SUBTYPE,
                        std::vector<std::string> const &CONT);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        std::vector<std::string> const&, size_t const) override;
                };

            /// `TDLOAD`: Name of Load
/**
   ## Format

   |          |          |         |          |          |
   | -------- | -------- | ------- | -------- | -------- |
   | `TDLOAD` | `NFIELD` | `ILREF` | `CODNAM` | `CODTXT` |
   |          | \<load name\>                      | | | |
   |          | \<text line\>                      | | | |
   |          | ...                                | | | |
   |          | \<text line\>                      | | | |

*/
                class tdload : public __base::card {

                    fem::types::card static const head;

                    fem::types::entry_type<long>
                    static const _form_NFIELD;
                    fem::types::entry_type<long>
                    static const _form_ILREF;
                    fem::types::entry_type<long>
                    static const _form_CODNAM;
                    fem::types::entry_type<long>
                    static const _form_CODTXT;
                    fem::types::entry_type<std::string>
                    static const _form_SET_NAME;
                    fem::types::entry_type<std::string>
                    static const _form_CONT;

                    bool nlnam;
                    long ncnam;
                    long nltxt;
                    long nctxt;

                public:

/** Number of numeric data fields on this record before text data (MAX
    = 1024).
*/
                    long NFIELD;
/** Internal load identification number. Legal range [1, `NSET`],
    where `NSET` is number of loads which is equeal to number of "Name
    and Description of a load" records (`TDLOAD`). Two `TDLOAD`
    records may not have identical load identification numbers
    (`ILREF`).
*/
                    long ILREF;
/** Coded dimension of load name:

      \f[
      \mathtt{CODNAM} = \mathtt{NLNAM} * 100 + \mathtt{NCNAM}.
      \f]

    The inverse relation will then be

      - `NLNAM` - number of physical records used for storing of load
        name.

        Legal range = [0,1]

          - = 0, no name defined

          - = 1, name is defined

        `NLNAM` = integer part of (`CODNAM` / 100)

          - `NCNAM` - number of characters in load name.

          Legal range = [0,64]

          `NCNAM` = remaindering of (`CODNAM` / 100)
*/
                    long CODNAM;
/** Coded dimension of load description text:

      \f[
      \mathtt{CODTXT} = \mathtt{NLTXT} * 100 + \mathtt{NCTXT}.
      \f]

    The inverse relation will then be:

    - `NLTXT` - number of physical records used for storing of load
      description text. 

      Legal range = [0,5]

        - = 0, no description text defined

        - ≥ 1, number of physical records with description text

      `NLTXT` = integer part of (`CODTXT` / 100)

    - `NCTXT` - number of characters per physical load description
      text record. 

      Legal range = [0,64]

      `NCTXT` = remaindering of (`CODTXT` / 100)
                    */
                    long CODTXT;

                    std::string SET_NAME;
                    std::vector<std::string> CONT;

                    tdload(std::vector<std::string> const&, size_t const);

                    tdload();

                    tdload(
                        long const NFIELD, long const ILREF, long const CODNAM,
                        long const CODTXT, std::string const &SET_NAME,
                        std::vector<std::string> const &CONT);

                    tdload(
                        long const ILREF, std::string const &SET_NAME,
                        std::vector<std::string> const &CONT={});

                    tdload(
                        long const NFIELD, long const ILREF, long const CODNAM,
                        std::string const &SET_NAME);

                    using card::operator();

                    card const &operator() (
                        long const NFIELD, long const ILREF, long const CODNAM,
                        long const CODTXT, std::string const &SET_NAME,
                        std::vector<std::string> const &CONT);

                    card const &operator() (
                        long const ILREF, std::string const &SET_NAME,
                        std::vector<std::string> const &CONT={});

                    card const &operator() (
                        long const NFIELD, long const ILREF, long const CODNAM,
                        std::string const &SET_NAME);

                    types
                    card_type() const override;

                protected:

                    std::ostream &put(std::ostream&) const override;

                    void read(
                        const std::vector<std::string>&, size_t const) override;
                };
            }
        }
    }
}

#endif // _FEM_CARDS_INDENT_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test""
// coding: utf-8
// End:
