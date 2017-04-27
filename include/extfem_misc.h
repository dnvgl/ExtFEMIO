/**
   \file extfem_misc.h
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

#if defined(_MSC_VER) & _MSC_VER < 1900
#define _EXTFEMIO_NOEXCEPT
#else
#define _EXTFEMIO_NOEXCEPT noexcept
#endif

#ifdef __GNUC__
#define _EXTFEMIO_UNUSED __attribute__((__unused__))
#else
#define _EXTFEMIO_UNUSED
#endif

#define NOT_IMPLEMENTED(msg) throw std::not_implemented(__FILE__, __LINE__, msg)

namespace std {

    class not_implemented : public exception {

    public:

        // Construct with given error message:
        explicit not_implemented(
            const char* fname, const size_t& line,
            const char* error=nullptr);

        // Provided for compatibility with std::exception.
        const char* what() const _EXTFEMIO_NOEXCEPT override;

    private:

        string errorMessage;
    };
}

namespace dnvgl {
    namespace extfem {
        namespace __base {
            class outline;
        }
    }
}
std::ostream &operator<<(std::ostream&, dnvgl::extfem::__base::outline const&);

namespace dnvgl {
    namespace extfem {
        namespace __base {
            class outline {
            protected:
                outline() = default;
                virtual ~outline() = default;
            public:
                std::ostream &operator<<(std::ostream&) const;
                friend std::ostream &::operator<<(
                    std::ostream&, outline const&);
            protected:
                virtual std::ostream &put(std::ostream&) const = 0;
            };
        }
        std::string version();
        std::string build_data();
    }
}

#endif // _EXTFEM_MISC_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_misc --use-colour no)"
// End:
