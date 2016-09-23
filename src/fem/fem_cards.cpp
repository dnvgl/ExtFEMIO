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
   const char cID_fem_cards[]
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
static char THIS_FILE[] = __FILE__;
#endif

namespace {
   const char initVals[3] = { '+', '*', ',' };

   const void _stderr_report(std::string const &msg) {
      std::cerr << msg << std::endl;
   }

   const void _stdout_report(std::string const &msg) {
      std::cout << msg << std::endl;
   }

   using namespace dnvgl::extfem::fem;

   const size_t map_pair_entries = 37;
   const std::pair<std::string, cards::types> map_pairs[map_pair_entries] = {
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

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const void(*note_report)(std::string const &) = &_stdout_report;
            const void(*info_report)(std::string const &) = &_stderr_report;
            const void(*warn_report)(std::string const &) = &_stderr_report;
            const void(*error_report)(std::string const &) = &_stderr_report;

            unknown::unknown(std::list<std::string> const &inp) :
               __base::card(inp), content(inp) {};

            const types
            unknown::card_type(void) const { return types::UNKNOWN; }

            std::ostream &unknown::put(std::ostream &os) const {
               throw errors::error("can't write UNKNOWN.");
               return os;
            }

            const std::map<std::string, types>
               cardtype_map(map_pairs, map_pairs + map_pair_entries);

            namespace __base {
               card::card(std::list<std::string> const &inp) {}

               card::card() {}

               fem::types::empty const card::empty = fem::types::empty();

               fem::types::card const card::head = fem::types::card("<DUMMY>");


               void
               card::card_split(std::list<std::string> const &inp, std::list<std::string> &res) {
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

               __base::beam_prop::beam_prop(std::list<std::string> const &inp) :
                  card(inp) {}

               __base::beam_prop::beam_prop() :
                  __base::beam_prop(-1) {}

               __base::beam_prop::beam_prop(long const &GEONO) :
                  card(), GEONO(GEONO) {}

               const dnvgl::extfem::fem::types::entry_type<long> __base::beam_prop::_form_GEONO("GEONO");

               __base::material::material(std::list<std::string> const &inp) :
                  card(inp) {}

               __base::material::material() :
                  __base::material(-1) {}

               __base::material::material(long const &MATNO) :
                  card(), MATNO(MATNO) {}

               const dnvgl::extfem::fem::types::entry_type<long> __base::material::_form_MATNO("MATNO");
            }

            void
            dispatch(std::list<std::string> const &inp, std::unique_ptr<__base::card> &res) {

               try {
                  std::string key(inp.front());
                  switch (cardtype_map.at(key)) {
                  case types::DATE:
                     res = std::make_unique<fem::cards::date>(inp);
                     break;
                  case types::GCOORD:
                     res = std::make_unique<fem::cards::gcoord>(inp);
                     break;
                  case types::GNODE:
                     res = std::make_unique<fem::cards::gnode>(inp);
                     break;
                  case types::GBARM:
                     res = std::make_unique<fem::cards::gbarm>(inp);
                     break;
                  case types::GBEAMG:
                     res = std::make_unique<fem::cards::gbeamg>(inp);
                     break;
                  case types::GECCEN:
                     res = std::make_unique<fem::cards::geccen>(inp);
                     break;
                  case types::GELTH:
                     res = std::make_unique<fem::cards::gelth>(inp);
                     break;
                  case types::GIORH:
                     res = std::make_unique<fem::cards::giorh>(inp);
                     break;
                  case types::GLSEC:
                     res = std::make_unique<fem::cards::glsec>(inp);
                     break;
                  case types::GPIPE:
                     res = std::make_unique<fem::cards::gpipe>(inp);
                     break;
                  case types::GUSYI:
                     res = std::make_unique<fem::cards::gusyi>(inp);
                     break;
                  case types::BELFIX:
                     res = std::make_unique<fem::cards::belfix>(inp);
                     break;
                  case types::IDENT:
                     res = std::make_unique<fem::cards::ident>(inp);
                     break;
                  case types::IEND:
                     res = std::make_unique<fem::cards::iend>(inp);
                     break;
                  case types::GELMNT1:
                     res = std::make_unique<fem::cards::gelmnt1>(inp);
                     break;
                  case types::GELREF1:
                     res = std::make_unique<fem::cards::gelref1>(inp);
                     break;
                  case types::BLDEP:
                     res = std::make_unique<fem::cards::bldep>(inp);
                     break;
                  case types::BNBCD:
                     res = std::make_unique<fem::cards::bnbcd>(inp);
                     break;
                  case types::BNDISPL:
                     res = std::make_unique<fem::cards::bndispl>(inp);
                     break;
                  case types::BNLOAD:
                     res = std::make_unique<fem::cards::bnload>(inp);
                     break;
                  case types::MGSPRNG:
                     res = std::make_unique<fem::cards::mgsprng>(inp);
                     break;
                  case types::GSETMEMB:
                     res = std::make_unique<fem::cards::gsetmemb>(inp);
                     break;
                  case types::GUNIVEC:
                     res = std::make_unique<fem::cards::gunivec>(inp);
                     break;
                  case types::MISOSEL:
                     res = std::make_unique<fem::cards::misosel>(inp);
                     break;
                  case types::MORSMEL:
                     res = std::make_unique<fem::cards::morsmel>(inp);
                     break;
                  case types::TEXT:
                     res = std::make_unique<fem::cards::text>(inp);
                     break;
                  case types::TDSETNAM:
                     res = std::make_unique<fem::cards::tdsetnam>(inp);
                     break;
                  case types::TDSUPNAM:
                     res = std::make_unique<fem::cards::tdsupnam>(inp);
                     break;
                  case types::TDLOAD:
                     res = std::make_unique<fem::cards::tdload>(inp);
                     break;
                  case types::BSELL:
                     res = std::make_unique<fem::cards::bsell>(inp);
                     break;
                  case types::GELMNT2:
                     res = std::make_unique<fem::cards::gelmnt2>(inp);
                     break;
                  case types::HSUPSTAT:
                     res = std::make_unique<fem::cards::hsupstat>(inp);
                     break;
                  case types::HSUPTRAN:
                     res = std::make_unique<fem::cards::hsuptran>(inp);
                     break;
                  case types::HIERARCH:
                     res = std::make_unique<fem::cards::hierarch>(inp);
                     break;
                  case types::BEUSLO:
                     res = std::make_unique<fem::cards::beuslo>(inp);
                     break;
                     // These are not real card types, they can't be returned
                  case types::UNKNOWN:
                     res = std::make_unique<fem::cards::unknown>(inp);
                  }
               } catch (std::out_of_range) {
                  res = std::make_unique<fem::cards::unknown>(inp);
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
