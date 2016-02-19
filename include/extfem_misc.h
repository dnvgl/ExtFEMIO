/**
   \file extfem_misc.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Misc. definitions for the extfem library.

   Detailed description
*/

// ID: $Id$

#if !defined _EXTFEM_MISC_H_
#define _EXTFEM_MISC_H_

#if (defined(_MSC_VER) && defined(_EXTFEMIO_DLL))
#ifdef _EXTFEMIO_EXPORT_IMPL
#  define DECLSPECIFIER __declspec( dllexport )
#  define EXPIMP_TEMPLATE
//#pragma message("DECLSPECIFIER: dllexport")
#else
#  define DECLSPECIFIER __declspec( dllimport ) 
#  define EXPIMP_TEMPLATE extern
//#pragma message("DECLSPECIFIER: dllimport")
#endif
#else //  !_EXTFEMIO_DLL
#define DECLSPECIFIER
#endif


namespace dnvgl {
   namespace extfem {
   }
}

#endif // _EXTFEM_MISC_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
