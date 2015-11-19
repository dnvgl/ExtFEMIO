// Copyright (C) 2015 by DNV GL SE

/// Definitions for Nastran Bulk data entry types.

// Author: Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20150407_BDF_TYPES
#define _BERHOL20150407_BDF_TYPES

#include <string>
#include <deque>
#include <set>
#include <iostream>
#include <typeinfo>
#include <limits>
#include <memory>
#include <sstream>

#ifdef __GNUC__
#include "config.h"
#endif

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <my_c++14.h>

#include "bdf/errors.h"
#include "extfem_string.h"
#include "bdf/type_bounds.h"

namespace dnvgl {
  namespace extfem {
    namespace bdf {
      namespace types {
        /// Indicators for different BDF card entries.
        typedef enum {
          /// Undefined entry, used for abstract base types
          None,
          /// Integer value
          Int,
          /// Floating point number
          Float,
          /// String value
          Str,
          /// List of Integers
          List,
          /// Empty cell (Placeholder)
          Blank} bdf_types;

        /// Indicator for BDF card output format
        typedef enum {
          /// Cards are written in Large Field Format
          LONG=16,
          /// Cards are written in Short Field Format
          SHORT=8,
          /// Cards are written in Free Field Format
          FREE=-1} out_form_type;

        class base {

        protected:

          static const bdf_types _type;

        public:

          ::std::string name;

          static out_form_type out_form;

          base(const ::std::string&);

          ~base() {};

          virtual bdf_types type() const = 0;

          template <class T1, class T2>
          friend inline bool operator> (const T1 &one, const T2 &other) {
            return other < one;
          };

          template <class T1, class T2>
          friend inline bool operator!= (const T1 &one, const T2 &other) {
            return !(other == one);
          };

          virtual ::std::string format(const void*) const = 0;
        };

        class card : public base {
        public:

          card(const ::std::string &name) : base(name) {};

          bdf_types type(void) const {return None;};

          ::std::string format(const void*) const;
        };

        class empty : public base {

        public:

          empty(void) : base("<empty>") {};

          bdf_types type(void) const {return None;};

          ::std::string format(const void*) const;
        };

        inline bool operator== (const base &one,
                                const base &other) {
          return (one.type() == other.type());
        }

        inline bool operator< (const base &one,
                               const base &other) {
          return (one.type() < other.type());
        }

        template <class T>
        class entry_type : public base {
        };

        /// Integer value.
        template <>
        class entry_type<long> : public base {

        private:

          ::dnvgl::extfem::bdf::type_bounds::bound<long> bounds;
          static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          int_re;

        protected:

          static const bdf_types _type = Int;

        public:

          entry_type<long>(::std::string);

          entry_type<long>(::std::string, ::dnvgl::extfem::bdf::type_bounds::bound<long>);

          long *operator() (const ::std::string&) const;

          bdf_types type() const { return _type; };

          ::std::string format(const ::std::unique_ptr<long>&) const;
          ::std::string format(const void *v) const {
            if (!v)
              return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
            else {
              long val(*((long*)v));
              ::std::unique_ptr<long> vp;
              vp = ::std::make_unique<long>(val);
              return this->format(vp);
            }
          };
        };

        /// Real value.
        template <>
        class entry_type<double> : public base {

        private:

          ::dnvgl::extfem::bdf::type_bounds::bound<double> bounds;
          static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          float_exp_re;
          static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          float_re;
          static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          float_lead_dot;

        protected:

          static const bdf_types _type = Float;

        public:

          entry_type<double>(::std::string);

          entry_type<double>(::std::string, ::dnvgl::extfem::bdf::type_bounds::bound<double>);

          double *operator() (const ::std::string&) const;

          bdf_types type() const {return _type;};

          ::std::string format(const ::std::unique_ptr<double>&) const;
          ::std::string format(const void *v) const {
            if (!v)
              return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
            else {
              double val(*((double*)v));
              ::std::unique_ptr<double> vp;
              vp = ::std::make_unique<double>(val);
              return this->format(vp);
            }
          };
        };

        /// String value.
        template <>
        class entry_type<::std::string> : public base {

        private:

          ::dnvgl::extfem::bdf::type_bounds::bound<::std::string> bounds;

    protected:

          static const bdf_types _type = Str;

        public:

          entry_type<::std::string>(::std::string);

          entry_type<::std::string>(::std::string, ::dnvgl::extfem::bdf::type_bounds::bound<::std::string>);

          ::std::string *operator() (const ::std::string &) const;

          bdf_types type() const {
            return _type;
          }

          ::std::string format(const ::std::unique_ptr<::std::string>&) const;
          ::std::string format(const void *v) const {
            if (!v)
              return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
            else {
              ::std::string val(*((::std::string*)v));
              ::std::unique_ptr<::std::string> vp;
              vp = ::std::make_unique<::std::string>(val);
              return this->format(vp);
            }
          };
        };

        /// List of integers.
        template <>
        class entry_type<::std::deque<int>> : public base {

        private:

          static const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            ::std::regex
#endif
            int_re;

        protected:

          static const bdf_types _type = List;

        public:

          entry_type<::std::deque<int>>(const ::std::string &name) :
            base(name) {};

          ::std::deque<int>* operator() (const ::std::string&) const;

          inline bdf_types type() const {return _type;};

          ::std::string format(const ::std::unique_ptr<::std::deque<int>>&) const;
          ::std::string format(const void *v) const {
            if (!v)
              return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
            else {
              ::std::deque<int> val(((::std::deque<int>*)v)->begin(), ((::std::deque<int>*)v)->end());
              ::std::unique_ptr<::std::deque<int>> vp;
              vp = ::std::make_unique<::std::deque<int>>(val);
              return this->format(vp);
            }
          };
        };

        template <class T> inline
        ::std::unique_ptr<T>
        get_val(const ::dnvgl::extfem::bdf::types::entry_type<T> &t, const ::std::string &inp) {
          T *dummy = t(inp);
          if (!dummy)
            return nullptr;
          else
            return ::std::make_unique<T>(*dummy);
        }

        template <class T> inline
        ::std::unique_ptr<T>
        get_val(const T *inp) {
          if (!inp)
            return nullptr;
          else
            return ::std::make_unique<T>(*inp);
        }
      };
    }
  }
}

#endif // _BERHOL20150407_BDF_TYPES

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding:utf-8
// End:
