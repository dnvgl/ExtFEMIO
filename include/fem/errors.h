/**
   \file fem/errors.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Define errors for handling FEM files.

   Detailed description
*/

// ID: $Id$

#pragma once

// ReSharper disable once CppUnusedIncludeDirective
#include <string>

#if defined(_MSC_VER) & _MSC_VER < 1900
#define _EXTFEMIO_NOEXCEPT
#else
#define _EXTFEMIO_NOEXCEPT noexcept
#endif

#if !defined _FEM_ERRORS_H_
#define _FEM_ERRORS_H_

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace errors {

                class error : public virtual std::exception {

                protected:

                    std::string msg;
                    std::string name;
                    std::string err_class;

                    std::string get_msg() const;

                public:

                    explicit error(
                        const std::string &msg,
                        const std::string &err_class="fem_error");

                    error(
                        const std::string&, const std::string &msg,
                        const std::string &err_class);

                    char const *what() const _EXTFEMIO_NOEXCEPT override;
                };

                class types_error : public error {

                public:

                    explicit types_error(const std::string &msg);
                };

                class float_error : public error {

                public:

                    float_error(const std::string &name, const std::string &msg);
                };

                class int_error : public error {

                public:

                    int_error(const std::string &name, const std::string &msg);
                };

                class bool_error : public error {

                public:

                    bool_error(const std::string &name, const std::string &msg);
                };

                class output_error : public error {

                public:

                    output_error(const std::string &name, const std::string &msg);
                };

                class list_error : public error {

                public:

                    list_error(const std::string &name, const std::string &msg);
                };

                class str_error : public error {

                public:

                    str_error(const std::string &name, const std::string &msg);
                };

                class string_error : public error {

                public:

                    string_error(const std::string &name, const std::string &msg);
                };

                class parse_error : public error {

                public:

                    parse_error(const std::string &name, const std::string &msg);
                };

                class usage_error : public error {

                public:

                    usage_error(const std::string &name, const std::string &msg);
                };

                class no_used : public virtual error {

                public:

                    explicit no_used(long const &no);
                };

                class id_used : public virtual error {

                public:

                    explicit id_used(long const &id);
                };

                class data_not_matching_id : public virtual error {

                public:

                    data_not_matching_id(long const &id_ex, long const &id_new);
                };
            }
        }
    }
}

#endif // _FEM_ERRORS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
