/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Handle BDF comments.

   Detailed description
*/

// ID:
namespace {
   char const cID_bdf_cards_comment[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <cmath>

#include "bdf/cards.h"

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;

double *comment::yield{nullptr};

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
        if (comment::yield != nullptr) {
            delete comment::yield;
            comment::yield = nullptr;
        }
        if (m[1] == "235")
            comment::yield = new double(235.);
        else if (m[1] == "315")
            comment::yield = new double(315.);
        else if (m[1] == "355")
            comment::yield = new double(355.);
        else if (m[1] == "390")
            comment::yield = new double(390.);
        else if (m[1] == "460")
            comment::yield = new double(460.);
    }
}

comment::comment() :
        card(), content(), __yield(nullptr) {}

comment::~comment() {
 if (yield != nullptr)
     delete this->__yield;
}

comment::comment(std::list<std::string> const &inp) :
        card(), content(), __yield(nullptr) {
    this->comment::read(inp);
}

comment::comment(std::vector<std::string> const &content,
                 double *yield/*=nullptr*/) :
        card(), content(content.begin(), content.end()), __yield(nullptr) {
    if (yield != nullptr) {
        if (comment::yield == nullptr)
            comment::yield = new double();
        *comment::yield = *yield;
        this->__yield = new double(*yield);
    }
}

comment::comment(std::string const *content,
                 double *yield/*=nullptr*/) :
        card(), content(list<std::string>({*content})), __yield(nullptr) {
    if (yield != nullptr) {
        if (comment::yield == nullptr)
            comment::yield = new double();
        *comment::yield = *yield;
        this->__yield = new double(*yield);
    }
}

cards::types comment::card_type() const {
    return cards::types::COMMENT;
}

card const &comment::operator() (std::list<std::string> const &inp) {
    if (this->__yield != nullptr)
        delete this->__yield;
    this->__yield = nullptr;
    this->read(inp);
    return *this;
}

card const &comment::operator() (std::vector<std::string> const &content,
                 double *yield/*=nullptr*/) {
    if (this->__yield != nullptr)
        delete this->__yield;
    this->__yield = nullptr;
    if (yield != nullptr) {
        if (comment::yield == nullptr)
            comment::yield = new double();
        *comment::yield = *yield;
        this->__yield = new double(*yield);
    }
    this->content.assign(content.begin(), content.end());
    return *this;
}

card const &comment::operator()(std::string const *content,
                 double *yield/*=nullptr*/) {
    if (this->__yield != nullptr)
        delete this->__yield;
    this->__yield = nullptr;
    if (yield != nullptr) {
        if (comment::yield == nullptr)
            comment::yield = new double();
        *comment::yield = *yield;
        this->__yield = new double(*yield);
    }
    this->content.push_back(*content);
    return *this;
}

void comment::read(std::list<std::string> const &inp) {
    this->content.clear();
    std::string tmp_str;

    for (auto &pos : inp) {
        pos.size();

        comment::to_yield(pos);
        tmp_str.assign(pos.substr(pos[1] == ' ' ? 2 : 1));
        if (this->content.size() == 0)
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
    std::string marker;
    for (auto pos : content) {
        marker = "$ ";
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
    if (comment::yield != nullptr)
        delete comment::yield;
    comment::yield = nullptr;
}

void comment::check_data() const {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
