// Copyright © 2015 by DNV GL SE

// Purpose: Processing BDF files.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150703_BDF_FILE
#define _BERHOL20150703_BDF_FILE

#include <deque>
#include <set>
#include <string>
#include <iostream>

namespace bdf {

  namespace input {

    class bdf_file {

    private:

      static const ::std::set<char> cont_chars;
      ::std::string cur_line;
      ::std::istream &data;

    public:

      bdf_file(::std::istream&);

      // ::std::deque<::std::string> operator << ()

      ::std::deque<::std::string>& get();

    };
  }

}

#endif // _BERHOL20150703_BDF_FILE

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 7"
// coding: utf-8
// End:
