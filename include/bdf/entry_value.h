/**
  \file
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2017 by DNV GL SE
  \brief Values for card entries.

  Detailed description
*/

/* ID: $Id$
 */

#ifndef _BNF_ENTRY_VALUE_H_
#define _BDF_ENTRY_VALUE_H_

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace types {

                //! Value for card entries.
                template <typename _Ty>
                class entry_value {
                public:
                    _Ty value;
                    bool is_value;
                    explicit entry_value(const _Ty value, const bool is_value=true);
                    explicit entry_value(const _Ty *value);
                    explicit entry_value();
                    entry_value(entry_value<_Ty> const&) = default;
                    entry_value<_Ty> &operator= (const _Ty &other);
                    bool operator== (const _Ty &other) const;
                    bool operator< (const _Ty &other) const;
                    bool operator|| (
                        const entry_value<_Ty> &other) const;
                    operator bool() const;
                    operator _Ty() const;
                    void operator() (const _Ty *val);
                    void operator() (const _Ty &val);
                    void push_back(const long&);
                };

                template <typename _Ty>
                entry_value<_Ty>::entry_value(
                    const _Ty value, const bool is_value) :
                        value(value), is_value(is_value) {}

                template <typename _Ty>
                entry_value<_Ty>::entry_value(const _Ty *value) {
                    if (!value) {
                        is_value = false;
                        this->value = _Ty();
                    } else {
                        is_value = true;
                        this->value = *value;
                    }
                }

                template <typename _Ty>
                entry_value<_Ty>::entry_value() :
                        value(_Ty()), is_value(false) {}

                template <typename _Ty>
                entry_value<_Ty> &entry_value<_Ty>::operator= (const _Ty &other) {
                    this->entry_value<_Ty>::operator() (other);
                    return *this;
                }


                template <typename _Ty>
                bool entry_value<_Ty>::operator== (const _Ty &other) const {
                    return is_value && value == other;
                }

                template <typename _Ty>
                bool entry_value<_Ty>::operator< (const _Ty &other) const {
                    return is_value && value < other;
                }

                template <typename _Ty>
                bool entry_value<_Ty>::operator|| (
                    const entry_value<_Ty> &other) const {
                    return is_value || other.is_value;
                }

                template <typename _Ty>
                entry_value<_Ty>::operator bool() const {
                    return is_value;
                }

                template <typename _Ty>
                entry_value<_Ty>::operator _Ty() const {
                    return value;
                }

                template <typename _Ty>
                void entry_value<_Ty>::operator() (const _Ty *val) {
                    is_value = (val != nullptr);
                    if (is_value) value = *val;
                }

                template <typename _Ty>
                void entry_value<_Ty>::operator() (const _Ty &val) {
                    is_value = true;
                    value = val;
                }

                // ReSharper disable CppPossiblyUninitializedMember
                template <> inline
                entry_value<std::vector<int> >::entry_value(
                    const entry_value<std::vector<int> > &val) :
                        value(val.value), is_value(val.is_value) {}

                template <> inline
                entry_value<std::vector<int> >::entry_value(
                    const std::vector<int> value, const bool is_value) :
                        value(value), is_value(is_value) {}

                template <> inline
                entry_value<std::vector<int> >::entry_value(
                    const std::vector<int> *value) :
                        is_value(value != nullptr) {
                    if (value)
                        copy(value->begin(), value->end(),
                        back_inserter(this->value));
                }
                // ReSharper restore CppPossiblyUninitializedMember

                template <> inline
                entry_value<std::string>::entry_value(
                    const std::string *value) :
                        value(""), is_value(value != nullptr) {
                    if (is_value) this->value = *value;
                }

                template <> inline
                void entry_value<std::string>::operator() (const std::string *val) {
                    is_value = (val != nullptr);
                    if (is_value) value = *val;
                    else value = "";
                }

                template <> inline
                void entry_value<std::vector<int> >::push_back(const long &inp) {
                    this->value.push_back(inp);
                }
            }
        }
    }
}

#endif // _BDF_ENTRY_VALUE_H_

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
