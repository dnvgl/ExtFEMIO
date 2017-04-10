/**
   \file extfem_string.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Helper functions for string manipulation.

   Detailed description
*/

// ID: $Id$

#pragma once

#include <string>

#if !defined _EXTFEM_STRING_H_
#define _EXTFEM_STRING_H_

namespace dnvgl {
    namespace extfem {
        namespace string {

            class string : public std::string {
            public:
                string();
                explicit string(const std::string& in);
                string(size_t, char);

// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
                string trim(const std::string &whitespace = " \t") const;

                string upper();

                string lower();
            };
        }
    }
}

#endif // _EXTFEM_STRING_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// coding: utf-8
// End:
