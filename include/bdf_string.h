// Copyright © 2015 by DNV GL SE

// Helper functions for string manipulation.

// Author: Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150618_BDF_STRING
#define _BERHOL20150618_BDF_STRING

#include <string>
#include <algorithm>

namespace bdf {

  namespace string {

    class string : public std::string {
    public:
      string(const std::string& in) : std::string(in) {};
      string trim(const std::string& = " \t");
      string upper();
      string lower();
    };
  }
}

#endif // _BERHOL20150618_BDF_STRING

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check"
// coding: utf-8
// End:
