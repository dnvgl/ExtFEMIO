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
   const char  cID[]
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

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long cl1 = 1;
   static const double cd0 = 0.;
}

namespace dnvgl {
   namespace extfem {
      namespace bdf{
         namespace cards{

            bdf::types::card cbar::head = bdf::types::card("CBAR");

            const entry_type<long> cbar::form_EID(
               "EID", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<long> cbar::form_PID("PID");
            const entry_type<long> cbar::form_GA("GA");
            const entry_type<long> cbar::form_GB("GB");
            const entry_type<double> cbar::form_X1("X1");
            const entry_type<long> cbar::form_G0(
               "G0", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<double> cbar::form_X2(
               "X2", bdf::type_bounds::bound<double>(
                  nullptr, nullptr, nullptr, true));
            const entry_type<double> cbar::form_X3(
               "X3", bdf::type_bounds::bound<double>(
                  nullptr, nullptr, nullptr, true));
            namespace {
               const char* initVals[8] = {
                  "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO" };
               const std::set<std::string> OFFT_set(initVals, initVals + 8);
            }
            const entry_type<std::string> cbar::form_OFFT(
               "OFFT", bdf::type_bounds::bound<std::string>(OFFT_set, "GGG"));

            const entry_type<std::deque<int>> cbar::form_PA("PA");
            const entry_type<std::deque<int>> cbar::form_PB("PB");
            const entry_type<double> cbar::form_W1A(
               "W1A",
               bdf::type_bounds::bound<double>(
                  nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W2A(
               "W2A",
               bdf::type_bounds::bound<double>(
                  nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W3A(
               "W3A",
               bdf::type_bounds::bound<double>(
                  nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W1B(
               "W1B",
               bdf::type_bounds::bound<double>(
                  nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W2B(
               "W2B",
               bdf::type_bounds::bound<double>(
                  nullptr, nullptr, &cd0));
            const entry_type<double> cbar::form_W3B(
               "W3B",
               bdf::type_bounds::bound<double>(
                  nullptr, nullptr, &cd0));

            cbar::cbar(const std::deque<std::string> &inp) :
               card(inp) {

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
                     choose_dir_code = has_DVEC;
                  }
                  catch (errors::float_error) {
                     form_G0.set_value(G0, *pos);
                     X1.is_value = false;
                     choose_dir_code = has_DCODE;
                  }
                  ++pos;
                  form_GB.set_value(GB, *(pos++));
                  form_GA.set_value(GA, *(pos++));
                  form_PID.set_value(PID, *(pos++));
                  form_EID.set_value(EID, *(pos++));
                  break;
               default:
                  throw errors::parse_error(
                     "CBAR", "Illegal number of entries.");
               }
            };

            cbar::cbar(
               const long *EID, const long *PID,
               const long *GA, const long *GB,
               const double *X1, const double *X2, const double *X3,
               const std::string *OFFT,
               const std::deque<int> *PA,
               const std::deque<int> *PB,
               const double *W1A, const double *W2A,
               const double *W3A, const double *W1B,
               const double *W2B, const double *W3B) :
               choose_dir_code(has_DVEC), EID(*EID), PID(*PID),
               GA(*GA), GB(*GB), X1(*X1), G0(nullptr), X2(*X2), X3(*X3),
               OFFT(OFFT),
               PA(PA), PB(PB),
               W1A(W1A), W2A(W2A), W3A(W3A),
               W1B(W1B), W2B(W2B), W3B(W3B) {};

            cbar::cbar(
               const long *EID, const long *PID,
               const long *GA, const long *GB, const long *G0,
               const std::string *OFFT,
               const std::deque<int> *PA, const std::deque<int> *PB,
               const double *W1A, const double *W2A,
               const double *W3A, const double *W1B,
               const double *W2B, const double *W3B) :
               choose_dir_code(has_DCODE), EID(*EID), PID(*PID),
               GA(*GA), GB(*GB), X1(), G0(*G0), X2(), X3(),
               OFFT(OFFT),
               PA(PA), PB(PB),
               W1A(W1A), W2A(W2A), W3A(W3A),
               W1B(W1B), W2B(W2B), W3B(W3B) {};


            std::ostream& cbar::operator<<(std::ostream& os) const {
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
// compile-command: "make -C ../.. check -j 8"
// End:
