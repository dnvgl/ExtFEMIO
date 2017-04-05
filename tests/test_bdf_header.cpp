/**
   \file tests/test_bdf_header.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for NASTRAN bulk data file headers.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <deque>

#include <my_c++14.h>

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/header.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::header;

TEST_CASE("BDF generate 'SOL' header entries", "[bdf_header,sol]") {

    std::ostringstream test;

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

    std::ostringstream test;

    SECTION("cend") {
        executive_control::cend probe;
        test << probe;
        CHECK(test.str() == "CEND\n");
    }
}

TEST_CASE("BDF generate 'TITLE' header entries", "[bdf_header,title]") {

    std::ostringstream test;

    SECTION("") {
        case_control::title probe("text");
        test << probe;
        CHECK(test.str() == "TITLE = text\n");
    }
}

TEST_CASE("BDF generate 'ECHO' header entries", "[bdf_header,echo]") {

    std::ostringstream test;

    SECTION("default") {
        case_control::echo probe;
        test << probe;
        CHECK(test.str() == "ECHO = NONE\n");
    }

    SECTION("NONE") {
        case_control::echo probe({new case_control::echo::none});
        test << probe;
        CHECK(test.str() == "ECHO = NONE\n");
    }
    SECTION("BOTH") {
        case_control::echo probe({new case_control::echo::both});
        test << probe;
        CHECK(test.str() == "ECHO = BOTH\n");
    }
}

TEST_CASE("BDF generate 'BEGIN BULK' header entries", "[bdf_header,begin bulk]") {

    std::ostringstream test;

    SECTION("1") {
        case_control::begin_bulk probe;
        test << probe;
        CHECK(test.str() == ("BEGIN BULK\n"));
    }
}

TEST_CASE("BDF generate 'SUBCASE' header entries", "[bdf_header,subcase]") {

    std::ostringstream test;

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

    std::ostringstream test;

    SECTION("1") {
        case_control::subtitle probe("LC 1");
        test << probe;
        CHECK(test.str() == "SUBTITLE = LC 1\n");
    }
}

TEST_CASE("BDF generate 'LOAD' header entries", "[bdf_header,load]") {

    std::ostringstream test;

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
        std::unique_ptr<__base::entry> probe = std::make_unique<case_control::load>(15);
        test << *probe;
        CHECK(test.str() == "LOAD = 15\n");
    }
}

namespace ExportBDF{ class BDF_Header; }
std::ostream&
    operator<<(std::ostream &, const ExportBDF::BDF_Header&);

namespace ExportBDF{

    class BDF_Header {
    private:
        std::list<std::unique_ptr<dnvgl::extfem::bdf::header::__base::entry> > entries;
    public:
        BDF_Header(std::string const&);
        ~BDF_Header();
        void add_LC(long const &lc_num, long const &id, std::string const &title);
        std::ostream const &operator<<(std::ostream&) const;
        friend std::ostream&
        ::operator<<(std::ostream &, const BDF_Header&);
    };

    BDF_Header::BDF_Header(std::string const &title) {
        using namespace dnvgl::extfem::bdf::header;
        entries.push_back(
            std::make_unique<executive_control::sol>(
                executive_control::sol::sol_no_type::SESTATIC));
        entries.push_back(std::make_unique<executive_control::cend>());
        entries.push_back(std::make_unique<case_control::title>(title));
        entries.push_back(
            std::make_unique<case_control::echo>(
                std::list<case_control::echo::describer*>{
                    new case_control::echo::none}));
    }

    BDF_Header::~BDF_Header() {
        entries.clear();
    }

    void BDF_Header::add_LC(long const &this_case, long const &load,
                            std::string const &title) {
        using namespace dnvgl::extfem::bdf::header;
        entries.push_back(std::make_unique<case_control::subcase>(this_case));
        entries.push_back(std::make_unique<case_control::subtitle>(title));
        entries.push_back(std::make_unique<case_control::load>(load));
        entries.push_back(
            std::make_unique<case_control::displacement>(
                std::list<case_control::displacement::describer*>{
                    new case_control::displacement::print,
                        new case_control::displacement::punch,
                        new case_control::displacement::real},
                case_control::displacement::restype::ALL));
        entries.push_back(
            std::make_unique<case_control::spcforces>(
                std::list<case_control::spcforces::describer*>{
                    new case_control::spcforces::print,
                        new case_control::spcforces::nozprint},
                case_control::spcforces::restype::ALL));
        entries.push_back(
            std::make_unique<case_control::stress>(
                std::list<case_control::stress::describer*>{
                    new case_control::stress::sort1,
                        new case_control::stress::print,
                        new case_control::stress::real,
                        new case_control::stress::vonmises,
                        new case_control::stress::center},
                case_control::stress::restype::ALL));
    }

    std::ostream const &BDF_Header::operator<< (std::ostream &os) const {
        return os << this;
    }
}

std::ostream &operator<<(std::ostream &os, const ExportBDF::BDF_Header &entry) {
    for (auto const &p : entry.entries)
        os << *p;
    os << case_control::begin_bulk();
    return os;
}

TEST_CASE("Sample Header", "[bdf_header]") {

    std::ostringstream test;

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
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
