// Copyright © 2015 by DNV GL SE

// Purpose: Backporting of some C++-14 functionality.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if !defined _BERHOL20150715_MY_CPP14
#define _BERHOL20150715_MY_CPP14

#include <memory> // brings in TEMPLATE macros.

namespace std {

#ifdef _MSC_VER

#define MAKE_UNIQUE(TEMPLATE_LIST, PADDING_LIST, LIST, COMMA, X1, X2, X3, X4)   \
    template<class T COMMA LIST(_CLASS_TYPE)>  \
    inline std::unique_ptr<T> make_unique(LIST(_TYPE_REFREF_ARG))  \
    {  \
    return std::unique_ptr<T>(new T(LIST(_FORWARD_ARG)));  \
}
    _VARIADIC_EXPAND_0X(MAKE_UNIQUE, , , , )
#undef MAKE_UNIQUE

#else

  template<typename T, typename... Args>
  ::std::unique_ptr<T> make_unique(Args&&... args) {
    return ::std::unique_ptr<T>(new T(::std::forward<Args>(args)...));
  }

#endif
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
