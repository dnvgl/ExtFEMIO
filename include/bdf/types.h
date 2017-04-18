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
#include <complex>
#include <iomanip>
#include <list>
#include <sstream>
#include <string>

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

#include "extfem_string.h"
#include "bdf/type_bounds.h"

template <class _Ty1, class _Ty2>
bool operator> (const _Ty1 &one, const _Ty2 &other);

template <class _Ty1, class _Ty2>
bool operator!= (const _Ty1 &one, const _Ty2 &other);

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace types {
                /// Indicators for different BDF card entries.
                enum class bdf_types{
                    /// Undefined entry, used for abstract base types
                    None,
                    /// Integer value
                    Int,
                    /// Floating point number
                    Float,
                    /// String value
                    Str,
                    /// Complex value
                    Complex,
                    /// List of Integers
                    List,
                    /// Empty cell (Placeholder)
                    Blank};

                /// Indicator for BDF card output format
                enum class out_form_type{
                    /// Cards are written in Large Field Format
                    LONG=16,
                    /// Cards are written in Short Field Format
                    SHORT=8,
                    /// Cards are written in Free Field Format
                    FREE=-1};

                class base {

                protected:

                    static const bdf_types _type;

                    static std::istringstream conv;

                private:

                    static bool first;

                public:

                    std::string name;

                    static out_form_type out_form;

                    explicit base(const std::string&);

                    virtual ~base();

                    virtual bdf_types type() const = 0;

                    template <class _Ty1, class _Ty2>
                    friend inline bool ::operator> (
                        const _Ty1 &one, const _Ty2 &other) {
                        return other < one;
                    }

                    template <class _Ty1, class _Ty2>
                    friend inline bool ::operator!= (
                        const _Ty1 &one, const _Ty2 &other) {
                        return !(other == one);
                    }

                    virtual std::string format(const void*) const = 0;
                };

                // Helper class to std::set outp and conv locale for all
                // classes derived from base.
                class imbue_helper : public base {
                public:

                    explicit imbue_helper(const std::locale &loc);

                    bdf_types type() const override;

                    std::string format(const void*) const override;
                };

                class card : public base {
                public:

                    explicit card(const std::string &name);

                    bdf_types type() const override;

                    std::string format(const void*) const override;
                };

                class empty : public base {

                public:

                    empty();

                    bdf_types type() const override;

                    std::string format(const void*) const override;
                };

                inline bool operator== (
                    const base &one, const base &other) {
                    return (one.type() == other.type());
                }

                inline bool operator< (
                    const base &one, const base &other) {
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

                    void inline operator() (const _Ty *val) {
                        is_value = (val != nullptr);

                        if (is_value)
                            value = *val;
                        return;
                    }

                    void inline operator() (const _Ty &val) {
                        is_value = true;
                        value = val;
                        return;
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
                }

                template <> inline
                // ReSharper disable CppPossiblyUninitializedMember
                entry_value<std::list<int> >::entry_value(const entry_value<std::list<int> > &val) : value(val.value), is_value(val.is_value) {}

                template <> inline
                entry_value<std::list<int> >::entry_value(const std::list<int> &value, const bool &is_value) : value(value), is_value(is_value) {}

                template <> inline
                    entry_value<std::list<int> >::entry_value(const std::list<int> *value) : is_value(value != nullptr) {
                    if (value)
                        copy(value->begin(), value->end(),
                        back_inserter(this->value));

                }

                template <> inline
                    entry_value<std::string>::entry_value(const std::string *value) : is_value(value != nullptr) {
                    if (is_value)
                        this->value = *value;
                    else
                        this->value = "";
                }
                // ReSharper restore CppPossiblyUninitializedMember

                template <> inline
                void entry_value<std::list<int> >::push_back(const long &inp) {
                    this->value.push_back(inp);
                }

                template <class _Ty>
                class entry_type : public base {
                protected:

                    dnvgl::extfem::bdf::type_bounds::bound<_Ty> bounds;

                public:
                    explicit entry_type(const std::string& cs)
                        : base(cs) { }

                    entry_value<_Ty> inline &check(
                        entry_value<_Ty> &val) const {
                        if (!bounds.is_allowed(val.value))
                            throw errors::str_error(
                                name, "!" + val.value +
                                "! Value not of allowed values.");
                        return val;
                    }
                };

/// Integer value.
                extern const
#ifdef HAVE_BOOST_REGEX_HPP
                boost::regex
#else
                std::regex
#endif
                int_re;

                template <>
                class entry_type<long> : public base {

                private:

                    dnvgl::extfem::bdf::type_bounds::bound<long> bounds;

                protected:

                    static const bdf_types _type = bdf_types::Int;

                public:

                    explicit entry_type(const std::string &name) :
                            bdf::types::base(name), bounds(nullptr) {};

                    entry_type(
                        const std::string &name,
                        const bdf::type_bounds::bound<long> &bounds) :
                            bdf::types::base(name), bounds(bounds) {};

                    entry_value<long> operator() (
                        const std::string &inp) const {
                        entry_value<long> val;
                        this->set_value(val, inp);
                        return val;
                    };

                    bdf_types type() const override { return _type; };

                    entry_value<long> inline check(
                        entry_value<long> val) const {
                        if (!bounds.in_bounds(val.value)) {
                            std::ostringstream msg("!", std::ostringstream::ate);
                            msg << val.value
                                << "! Value not in list of allowed range.";
                            throw errors::int_error(name, msg.str());
                        }
                        return val;
                    }

                    void set_value(
                        dnvgl::extfem::bdf::types::entry_value<long> &val,
                        const std::string &inp) const {
                        auto sval = extfem::string::string(inp).trim();

                        if (sval.length() == 0) {
                            if (this->bounds.does_allow_empty()) {
                                val.is_value = false;
                                return;
                            };
                            if (!this->bounds.has_default())
                                throw errors::int_error(
                                    name, "empty entry without default");
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
                        check(val);
                        return;
                    }

                    std::string format(const void *v) const override {
                        if (!v)
                            return dnvgl::extfem::bdf::types::
                                empty().format(nullptr);
                        else {
                            entry_value<long> val(static_cast<long const*>(v));
                            return this->format(val);
                        }
                    }

                    std::string format(const entry_value<long> &inp) const {
                        std::ostringstream outp;
                        outp.imbue(std::locale::classic());

                        switch (out_form) {
                        case out_form_type::LONG:
                            outp << std::setiosflags(std::ios::right)
                                 << std::setfill(' ')
                                 << std::setw(16) << inp.value;
                            break;
                        case out_form_type::SHORT:
                            outp << std::setiosflags(std::ios::right)
                                 << std::setfill(' ')
                                 << std::setw(8) << inp.value;
                            break;
                        case out_form_type::FREE:
                            outp << inp.value;
                            break;
                        }

                        std::string out(outp.str());

                        if (out.size() != static_cast<size_t>(out_form) &&
                            out_form != out_form_type::FREE) {
                            std::ostringstream msg(
                                "output string for value ",
                                std::ostringstream::ate);
                            msg << inp.value
                                << " of incorrect size, got length of "
                                << out.size()
                                << " instead of allowed length of "
                                << static_cast<long>(out_form) << ".";
                            throw errors::int_error(name, msg.str());
                        }

                        return out;
                    };

                    std::string format(const long &val) const {
                        entry_value<long> tmp(val);
                        return format(tmp);
                    };
                };

/// Real value.
                extern const
#ifdef HAVE_BOOST_REGEX_HPP
                boost::regex
#else
                std::regex
#endif
                float_exp_re;
                extern const
#ifdef HAVE_BOOST_REGEX_HPP
                boost::regex
#else
                std::regex
#endif
                float_re;
                extern const
#ifdef HAVE_BOOST_REGEX_HPP
                boost::regex
#else
                std::regex
#endif
                float_lead_dot;

                template <>
                class entry_type<double> : public base{

                private:

                    dnvgl::extfem::bdf::type_bounds::bound<double> bounds;

                    static const bdf_types _type = bdf_types::Float;

                public:

                    entry_type<double>(const std::string &name) :
                            bdf::types::base(name),
                            bounds(bdf::type_bounds::bound<double>()) {};

                    entry_type<double>(
                        const std::string &name,
                        const bdf::type_bounds::bound<double> &bounds) :
                            bdf::types::base(name), bounds(bounds) {};

                    bdf_types inline type() const override { return _type; };

                    entry_value<double> inline check(
                        entry_value<double> val) const {
                        if (!bounds.in_bounds(val.value)) {
                            std::ostringstream msg("!", std::ostringstream::ate);
                            msg << val.value
                                << "! Value not in list of allowed range.";
                            throw errors::float_error(name, msg.str());
                        }
                        return val;
                    }

                    // Convert string to float
                    void set_value(
                        entry_value<double> &val,
                        const std::string &inp) const {

                        auto sval = extfem::string::string(inp).trim().upper();

                        if (sval.length() == 0) {
                            if (this->bounds.does_allow_empty()) {
                                val.is_value = false;
                                return;
                            }
                            if (!this->bounds.has_default())
                                throw errors::float_error(
                                    name, "empty entry without default");
                            val.value = this->bounds.get_default();
                        }
                        else {
                            if (!regex_match(sval, float_re)) {
                                std::string msg("illegal input, no float");
                                throw errors::float_error(
                                    name, msg + "; !" + sval + "!");
                            }

#ifdef HAVE_BOOST_REGEX_HPP
                            ::boost::smatch m;
#else
                            std::smatch m;
#endif

                            if (regex_search(sval, m, float_exp_re))
                                sval = string::string(m[1].str() + "E" + m[2].str());

                            if (regex_match(sval, float_lead_dot)) {
                                auto pos = sval.find('.');
                                sval.insert(pos, 1, '0');
                            }
                            // val.value = std::atol(sval.c_str());
                            conv.str(sval);
                            conv.seekg(0);
                            conv >> val.value;
                        }
                        if (!this->bounds.in_bounds(val))
                            throw errors::float_error(
                                name, "boundary condition violated");
                        val.is_value = true;
                        return;
                    }

                    entry_value<double> operator() (
                        const std::string &inp) const {
                        entry_value<double> val;
                        this->set_value(val, inp);
                        return val;
                    }

                    std::string inline format(const void *v) const override {
                        if (!v)
                            return dnvgl::extfem::bdf::types::
                                empty().format(nullptr);
                        else {
                            double val(*(static_cast<entry_value<double> const*>(v)));
                            return this->format(val);
                        }
                    }

                    std::string inline format(
                        const entry_value<double> &inp) const {

                        if (!inp)
                            return bdf::types::empty().format(nullptr);

                        std::ostringstream outp;
                        outp.imbue(std::locale::classic());

                        outp << std::setiosflags(std::ios::scientific);

#ifdef _MSC_VER
                        // std::set output to two digit exponetial format.
                        unsigned int ext_exp_format = _set_output_format(
                            _TWO_DIGIT_EXPONENT);
#endif
                        switch (out_form) {
                        case out_form_type::LONG:
                            outp << std::setiosflags(std::ios::right)
                                 << std::setfill(' ');
                            if (inp.value <= 0)
                                outp << std::setprecision(10);
                            else
                                outp << std::setprecision(11);
                            outp << std::setw(17) << inp.value;
                            break;
                        case out_form_type::SHORT: {
                            // Check on how much precision is lost
                            // when using SHORT format. If too much
                            // precision is list raise exception which
                            // causes calling routine to switch to
                            // LONG format.
                            double order(
                                pow(10.,
                                    -floor(std::log10(fabs(inp.value))) + 3.));
                            if (fabs(fabs(std::round(inp.value * order) /
                                          (inp.value * order)) - 1.) > 1e-8) {
                                std::ostringstream msg(
                                    "output string for value ",
                                    std::ostringstream::ate);
                                msg << inp.value
                                    << " looses too much precision of being "
                                    << "crammed into string of "
                                    << static_cast<long>(out_form)
                                    << " characters.";
                                throw errors::float_error(name, msg.str());
                            }
                        }
                            outp << std::setiosflags(std::ios::right)
                                 << std::setfill(' ');
                            if (inp.value <= 0)
                                outp << std::setprecision(2);
                            else
                                outp << std::setprecision(3);
                            outp << std::setw(9) << inp.value;
                            break;
                        case out_form_type::FREE:
                            std::ostringstream res;
                            res << std::setiosflags(std::ios::scientific)
                                << inp.value;
                            outp << std::string(res.str());
                            break;
                        }

                        std::string out(outp.str());
                        out.erase(out.find('e'), 1);
                        if (out.size() != static_cast<size_t>(out_form) &&
                            out_form != out_form_type::FREE) {
                            std::ostringstream msg(
                                "output string for value ",
                                std::ostringstream::ate);
                            msg << inp.value
                                << " of incorrect size, got length of "
                                << out.size()
                                << " instead of allowed length of "
                                << static_cast<long>(out_form) << ".";
                            throw errors::float_error(name, msg.str());
                        }

#ifdef _MSC_VER
                        // Reset exponetial format to former std::settings.
                        _set_output_format(ext_exp_format);
#endif

                        return out;
                    }

                    std::string inline format(const double &val) const {
                        entry_value<double> tmp(val);
                        return format(tmp);
                    }
                };

                /// String value.
                template <>
                class entry_type<std::string> : public base {

                protected:

                    dnvgl::extfem::bdf::type_bounds::bound<std::string> bounds;
                    static const bdf_types _type = bdf_types::Str;

                public:

                    entry_type(const std::string &name) :
                            base(name),
                            bounds(bdf::type_bounds::bound<std::string>()) {}

                    entry_type(
                        const std::string &name,
                        const bdf::type_bounds::bound<std::string> &bounds) :
                            bdf::types::base(name), bounds(bounds) {}

                    entry_value<std::string> inline check(
                        entry_value<std::string> val) const {
                        if (!bounds.is_allowed(val.value))
                            throw errors::str_error(
                                name, "!" + val.value +
                                "! Value not in list of allowed values.");
                        return val;
                    }

                    entry_value<std::string>
                    operator() (const std::string &inp) const {
                        auto sval = extfem::string::string(inp).trim();

                        if (sval.length() == 0)
                            sval = string::string(bounds.get_default());

                        return check(entry_value<std::string>(sval, true));
                    };

                    bdf_types inline type() const override { return _type; }

                    void set_value(
                        entry_value<std::string> &val,
                        std::string const &inp) const {
                        val = this->operator() (inp);
                    }

                    std::string format(const void *v) const override {
                        if (!v)
                            return dnvgl::extfem::bdf::types::
                                empty().format(nullptr);
                        else {
                            entry_value<std::string> val(static_cast<std::string const*>(v));
                            return this->format(val);
                        }
                    }

                    std::string format(
                        const entry_value<std::string> &inp) const {
                        if (!inp)
                            return bdf::types::empty().format(nullptr);

                        std::ostringstream outp;
                        outp.imbue(std::locale::classic());

                        switch (out_form) {
                        case out_form_type::LONG:
                            outp << std::setiosflags(std::ios_base::left)
                                 << std::setfill(' ')
                                 << std::setw(16) << static_cast<std::string>(inp);
                            break;
                        case out_form_type::SHORT:
                            outp << std::setiosflags(std::ios_base::left)
                                 << std::setfill(' ')
                                 << std::setw(8) << static_cast<std::string>(inp);
                            break;
                        case out_form_type::FREE:
                            outp << static_cast<std::string>(inp);
                            break;
                        }
                        std::string out(outp.str());
                        if (out.size() != static_cast<size_t>(out_form) &&
                            out_form != out_form_type::FREE) {
                            std::ostringstream msg(
                                "output string for value ",
                                std::ostringstream::ate);
                            msg << static_cast<std::string>(inp)
                                << " of incorrect size, got length of "
                                << out.size()
                                << " instead of allowed length of "
                                << static_cast<long>(out_form) << ".";
                            throw errors::int_error(name, msg.str());
                        }

                        return out;
                    };

                    std::string format(const std::string &val) const {
                        entry_value<std::string> tmp(val);
                        return format(tmp);
                    };
                };

                /// List of integers.
                extern const
#ifdef HAVE_BOOST_REGEX_HPP
                boost::regex
#else
                std::regex
#endif
                list_int_re;

                template <>
                class entry_type<std::list<int> > : public base {

                private:

                protected:

                    static const bdf_types _type = bdf_types::List;

                public:

                    entry_type<std::list<int> >(const std::string &name) :
                            base(name) {};

                    entry_value<std::list<int> >
                    operator() (const std::string &inp) const {
                        entry_value<std::list<int> > val;
                        this->set_value(val, inp);
                        return val;
                    };

                    bdf_types type() const override {return _type;};

                    entry_value<std::list<int>> inline check(
                        entry_value<std::list<int>> val) const {
                        // if (!bounds.in_bounds(val.value)) {
                        //     std::ostringstream msg("!", std::ostringstream::ate);
                        //     msg << val.value
                        //         << "! Value not in list of allowed range.";
                        //     throw errors::list_error(name, msg.str());
                        // }
                        return val;
                    }

                    void set_value(
                        entry_value<std::list<int> > &val,
                        const std::string inp) const {

                        auto sval = extfem::string::string(inp).trim();

                        if (! regex_match(sval, list_int_re)) {
                            std::string msg(name + ":illegal input (""");
                            throw errors::types_error(
                                msg + sval + """), no integer in list");
                        }
                        val.is_value = true;
                        for (auto pos = sval.begin(); pos != sval.end(); ++pos)
                            val.value.push_back(int(*pos - '0'));

                        return;
                    };

                    std::string format(const void *inp) const override {
                        if (!inp)
                            return dnvgl::extfem::bdf::types::
                                empty().format(nullptr);
                        else {
                            entry_value<std::list<int> > val(
                                static_cast<std::list<int> const*>(inp));
                            return this->format(val);
                        }
                    };

                    std::string format(
                        const entry_value<std::list<int> > &inp) const {

                        if (!inp)
                            return bdf::types::empty().format(nullptr);

                        std::ostringstream res1, res2;

                        for (const auto &p : inp.value) res1 << p;

                        std::string inp_proc(res1.str());

                        switch (out_form) {
                        case out_form_type::LONG:
                            res2 << std::setiosflags(std::ios::right)
                                 << std::setfill(' ') << std::setw(16)
                                 << inp_proc;
                            break;
                        case out_form_type::SHORT:
                            res2.setf(std::ios_base::right,
                                      std::ios_base::adjustfield);
                            res2.fill(' ');
                            res2 << std::setw(8) << inp_proc;
                            break;
                        case out_form_type::FREE:
                            res2 << inp_proc;
                            break;
                        }

                        std::string out(res2.str());
                        if (out.size() != static_cast<size_t>(out_form) &&
                            out_form != out_form_type::FREE) {
                            std::ostringstream msg(
                                "output string for value ",
                                std::ostringstream::ate);
                            msg << inp_proc
                                << " of incorrect size, got length of "
                                << out.size()
                                << " instead of allowed length of "
                                << static_cast<long>(out_form) << ".";
                            throw errors::output_error(name, msg.str());
                        }
                        return out;
                    };
                };

                template <>
                class entry_type<std::complex<double> > : public base {

                private:

                    dnvgl::extfem::bdf::type_bounds::bound<
                    std::complex<double>> bounds;

                    static const bdf_types _type = bdf_types::Complex;

                public:

                    entry_type<std::complex<double> >(const std::string &name) :
                            bdf::types::base(name),
                            bounds(bdf::type_bounds::bound<
                                   std::complex<double>>()) {};

                    entry_type<std::complex<double> >(
                        const std::string &name,
                        const bdf::type_bounds::bound<
                        std::complex<double>> &bounds) :
                            bdf::types::base(name), bounds(bounds) {};

                    bdf_types inline type() const override { return _type; };

                    // Convert string to float
                    void set_value(
                        entry_value<std::complex<double> > &val,
                        const std::string &inp1,
                        const std::string &inp2="") const {

                        auto sval1 = extfem::string::string(
                            inp1).trim().upper();
                        auto sval2 = extfem::string::string(
                            inp2).trim().upper();

                        double c_real, c_imag;

                        val.is_value = false;

                        if (sval1.length() == 0) {
                            throw errors::float_error(
                                name, "empty entry without default");
                        } else {
                            if (!regex_match(sval1, float_re)) {
                                std::string msg("illegal input, no float");
                                throw errors::float_error(
                                    name, msg + "; !" + sval1 + "!");
                            }
                            if (sval2.length() > 0 &&
                                !regex_match(sval2, float_re)) {
                                std::string msg("illegal input, no float");
                                throw errors::float_error(
                                    name, msg + "; !" + sval2 + "!");
                            }

#ifdef HAVE_BOOST_REGEX_HPP
                            ::boost::smatch m;
#else
                            std::smatch m;
#endif

                            if (regex_search(sval1, m, float_exp_re))
                                sval1 = string::string(m[1].str() + "E" + m[2].str());
                            if (regex_match(sval1, float_lead_dot)) {
                                auto pos = sval1.find('.');
                                sval1.insert(pos, 1, '0');
                            }
                            conv.str(sval1);
                            conv.seekg(0);
                            conv >> c_real;

                            if (sval2.length() > 0) {
                                if (regex_search(sval2, m, float_exp_re))
                                    sval2 = string::string(m[1].str() + "E" + m[2].str());
                                if (regex_match(sval2, float_lead_dot)) {
                                    auto pos = sval2.find('.');
                                    sval2.insert(pos, 1, '0');
                                }
                                conv.str(sval2);
                                conv.seekg(0);
                                conv >> c_imag;
                            } else
                                c_imag = 0.;
                            val = std::complex<double>(c_real, c_imag);
                        }
                        val.is_value = true;
                        return;
                    }

                    entry_value<std::complex<double> > operator() (
                        const std::string &inp1,
                        const std::string &inp2="") const {
                        entry_value<std::complex<double> > val;
                        this->set_value(val, inp1, inp2);
                        return val;
                    }

                    std::string inline format(const void *v) const override {
                        if (!v)
                            return (bdf::types::empty().format(nullptr) +
                                    bdf::types::empty().format(nullptr));
                        else {
                            entry_value<std::complex<double>> val(
                                *static_cast<std::complex<double> const*>(v));
                            return this->format(val);
                        }
                    }

                    std::string inline format(
                        const entry_value<std::complex<double> > &inp) const {

                        if (!inp)
                            return (bdf::types::empty().format(nullptr) +
                                    bdf::types::empty().format(nullptr));

                        std::ostringstream outp;
                        outp.imbue(std::locale::classic());

                        outp << std::setiosflags(std::ios::scientific);

#ifdef _MSC_VER
                        // std::set output to two digit exponetial format.
                        unsigned int ext_exp_format = _set_output_format(
                            _TWO_DIGIT_EXPONENT);
#endif
                        switch (out_form) {
                        case out_form_type::LONG:
                            outp << std::setiosflags(std::ios::right)
                                 << std::setfill(' ');
                            if (inp.value.real() < 0)
                                outp << std::setprecision(10);
                            else
                                outp << std::setprecision(11);
                            outp << std::setw(17) << inp.value.real();
                            if (inp.value.imag() < 0)
                                outp << std::setprecision(10);
                            else
                                outp << std::setprecision(11);
                            outp << std::setw(17) << inp.value.imag();
                            break;
                        case out_form_type::SHORT:
                            {
                                // Check on how much precision is lost
                                // when using SHORT format. If too
                                // much precision is list raise
                                // exception which causes calling
                                // routine to switch to LONG format.
                                double order_r(
                                    pow(10.,
                                        -floor(
                                            std::log10(
                                                fabs(inp.value.real()))) + 3.));
                                double order_i(
                                    pow(10.,
                                        -floor(
                                            std::log10(
                                                fabs(inp.value.imag()))) + 3.));
                                if ((fabs(fabs(
                                              std::round(inp.value.real() *
                                                         order_r) /
                                              (inp.value.real() * order_r))
                                          - 1.) > 1e-8) ||
                                    (fabs(fabs(std::round(inp.value.imag() *
                                                          order_i) /
                                               (inp.value.imag() * order_i))
                                          - 1.) > 1e-8)) {
                                    std::ostringstream msg(
                                        "output string for value ",
                                        std::ostringstream::ate);
                                    msg << inp.value
                                        << " looses too much precision of "
                                        << "being crammed into string of "
                                        << static_cast<long>(out_form)
                                        << " characters.";
                                    throw errors::float_error(name, msg.str());
                                }
                                outp << std::setiosflags(std::ios::right)
                                     << std::setfill(' ');
                                if (inp.value.real() < 0)
                                    outp << std::setprecision(2);
                                else
                                    outp << std::setprecision(3);
                                outp << std::setw(9) << inp.value.real();
                                if (inp.value.imag() < 0)
                                    outp << std::setprecision(2);
                                else
                                    outp << std::setprecision(3);
                                outp << std::setw(9) << inp.value.imag();
                                break;
                            }
                        case out_form_type::FREE:
                            std::ostringstream res;
                            res.imbue(std::locale::classic());
                            res << std::setiosflags(std::ios::scientific)
                                << inp.value.real() << "," << inp.value.imag();
                            outp << std::string(res.str());
                            break;
                        }

                        std::string out(outp.str());
                        out.erase(out.find('e'), 1);
                        out.erase(out.find('e'), 1);
                        if (out.size() != static_cast<size_t>(out_form)*2 &&
                            out_form != out_form_type::FREE) {
                            std::ostringstream msg(
                                "output string for value ",
                                std::ostringstream::ate);
                            msg << "!" << inp.value << "! -> !" << out
                                << "! of incorrect size, got length of "
                                << out.size()
                                << " instead of allowed length of "
                                << static_cast<long>(out_form) << ".";
                            throw errors::float_error(name, msg.str());
                        }

#ifdef _MSC_VER
                        // Reset exponetial format to former std::settings.
                        _set_output_format(ext_exp_format);
#endif

                        return out;
                    }

                    std::string inline format(
                        const std::complex<double> &val) const {
                        entry_value<std::complex<double> > tmp(val);
                        return format(tmp);
                    }
                };
            }
        }
    }
}

#endif // _BDF_TYPES_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// coding:utf-8
// End:
