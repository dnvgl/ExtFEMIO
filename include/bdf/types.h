/**
    \file bdf/types.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _BDF_TYPES_H_
#define _BDF_TYPES_H_

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

               static ::std::istringstream conv;
               static ::std::ostringstream outp;

            private:

               static bool first;

            public:

               ::std::string name;

               static out_form_type out_form;

               DllExport base(const ::std::string&);

               ~base() {};

               virtual bdf_types type(void) const = 0;

               template <class _Ty1, class _Ty2>
               friend inline bool operator> (const _Ty1 &one, const _Ty2 &other) {
                  return other < one;
               };

               template <class _Ty1, class _Ty2>
               friend inline bool operator!= (const _Ty1 &one, const _Ty2 &other) {
                  return !(other == one);
               };

               virtual ::std::string format(const void*) const = 0;
            };

            // Helper class to set outp and conv locale for all
            // classes derived from base.
            class imbue_helper : public base {
            public:

               imbue_helper(const ::std::locale &loc) : base("") {
                  outp.imbue(loc);
                  conv.imbue(loc);
               };

               bdf_types type(void) const {return None;};

               ::std::string format(const void*) const { return "";};
            };

            class card : public base {
            public:

               card(const ::std::string &name) : base(name) {};

               bdf_types type(void) const {return None;};

               ::std::string format(const void*) const;
               ::std::string format() const;
            };

            class empty : public base {

            public:

               empty(void) : base("<empty>") {};

               bdf_types type(void) const {return None;};

               ::std::string format(const void*) const;
               ::std::string format() const;
            };

            inline bool operator== (const base &one,
                                    const base &other) {
               return (one.type() == other.type());
            }

            inline bool operator< (const base &one,
                                   const base &other) {
               return (one.type() < other.type());
            }

            template <class _Ty>
            class entry_value {
            public:

               _Ty value;
               bool is_value;

               entry_value(const _Ty &value, const bool &is_value=true) :
                  value(value), is_value(is_value) {};

               entry_value(const _Ty *value) {
                  if (!value) {
                     is_value = false;
                     this->value = _Ty();
                  } else {
                     is_value = true;
                     this->value = *value;
                  }
               };

               entry_value() : value(_Ty()), is_value(false) {};

               entry_value(const entry_value<_Ty> &val) :
                  value(val.value), is_value(val.is_value) {};


               inline bool operator== (const _Ty &other) const {
                  return is_value && value == other;
               }

               inline bool operator< (const _Ty &other) const {
                  return is_value && value < other;
               }

               inline bool operator|| (const entry_value<_Ty> &other) const {
                  return is_value || other.is_value;
               }

               inline operator bool() const {
                  return is_value;
               }

               inline operator _Ty() const {
                  return value;
               }

               void push_back(const long&);
            };

            template <class _Ty>
            class entry_type : public base { };

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

               entry_type<long>(const ::std::string&);

               entry_type<long>(
                  const ::std::string&,
                  const ::dnvgl::extfem::bdf::type_bounds::bound<long>&);

               entry_value<long> operator() (const ::std::string&) const;

               bdf_types type() const { return _type; };

               void set_value(entry_value<long>&, const ::std::string&) const;

               ::std::string format(const void*) const;
               ::std::string format(const entry_value<long> &v) const;
               ::std::string format(const long&) const;
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

               static const bdf_types _type = Float;

            public:

               entry_type<double>(const ::std::string&);

               entry_type<double>(
                  const ::std::string&,
                  const ::dnvgl::extfem::bdf::type_bounds::bound<double>&);

               entry_value<double> operator() (const ::std::string&) const;

               bdf_types type() const {return _type;};

               void set_value(entry_value<double> &, const ::std::string &i) const;

               ::std::string format(const void *) const;
               ::std::string format(const entry_value<double>&) const;
               ::std::string format(const double&) const;
            };

            /// String value.
            template <>
            class entry_type<::std::string> : public base {

            private:

               ::dnvgl::extfem::bdf::type_bounds::bound<::std::string> bounds;

            protected:

               static const bdf_types _type = Str;

            public:

               entry_type<::std::string>(const ::std::string&);

               entry_type<::std::string>(
                  const ::std::string&,
                  const ::dnvgl::extfem::bdf::type_bounds::bound<::std::string>&);

               entry_value<::std::string>
                  operator() (const ::std::string &) const;

               bdf_types type() const { return _type; }

               void set_value(
                  entry_value<::std::string> &, const ::std::string &i) const;
               void set_value(
                  entry_value<::std::string> &, const ::std::string *inp) const ;

               ::std::string format(const void *) const;
               ::std::string format(const entry_value<::std::string>&) const;
               ::std::string format(const ::std::string&) const;
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

               entry_value<::std::deque<int>>
                  operator() (const ::std::string&) const;

               inline bdf_types type() const {return _type;};

               void set_value(
                  entry_value<::std::deque<int>>&, const ::std::string) const;

               ::std::string format(const void *v) const;
               ::std::string format(const entry_value<::std::deque<int>>&) const;
            };
         }
      }
   }
}

#endif // _BDF_TYPES_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding:utf-8
// End:
