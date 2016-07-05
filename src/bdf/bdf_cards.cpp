/**
   \file bdf/bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definition for Nastran BDF cards.

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

#include <string>
#include <iostream>

#include "bdf/cards.h"
#include "bdf/errors.h"
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

   const size_t map_pairs_num = 14;
   const std::pair<std::string, dnvgl::extfem::bdf::cards::types> map_pairs[map_pairs_num] = {
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("GRID", dnvgl::extfem::bdf::cards::GRID),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("MAT1", dnvgl::extfem::bdf::cards::MAT1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTRIA3", dnvgl::extfem::bdf::cards::CTRIA3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CQUAD4", dnvgl::extfem::bdf::cards::CQUAD4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PSHELL", dnvgl::extfem::bdf::cards::PSHELL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBEAM", dnvgl::extfem::bdf::cards::CBEAM),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBEAM", dnvgl::extfem::bdf::cards::PBEAM),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBEAML", dnvgl::extfem::bdf::cards::PBEAML),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBAR", dnvgl::extfem::bdf::cards::CBAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBAR", dnvgl::extfem::bdf::cards::PBAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBARL", dnvgl::extfem::bdf::cards::PBARL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CROD", dnvgl::extfem::bdf::cards::CROD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PROD", dnvgl::extfem::bdf::cards::PROD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("ENDDATA", dnvgl::extfem::bdf::cards::ENDDATA)};

   const std::map<std::string, dnvgl::extfem::bdf::cards::types> cardtype_map(
      map_pairs, map_pairs + map_pairs_num);
}

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

            const void(*note_report)(std::string const &) = &_stdout_report;

            const void(*info_report)(std::string const &) = &_stderr_report;

            const void(*warn_report)(std::string const &) = &_stderr_report;

            const void(*error_report)(std::string const &) = &_stderr_report;

            namespace __base {

               card::card(std::list<std::string> const &inp) {}

               card::card() {}

               bdf::types::empty card::empty = bdf::types::empty();

               const std::set<char> card::free_form_cont(initVals, initVals + 3);

               std::string card::format_outlist(
                  const std::list<std::unique_ptr<format_entry> > &en) const {

                  unsigned long i = 0;
                  std::ostringstream res("");

                  try {
                     for (auto &p : en) {
                        if (++i > 9) {
                           i = 2;
                           res << std::endl << bdf::types::card("").format(nullptr);
                        }
                        res << p->first->format(p->second);
                     }
                  } catch (errors::form_error) {
                     unsigned long lines = 0;
                     res.seekp(0);
                     i = 0;
                     bdf::types::base::out_form = bdf::types::LONG;
                     for (auto &p : en) {
                        if (++i > 5) {
                           lines += 1;
                           i = 2;
                           res << std::endl << bdf::types::card("").format(nullptr);
                        }
                        res << p->first->format(p->second);
                     }
                     if (!(lines%2))
                        res << std::endl << bdf::types::card("").format(nullptr);
                     bdf::types::base::out_form = bdf::types::SHORT;
                  }
                  return res.str();
               }

               bdf::types::card card::head = bdf::types::card("<DUMMY>");

               void card::card_split(std::list<std::string> const &inp,
                                     std::list<std::string> &res) {
                  std::string head;

                  res.clear();

                  bool first = true;

                  for (auto pos=inp.begin(); pos!=inp.end(); ++pos) {
                     head = extfem::string::string(pos->substr(0, 8)).trim();
                     // Free Field Format
                     if (head.find(',') != std::string::npos) {
                        if (first) {
                           res.push_back(extfem::string::string(head.substr(0, head.find(','))).trim("*"));
                        }
                        auto tmp(extfem::string::string(*pos).trim(" \t\n"));
                        tmp = tmp.substr(tmp.find(',')+1);

                        auto tail(tmp.substr(tmp.rfind(',')+1));

                        while (tail.length() == 0 || free_form_cont.find(tail.at(0)) != free_form_cont.end()) {
                           if (tail.length() != 0)
                              tmp = tmp.substr(0, tmp.rfind(',')+1);
                           ++pos;
                           tmp.append(extfem::string::string(pos->substr(pos->find(',')+1)).trim(" \t\n"));
                           tail = tmp.substr(tmp.rfind(',')+1);
                        }
                        while (tmp.find(',') != std::string::npos) {
                           res.push_back(extfem::string::string(tmp.substr(0, tmp.find(','))).trim(" \n\t"));
                           tmp = tmp.substr(tmp.find(',')+1);
                        }
                        res.push_back(tmp);
                        first = false;
                        // Long Field Format
                     } else {
                        if (first) {
                           res.push_back(extfem::string::string(head).trim("\t\n*"));
                        }
                        if (head.length() > 0 && head.back() == '*') {
                           std::string tmp(pos->length() > 8 ? pos->substr(8) : "");
                           tmp.resize(64, ' ');
                           if (++pos != inp.end()) {
                              if (pos->length() > 8)
                                 tmp += extfem::string::string((pos)->substr(8)).trim("\t\n");
                           } else {
                              pos--;
                              std::ostringstream msg("Long Field Format: Missing continuation line for record:\n", std::ostringstream::ate);
                              for (auto l : inp) msg << "--> " << l << std::endl;
                              (*warn_report)(msg.str());
                           }
                           tmp.resize(128, ' ');
                           for (int i=0; i<8; ++i) {
                              res.push_back(extfem::string::string(tmp.substr(i*16, 16)).trim(" \t\n"));
                           }
                           // Short Field Format
                        } else {
                           auto tmp(*pos);
                           tmp.resize(80, ' ');
                           tmp = tmp.substr(8);
                           for (int i=0; i<8; ++i) {
                              res.push_back(extfem::string::string(tmp.substr(i*8, 8)).trim(" \t\n"));
                           }
                        }
                        first = false;
                     }
                  }
               }

               std::ostream &card::put(std::ostream &os) const {

                  std::list<std::unique_ptr<format_entry> > entries;

                  this->collect_outdata(entries);

                  os << this->format_outlist(entries);

                  return os << std::endl;
               }
            }

            void dispatch(
               const std::list<std::string> &inp,
               std::unique_ptr<__base::card> &res) {

               res = nullptr;

               if (inp.empty()) {
                  res = std::make_unique<bdf::cards::unknown>(inp);
                  return;
               }

               try {
                  switch (cardtype_map.at(inp.front())) {
                  case GRID:
                     res = std::make_unique<bdf::cards::grid>(inp);
                     break;
                  case CTRIA3:
                     res = std::make_unique<bdf::cards::ctria3>(inp);
                     break;
                  case CQUAD4:
                     res = std::make_unique<bdf::cards::cquad4>(inp);
                     break;
                  case CBEAM:
                     res = std::make_unique<bdf::cards::cbeam>(inp);
                     break;
                  case CBAR:
                     res = std::make_unique<bdf::cards::cbar>(inp);
                     break;
                  case CROD:
                     res = std::make_unique<bdf::cards::crod>(inp);
                     break;
                  case PSHELL:
                     res = std::make_unique<bdf::cards::pshell>(inp);
                     break;
                  case PBEAM:
                     res = std::make_unique<bdf::cards::pbeam>(inp);
                     break;
                  case PBEAML:
                     res = std::make_unique<bdf::cards::pbeaml>(inp);
                     break;
                  case PBAR:
                     res = std::make_unique<bdf::cards::pbar>(inp);
                     break;
                  case PBARL:
                     res = std::make_unique<bdf::cards::pbarl>(inp);
                     break;
                  case PROD:
                     res = std::make_unique<bdf::cards::prod>(inp);
                     break;
                  case MAT1:
                     res = std::make_unique<bdf::cards::mat1>(inp);
                     break;
                  case MAT2:
                     res = std::make_unique<bdf::cards::mat2>(inp);
                     break;
                  case ENDDATA:
                     res = std::make_unique<bdf::cards::enddata>(inp);
                     break;
                  case FORCE:
                     res = std::make_unique<bdf::cards::force>(inp);
                     break;
                  case MOMENT:
                     res = std::make_unique<bdf::cards::moment>(inp);
                     break;
                  case LOAD:
                     res = std::make_unique<bdf::cards::load>(inp);
                     break;
                  case PARAM:
                     res = std::make_unique<bdf::cards::param>(inp);
                     break;
                     // These are not real card types, they can't be returned
                  case UNKNOWN:
                  case BEAM_PROP:
                  case BAR_PROP:
                  case BEAM_BASE:
                     res = std::make_unique<bdf::cards::unknown>(inp);
                  }
               } catch (std::out_of_range) {
                  res = std::make_unique<bdf::cards::unknown>(inp);
               }
            }

            const types unknown::card_type(void) const{
               return UNKNOWN;
            }

            void unknown::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {
               throw errors::error("can't write UNKNOWN.");
               return;
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
// compile-command: "make -C ../.. check -j8"
// End:
