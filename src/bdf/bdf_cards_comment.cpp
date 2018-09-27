/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Handle BDF comments.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_bdf_cards_comment[]) =
        "@(#) $Id$";
}

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <cmath>

#include "bdf/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;

shared_ptr<double> comment::yield = nullptr;

#ifdef HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
comment::find_yield("(?:^(?:.*[^[:digit:]])?((?:3(?:[15]5|90)|235|460))"
                    "(?:[^[:digit:]].*)?$)",
#ifdef HAVE_BOOST_REGEX_HPP
           boost::regex_constants::ECMAScript
#else
           std::regex_constants::ECMAScript
#endif
    );

void comment::to_yield(std::string const inp) {
    // Noch ein Zusatzwunsch zum Material. Der Name sollte auch
    // mit übernommen werden. Und wenn der Name 235 oder 315 oder
    // 355 oder 390 oder 460 als substring enthält dann diesen
    // Wert als yield stress übernehmen.
#ifdef HAVE_BOOST_REGEX_HPP
    boost::smatch
#else
        std::smatch
#endif
        m;
    if (regex_search(inp, m, comment::find_yield)) {
        if (m[1] == "235")      comment::yield = make_shared<double>(235.);
        else if (m[1] == "315") comment::yield = make_shared<double>(315.);
        else if (m[1] == "355") comment::yield = make_shared<double>(355.);
        else if (m[1] == "390") comment::yield = make_shared<double>(390.);
        else if (m[1] == "460") comment::yield = make_shared<double>(460.);
        else                    comment::yield = nullptr;
    }
}

comment::~comment() {
    this->__yield = nullptr;
}

comment::comment(std::list<std::string> const &inp) :
        card(), content(), __yield(nullptr) {
    this->comment::read(inp);
}

comment::comment(std::vector<std::string> const &content,
                 double *yield/*=nullptr*/) :
        card(), content(content.begin(), content.end()), __yield(nullptr) {
    if (yield) {
        comment::yield = make_shared<double>(*yield);
        this->__yield = make_shared<double>(*yield);
    } else
        this->__yield = nullptr;
}

comment::comment(std::string const *content,
                 double *yield/*=nullptr*/) :
        comment(std::vector<std::string>({*content}), yield) {}

comment::comment(std::string const &content,
                 double *yield/*=nullptr*/) :
        comment(std::vector<std::string>({content}), yield) {}

cards::types comment::card_type() const {
    return cards::types::COMMENT;
}

card const &comment::operator() (std::list<std::string> const &inp) {
    this->__yield = nullptr;
    this->read(inp);
    return *this;
}

card const &comment::operator() (std::vector<std::string> const &content,
                 double *yield/*=nullptr*/) {
    if (yield != nullptr) {
        comment::yield = make_shared<double>(*yield);
        this->__yield = make_shared<double>(*yield);
    } else {
        comment::yield = nullptr;
        this->__yield = nullptr;
    }
    this->content.assign(content.begin(), content.end());
    return *this;
}

card const &comment::operator()(std::string const &content,
                 double *yield/*=nullptr*/) {
    return this->comment::operator() (vector<std::string>({content}), yield);
}

card const &comment::operator()(std::string const *content,
                 double *yield/*=nullptr*/) {
    return this->comment::operator() (vector<std::string>({*content}), yield);
}

void comment::read(std::list<std::string> const &inp) {
    this->content.clear();
    std::string tmp_str;

    for (auto &pos : inp) {
        pos.size();

        comment::to_yield(pos);
        tmp_str.assign(pos.substr(pos[1] == ' ' ? 2 : 1));
        if (this->content.empty())
            this->content.push_back(tmp_str);
        else {
            if (tmp_str[0] == '+')
                this->content.back().append(tmp_str.substr(1));
            else
                if (tmp_str[0] == ' ')
                    this->content.push_back(tmp_str.substr(1));
                else
                    this->content.push_back(std::string(tmp_str) );
        }
    }
}

void comment::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    // Do not use!!
    NOT_IMPLEMENTED("DO NOT USE");
}

ostream &comment::put(ostream &os) const {
    for (auto pos : content) {
        std::string marker{"$ "};
        std::string tmp(pos.begin(), pos.end());
        do {
            os << marker << tmp.substr(0, 78) << endl;
            marker = "$+";
        } while ((pos.size() > 78) && (tmp = tmp.erase(0, 78)).size() > 0);
    }
    if (this->__yield != nullptr)
        os << "$ YIELD: " << round(*this->__yield) << endl;
    return os;
}

void comment::clear_yield() {
     comment::yield = nullptr;
}

void comment::check_data() {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
