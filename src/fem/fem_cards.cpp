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
   const char  cID[]
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
      std::pair<std::string, cards::types>("DATE", cards::DATE),
      std::pair<std::string, cards::types>("GCOORD", cards::GCOORD),
      std::pair<std::string, cards::types>("GNODE", cards::GNODE),
      std::pair<std::string, cards::types>("IDENT", cards::IDENT),
      std::pair<std::string, cards::types>("IEND", cards::IEND),
      std::pair<std::string, cards::types>("GELMNT1", cards::GELMNT1),
      std::pair<std::string, cards::types>("GELREF1", cards::GELREF1),
      std::pair<std::string, cards::types>("GBARM", cards::GBARM),
      std::pair<std::string, cards::types>("GBEAMG", cards::GBEAMG),
      std::pair<std::string, cards::types>("GECCEN", cards::GECCEN),
      std::pair<std::string, cards::types>("GELTH", cards::GELTH),
      std::pair<std::string, cards::types>("GIORH", cards::GIORH),
      std::pair<std::string, cards::types>("GLSEC", cards::GLSEC),
      std::pair<std::string, cards::types>("GPIPE", cards::GPIPE),
      std::pair<std::string, cards::types>("GUSYI", cards::GUSYI),
      std::pair<std::string, cards::types>("BELFIX", cards::BELFIX),
      std::pair<std::string, cards::types>("BLDEP", cards::BLDEP),
      std::pair<std::string, cards::types>("BNBCD", cards::BNBCD),
      std::pair<std::string, cards::types>("BNDISPL", cards::BNDISPL),
      std::pair<std::string, cards::types>("BNLOAD", cards::BNLOAD),
      std::pair<std::string, cards::types>("MGSPRNG", cards::MGSPRNG),
      std::pair<std::string, cards::types>("GSETMEMB", cards::GSETMEMB),
      std::pair<std::string, cards::types>("GUNIVEC", cards::GUNIVEC),
      std::pair<std::string, cards::types>("MISOSEL", cards::MISOSEL),
      std::pair<std::string, cards::types>("MORSMEL", cards::MORSMEL),
      std::pair<std::string, cards::types>("TDSETNAM", cards::TDSETNAM),
      std::pair<std::string, cards::types>("TDSUPNAM", cards::TDSUPNAM),
      std::pair<std::string, cards::types>("TEXT", cards::TEXT),
      std::pair<std::string, cards::types>("TDSETNAM", cards::TDSETNAM),
      std::pair<std::string, cards::types>("TDSUPNAM", cards::TDSUPNAM),
      std::pair<std::string, cards::types>("TDLOAD", cards::TDLOAD),
      std::pair<std::string, cards::types>("BSELL", cards::BSELL),
      std::pair<std::string, cards::types>("GELMNT2", cards::GELMNT2),
      std::pair<std::string, cards::types>("HSUPSTAT", cards::HSUPSTAT),
      std::pair<std::string, cards::types>("HSUPTRAN", cards::HSUPTRAN),
      std::pair<std::string, cards::types>("HIERARCH", cards::HIERARCH),
      std::pair<std::string, cards::types>("BEUSLO", cards::BEUSLO)
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
            unknown::card_type(void) const { return UNKNOWN; }

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
                  case DATE:
                     res = std::make_unique<fem::cards::date>(inp);
                     break;
                  case GCOORD:
                     res = std::make_unique<fem::cards::gcoord>(inp);
                     break;
                  case GNODE:
                     res = std::make_unique<fem::cards::gnode>(inp);
                     break;
                  case GBARM:
                     res = std::make_unique<fem::cards::gbarm>(inp);
                     break;
                  case GBEAMG:
                     res = std::make_unique<fem::cards::gbeamg>(inp);
                     break;
                  case GECCEN:
                     res = std::make_unique<fem::cards::geccen>(inp);
                     break;
                  case GELTH:
                     res = std::make_unique<fem::cards::gelth>(inp);
                     break;
                  case GIORH:
                     res = std::make_unique<fem::cards::giorh>(inp);
                     break;
                  case GLSEC:
                     res = std::make_unique<fem::cards::glsec>(inp);
                     break;
                  case GPIPE:
                     res = std::make_unique<fem::cards::gpipe>(inp);
                     break;
                  case GUSYI:
                     res = std::make_unique<fem::cards::gusyi>(inp);
                     break;
                  case BELFIX:
                     res = std::make_unique<fem::cards::belfix>(inp);
                     break;
                  case IDENT:
                     res = std::make_unique<fem::cards::ident>(inp);
                     break;
                  case IEND:
                     res = std::make_unique<fem::cards::iend>(inp);
                     break;
                  case GELMNT1:
                     res = std::make_unique<fem::cards::gelmnt1>(inp);
                     break;
                  case GELREF1:
                     res = std::make_unique<fem::cards::gelref1>(inp);
                     break;
                  case BLDEP:
                     res = std::make_unique<fem::cards::bldep>(inp);
                     break;
                  case BNBCD:
                     res = std::make_unique<fem::cards::bnbcd>(inp);
                     break;
                  case BNDISPL:
                     res = std::make_unique<fem::cards::bndispl>(inp);
                     break;
                  case BNLOAD:
                     res = std::make_unique<fem::cards::bnload>(inp);
                     break;
                  case MGSPRNG:
                     res = std::make_unique<fem::cards::mgsprng>(inp);
                     break;
                  case GSETMEMB:
                     res = std::make_unique<fem::cards::gsetmemb>(inp);
                     break;
                  case GUNIVEC:
                     res = std::make_unique<fem::cards::gunivec>(inp);
                     break;
                  case MISOSEL:
                     res = std::make_unique<fem::cards::misosel>(inp);
                     break;
                  case MORSMEL:
                     res = std::make_unique<fem::cards::morsmel>(inp);
                     break;
                  case TEXT:
                     res = std::make_unique<fem::cards::text>(inp);
                     break;
                  case TDSETNAM:
                     res = std::make_unique<fem::cards::tdsetnam>(inp);
                     break;
                  case TDSUPNAM:
                     res = std::make_unique<fem::cards::tdsupnam>(inp);
                     break;
                  case TDLOAD:
                     res = std::make_unique<fem::cards::tdload>(inp);
                     break;
                  case BSELL:
                     res = std::make_unique<fem::cards::bsell>(inp);
                     break;
                  case GELMNT2:
                     res = std::make_unique<fem::cards::gelmnt2>(inp);
                     break;
                  case HSUPSTAT:
                     res = std::make_unique<fem::cards::hsupstat>(inp);
                     break;
                  case HSUPTRAN:
                     res = std::make_unique<fem::cards::hsuptran>(inp);
                     break;
                  case HIERARCH:
                     res = std::make_unique<fem::cards::hierarch>(inp);
                     break;
                  case BEUSLO:
                     res = std::make_unique<fem::cards::beuslo>(inp);
                     break;
                     // These are not real card types, they can't be returned
                  case UNKNOWN:
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
