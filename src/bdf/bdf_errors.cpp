/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error handling for processing BDF data.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_errors[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/errors.h"

using namespace dnvgl::extfem::bdf::errors;

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

error::error(
    const std::string &name, const std::string &msg,
    const std::string &err_class) :
        msg(msg), name(name), err_class(err_class) {};

std::string error::get_msg() const {
    if (name.length())
        return err_class + ":" + name + ":" + msg;
    return err_class + ":" + msg;
}

char const *error::what() const _EXTFEMIO_NOEXCEPT{
    return (this->get_msg() + "\n").c_str();
}

types_error::types_error(const std::string &msg) :
        error("", msg, "types_error") {}

form_error::form_error(
    const std::string &name, const std::string &msg,
    const std::string &cls) :
        error(name, msg, cls) {}


float_error::float_error(
    const std::string &name, const std::string &msg) :
        form_error(name, msg, "float_error") {}

complex_error::complex_error(
    const std::string &name, const std::string &msg) :
        form_error(name, msg, "complex_error") {};

int_error::int_error(
    const std::string &name, const std::string &msg) :
        form_error(name, msg, "int_error") {}

list_error::list_error(
    const std::string &name, const std::string &msg) :
        form_error(name, msg, "list_error") {}

str_error::str_error(
    const std::string &name, const std::string &msg) :
        form_error(name, msg, "str_error") {};

output_error::output_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "output_error") {}

parse_error::parse_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "parse_error") {}

usage_error::usage_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "usage_error") {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
