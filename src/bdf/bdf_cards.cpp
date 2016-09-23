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
   const char cID_bdf_cards[]
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

   const size_t map_pairs_num = 116;
   const std::pair<std::string, dnvgl::extfem::bdf::cards::types> map_pairs[map_pairs_num] = {
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("GRID", dnvgl::extfem::bdf::cards::types::GRID),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("MAT1", dnvgl::extfem::bdf::cards::types::MAT1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTRIA3", dnvgl::extfem::bdf::cards::types::CTRIA3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CQUAD4", dnvgl::extfem::bdf::cards::types::CQUAD4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PSHELL", dnvgl::extfem::bdf::cards::types::PSHELL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBEAM", dnvgl::extfem::bdf::cards::types::CBEAM),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBEAM", dnvgl::extfem::bdf::cards::types::PBEAM),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBEAML", dnvgl::extfem::bdf::cards::types::PBEAML),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBAR", dnvgl::extfem::bdf::cards::types::CBAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBAR", dnvgl::extfem::bdf::cards::types::PBAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PBARL", dnvgl::extfem::bdf::cards::types::PBARL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CROD", dnvgl::extfem::bdf::cards::types::CROD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PROD", dnvgl::extfem::bdf::cards::types::PROD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("ENDDATA", dnvgl::extfem::bdf::cards::types::ENDDATA),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("MAT2", dnvgl::extfem::bdf::cards::types::MAT2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("FORCE", dnvgl::extfem::bdf::cards::types::FORCE),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("MOMENT", dnvgl::extfem::bdf::cards::types::MOMENT),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CMASS2", dnvgl::extfem::bdf::cards::types::CMASS2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CMASS4", dnvgl::extfem::bdf::cards::types::CMASS4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("GRAV", dnvgl::extfem::bdf::cards::types::GRAV),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("LOAD", dnvgl::extfem::bdf::cards::types::LOAD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAABSF", dnvgl::extfem::bdf::cards::types::CAABSF),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAERO1", dnvgl::extfem::bdf::cards::types::CAERO1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAERO2", dnvgl::extfem::bdf::cards::types::CAERO2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAERO3", dnvgl::extfem::bdf::cards::types::CAERO3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAERO4", dnvgl::extfem::bdf::cards::types::CAERO4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAERO5", dnvgl::extfem::bdf::cards::types::CAERO5),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAXIF2", dnvgl::extfem::bdf::cards::types::CAXIF2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAXIF3", dnvgl::extfem::bdf::cards::types::CAXIF3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAXIF4", dnvgl::extfem::bdf::cards::types::CAXIF4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CAXIFi", dnvgl::extfem::bdf::cards::types::CAXIFi),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBEND", dnvgl::extfem::bdf::cards::types::CBEND),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBUSH1D", dnvgl::extfem::bdf::cards::types::CBUSH1D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBUSH", dnvgl::extfem::bdf::cards::types::CBUSH),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CBUTT", dnvgl::extfem::bdf::cards::types::CBUTT),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CCONEAX", dnvgl::extfem::bdf::cards::types::CCONEAX),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CCRSFIL", dnvgl::extfem::bdf::cards::types::CCRSFIL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP1", dnvgl::extfem::bdf::cards::types::CDAMP1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP1D", dnvgl::extfem::bdf::cards::types::CDAMP1D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP2", dnvgl::extfem::bdf::cards::types::CDAMP2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP2D", dnvgl::extfem::bdf::cards::types::CDAMP2D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP3", dnvgl::extfem::bdf::cards::types::CDAMP3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP4", dnvgl::extfem::bdf::cards::types::CDAMP4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDAMP5", dnvgl::extfem::bdf::cards::types::CDAMP5),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM1", dnvgl::extfem::bdf::cards::types::CDUM1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM2", dnvgl::extfem::bdf::cards::types::CDUM2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM3", dnvgl::extfem::bdf::cards::types::CDUM3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM4", dnvgl::extfem::bdf::cards::types::CDUM4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM5", dnvgl::extfem::bdf::cards::types::CDUM5),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM6", dnvgl::extfem::bdf::cards::types::CDUM6),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM7", dnvgl::extfem::bdf::cards::types::CDUM7),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM8", dnvgl::extfem::bdf::cards::types::CDUM8),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CDUM9", dnvgl::extfem::bdf::cards::types::CDUM9),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CELAS1", dnvgl::extfem::bdf::cards::types::CELAS1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CELAS1D", dnvgl::extfem::bdf::cards::types::CELAS1D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CELAS2", dnvgl::extfem::bdf::cards::types::CELAS2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CELAS2D", dnvgl::extfem::bdf::cards::types::CELAS2D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CELAS3", dnvgl::extfem::bdf::cards::types::CELAS3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CELAS4", dnvgl::extfem::bdf::cards::types::CELAS4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CFILLET", dnvgl::extfem::bdf::cards::types::CFILLET),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CFLUID2", dnvgl::extfem::bdf::cards::types::CFLUID2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CFLUID3", dnvgl::extfem::bdf::cards::types::CFLUID3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CFLUID4", dnvgl::extfem::bdf::cards::types::CFLUID4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CGAP", dnvgl::extfem::bdf::cards::types::CGAP),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CHACAB", dnvgl::extfem::bdf::cards::types::CHACAB),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CHACBR", dnvgl::extfem::bdf::cards::types::CHACBR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CHBDYE", dnvgl::extfem::bdf::cards::types::CHBDYE),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CHBDYG", dnvgl::extfem::bdf::cards::types::CHBDYG),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CHBDYP", dnvgl::extfem::bdf::cards::types::CHBDYP),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CHEXA", dnvgl::extfem::bdf::cards::types::CHEXA),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CMASS1", dnvgl::extfem::bdf::cards::types::CMASS1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CMASS3", dnvgl::extfem::bdf::cards::types::CMASS3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("COMBWLD", dnvgl::extfem::bdf::cards::types::COMBWLD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CONM1", dnvgl::extfem::bdf::cards::types::CONM1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CONM2", dnvgl::extfem::bdf::cards::types::CONM2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CONROD", dnvgl::extfem::bdf::cards::types::CONROD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CPENTA", dnvgl::extfem::bdf::cards::types::CPENTA),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CQUAD8", dnvgl::extfem::bdf::cards::types::CQUAD8),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CQUAD", dnvgl::extfem::bdf::cards::types::CQUAD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CQUADR", dnvgl::extfem::bdf::cards::types::CQUADR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CQUADX", dnvgl::extfem::bdf::cards::types::CQUADX),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CRAC2D", dnvgl::extfem::bdf::cards::types::CRAC2D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CRAC3D", dnvgl::extfem::bdf::cards::types::CRAC3D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CSHEAR", dnvgl::extfem::bdf::cards::types::CSHEAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CSLOT3", dnvgl::extfem::bdf::cards::types::CSLOT3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CSLOT4", dnvgl::extfem::bdf::cards::types::CSLOT4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CSPOT", dnvgl::extfem::bdf::cards::types::CSPOT),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTETRA", dnvgl::extfem::bdf::cards::types::CTETRA),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTRIA6", dnvgl::extfem::bdf::cards::types::CTRIA6),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTRIAR", dnvgl::extfem::bdf::cards::types::CTRIAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTRIAX6", dnvgl::extfem::bdf::cards::types::CTRIAX6),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTRIAX", dnvgl::extfem::bdf::cards::types::CTRIAX),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CTUBE", dnvgl::extfem::bdf::cards::types::CTUBE),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("CVISC", dnvgl::extfem::bdf::cards::types::CVISC),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("ELEMENT", dnvgl::extfem::bdf::cards::types::ELEMENT),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("GENEL", dnvgl::extfem::bdf::cards::types::GENEL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("GMINTC", dnvgl::extfem::bdf::cards::types::GMINTC),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("GMINTS", dnvgl::extfem::bdf::cards::types::GMINTS),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("PLOTEL", dnvgl::extfem::bdf::cards::types::PLOTEL),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RBAR1", dnvgl::extfem::bdf::cards::types::RBAR1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RBAR", dnvgl::extfem::bdf::cards::types::RBAR),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RBE1", dnvgl::extfem::bdf::cards::types::RBE1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RBE2", dnvgl::extfem::bdf::cards::types::RBE2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RBE3", dnvgl::extfem::bdf::cards::types::RBE3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RBE3D", dnvgl::extfem::bdf::cards::types::RBE3D),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RJOINT", dnvgl::extfem::bdf::cards::types::RJOINT),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RROD", dnvgl::extfem::bdf::cards::types::RROD),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RSPLINE", dnvgl::extfem::bdf::cards::types::RSPLINE),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RSSCON", dnvgl::extfem::bdf::cards::types::RSSCON),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RTRPLT1", dnvgl::extfem::bdf::cards::types::RTRPLT1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("RTRPLT", dnvgl::extfem::bdf::cards::types::RTRPLT),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("SPLINE1", dnvgl::extfem::bdf::cards::types::SPLINE1),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("SPLINE2", dnvgl::extfem::bdf::cards::types::SPLINE2),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("SPLINE3", dnvgl::extfem::bdf::cards::types::SPLINE3),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("SPLINE4", dnvgl::extfem::bdf::cards::types::SPLINE4),
      std::pair<std::string, dnvgl::extfem::bdf::cards::types>("SPLINE5", dnvgl::extfem::bdf::cards::types::SPLINE5)};

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

               card const *card::operator() (std::list<std::string> const &inp) {
                  this->read(inp);
                  return this;
               }

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
                     bdf::types::base::out_form = bdf::types::out_form_type::LONG;
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
                     bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
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

                  if (entries.size()>0)
                     os << this->format_outlist(entries) << std::endl;

                  return os;
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
                  case types::GRID:
                     res = std::make_unique<bdf::cards::grid>(inp);
                     break;
                  case types::CTRIA3:
                     res = std::make_unique<bdf::cards::ctria3>(inp);
                     break;
                  case types::CQUAD4:
                     res = std::make_unique<bdf::cards::cquad4>(inp);
                     break;
                  case types::CBEAM:
                     res = std::make_unique<bdf::cards::cbeam>(inp);
                     break;
                  case types::CBAR:
                     res = std::make_unique<bdf::cards::cbar>(inp);
                     break;
                  case types::CROD:
                     res = std::make_unique<bdf::cards::crod>(inp);
                     break;
                  case types::PSHELL:
                     res = std::make_unique<bdf::cards::pshell>(inp);
                     break;
                  case types::PBEAM:
                     res = std::make_unique<bdf::cards::pbeam>(inp);
                     break;
                  case types::PBEAML:
                     res = std::make_unique<bdf::cards::pbeaml>(inp);
                     break;
                  case types::PBAR:
                     res = std::make_unique<bdf::cards::pbar>(inp);
                     break;
                  case types::PBARL:
                     res = std::make_unique<bdf::cards::pbarl>(inp);
                     break;
                  case types::PROD:
                     res = std::make_unique<bdf::cards::prod>(inp);
                     break;
                  case types::MAT1:
                     res = std::make_unique<bdf::cards::mat1>(inp);
                     break;
                  case types::MAT2:
                     res = std::make_unique<bdf::cards::mat2>(inp);
                     break;
                  case types::ENDDATA:
                     res = std::make_unique<bdf::cards::enddata>(inp);
                     break;
                  case types::FORCE:
                     res = std::make_unique<bdf::cards::force>(inp);
                     break;
                  case types::MOMENT:
                     res = std::make_unique<bdf::cards::moment>(inp);
                     break;
                  case types::CMASS2:
                     res = std::make_unique<bdf::cards::cmass2>(inp);
                     break;
                  case types::CMASS4:
                     res = std::make_unique<bdf::cards::cmass4>(inp);
                     break;
                  case types::GRAV:
                     res = std::make_unique<bdf::cards::grav>(inp);
                     break;
                  case types::LOAD:
                     res = std::make_unique<bdf::cards::load>(inp);
                     break;
                  case types::PARAM:
                     res = std::make_unique<bdf::cards::param>(inp);
                     break;
                  /// Elements only supported to allow counting.
                  case types::CAABSF:
                  case types::CAERO1:
                  case types::CAERO2:
                  case types::CAERO3:
                  case types::CAERO4:
                  case types::CAERO5:
                  case types::CAXIF2:
                  case types::CAXIF3:
                  case types::CAXIF4:
                  case types::CBEND:
                  case types::CBUSH1D:
                  case types::CBUSH:
                  case types::CBUTT:
                  case types::CCONEAX:
                  case types::CCRSFIL:
                  case types::CDAMP1:
                  case types::CDAMP1D:
                  case types::CDAMP2:
                  case types::CDAMP2D:
                  case types::CDAMP3:
                  case types::CDAMP4:
                  case types::CDAMP5:
                  case types::CDUM1:
                  case types::CDUM2:
                  case types::CDUM3:
                  case types::CDUM4:
                  case types::CDUM5:
                  case types::CDUM6:
                  case types::CDUM7:
                  case types::CDUM8:
                  case types::CDUM9:
                  case types::CELAS1:
                  case types::CELAS1D:
                  case types::CELAS2:
                  case types::CELAS2D:
                  case types::CELAS3:
                  case types::CELAS4:
                  case types::CFILLET:
                  case types::CFLUID2:
                  case types::CFLUID3:
                  case types::CFLUID4:
                  case types::CGAP:
                  case types::CHACAB:
                  case types::CHACBR:
                  case types::CHBDYE:
                  case types::CHBDYG:
                  case types::CHBDYP:
                  case types::CHEXA:
                  case types::CMASS1:
                  case types::CMASS3:
                  case types::COMBWLD:
                  case types::CONM1:
                  case types::CONM2:
                  case types::CONROD:
                  case types::CPENTA:
                  case types::CQUAD8:
                  case types::CQUAD:
                  case types::CQUADR:
                  case types::CQUADX:
                  case types::CRAC2D:
                  case types::CRAC3D:
                  case types::CSHEAR:
                  case types::CSLOT3:
                  case types::CSLOT4:
                  case types::CSPOT:
                  case types::CTETRA:
                  case types::CTRIA6:
                  case types::CTRIAR:
                  case types::CTRIAX6:
                  case types::CTRIAX:
                  case types::CTUBE:
                  case types::CVISC:
                  case types::ELEMENT:
                  case types::GENEL:
                  case types::GMINTC:
                  case types::GMINTS:
                  case types::PLOTEL:
                  case types::RBAR1:
                  case types::RBAR:
                  case types::RBE1:
                  case types::RBE2:
                  case types::RBE3:
                  case types::RBE3D:
                  case types::RJOINT:
                  case types::RROD:
                  case types::RSPLINE:
                  case types::RSSCON:
                  case types::RTRPLT1:
                  case types::RTRPLT:
                  case types::SPLINE1:
                  case types::SPLINE2:
                  case types::SPLINE3:
                  case types::SPLINE4:
                  case types::SPLINE5:
                     res = std::make_unique<bdf::cards::__base::element>(inp);
                     break;
                  /// These are not real card types, they can't be returned
                  case types::UNKNOWN:
                  case types::BEAM_PROP:
                  case types::BAR_PROP:
                  case types::BEAM_BASE:
                  case types::CAXIFi:
                     res = std::make_unique<bdf::cards::unknown>(inp);
                  }
               } catch (std::out_of_range) {
                  res = std::make_unique<bdf::cards::unknown>(inp);
               }
            }

            unknown::unknown(const std::list<std::string> &inp) :
                  card(inp), content(inp) {};

            const types unknown::card_type(void) const{
               return types::UNKNOWN;
            }

            void unknown::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {
               throw errors::error("UNKNOWN", "can't write UNKNOWN.");
               return;
            }

            void unknown::read(const std::list<std::string> &inp) {
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
