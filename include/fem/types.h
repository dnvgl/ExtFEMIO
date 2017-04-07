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

#include <vector>
#include <sstream>

#ifdef __GNUC__
#include "config.h"
#endif

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#if (__GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))) || \
    (_MSC_VER && _MSC_VER <= 1700)
#include "my_c++14.h"
#endif

#include "fem/type_bounds.h"

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

                        virtual ~b_type() {};

                        virtual fem_types type() const = 0;

                    };

                    // Helper class to std::set conv locale for all
                    // classes derived from base.
                    class imbue_helper : public b_type {
                    public:

                        imbue_helper(std::locale const &loc);

                        fem_types type() const override;

                        static std::string format(void const*);
                    };

                }

                class card : public __base::b_type {
                public:

                    card(std::string const &name);

                    card();

                    fem_types type() const override {return fem_types::None;};

                    std::string format() const;
                };

                class empty : public __base::b_type {

                public:

                    empty();

                    fem_types type() const override;

                    static std::string format();
                };

                template <class _Ty>
                class entry_type : public __base::b_type {

                public:
                    explicit entry_type(std::string const& cs)
                        : b_type(cs) {
                    }

                    virtual std::string format(_Ty const &d) const = 0;
                };


                template <>
                class entry_type<long> : public __base::b_type {

                    // Integer value.

                private:

                    type_bounds::bound<long> bounds;

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
                        type_bounds::bound<long> const &bounds);

/// Convert string to long
                    long operator() (std::string const &inp) const;

                    fem_types type() const override;

                    std::string format(long const &inp) const;
                };

                /// Boolean value.
                template <>
                class entry_type<bool> : public __base::b_type {

                private:

                    type_bounds::bound<bool> bounds;

                protected:

#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex static const bool_re;
#else
                    std::regex static const bool_re;
#endif

                    fem_types static const _type;

                public:

                    entry_type(std::string const &name);

                    bool operator() (std::string const &inp) const;

                    fem_types type() const override;

                    static std::string format(bool const &inp);
                };

                template <>
                class entry_type<double> : public __base::b_type {

                    /// Real value.

                private:

                    type_bounds::bound<double> bounds;

                protected:

#ifdef HAVE_BOOST_REGEX_HPP
                    boost::regex static const float_re;
#else
                    std::regex static const float_re;
#endif

                    fem_types static const _type;

                public:

                    entry_type(std::string const &name);

                    entry_type(
                        std::string const &name,
                        type_bounds::bound<double> const &bounds);

                    /// Convert string to double
                    double operator() (std::string const &inp) const;

                    fem_types type() const override;

                    std::string format(double const &inp) const;
                };

                template <>
                class entry_type<std::string> : public __base::b_type {

                    // String value.

                private:

                    type_bounds::bound<std::string> bounds;

                protected:

                    fem_types static const _type;

                public:

                    entry_type(std::string const&);

                    entry_type(
                        std::string const&,
                        type_bounds::bound<std::string> const&);

                    std::string operator() (
                        std::string const&, std::string const&,
                        std::string const&, std::string const&) const;

                    fem_types type() const override {
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
                    boost::regex static const list_int_re;
#else
                    std::regex static const list_int_re;
#endif

                    fem_types static const _type;

                public:

                    entry_type(std::string const &name);

                    void operator() (
                        std::vector<int> &value, std::string const &inp) const;

                    fem_types type() const override;

                    std::string format(
                        std::vector<int> const &inp) const;
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
