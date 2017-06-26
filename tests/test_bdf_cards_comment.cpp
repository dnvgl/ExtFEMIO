/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Handle BDF comments

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   char const cID_test_bdf_cards_comment[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"
#include "bdf/file.h"

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace bdf::cards;
using namespace bdf::cards::__base;

using bdf::types::entry_type;
using bdf::types::entry_value;

class test_comment : public comment {
public:
    using comment::find_yield;
};

TEST_CASE("BDF COMMENT yield stress definition.", "[bdf_comment]") {
#ifdef HAVE_BOOST_REGEX_HPP
        boost::smatch
#else
        std::smatch
#endif
            m;
        CHECK(regex_search(std::string("$ 235"), m, test_comment::find_yield));
        CHECK(regex_search(
                  std::string("$ Yield: 315 test"), m, test_comment::find_yield));
        CHECK(regex_search(std::string("$ 355"), m, test_comment::find_yield));
        CHECK(regex_search(std::string("$ 390"), m, test_comment::find_yield));
        CHECK(regex_search(std::string("$ 460"), m, test_comment::find_yield));
}

TEST_CASE("BDF COMMENT definitions; empty comment.", "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ "});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({""}));
}

TEST_CASE("BDF COMMENT definitions; long comment.", "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ a",
            "$+     a"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"a     a"}));
}

TEST_CASE("BDF COMMENT definitions; long comment (2).", "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ a",
            "$+12345a"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"a12345a"}));
}

TEST_CASE("BDF COMMENT definitions; one line.",
          "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$foo"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"foo"}));
}

TEST_CASE("BDF COMMENT definitions; with yield stress (235).",
          "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ 235"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"235"}));
    CHECK((comment::yield && *comment::yield == 235.));
}

TEST_CASE("BDF COMMENT definitions; with yield stress (315).",
          "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ yield stress for the following material definition:315"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({
                "yield stress for the following material definition:315"}));
    CHECK((probe.yield && *probe.yield == 315.));
    CHECK((comment::yield && *comment::yield == 315.));

    comment::clear_yield();

    CHECK(probe.yield == nullptr);
    CHECK(comment::yield == nullptr);
}

TEST_CASE("BDF COMMENT definitions; with yield stress (355).",
          "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ yield stress: 355"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"yield stress: 355"}));
    CHECK((probe.yield && *probe.yield == 355.));
    CHECK((comment::yield && *comment::yield == 355.));
}

TEST_CASE("BDF COMMENT definitions; with yield stress (390).",
          "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ 390"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"390"}));
    CHECK((probe.yield && *probe.yield == 390.));
    CHECK((comment::yield && *comment::yield == 390.));
}

TEST_CASE("BDF COMMENT definitions; with yield stress (460).",
          "[bdf_comment]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "$ 460"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    comment probe(lines);

    CHECK(probe.content == list<std::string>({"460"}));
    CHECK((probe.yield && *probe.yield == 460.));
    CHECK((comment::yield && *comment::yield == 460.));
}

TEST_CASE("BDF COMMENT roundtrip test", "[bdf_comment]") {
    ostringstream test;

    std::string content("");

    comment probe(&content);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() == "$ \n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        input::bdf_file file(raw);
        file.get(data);

        card::card_split(data, lines);
        comment probe_l(lines);

        CHECK(probe_l.content == list<std::string>({""}));
    }
}

TEST_CASE("BDF COMMENT roundtrip test (reuse)", "[bdf_comment]") {
    ostringstream test;

    std::string content("");

    comment probe;
    test << probe;
    test << probe(&content);

    SECTION("check output") {
        CHECK(test.str() ==
              "$ \n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l;
        probe_l(lines);

        CHECK(probe_l.content == list<std::string>({""}));
    }
}

TEST_CASE("BDF COMMENT roundtrip test; two lines.", "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content{"This is a test", "one two"};

    comment probe(content);
    test << probe;

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
              "$ This is a test\n"
              "$ one two\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "This is a test",
                    "one two"}));
        CHECK(probe_l.yield == nullptr);
        CHECK(comment::yield == nullptr);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; two lines (reuse).", "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content{"This is a test", "one two"};

    comment probe;
    test << probe;
    test << probe(content);

    SECTION("check output") {
        CHECK(test.str() ==
              "$ This is a test\n"
              "$ one two\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l;
        probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "This is a test",
                    "one two"}));
        CHECK(probe_l.yield == nullptr);
        CHECK(comment::yield == nullptr);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; two lines (2).", "[bdf_comment]") {
    ostringstream test;

    std::string content{"This is a test"};

    comment probe(content);
    probe("one two");
    test << probe;

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
              "$ This is a test\n"
              "$ one two\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "This is a test",
                    "one two"}));
        CHECK(probe_l.yield == nullptr);
        CHECK(comment::yield == nullptr);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; long line.", "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content{
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean "
        "commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus"};

    comment probe(content);
    test << probe;

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "$ Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligul\n"
        "$+a eget dolor. Aenean massa. Cum sociis natoque penatibus\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. "
                    "Aenean commodo ligula eget dolor. Aenean massa. Cum "
                    "sociis natoque penatibus"}));
        CHECK(probe_l.yield == nullptr);
        CHECK(comment::yield == nullptr);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; long line (reuse).", "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content{
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean "
        "commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus"};

    comment probe;
    test << probe;
    test << probe(content);

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "$ Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligul\n"
        "$+a eget dolor. Aenean massa. Cum sociis natoque penatibus\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l;
        probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. "
                    "Aenean commodo ligula eget dolor. Aenean massa. Cum "
                    "sociis natoque penatibus"}));
        CHECK(probe_l.yield == nullptr);
        CHECK(comment::yield == nullptr);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; only yield stress.", "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content;
    double *yield = new double(315.);

    comment probe(content, yield);
    test << probe;

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "$ YIELD: 315\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l(lines);

        CHECK(probe_l.content == list<std::string>({"YIELD: 315"}));
        CHECK(*probe_l.yield == 315.);
        CHECK(*comment::yield == 315.);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; only yield stress (reuse).",
          "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content;
    double *yield = new double(315.);

    comment probe;
    test << probe;
    test << probe(content, yield);

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "$ YIELD: 315\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l;
        probe_l(lines);

        CHECK(probe_l.content == list<std::string>({"YIELD: 315"}));
        CHECK(*probe_l.yield == 315.);
        CHECK(*comment::yield == 315.);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; yield stress and comment.",
          "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content{
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean "
        "commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus"};
    double *yield = new double(315.);

    comment probe(content, yield);
    test << probe;

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
              "$ Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligul\n"
              "$+a eget dolor. Aenean massa. Cum sociis natoque penatibus\n"
              "$ YIELD: 315\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean "
                    "commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus",
                    "YIELD: 315"}));
        CHECK(*probe_l.yield == 315.);
        CHECK(*comment::yield == 315.);
    }
}

TEST_CASE("BDF COMMENT roundtrip test; yield stress and comment (reuse).",
          "[bdf_comment]") {
    ostringstream test;

    vector<std::string> content{
        // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean "
        "commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus"};
    double *yield = new double(315.);

    comment probe;
    test << probe;
    test << probe(content, yield);

    reset_statics();

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
              "$ Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligul\n"
              "$+a eget dolor. Aenean massa. Cum sociis natoque penatibus\n"
              "$ YIELD: 315\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        comment probe_l;
        probe_l(lines);

        CHECK(probe_l.content == list<std::string>({
                    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean "
                    "commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus",
                    "YIELD: 315"}));
        CHECK(*probe_l.yield == 315.);
        CHECK(*comment::yield == 315.);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test ;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
