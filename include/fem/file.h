// Copyright © 2015 by DNV GL SE

// Purpose: Processing Sesam FEM files.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20151111_FILE
#define _BERHOL20151111_FILE

#include <deque>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>

#include "extfem_misc.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace input {

        struct line_reader : ::std::ctype<char> {

          line_reader() : ctype(make_table()) { }

        private:

          static mask* make_table() {
            const mask* classic = classic_table();
            static ::std::vector<mask> v(classic, classic + table_size);
            v[' '] &= ~space;
            return &v[0];
          }
        };

        class fem_file {

        private:

          static const ::std::set<char> cont_chars;
          ::std::string cur_line;
          ::std::istream &data;

        public:

          ::std::string last_comment;

          bool eof;

          DllExport fem_file(::std::istream&);

          DllExport ::std::deque<::std::string>& get();

          /// actual byte position (hopefully no fem > 2Gybte will be
          /// readin ...)
          DllExport ::std::streampos size(void);

          /// actual byte position (hopefully no fem > 2Gybte will be
          /// readin ...)
          DllExport ::std::streampos pos(void);
        };
      }
    }
  }
}


#endif // _BERHOL20151111_FILE

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check"
// coding: utf-8
// End:
