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
#include <vector>
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

                enum class fem_types {
                    /// Indicates class not suitable for end use.
                    None,
                    /// Integer value cell
                    Int,
                    /// Floating point value cell
                    Float,
                    /// Character string cell
                    Str,
                    /// cell with true/false value
                    Bool,
                    /// empty cell
                    Blank,
                    /// list of integers
                    List
                };

                namespace __base {
                    class b_type {

                    protected:

                        fem_types static const _type;
                        std::string name;
                        std::istringstream static conv;

                    public:

                        b_type(std::string const&);

                        virtual ~b_type(void) {};

                        virtual fem_types type(void) const = 0;

                    };

                    // Helper class to std::set conv locale for all
                    // classes derived from base.
                    class imbue_helper : public b_type {
                    public:

                        imbue_helper(std::locale const &loc) : b_type("") {
                            conv.imbue(loc);
                        };

                        virtual fem_types type(void) const {
                            return fem_types::None;
                        };

                        std::string format(void const*) const {
                            return "";
                        };
                    };

                }

                class card : public __base::b_type {
                public:

                    card(std::string const &name) : __base::b_type(name) {};

                    card(void) : __base::b_type("") {};

                    virtual fem_types type(void) const {return fem_types::None;};

                    std::string format(void) const;
                };

                class empty : public __base::b_type {

                public:

                    empty(void) : __base::b_type("") {};

                    virtual fem_types type(void) const {return fem_types::None;};

                    std::string format(void) const;
                };

                template <class _Ty>
                class entry_type : public __base::b_type {

                public:
                    virtual std::string format(_Ty const &d) const = 0;
                };


                template <>
                class entry_type<long> : public __base::b_type {

                    // Integer value.

                private:

                    dnvgl::extfem::fem::type_bounds::bound<long> bounds;

                protected:

                    fem_types static const _type;

#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex static const int_re;
#else
                    std::regex static const int_re;
#endif

                public:

                    entry_type(std::string const &name);

                    entry_type(
                        std::string const &name,
                        fem::type_bounds::bound<long> const &bounds);

/// Convert string to long
                    long operator() (std::string const &inp) const;

                    virtual fem_types type(void) const;

                    std::string format(long const &inp) const;
                };

                /// Boolean value.
                template <>
                class entry_type<bool> : public __base::b_type {

                private:

                    dnvgl::extfem::fem::type_bounds::bound<bool> bounds;

                protected:

#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex
#else
                    std::regex
#endif
                    static const bool_re;

                    fem_types static const _type;

                public:

                    entry_type(std::string const &name) :
                            fem::types::__base::b_type(name), bounds() {}


                    bool operator() (std::string const &inp) const {
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


                    virtual fem_types type(void) const { return _type; };

                    std::string format(bool const &inp) const {
                        if (inp) return "           +1.00";
                        else return "           +0.00";
                    }
                };

                template <>
                class entry_type<double> : public __base::b_type {

                    /// Real value.

                private:

                    dnvgl::extfem::fem::type_bounds::bound<double> bounds;

                protected:

#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex
#else
                    std::regex
#endif
                    static const float_re;

                    fem_types static const _type;

                public:

                    entry_type(std::string const &name) :
                            __base::b_type(name), bounds() {};


                    entry_type(
                        std::string const &name,
                        fem::type_bounds::bound<double> const &bounds) :
                            fem::types::__base::b_type(name), bounds(bounds) {};

                    /// Convert string to double
                    double operator() (std::string const &inp) const {
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

                    virtual fem_types type(void) const {return _type;};

                    std::string format(double const &inp) const {

                        std::ostringstream res;
                        res.imbue(std::locale::classic());

#ifdef _MSC_VER
                        // std::set output to two digit exponetial format.
                        unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

                        res.setf(std::ios_base::showpos);
                        res.setf(std::ios_base::scientific, std::ios::floatfield);
                        res.setf(std::ios_base::adjustfield, std::ios::left);

                        res.precision(9);
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
                        // Reset exponetial format to former std::settings.
                        _set_output_format(ext_exp_format);
#endif

                        return out;
                    };
                };

                template <>
                class entry_type<std::string> : public __base::b_type {

                    // String value.

                private:

                    dnvgl::extfem::fem::type_bounds::bound<std::string> bounds;

                protected:

                    fem_types static const _type;

                public:

                    entry_type(std::string const&);

                    entry_type(
                        std::string const&,
                        dnvgl::extfem::fem::type_bounds::bound<std::string> const&);

                    std::string operator() (
                        std::string const&, std::string const&,
                        std::string const&, std::string const&) const;

                    virtual fem_types type(void) const {
                        return _type;
                    }

                    std::string format(
                        std::string const&, size_t const &len=72) const;
                };

                template <>
                class entry_type<std::vector<int> > : public __base::b_type {

                    // List of integers.

                protected:

#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex
#else
                    std::regex
#endif
                    static const list_int_re;

                    fem_types static const _type;

                public:

                    entry_type(
                        std::string const &name) :
                            __base::b_type(name) {};

                    void operator() (
                        std::vector<int> &value, std::string const &inp) const {

                        double tmp_d;
                        std::list<int> tmp_l;
                        long tmp;

                        if (! regex_match(inp, list_int_re)) {
                            std::string msg("illegal input (""");
                            throw errors::int_error(
                                name, msg + inp + """), no integer list!");
                        }

                        conv.str(inp);
                        conv.seekg(0);
                        conv >> tmp_d;
                        tmp = (long)tmp_d;

                        while (tmp) {
                            ldiv_t divmod = std::div(tmp, (long)10);
                            value.push_back(divmod.rem);
                            tmp /= 10;
                        }
                        std::sort(value.begin(), value.end());

                        return;
                    };

                    virtual inline fem_types type(void) const {return _type;};

                    std::string format(
                        std::vector<int> const &inp) const {

                        std::ostringstream res, res2;
                        res.imbue(std::locale::classic());
                        res2.imbue(std::locale::classic());

                        double value = 0;
                        for (auto &p : inp) {
                            value *= 10.;
                            value += p;
                        }

#ifdef _MSC_VER
                        // std::set output to two digit exponential format.
                        unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

                        res.setf(std::ios_base::scientific, std::ios::floatfield);
                        res.setf(std::ios_base::adjustfield, std::ios::left);

                        res << " ";
                        res.precision(9);
                        res.width(15);
                        res.fill(' ');

                        res << value;
                        std::string out(res.str());
                        if (out.size() != 16) {
                            std::ostringstream msg(
                                "output string for value ",
                                std::ostringstream::ate);
                            std::copy(
                                inp.begin(), inp.end(),
                                std::ostream_iterator<int>(msg, ", "));
                            msg << " of incorrect size, got length of " << out.size()
                                << " instead of allowed length of 16. " << "!" << out << "!";
                            throw errors::output_error(name, msg.str());
                        }

#ifdef _MSC_VER
                        // Reset exponential output format to former std::settings.
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
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
