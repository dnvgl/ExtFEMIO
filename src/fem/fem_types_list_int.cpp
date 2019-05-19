/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Sesam FEM data entry types.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_fem_types_list_int[]) =
        "@(#) $Id$";
}

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <vector>
#include <sstream>
#include <algorithm>

#include "fem/types.h"
#include "fem/errors.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
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
    std::vector<int> tmp_l;

    if (! regex_match(inp, list_int_re)) {
        std::string const msg("illegal input (""");
        throw errors::int_error(
            name, msg + inp + """), no integer list!");
    }

    conv.str(inp);
    conv.seekg(0);
    conv >> tmp_d;
    long tmp{static_cast<long>(tmp_d)};

    while (tmp) {
        ldiv_t const divmod = std::div(tmp, static_cast<long>(10));
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

#if defined(_MSC_VER) && _MSC_VER < 1900
	// std::set output to two digit exponential format.
    unsigned int const ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
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

#if defined(_MSC_VER) && _MSC_VER < 1900
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
