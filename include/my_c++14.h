/**
   \file my_c++14.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Backporting of some C++-14 functionality.

   Detailed description
*/

// ID: $Id$

#if !defined _MY_CPP14_H_
#define _MY_CPP14_H_

#include <memory> // brings in TEMPLATE macros.

namespace std {

#if __GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))

   template<typename _Ty, typename... Args>
   std::unique_ptr<_Ty> make_unique(Args&&... args) {
      return std::unique_ptr<_Ty>(new _Ty(std::forward<Args>(args)...));
   }

#endif


#if _MSC_VER && _MSC_VER <= 1700

   double round(double number);

#define MAKE_UNIQUE(TEMPLATE_LIST, PADDING_LIST, LIST, COMMA, X1, X2, X3, X4) \
   template<class _Ty COMMA LIST(_CLASS_TYPE)>                          \
   inline std::unique_ptr<_Ty> make_unique(LIST(_TYPE_REFREF_ARG))    \
   {                                                                    \
      return std::unique_ptr<_Ty>(new _Ty(LIST(_FORWARD_ARG)));       \
   }
   _VARIADIC_EXPAND_0X(MAKE_UNIQUE, , , , )

#undef MAKE_UNIQUE

#endif
}

#endif // _MY_CPP14_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// coding: utf-8
// End:
