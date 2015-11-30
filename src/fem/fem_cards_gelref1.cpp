/**
   \file fem/fem_cards_gelref1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM GELREF1 cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <memory>

#include "fem/cards.h"
#include "fem/types.h"
#include "fem/errors.h"

#ifdef _TYPE
#undef _TYPE
#endif

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card gelref1::head("GELREF1");

            const entry_type<long> gelref1::_ELNO("ELNO");
            const entry_type<long> gelref1::_MATNO("MATNO");
            const entry_type<long> gelref1::_ADDNO("ADDNO");
            const entry_type<long> gelref1::_INTNO("INTNO");
            const entry_type<long> gelref1::_MINTNO("MINTNO");
            const entry_type<long> gelref1::_STRANO("STRANO");
            const entry_type<long> gelref1::_STRENO("STRENO");
            const entry_type<long> gelref1::_STREPONO("STREPONO");
            const entry_type<long> gelref1::_GEONO_OPT("GEONO_OPT");
            const entry_type<long> gelref1::_FIXNO_OPT("FIXNO_OPT");
            const entry_type<long> gelref1::_ECCNO_OPT("ECCNO_OPT");
            const entry_type<long> gelref1::_TRANSNO_OPT("TRANSNO_OPT");
            const entry_type<long> gelref1::_GEONO("GEONO");
            const entry_type<long> gelref1::_FIXNO("FIXNO");
            const entry_type<long> gelref1::_ECCNO("ECCNO");
            const entry_type<long> gelref1::_TRANSNO("TRANSNO");

            gelref1::gelref1(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ::std::deque<::std::string> node_vals;
               entry_type<long> lval("lval");

               long tmp, nvals = 0, ind_offset = 0;
               ldiv_t divmod;

               ++pos;
               ELNO = _ELNO(*(pos++));
               MATNO = _MATNO(*(pos++));
               ADDNO = _ADDNO(*(pos++));
               INTNO = _INTNO(*(pos++));
               MINTNO = _MINTNO(*(pos++));
               STRANO = _STRANO(*(pos++));
               STRENO = _STRENO(*(pos++));
               STREPONO = _STREPONO(*(pos++));
               GEONO_OPT = _GEONO_OPT(*(pos++));
               if (GEONO_OPT == -1) nvals += 1;
               FIXNO_OPT = _FIXNO_OPT(*(pos++));
               if (FIXNO_OPT == -1) nvals += 1;
               ECCNO_OPT = _ECCNO_OPT(*(pos++));
               if (ECCNO_OPT == -1) nvals += 1;
               TRANSNO_OPT = _TRANSNO_OPT(*(pos++));
               if (TRANSNO_OPT == -1) nvals += 1;

               while (pos != inp.end()) {
                  tmp = lval(*pos);
                  if (tmp == 0) break;
                  node_vals.push_back(*(pos++));
               }
               if (node_vals.size() != 0) {
                  divmod = ldiv((long)node_vals.size(), nvals);
                  if (divmod.rem != 0)
                     throw ::dnvgl::extfem::fem::errors::parse_error(
                        "GELREF1", "Number of node values is not multiple "
                        "of 4.");

                  if (GEONO_OPT == -1) {
                     for (long i=0; i < divmod.quot; i++)
                        GEONO.push_back(_GEONO(node_vals[i]));
                     ind_offset = nvals;
                  }
                  if (FIXNO_OPT == -1) {
                     for (long i=0; i < divmod.quot; i++)
                        FIXNO.push_back(_FIXNO(node_vals[i+ind_offset]));
                     ind_offset += nvals;
                  }
                  if (ECCNO_OPT == -1) {
                     for (long i=0; i < divmod.quot; i++)
                        ECCNO.push_back(_ECCNO(node_vals[i+ind_offset]));
                     ind_offset += nvals;
                  }
                  if (TRANSNO_OPT == -1) {
                     for (long i=0; i < divmod.quot; i++)
                        TRANSNO.push_back(_TRANSNO(node_vals[i+ind_offset]));
                     ind_offset += nvals;
                  }
               }
            }

            gelref1::gelref1(
               const long *ELNO, const long *MATNO,
               const long *ADDNO, const long *INTNO,
               const long *MINTNO, const long *STRANO,
               const long *STRENO, const long *STREPONO,
               const long *GEONO_OPT, const long *FIXNO_OPT,
               const long *ECCNO_OPT, const long *TRANSNO_OPT,
               const ::std::deque<long> *GEONO,
               const ::std::deque<long> *FIXNO,
               const ::std::deque<long> *ECCNO,
               const ::std::deque<long> *TRANSNO) :
               card(),
               ELNO(*ELNO), MATNO(*MATNO), ADDNO(*ADDNO), INTNO(*INTNO),
               MINTNO(*MINTNO), STRANO(*STRANO), STRENO(*STRENO),
               STREPONO(*STREPONO), GEONO_OPT(*GEONO_OPT),
               FIXNO_OPT(*FIXNO_OPT), ECCNO_OPT(*ECCNO_OPT),
               TRANSNO_OPT(*TRANSNO_OPT) {

               size_t lmax = 0, lmin = 0;
               bool min_max_set = false;

               if (GEONO && GEONO->size()) {
                  min_max_set = true;
                  lmin = lmax = GEONO->size();
                  ::std::copy(GEONO->begin(), GEONO->end(),
                              ::std::back_inserter(this->GEONO));
               }
               if (FIXNO && FIXNO->size()) {
                  if (min_max_set) {
                     lmin = lmin ? FIXNO->size() > lmin : FIXNO->size();
                     lmax = lmax ? FIXNO->size() < lmax : FIXNO->size();
                  } else {
                     min_max_set = true;
                     lmin = lmax = FIXNO->size();
                  }
                  ::std::copy(FIXNO->begin(), FIXNO->end(),
                              ::std::back_inserter(this->FIXNO));
               }
               if (ECCNO && ECCNO->size()) {
                  if (min_max_set) {
                     lmin = lmin ? ECCNO->size() > lmin : ECCNO->size();
                     lmax = lmax ? ECCNO->size() < lmax : ECCNO->size();
                  } else {
                     min_max_set = true;
                     lmin = lmax = ECCNO->size();
                  }
                  ::std::copy(ECCNO->begin(), ECCNO->end(),
                              ::std::back_inserter(this->ECCNO));
               }
               if (TRANSNO && TRANSNO->size()) {
                  if (min_max_set) {
                     lmin = lmin ? TRANSNO->size() > lmin : TRANSNO->size();
                     lmax = lmax ? TRANSNO->size() < lmax : TRANSNO->size();
                  } else {
                     min_max_set = true;
                     lmin = lmax = TRANSNO->size();
                  }
                  ::std::copy(TRANSNO->begin(), TRANSNO->end(),
                              ::std::back_inserter(this->TRANSNO));
               }

               if (lmin != lmax) {
                  throw ::dnvgl::extfem::fem::errors::usage_error(
                     "GELREF1",
                     "GEONO, FIXNO, ECCNO, and TRANSNO if not empty, have "
                     "to be of same size");
               }
            }

            const ::dnvgl::extfem::fem::cards::types
            gelref1::card_type(void) const { return GELREF1; }

            ::std::ostream&
            operator<< (::std::ostream &os, const gelref1 &card) {

               os << gelref1::head.format()
                  << card._ELNO.format(card.ELNO)
                  << card._MATNO.format(card.MATNO)
                  << card._ADDNO.format(card.ADDNO)
                  << card._INTNO.format(card.INTNO) << ::std::endl
                  << ::dnvgl::extfem::fem::types::card().format()
                  << card._MINTNO.format(card.MINTNO)
                  << card._STRANO.format(card.STRANO)
                  << card._STRENO.format(card.STRENO)
                  << card._STREPONO.format(card.STREPONO) << ::std::endl
                  << ::dnvgl::extfem::fem::types::card().format()
                  << card._GEONO_OPT.format(card.GEONO_OPT)
                  << card._FIXNO_OPT.format(card.FIXNO_OPT)
                  << card._ECCNO_OPT.format(card.ECCNO_OPT)
                  << card._TRANSNO_OPT.format(card.TRANSNO_OPT);

               size_t i = 5;
               for (auto p : card.GEONO) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << fem::types::card().format();
                  }
                  os << card._GEONO.format(p);
               }
               for (auto p : card.FIXNO) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << ::fem::types::card().format();
                  }
                  os << card._FIXNO.format(p);
               }
               for (auto p : card.ECCNO) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << ::dnvgl::extfem::fem::types::card().format();
                  }
                  os << card._ECCNO.format(p);
               }
               for (auto p : card.TRANSNO) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << ::dnvgl::extfem::fem::types::card().format();
                  }
                  os << card._TRANSNO.format(p);
               }

               while (i++ < 4)
                  os << card._ELNO.format(0);
               os << std::endl;
               return os;
            }

            const ::std::ostream&
            gelref1::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
