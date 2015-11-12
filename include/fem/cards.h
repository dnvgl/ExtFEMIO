// Copyright © 2015 by DNV GL SE

// Classes for the differen Sesame FEM cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20151111_CARDS
#define _BERHOL20151111_CARDS

#include <deque>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <memory>

#include "extfem_misc.h"

#include <my_c++14.h>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "fem/types.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace cards {

        typedef enum {
          UNKNOWN,
          IDENT
        } types;

        typedef ::std::pair<::dnvgl::extfem::fem::types::base*, void*> format_entry;

        class card {

        private:

          // two character strings for continuation lines in Free Form
          // Format cards.
          static const ::std::set<char> free_form_cont;

          static const ::std::map<::std::string, types> cardtype_map;

        protected:

          static ::dnvgl::extfem::fem::types::empty empty;

          static ::dnvgl::extfem::fem::types::card head;

          ::std::string format_outlist(
            const ::std::deque<::std::unique_ptr<format_entry>>&) const;

        public:

          friend
          ::std::unique_ptr<format_entry>
          format(const ::std::unique_ptr<::dnvgl::extfem::fem::types::card> &formatter);

          friend
          ::std::unique_ptr<format_entry>
          format(const ::std::unique_ptr<::dnvgl::extfem::fem::types::empty> &formatter);
          template <class T> friend
          ::std::unique_ptr<format_entry>
          format(const ::dnvgl::extfem::fem::types::entry_type<T> &formatter,
                 const ::std::unique_ptr<T> &val);

          DllExport static ::std::deque<::std::string>
          card_split(::std::deque<::std::string> const &);

          DllExport card (const ::std::deque<::std::string> &);
          DllExport card ();

          virtual const ::dnvgl::extfem::fem::cards::types card_type(void) const = 0;
          virtual const ::std::ostream& operator<<(::std::ostream&) const = 0;
        };

        inline ::std::unique_ptr<format_entry>
        format(const ::dnvgl::extfem::fem::types::card &formatter) {
          return ::std::make_unique<format_entry>(
            (::dnvgl::extfem::fem::types::card*)&formatter, (void*)NULL);
        };

        inline ::std::unique_ptr<format_entry>
        format(const ::dnvgl::extfem::fem::types::empty &formatter) {
          return ::std::make_unique<format_entry>(
            (::dnvgl::extfem::fem::types::base*)&formatter, (void*)NULL);
        };

        template <class T>
        inline ::std::unique_ptr<format_entry>
        format(const ::dnvgl::extfem::fem::types::entry_type<T> &formatter,
               const ::std::unique_ptr<T> &val) {
          return ::std::make_unique<format_entry>(
            (::dnvgl::extfem::fem::types::base*)&formatter,
            (void*)val.get());
        };

        class ident : public card {

        private:

          static const ::dnvgl::extfem::fem::types::card head;

          static const ::dnvgl::extfem::fem::types::entry_type<long> _SLEVEL;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SELTYP;
          static const ::dnvgl::extfem::fem::types::entry_type<long> _SELMOD;

        public:

          ::std::unique_ptr<long> SLEVEL;
          ::std::unique_ptr<long> SELTYP;
          ::std::unique_ptr<long> SELMOD;

          DllExport ident(const ::std::deque<::std::string>&);

          DllExport ident(
            const long *iSLEVEL, const long *iSELTYP,
            const long *iSELMOD) {
            SLEVEL = ::std::make_unique<long>(*iSLEVEL);
            SELTYP = ::std::make_unique<long>(*iSELTYP);
            SELMOD = ::std::make_unique<long>(*iSELMOD);
          };


          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const { return IDENT; };

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const ident&);
          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const;
        };

        class unknown : public card {

        public:

          DllExport unknown(const ::std::deque<::std::string> &inp) :
            card(inp), content(inp) {};

          DllExport const ::dnvgl::extfem::fem::cards::types
          card_type(void) const { return UNKNOWN; }

          ::std::deque<::std::string> content;

          DllExport const ::std::ostream&
          operator<< (::std::ostream& os) const {
            throw errors::error("can't write UNKNOWN.");
            return os;
          };

          DllExport friend ::std::ostream&
          operator<< (::std::ostream&, const unknown&);
        };
      }
    }
  }
}

#include "fem/cards_elements.h"
#include "fem/cards_properties.h"
#include "fem/cards_loads.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace cards {
        DllExport ::std::unique_ptr<card> dispatch(const ::std::deque<::std::string> &);
      }
    }
  }
}
#endif // _BERHOL20151111_CARDS

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// coding: utf-8
// End:
