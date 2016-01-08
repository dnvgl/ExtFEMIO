/**
   \file bdf/bdf_types_list_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

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

#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <sstream>
#include <iomanip>

#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl;
using namespace extfem;

#ifdef __GNUC__
using ::boost::regex;
#else
using ::std::regex;
#endif
using bdf::types::entry_type;
using bdf::types::entry_value;

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace types {
            template <>
            entry_value<::std::deque<int>>::entry_value(
               const ::std::deque<int> &value, const bool &is_value) :
                         value(value.begin(), value.end()),
                         is_value(is_value) {
            };

            template <>
            entry_value<::std::deque<int>>::entry_value(
               const entry_value<::std::deque<int>> &val) :
                         value(val.value.begin(), val.value.end()),
                         is_value(val.is_value) {
            };

            template <>
            entry_value<::std::deque<int>>::entry_value(
               const ::std::deque<int> *value) {
               if (!value) {
                  this->is_value = false;
               } else {
                  is_value = true;
                  copy(value->begin(), value->end(),
                       back_inserter(this->value));
               }
            }
         }
      }
   }
}

const regex entry_type<::std::deque<int>>::int_re("[[:digit:]]*");

void
entry_type<::std::deque<int>>::set_value(
   entry_value<::std::deque<int>> &val, const ::std::string inp) const {

   auto sval = extfem::string::string(inp).trim();

   if (! regex_match(sval, int_re)) {
      ::std::string msg(name + ":illegal input (""");
      throw errors::types_error(msg + sval + """), no integer in list");
   }
   val.is_value = true;
   for (auto pos = sval.begin(); pos != sval.end(); ++pos)
      val.value.push_back((int)(*pos - '0'));

   return;
}

entry_value<::std::deque<int>>
entry_type<::std::deque<int>>::operator() (const ::std::string &inp) const {
   entry_value<::std::deque<int>> val;
   this->set_value(val, inp);
   return val;
}

::std::string
entry_type<::std::deque<int>>::format(const void *inp) const  {
   if (!inp)
      return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
   else {
      entry_value<::std::deque<int>> val((::std::deque<int>*)inp);
      return this->format(val);
   }
};

::std::string
entry_type<::std::deque<int>>::format(const entry_value<::std::deque<int>> &inp) const {

   if (!inp)
      return bdf::types::empty().format(nullptr);

   ::std::ostringstream res1, res2;

   for (const auto &p : inp.value) res1 << p;

   ::std::string inp_proc(res1.str());

   switch (out_form) {
   case LONG:
      res2 << std::setiosflags(std::ios::right)
           << std::setfill(' ') << std::setw(16) << inp_proc;
      // res2.setf(ios_base::right, ios_base::adjustfield);
      // res2.fill(' ');
      // res2 << setw(16) << inp_proc;
      break;
   case SHORT:
      res2.setf(ios_base::right, ios_base::adjustfield);
      res2.fill(' ');
      res2 << setw(8) << inp_proc;
      break;
   case FREE:
      res2 << inp_proc;
      break;
   }

   ::std::string out(res2.str());
   if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
      ::std::ostringstream msg("output string for value ", ::std::ostringstream::ate);
      msg << inp_proc << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of " << out_form << ".";
      throw errors::output_error(name, msg.str());
   }
   return out;
}

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace types {
            template <>
            inline void
            entry_value<::std::deque<int>>::push_back(const long &inp) {
               value.push_back(inp);
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
