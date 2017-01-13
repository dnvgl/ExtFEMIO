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

namespace std {

    class not_implemented : public std::exception {

    public:

        // Construct with given error message:
        not_implemented(const std::string &error=std::string("Functionality not yet implemented!")) {
            errorMessage = error;
        }

        not_implemented(const std::string &fname, const size_t &line) {
            std::ostringstream msg("", std::ostringstream::ate);
            msg << fname << ":" << line << ":"
                <<"Functionality not yet implemented!";
            errorMessage = msg.str();
        }

        // Provided for compatibility with std::exception.
        const char *what() const
#if __GNUC__
            noexcept
#endif
        {
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
