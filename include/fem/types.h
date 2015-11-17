/* Copyright © 2015 by DNV GL SE */

/*
  Purpose: Definitions for entry types for DNV GL FEM file records.

  Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
 */

/* ID: $Id$
 */

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20151102_TYPES
#define _BERHOL20151102_TYPES

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

#include "my_c++14.h"

#include "extfem_string.h"
#include "fem/type_bounds.h"
#include "fem/errors.h"

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace types {

        typedef enum { None, Comment, Int, Float, Str, List, Blank } fem_types;

        class base {

        protected:

          static const fem_types _type;
          ::std::string name;

        public:

          base(const ::std::string &name);

          ~base() {};

          virtual fem_types type() const = 0;

        };

        class card : public base {
        public:

          card(const ::std::string &name) : base(name) {};

          fem_types type(void) const {return None;};

          ::std::string format() const;
        };

        class empty : public base {

        public:

          empty(void) : base("") {};

          fem_types type(void) const {return None;};

          ::std::string format() const;
        };

        template <class T>
        class entry_type : public base {

        public:
          virtual ::std::string format(const T &d) const = 0;
        };

        template <>
        class entry_type<long> : public base {

          // Integer value.

        private:

          ::dnvgl::extfem::fem::type_bounds::bound<long> bounds;
          static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          int_re;

        protected:

          static const fem_types _type = Int;

        public:

          entry_type<long>(::std::string);

          entry_type<long>(::std::string, ::dnvgl::extfem::fem::type_bounds::bound<long>);

          long operator() (const ::std::string&) const;

          fem_types type() const { return _type; };

          ::std::string format(const long&) const;
        };

        template <>
        class entry_type<double> : public base {

          // Real value.

        private:

          ::dnvgl::extfem::fem::type_bounds::bound<double> bounds;

          static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          float_re;

        protected:

          static const fem_types _type = Float;

        public:

          entry_type<double>(::std::string);

          entry_type<double>(::std::string, ::dnvgl::extfem::fem::type_bounds::bound<double>);

          double operator() (const ::std::string&) const;

          fem_types type() const {return _type;};

          ::std::string format(const double&) const;
        };

        template <>
        class entry_type<::std::string> : public base {

          // String value.

        private:

          ::dnvgl::extfem::fem::type_bounds::bound<::std::string> bounds;

        protected:

          static const fem_types _type = Str;

        public:

          entry_type<::std::string>(::std::string);

          entry_type<::std::string>(::std::string, ::dnvgl::extfem::fem::type_bounds::bound<::std::string>);

          ::std::string operator() (const ::std::string &) const;

          fem_types type() const {
            return _type;
          }

          ::std::string format(const ::std::string&, const size_t &len=72) const;
        };

        template <>
        class entry_type<::std::deque<int>> : public base {

          // List of integers.

        private:

        static const
#ifdef HAVE_BOOST_REGEX_HPP
          boost::regex
#else
          ::std::regex
#endif
          int_re;

        protected:

          static const fem_types _type = List;

        public:

          entry_type<::std::deque<int>>(const ::std::string &name) :
            base(name) {};

          ::std::deque<int> operator() (const ::std::string&) const;

          inline fem_types type() const {return _type;};

          ::std::string format(const ::std::deque<int>&) const;
        };
      }
    }
  }
}

#endif // _BERHOL20151102_TYPES

/*
  Local Variables:
  mode: C++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../.. check -j8"
  coding: utf-8
  End:
 */