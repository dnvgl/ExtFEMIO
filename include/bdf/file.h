/**
   \file bdf/file.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing BDF files.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _BDF_FILE_H_
#define _BDF_FILE_H_

#include <list>
#include <set>
// ReSharper disable CppUnusedIncludeDirective
#include <string>
#include <iostream>
// ReSharper restore CppUnusedIncludeDirective

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace input {

                class bdf_file {

                private:

                    static const std::set<char> cont_chars;
                    std::string cur_line;
                    std::istream &data;

                public:

                    std::string last_comment;

                    bool eof() const;

                    explicit bdf_file(std::istream&);

                    void get(std::list<std::string>& oContent);

                    /** actual byte position (hopefully no bdf > 2Gybte will be
                        readin....)
                        */
                    std::streampos size() const;

                    /** actual byte position (hopefully no bdf > 2Gybte will be
                        readin....)
                        */
                    std::streampos pos() const;
                };
            }
        }
    }
}

#endif // _BDF_FILE_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
