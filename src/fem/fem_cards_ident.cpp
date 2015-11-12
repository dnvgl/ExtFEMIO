// Copyright © 2015 by DNV GL SE

// Purpose: Processing Sesam FEM IDENT cards.

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

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace cards {

        const fem::types::card ident::head("IDENT");

        const entry_type<long> ident::_SLEVEL("SLEVEL");
        const entry_type<long> ident::_SELTYP("SELTYP");
        const entry_type<long> ident::_SELMOD("SELMOD");

        ident::ident(const ::std::deque<::std::string> &inp) :
          card(inp) {

          auto pos = inp.begin();

          ++pos;
          SLEVEL = fem::types::get_val<long>(_SLEVEL, *(pos++));
          SELTYP = fem::types::get_val<long>(_SELTYP, *(pos++));
          SELMOD = fem::types::get_val<long>(_SELMOD, *(pos++));
        }

        const ::std::ostream& ident::operator<<(::std::ostream& os) const {
          os << this;
          return os;
        }

        ::std::ostream& operator<<(::std::ostream &os, const ident &card) {

          ::std::deque<::std::unique_ptr<format_entry>> entries;

          entries.push_back(format(ident::head));

          entries.push_back(format<long>(card._SLEVEL, card.SLEVEL));
          entries.push_back(format<long>(card._SELTYP, card.SELTYP));
          entries.push_back(format<long>(card._SELMOD, card.SELMOD));
          entries.push_back(format(ident::empty));

          os << card.format_outlist(entries) << ::std::endl;

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
// compile-command: "make test"
// End:
