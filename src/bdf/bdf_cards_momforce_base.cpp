/**
   \file bdf/bdf_cards_momforce_base.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF `FORCE` and `MOMENT` cards.

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

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
   static const long cl0 = 0, cl1 = 1;
   static const double cd0 = 0.;
}

namespace dnvgl {
   namespace extfem {
      namespace bdf{

         using types::entry_type;
         using namespace type_bounds;

         namespace cards {
            namespace __base {

               const entry_type<long> momforce::form_SID(
                  "SID", bound<long>(&cl1));
               const entry_type<long> momforce::form_G(
                  "G", bound<long>(&cl1));
               const entry_type<long> momforce::form_CID(
                  "CID", bound<long>(&cl0, nullptr, &cl0));
               const entry_type<double> momforce::form_F("F");
               const entry_type<double> momforce::form_N1(
                  "N1", bound<double>(nullptr, nullptr, &cd0));
               const entry_type<double> momforce::form_N2(
                  "N2", bound<double>(nullptr, nullptr, &cd0));
               const entry_type<double> momforce::form_N3(
                  "N3", bound<double>(nullptr, nullptr, &cd0));

               momforce::momforce(void) : card() {}

               momforce::momforce(const std::list<std::string> &inp) :
                  card(inp) {
                  this->read(inp);
               }

               momforce::momforce(
                  const long *SID, const long *G, const long *CID,
                  const double *F,
                  const double *N1, const double *N2, const double *N3) :
                  SID(*SID), G(*G), CID(*CID), F(*F), N1(N1), N2(N2), N3(N3) {}

               __base::card const *momforce::operator() (
                     const long *SID, const long *G, const long *CID,
                     const double *F,
                     const double *N1, const double *N2/*=nullptr*/, const double *N3/*=nullptr*/) {
                  this->SID = *SID;
                  this->G = *G;
                  this->CID = *CID;
                  this->F = *F;
                  this->N1 = N1;
                  if (N2)
                     this->N2 = N2;
                  else
                     this->N2 = nullptr;
                  if (N3)
                     this->N3 = N3;
                  else
                     this->N3 = nullptr;
                  return this;
               }


               void momforce::read(std::list<std::string> const &inp) {

                  auto pos = inp.rbegin();

                  form_N2.set_value(N2, "");
                  form_N3.set_value(N3, "");

                  switch (inp.size()-1) {
                  case 8:
                     ++pos;
                  case 7:
                     form_N3.set_value(N3, *(pos++));
                  case 6:
                     form_N2.set_value(N2, *(pos++));
                  case 5:
                     form_N1.set_value(N1, *(pos++));
                     if (N1 == 0. && N2 == 0. && N3 == 0.) {
                        throw errors::parse_error(
                           "FORCE/MOMENT", "At least one of N1, N2, and N3 has to be != 0..");
                     }
                     form_F.set_value(F, *(pos++));
                     form_CID.set_value(CID, *(pos++));
                     form_G.set_value(G, *(pos++));
                     form_SID.set_value(SID, *(pos++));
                     break;
                  default:
                     throw errors::parse_error("FORCE/MOMENT", "Illegal number of entries.");
                  }
               }

               void momforce::collect_outdata (
                  std::list<std::unique_ptr<format_entry> > &res) const {
                  res.push_back(get_head());

                  res.push_back(format<long>(form_SID, SID));
                  res.push_back(format<long>(form_G, G));
                  res.push_back(format<long>(form_CID, CID));
                  res.push_back(format<double>(form_F, F));
                  res.push_back(format<double>(form_N1, N1));
                  if (N2 || N3)
                     res.push_back(format<double>(form_N2, N2));
                  if (N3)
                     res.push_back(format<double>(form_N3, N3));
                  return;
               }
            }

            force::force(void) : __base::momforce() {}

            force::force(const std::list<std::string> &inp) :
               __base::momforce(inp) {}

            force::force(
               const long *SID, const long *G, const long *CID,
               const double *F,
               const double *N1, const double *N2/*=nullptr*/, const double *N3/*=nullptr*/) :
               __base::momforce(SID, G, CID, F, N1, N2, N3) {};

            bdf::types::card force::head = bdf::types::card("FORCE");

            std::unique_ptr<format_entry> force::get_head(void) const {
               return format(force::head);
            }

            const types force::card_type(void) const {
               return FORCE;
            }

            moment::moment(void) : __base::momforce() {}

            moment::moment(const std::list<std::string> &inp) :
               __base::momforce(inp) {}

            moment::moment(
               const long *SID, const long *G, const long *CID,
               const double *F,
               const double *N1, const double *N2/*=nullptr*/, const double *N3/*=nullptr*/) :
                  __base::momforce(SID, G, CID, F, N1, N2, N3) {};

            bdf::types::card moment::head = bdf::types::card("MOMENT");

            std::unique_ptr<format_entry> moment::get_head(void) const {
               return format(moment::head);
            }

            const types moment::card_type(void) const {
               return MOMENT;
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
