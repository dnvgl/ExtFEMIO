/**
   \file bdf/bdf_cards_cbar.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Defintions for Patran CBAR cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char cID_bdf_cards_cbar[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <sstream>
#include <functional>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef W2A
#undef W2A
#endif

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace bdf{

         using types::entry_type;
         using namespace type_bounds;

         namespace cards{
            namespace {
               static const long cl1 = 1;
               static const double cd0 = 0.;
            }

            bdf::types::card cbar::head = bdf::types::card("CBAR");

            // const entry_type<long> cbar::form_EID(
            //    "EID", bound<long>(&cl1));
            const entry_type<long> cbar::form_PID("PID");
            const entry_type<long> cbar::form_GA("GA");
            const entry_type<long> cbar::form_GB("GB");
            const entry_type<double> cbar::form_X1("X1");
            const entry_type<long> cbar::form_G0(
               "G0", bound<long>(&cl1));
            const entry_type<double> cbar::form_X2(
               "X2", bound<double>(nullptr, nullptr, nullptr, true));
            const entry_type<double> cbar::form_X3(
               "X3", bound<double>(nullptr, nullptr, nullptr, true));
            namespace {
               const char* initVals[8] = {
                  "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO" };
               const std::set<std::string> OFFT_set(initVals, initVals + 8);
            }
            const entry_type<std::string> cbar::form_OFFT(
               "OFFT", bound<std::string>(OFFT_set, "GGG"));
            const entry_type<std::list<int> > cbar::form_PA("PA");
            const entry_type<std::list<int> > cbar::form_PB("PB");
            const entry_type<double> cbar::form_W1A(
               "W1A", bound<double>(nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W2A(
               "W2A", bound<double>(nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W3A(
               "W3A", bound<double>(nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W1B(
               "W1B", bound<double>(nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W2B(
               "W2B", bound<double>(nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W3B(
               "W3B", bound<double>(nullptr, nullptr, &cd0));

            cbar::cbar(std::list<std::string> const &inp) :
               element(inp) {
               this->read(inp);
            }

            cbar::cbar(
               const long *EID, const long *PID,
               const long *GA, const long *GB,
               const double *X1, const double *X2, const double *X3,
               const std::string *OFFT,
               const std::list<int> *PA,
               const std::list<int> *PB,
               const double *W1A, const double *W2A,
               const double *W3A, const double *W1B,
               const double *W2B, const double *W3B) :
               element(EID),
               choose_dir_code(CHOOSE_DIR_CODE::has_DVEC), PID(*PID),
               GA(*GA), GB(*GB), X1(*X1), G0(nullptr), X2(*X2), X3(*X3),
               OFFT(OFFT),
               PA(PA), PB(PB),
               W1A(W1A), W2A(W2A), W3A(W3A),
               W1B(W1B), W2B(W2B), W3B(W3B) {}

            cbar::cbar(
               const long *EID, const long *PID,
               const long *GA, const long *GB, const long *G0,
               const std::string *OFFT,
               const std::list<int> *PA, const std::list<int> *PB,
               const double *W1A, const double *W2A,
               const double *W3A, const double *W1B,
               const double *W2B, const double *W3B) :
               element(EID),
               choose_dir_code(CHOOSE_DIR_CODE::has_DCODE), PID(*PID),
               GA(*GA), GB(*GB), X1(), G0(*G0), X2(), X3(),
               OFFT(OFFT),
               PA(PA), PB(PB),
               W1A(W1A), W2A(W2A), W3A(W3A),
               W1B(W1B), W2B(W2B), W3B(W3B) {}

            void cbar::read(std::list<std::string> const &inp) {
               auto pos = inp.rbegin();

               switch (inp.size()-1) {
               case 16:
                  form_W3B.set_value(W3B, *(pos++));
               case 15:
                  form_W2B.set_value(W2B, *(pos++));
               case 14:
                  form_W1B.set_value(W1B, *(pos++));
               case 13:
                  form_W3A.set_value(W3A, *(pos++));
               case 12:
                  form_W2A.set_value(W2A, *(pos++));
               case 11:
                  form_W1A.set_value(W1A, *(pos++));
               case 10:
                  form_PB.set_value(PB, *(pos++));
               case 9:
                  form_PA.set_value(PA, *(pos++));
               case 8:
                  form_OFFT.set_value(OFFT, *(pos++));
               case 7:
                  form_X3.set_value(X3, *(pos++));
               case 6:
                  form_X2.set_value(X2, *(pos++));
               case 5:
                  try {
                     form_X1.set_value(X1, *pos);
                     if (!X2.is_value || !X3.is_value) {
                        throw errors::parse_error(
                           "CBAR", "Incomplete direction vector.");
                     }
                     G0.is_value = false;
                     choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
                  }
                  catch (errors::float_error) {
                     form_G0.set_value(G0, *pos);
                     X1.is_value = false;
                     choose_dir_code = CHOOSE_DIR_CODE::has_DCODE;
                  }
                  ++pos;
                  form_GB.set_value(GB, *(pos++));
                  form_GA.set_value(GA, *(pos++));
                  form_PID.set_value(PID, *(pos++));
                  // form_EID.set_value(EID, *(pos++));
                  break;
               default:
                  throw errors::parse_error(
                     "CBAR", "Illegal number of entries.");
               }
            }

            void cbar::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {
               res.push_back(format(cbar::head));

               res.push_back(format<long>(this->form_EID, this->EID));
               res.push_back(format<long>(this->form_PID, this->PID));
               res.push_back(format<long>(this->form_GA, this->GA));
               res.push_back(format<long>(this->form_GB, this->GB));
               if (this->choose_dir_code == CHOOSE_DIR_CODE::has_DCODE) {
                  res.push_back(format<long>(this->form_G0, this->G0));
                  if ((bool)this->OFFT || (bool)this->PA || (bool)this->PB || (bool)this->W1A || (bool)this->W2A ||
                      (bool)this->W3A || (bool)this->W1B || (bool)this->W2B || (bool)this->W3B) {
                     res.push_back(format(cbar::empty));
                     res.push_back(format(cbar::empty));
                  }
               }
               else {
                  res.push_back(format<double>(this->form_X1, this->X1));
                  res.push_back(format<double>(this->form_X2, this->X2));
                  res.push_back(format<double>(this->form_X3, this->X3));
               }

               if ((bool)this->OFFT || (bool)this->PA || (bool)this->PB || (bool)this->W1A || (bool)this->W2A ||
                   (bool)this->W3A || (bool)this->W1B || (bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<std::string>(this->form_OFFT, this->OFFT));
               else goto cont;

               if ((bool)this->PA || (bool)this->PB || (bool)this->W1A || (bool)this->W2A || (bool)this->W3A ||
                   (bool)this->W1B || (bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<std::list<int> >(this->form_PA, this->PA));
               else goto cont;
               if ((bool)this->PB || (bool)this->W1A || (bool)this->W2A || (bool)this->W3A || (bool)this->W1B ||
                   (bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<std::list<int> >(this->form_PB, this->PB));
               else goto cont;
               if ((bool)this->W1A || (bool)this->W2A || (bool)this->W3A || (bool)this->W1B || (bool)this->W2B ||
                   (bool)this->W3B)
                  res.push_back(format<double>(this->form_W1A, this->W1A));
               else goto cont;
               if ((bool)this->W2A || (bool)this->W3A || (bool)this->W1B || (bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<double>(this->form_W2A, this->W2A));
               else goto cont;
               if ((bool)this->W3A || (bool)this->W1B || (bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<double>(this->form_W3A, this->W3A));
               else goto cont;
               if ((bool)this->W1B || (bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<double>(this->form_W1B, this->W1B));
               else goto cont;
               if ((bool)this->W2B || (bool)this->W3B)
                  res.push_back(format<double>(this->form_W2B, this->W2B));
               else goto cont;
               if ((bool)this->W3B)
                  res.push_back(format<double>(this->form_W3B, this->W3B));
            cont:
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
