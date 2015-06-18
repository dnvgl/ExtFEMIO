// Copyright © 2015 by DNV GL SE

// Helper functions for string manipulation.

// Author: Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150618_BDF_STRING
#define _BERHOL20150618_BDF_STRING

#include <string>
#include <algorithm>

namespace bdf_string {

  class string {
  public:
    static ::std::string trim(const ::std::string&,
                              const ::std::string& = " \t");
    static ::std::string upper(const ::std::string&);
    static ::std::string lower(const ::std::string&);
  };
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
