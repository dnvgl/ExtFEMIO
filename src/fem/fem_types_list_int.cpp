/**
   \file fem/fem_types_list_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Sesam FEM data entry types.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_types_list_int[]_EXTFEMIO_UNUSED =
        "@(#) $Id$";
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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef HAVE_BOOST_REGEX_HPP
using namespace boost;
#else
using namespace std;
#endif

using namespace dnvgl::extfem::fem::types;

const regex entry_type<std::vector<int> >::list_int_re(
    "(            0.00)|"
    "([[:space:]]"
    "[[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2})|"
    "([[:space:]\\+-]"
    "[[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]])|"
    "([[:space:]\\+-][[:digit:]][.][[:digit:]]{9}[eE][\\+-][[:digit:]]{2})",
    regex_constants::ECMAScript);

fem_types const entry_type<std::vector<int> >::_type = fem_types::List;

entry_type<std::vector<int> >::entry_type(std::string const &name) :
        b_type(name) {}

void entry_type<std::vector<int> >::operator() (
    std::vector<int> &value, std::string const &inp) const {

    double tmp_d;
    std::list<int> tmp_l;
    long tmp;

    if (! regex_match(inp, list_int_re)) {
        std::string msg("illegal input (""");
        throw errors::int_error(
            name, msg + inp + """), no integer list!");
    }

    conv.str(inp);
    conv.seekg(0);
    conv >> tmp_d;
    tmp = static_cast<long>(tmp_d);

    while (tmp) {
        ldiv_t divmod = std::div(tmp, static_cast<long>(10));
        value.push_back(divmod.rem);
        tmp /= 10;
    }
    sort(value.begin(), value.end());

    return;
}

inline fem_types entry_type<std::vector<int> >::type() const {
    return _type;
}

std::string entry_type<std::vector<int> >::format(
    std::vector<int> const &inp) const {

    std::ostringstream res, res2;
    res.imbue(std::locale::classic());
    res2.imbue(std::locale::classic());

    double value = 0;
    for (auto &p : inp) {
        value *= 10.;
        value += p;
    }

#ifdef _MSC_VER
    // std::set output to two digit exponential format.
    unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

    res.setf(std::ios_base::scientific, std::ios::floatfield);
    res.setf(std::ios_base::adjustfield, std::ios::left);

    res << " ";
    res.precision(9);
    res.width(15);
    res.fill(' ');

    res << value;
    std::string out(res.str());
    if (out.size() != 16) {
        std::ostringstream msg(
            "output string for value ",
            std::ostringstream::ate);
        copy(
            inp.begin(), inp.end(),
            std::ostream_iterator<int>(msg, ", "));
        msg << " of incorrect size, got length of " << out.size()
            << " instead of allowed length of 16. " << "!" << out << "!";
        throw errors::output_error(name, msg.str());
    }

#ifdef _MSC_VER
    // Reset exponential output format to former std::settings.
    _set_output_format(ext_exp_format);
#endif

    return out;
};


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
