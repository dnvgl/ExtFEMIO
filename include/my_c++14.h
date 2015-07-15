// Copyright © 2015 by DNV GL SE

// Purpose: Backporting of some C++-14 functionality.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150715_MY_CPP14
#define _BERHOL20150715_MY_CPP14

namespace std {
  template<typename T, typename... Args>
  ::std::unique_ptr<T> make_unique(Args&&... args) {
    return ::std::unique_ptr<T>(new T(::std::forward<Args>(args)...));
  }
}

#endif // _BERHOL20150715_MY_CPP14

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
