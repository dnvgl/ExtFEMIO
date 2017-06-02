/**
   \file
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
#include <vector>
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

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace types {
                template <typename _Ty> class entry_value;
            }
        }
    }
}

#include "bdf/type_bounds.h"

/// Forward declaration of less than comparison.
template <typename _Ty1, typename _Ty2>
bool operator> (const _Ty1 &one, const _Ty2 &other);

/// Forward declaration of not equal comparison.
template <typename _Ty1, typename _Ty2>
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

                //! Base class for all card entries.
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
                    virtual ~base() = default;
                    virtual bdf_types type() const = 0;
                    template <typename _Ty1, typename _Ty2>
                    friend bool ::operator> (
                        const _Ty1 &one, const _Ty2 &other) {
                        return other < one;
                    }
                    template <typename _Ty1, typename _Ty2>
                    friend bool ::operator!= (
                        const _Ty1 &one, const _Ty2 &other) {
                        return !(other == one);
                    }
                    virtual std::string format(const void*) const = 0;
                };

                /*! Helper class to std::set outp and conv locale for
                    all classes derived from base.
                */
                class imbue_helper : public base {
                public:
                    explicit imbue_helper(const std::locale &loc);
                    bdf_types type() const override;
                    std::string format(const void*) const override;
                };

                //! Card title
                class card : public base {
                public:
                    explicit card(const std::string &name);
                    bdf_types type() const override;
                    std::string format(const void*) const override;
                };

                //! Empty entry.
                class empty : public base {
                public:
                    empty();
                    bdf_types type() const override;
                    std::string format(const void*) const override;
                };
            }
        }
    }
}

#include "entry_value.h"
#include "entry_type.h"

#endif // _BDF_TYPES_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_types --use-colour no;
//    ../../cbuild/tests/test_bdf_bounds --use-colour no)"
// coding:utf-8
// End:
