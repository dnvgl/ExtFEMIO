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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "fem/cards.h"
#include "fem/errors.h"
#include "extfem_string.h"

using namespace ::std;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {
            card::card(const deque<::std::string> &inp) {}

            card::card() {}

            unknown::unknown(const ::std::deque<::std::string> &inp) :
               card(inp), content(inp) {};

            const types
            unknown::card_type(void) const { return UNKNOWN; }

            const ::std::ostream&
            unknown::operator<< (::std::ostream &os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const unknown &card) {
               throw errors::error("can't write UNKNOWN.");
               return os;
            }
         }
      }
   }
}

namespace {
   const char initVals[3] = { '+', '*', ',' };
}

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {
            fem::types::empty card::empty = fem::types::empty();

            fem::types::card card::head = fem::types::card("<DUMMY>");
         }
      }
   }
}

namespace {
   using namespace dnvgl::extfem::fem;

   const size_t map_pair_entries = 16;
   const pair<::std::string, cards::types> map_pairs[map_pair_entries] = {
      // UNKNOWN,
      pair<::std::string, cards::types>("DATE", cards::DATE),
      pair<::std::string, cards::types>("GCOORD", cards::GCOORD),
      pair<::std::string, cards::types>("GNODE", cards::GNODE),
      pair<::std::string, cards::types>("IDENT", cards::IDENT),
      pair<::std::string, cards::types>("IEND", cards::IEND),
      pair<::std::string, cards::types>("GELMNT1", cards::GELMNT1),
      pair<::std::string, cards::types>("GELREF1", cards::GELREF1),
      pair<::std::string, cards::types>("GBARM", cards::GBARM),
      pair<::std::string, cards::types>("GBEAMG", cards::GBEAMG),
      pair<::std::string, cards::types>("GECCEN", cards::GECCEN),
      pair<::std::string, cards::types>("GELTH", cards::GELTH),
      pair<::std::string, cards::types>("GIORH", cards::GIORH),
      pair<::std::string, cards::types>("GLSEC", cards::GLSEC),
      pair<::std::string, cards::types>("GPIPE", cards::GPIPE),
      pair<::std::string, cards::types>("BLDEP", cards::BLDEP),
      // pair<::std::string, cards::types>("BNBCD", cards::BNBCD),
      // pair<::std::string, cards::types>("BNDISPL", cards::BNDISPL),
      // pair<::std::string, cards::types>("BNLOAD", cards::BNLOAD),
      // pair<::std::string, cards::types>("MGSPRNG", cards::MGSPRNG),
      // pair<::std::string, cards::types>("GSETMEMB", cards::GSETMEMB),
      // pair<::std::string, cards::types>("GUNIVEC", cards::GUNIVEC),
      // pair<::std::string, cards::types>("MISOSEL", cards::MISOSEL),
      // pair<::std::string, cards::types>("TDSETNAM", cards::TDSETNAM),
      pair<::std::string, cards::types>("TEXT", cards::TEXT),
      // pair<::std::strincards::types>("TDLOAD", cards::TDLOAD),
   };
}

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {
            const map<::std::string, types>
               cardtype_map(map_pairs, map_pairs + map_pair_entries);

            deque<::std::string>
            card::card_split(deque<::std::string> const &inp) {
               deque<::std::string> res;
               ::std::string head;

               bool first = true;

               for (auto &pos : inp) {
                  head = extfem::string::string(pos.substr(0, 8)).trim();
                  if (first)
                     res.push_back(extfem::string::string(head).trim("\t\n"));
                  auto tmp(pos);
                  tmp.resize(80, ' ');
                  tmp = tmp.substr(8);
                  for (int i=0; i<4; ++i)
                     res.push_back(tmp.substr(i*16, 16));
                  first = false;
               }
               return res;
            }

            void
            dispatch(const deque<::std::string> &inp,
                     ::std::unique_ptr<fem::cards::card> &res) {

               try {
                  ::std::string key(inp.at(0));
                  switch (cardtype_map.at(key)) {
                  case DATE:
                     res = ::std::make_unique<fem::cards::date>(inp);
                     break;
                  case GCOORD:
                     res = ::std::make_unique<fem::cards::gcoord>(inp);
                     break;
                  case GNODE:
                     res = ::std::make_unique<fem::cards::gnode>(inp);
                     break;
                  case GBARM:
                     res = ::std::make_unique<fem::cards::gbarm>(inp);
                     break;
                  case GBEAMG:
                     res = ::std::make_unique<fem::cards::gbeamg>(inp);
                     break;
                  case GECCEN:
                     res = ::std::make_unique<fem::cards::geccen>(inp);
                     break;
                  case GELTH:
                     res = ::std::make_unique<fem::cards::gelth>(inp);
                     break;
                  case GIORH:
                     res = ::std::make_unique<fem::cards::giorh>(inp);
                     break;
                  case GLSEC:
                     res = ::std::make_unique<fem::cards::glsec>(inp);
                     break;
                  case GPIPE:
                     res = ::std::make_unique<fem::cards::gpipe>(inp);
                     break;
                  case IDENT:
                     res = ::std::make_unique<fem::cards::ident>(inp);
                     break;
                  case IEND:
                     res = ::std::make_unique<fem::cards::iend>(inp);
                     break;
                  case GELMNT1:
                     res = ::std::make_unique<fem::cards::gelmnt1>(inp);
                     break;
                  case GELREF1:
                     res = ::std::make_unique<fem::cards::gelref1>(inp);
                     break;
                  case BLDEP:
                     res = ::std::make_unique<fem::cards::bldep>(inp);
                     break;
                  case TEXT:
                     res = ::std::make_unique<fem::cards::text>(inp);
                     break;
                     // These are not real card types, they can't be returned
                  case UNKNOWN:
                     res = nullptr;
                  }
               } catch (out_of_range) {
                  res = ::std::make_unique<fem::cards::unknown>(inp);
               }
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
