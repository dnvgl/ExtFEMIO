/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error handling for processing SUPPORT data.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_support_errors[]) =
        "@(#) $Id$";
}

#include "support/errors.h"

using namespace dnvgl::extfem::support::errors;

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
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

std::string error::operator() () const {
    return this->get_msg() + "\n";
}

parse_error::parse_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "parse_error") {}

unreadable_error::unreadable_error(
    const std::string &name, const std::string &msg) :
        error(name, msg, "unreadable_error") {}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    make -C ../../cbuild test"
// End:
