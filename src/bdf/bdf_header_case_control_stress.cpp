/**
   \file bdf_header_case_control_stress.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of BDF file header STRESS entries

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

               stress::stress(
                  std::list<describer*> const &_describers,
                  restype const &res, long const &res_n) :
                  res(res), res_n(res_n) {
                  for (auto p : _describers)
                     describers.push_back(std::unique_ptr<describer>(p));
               }

               stress::stress(
                  std::list<describer*> const &describers,
                  restype const &res/*=NONE*/) :
                  stress(describers, res, 0) {}

               stress::stress(
                  std::list<describer*> const &describers,
                  long const &res) :
                  stress(describers, stress::n, res) {}

               std::ostream const& stress::operator<< (std::ostream &os) const {
                  return os << this;
               }


               std::ostream const &stress::put(std::ostream &os) const {
                  os << "STRESS";
                  if (this->describers.size() > 0) {
                     bool first = true;
                     for (auto &p : this->describers) {
                        if (first) {
                           os << "(";
                           first = false;
                        } else
                           os << ", ";
                        os << p->str();
                     }
                     os << ")";
                  }
                  switch (this->res) {
                  case stress::n:
                     os << " = " << this->res_n;
                     break;
                  case stress::ALL:
                     os << " = ALL";
                     break;
                  case stress::NONE:
                     os << " = NONE";
                     break;
                  }
                  return os << std::endl;
               }

               stress::describer::describer(void) {}

               stress::corner::corner(void) {}

               std::string const stress::corner::str(void) const {
                  return "CORNER";
               }

               stress::sort1::sort1(void) {}

               std::string const stress::sort1::str(void) const {
                  return "SORT1";
               }

               stress::print::print(void) {}

               std::string const stress::print::str(void) const {
                  return "PRINT";
               }

               stress::punch::punch(void) {}

               std::string const stress::punch::str(void) const {
                  return "PUNCH";
               }

               stress::phase::phase(void) {}

               std::string const stress::phase::str(void) const {
                  return "PHASE";
               }

               stress::plot::plot(void) {}

               std::string const stress::plot::str(void) const {
                  return "PLOT";
               }

               stress::psdf::psdf(void) {}

               std::string const stress::psdf::str(void) const {
                  return "PSDF";
               }

               stress::crms::crms(void) {}

               std::string const stress::crms::str(void) const {
                  return "CRMS";
               }

               stress::rpunch::rpunch(void) {}

               std::string const stress::rpunch::str(void) const {
                  return "RPUNCH";
               }

               stress::rall::rall(void) {}

               std::string const stress::rall::str(void) const {
                  return "RALL";
               }

               stress::norprint::norprint(void) {}

               std::string const stress::norprint::str(void) const {
                  return "NORPRINT";
               }

               stress::sort2::sort2(void) {}

               std::string const stress::sort2::str(void) const {
                  return "SORT2";
               }

               stress::real::real(void) {}

               std::string const stress::real::str(void) const {
                  return "REAL";
               }

               stress::imag::imag(void) {}

               std::string const stress::imag::str(void) const {
                  return "IMAG";
               }

               stress::atoc::atoc(void) {}

               std::string const stress::atoc::str(void) const {
                  return "ATOC";
               }

               stress::vonmises::vonmises(void) {}

               std::string const stress::vonmises::str(void) const {
                  return "VONMISES";
               }

               stress::maxs::maxs(void) {}

               std::string const stress::maxs::str(void) const {
                  return "MAXS";
               }

               stress::shear::shear(void) {}

               std::string const stress::shear::str(void) const {
                  return "SHEAR";
               }

               stress::center::center(void) {}

               std::string const stress::center::str(void) const {
                  return "CENTER";
               }

               stress::cubic::cubic(void) {}

               std::string const stress::cubic::str(void) const {
                  return "CUBIC";
               }

               stress::sgage::sgage(void) {}

               std::string const stress::sgage::str(void) const {
                  return "SGAGE";
               }

               stress::bilin::bilin(void) {}

               std::string const stress::bilin::str(void) const {
                  return "BILIN";
               }

               stress::rprint::rprint(void) {}

               std::string const stress::rprint::str(void) const {
                  return "RPRINT";
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
