/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error Handling for processing FEM data.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_errors[]) =
        "@(#) $Id$";
}

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

using namespace std;

using namespace dnvgl::extfem::fem::errors;

error::error(
    const std::string &msg, const std::string &err_class) :
        msg(msg), name(""), err_class(err_class) {}

error::error(
    const std::string &name, const std::string &msg,
    const std::string &err_class) :
        msg(msg), name(name), err_class(err_class) {};

string error::get_msg() const {
    if (name.length())
        return err_class + ":" + name + ":" + msg;
    return err_class + ":" + msg;
}

const char *error::what() const _EXTFEMIO_NOEXCEPT {
    return (this->get_msg() + "\n").c_str();
}

types_error::types_error(const std::string &msg) :
        error("", msg, "types_error") {}

float_error::float_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "float_error") {}

int_error::int_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "int_error") {}

bool_error::bool_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "bool_error") {}

output_error::output_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "output_error") {}

list_error::list_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "list_error") {}

str_error::str_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "str_error") {};

string_error::string_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "string_error") {};

parse_error::parse_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "parse_error") {}

usage_error::usage_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "usage_error") {}

no_used::no_used(long const &no) :
        error("no_used", "") {
    ostringstream res;
    res << "Element number " << no << " already used." << endl;
    msg.assign(res.str());
}

id_used::id_used(long const &id) :
        error("id_used", "") {
    ostringstream res;
    res << "Element id " << id << " already used." << endl;
    msg.assign(res.str());
}

data_not_matching_id::data_not_matching_id(
    long const &id_ex, long const &id_new) :
        error("data_not_matching_id") {
    ostringstream res;
    res << "Element id already set to " << id_ex
        << " with attempt to set to " << id_new << "."<< endl;
    msg.assign(res.str());
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
