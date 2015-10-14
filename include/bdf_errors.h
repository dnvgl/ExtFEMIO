// Copyright © 2015 by DNV GL SE

// Purpose: Error handling for processing BDF data.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150710_BDF_ERRORS
#define _BERHOL20150710_BDF_ERRORS

#ifdef _MSC_VER
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

#include <string>

class bdf_error {

protected:

  std::string msg;
  std::string name;
  std::string err_class;

  std::string get_msg(void) const;

public:

  DllExport bdf_error(
    const std::string &msg,
    const std::string &err_class="bdf_error");

  DllExport bdf_error(
    const std::string&, const std::string &msg,
    const std::string &err_class="bdf_error");

  DllExport std::string operator() (void) const;

};

class bdf_types_error : public bdf_error {

public:

  bdf_types_error(const std::string &msg);

};

class bdf_float_error : public bdf_error {

public:

  bdf_float_error(const std::string&, const std::string&);

};

class bdf_int_error : public bdf_error {

public:

  bdf_int_error(const std::string&, const std::string&);

};

class bdf_list_error : public bdf_error {

public:

  bdf_list_error(const std::string&, const std::string &);

};

class bdf_str_error : public bdf_error {

public:

  bdf_str_error(const std::string&, const std::string &);

};

class bdf_string_error : public bdf_error {

public:

  bdf_string_error(const std::string&, const std::string &);

};

class bdf_parse_error : public bdf_error {

public:

  bdf_parse_error(const std::string&, const std::string &);

};

#endif // _BERHOL20150710_BDF_ERRORS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
