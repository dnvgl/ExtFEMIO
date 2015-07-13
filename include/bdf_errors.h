// Copyright © 2015 by DNV GL SE

// Purpose: Error handling for processing BDF data.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150710_BDF_ERRORS
#define _BERHOL20150710_BDF_ERRORS

#include <string>

class bdf_error {

protected:

  ::std::string msg;

  ::std::string get_msg(void) { return msg; };

public:

  bdf_error(const ::std::string &msg=::std::string("")) : msg(msg) {};

  ::std::string operator() (void) { return this->get_msg(); };

};

class bdf_types_error : public bdf_error {

public:

  bdf_types_error(const ::std::string &msg=::std::string("")) : bdf_error(msg) {};

};

class bdf_float_error : public bdf_error {

public:

  bdf_float_error(const ::std::string &msg=::std::string("")) : bdf_error(msg) {};

};

class bdf_int_error : public bdf_error {

public:

  bdf_int_error(const ::std::string &msg=::std::string("")) : bdf_error(msg) {};

};

class bdf_list_error : public bdf_error {

public:

  bdf_list_error(const ::std::string &msg=::std::string("")) : bdf_error(msg) {};

};

class bdf_string_error : public bdf_error {

public:

  bdf_string_error(const ::std::string &msg=::std::string("")) : bdf_error(msg) {};

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
