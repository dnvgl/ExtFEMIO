/*!
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Misc. definitions for the extfem library.

   Detailed description
*/

// ID: $Id$

#pragma once

#if !defined _EXTFEM_MISC_H_
#define _EXTFEM_MISC_H_

// ReSharper disable CppUnusedIncludeDirective
#include <cstring>
#include <string>
// ReSharper restore CppUnusedIncludeDirective
#include <exception>
#include "extfem_misc.h"

#if defined(_MSC_VER) & _MSC_VER < 1900
#define _EXTFEMIO_NOEXCEPT
#else
#define _EXTFEMIO_NOEXCEPT noexcept
#endif

#ifdef _EXTFEMIO_UNUSED
#elif defined(__GNUC__)
#define _EXTFEMIO_UNUSED(x) x __attribute__((__unused__))
#elif defined(_MSC_VER)
#define _EXTFEMIO_UNUSED(x) __pragma(warning(suppress: 4100 4101)) x
#elif defined(__LCLINT__)
#define _EXTFEMIO_UNUSED(x) /*@unused@*/ x
#elif defined(__cplusplus)
#define _EXTFEMIO_UNUSED(x)
#else
#define _EXTFEMIO_UNUSED(x) x
#endif

/// Shortcut to throw not_implemented with appropriate information.
#define NOT_IMPLEMENTED(msg) \
    throw std::not_implemented(__FILE__, __LINE__, msg)

/*! @mainpage Process various FEM file formats from C++
 * @brief The library currently support subsets of Sesam FEM and Nastran BDF files.
 *
 * Library to access various FE program export/import file formats.
 * Depending on the software writing and/or reading of the elements is
 * supported. Currently supported file formats are:
 *
 * * \b BDF : NASTRAN \c BDF files.
 *
 * * \b FEM : DNV GL \b Sestra text \c FEM files.
 *
 * The library provides a class for each supported data sets in BDF
 * and FEM. For each field in the dataset an attribute is provided.
 * Regarding the naming conventions, the classes and attributes are
 * named as described in the respective documentation. Class names are
 * in minuskels, attribute names in majuskels.
 *
 * Some constraints are enforced, i.e. the reuse of element, or
 * property ids is prohibited, but the next free id is used instead.
 */

/*! @defgroup exceptions Various exceptions
 * @brief Various exceptions to signal error states.
 *
 * These custom exceptions are used to express various error states in
 * processing diffrent files.
 */

/*! @defgroup extfem Functionality to access various finite element file formats.
 * @brief Process the input/output records for various import/export files for finite element programs
 */

/*! @defgroup extfem_base Base functionality for FEM file representing classes.
 * @ingroup extfem
 */

namespace std {

     /*!
      * @brief Exception class indicating methods not yet implemented.
      * @ingroup exceptions
      */
    class not_implemented : public exception {

    public:

        /// Construct with given error message:
        explicit not_implemented(
            const char* fname, const size_t& line,
            const char* error=nullptr);

        explicit not_implemented(
            const char* fname, const size_t& line,
            const std::string &error);

        /// Provided for compatibility with std::exception.
        const char* what() const _EXTFEMIO_NOEXCEPT override;

    private:

        string errorMessage;

    };
}

namespace dnvgl {
/// @ingroup extfem
    namespace extfem {
/// @ingroup extfem_base
        namespace __base {
            class outline;
        }
    }
}

std::ostream &operator<<(std::ostream&, dnvgl::extfem::__base::outline const&);

namespace dnvgl {
/// @ingroup extfem
    namespace extfem {
        namespace __base {

/*!
 * @brief General interface for classes general FEM file entries.
 * @ingroup extfem_base
 */
            class outline {

            protected:

                outline() = default;

                virtual ~outline() = default;

            public:

                std::ostream &operator<<(std::ostream&) const;

                friend std::ostream &::operator<<(
                    std::ostream&, outline const&);

            protected:

/// Method to be used by `operator<<` to output the actual data.
                virtual std::ostream &put(std::ostream&) const = 0;

            };
        }

/// Get library version string.
        std::string version();

/// Get library version string.
        std::string build_data();
    }
}

#endif // _EXTFEM_MISC_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_misc --use-colour no)"
// End:
