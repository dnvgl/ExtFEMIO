/**
  \file
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2017 by DNV GL SE
  \brief Types for card entries.

  Detailed description
*/

/* ID: $Id$
 */

#ifndef _BDF_ENTRY_TYPE_H
#define _BDF_ENTRY_TYPE_H

#include <type_traits>

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace types {
                template <typename _Ty>
                class entry_type : public base {
                protected:
                    dnvgl::extfem::bdf::type_bounds::bound<_Ty> *bounds;
                    static const bdf_types _type;
                public:
                    explicit entry_type(const std::string& cs);
                    entry_type(const std::string &name,
                               bdf::type_bounds::bound<_Ty> *bounds);
                    bdf_types type() const;
                    entry_value<_Ty> check(entry_value<_Ty> &val);
                    entry_value<_Ty> check(_Ty val);
                    void reset();
                    void set_value(
                        entry_value<_Ty> &val, const std::string &inp);
                    void set_value(
                        entry_value<_Ty> &,
                        const std::string &, const std::string &);

                    std::string format(const entry_value<_Ty> &inp) const;
                    std::string format(const _Ty &val) const;
                    std::string format(const void *v) const;
                    entry_value<_Ty> operator() (std::string const &inp);
                    entry_value<_Ty> operator() (
                        std::string const &, std::string const &);
                };

                template <typename _Ty>
                entry_type<_Ty>::entry_type(const std::string& cs) :
                        base(cs), bounds(nullptr) { }

                template <typename _Ty>
                entry_type<_Ty>::entry_type(
                    const std::string &name,
                    bdf::type_bounds::bound<_Ty> *bounds) :
                        bdf::types::base(name) {
                    this->bounds = bounds;
                }

                template <typename _Ty>
                entry_value<_Ty> entry_type<_Ty>::check(entry_value<_Ty> &val) {
                    if (bounds && !bounds->is_allowed(val.value)) {
                        throw errors::str_error(
                            name, "!" + val.value +
                            "! Value not of allowed values.");
                    }
                    return val;
                }

                template <typename _Ty>
                entry_value<_Ty> entry_type<_Ty>::check(_Ty val) {
                    if (bounds && (!bounds->in_bounds(val))) {
                        std::ostringstream msg("!", std::ostringstream::ate);
                        msg << val << "! Value not in list of allowed range.";
                        throw errors::int_error(name, msg.str());
                    }
                    return entry_value<_Ty>(val);
                }

                template <typename _Ty>
                void entry_type<_Ty>::reset() {
                    bounds->reset();
                }

                template <typename _Ty>
                void entry_type<_Ty>::set_value(
                    entry_value<_Ty> &val, const std::string &inp) {
                    NOT_IMPLEMENTED("entry_type<_Ty>::set_value" + inp);
                }

                template <typename _Ty>
                void entry_type<_Ty>::set_value(
                    entry_value<_Ty> &,
                    const std::string &inp1, const std::string &inp2) {
                    NOT_IMPLEMENTED("entry_type<_Ty>::set_value" + inp1 + inp2);
                }

                template <typename _Ty>
                entry_value<_Ty> entry_type<_Ty>::operator() (
                    const std::string &inp) {
                    entry_value<_Ty> val;
                    this->set_value(val, inp);
                    check(val);
                    return val;
                }

                template <typename _Ty>
                entry_value<_Ty> entry_type<_Ty>::operator() (
                    const std::string &inp1, const std::string &inp2) {
                    NOT_IMPLEMENTED("entry_type<_Ty>::set_value" + inp1 + inp2);
                }


/// Integer value.
#ifdef HAVE_BOOST_REGEX_HPP
                extern const boost::regex int_re;
#else
                extern const std::regex int_re;
#endif

                template <typename _Ty> inline
                bdf_types entry_type<_Ty>::type() const {
                    return entry_type<_Ty>::_type;
                };

                template <> inline
                entry_value<long> entry_type<long>::check(
                    entry_value<long> &val) {
                    if (this->bounds != nullptr &&
                        !this->bounds->in_bounds(val.value)) {
                        std::ostringstream msg("!", std::ostringstream::ate);
                        msg << val.value
                            << "! Value not in list of allowed range.";
                        throw errors::int_error(name, msg.str());
                    }
                    return val;
                }

                template <> inline
                void entry_type<long>::set_value(
                    dnvgl::extfem::bdf::types::entry_value<long> &val,
                    const std::string &inp) {
                    auto sval = extfem::string::string(inp).trim();

                    if (sval.length() == 0) {
                        if (this->bounds->does_allow_empty()) {
                            val.is_value = false;
                            return;
                        };
                        if (!this->bounds->has_default())
                            throw errors::int_error(
                                name, "empty entry without default");
                        val.is_value = true;
                        val = this->bounds->get_default();
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
                    return;
                }

                template <> inline
                std::string entry_type<long>::format(
                    const entry_value<long> &inp) const {
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
                }

                template <> inline
                std::string entry_type<long>::format(const void *v) const {
                    if (!v)
                        return dnvgl::extfem::bdf::types::
                            empty().format(nullptr);
                    else {
                        entry_value<long> val(static_cast<long const*>(v));
                        return this->format(val);
                    }
                }

                template <> inline
                std::string entry_type<long>::format(const long &val) const {
                    entry_value<long> tmp(val);
                    return format(tmp);
                }

/// Real value.
#ifdef HAVE_BOOST_REGEX_HPP
                extern const boost::regex float_exp_re;
                extern const boost::regex float_re;
                extern const boost::regex float_lead_dot;
#else
                extern const std::regex float_exp_re;
                extern const std::regex float_re;
                extern const std::regex float_lead_dot;
#endif

                template <> inline
                entry_value<double>
                entry_type<double>::check(entry_value<double> &val) {
                    std::ostringstream msg("!", std::ostringstream::ate);
                    if (bounds && !bounds->in_bounds(val.value)) {
                        msg << val.value
                            << "! Value not in list of allowed range.";
                        throw errors::float_error(name, msg.str());
                    }
                    return val;
                }

                template <> inline
                entry_value<double>
                entry_type<double>::check(double val) {
                    std::ostringstream msg("!", std::ostringstream::ate);
                    if (bounds && !bounds->in_bounds(val)) {
                        std::ostringstream msg("!", std::ostringstream::ate);
                        msg << val
                            << "! Value not in list of allowed range.";
                        throw errors::float_error(name, msg.str());
                    }
                    return entry_value<double>(val);
                }

                // Convert string to float
                template <> inline
                void entry_type<double>::set_value(
                    entry_value<double> &val,
                    const std::string &inp) {

                    auto sval = extfem::string::string(inp).trim().upper();

                    if (sval.length() == 0) {
                        if (this->bounds->does_allow_empty()) {
                            val.is_value = false;
                            return;
                        }
                        if (!this->bounds->has_default())
                            throw errors::float_error(
                                name, "empty entry without default");
                        val.value = this->bounds->get_default();
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
                    if (this->bounds && !this->bounds->in_bounds(val.value))
                        throw errors::float_error(
                            name, "boundary condition violated");
                    val.is_value = true;
                    return;
                }

                template <> inline
                std::string entry_type<double>::format(
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

                template <> inline
                std::string entry_type<double>::format(const double &val) const {
                    entry_value<double> tmp(val);
                    return format(tmp);
                }

                template <> inline
                std::string entry_type<double>::format(const void *v) const {
                    if (!v)
                        return dnvgl::extfem::bdf::types::
                            empty().format(nullptr);
                    else {
                        double val(*(static_cast<entry_value<double> const*>(v)));
                        return this->format(val);
                    }
                }

                /// String value.
                template <> inline
                entry_value<std::string> entry_type<std::string>::check(
                    entry_value<std::string> &val) {
                    if (bounds && !bounds->is_allowed(val.value)) {
                        throw errors::str_error(
                            name, "!" + val.value +
                            "! Value not in list of allowed values.");
                    }
                    return val;
                }

                template <> inline
                entry_value<std::string>
                entry_type<std::string>::operator() (std::string const &inp) {
                    std::string sval = extfem::string::string(inp).trim();
                    if (sval.length() == 0)
                        sval = string::string(bounds->get_default());
                    return check(entry_value<std::string>(sval, true));
                }

                template <> inline
                void entry_type<std::string>::set_value(
                    entry_value<std::string> &val,
                    std::string const &inp) {
                    val = this->operator() (inp);
                    check(val);
                }

                template <> inline
                std::string entry_type<std::string>::format(
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
                }

                template <> inline
                std::string entry_type<std::string>::format(const void *v) const {
                    if (!v)
                        return dnvgl::extfem::bdf::types::
                            empty().format(nullptr);
                    else {
                        entry_value<std::string> val(static_cast<std::string const*>(v));
                        return this->format(val);
                    }
                }

                template <> inline
                std::string entry_type<std::string>::format(const std::string &val) const {
                    entry_value<std::string> tmp(val);
                    return format(tmp);
                }

                /// List of integers.
#ifdef HAVE_BOOST_REGEX_HPP
                extern const boost::regex list_int_re;
#else
                extern const std::regex list_int_re;
#endif

                template <> inline
                entry_value<std::vector<int>>
                entry_type<std::vector<int>>::check(
                    entry_value<std::vector<int>> &val) {
                    std::ostringstream msg("!", std::ostringstream::ate);
                    // if (!bounds.in_bounds(val.value)) {
                    //     std::ostringstream msg("!", std::ostringstream::ate);
                    //     msg << val.value
                    //         << "! Value not in list of allowed range.";
                    //     throw errors::list_error(name, msg.str());
                    // }
                    return val;
                }

                template <> inline
                void entry_type<std::vector<int>>::set_value(
                    entry_value<std::vector<int>> &val,
                    const std::string &inp) {
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
                }

                template <> inline
                std::string entry_type<std::vector<int>>::format(
                    const entry_value<std::vector<int>> &inp) const {
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
                }

                template <> inline
                std::string entry_type<std::vector<int>>::format(
                    const void *inp) const {
                    if (!inp)
                        return dnvgl::extfem::bdf::types::
                            empty().format(nullptr);
                    else {
                        entry_value<std::vector<int> > val(
                            static_cast<std::vector<int> const*>(inp));
                        return this->format(val);
                    }
                }

                // Convert string to float
                template <> inline
                void entry_type<std::complex<double>>::set_value(
                    entry_value<std::complex<double>> &val,
                    const std::string &inp1,
                    const std::string &inp2) {

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

                template <> inline
                void entry_type<std::complex<double>>::set_value(
                    entry_value<std::complex<double>> &val,
                    const std::string &inp)
                {
                    return entry_type<std::complex<double>>::set_value(
                        val, inp, "");
                }

                template <> inline
                entry_value<std::complex<double>>
                entry_type<std::complex<double>>::operator() (
                    const std::string &inp1, const std::string &inp2) {
                    entry_value<std::complex<double> > val;
                    this->set_value(val, inp1, inp2);
                    return val;
                }

                template <> inline
                entry_value<std::complex<double>>
                entry_type<std::complex<double>>::check(
                    entry_value<std::complex<double>> &val) {
                    std::ostringstream msg("!", std::ostringstream::ate);
                    if (bounds && !bounds->in_bounds(val.value)) {
                        std::ostringstream msg("!", std::ostringstream::ate);
                        msg << val.value
                            << "! Value not in list of allowed range.";
                        throw errors::complex_error(name, msg.str());
                    }
                    return val;
                }

                template <> inline
                std::string
                entry_type<std::complex<double>>::format(
                    const entry_value<std::complex<double>> &inp) const {
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
                    case out_form_type::SHORT: {
                        // Check on how much precision is lost when
                        // using SHORT format. If too much precision
                        // is list raise exception which causes
                        // calling routine to switch to LONG format.
                        double order_r{
                            pow(10.,
                                -floor(
                                    std::log10(
                                        fabs(inp.value.real()))) + 3.)};
                        double order_i{
                            pow(10.,
                                -floor(
                                    std::log10(
                                        fabs(inp.value.imag()))) + 3.)};
                        if ((fabs(fabs(std::round(
                                           inp.value.real() * order_r) /
                                       (inp.value.real() * order_r))
                                  - 1.) > 1e-8) ||
                            (fabs(fabs(std::round(inp.value.imag() * order_i) /
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

                template <> inline
                std::string
                entry_type<std::complex<double>>::format(const void *v) const {
                    if (!v)
                        return (bdf::types::empty().format(nullptr) +
                                bdf::types::empty().format(nullptr));
                    else {
                        entry_value<std::complex<double>> val(
                            *static_cast<std::complex<double> const*>(v));
                        return this->format(val);
                    }
                }

                template <> inline
                std::string
                entry_type<std::complex<double>>::format(
                    const std::complex<double> &val) const {
                    entry_value<std::complex<double> > tmp(val);
                    return format(tmp);
                }
            }
        }
    }
}

inline bool operator== (
    const dnvgl::extfem::bdf::types::base &one,
    const dnvgl::extfem::bdf::types::base &other) {
    return (one.type() == other.type());
}

inline bool operator< (
    const dnvgl::extfem::bdf::types::base &one,
    const dnvgl::extfem::bdf::types::base &other) {
    return (one.type() < other.type());
}

#endif // _BDF_ENTRY_TYPE_H


// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_types --use-colour no;
//    ../../cbuild/tests/test_bdf_bounds --use-colour no)"
// coding:utf-8
// End:
