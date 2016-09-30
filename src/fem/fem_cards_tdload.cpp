/**
   \file fem/fem_cards_tdload.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `TDLOAD` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_tdload[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

#include <memory>

#include "fem/cards.h"
#include "fem/types.h"
#include "extfem_misc.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

fem::types::card const tdload::head("TDLOAD");

entry_type<long> const tdload::_form_NFIELD("NFIELD");
entry_type<long> const tdload::_form_ILREF("ILREF");
entry_type<long> const tdload::_form_CODNAM("CODNAM");
entry_type<long> const tdload::_form_CODTXT("CODTXT");
entry_type<std::string> const tdload::_form_SET_NAME(
   "SET_NAME", type_bounds::bound<std::string>(""));
entry_type<std::string> const tdload::_form_CONT("CONT");

tdload::tdload(std::list<std::string> const &inp) :
   card(inp) {

   if (inp.size() < 5)
      throw errors::parse_error(
         "TDLOAD", "Illegal number of entries.");

   auto pos = inp.begin();

   ++pos;
   NFIELD = _form_NFIELD(*(pos++));
   if (NFIELD != 4) {
      std::ostringstream msg(
         "Only NFIELD values of 4 are supported, "
         "but got value of ",
         std::ostringstream::ate);
      msg << NFIELD;
      errors::parse_error("TDLOAD", msg.str());
   }
   ILREF = _form_ILREF(*(pos++));
   CODNAM = _form_CODNAM(*(pos++));
   CODTXT = _form_CODTXT(*(pos++));

   auto div_val = ldiv(CODNAM, 100);
   nlnam = div_val.quot != 0;
   ncnam = div_val.rem;
   div_val = ldiv(CODTXT, 100);
   nltxt = div_val.quot;
   nctxt = div_val.rem;

   if (nlnam) {
      auto pos_0 = *pos++;
      auto pos_1 = *pos++;
      auto pos_2 = *pos++;
      auto pos_3 = *pos++;
      SET_NAME = _form_SET_NAME(
         pos_0, pos_1, pos_2, pos_3);
      SET_NAME.resize(ncnam, ' ');
   } else
      (((pos++)++)++)++;
   for (long i=0; i < nltxt; i++) {
      auto pos_0 = *pos++;
      auto pos_1 = *pos++;
      auto pos_2 = *pos++;
      auto pos_3 = *pos++;
      std::string cont = _form_CONT(
         pos_0, pos_1, pos_2, pos_3);
      cont.resize(nctxt, ' ');
      CONT.push_back(cont);
   }
}

tdload::tdload(void) :
   tdload(0, -1, 0, {}) {}

tdload::tdload(long const &NFIELD,
               long const &ILREF,
               long const &CODNAM,
               long const &CODTXT,
               std::string const &SET_NAME,
               std::vector<std::string> const &CONT) :
   card(), NFIELD(NFIELD), ILREF(ILREF),
   CODNAM(CODNAM), CODTXT(CODTXT),
   SET_NAME(SET_NAME), CONT(CONT) {
   auto div_val = ldiv(CODNAM, 100);
   nlnam = div_val.quot != 0;
   ncnam = div_val.rem;
   div_val = ldiv(CODTXT, 100);
   nltxt = div_val.quot;
   nctxt = div_val.rem;
}

tdload::tdload(long const &ILREF,
               std::string const &SET_NAME,
               std::vector<std::string> const &CONT/*={}*/) :
   card(), NFIELD(4), ILREF(ILREF),
   SET_NAME(SET_NAME), CONT(CONT) {

   nlnam = true;
   ncnam = (long)SET_NAME.size();
   CODNAM = 100 + ncnam;
   nltxt = (long)CONT.size();
   nctxt = 0;
   if (CONT.size()>0) {
      for (auto &p : CONT)
         nctxt = std::max(nctxt, (long)p.size());
      for (auto &p : this->CONT)
         p.resize(nctxt, ' ');
   }
   CODTXT = (100 * nltxt) + nctxt;
}

tdload::tdload(long const &NFIELD,
               long const &ILREF,
               long const &CODNAM,
               std::string const &SET_NAME) :
   tdload(NFIELD, ILREF, CODNAM, 0, SET_NAME, {}) {}

cards::__base::card const &tdload::operator() (
   long const &NFIELD,
   long const &ILREF,
   long const &CODNAM,
   long const &CODTXT,
   std::string const &SET_NAME,
   std::vector<std::string> const &CONT) {
   this->NFIELD = NFIELD;
   this->ILREF = ILREF;
   this->CODNAM = CODNAM;
   this->CODTXT = CODTXT;
   this->SET_NAME = SET_NAME;
   this->CONT = CONT;
   auto div_val = ldiv(CODNAM, 100);
   nlnam = div_val.quot != 0;
   ncnam = div_val.rem;
   div_val = ldiv(CODTXT, 100);
   nltxt = div_val.quot;
   nctxt = div_val.rem;
   return *this;
}

cards::__base::card const &tdload::operator() (
   long const &ILREF,
   std::string const &SET_NAME,
   std::vector<std::string> const &CONT/*={}*/) {
   nlnam = true;
   ncnam = (long)SET_NAME.size();
   CODNAM = 100 + ncnam;
   nltxt = (long)CONT.size();
   nctxt = 0;
   if (CONT.size()>0) {
      for (auto &p : CONT)
         nctxt = std::max(nctxt, (long)p.size());
      for (auto &p : this->CONT)
         p.resize(nctxt, ' ');
   }
   CODTXT = (100 * nltxt) + nctxt;
   return (*this)(4, ILREF, 100 + ncnam, CODTXT, SET_NAME, CONT);
}

cards::__base::card const &tdload::operator() (
   long const &NFIELD,
   long const &ILREF,
   long const &CODNAM,
   std::string const &SET_NAME) {
   return (*this)(NFIELD, ILREF, CODNAM, 0, SET_NAME, {});
}

dnvgl::extfem::fem::cards::types const
tdload::card_type(void) const { return types::TDLOAD; };

std::ostream &tdload::put(std::ostream& os) const {
   if (this->ILREF == -1) return os;
   os << tdload::head.format()
      << this->_form_NFIELD.format(this->NFIELD)
      << this->_form_ILREF.format(this->ILREF)
      << this->_form_CODNAM.format(this->CODNAM)
      << this->_form_CODTXT.format(this->CODTXT) << std::endl;
   if (this->nlnam)
      os << dnvgl::extfem::fem::types::card().format()
         << this->_form_SET_NAME.format(this->SET_NAME, this->ncnam+8) << std::endl;
   for (auto p : this->CONT)
      os << dnvgl::extfem::fem::types::card().format()
         << this->_form_CONT.format(p, this->nctxt+8) << std::endl;
   return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
