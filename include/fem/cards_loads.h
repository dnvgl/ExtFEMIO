/**
   \file fem/cards_loads.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Load desribing cards for Sesam FEM files.

   Detailed description
*/

// ID: $Id$

#if !defined _FEM_CARDS_LOADS_H_
#define _FEM_CARDS_LOADS_H_

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

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

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_NFIELD;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ILREF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CODNAM;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_CODTXT;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_SET_NAME;
               dnvgl::extfem::fem::types::entry_type<std::string> static const _form_CONT;

               bool nlnam;
               long ncnam;
               long nltxt;
               long nctxt;

            public:

               /** Number of numeric data fields on this record before
                * text data (MAX = 1024).
                */
               long NFIELD;
               /** Internal load identification number. Legal range [1,
                   `NSET`], where `NSET` is number of loads which is
                   equeal to number of "Name and Description of a load"
                   records (`TDLOAD`). Two `TDLOAD` records may
                   not have identical load identification numbers
                   (`ILREF`).
               */
               long ILREF;
               /** Coded dimension of load name:

                     \f[
                       \mathtt{CODNAM} = \mathtt{NLNAM} * 100 + \mathtt{NCNAM}.
                     \f]

                   The inverse relation will then be

                     - `NLNAM` - number of physical records used for
                       storing of load name.

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

                     - `NLTXT` - number of physical records used for
                       storing of load description text. Legal range =
                       [0,5]

                       - = 0, no description text defined

                       - ≥ 1, number of physical records with
                         description text

                       `NLTXT` = integer part of (`CODTXT` / 100)


                     - `NCTXT` - number of characters per physical load
                       description text record. Legal range = [0,64]

                       `NCTXT` = remaindering of (`CODTXT` / 100)
               */
               long CODTXT;

               std::string SET_NAME;
               std::vector<std::string> CONT;

               tdload(std::list<std::string> const &);

               tdload(void);

               tdload(long const &NFIELD,
                      long const &ILREF,
                      long const &CODNAM,
                      long const &CODTXT,
                      std::string const &SET_NAME,
                      std::vector<std::string> const &CONT);

               tdload(long const &ILREF,
                      std::string const &SET_NAME,
                      std::vector<std::string> const &CONT={});

               tdload(long const &NFIELD,
                      long const &ILREF,
                      long const &CODNAM,
                      std::string const &SET_NAME);

               __base::card const &operator() (
                  long const &NFIELD,
                  long const &ILREF,
                  long const &CODNAM,
                  long const &CODTXT,
                  std::string const &SET_NAME,
                  std::vector<std::string> const &CONT);

               __base::card const &operator() (
                  long const &ILREF,
                  std::string const &SET_NAME,
                  std::vector<std::string> const &CONT={});

               __base::card const &operator() (
                  long const &NFIELD,
                  long const &ILREF,
                  long const &CODNAM,
                  std::string const &SET_NAME);

               dnvgl::extfem::fem::cards::types const
               card_type(void) const;

            protected:

               virtual std::ostream &put(std::ostream&) const;

               void read(const std::list<std::string>&);
            };

/// `BEUSLO`: Elements with Surface Loads
/**
## Format

|          |               |          |          |               |
| -------- | ------------- | -------- | -------- | ------------- |
| `BEUSLO` | `LLC`         | `LOTYP`  | `COMPLX` | `LAYER`       |
|          | `ELNO`        | `NDOF`   | `INTNO`  | `SIDE`        |
|          | `RLOAD1`      | `RLOAD2` | ...      | ...           |
|          | `RLOAD(NDOF)` | `ILOAD1` | ...      | `ILOAD(NDOF)` |

If phase shift is not specified, i.e. `COMPLX` = 0, the fields or
positions `ILOAD1`, `ILOAD2`, etc. are left out.

Normal pressure means that only one pressure component is specified
for each node, and this pressure component is acting normal to the
surface.

For volume elements a positive value means normal pressure directed
into the element. For shell elements, a positive value means normal
pressure in the local /z/-direction.
*/
            class beuslo : public __base::card {

            private:

               dnvgl::extfem::fem::types::card static const head;

               dnvgl::extfem::fem::types::entry_type<long> static const _form_LLC;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_LOTYP;
               dnvgl::extfem::fem::types::entry_type<bool> static const _form_COMPLX;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_LAYER;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_ELNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_NDOF;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_INTNO;
               dnvgl::extfem::fem::types::entry_type<long> static const _form_SIDE;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_RLOAD;
               dnvgl::extfem::fem::types::entry_type<double> static const _form_ILOAD;


            public:

               /** Local load case number (positive integer number).
                */
               long LLC;
               /** Load type.

                     - =1: normal pressure, conservative load

                     - =2: load given in component form, conservative
                         load

                     - =3: dummy hydro pressure, used to indicate the
                           direction of hydrostatic / hydrodynamic
                           pressure to be computed by a hydrodynamic
                           load program.

                     - =-1: normal pressure, non-conservative load

                     - =-2: load given in component form,
                            non-conservative load
               */
               long LOTYP;
               /** Phase shift definition.

                     - =0: no phase shift

                     - =1: phase shift
               */
               bool COMPLX;
               /** Layer number for elements with more than one layer.
                   If `LAYER` equals 0, the surface load will be
                   positioned in the shell layer (in opposition to a
                   stiffener layer). If more than one shell layer and
                   `LAYER` equals 0, the programs shall stop and give
                   an error message. For elements which are treated as
                   one layer in the load calculations (e.g. the
                   sandwich element in SESTRA), `LAYER` does not have
                   any meaning.
                */
               long LAYER;
               /** Internal element number (generated by the program).
                */
               long ELNO;
               /**

                   - If `LOTYP` = 1: number of nodes of the specified
                                     element side

                   - If `LOTYP` = 2: number of translational degrees
                                     of freedom of the specified
                                     element side

                   - If `LOTYP` = 3: `NDOF` = 1
                */
               long NDOF;
               /** Integration station reference number. Referring to
                   record `GELINT`. This reference is usually not used
                   (=0). It means that the program performing the load
                   calculation chooses integration points.
                */
               long INTNO;
               /** Side definition

                   For shell elements:

                     - =1: loads referred to element side where /z/=-1

                     - =2: loads referred to element side where /z/= 0

                     - =3: loads referred to element side where /z/= 1

                   For solid elements:

                     `SIDE` will be a six figures number for a
                     hexahedron, a five figures number for a prism and
                     a four figures number for a tetrahedron,
                     consisting of zeroes with 1 for the side with
                     load. For instance 000100 for a hexahedron means
                     load on side no. 4.
               */
               long SIDE;
               /** The real part of the load with respect to the /i/th
                   degree of freedom or /i/th node of the element
                   side.
                */
               std::vector<double> RLOADi;
               /** The imaginary part of the load with respect to the
                   /i/th degree of freedom or /i/th node of the
                   element side.

                   If `LOTYP`= 3, `RLOAD`= ±1.0 indicating which side
                   the element pressure comes from. (+1 indicates
                   shell element `SIDE`= 1 (/z/=-1), -1 indicates
                   shell element `SIDE`= 3 (/z/=1)). For solids when
                   `LOTYP` = 3, `RLOAD` must be +1.0.
                */
               std::vector<double> ILOADi;

               beuslo(void);

               beuslo(std::list<std::string> const &);

               beuslo(long const &LLC,
                      long const &LOTYP,
                      bool const &COMPLX,
                      long const &LAYER,
                      long const &ELNO,
                      long const &NDOF,
                      long const &INTNO,
                      long const &SIDE,
                      std::vector<double> const &RLOAD,
                      std::vector<double> const &ILOAD = {});

               beuslo(long const &LLC,
                      long const &LOTYP,
                      bool const &COMPLX,
                      long const &LAYER,
                      long const &ELNO,
                      long const &INTNO,
                      long const &SIDE,
                      std::vector<double> const &RLOAD,
                      std::vector<double> const &ILOAD = {});

               beuslo(long const &LLC,
                      long const &LOTYP,
                      long const &LAYER,
                      long const &ELNO,
                      long const &NDOF,
                      long const &INTNO,
                      long const &SIDE,
                      std::vector<double> const &RLOAD,
                      std::vector<double> const &ILOAD = {});

               beuslo(long const &LLC,
                      long const &LOTYP,
                      long const &LAYER,
                      long const &ELNO,
                      long const &INTNO,
                      long const &SIDE,
                      std::vector<double> const &RLOAD,
                      std::vector<double> const &ILOAD = {});

               dnvgl::extfem::fem::cards::types const
               card_type(void) const;

            protected:

               virtual std::ostream &put(std::ostream&) const;

               void read(const std::list<std::string>&);
            };
         }
      }
   }
}

#endif // _FEM_CARDS_LOADS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
