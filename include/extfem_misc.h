/**
   \file extfem_misc.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Misc. definitions for the extfem library.

   Detailed description
*/

// ID: $Id$

#if !defined _EXTFEM_MISC_H_
#define _EXTFEM_MISC_H_

#include <sstream>
#include <cstring>

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


namespace std {

    class not_implemented : public std::exception {

    public:

        // Construct with given error message:
        not_implemented(const char *fname="", const size_t &line=0,
                        const char *error = "Functionality not yet implemented!") {
            std::ostringstream msg("", std::ostringstream::ate);
            if (line != 0 && std::strlen(fname) > 0)
                msg << fname << ":" << line << ":";
            msg << "Functionality not yet implemented!";
            errorMessage = msg.str();
        }

        // Provided for compatibility with std::exception.
        const char *what() const _EXTFEMIO_NOEXCEPT {
            return errorMessage.c_str();
        }

    private:

        std::string errorMessage;
    };
}

namespace dnvgl {
    namespace extfem {
        namespace __base {
            class outline {
            protected:
                outline(void);
                virtual ~outline(void);
            public:
                std::ostream &operator<<(std::ostream&);
                friend std::ostream &operator<<(std::ostream&, outline const &);
            protected:
                virtual std::ostream &put(std::ostream&) const = 0;
            };
        }
        std::string version(void);
        std::string build_data(void);
    }
}

#endif // _EXTFEM_MISC_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
