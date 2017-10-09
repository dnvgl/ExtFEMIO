/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing of string entries from Sesam FEM files.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_types_str[]) =
        "@(#) $Id$";
}

#include <sstream>

#include "fem/types.h"
#include "fem/errors.h"
#include "extfem_string.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem::type_bounds;
using namespace dnvgl::extfem::fem::types;

fem_types const entry_type<string>::_type = fem_types::Str;

entry_type<string>::entry_type(const std::string &name) :
        b_type(name), bounds() {}

entry_type<string>::entry_type(
    const std::string &name,
    const bound<std::string> &bounds) :
        b_type(name), bounds(bounds) {}

string
entry_type<string>::operator() (
    const std::string &inp1, const std::string &inp2,
    const std::string &inp3, const std::string &inp4) const {

    string::string static sval;

    sval.assign(72, ' ');

    sval.insert(0, inp1).insert(16, inp2).insert(32, inp3).insert(48, inp4);

    std::string res(sval);

    if (res.length() == 0)
        res.assign(bounds.get_default());
    return res;
}

string entry_type<string>::format(
    const std::string &inp, const size_t &len) const {

    ostringstream res;

    res.setf(ios_base::left, ios_base::adjustfield);
    res.fill(' ');
    res.width(len);

    res << inp;
    std::string out(res.str());
    if (out.size() > len) {
        ostringstream msg("output string for value ", ostringstream::ate);
        msg << inp << " of incorrect size, got length of " << out.size()
            << " instead of allowed length of " << len << ".";
        throw errors::int_error(name, msg.str());
    }
    out.resize(len-8, ' ');
    return out;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
