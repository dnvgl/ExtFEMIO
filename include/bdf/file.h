// Copyright © 2015 by DNV GL SE

// Purpose: Processing BDF files.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20150703_BDF_FILE
#define _BERHOL20150703_BDF_FILE

#include <deque>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>

#ifdef _MSC_VER
#define DllExport   __declspec( dllexport ) 
#else
#define DllExport
#endif

namespace bdf {

  namespace input {
      struct line_reader : std::ctype<char> {
          line_reader() : ctype(make_table()) { }
      private:
          static mask* make_table() {
              const mask* classic = classic_table();
              static std::vector<mask> v(classic, classic + table_size);
              v[' '] &= ~space;
              return &v[0];
          }
      };
      
      class bdf_file {

      private:
          
          static const std::set<char> cont_chars;
          std::string cur_line;
          std::istream &data;
          
      public:

          bool eof;
          
          DllExport bdf_file(std::istream&);

          DllExport std::deque<std::string>& get();
          // actual byte position (hopefully no bdf > 2Gybte will be readin....) 
          DllExport long pos();      
      };
  }

}

#endif // _BERHOL20150703_BDF_FILE

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
