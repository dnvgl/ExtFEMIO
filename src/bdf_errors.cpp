// Copyright © 2015 by DNV GL SE

// Purpose: Error handling for processing BDF data.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "stdafx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_errors.h"

bdf_error::bdf_error(
  const std::string &msg, const std::string &err_class) :
  msg(msg), name(""), err_class(err_class) {}


bdf_error::bdf_error(
  const std::string &name, const std::string &msg,
  const std::string &err_class) :
  msg(msg), name(name), err_class(err_class) {};

std::string bdf_error::get_msg(void) const {
  if (name.length())
    return err_class + ":" + name + ":" + msg;
  return err_class + ":" + msg;
}

std::string bdf_error::operator() (void) const {
  return this->get_msg();
}

bdf_types_error::bdf_types_error(const std::string &msg) :
  bdf_error("", msg, "bdf_types_error") {}

bdf_float_error::bdf_float_error(
  const std::string &name, const std::string &msg) :
  bdf_error(name, msg, "bdf_float_error") {}

bdf_int_error::bdf_int_error(
  const std::string &name, const std::string&msg) :
  bdf_error(name, msg, "bdf_int_error") {}

bdf_list_error::bdf_list_error(
  const std::string &name, const std::string &msg) :
  bdf_error(name, msg, "bdf_list_error") {}

bdf_str_error::bdf_str_error(
  const std::string &name, const std::string &msg) :
  bdf_error(name, msg, "bdf_str_error") {};

bdf_string_error::bdf_string_error(
  const std::string &name, const std::string &msg) :
  bdf_error(name, msg, "bdf_string_error") {};

bdf_parse_error::bdf_parse_error(
  const std::string &name, const std::string &msg) :
  bdf_error(name, msg, "bdf_parse_error") {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
