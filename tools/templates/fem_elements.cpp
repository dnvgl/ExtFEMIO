/**
   \file fem/fem_elements.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for FEm elements.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id: fem_elements.cpp 437 2016-09-01 15:04:40Z berhol $";
}

#include <memory>

#include "my_c++14.h"
#include "fem/cards.h"
#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace elements {
            using namespace dnvgl::extfem::fem::cards;

            void dispatch(
               std::unique_ptr<__base::elem> &res, const cards::gelmnt1 *data) {

               switch (data->ELTYP) {
{% for e in enum %}               case {{ e[0]|upper() }}: res = std::make_unique<{{ e[0]|lower() }}>(data); break;
{% endfor %}               case UNDEFINED: res = std::make_unique<undef>(); break;
               case INVALID: throw errors::parse_error(
                  "GELMNT1", "invalid element type"); break;
               };
            }

            std::string name_elem(el_types const &type) {
               switch (type) {
{% for e in enum %}               case {{ e[0]|upper() }}: return "{{ e[0]|upper() }}";
{% endfor %}               case UNDEFINED: return "UNDEFINED";
               case INVALID: return "INVALID";
               }
               return "";
            };

            undef::undef (void) {}

            long undef::nnodes(void) const {return -1;}

            el_types undef::get_type(void) const {return UNDEFINED;}

            namespace __base {

               elem::elem(void) :
                  eleno(-1), elident(-1), el_add(-1), nodes({}),
                  matref(-1), add_no(-1), intno(-1), mass_intno(-1),
                  i_strain_ref(-1), i_stress_ref(-1),
                  strpoint_ref(-1), section({}),
                  fixations({}), eccentrities({}), csys({}) {}

               elem::elem(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  eleno(eleno), elident(elident), el_add(el_add),
                  nodes(nodes), matref(matref), add_no(add_no),
                  intno(intno), mass_intno(mass_intno),
                  i_strain_ref(i_strain_ref),
                  i_stress_ref(i_stress_ref),
                  strpoint_ref(strpoint_ref),
                  section(section), fixations(fixations),
                  eccentrities(eccentrities), csys(csys) {}

               elem::elem(cards::gelmnt1 const *data) :
                  matref(-1), add_no(0),
                  intno(0), mass_intno(0), i_strain_ref(0),
                  i_stress_ref(0), strpoint_ref(0),
                  section(), fixations(), eccentrities(),
                  csys() {
                  this->add(data);
               }

               elem::elem(cards::gelref1 const *data) :
                  eleno(0), el_add(0), nodes() {
                  this->add(data);
               }

               elem::elem(elem const *data) {
                  this->eleno = data->eleno;
                  this->elident = data->elident;
                  this->el_add = data->el_add;
                  this->nodes = data->nodes;
                  this->matref = data->matref;
                  this->add_no = data->add_no;
                  this->intno = data->intno;
                  this->mass_intno = data->mass_intno;
                  this->i_strain_ref = data->i_strain_ref;
                  this->i_stress_ref = data->i_stress_ref;
                  this->strpoint_ref = data->strpoint_ref;
                  this->section = data->section;
                  this->fixations = data->fixations;
                  this->eccentrities = data->eccentrities;
                  this->csys = data->csys;
               }

               void elem::add(cards::gelmnt1 const *data) {
                  this->eleno = data->ELNOX;
                  this->elident = data->ELNO;
                  this->el_add = data->ELTYAD;
                  this->nodes = data->NODIN;
               }

               void elem::add(cards::gelref1 const *data) {
                  this->elident = data->ELNO;
                  this->matref = data->MATNO;
                  this->add_no = data->ADDNO;
                  this->intno = data->INTNO;
                  this->mass_intno = data->MINTNO;
                  this->i_strain_ref = data->STRANO;
                  this->i_stress_ref = data->STRENO;
                  this->strpoint_ref = data->STREPONO;
                  if (data->GEONO_OPT == -1)
                     this->section = data->GEONO;
                  else if (data->GEONO_OPT != 0)
                     this->section.push_back(data->GEONO_OPT);
                  if (data->FIXNO_OPT == -1)
                     this->fixations = data->FIXNO;
                  else if (data->FIXNO_OPT != 0)
                     this->fixations.push_back(data->FIXNO_OPT);
                  if (data->ECCNO_OPT == -1)
                     this->eccentrities = data->ECCNO;
                  else if (data->ECCNO_OPT != 0)
                     this->eccentrities.push_back(data->ECCNO_OPT);
                  if (data->TRANSNO_OPT == -1)
                     this->csys = data->TRANSNO;
                  else if (data->TRANSNO_OPT != 0)
                     this->csys.push_back(data->TRANSNO_OPT);
               }

               cards::gelmnt1 elem::gelmnt1(void) const {
                  return cards::gelmnt1(this->eleno,   // ELNOX
                                        this->elident, // ELNO
                                        this->get_type(),
                                        this->el_add,  // ELTYAD
                                        this->nodes);  // NODIN
               }

               cards::gelref1 elem::gelref1(void) const {
                  long geono_opt;
                  long fixno_opt;
                  long eccno_opt;
                  long transno_opt;

                  if (this->section.size() == 0) {
                     geono_opt = 0;
                  } else if (this->section.size() == 1) {
                     geono_opt = this->section[0];
                  } else {
                     geono_opt = -1;
                  }
                  if (this->fixations.size() == 0) {
                     fixno_opt = 0;
                  } else if (this->fixations.size() == 1) {
                     fixno_opt = this->fixations[0];
                  } else {
                     fixno_opt = -1;
                  }
                  if (this->eccentrities.size() == 0) {
                     eccno_opt = 0;
                  } else if (this->eccentrities.size() == 1) {
                     eccno_opt = this->eccentrities[0];
                  } else {
                     eccno_opt = -1;
                  }
                  if (this->csys.size() == 0) {
                     transno_opt = 0;
                  } else if (this->csys.size() == 1) {
                     transno_opt = this->csys[0];
                  } else {
                     transno_opt = -1;
                  }

                  return cards::gelref1(
                     this->elident,      // ELNO
                     this->matref,       // MATNO
                     this->add_no,       // ADDNO
                     this->intno,        // INTNO;
                     this->mass_intno,   // MINTNO;
                     this->i_strain_ref, // STRANO;
                     this->i_stress_ref, // STRENO;
                     this->strpoint_ref, // STREPONO;
                     geono_opt,
                     fixno_opt,
                     eccno_opt,
                     transno_opt,
                     this->section.size() > 1 ? this->section : std::vector<long>({}),
                     this->fixations.size() > 1 ? this->fixations : std::vector<long>({}),
                     this->eccentrities.size() > 1 ? this->eccentrities : std::vector<long>({}),
                     this->csys.size() > 1 ? this->csys : std::vector<long>({}));
               }
            }

            undef::undef(const cards::gelref1 *data) :
               __base::elem(data) {}

            namespace __base {
               std::ostream &operator<<(std::ostream &os, __base::elem const &data) {
                  if (data.elident < 0) return os;
                  os << data.gelmnt1();
                  os << data.gelref1();
                  return os;
               }
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
