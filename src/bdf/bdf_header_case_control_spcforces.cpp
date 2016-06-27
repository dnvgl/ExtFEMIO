/**
   \file bdf_header_case_control_spcforces.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Siupport for BDF SPCFORCES case control entries.

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

#include "bdf/header.h"


namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace header {
            namespace case_control {

               spcforces::spcforces(
                  std::list<describer*> const &_describers, restype const &res, long const &n) :
                  res(res), res_n(n) {
                  for (auto p : _describers)
                     describers.push_back(std::unique_ptr<describer>(p));
               }

               spcforces::spcforces(
                  std::list<describer*> const &describers, restype const &res) :
                  spcforces(describers, res, 0) {}

               spcforces::spcforces(
                  std::list<describer*> const &describers, long const &res) :
                  spcforces(describers, spcforces::n, res) {}

               std::ostream const &spcforces::operator<< (std::ostream &os) const {
                  return os << *this;
               }

               std::ostream const &operator<< (std::ostream &os, spcforces const &entry) {
                  os << "SPCFORCES";
                  if (entry.describers.size() > 0) {
                     bool first = true;
                     for (auto &p : entry.describers) {
                        if (first) {
                           os << "(";
                           first = false;
                        } else
                           os << ", ";
                        os << p->str();
                     }
                     os << ")";
                  }
                  switch (entry.res) {
                  case spcforces::n:
                     os << " = " << entry.res_n;
                     break;
                  case spcforces::ALL:
                     os << " = ALL";
                     break;
                  case spcforces::NONE:
                     os << " = NONE";
                     break;
                  }
                  return os << std::endl;
               }

               spcforces::describer::describer(void) {}

               spcforces::print::print(void) {}
               std::string const spcforces::print::str(void) const {
                  return "PRINT";
               }

               spcforces::nozprint::nozprint(void) {}
               std::string const spcforces::nozprint::str(void) const {
                  return "NOZPRINT";
               }

               spcforces::sort2::sort2(void) {}
               std::string const spcforces::sort2::str(void) const {
                  return "SORT2";
               }

               spcforces::punch::punch(void) {}
               std::string const spcforces::punch::str(void) const {
                  return "PUNCH";
               }

               spcforces::imag::imag(void) {}
               std::string const spcforces::imag::str(void) const {
                  return "IMAG";
               }

               spcforces::phase::phase(void) {}
               std::string const spcforces::phase::str(void) const {
                  return "PHASE";
               }

               spcforces::psdf::psdf(void) {}
               std::string const spcforces::psdf::str(void) const {
                  return "PSDF";
               }

               spcforces::crms::crms(void) {}
               std::string const spcforces::crms::str(void) const {
                  return "CRMS";
               }

               spcforces::rpunch::rpunch(void) {}
               std::string const spcforces::rpunch::str(void) const {
                  return "RPUNCH";
               }

               spcforces::rall::rall(void) {}
               std::string const spcforces::rall::str(void) const {
                  return "RALL";
               }

               spcforces::norprint::norprint(void) {}
               std::string const spcforces::norprint::str(void) const {
                  return "NORPRINT";
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
// compile-command: "make test"
// End:
