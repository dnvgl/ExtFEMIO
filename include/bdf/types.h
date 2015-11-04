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

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/errors.h"
#include "extfem_string.h"
#include "bdf/type_bounds.h"


namespace bdf {

  namespace types {

    typedef enum {
      None, Int, Float, Str, List, Choose, Cross, Blank} bdf_types;

    typedef enum {LONG=16, SHORT=8, FREE=-1} out_form_type;

    class base {

    protected:

      static const bdf_types _type;
      std::string name;

    public:

      static out_form_type out_form;

      base(const std::string &name);

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

      virtual std::string format(const void*) const = 0;

    };

    class card : public base {
    public:

      card(const std::string &name) : base(name) {};

      bdf_types type(void) const {return None;};

      std::string format(const void* d) const;
    };

    class empty : public base {

    public:

      empty(void) : base("") {};

      bdf_types type(void) const {return None;};

      std::string format(const void* d) const;
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

    template <>
    class entry_type<long> : public base {

      // Integer value.

    private:

      bdf::type_bounds::bound<long> bounds;
      static const
#ifdef HAVE_BOOST_REGEX_HPP
      boost::regex
#else
      std::regex
#endif
      int_re;

    protected:

      static const bdf_types _type = Int;

    public:

      entry_type<long>(std::string);

      entry_type<long>(std::string, bdf::type_bounds::bound<long>);

      long *operator() (const std::string&) const;

      bdf_types type() const { return _type; };

      std::string format(const std::unique_ptr<long>&) const;
      std::string format(const void *v) const {
        if (!v)
          return bdf::types::empty().format(nullptr);
        else {
          long val(*((long*)v));
          std::unique_ptr<long> vp;
          vp = std::make_unique<long>(val);
          return this->format(vp);
        }
      };
    };


    template <>
    class entry_type<double> : public base {

      // Real value.

    private:

      bdf::type_bounds::bound<double> bounds;
      static const
#ifdef HAVE_BOOST_REGEX_HPP
      boost::regex
#else
      std::regex
#endif
      float_exp_re;
      static const
#ifdef HAVE_BOOST_REGEX_HPP
      boost::regex
#else
      std::regex
#endif
      float_re;
      static const
#ifdef HAVE_BOOST_REGEX_HPP
      boost::regex
#else
      std::regex
#endif
      float_lead_dot;

    protected:

      static const bdf_types _type = Float;

    public:

      entry_type<double>(std::string);

      entry_type<double>(std::string, bdf::type_bounds::bound<double>);

      double *operator() (const std::string&) const;

      bdf_types type() const {return _type;};

      std::string format(const std::unique_ptr<double>&) const;
      std::string format(const void *v) const {
        if (!v)
          return bdf::types::empty().format(nullptr);
        else {
          double val(*((double*)v));
          std::unique_ptr<double> vp;
          vp = std::make_unique<double>(val);
          return this->format(vp);
        }
      };
    };

    template <>
    class entry_type<std::string> : public base {

      // String value.

    private:

      bdf::type_bounds::bound<std::string> bounds;

    protected:

      static const bdf_types _type = Str;

    public:

      entry_type<std::string>(std::string);

      entry_type<std::string>(std::string, bdf::type_bounds::bound<std::string>);

      std::string *operator() (const std::string &) const;

      bdf_types type() const {
        return _type;
      }

      std::string format(const std::unique_ptr<std::string>&) const;
      std::string format(const void *v) const {
        if (!v)
          return bdf::types::empty().format(nullptr);
        else {
          std::string val(*((std::string*)v));
          std::unique_ptr<std::string> vp;
          vp = std::make_unique<std::string>(val);
          return this->format(vp);
        }
      };
    };

    template <>
    class entry_type<std::deque<int>> : public base {

      // List of integers.

    private:

      static const
#ifdef HAVE_BOOST_REGEX_HPP
        boost::regex
#else
        std::regex
#endif
        int_re;

    protected:

      static const bdf_types _type = List;

    public:

      entry_type<std::deque<int>>(const std::string &name) :
        base(name) {};

      std::deque<int>* operator() (const std::string&) const;

      inline bdf_types type() const {return _type;};

      std::string format(const std::unique_ptr<std::deque<int>>&) const;
      std::string format(const void *v) const {
        if (!v)
          return bdf::types::empty().format(nullptr);
        else {
          std::deque<int> val(((std::deque<int>*)v)->begin(), ((std::deque<int>*)v)->end());
          std::unique_ptr<std::deque<int>> vp;
          vp = std::make_unique<std::deque<int>>(val);
          return this->format(vp);
        }
      };
    };

    template <class T> inline
    std::unique_ptr<T>
    get_val(const bdf::types::entry_type<T> &t, const std::string &inp) {
      T *dummy = t(inp);
      if (!dummy)
        return nullptr;
      else
        return std::make_unique<T>(*dummy);
    }

    template <class T> inline
    std::unique_ptr<T>
    get_val(const T *inp) {
      if (!inp)
        return nullptr;
      else
        return std::make_unique<T>(*inp);
    }

  };
}

#endif // _BERHOL20150407_BDF_TYPES

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../.. check -j 8"
  coding:u tf-8
  End:
*/
