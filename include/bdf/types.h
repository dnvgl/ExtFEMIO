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

#include <cmath>
#include <string>
#include <deque>
#include <set>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <limits>
#include <memory>
#include <sstream>
#include <iomanip>

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

            class DECLSPECIFIER base {

            protected:

               static const bdf_types _type;

               static ::std::istringstream conv;

            private:

               static bool first;

            public:

               ::std::string name;

               static out_form_type out_form;

               base(const ::std::string&);

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

            class DECLSPECIFIER empty : public base {

            public:

               empty(void);

               bdf_types type(void) const { return None; };

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

               entry_value(const _Ty *value);
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

            template<class _Ty>
            entry_value<_Ty>::entry_value(const _Ty *value) {
               if (!value) {
                  is_value = false;
                  this->value = _Ty();
               } else {
                  is_value = true;
                  this->value = *value;
               }
            };

            template <> inline
            entry_value<::std::deque<int>>::entry_value(
               const entry_value<::std::deque<int>> &val) :
                               value(val.value.begin(), val.value.end()),
                               is_value(val.is_value) {};

            template <> inline
            entry_value<::std::deque<int>>::entry_value(
               const ::std::deque<int> &value, const bool &is_value) :
                         value(value.begin(), value.end()),
                         is_value(is_value) {
            };

            template <> inline
            entry_value<::std::deque<int>>::entry_value(const ::std::deque<int> *value) {
               if (!value) {
                  this->is_value = false;
               } else {
                  is_value = true;
                  copy(value->begin(), value->end(),
                       back_inserter(this->value));
               }
            };

            template <> inline
            void entry_value<::std::deque<int>>::push_back(const long &inp) {
               this->value.push_back(inp);
            };

            template <> inline
            entry_value<::std::string>::entry_value(const ::std::string *value) {
               if (!value) {
                  this->is_value = false;
                  this->value = "";
               } else {
                  this->is_value = true;
                  this->value = *value;
               }
            };

            template <class _Ty>
            class entry_type : public base { };

/// Integer value.
            DECLSPECIFIER extern const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            ::std::regex
#endif
            int_re;

            template <>
            class entry_type<long> : public base {

            private:

               ::dnvgl::extfem::bdf::type_bounds::bound<long> bounds;

            protected:

               static const bdf_types _type = Int;

            public:

               entry_type(const ::std::string &name) :
               bdf::types::base(name), bounds(0) {};

               entry_type(
                  const std::string &name,
                  const bdf::type_bounds::bound<long> &bounds) :
               bdf::types::base(name), bounds(bounds) {};

               entry_value<long> operator() (const std::string &inp) const {
                  entry_value<long> val;
                  this->set_value(val, inp);
                  return val;
               };

               bdf_types type() const { return _type; };

               void set_value(
                  ::dnvgl::extfem::bdf::types::entry_value<long> &val,
                  const ::std::string &inp) const {
                  auto sval = extfem::string::string(inp).trim();

                  if (sval.length() == 0) {
                     if (this->bounds.does_allow_empty()) {
                        val.is_value = false;
                        return;
                     };
                     if (!this->bounds.has_default())
                        throw errors::int_error(name, "empty entry without default");
                     val.is_value = true;
                     val = this->bounds.get_default();
                     return;
                  } else {
                     if (! regex_match(inp, int_re)) {
                        std::string msg("illegal input (""");
                        msg += inp;
                        msg += """), no integer";
                        throw errors::int_error(name, msg);
                     }
                     conv.str(sval);
                     conv.seekg(0);
                     conv >> val.value;
                     val.is_value = true;
                  }
                  if (!this->bounds.in_bounds(val)) {
                     std::ostringstream msg("boundary condition violated (",
                                            ::std::ostringstream::ate);
                     msg << name << ")\n(""" << inp << ", " << sval << ", " << val.value << """)";
                     throw errors::int_error(name, msg.str());
                  }
                  return;
               };

               ::std::string format(const void *v) const {
                  if (!v)
                     return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
                  else {
                     entry_value<long> val((long*)v);
                     return this->format(val);
                  }
               };

               ::std::string format(const entry_value<long> &inp) const {
                  std::ostringstream outp;

                  switch (out_form) {
                  case LONG:
                     outp << std::setiosflags(std::ios::right) << std::setfill(' ')
                          << std::setw(16) << inp.value;
                     break;
                  case SHORT:
                     outp << std::setiosflags(std::ios::right) << std::setfill(' ')
                          << std::setw(8) << inp.value;
                     break;
                  case FREE:
                     outp << inp.value;
                     break;
                  }

                  std::string out(outp.str());

                  if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
                     std::ostringstream msg("output string for value ", std::ostringstream::ate);
                     msg << inp.value << " of incorrect size, got length of " << out.size()
                         << " instead of allowed length of " << out_form << ".";
                     throw errors::int_error(name, msg.str());
                  }

                  return out;
               };

               ::std::string format(const long &val) const {
                  entry_value<long> tmp(val);
                  return format(tmp);
               };
            };

/// Real value.
            DECLSPECIFIER extern const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            ::std::regex
#endif
            float_exp_re;
            DECLSPECIFIER extern const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            ::std::regex
#endif
            float_re;
            DECLSPECIFIER extern const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            ::std::regex
#endif
            float_lead_dot;

            template <>
            class entry_type<double> : public base{

            private:

               ::dnvgl::extfem::bdf::type_bounds::bound<double> bounds;

               static const bdf_types _type = Float;

            public:

               entry_type<double>(const ::std::string &name) :
                  bdf::types::base(name), bounds(bdf::type_bounds::bound<double>()) {};

               entry_type<double>(
                  const ::std::string &name,
                  const bdf::type_bounds::bound<double> &bounds) :
                  bdf::types::base(name), bounds(bounds) {};

               bdf_types inline type() const { return _type; };

               // Convert string to float
               void set_value(
                  entry_value<double> &val, const ::std::string &inp) const {

                  auto sval = extfem::string::string(inp).trim().upper();

                  if (sval.length() == 0) {
                     if (this->bounds.does_allow_empty()) {
                        val.is_value = false;
                        return;
                     }
                     if (!this->bounds.has_default())
                        throw errors::float_error(name, "empty entry without default");
                     val.value = this->bounds.get_default();
                  }
                  else {
                     if (!regex_match(sval, float_re)) {
                        ::std::string msg("illegal input, no float");
                        throw errors::float_error(name, msg + "; !" + sval + "!");
                     }

#ifdef HAVE_BOOST_REGEX_HPP
                     ::boost::smatch m;
#else
                     ::std::smatch m;
#endif

                     if (regex_search(sval, m, float_exp_re))
                        sval = m[1].str() + "E" + m[2].str();

                     if (regex_match(sval, float_lead_dot)) {
                        auto pos = sval.find('.');
                        sval.insert(pos, 1, '0');
                     }

                     conv.str(sval);
                     conv.seekg(0);
                     conv >> val.value;
                  }
                  if (!this->bounds.in_bounds(val))
                     throw errors::float_error(name, "boundary condition violated");
                  val.is_value = true;
                  return;
               }

               entry_value<double> operator() (const ::std::string &inp) const {
                  entry_value<double> val;
                  this->set_value(val, inp);
                  return val;
               }

               ::std::string inline format(const void *v) const {
                  if (!v)
                     return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
                  else {
                     double val(*((entry_value<double>*)v));
                     return this->format(val);
                  }
               }

               ::std::string inline format(const entry_value<double> &inp) const {

                  if (!inp)
                     return bdf::types::empty().format(nullptr);

                  std::ostringstream outp;

                  outp << std::setiosflags(std::ios::scientific);

#ifdef _MSC_VER
                  // Set output to two digit exponetial format.
                  unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif
                  switch (out_form) {
                  case LONG:
                     outp << std::setiosflags(std::ios::right) << std::setfill(' ');
                     if (inp.value < 0)
                        outp << std::setprecision(10);
                     else
                        outp << std::setprecision(11);
                     outp << std::setw(17) << inp.value;
                     break;
                  case SHORT: {
                     // Check on how much precision is lost when using SHORT format.
                     // If too much precision is list raise exception which causes
                     // calling routine to switch to LONG format.
                     double order(pow(10., -floor(::std::log10(fabs(inp.value))) + 3.));
                     if (fabs(fabs(round(inp.value * order) / (inp.value * order)) - 1.) > 1e-8) {
                        ::std::ostringstream msg("output string for value ",
                           ::std::ostringstream::ate);
                        msg << inp.value
                           << " looses too much precision of being crammed into string of "
                           << out_form << " characters.";
                        throw errors::float_error(name, msg.str());
                     }
                  }
                              outp << std::setiosflags(std::ios::right) << std::setfill(' ');
                              if (inp.value < 0)
                                 outp << std::setprecision(2);
                              else
                                 outp << std::setprecision(3);
                              outp << std::setw(9) << inp.value;
                              break;
                  case FREE:
                     ::std::ostringstream res;
                     res << std::setiosflags(std::ios::scientific)
                        << inp.value;
                     outp << ::std::string(res.str());
                     break;
                  }

                  ::std::string out(outp.str());
                  out.erase(out.find('e'), 1);
                  if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
                     ::std::ostringstream msg("output string for value ", ::std::ostringstream::ate);
                     msg << inp.value << " of incorrect size, got length of " << out.size()
                        << " instead of allowed length of " << out_form << ".";
                     throw errors::float_error(name, msg.str());
                  }

#ifdef _MSC_VER
                  // Reset exponetial format to former settings.
                  _set_output_format(ext_exp_format);
#endif

                  return out;
               }

               ::std::string inline format(const double &val) const {
                  entry_value<double> tmp(val);
                  return format(tmp);
               }
            };

            /// String value.
            template <>
            class entry_type<::std::string> : public base {

            private:

               ::dnvgl::extfem::bdf::type_bounds::bound<::std::string> bounds;

            protected:

               static const bdf_types _type = Str;

            public:

               entry_type(const std::string &name) :
                  base(name), bounds(bdf::type_bounds::bound<std::string>()) {};

               entry_type(
                  const std::string &name,
                  const bdf::type_bounds::bound<std::string> &bounds) :
                  bdf::types::base(name), bounds(bounds) {};

               entry_value<std::string>
                  operator() (const std::string &inp) const {
                  auto sval = extfem::string::string(inp).trim();

                  if (sval.length() == 0)
                     sval = bounds.get_default();

                  if (!bounds.is_allowed(sval))
                     throw errors::str_error(name, "!" + sval + "! Value not in list of allowed values.");

                  return entry_value<std::string>(sval, true);
               };

               bdf_types inline type() const { return _type; }

               void set_value(
                  entry_value<std::string> &val, std::string const &inp) const {
                  val = this->operator() (inp);
               }

               void set_value(
                  entry_value<::std::string> &, const ::std::string *inp) const ;

               ::std::string format(const void *v) const {
                  if (!v)
                     return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
                  else {
                     entry_value<::std::string> val((std::string*)v);
                     return this->format(val);
                  }
               }

               std::string format(const entry_value<std::string> &inp) const {
                  if (!inp)
                     return bdf::types::empty().format(nullptr);

                  std::ostringstream outp;

                  switch (out_form) {
                  case LONG:
                     outp << std::setiosflags(std::ios_base::left) << std::setfill(' ')
                          << std::setw(16) << (::std::string)inp;
                     break;
                  case SHORT:
                     outp << std::setiosflags(std::ios_base::left) << std::setfill(' ')
                          << std::setw(8) << (::std::string)inp;
                     break;
                  case FREE:
                     outp << (::std::string)inp;
                     break;
                  }
                  std::string out(outp.str());
                  if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
                     std::ostringstream msg("output string for value ", std::ostringstream::ate);
                     msg << (::std::string)inp << " of incorrect size, got length of " << out.size()
                         << " instead of allowed length of " << out_form << ".";
                     throw errors::int_error(name, msg.str());
                  }

                  return out;
               };

               ::std::string format(const ::std::string &val) const {
                  entry_value<std::string> tmp(val);
                  return format(tmp);
               };
            };

            /// List of integers.
            DECLSPECIFIER extern const
#ifdef HAVE_BOOST_REGEX_HPP
               boost::regex
#else
               ::std::regex
#endif
               list_int_re;

            template <>
            class entry_type<::std::deque<int>> : public base {

            private:

            protected:

               static const bdf_types _type = List;

            public:

               entry_type<::std::deque<int>>(const ::std::string &name) :
                  base(name) {};

               entry_value<::std::deque<int>>
                  operator() (const ::std::string &inp) const {
                  entry_value<::std::deque<int>> val;
                  this->set_value(val, inp);
                  return val;
               };

               bdf_types type() const {return _type;};

               void set_value(
                  entry_value<::std::deque<int>> &val, const ::std::string inp) const {

                  auto sval = extfem::string::string(inp).trim();

                  if (! regex_match(sval, list_int_re)) {
                     ::std::string msg(name + ":illegal input (""");
                     throw errors::types_error(msg + sval + """), no integer in list");
                  }
                  val.is_value = true;
                  for (auto pos = sval.begin(); pos != sval.end(); ++pos)
                     val.value.push_back((int)(*pos - '0'));

                  return;
               };

               ::std::string format(const void *inp) const {
                  if (!inp)
                     return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
                  else {
                     entry_value<::std::deque<int>> val((::std::deque<int>*)inp);
                     return this->format(val);
                  }
               };

               ::std::string format(const entry_value<::std::deque<int>> &inp) const {

                  if (!inp)
                     return bdf::types::empty().format(nullptr);

                  ::std::ostringstream res1, res2;

                  for (const auto &p : inp.value) res1 << p;

                  ::std::string inp_proc(res1.str());

                  switch (out_form) {
                  case LONG:
                     res2 << std::setiosflags(std::ios::right)
                          << std::setfill(' ') << std::setw(16) << inp_proc;
                     // res2.setf(ios_base::right, std::ios_base::adjustfield);
                     // res2.fill(' ');
                     // res2 << setw(16) << inp_proc;
                     break;
                  case SHORT:
                     res2.setf(std::ios_base::right, std::ios_base::adjustfield);
                     res2.fill(' ');
                     res2 << std::setw(8) << inp_proc;
                     break;
                  case FREE:
                     res2 << inp_proc;
                     break;
                  }

                  ::std::string out(res2.str());
                  if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
                     ::std::ostringstream msg("output string for value ", ::std::ostringstream::ate);
                     msg << inp_proc << " of incorrect size, got length of " << out.size()
                         << " instead of allowed length of " << out_form << ".";
                     throw errors::output_error(name, msg.str());
                  }
                  return out;
               };
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
