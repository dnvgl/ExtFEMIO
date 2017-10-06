/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for SESAM FEM data entry types.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_types_int[]) =
        "@(#) $Id$";
}

#ifdef __GNUC__
#include "config.h"
#endif

#include <sstream>

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

regex const entry_type<long>::int_re(
    "([[:space:]\\+-]"
    "[[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]])|"
    "([[:space:]]"
    "[[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2})|"
    "([[:space:]\\+-][[:digit:]][.][[:digit:]]{9}[eE][\\+-][[:digit:]]{2})|"
    "(            0.00)",
    regex_constants::ECMAScript
    );

fem_types const entry_type<long>::_type = fem_types::Int;

entry_type<long>::entry_type(std::string const &name) :
        b_type(name), bounds() {}

entry_type<long>::entry_type(
    std::string const &name,
    type_bounds::bound<long> const &bounds) :
        b_type(name), bounds(bounds) {}

long entry_type<long>::operator() (std::string const &inp) const {
    double value;

    if (inp.length() == 0) {
        if (!this->bounds.has_default())
            throw errors::int_error(name, "empty entry without default");
        return this->bounds.get_default();
    } else {
        if (! regex_match(inp, int_re)) {
            std::string msg("illegal input (""");
            throw errors::int_error(name, msg + inp + """), no integer!");
        }

        conv.str(inp);
        conv.seekg(0);
        conv >> value;
    }
    if (!this->bounds.in_bounds(long(value))) {
        std::string msg("boundary condition violated (");
        throw errors::int_error(
            name, msg + name + ")\n(""" + inp + """)");
    }
    return long(value);
}

fem_types entry_type<long>::type() const { return _type; }

std::string entry_type<long>::format(long const &inp) const {

    std::ostringstream res;
    res.imbue(std::locale::classic());

#ifdef _MSC_VER
    // std::set output to two digit exponential format.
    unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

    res.setf(std::ios_base::showpos);
    res.setf(std::ios_base::scientific, std::ios_base::floatfield);
    res.setf(std::ios_base::adjustfield, std::ios::left);

    res.precision(9);
    res.width(16);
    res.fill(' ');

    res << double(inp);
    std::string out(res.str());
    if (out.size() != 16) {
        std::ostringstream msg(
            "output string for value ", std::ostringstream::ate);
        msg << double(inp) << " of incorrect size, got length of " << out.size()
            << " instead of allowed length of 16." << out;
        throw errors::int_error(name, msg.str());
    }

#ifdef _MSC_VER
    // Reset exponetial format to former std::settings.
    _set_output_format(ext_exp_format);
#endif

    return out;
};

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
