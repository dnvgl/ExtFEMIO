/**
   \file fem/file.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM files.

   Detailed description
*/
// ID: $Id$

#pragma once

#if !defined _FEM_FILE_H_
#define _FEM_FILE_H_

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

               fem_file(::std::istream&);

               void get(::std::deque<::std::string>&);

               /// actual byte position (hopefully no fem > 2Gybte will be
               /// readin ...)
               ::std::streampos size(void);

               /// actual byte position (hopefully no fem > 2Gybte will be
               /// readin ...)
               ::std::streampos pos(void);
            };
         }
      }
   }
}

#endif // _FEM_FILE_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check"
// coding: utf-8
// End:
