/**
   \file bdf/file.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing BDF files.

   Detailed description
*/

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BDF_FILE_H_
#define _BDF_FILE_H_

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
      namespace bdf {
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

            class bdf_file {

            private:

               static const ::std::set<char> cont_chars;
               ::std::string cur_line;
               ::std::istream &data;

            public:

               ::std::string last_comment;

               bool eof;

               DllExport bdf_file(::std::istream&);

               DllExport void get(std::deque<std::string>& oContent);

               /** actual byte position (hopefully no bdf > 2Gybte will be
                   readin....)
               */
               DllExport ::std::streampos size(void);

               /** actual byte position (hopefully no bdf > 2Gybte will be
                   readin....)
               */
               DllExport ::std::streampos pos(void);
            };
         }
      }
   }
}

#endif // _BDF_FILE_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
