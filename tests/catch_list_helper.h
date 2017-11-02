/**
  \file
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2017 by DNV GL SE
  \brief Helper classes to compare std::list's under catch.hpp.

  Detailed description
*/

/* ID: $Id$
 */

#pragma once
#include <list>
#include <ostream>

#ifndef _CATCH_LIST_HELPER_H_
#define _CATCH_LIST_HELPER_H_

#ifdef min
#undef min
#endif

namespace std {
    template<typename _Ty>
    std::ostream &operator<<(std::ostream &os, std::list<_Ty> const &in) {
        os << "[" << endl;
        size_t i{0};
        for (auto pos : in) {
            os << pos;
            if (++i != in.size()) {
                os << ", ";
                if (i % 3 == 0)
                    os << endl;
            }
        }
        os << endl << "]";
        return os;
    }

    template<typename _Ty>
    inline std::string toString(std::list<_Ty> &in) {
        std::ostringstream ss;
        ss << in;
        return in.str();
    }

    // The list matcher class
    template<typename _Ty>
    class MatchList : public Catch::MatcherBase<std::list<_Ty>> {
        std::list<_Ty> ref;
        _Ty const static eps;
    public:
        explicit MatchList(std::list<_Ty> const &ref) : ref(ref) {}

        // Performs the test for this matcher
        virtual bool match(std::list<_Ty> const &in) const override {
            return (abs(ref - in) < eps).min();
        }

        // Produces a string describing what this matcher does. It should
        // include any provided data (the begin/ end in this case) and
        // be written as if it were stating a fact (in the output it will be
        // preceded by the value under test).
        std::string describe() const override {
            std::ostringstream ss;
            ss << "equals list " << ref;
            return ss.str();
        }
    };

    template<typename _Ty>
    const _Ty MatchList<_Ty>::eps = _Ty(1e-8);

    template<>
    const std::string MatchList<std::string>::eps = "";

    template<>
    inline bool MatchList<std::string>::match(std::list<std::string> const &in) const {
        return ref == in;
    }

    // The builder function
    template<typename _Ty>
    inline MatchList<_Ty> IsEqual(std::list<_Ty> const &in) {
        return MatchList<_Ty>(in);
    }
}


#endif // _CATCH_LIST_HELPER_H_

/*
  Local Variables:
  mode: c++
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../cbuild -j7 &&
  (make -C ../cbuild test ;
    ../cbuild/tests/test_bdf_cards --use-colour no)"
  coding: utf-8
  End:
 */
