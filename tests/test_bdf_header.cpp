/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for NASTRAN bulk data file headers.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_bdf_header[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif

#include <deque>

#if (__GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))) || (_MSC_VER && _MSC_VER <= 1700)
#include <my_c++14.h>
#endif

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/header.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::header;

TEST_CASE("BDF generate 'SOL' header entries", "[bdf_header,sol]") {

    ostringstream test;

    SECTION("sol 101") {
        executive_control::sol probe(101);
        test << probe;
        CHECK(test.str() == "SOL 101\n");
    }

    SECTION("sol sol::SESTATIC") {
        executive_control::sol probe(executive_control::sol::sol_no_type::SESTATIC);
        test << probe;
        CHECK(test.str() == "SOL 101\n");
    }
}

TEST_CASE("BDF generate 'CEND' header entries", "[bdf_header,cend]") {

    ostringstream test;

    SECTION("cend") {
        executive_control::cend probe;
        test << probe;
        CHECK(test.str() == "CEND\n");
    }
}

TEST_CASE("BDF generate 'TITLE' header entries", "[bdf_header,title]") {

    ostringstream test;

    SECTION("title") {
        case_control::title probe("text");
        test << probe;
        CHECK(test.str() == "TITLE = text\n");
    }
}

TEST_CASE("BDF generate 'ECHO' header entries", "[bdf_header,echo]") {

    ostringstream test;

    SECTION("default") {
        case_control::echo probe;
        test << probe;
        CHECK(test.str() == "ECHO = NONE\n");
    }

    SECTION("NONE") {
        case_control::echo probe({make_shared<case_control::echo::none>()});
        test << probe;
        CHECK(test.str() == "ECHO = NONE\n");
    }
    SECTION("BOTH") {
        case_control::echo probe({make_shared<case_control::echo::both>()});
        test << probe;
        CHECK(test.str() == "ECHO = BOTH\n");
    }
}

TEST_CASE("BDF generate 'BEGIN BULK' header entries", "[bdf_header,begin bulk]") {

    ostringstream test;

    SECTION("1") {
        case_control::begin_bulk probe;
        test << probe;
        CHECK(test.str() == ("BEGIN BULK\n"));
    }
}

TEST_CASE("BDF generate 'SUBCASE' header entries", "[bdf_header,subcase]") {

    ostringstream test;

    SECTION("1") {
        case_control::subcase probe(1);
        test << probe;
        CHECK(test.str() == ("SUBCASE = 1\n"));
    }

    SECTION("Title") {
        case_control::subcase probe;
        test << probe;
        CHECK(test.str() == ("SUBCASE = 2\n"));
    }
}

TEST_CASE("BDF generate 'SUBTITLE' header entries", "[bdf_header,subtitle]") {

    ostringstream test;

    SECTION("1") {
        case_control::subtitle probe("LC 1");
        test << probe;
        CHECK(test.str() == "SUBTITLE = LC 1\n");
    }
}

TEST_CASE("BDF generate 'LOAD' header entries", "[bdf_header,load]") {

    ostringstream test;

    SECTION("1") {
        case_control::load probe(1);
        test << probe;
        CHECK(test.str() == "LOAD = 1\n");
    }

    SECTION("15") {
        case_control::load probe(15);
        test << probe;
        CHECK(test.str() == "LOAD = 15\n");
    }

    SECTION("ptr") {
        shared_ptr<__base::entry> probe = make_shared<case_control::load>(15);
        test << *probe;
        CHECK(test.str() == "LOAD = 15\n");
    }
}

namespace ExportBDF{ class BDF_Header; }
ostream&
    operator<<(ostream &, const ExportBDF::BDF_Header&);

namespace ExportBDF{

    class BDF_Header {
    private:
        vector<shared_ptr<dnvgl::extfem::bdf::header::__base::entry> > entries;
    public:
        BDF_Header(std::string const&);
        ~BDF_Header();
        void add_LC(long const &lc_num, long const &id, std::string const &title);
        ostream const &operator<<(ostream&) const;
        friend ostream&
        ::operator<<(ostream &, const BDF_Header&);
    };

    BDF_Header::BDF_Header(std::string const &title) {
        using namespace dnvgl::extfem::bdf::header;
        entries.push_back(
            make_shared<executive_control::sol>(
                executive_control::sol::sol_no_type::SESTATIC));
        entries.push_back(make_shared<executive_control::cend>());
        entries.push_back(make_shared<case_control::title>(title));
        entries.push_back(
            make_shared<case_control::echo>(
                vector<shared_ptr<case_control::echo::describer>>{
                    make_shared<case_control::echo::none>()}));
    }

    BDF_Header::~BDF_Header() {
        entries.clear();
    }

    void BDF_Header::add_LC(long const &this_case, long const &load,
                            std::string const &title) {
        using namespace dnvgl::extfem::bdf::header;
        entries.push_back(make_shared<case_control::subcase>(this_case));
        entries.push_back(make_shared<case_control::subtitle>(title));
        entries.push_back(make_shared<case_control::load>(load));
        entries.push_back(
            make_shared<case_control::displacement>(
                vector<shared_ptr<case_control::displacement::describer>>{
                    make_shared<case_control::displacement::print>(),
                    make_shared<case_control::displacement::punch>(),
                    make_shared<case_control::displacement::real>()},
                case_control::displacement::restype::ALL));
        entries.push_back(
            make_shared<case_control::spcforces>(
                vector<shared_ptr<case_control::spcforces::describer>>{
                    make_shared<case_control::spcforces::print>(),
                    make_shared<case_control::spcforces::nozprint>()},
                case_control::spcforces::restype::ALL));
        entries.push_back(
            make_shared<case_control::stress>(
                vector<shared_ptr<case_control::stress::describer>>{
                    make_shared<case_control::stress::sort1>(),
                    make_shared<case_control::stress::print>(),
                    make_shared<case_control::stress::real>(),
                    make_shared<case_control::stress::vonmises>(),
                    make_shared<case_control::stress::center>()},
                case_control::stress::restype::ALL));
    }

    ostream const &BDF_Header::operator<< (ostream &os) const {
        return os << this;
    }
}

ostream &operator<<(ostream &os, const ExportBDF::BDF_Header &entry) {
    for (auto const &p : entry.entries)
        os << *p;
    os << case_control::begin_bulk();
    return os;
}

TEST_CASE("Sample Header", "[bdf_header]") {

    ostringstream test;

    ExportBDF::BDF_Header probe("test case");

    probe.add_LC(1, 10, "LC_1");
    probe.add_LC(2, 20, "LC_2");
    probe.add_LC(3, 30, "LC_3");

    SECTION("result") {
        test << probe;
        CHECK(test.str() == "SOL 101\n"
              "CEND\n"
              "TITLE = test case\n"
              "ECHO = NONE\n"
              "SUBCASE = 1\n"
              "SUBTITLE = LC_1\n"
              "LOAD = 10\n"
              "DISPLACEMENT(PRINT, PUNCH, REAL) = ALL\n"
              "SPCFORCES(PRINT, NOZPRINT) = ALL\n"
              "STRESS(SORT1, PRINT, REAL, VONMISES, CENTER) = ALL\n"
              "SUBCASE = 2\n"
              "SUBTITLE = LC_2\n"
              "LOAD = 20\n"
              "DISPLACEMENT(PRINT, PUNCH, REAL) = ALL\n"
              "SPCFORCES(PRINT, NOZPRINT) = ALL\n"
              "STRESS(SORT1, PRINT, REAL, VONMISES, CENTER) = ALL\n"
              "SUBCASE = 3\n"
              "SUBTITLE = LC_3\n"
              "LOAD = 30\n"
              "DISPLACEMENT(PRINT, PUNCH, REAL) = ALL\n"
              "SPCFORCES(PRINT, NOZPRINT) = ALL\n"
              "STRESS(SORT1, PRINT, REAL, VONMISES, CENTER) = ALL\n"
              "BEGIN BULK\n");
    }
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test ;
//    ../cbuild/tests/test_bdf_header --use-colour no)"
// End:
