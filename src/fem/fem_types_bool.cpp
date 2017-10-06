/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implemention of bool boundaries for Sesam FEM IO.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_types_bool[]) =
        "@(#) $Id$";
}

#include <sstream>

#include "fem/types.h"

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

regex const entry_type<bool>::bool_re(
    "([[:space:]]*[[:space:]\\+-]?[01][.][0]*([eE][\\+-][[:digit:]]{2,3})?[[:space:]]*)",
    regex_constants::ECMAScript
    );

entry_type<bool>::entry_type(std::string const &name) :
        b_type(name), bounds() {}

bool entry_type<bool>::operator() (std::string const &inp) const {
    double value;

    if (inp.length() == 0) {
        if (!this->bounds.has_default())
            throw errors::bool_error(name, "empty entry without default");
        return this->bounds.get_default();
    }
    else {
        if (!regex_match(inp, bool_re)) {
            std::string msg("illegal input (""");
            throw errors::bool_error(name, msg + inp + """), no bool!");
        }

        conv.str(inp);
        conv.seekg(0);
        conv >> value;
    }
    if (value == 1.) return true;
    else if (value == 0.) return false;
    else {
        std::string msg("boundary condition violated (");
        throw errors::bool_error(
            name, msg + name + ")\n(""" + inp + """)");
    }
}

fem_types entry_type<bool>::type() const { return _type; }

std::string entry_type<bool>::format(bool const &inp) {
    if (inp) return "           +1.00";
    else return "           +0.00";
}

fem_types const entry_type<bool>::_type = fem_types::Bool;

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
