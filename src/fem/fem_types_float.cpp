/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for SESAM FEM entry types.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_types_float[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <sstream>

#ifdef __GNUC__
#include "config.h"
#endif

#ifdef _MSC_VER
#include <stdio.h>
#endif

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

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

using namespace dnvgl::extfem::fem;
using namespace types;

regex const entry_type<double>::float_re(
    "([[:space:]]*[[:space:]+-]?"
    "[[:digit:]][.][[:digit:]]+[eE][\\+-][[:digit:]]{2,3}"
    "[[:space:]]*)", regex_constants::ECMAScript );

fem_types const entry_type<double>::_type = fem_types::Float;

entry_type<double>::entry_type(std::string const &name) :
        b_type(name), bounds() {}

entry_type<double>::entry_type(
    std::string const &name,
    type_bounds::bound<double> const &bounds) :
        b_type(name), bounds(bounds) {}

double entry_type<double>::operator() (std::string const &inp) const {
    double value;

    if (inp.length() == 0) {
        if (!this->bounds.has_default())
            throw errors::float_error(name, "empty entry without default");
        value = this->bounds.get_default();
    }
    else {
        if (!regex_match(inp, float_re)) {
            std::string msg("illegal input, (""");
            throw errors::float_error(name, msg + inp + """), no float!");
        }

        conv.str(inp);
        conv.seekg(0);
        conv >> value;
    }
    if (!this->bounds.in_bounds(value)) {
        std::string msg("boundary condition violated (");
        throw errors::float_error(
            name, msg + name + ")\n(""" + inp + """)");
    }
    return value;
}

fem_types entry_type<double>::type() const {return _type;};

std::string entry_type<double>::format(double const &inp) const {

    std::ostringstream res;
    res.imbue(std::locale::classic());

#ifdef _MSC_VER
    // std::set output to two digit exponetial format.
    unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

    res.setf(std::ios_base::showpos);
    res.setf(std::ios_base::scientific, std::ios::floatfield);
    res.setf(std::ios_base::adjustfield, std::ios::left);

    res.precision(9);
    res.width(16);
    res.fill(' ');

    res << inp;
    std::string out(res.str());
    if (out.size() != 16) {
        std::ostringstream msg("output string for value ", std::ostringstream::ate);
        msg << inp << " of incorrect size, got length of " << out.size()
            << " instead of allowed length of 16.";
        throw errors::output_error(name, msg.str());
    }

#ifdef _MSC_VER
    // Reset exponetial format to former std::settings.
    _set_output_format(ext_exp_format);
#endif

    return out;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
