/**
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2015 by DNV GL SE
  \brief Definitions for Sesam FEM data entry types.

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

#include <list>
#include <sstream>
#include <algorithm>

#include "fem/types.h"
#include "fem/errors.h"

using namespace ::std;
using namespace ::dnvgl;
using namespace extfem;
using fem::types::entry_type;

#ifdef __GNUC__
using boost::regex;
#else
using std::regex;
#endif
using fem::types::entry_type;

const
#if HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
entry_type<::std::deque<int>>::int_re(
  "[[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]]",
#ifdef HAVE_BOOST_REGEX_HPP
  boost::regex_constants::ECMAScript);
#else
  std::regex_constants::ECMAScript);
#endif

::std::deque<int>*
entry_type<std::deque<int>>::operator() (const std::string &inp) const {
  auto *value =  new std::deque<int>();

  double tmp_d;
  ::std::list<int> tmp_l;
  long tmp;

  if (! regex_match(inp, int_re)) {
    std::string msg("illegal input (""");
    throw errors::int_error(name, msg + inp + """), no integer!");
  }

  istringstream conv(inp);
  conv.imbue(locale("C"));
  conv >> tmp_d;
  tmp = (long)tmp_d;

  while (tmp) {
    ldiv_t divmod = div(tmp, (long)10);
    value->push_back(divmod.rem);
    tmp /= 10;
  }
  ::std::sort(value->begin(), value->end());

  return value;
}

std::string
entry_type<std::deque<int>>::format(
  const std::deque<int> &inp) const {

  std::ostringstream res, res2;

  double value = 0;
  for (auto &p : inp) {
    value *= 10.;
    value += p;
  }

#ifdef _MSC_VER
  // Set output to two digit exponetial format.
  unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

  res << " ";
  res.setf(ios_base::scientific, ios::floatfield);
  res.setf(ios_base::adjustfield, ios::left);

  res.precision(8);
  res.width(15);
  res.fill(' ');

  res << value;
  std::string out(res.str());
  if (out.size() != 16) {
    ::std::ostringstream msg("output string for value ",
                           ::std::ostringstream::ate);
    ::std::copy(inp.begin(), inp.end(),
                ostream_iterator<int>(msg, ", "));
    msg << " of incorrect size, got length of " << out.size()
        << " instead of allowed length of 16.";
    throw errors::output_error(name, msg.str());
  }

#ifdef _MSC_VER
  // Reset exponetial format to former settings.
  _set_output_format(ext_exp_format);
#endif

  return out;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
