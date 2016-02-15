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

#ifdef _MSC_VER && _EXTFEMIO_DLL
#ifdef _EXTFEMIO_EXPORT_IMPL
#define EXTFEMIO_API __declspec( dllexport )
// #pragma message("EXTFEMIO_API: EXTFEMIO_API")
#else
#define EXTFEMIO_API __declspec( dllimport ) 
// #pragma message("EXTFEMIO_API: dllimport")
#endif
#else //  !_EXTFEMIO_DLL
#define EXTFEMIO_API
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
