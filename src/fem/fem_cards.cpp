/**
   \file fem/fem_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definitions for Sesam FEM cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   char const cID_fem_cards[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/errors.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
char static THIS_FILE[] = __FILE__;
#endif

namespace {
   char const initVals[3] = { '+', '*', ',' };

   void const _stderr_report(std::string const &msg) {
      std::cerr << msg << std::endl;
   }

   void const _stdout_report(std::string const &msg) {
      std::cout << msg << std::endl;
   }

   using namespace dnvgl::extfem::fem;

   size_t const map_pair_entries = 37;
   std::pair<std::string, cards::types> const map_pairs[map_pair_entries] = {
      // UNKNOWN,
      std::pair<std::string, cards::types>("DATE", cards::types::DATE),
      std::pair<std::string, cards::types>("GCOORD", cards::types::GCOORD),
      std::pair<std::string, cards::types>("GNODE", cards::types::GNODE),
      std::pair<std::string, cards::types>("IDENT", cards::types::IDENT),
      std::pair<std::string, cards::types>("IEND", cards::types::IEND),
      std::pair<std::string, cards::types>("GELMNT1", cards::types::GELMNT1),
      std::pair<std::string, cards::types>("GELREF1", cards::types::GELREF1),
      std::pair<std::string, cards::types>("GBARM", cards::types::GBARM),
      std::pair<std::string, cards::types>("GBEAMG", cards::types::GBEAMG),
      std::pair<std::string, cards::types>("GECCEN", cards::types::GECCEN),
      std::pair<std::string, cards::types>("GELTH", cards::types::GELTH),
      std::pair<std::string, cards::types>("GIORH", cards::types::GIORH),
      std::pair<std::string, cards::types>("GLSEC", cards::types::GLSEC),
      std::pair<std::string, cards::types>("GPIPE", cards::types::GPIPE),
      std::pair<std::string, cards::types>("GUSYI", cards::types::GUSYI),
      std::pair<std::string, cards::types>("BELFIX", cards::types::BELFIX),
      std::pair<std::string, cards::types>("BLDEP", cards::types::BLDEP),
      std::pair<std::string, cards::types>("BNBCD", cards::types::BNBCD),
      std::pair<std::string, cards::types>("BNDISPL", cards::types::BNDISPL),
      std::pair<std::string, cards::types>("BNLOAD", cards::types::BNLOAD),
      std::pair<std::string, cards::types>("MGSPRNG", cards::types::MGSPRNG),
      std::pair<std::string, cards::types>("GSETMEMB", cards::types::GSETMEMB),
      std::pair<std::string, cards::types>("GUNIVEC", cards::types::GUNIVEC),
      std::pair<std::string, cards::types>("MISOSEL", cards::types::MISOSEL),
      std::pair<std::string, cards::types>("MORSMEL", cards::types::MORSMEL),
      std::pair<std::string, cards::types>("TDSETNAM", cards::types::TDSETNAM),
      std::pair<std::string, cards::types>("TDSUPNAM", cards::types::TDSUPNAM),
      std::pair<std::string, cards::types>("TEXT", cards::types::TEXT),
      std::pair<std::string, cards::types>("TDSETNAM", cards::types::TDSETNAM),
      std::pair<std::string, cards::types>("TDSUPNAM", cards::types::TDSUPNAM),
      std::pair<std::string, cards::types>("TDLOAD", cards::types::TDLOAD),
      std::pair<std::string, cards::types>("BSELL", cards::types::BSELL),
      std::pair<std::string, cards::types>("GELMNT2", cards::types::GELMNT2),
      std::pair<std::string, cards::types>("HSUPSTAT", cards::types::HSUPSTAT),
      std::pair<std::string, cards::types>("HSUPTRAN", cards::types::HSUPTRAN),
      std::pair<std::string, cards::types>("HIERARCH", cards::types::HIERARCH),
      std::pair<std::string, cards::types>("BEUSLO", cards::types::BEUSLO)
   };
}

using namespace dnvgl::extfem;
using namespace fem;
using namespace cards;

void const (*cards::note_report)(std::string const &) = &_stdout_report;
void const (*cards::info_report)(std::string const &) = &_stderr_report;
void const (*cards::warn_report)(std::string const &) = &_stderr_report;
void const (*cards::error_report)(std::string const &) = &_stderr_report;

unknown::unknown(std::list<std::string> const &inp) :
   cards::__base::card(inp), content(inp) {};

cards::types const
unknown::card_type(void) const { return cards::types::UNKNOWN; }

std::ostream &unknown::put(std::ostream &os) const {
   throw errors::error("can't write UNKNOWN.");
   return os;
}

std::map<std::string, cards::types> const
cardtype_map(map_pairs, map_pairs + map_pair_entries);

cards::__base::card::card(std::list<std::string> const &inp) {}


cards::__base::card::card() {}

fem::types::empty const cards::__base::card::empty = fem::types::empty();

fem::types::card const cards::__base::card::head = fem::types::card("<DUMMY>");


void cards::__base::card::card_split(
   std::list<std::string> const &inp, std::list<std::string> &res) {
   std::string head;

   bool first = true;

   res.clear();

   for (auto &pos : inp) {
      head = extfem::string::string(pos.substr(0, 8)).trim();
      if (first)
         res.push_back(string::string(head).trim("\t\n"));
      std::string tmp(string::string(pos).trim("\t\n"));
      tmp.resize(80, ' ');
      tmp = tmp.substr(8);
      for (int i=0; i<4; ++i)
         res.push_back(tmp.substr(i*16, 16));
      first = false;
   }
}

cards::__base::beam_prop::beam_prop(std::list<std::string> const &inp) :
   card(inp) {}

cards::__base::beam_prop::beam_prop() :
   __base::beam_prop(-1) {}

cards::__base::beam_prop::beam_prop(long const &GEONO) :
   card(), GEONO(GEONO) {}

dnvgl::extfem::fem::types::entry_type<long> const
cards::__base::beam_prop::_form_GEONO("GEONO");

cards::__base::material::material(std::list<std::string> const &inp) :
   card(inp) {}

cards::__base::material::material() :
   __base::material(-1) {}

cards::__base::material::material(long const &MATNO) :
   card(), MATNO(MATNO) {}

dnvgl::extfem::fem::types::entry_type<long> const
cards::__base::material::_form_MATNO("MATNO");

void
cards::dispatch(std::list<std::string> const &inp,
                std::unique_ptr<cards::__base::card> &res) {

   try {
      std::string key(inp.front());
      switch (cardtype_map.at(key)) {
      case cards::types::DATE:
         res = std::make_unique<fem::cards::date>(inp);
         break;
      case cards::types::GCOORD:
         res = std::make_unique<fem::cards::gcoord>(inp);
         break;
      case cards::types::GNODE:
         res = std::make_unique<fem::cards::gnode>(inp);
         break;
      case cards::types::GBARM:
         res = std::make_unique<fem::cards::gbarm>(inp);
         break;
      case cards::types::GBEAMG:
         res = std::make_unique<fem::cards::gbeamg>(inp);
         break;
      case cards::types::GECCEN:
         res = std::make_unique<fem::cards::geccen>(inp);
         break;
      case cards::types::GELTH:
         res = std::make_unique<fem::cards::gelth>(inp);
         break;
      case cards::types::GIORH:
         res = std::make_unique<fem::cards::giorh>(inp);
         break;
      case cards::types::GLSEC:
         res = std::make_unique<fem::cards::glsec>(inp);
         break;
      case cards::types::GPIPE:
         res = std::make_unique<fem::cards::gpipe>(inp);
         break;
      case cards::types::GUSYI:
         res = std::make_unique<fem::cards::gusyi>(inp);
         break;
      case cards::types::BELFIX:
         res = std::make_unique<fem::cards::belfix>(inp);
         break;
      case cards::types::IDENT:
         res = std::make_unique<fem::cards::ident>(inp);
         break;
      case cards::types::IEND:
         res = std::make_unique<fem::cards::iend>(inp);
         break;
      case cards::types::GELMNT1:
         res = std::make_unique<fem::cards::gelmnt1>(inp);
         break;
      case cards::types::GELREF1:
         res = std::make_unique<fem::cards::gelref1>(inp);
         break;
      case cards::types::BLDEP:
         res = std::make_unique<fem::cards::bldep>(inp);
         break;
      case cards::types::BNBCD:
         res = std::make_unique<fem::cards::bnbcd>(inp);
         break;
      case cards::types::BNDISPL:
         res = std::make_unique<fem::cards::bndispl>(inp);
         break;
      case cards::types::BNLOAD:
         res = std::make_unique<fem::cards::bnload>(inp);
         break;
      case cards::types::MGSPRNG:
         res = std::make_unique<fem::cards::mgsprng>(inp);
         break;
      case cards::types::GSETMEMB:
         res = std::make_unique<fem::cards::gsetmemb>(inp);
         break;
      case cards::types::GUNIVEC:
         res = std::make_unique<fem::cards::gunivec>(inp);
         break;
      case cards::types::MISOSEL:
         res = std::make_unique<fem::cards::misosel>(inp);
         break;
      case cards::types::MORSMEL:
         res = std::make_unique<fem::cards::morsmel>(inp);
         break;
      case cards::types::TEXT:
         res = std::make_unique<fem::cards::text>(inp);
         break;
      case cards::types::TDSETNAM:
         res = std::make_unique<fem::cards::tdsetnam>(inp);
         break;
      case cards::types::TDSUPNAM:
         res = std::make_unique<fem::cards::tdsupnam>(inp);
         break;
      case cards::types::TDLOAD:
         res = std::make_unique<fem::cards::tdload>(inp);
         break;
      case cards::types::BSELL:
         res = std::make_unique<fem::cards::bsell>(inp);
         break;
      case cards::types::GELMNT2:
         res = std::make_unique<fem::cards::gelmnt2>(inp);
         break;
      case cards::types::HSUPSTAT:
         res = std::make_unique<fem::cards::hsupstat>(inp);
         break;
      case cards::types::HSUPTRAN:
         res = std::make_unique<fem::cards::hsuptran>(inp);
         break;
      case cards::types::HIERARCH:
         res = std::make_unique<fem::cards::hierarch>(inp);
         break;
      case cards::types::BEUSLO:
         res = std::make_unique<fem::cards::beuslo>(inp);
         break;
         // These are not real card types, they can't be returned
      case cards::types::UNKNOWN:
         res = std::make_unique<fem::cards::unknown>(inp);
      }
   } catch (std::out_of_range) {
      res = std::make_unique<fem::cards::unknown>(inp);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
