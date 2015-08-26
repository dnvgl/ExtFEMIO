/* Copyright (C) 2015 by DNV GL SE */

/*
   Definitions for Nastran Bulk data entry types.

   Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

*/
/* ID: $Id$
 */

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

#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif
#ifdef __GNUC__
using namespace boost;
#else
using namespace std;
#endif

#include <my_c++14.h>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_errors.h"
#include "bdf_string.h"
#include "bdf_type_bounds.h"


namespace bdf {

  namespace types {

    typedef enum {
      None, Int, Float, Str, List, Choose, Cross, Blank} bdf_types;

    class base {

    protected:

      static const bdf_types _type;
      ::std::string name;

    public:

      base(::std::string);

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
    class entry_type : public base {};

    template <>
    class entry_type<long> : public base {

      // Integer value.

    private:

      ::bdf::type_bounds::bound<long> bounds;
      static const regex int_re;

    protected:

      static const bdf_types _type = Int;

    public:

      entry_type<long>(::std::string);

      entry_type<long>(::std::string, ::bdf::type_bounds::bound<long>);

      long *operator() (const std::string&) const;

      bdf_types type() const { return _type; };
    };


    template <>
    class entry_type<double> : public base {

      // Real value.

    private:

      ::bdf::type_bounds::bound<double> bounds;
      static const regex float_exp_re;
      static const regex float_re;
      static const regex float_lead_dot;

    protected:

      static const bdf_types _type = Float;

    public:

      entry_type<double>(::std::string);

      entry_type<double>(::std::string, ::bdf::type_bounds::bound<double>);

      double *operator() (const ::std::string&) const;

      bdf_types type() const {return _type;};
    };

    template <>
    class entry_type<::std::string> : public base {

      // String value.

    private:

      ::bdf::type_bounds::bound<::std::string> bounds;

    protected:

      static const bdf_types _type = Str;

    public:

      entry_type<::std::string>(::std::string);

      entry_type<::std::string>(::std::string, ::bdf::type_bounds::bound<::std::string>);

      ::std::string *operator() (const ::std::string &) const;

      bdf_types type() const {return _type;};

    };

    template <>
    class entry_type<::std::deque<int>> : public base {

      // List of integers.

    private:

      static const regex int_re;

    protected:

      static const bdf_types _type = List;

    public:

      entry_type<::std::deque<int>>(::std::string name) :
        base(name) {};

      ::std::deque<int>* operator() (const ::std::string&) const;

      inline bdf_types type() const {return _type;};

    };
  };
}

template <class T> inline
::std::unique_ptr<T>
get_val(const ::bdf::types::entry_type<T> &t, const ::std::string &inp) {
  T *dummy = t(inp);
  if (!dummy)
    return nullptr;
  else
    return ::std::make_unique<T>(*dummy);
}

#endif // _BERHOL20150407_BDF_TYPES

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  coding:u tf-8
  End:
*/
