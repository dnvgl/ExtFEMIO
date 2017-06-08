/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Error handling for processing BDF data.

   Detailed description
*/

// ID: $Id$

#if !defined _BDF_ERRORS_H_
#define _BDF_ERRORS_H_

#if defined(_MSC_VER) & _MSC_VER < 1900
#define _EXTFEMIO_NOEXCEPT
#else
#define _EXTFEMIO_NOEXCEPT noexcept
#endif

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace errors {

                class error : public std::exception {
                protected:
                    error() = default;
                protected:
                    std::string msg = "";
                    std::string name = "";
                    std::string err_class = "";
                    std::string get_msg() const;
                public:
                    ~error() = default;
                    error(
                        const std::string&, const std::string &msg,
                        const std::string &err_class="bdf_error");
                    char const *what() const _EXTFEMIO_NOEXCEPT override;
                };

                class types_error : public error {
                    types_error() = default;
                public:
                    ~types_error() = default;
                    types_error(const std::string &msg);
                };

                class form_error : public error {
                protected:
                    form_error() = default;
                public:
                    ~form_error() = default;
                    form_error(
                        const std::string &name, const std::string &msg,
                        const std::string &cls="bdf_error");
                };

                class float_error : public form_error {
                    float_error() = default;
                public:
                    ~float_error() = default;
                    float_error(const std::string&, const std::string&);
                };

                class complex_error : public form_error {
                    complex_error() = default;
                public:
                    ~complex_error() = default;
                    complex_error(const std::string&, const std::string&);
                };

                class int_error : public form_error {
                    int_error() = default;
                public:
                    ~int_error() = default;
                    int_error(const std::string&, const std::string&);
                };

                class list_error : public form_error {
                    list_error() = default;
                public:
                    ~list_error() = default;
                    list_error(const std::string&, const std::string &);
                };

                class str_error : public form_error {
                    str_error() = default;
                public:
                    ~str_error() = default;
                    str_error(const std::string&, const std::string &);
                };

                class output_error : public error {
                    output_error() = default;
                public:
                    ~output_error() = default;
                    output_error(const std::string&, const std::string&);
                };

                class parse_error : public error {
                    parse_error() = default;
                public:
                    ~parse_error() = default;
                    parse_error(const std::string&, const std::string &);
                };

                class usage_error : public error {
                    usage_error() = default;
                public:
                    ~usage_error() = default;
                    usage_error(const std::string&, const std::string &);
                };
            }
        }
    }
}

#endif // _BDF_ERRORS_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
