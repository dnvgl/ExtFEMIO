/**
   \file bdf/bdf_errors.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error handling for processing BDF data.

   Detailed description
   */
#include "StdAfx.h"

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

std::string error::get_msg(void) const {
    if (name.length())
        return err_class + ":" + name + ":" + msg;
    return err_class + ":" + msg;
}

char const *error::what(void) const _EXTFEMIO_NOEXCEPT{
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

int_error::int_error(
    const std::string &name, const std::string &msg) :
    form_error(name, msg, "int_error") {}

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

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    make -C ../../cbuild test"
// End:
