// Copyright © 2015 by DNV GL SE

// Purpose: Processing Sesam FEM GNODE cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}


#include <memory>

#include "fem/cards.h"
#include "fem/types.h"

#ifdef _TYPE
#undef _TYPE
#endif

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace cards {

        gnode::gnode(const ::std::deque<::std::string> &inp) :
          card(inp) {
        }

        const ::dnvgl::extfem::fem::cards::types
        gnode::card_type(void) const {return GNODE;}

        ::std::ostream&
        operator<< (::std::ostream &os, const gnode &inp) {
          return os;
        }

        const ::std::ostream&
        gnode::operator<< (::std::ostream& os) const {
          return os;
        }
      }
    }
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. doxyfile.stamp check -j 8"
// End:
