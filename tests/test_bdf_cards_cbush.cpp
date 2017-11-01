/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing the BDF `CBUSH` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards_cbush[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

using bdf::types::entry_type;
using bdf::types::entry_value;

TEST_CASE("BDF CBUSH definitions.", "[bdf_cbush]") {
    cbush::reset();

    SECTION("QR Guide, Example 1") {
        list<std::string> const data({"CBUSH,39,6,1,100,75"});
        list<std::string> lines;
        cards::__base::card::card_split(data, lines);
        cbush probe(lines);

        CHECK(long(probe.EID) == 39);
        CHECK(long(probe.PID) == 6);
        CHECK(long(probe.GA) == 1);
        CHECK(long(probe.GB) == 100);
        CHECK(long(probe.GO) == 75);
        CHECK_FALSE(bool(probe.X1));
        CHECK_FALSE(bool(probe.X2));
        CHECK_FALSE(bool(probe.X3));
        CHECK_FALSE(bool(probe.CID));
        CHECK_FALSE(bool(probe.S));
        CHECK_FALSE(bool(probe.OCID));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.S3));
    }

    SECTION("QR Guide, Example 2") {
        list<std::string> const data({"CBUSH,39,6,1,,,,,0"});
        std::list<std::string> lines;
        cards::__base::card::card_split(data, lines);
        cbush probe(lines);

        CHECK(long(probe.EID) == 39);
        CHECK(long(probe.PID) == 6);
        CHECK(long(probe.GA) == 1);
        CHECK_FALSE(bool(probe.GB));
        CHECK_FALSE(bool(probe.GO));
        CHECK_FALSE(bool(probe.X1));
        CHECK_FALSE(bool(probe.X2));
        CHECK_FALSE(bool(probe.X3));
        CHECK(long(probe.CID) == 0);
        CHECK_FALSE(bool(probe.S));
        CHECK_FALSE(bool(probe.OCID));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.S3));
    }

    SECTION("QR Guide, Example 3.") {
        list<std::string> const data({"CBUSH,39,6,1,100,,,,6"});
        std::list<std::string> lines;
        cards::__base::card::card_split(data, lines);
        cbush probe(lines);

        CHECK(long(probe.EID) == 39);
        CHECK(long(probe.PID) == 6);
        CHECK(long(probe.GA) == 1);
        CHECK(long(probe.GB) == 100);
        CHECK_FALSE(bool(probe.GO));
        CHECK_FALSE(bool(probe.X1));
        CHECK_FALSE(bool(probe.X2));
        CHECK_FALSE(bool(probe.X3));
        CHECK(long(probe.CID) == 6);
        CHECK_FALSE(bool(probe.S));
        CHECK_FALSE(bool(probe.OCID));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.S3));
    }

    SECTION("QR Guide, Example 3.") {
        std::list<std::string> const data({
                "CBUSH,39,6,1,600,,,,,0.25,10,0.,10.,10."});
        std::list<std::string> lines;
        cards::__base::card::card_split(data, lines);
        cbush probe(lines);

        CHECK(long(probe.EID) == 39);
        CHECK(long(probe.PID) == 6);
        CHECK(long(probe.GA) == 1);
        CHECK(long(probe.GB) == 600);
        CHECK_FALSE(bool(probe.GO));
        CHECK_FALSE(bool(probe.X1));
        CHECK_FALSE(bool(probe.X2));
        CHECK_FALSE(bool(probe.X3));
        CHECK_FALSE(bool(probe.CID));
        CHECK(double(probe.S) == .25);
        CHECK(long(probe.OCID) == 10);
        CHECK(double(probe.S1) == 0.);
        CHECK(double(probe.S2) == 10.);
        CHECK(double(probe.S3) == 10.);
    }
}


TEST_CASE("CBUSH Roundtrip test 1 (dir code).", "[bdf_cbush_roundtrip_1]") {
    cbush::reset();

    std::stringstream test;

    long EID{1}, PID{2}, GA{3}, GB{4}, GO{5};

    cbush const probe(&EID, &PID, &GA, &GB, nullptr, nullptr, nullptr, &GO);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH          1       2       3       4       5\n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.GO.value == 5);
    }
}

TEST_CASE("CBUSH Roundtrip test 1 (dir code) (reuse).", "[bdf_cbush_roundtrip_1_reuse]") {

    cbush::reset();

    std::stringstream test;

    long EID{1}, PID{2}, GA{3}, GB{4}, GO{5};

    cbush probe;
    probe(&EID, &PID, &GA, &GB, nullptr, nullptr, nullptr, &GO);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH          1       2       3       4       5\n");
    }

    SECTION("check reading") {
        cbush::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());
        cbush probe_l;

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.GO.value == 5);
    }
}

TEST_CASE("CBUSH Roundtrip test (QRG sample 1)", "[bdf_cbush_roundtrip_2]"){
    cbush::reset();

    ostringstream test;

    long EID{2}, PID{39}, GA{7}, GB{3};
    double X1{.6}, X2{18.}, X3{26.};
    long CID{0};

    cbush const probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, nullptr, &CID);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH          2      39       7       36.000-011.800+012.600+01       0\n");
    }

    SECTION("check reading") {
        cbush::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 26);
        CHECK(probe_l.CID.value == 0);
    }
}

TEST_CASE("CBUSH Roundtrip test (QRG sample 1) (reuse)", "[bdf_cbush_roundtrip_2_reuse]"){
    cbush::reset();

    std::ostringstream test;

    long EID{2}, PID{39}, GA{7}, GB{3};
    double X1{.6}, X2{18}, X3{26};
    long CID{0};

    cbush probe;
    probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, nullptr, &CID);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH          2      39       7       36.000-011.800+012.600+01       0\n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());
        cbush probe_l;

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 26);
        CHECK(probe_l.CID.value == 0);
    }
}

TEST_CASE("CBUSH Roundtrip test (QRG sample 1 (long))", "[bdf_cbush_roundtrip_3]") {
    cbush::reset();

    std::ostringstream test;

    long EID{2}, PID{39}, GA{7}, GB{3};
    double X1{.6}, X2{18}, X3{1234.5};
    long CID{0};

    cbush const probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, nullptr, &CID);

    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH*                 2              39               7               3\n"
              "*       6.00000000000-011.80000000000+011.23450000000+03               0\n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 1234.5);
        CHECK(probe_l.CID.value == 0);
    }
}

TEST_CASE("CBUSH Roundtrip test (QRG sample 1 (long)) (reuse)",
          "[bdf_cbush_roundtrip_3_reuse]") {
    cbush::reset();

    std::ostringstream test;

    long EID{2}, PID{39}, GA{7}, GB{3};
    double X1{.6}, X2{18}, X3{1234.5};
    long CID{0};

    cbush probe;
    probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, nullptr, &CID);

    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH*                 2              39               7               3\n"
              "*       6.00000000000-011.80000000000+011.23450000000+03               0\n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());
        cbush probe_l;

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 1234.5);
        CHECK(probe_l.CID.value == 0);
    }
}

TEST_CASE("CBUSH Roundtrip test (dir code all elements)", "[bdf_cbush_roundtrip_4]") {
    cbush::reset();

    std::ostringstream test;

    long EID{1}, PID{2}, GA{3}, GB{4}, GO{5};
    double S{.8};

    cbush const probe(&EID, &PID, &GA, &GB,
                nullptr, nullptr, nullptr, &GO, nullptr, &S);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH          1       2       3       4       5                        \n"
              "        8.000-01\n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.GO.value == 5);
        CHECK(probe_l.S.value == .8);
    }
}

TEST_CASE("CBUSH Roundtrip test (dir code all elements) (reuse)",
          "[bdf_cbush_roundtrip_4_reuse]") {
    cbush::reset();

    std::ostringstream test;

    long EID{1}, PID{2}, GA{3}, GB{4}, GO{5};
    double S{.7};

    cbush const probe(&EID, &PID, &GA, &GB,
                nullptr, nullptr, nullptr, &GO, nullptr,
                &S);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBUSH          1       2       3       4       5                        \n"
              "        7.000-01\n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.GO.value == 5);
        CHECK(probe_l.S.value == .7);
    }
}

TEST_CASE("CBUSH Roundtrip test (dir code all elements) (large)",
          "[bdf_cbush_roundtrip_5]") {
    cbush::reset();

    std::ostringstream test;
    long EID{123456789}, PID{2}, GA{3}, GB{4}, GO{5};
    double S{.6};

    cbush const probe(&EID, &PID, &GA, &GB,
                nullptr, nullptr, nullptr, &GO, nullptr,
                &S);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBUSH*         123456789               2               3               4\n"
              "*                      5                                                \n"
              "*       6.00000000000-01\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l(lines);

        CHECK(probe_l.EID.value == 123456789);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.GO.value == 5);
        CHECK(probe_l.S.value == .6);
    }
}

TEST_CASE("CBUSH Roundtrip test (dir code all elements) (large) (reuse)",
          "[bdf_cbush_roundtrip_5_reuse]") {
    cbush::reset();

    std::ostringstream test;
    long EID{123456789}, PID{2}, GA{3}, GB{4}, GO{5};
    double S{.2};

    cbush probe;
    test << probe;
    test << probe(&EID, &PID, &GA, &GB,
                  nullptr, nullptr, nullptr, &GO, nullptr,
                  &S);

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBUSH*         123456789               2               3               4\n"
              "*                      5                                                \n"
              "*       2.00000000000-01\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cbush probe_l;
        probe_l(lines);

        CHECK(probe_l.EID.value == 123456789);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.GO.value == 5);
        CHECK(probe_l.S.value == .2);

    }
}

TEST_CASE("CBUSH Roundtrip test dir code all large (ptr)", "[bdf_cbush_roundtrip_6]") {
    cbush::reset();

    std::ostringstream test;

    long EID{123456789}, PID{2}, GA{3}, GB{4}, GO{5};
    double S{.2};

    cards::__base::card *probe = new cbush(
        &EID, &PID, &GA, &GB,
        nullptr, nullptr, nullptr, &GO, nullptr,
        &S);
    test << *probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBUSH*         123456789               2               3               4\n"
              "*                      5                                                \n"
              "*       2.00000000000-01\n"
              "*       \n");
        delete probe;
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cards::__base::card *probe_l = new cbush(lines);

        CHECK(static_cast<cbush*>(probe_l)->EID.value == 123456789);
        CHECK(static_cast<cbush*>(probe_l)->PID.value == 2);
        CHECK(static_cast<cbush*>(probe_l)->GA.value == 3);
        CHECK(static_cast<cbush*>(probe_l)->GB.value == 4);
        CHECK(static_cast<cbush*>(probe_l)->GO.value == 5);
        CHECK(static_cast<cbush*>(probe_l)->S.value == .2);

        delete probe_l;
    }
}

TEST_CASE("CBUSH Roundtrip test dir code all large (ptr) (reuse)",
          "[bdf_cbush_roundtrip_6_reuse]") {
    cbush::reset();

    std::ostringstream test;

    long EID{123456789}, PID{2}, GA{3}, GB{4}, GO{5};
    double S{.5};

    cards::__base::card *probe = new cbush;
    test << *probe;
    (*static_cast<cbush*>(probe))(
        &EID, &PID, &GA, &GB,
        nullptr, nullptr, nullptr, &GO, nullptr,
        &S);
    test << *probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBUSH*         123456789               2               3               4\n"
              "*                      5                                                \n"
              "*       5.00000000000-01\n"
              "*       \n");
        delete probe;
    }

    SECTION("check reading") {
        cbush::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        cards::__base::card::card_split(data, lines);
        cards::__base::card *probe_l = new cbush;
        (*static_cast<cbush*>(probe_l))(lines);

        CHECK(static_cast<cbush*>(probe_l)->EID.value == 123456789);
        CHECK(static_cast<cbush*>(probe_l)->PID.value == 2);
        CHECK(static_cast<cbush*>(probe_l)->GA.value == 3);
        CHECK(static_cast<cbush*>(probe_l)->GB.value == 4);
        CHECK(static_cast<cbush*>(probe_l)->GO.value == 5);
        CHECK(static_cast<cbush*>(probe_l)->S.value == .5);

        delete probe_l;
    }
}

TEST_CASE("Multiple cbush lines.", "[bdf_cbush]") {
    cbush probe;

    std::ostringstream test;

    long EID{1};
    long PID{999};
    long GA{5};
    double X{1.}, Y{0.}, Z{0.};
    long CID{0};

    test << probe(&EID, &PID, &GA, nullptr, &X, &Y, &Z, nullptr, &CID); GA++;
    test << probe(&EID, &PID, &GA, nullptr, &X, &Y, &Z, nullptr, &CID); GA++;
    test << probe(&EID, &PID, &GA, nullptr, &X, &Y, &Z, nullptr, &CID); GA++;
    test << probe(&EID, &PID, &GA, nullptr, &X, &Y, &Z, nullptr, &CID); GA++;
    test << probe(&EID, &PID, &GA, nullptr, &X, &Y, &Z, nullptr, &CID);

        CHECK(test.str() ==
              "CBUSH          1     999       5        1.000+00 0.00+00 0.00+00       0\n"
              "CBUSH          2     999       6        1.000+00 0.00+00 0.00+00       0\n"
              "CBUSH          3     999       7        1.000+00 0.00+00 0.00+00       0\n"
              "CBUSH          4     999       8        1.000+00 0.00+00 0.00+00       0\n"
              "CBUSH          5     999       9        1.000+00 0.00+00 0.00+00       0\n");
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test ;
//    ../cbuild/tests/test_bdf_cards --use-colour no --invisibles)"
// End:
