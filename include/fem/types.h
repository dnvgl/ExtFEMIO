/**
   \file fem/types.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for entry types for DNV GL FEM file records.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _FEM_TYPES_H_
#define _FEM_TYPES_H_

#include <string>
#include <deque>
#include <set>
#include <list>
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

            typedef enum {
               /// Indicates class not suitable for end use.
               None,
               // /// comment cell
               // Comment,
               /// Integer value cell
               Int,
               /// Floating point value cell
               Float,
               /// Character string cell
               Str,
               /// empty cell
               Blank,
               /// list of integers
               List
            } fem_types;

            class base {

            protected:

               static const fem_types _type;
               ::std::string name;
               static ::std::istringstream conv;

            public:

               base(const ::std::string&);

               ~base() {};

               virtual fem_types type() const = 0;

            };

            class card : public base {
            public:

               card(const ::std::string &name) : base(name) {};

               card(void) : base("") {};

               fem_types type(void) const {return None;};

               ::std::string format() const;
            };

            class empty : public base {

            public:

               empty(void) : base("") {};

               fem_types type(void) const {return None;};

               ::std::string format() const;
            };

            template <class _Ty>
            class entry_type : public base {

            public:
               virtual ::std::string format(const _Ty &d) const = 0;
            };


            extern const
#ifdef HAVE_BOOST_REGEX_HPP
               boost::regex
#else
               ::std::regex
#endif
               int_re;

            template <>
            class entry_type<long> : public base {

               // Integer value.

            private:

               ::dnvgl::extfem::fem::type_bounds::bound<long> bounds;

            protected:

               static const fem_types _type = Int;

            public:

               entry_type(const ::std::string &name) :
                  fem::types::base(name), bounds() {};


               entry_type(
                  const std::string &name,
                  const fem::type_bounds::bound<long> &bounds) :
                  fem::types::base(name), bounds(bounds) {};

/// Convert string to long
               long operator() (const std::string &inp) const {
                  double value;

                  if (inp.length() == 0) {
                     if (!this->bounds.has_default())
                        throw errors::int_error(name, "empty entry without default");
                     return this->bounds.get_default();
                  } else {
                     if (! regex_match(inp, int_re)) {
                        std::string msg("illegal input (""");
                        throw errors::int_error(name, msg + inp + """), no integer!");
                     }

                     conv.str(inp);
                     conv.seekg(0);
                     conv >> value;
                  }
                  if (!this->bounds.in_bounds(long(value))) {
                     std::string msg("boundary condition violated (");
                     throw errors::int_error(
                        name, msg + name + ")\n(""" + inp + """)");
                  }
                  return long(value);
               };

               fem_types type() const { return _type; };

               ::std::string format(const long &inp) const {

                  std::ostringstream res;

#ifdef _MSC_VER
                  // Set output to two digit exponetial format.
                  unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

                  res.setf(std::ios_base::showpos);
                  res.setf(std::ios_base::scientific, std::ios_base::floatfield);
                  res.setf(std::ios_base::adjustfield, std::ios::left);

                  res.precision(8);
                  res.width(16);
                  res.fill(' ');

                  res << double(inp);
                  std::string out(res.str());
                  if (out.size() != 16) {
                     std::ostringstream msg("output string for value ", std::ostringstream::ate);
                     msg << double(inp) << " of incorrect size, got length of " << out.size()
                         << " instead of allowed length of 16." << out;
                     throw errors::int_error(name, msg.str());
                  }

#ifdef _MSC_VER
                  // Reset exponetial format to former settings.
                  _set_output_format(ext_exp_format);
#endif

                  return out;
               };
            };

            /// Boolean value.
            extern const
#ifdef HAVE_BOOST_REGEX_HPP
               boost::regex
#else
               ::std::regex
#endif
               bool_re;

            template <>
            class entry_type<bool> : public base {

            private:

               ::dnvgl::extfem::fem::type_bounds::bound<bool> bounds;

            protected:

               static const fem_types _type = Int;

            public:

               entry_type(const ::std::string &name) :
                  fem::types::base(name), bounds() {}


               bool operator() (const ::std::string &inp) const {
                  double value;

                  if (inp.length() == 0) {
                     if (!this->bounds.has_default())
                        throw errors::bool_error(name, "empty entry without default");
                     return this->bounds.get_default();
                  }
                  else {
                     if (!regex_match(inp, bool_re)) {
                        std::string msg("illegal input (""");
                        throw errors::bool_error(name, msg + inp + """), no bool!");
                     }

                     conv.str(inp);
                     conv.seekg(0);
                     conv >> value;
                  }
                  if (value == 1.) return true;
                  else if (value == 0.) return false;
                  else {
                     std::string msg("boundary condition violated (");
                     throw errors::bool_error(
                        name, msg + name + ")\n(""" + inp + """)");
                  }
               }


               fem_types type() const { return _type; };

               ::std::string format(const bool &inp) const {
                  if (inp) return " 1.00000000e+00 ";
                  else return " 0.00000000e+00 ";
               }
            };

            extern const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            ::std::regex
#endif
            float_re;

            template <>
            class entry_type<double> : public base {

            /// Real value.

            private:

               ::dnvgl::extfem::fem::type_bounds::bound<double> bounds;

            protected:

               static const fem_types _type = Float;

            public:

               entry_type(const ::std::string &name) :
                  base(name), bounds() {};


               entry_type(
                  const std::string &name,
                  const fem::type_bounds::bound<double> &bounds) :
                  fem::types::base(name), bounds(bounds) {};

               /// Convert string to double
               double operator() (const ::std::string &inp) const {
                  double value;

                  if (inp.length() == 0) {
                     if (!this->bounds.has_default())
                        throw errors::float_error(name, "empty entry without default");
                     value = this->bounds.get_default();
                  }
                  else {
                     if (!regex_match(inp, float_re)) {
                        std::string msg("illegal input, (""");
                        throw errors::float_error(name, msg + inp + """), no float!");
                     }

                     conv.str(inp);
                     conv.seekg(0);
                     conv >> value;
                  }
                  if (!this->bounds.in_bounds(value)) {
                     std::string msg("boundary condition violated (");
                     throw errors::float_error(
                        name, msg + name + ")\n(""" + inp + """)");
                  }
                  return value;
               };

               fem_types type() const {return _type;};

               ::std::string format(const double &inp) const {

                  std::ostringstream res;

#ifdef _MSC_VER
                  // Set output to two digit exponetial format.
                  unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

                  res.setf(std::ios_base::showpos);
                  res.setf(std::ios_base::scientific, std::ios::floatfield);
                  res.setf(std::ios_base::adjustfield, std::ios::left);

                  res.precision(8);
                  res.width(16);
                  res.fill(' ');

                  res << inp;
                  std::string out(res.str());
                  if (out.size() != 16) {
                     std::ostringstream msg("output string for value ", std::ostringstream::ate);
                     msg << inp << " of incorrect size, got length of " << out.size()
                         << " instead of allowed length of 16.";
                     throw errors::output_error(name, msg.str());
                  }

#ifdef _MSC_VER
                  // Reset exponetial format to former settings.
                  _set_output_format(ext_exp_format);
#endif

                  return out;
               };
            };

            template <>
            class entry_type<::std::string> : public base {

               // String value.

            private:

               ::dnvgl::extfem::fem::type_bounds::bound<::std::string> bounds;

            protected:

               static const fem_types _type = Str;

            public:

               entry_type(const ::std::string&);

               entry_type(
                  const ::std::string&,
                  const ::dnvgl::extfem::fem::type_bounds::bound<::std::string>&);

               ::std::string operator() (const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&) const;

               fem_types type() const {
                  return _type;
               }

               ::std::string format(
                  const ::std::string&, const size_t &len=72) const;
            };

            extern const
#ifdef HAVE_BOOST_REGEX_HPP
               boost::regex
#else
               ::std::regex
#endif
               list_int_re;


               template <>
            class entry_type<::std::deque<int>> : public base {

               // List of integers.

            protected:

               static const fem_types _type = List;

            public:

               entry_type(
                  const ::std::string &name) :
                  base(name) {};

               ::std::deque<int>* operator() (const std::string &inp) const {
                  auto *value =  new std::deque<int>();

                  double tmp_d;
                  ::std::list<int> tmp_l;
                  long tmp;

                  if (! regex_match(inp, int_re)) {
                     std::string msg("illegal input (""");
                     throw errors::int_error(name, msg + inp + """), no integer!");
                  }

                  conv.str(inp);
                  conv.seekg(0);
                  conv >> tmp_d;
                  tmp = (long)tmp_d;

                  while (tmp) {
                     ldiv_t divmod = std::div(tmp, (long)10);
                     value->push_back(divmod.rem);
                     tmp /= 10;
                  }
                  ::std::sort(value->begin(), value->end());

                  return value;
               };

               inline fem_types type() const {return _type;};

               ::std::string format(
                  const std::deque<int> &inp) const {

                  std::ostringstream res, res2;

                  double value = 0;
                  for (auto &p : inp) {
                     value *= 10.;
                     value += p;
                  }

#ifdef _MSC_VER
                  // Set output to two digit exponetial format.
                  unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

                  res << " ";
                  res.setf(std::ios_base::scientific, std::ios::floatfield);
                  res.setf(std::ios_base::adjustfield, std::ios::left);

                  res.precision(8);
                  res.width(15);
                  res.fill(' ');

                  res << value;
                  std::string out(res.str());
                  if (out.size() != 16) {
                     ::std::ostringstream msg("output string for value ",
                                              ::std::ostringstream::ate);
                     ::std::copy(inp.begin(), inp.end(),
                                 std::ostream_iterator<int>(msg, ", "));
                     msg << " of incorrect size, got length of " << out.size()
                         << " instead of allowed length of 16.";
                     throw errors::output_error(name, msg.str());
                  }

#ifdef _MSC_VER
                  // Reset exponetial format to former settings.
                  _set_output_format(ext_exp_format);
#endif

                  return out;
               };
            };
         }
      }
   }
}

#endif // _FEM_TYPES_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
