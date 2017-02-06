/**
   \file tests/test_fem_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the FEM cards classes.

   Detailed description
*/

// ID:
namespace {
    char const cID_test_fem_cards[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <iostream>
#include <list>
#include <vector>

#include <catch.hpp>

#include "config.h"

#include "fem/cards.h"
#include "fem/file.h"
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;
using namespace dnvgl::extfem::fem::input;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
    return Catch::toString( ex.what() );
}

CATCH_TRANSLATE_EXCEPTION( exception& ex ) {
    return Catch::toString( ex.what() );
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
    return ex;
}

TEST_CASE("Split FEM dataset", "[datasets, split]") {

    SECTION("Checkn icomplete lines") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GCHAN     1.00000000E+00  1.00000001E-01  9.99999978E-03  9.99999978E-03\n",
                "          9.99999978E-03  1.00000001E-01  1.00000000E+00\n",
                "          1.00000000E+00\n" });
        vector<string> entries;
        long len = __base::card::card_split(data, data.size(), entries);
        REQUIRE(len == 13);
        REQUIRE(entries == vector<string>({
                    "GCHAN", "  1.00000000E+00", "  1.00000001E-01",
                    "  9.99999978E-03", "  9.99999978E-03", "  9.99999978E-03",
                    "  1.00000001E-01", "  1.00000000E+00", "                ",
                    "  1.00000000E+00", "                ", "                ",
                    "                "}));
    }
}

TEST_CASE("FEM_Dispatch", "[cards, ident]") {

    string s(
        //  45678|234567890123456|234567890123456|234567890123456|234567890123456
        //       SLEVEL          SELTYP          SELMOD
        "IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000\n"
        "TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001\n"
        "        CONVERSION DETAILS:\n"
        "        Msc Nastran File Format -> Sesam Interface File.\n"
        "        Input  : \\test_01.fem\n"
        "        Log    : \\test_01.txt\n"
        "DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001\n"
        "        DATE TIME:  11/03/2015 09:46:08\n"
        "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013\n"
        "        COMPUTER: HAML130185\n"
        "        USER: berhol\n");
    s += "TDLOAD   4.00000000e+000 1.00000000e+000 1.07000000e+002 0.00000000e+000\n"
        "        SubCase\n";
    s += "GNODE    1.00000000e+000 1.00000000e+000 6.00000000e+000 1.23456000e+005\n";
    s += "GCOORD   1.00000000e+000 1.11525000e+005 1.80000000e+004 2.10000000e+004\n";
    s += "GELMNT1  3.39000000e+002 8.54000000e+002 2.40000000e+001 0.00000000e+000\n"
        "         6.08000000e+002 6.18000000e+002 5.71000000e+002 5.65000000e+002\n";
    s += "GELREF1  4.64000000e+002 3.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GBARM    2.00000000e+000 2.50000000e+002 3.20000000e+001 3.20000000e+001\n"
        "         1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GBEAMG   1.68500000e+003 0.00000000e+000 1.11500000e+004 1.00000000e-008\n"
        "         5.93000000e+008 1.57380000e+007 0.00000000e+000 1.00000000e-008\n"
        "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n"
        "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n";
    s += "GECCEN   1.37200000e+003 0.00000000e+000-2.48199365e+002-9.05288207e+000\n";
    s += "GELTH    6.54394000e+005 1.00000000e-001 0.00000000e+000 0.00000000e+000\n";
    s += "GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n"
        "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n"
        "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GUSYI    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n"
        "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n"
        "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GLSEC    1.90000000e+001 2.00000000e+002 1.00000000e+001 9.00000000e+001\n"
        "         1.40000000e+001 1.00000000e+000 1.00000000e+000 1.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GPIPE    6.54391000e+005 0.00000000e+000 3.12094257e-001 1.56047128e-001\n"
        "         1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "BLDEP    1.11140000e+004 2.30470000e+004 6.00000000e+000 9.00000000e+000\n"
        "         1.00000000e+000 1.00000000e+000 1.00000000e+000 0.00000000e+000\n"
        "         1.00000000e+000 6.00000000e+000 2.27000996e+004 0.00000000e+000\n"
        "         1.00000000e+000 5.00000000e+000 9.07859961e+003 0.00000000e+000\n"
        "         2.00000000e+000 2.00000000e+000 1.00000000e+000 0.00000000e+000\n"
        "         2.00000000e+000 4.00000000e+000-9.07859961e+003 0.00000000e+000\n"
        "         2.00000000e+000 6.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         3.00000000e+000 3.00000000e+000 1.00000000e+000 0.00000000e+000\n"
        "         3.00000000e+000 5.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         3.00000000e+000 4.00000000e+000-2.27000996e+004 0.00000000e+000\n";
    s += "BNBCD    2.30470000e+004 6.00000000e+000 1.00000000e+000 1.00000000e+000\n"
        "         1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000\n";
    s += "BELFIX   2.30470000e+004 1.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000\n"
        "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "BNDISPL  2.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         2.30460000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "BNLOAD   1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         1.52200000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         2.00000000e+006 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "MGSPRNG  6.90000000e+001 6.00000000e+000 1.00000000e+008 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GSETMEMB 5.00000000e+000 1.74000000e+002 1.00000000e+000 2.00000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GUNIVEC  5.17000000e+002 0.00000000e+000 0.00000000e+000-1.00000000e+000\n";
    s += "MISOSEL  6.60000000e+001 2.06000000e+008 3.00036000e-001 7.80000000e+000\n"
        "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "MORSMEL   8.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00\n"
        "          0.00000000E+00  1.07820425E+11  3.14079724E+10  1.41541114E+11\n"
        "          0.00000000E+00  0.00000000E+00  3.26140006E+10  2.21900001E-01\n"
        "          2.91298896E-01  2.99999993E-02  2.99999993E-02  1.20000004E-05\n"
        "          1.20000004E-05\n";
    s += "TDSETNAM 4.00000000e+000 1.66000000e+002 1.13000000e+002 0.00000000e+000\n"
        "        KEY_HOLE_ROOF\n";
    s += "TDSUPNAM 4.00000000e+000 1.66000000e+002 1.13000000e+002 0.00000000e+000\n"
        "        KEY_HOLE_ROOF\n";
    s += "GELMNT2   1.00000000E+00  1.00000000E+00  1.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n";
    s += "HSUPSTAT  9.00000000E+00  1.00000000E+00  2.32998000E+05  6.00000000E+00\n"
        "          2.30333000E+05  1.26810000E+05  0.00000000E+00  2.00000000E+00\n"
        "         -1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n";
    s += "HSUPTRAN  1.80000000E+01  2.00000000E+00  1.00000000E+00  0.00000000E+00\n"
        "          0.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00\n"
        "          0.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          0.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n";
    s += "HIERARCH  9.00000000E+00  1.00000000E+00  2.00000000E+00  1.00000000E+00\n"
        "          2.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00\n"
        "          2.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n";
    s += "TDLOAD    4.00000000E+00  1.00000000E+00  1.04000000E+02  0.00000000E+00\n"
        "        LC_1                                                            \n";
    s += "BSELL     1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  1.00000000E+00  2.00000000E+00 -1.00000000E+00\n";
    s += "BNBCD     3.88350000E+04  6.00000000E+00  4.00000000E+00  4.00000000E+00\n"
        "          4.00000000E+00  4.00000000E+00  4.00000000E+00  4.00000000E+00\n";
    s += "BEUSLO    1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n"
        "          1.00000000E+00  4.00000000E+00  0.00000000E+00  2.00000000E+00\n"
        "          1.66046816E+04  3.86669189E+03  3.86368091E+03  1.62054932E+04\n";
    s += "BNLOAD    1.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00\n"
        "          1.00000000e+00  3.00000000e+00  1.10000000e+00  1.20000000e+00\n"
        "          1.30000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00\n";
    s += "IEND     0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n";
    s += "GBOX      1.00000000E+00  1.00000000E-01  9.99999978E-03  9.99999978E-03\n"
        "          9.99999978E-03  1.00000000E-01  1.00000000E+00  1.00000000E+00\n";
    s += "GCHAN    1.16000000e+002 2.00000000e-001 8.50000000e-003 7.50000000e-002\n"
        "         1.15000000e-002 1.00000000e+000 1.00000000e+000 0.00000000e+000\n"
        "         1.00000000e+000 1.00000000e+000 1.00000000e+000 0.00000000e+000\n";
    s += "GCHANR  +1.300000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01\n"
        "        +2.500000000e-02+1.000000000e+00+1.000000000e+00\n"
        "        +1.000000000e+00+5.000000000e-03\n";
    s += "GDOBO   +1.400000000e+01+2.000000000e+00+4.000000000e-02+1.500000000e+00\n"
        "        +5.000000000e-02+6.000000000e-02+1.000000000e+00+1.000000000e+00\n";
    s += "GIORHR  +1.500000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01\n"
        "        +2.000000000e-02+1.800000000e-01+2.000000000e-02+1.000000000e+00\n"
        "        +1.000000000e+00+5.000000000e-03+6.000000000e-03\n";
    s += "GLSECR  +1.600000000e+01+2.000000000e-01+3.000000000e-02+1.500000000e-01\n"
        "        +2.000000000e-02+1.000000000e+00+1.000000000e+00+1.000000000e+00\n"
        "        +5.000000000e-03\n";
    s += "GTONP   +1.700000000e+01+2.000000000e-01+2.000000000e-02+1.200000000e-01\n"
        "        +3.000000000e-02+1.500000000e+00+4.000000000e-02+1.000000000e+00\n"
        "        +1.000000000e+00\n";

    istringstream ist(s);
    fem_file probe(ist);
    vector<string> l;
    vector<string> ref;
    vector<string> entries;

    size_t len;

    unique_ptr<cards::__base::card> current;

    __base::geoprop::reset_geono();

    SECTION("Checking dispatch [ident].") {
        len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::IDENT);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<ident*>(current.get())->SLEVEL == 1);
        REQUIRE(static_cast<ident*>(current.get())->SELTYP == 1);
        REQUIRE(static_cast<ident*>(current.get())->SELMOD == ident::mod_type::DIM_3D);
    }

    SECTION("Checking dispatch [text].") {
        for (int i = 0; i < 2; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::TEXT);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456|2
        // TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001
        //         CONVERSION DETAILS:
        //         Msc Nastran File Format -> Sesam Interface File.
        //         Input  : \test_01.bdt
        //         Log    : \test_01.txt
        REQUIRE(static_cast<text*>(current.get())->TYPE == 0);
        REQUIRE(static_cast<text*>(current.get())->SUBTYPE == 0);
        REQUIRE(static_cast<text*>(current.get())->NRECS == 4);
        REQUIRE(static_cast<text*>(current.get())->NBYTE == 72);
        REQUIRE(static_cast<text*>(current.get())->CONT == vector<string>(
                    //         1         2         3         4         5         6         7
                    // 23456789012345678901234567890123456789012345678901234567890123456789012
                    {"CONVERSION DETAILS:                                                     ",
                            "Msc Nastran File Format -> Sesam Interface File.                        ",
                            "Input  : \\test_01.fem                                                   ",
                            "Log    : \\test_01.txt                                                   "}));
    }

    SECTION("Checking dispatch [date].") {
        for (int i = 0; i < 3; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::DATE);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001
        //         DATE TIME:  11/03/2015 09:46:08
        //         PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013
        //         COMPUTER: HAML130185
        //         USER: berhol
        REQUIRE(static_cast<date*>(current.get())->TYPE == 0);
        REQUIRE(static_cast<date*>(current.get())->SUBTYPE == 0);
        REQUIRE(static_cast<date*>(current.get())->NRECS == 4);
        REQUIRE(static_cast<date*>(current.get())->NBYTE == 72);
        REQUIRE(static_cast<date*>(current.get())->CONT == vector<string>(
                    //         1         2         3         4         5         6         7
                    // 23456789012345678901234567890123456789012345678901234567890123456789012
                    {"DATE TIME:  11/03/2015 09:46:08                                         ",
                            "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013                    ",
                            "COMPUTER: HAML130185                                                    ",
                            "USER: berhol                                                            "}));
    }

    SECTION("Checking dispatch [tdload].") {
        for (int i = 0; i < 4; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        // REQUIRE(current->card_type() == cards::TDLOAD);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // TDLOAD   4.00000000e+000 1.00000000e+000 1.07000000e+002 0.00000000e+000
        //         SubCase
        REQUIRE(static_cast<tdsetnam*>(current.get())->NFIELD == 4);
        REQUIRE(static_cast<tdsetnam*>(current.get())->ISREF == 1);
        REQUIRE(static_cast<tdsetnam*>(current.get())->CODNAM == 107);
        REQUIRE(static_cast<tdsetnam*>(current.get())->CODTXT == 0);
        REQUIRE(static_cast<tdsetnam*>(current.get())->SET_NAME ==
                //        1         2         3         4         5         6         7
                //23456789012345678901234567890123456789012345678901234567890123456789012
                "SubCase");
        REQUIRE(static_cast<tdsetnam*>(current.get())->CONT == vector<string>());
    }

    SECTION("Checking dispatch [gnode].") {
        for (int i = 0; i < 5; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GNODE);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GNODE    1.00000000e+000 1.00000000e+000 6.00000000e+000 1.23456000e+005
        REQUIRE(static_cast<gnode*>(current.get())->NODEX == 1);
        REQUIRE(static_cast<gnode*>(current.get())->NODENO == 1);
        REQUIRE(static_cast<gnode*>(current.get())->NDOF == 6);
        REQUIRE(static_cast<gnode*>(current.get())->ODOF == vector<int>(
                    {1, 2, 3, 4, 5, 6}));
    }

    SECTION("Checking dispatch [gcoord].") {
        for (int i = 0; i < 6; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GCOORD);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GCOORD   1.00000000e+000 1.11525000e+005 1.80000000e+004 2.10000000e+004
        REQUIRE(static_cast<gcoord*>(current.get())->NODENO == 1);
        REQUIRE(static_cast<gcoord*>(current.get())->XCOORD == 111525.);
        REQUIRE(static_cast<gcoord*>(current.get())->YCOORD == 18000.);
        REQUIRE(static_cast<gcoord*>(current.get())->ZCOORD == 21000.);
    }

    SECTION("Checking dispatch [gelmnt1].") {
        for (int i = 0; i < 7; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GELMNT1);
        gelmnt1 *cur = static_cast<gelmnt1*>(current.get());
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GELMNT1  3.39000000e+002 8.54000000e+002 2.40000000e+001 0.00000000e+000
        //          6.08000000e+002 6.18000000e+002 5.71000000e+002 5.65000000e+002
        REQUIRE(static_cast<gelmnt1*>(current.get())->ELNOX == 339);
        REQUIRE(static_cast<gelmnt1*>(current.get())->ELNO == 854);
        REQUIRE(static_cast<gelmnt1*>(current.get())->ELTYP == elements::el_types::FQUS_FFQ);
        REQUIRE(static_cast<gelmnt1*>(current.get())->ELTYAD == 0);
        REQUIRE(static_cast<gelmnt1*>(current.get())->NODIN == vector<long>(
                    {608, 618, 571, 565}));
    }

    SECTION("Checking dispatch [gelref1].") {
        for (int i = 0; i < 8; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GELREF1);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GELREF1  4.64000000e+002 3.00000000e+000 0.00000000e+000 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gelref1*>(current.get())->ELNO == 464);
        REQUIRE(static_cast<gelref1*>(current.get())->MATNO == 3);
        REQUIRE(static_cast<gelref1*>(current.get())->ADDNO == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->INTNO == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->MINTNO == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->STRANO == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->STRENO == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->STREPONO == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->GEONO_OPT == 1);
        REQUIRE(static_cast<gelref1*>(current.get())->FIXNO_OPT == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->ECCNO_OPT == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->TRANSNO_OPT == 0);
        REQUIRE(static_cast<gelref1*>(current.get())->GEONO == vector<long>(0));
        REQUIRE(static_cast<gelref1*>(current.get())->FIXNO == vector<long>(0));
        REQUIRE(static_cast<gelref1*>(current.get())->ECCNO == vector<long>(0));
        REQUIRE(static_cast<gelref1*>(current.get())->TRANSNO == vector<long>(0));
    }

    SECTION("Checking dispatch [gbarm].") {
        for (int i = 0; i < 9; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GBARM);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GBARM    2.00000000e+000 2.50000000e+002 3.20000000e+001 3.20000000e+001
        //          1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gbarm*>(current.get())->GEONO == 2);
        REQUIRE(static_cast<gbarm*>(current.get())->HZ == 250.);
        REQUIRE(static_cast<gbarm*>(current.get())->BT == 32.);
        REQUIRE(static_cast<gbarm*>(current.get())->BB == 32.);
        REQUIRE(static_cast<gbarm*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<gbarm*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<gbarm*>(current.get())->NLOBY == 0);
        REQUIRE(static_cast<gbarm*>(current.get())->NLOBZ == 0);
    }

    SECTION("Checking dispatch [gbeamg].") {
        for (int i = 0; i < 10; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GBEAMG);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GBEAMG   1.68500000e+003 0.00000000e+000 1.11500000e+004 1.00000000e-008
        //          5.93000000e+008 1.57380000e+007 0.00000000e+000 1.00000000e-008
        //          1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008
        //          1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008
        REQUIRE(static_cast<gbeamg*>(current.get())->GEONO == 1685);
        REQUIRE(static_cast<gbeamg*>(current.get())->AREA == 1.115e4);
        REQUIRE(static_cast<gbeamg*>(current.get())->IX == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->IY == 5.93e8);
        REQUIRE(static_cast<gbeamg*>(current.get())->IZ == 1.5738e7);
        REQUIRE(static_cast<gbeamg*>(current.get())->IYZ == 0.);
        REQUIRE(static_cast<gbeamg*>(current.get())->WXMIN == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->WYMIN == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->WZMIN == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->SHARY == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->SHARZ == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->SHCENY == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->SHCENZ == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->SY == 1e-8);
        REQUIRE(static_cast<gbeamg*>(current.get())->SZ == 1e-8);
    }

    SECTION("Checking dispatch [geccen].") {
        for (int i = 0; i < 11; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GECCEN);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GECCEN   1.37200000e+003 0.00000000e+000-2.48199365e+002-9.05288207e+000
        REQUIRE(static_cast<geccen*>(current.get())->ECCNO == 1372);
        REQUIRE(static_cast<geccen*>(current.get())->EX == 0.);
        REQUIRE(static_cast<geccen*>(current.get())->EY == -2.48199365e+002);
        REQUIRE(static_cast<geccen*>(current.get())->EZ == -9.05288207);
    }

    SECTION("Checking dispatch [gelth].") {
        for (int i = 0; i < 12; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GELTH);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GELTH    6.54394000e+005 1.00000000e-001 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gelth*>(current.get())->GEONO == 654394);
        REQUIRE(static_cast<gelth*>(current.get())->TH == .1);
        REQUIRE(static_cast<gelth*>(current.get())->NINT == 0);
    }


    SECTION("Checking dispatch [giorh].") {
        for (int i = 0; i < 13; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GIORH);
        // GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002
        //          1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000
        //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<giorh*>(current.get())->GEONO == 5);
        REQUIRE(static_cast<giorh*>(current.get())->HZ == 466.);
        REQUIRE(static_cast<giorh*>(current.get())->TY == 14.5);
        REQUIRE(static_cast<giorh*>(current.get())->BT == 125);
        REQUIRE(static_cast<giorh*>(current.get())->TT == 16.);
        REQUIRE(static_cast<giorh*>(current.get())->BB == 14.5);
        REQUIRE(static_cast<giorh*>(current.get())->TB == 16.);
        REQUIRE(static_cast<giorh*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<giorh*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<giorh*>(current.get())->NLOBYT == 0);
        REQUIRE(static_cast<giorh*>(current.get())->NLOBYB == 0);
        REQUIRE(static_cast<giorh*>(current.get())->NLOBZ == 0);
    }

    SECTION("Checking dispatch [gusyi].") {
        for (int i = 0; i < 14; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GUSYI);
        // GUSYI    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002
        //          1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000
        //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gusyi*>(current.get())->GEONO == 5);
        REQUIRE(static_cast<gusyi*>(current.get())->HZ == 466.);
        REQUIRE(static_cast<gusyi*>(current.get())->TY == 14.5);
        REQUIRE(static_cast<gusyi*>(current.get())->BT == 125.);
        REQUIRE(static_cast<gusyi*>(current.get())->B1 == 16.);
        REQUIRE(static_cast<gusyi*>(current.get())->TT == 14.5);
        REQUIRE(static_cast<gusyi*>(current.get())->BB == 16.);
        REQUIRE(static_cast<gusyi*>(current.get())->B2 == 1);
        REQUIRE(static_cast<gusyi*>(current.get())->TB == 1.);
        REQUIRE(static_cast<gusyi*>(current.get())->SFY == 0.);
        REQUIRE(static_cast<gusyi*>(current.get())->SFZ == 0.);
        REQUIRE(static_cast<gusyi*>(current.get())->NLOBYT == 0);
        REQUIRE(static_cast<gusyi*>(current.get())->NLOBYB == 1);
        REQUIRE(static_cast<gusyi*>(current.get())->NLOBZ == 0);
    }

    SECTION("Checking dispatch [glsec].") {
        for (int i = 0; i < 15; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GLSEC);
        // GLSEC    1.90000000e+001 2.00000000e+002 1.00000000e+001 9.00000000e+001
        //          1.40000000e+001 1.00000000e+000 1.00000000e+000 1.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<glsec*>(current.get())->GEONO == 19);
        REQUIRE(static_cast<glsec*>(current.get())->HZ == 200.);
        REQUIRE(static_cast<glsec*>(current.get())->TY == 10);
        REQUIRE(static_cast<glsec*>(current.get())->BY == 90.);
        REQUIRE(static_cast<glsec*>(current.get())->TZ == 14.);
        REQUIRE(static_cast<glsec*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<glsec*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<glsec*>(current.get())->K);
        REQUIRE(static_cast<glsec*>(current.get())->NLOBY == 0);
        REQUIRE(static_cast<glsec*>(current.get())->NLOBZ == 0);
    }

    SECTION("Checking dispatch [gpipe].") {
        for (int i = 0; i < 16; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GPIPE);
        // GPIPE    6.54391000e+005 0.00000000e+000 3.12094257e-001 1.56047128e-001
        //          1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gpipe*>(current.get())->GEONO == 654391);
        REQUIRE(static_cast<gpipe*>(current.get())->DI == .0);
        REQUIRE(static_cast<gpipe*>(current.get())->DY == .312094257);
        REQUIRE(static_cast<gpipe*>(current.get())->T == .156047128);
        REQUIRE(static_cast<gpipe*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<gpipe*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<gpipe*>(current.get())->NCIR == 0);
        REQUIRE(static_cast<gpipe*>(current.get())->NRAD == 0);
    }

    SECTION("Checking dispatch [bldep].") {
        for (int i = 0; i < 17; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BLDEP);
        // BLDEP    1.11140000e+004 2.30470000e+004 6.00000000e+000 9.00000000e+000
        //          1.00000000e+000 1.00000000e+000 1.00000000e+000 0.00000000e+000
        //          1.00000000e+000 6.00000000e+000 2.27000996e+004 0.00000000e+000
        //          1.00000000e+000 5.00000000e+000 9.07859961e+003 0.00000000e+000
        //          2.00000000e+000 2.00000000e+000 1.00000000e+000 0.00000000e+000
        //          2.00000000e+000 4.00000000e+000-9.07859961e+003 0.00000000e+000
        //          2.00000000e+000 6.00000000e+000 0.00000000e+000 0.00000000e+000
        //          3.00000000e+000 3.00000000e+000 1.00000000e+000 0.00000000e+000
        //          3.00000000e+000 5.00000000e+000 0.00000000e+000 0.00000000e+000
        //          3.00000000e+000 4.00000000e+000-2.27000996e+004 0.00000000e+000
        REQUIRE(static_cast<bldep*>(current.get())->NODENO == 11114);
        REQUIRE(static_cast<bldep*>(current.get())->CNOD == 23047);
        REQUIRE(static_cast<bldep*>(current.get())->NDDOF == 6);
        REQUIRE(static_cast<bldep*>(current.get())->NDEP == 9);

        long c_ref_depdof[9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
        long c_ref_indepdof[9] = {1, 6, 5, 2, 4, 6, 3, 5, 4};
        double c_ref_b[9] = {1., 2.27000996e+4, 9.07859961e+3,
                             1., -9.07859961e+3, 0.,
                             1., 0., -2.27000996e+4};
        vector<long> ref_depdof(c_ref_depdof, c_ref_depdof + 9);
        vector<long> ref_indepdof(c_ref_indepdof, c_ref_indepdof + 9);
        vector<double> ref_b(c_ref_b, c_ref_b + 9);
        REQUIRE(static_cast<bldep*>(current.get())->DEPDOF == ref_depdof);
        REQUIRE(static_cast<bldep*>(current.get())->INDEPDOF == ref_indepdof);
        REQUIRE(static_cast<bldep*>(current.get())->b == ref_b);
    }

    SECTION("Checking dispatch [bnbcd].") {
        for (int i = 0; i < 18; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BNBCD);
        // BNBCD    2.30470000e+004 6.00000000e+000 1.00000000e+000 1.00000000e+000
        //          1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000
        REQUIRE(static_cast<bnbcd*>(current.get())->NODENO == 23047);
        REQUIRE(static_cast<bnbcd*>(current.get())->NDOF == 6);
        REQUIRE(static_cast<bnbcd*>(current.get())->FIX == vector<bnbcd::fix_key>(
                    6, bnbcd::fix_key::DISPL_FIX));
    }

    SECTION("Checking dispatch [belfix].") {
        for (int i = 0; i < 19; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BELFIX);
        // BELFIX   2.30470000e+004 1.00000000e+000 0.00000000e+000 0.00000000e+000
        //          1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000
        //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<belfix*>(current.get())->FIXNO == 23047);
        REQUIRE(static_cast<belfix*>(current.get())->OPT == belfix::n_opt::FIXATION);
        REQUIRE(static_cast<belfix*>(current.get())->TRANO == 0);
        REQUIRE(static_cast<belfix*>(current.get())->A == vector<double>(
                    {1., 1., 1., 1., 1., 0.}));
    }

    SECTION("Checking dispatch [bndispl].") {
        for (int i = 0; i < 20; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BNDISPL);
        // BNDISPL  2.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000
        //          2.30460000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<bndispl*>(current.get())->LLC == 2);
        REQUIRE(static_cast<bndispl*>(current.get())->DTYPE == 1);
        REQUIRE_FALSE(static_cast<bndispl*>(current.get())->COMPLX);
        REQUIRE(static_cast<bndispl*>(current.get())->NODENO == 23046);
        REQUIRE(static_cast<bndispl*>(current.get())->NDOF == 6);
        REQUIRE(static_cast<bndispl*>(current.get())->RDISP ==
                vector<double>({0., 0., 0., 0., 0., 0.}));
        REQUIRE(static_cast<bndispl*>(current.get())->IDISP ==
                vector<double>());
    }

    SECTION("Checking dispatch [bnload].") {
        for (int i = 0; i < 21; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BNLOAD);
        // BNLOAD   1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          1.52200000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000
        //          2.00000000e+006 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<bnload*>(current.get())->LLC == 1);
        REQUIRE(static_cast<bnload*>(current.get())->LOTYP == 0);
        REQUIRE_FALSE(static_cast<bnload*>(current.get())->COMPLX);
        REQUIRE(static_cast<bnload*>(current.get())->NODENO == 15220);
        REQUIRE(static_cast<bnload*>(current.get())->NDOF == 6);
        REQUIRE(static_cast<bnload*>(current.get())->RLOAD ==
                vector<double>({0., 0., 2.e6, 0., 0., 0.}));
        REQUIRE(static_cast<bnload*>(current.get())->ILOAD ==
                vector<double>(0));
    }

    SECTION("Checking dispatch [mgsprng].") {
        for (int i = 0; i < 22; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::MGSPRNG);
        // MGSPRNG  6.90000000e+001 6.00000000e+000 1.00000000e+008 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<mgsprng*>(current.get())->MATNO == 69);
        REQUIRE(static_cast<mgsprng*>(current.get())->NDOF == 6);
        double c_ref_k[6] = {0., 0., 0., 0., 0., 0.};
        vector<vector<double> > ref_K;
        for (int i = 0; i < 6; i++)
            ref_K.push_back(vector<double>(c_ref_k, c_ref_k + 6));
        ref_K[0][0] = 1e8;

        REQUIRE(static_cast<mgsprng*>(current.get())->K == ref_K);
    }

    SECTION("Checking dispatch [gsetmemb].") {
        for (int i = 0; i < 23; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GSETMEMB);
        // GSETMEMB 5.00000000e+000 1.74000000e+002 1.00000000e+000 2.00000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gsetmemb*>(current.get())->NFIELD == 5);
        REQUIRE(static_cast<gsetmemb*>(current.get())->ISREF == 174);
        REQUIRE(static_cast<gsetmemb*>(current.get())->INDEX == 1);
        REQUIRE(static_cast<gsetmemb*>(current.get())->ISTYPE == gsetmemb::types::ELEM_SET);
        REQUIRE(static_cast<gsetmemb*>(current.get())->ISORIG == gsetmemb::origins::UNDEF_ORIGIN);
        REQUIRE(static_cast<gsetmemb*>(current.get())->IRMEMB ==
                vector<long>(0));
    }

    SECTION("Checking dispatch [gunivec].") {
        for (int i = 0; i < 24; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GUNIVEC);
        // GUNIVEC  5.17000000e+002 0.00000000e+000 0.00000000e+000-1.00000000e+000
        REQUIRE(static_cast<gunivec*>(current.get())->TRANSNO == 517);
        REQUIRE(static_cast<gunivec*>(current.get())->UNIX == 0.);
        REQUIRE(static_cast<gunivec*>(current.get())->UNIY == 0.);
        REQUIRE(static_cast<gunivec*>(current.get())->UNIZ == -1.);
    }

    SECTION("Checking dispatch [misosel].") {
        for (int i = 0; i < 25; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::MISOSEL);
        // MISOSEL  6.60000000e+001 2.06000000e+008 3.00036000e-001 7.80000000e+000
        //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<misosel*>(current.get())->MATNO == 66);
        REQUIRE(static_cast<misosel*>(current.get())->YOUNG == 2.06e8);
        REQUIRE(static_cast<misosel*>(current.get())->POISS == 3.00036e-1);
        REQUIRE(static_cast<misosel*>(current.get())->RHO == 7.8);
        REQUIRE(static_cast<misosel*>(current.get())->DAMP == 0.);
        REQUIRE(static_cast<misosel*>(current.get())->ALPHA == 0.);
    }

    SECTION("Checking dispatch [morsmel].") {
        for (int i = 0; i < 26; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::MORSMEL);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // MORSMEL   8.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00
        //           0.00000000E+00  1.07820425E+11  3.14079724E+10  1.41541114E+11
        //           0.00000000E+00  0.00000000E+00  3.26140006E+10  2.21900001E-01
        //           2.91298896E-01  2.99999993E-02  2.99999993E-02  1.20000004E-05
        //           1.20000004E-05

        REQUIRE(static_cast<morsmel*>(current.get())->MATNO == 8);
        REQUIRE(static_cast<morsmel*>(current.get())->Q1 == 0.);
        REQUIRE(static_cast<morsmel*>(current.get())->Q2 == 0.);
        REQUIRE(static_cast<morsmel*>(current.get())->Q3 == 1.);
        REQUIRE(static_cast<morsmel*>(current.get())->RHO == 0.);
        REQUIRE(static_cast<morsmel*>(current.get())->D11 == 1.07820425e+11);
        REQUIRE(static_cast<morsmel*>(current.get())->D21 == 3.14079724e+10);
        REQUIRE(static_cast<morsmel*>(current.get())->D22 == 1.41541114e+11);
        REQUIRE(static_cast<morsmel*>(current.get())->D31 == 0.);
        REQUIRE(static_cast<morsmel*>(current.get())->D32 == 0.);
        REQUIRE(static_cast<morsmel*>(current.get())->D33 == 3.26140006e+10);
        REQUIRE(static_cast<morsmel*>(current.get())->PS1 == 2.21900001e-1);
        REQUIRE(static_cast<morsmel*>(current.get())->PS2 == 2.91298896e-1);
        REQUIRE(static_cast<morsmel*>(current.get())->DAMP1 == 2.99999993e-2);
        REQUIRE(static_cast<morsmel*>(current.get())->DAMP2 == 2.99999993e-2);
        REQUIRE(static_cast<morsmel*>(current.get())->ALPHA1 == 1.20000004e-5);
        REQUIRE(static_cast<morsmel*>(current.get())->ALPHA2 == 1.20000004e-5);
    }

    SECTION("Checking dispatch [tdsetnam].") {
        for (int i = 0; i < 27; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::TDSETNAM);
        // TDSETNAM 4.00000000e+000 1.66000000e+002 1.13000000e+002 0.00000000e+000
        //         KEY_HOLE_ROOF
        REQUIRE(static_cast<tdsetnam*>(current.get())->NFIELD == 4);
        REQUIRE(static_cast<tdsetnam*>(current.get())->ISREF == 166);
        REQUIRE(static_cast<tdsetnam*>(current.get())->CODNAM == 113);
        REQUIRE(static_cast<tdsetnam*>(current.get())->CODTXT == 0);
        REQUIRE(static_cast<tdsetnam*>(current.get())->SET_NAME ==
                "KEY_HOLE_ROOF");
        REQUIRE(static_cast<tdsetnam*>(current.get())->CONT ==
                vector<string>(0));
    }

    SECTION("Checking dispatch [tdsupnam].") {
        for (int i = 0; i < 28; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::TDSUPNAM);
        // TDSUPNAM 4.00000000e+000 1.66000000e+002 1.13000000e+002 0.00000000e+000
        //         KEY_HOLE_ROOF
        REQUIRE(static_cast<tdsupnam*>(current.get())->NFIELD == 4);
        REQUIRE(static_cast<tdsupnam*>(current.get())->IHREF == 166);
        REQUIRE(static_cast<tdsupnam*>(current.get())->CODNAM == 113);
        REQUIRE(static_cast<tdsupnam*>(current.get())->CODTXT == 0);
        REQUIRE(static_cast<tdsupnam*>(current.get())->SUP_NAME ==
                "KEY_HOLE_ROOF");
        REQUIRE(static_cast<tdsupnam*>(current.get())->CONT ==
                vector<string>(0));
    }

    SECTION("Checking dispatch [gelmnt2].") {
        for (int i = 0; i < 29; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GELMNT2);
        // GELMNT2   1.000000000e+00 1.000000000e+00 1.000000000e+00 0.00000000E+00
        //           1.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        //           1.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        //           1.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        //           1.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00
        REQUIRE(static_cast<gelmnt2*>(current.get())->SUBNO == 1);
        REQUIRE(static_cast<gelmnt2*>(current.get())->SLEVEL == 1);
        REQUIRE(static_cast<gelmnt2*>(current.get())->STYPE == 1);
        REQUIRE(static_cast<gelmnt2*>(current.get())->ADDNO == 0);
        REQUIRE(vector<double>(static_cast<gelmnt2*>(current.get())->T[0],
                               static_cast<gelmnt2*>(current.get())->T[0] + 4) ==
                vector<double>({1., 0., 0., 0.}));
        REQUIRE(vector<double>(static_cast<gelmnt2*>(current.get())->T[1],
                               static_cast<gelmnt2*>(current.get())->T[1] + 4) ==
                vector<double>({0., 1., 0., 0.}));
        REQUIRE(vector<double>(static_cast<gelmnt2*>(current.get())->T[2],
                               static_cast<gelmnt2*>(current.get())->T[2] + 4) ==
                vector<double>({0., 0., 1., 0.}));
        REQUIRE(vector<double>(static_cast<gelmnt2*>(current.get())->T[3],
                               static_cast<gelmnt2*>(current.get())->T[3] + 4) ==
                vector<double>({0., 0., 0., 1.}));
        REQUIRE(static_cast<gelmnt2*>(current.get())->NNOD == 1);
        REQUIRE(static_cast<gelmnt2*>(current.get())->NOD ==
                vector<long>(1, 1));
        current.reset();
    }

    SECTION("Checking dispatch [hsupstat].") {
        for (int i = 0; i < 30; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::HSUPSTAT);
        // HSUPSTAT  9.000000000e+00 1.000000000e+00 2.32998000E+05  6.00000000E+00
        //           2.30333000E+05  1.26810000E+05  0.000000000e+00 2.00000000E+00
        //          -1.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        REQUIRE(static_cast<hsupstat*>(current.get())->NFIELD == 9);
        REQUIRE(static_cast<hsupstat*>(current.get())->ISELTY == 1);
        REQUIRE(static_cast<hsupstat*>(current.get())->NIDOF == 232998);
        REQUIRE(static_cast<hsupstat*>(current.get())->NRDOF == 6);
        REQUIRE(static_cast<hsupstat*>(current.get())->NBAND == 230333);
        REQUIRE(static_cast<hsupstat*>(current.get())->NELT == 126810);
        REQUIRE(static_cast<hsupstat*>(current.get())->LINDEP == 0);
        REQUIRE(static_cast<hsupstat*>(current.get())->RELOADC == 2);
        REQUIRE(static_cast<hsupstat*>(current.get())->COMPLC == -1);
        current.reset();
    }

    SECTION("Checking dispatch [hsuptran].") {
        for (int i = 0; i < 31; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::HSUPTRAN);
        // HSUPTRAN  1.800000000e+01 2.000000000e+00 1.000000000e+00 0.00000000E+00
        //           0.000000000e+00 0.000000000e+00 0.000000000e+00 1.00000000E+00
        //           0.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        //           1.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        //           0.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00
        REQUIRE(static_cast<hsuptran*>(current.get())->NFIELD == 18);
        REQUIRE(static_cast<hsuptran*>(current.get())->ITREF == 2);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[0][0] == 1.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[0][1] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[0][2] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[0][3] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[1][0] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[1][1] == 1.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[1][2] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[1][3] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[2][0] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[2][1] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[2][2] == 1.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[2][3] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[3][0] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[3][1] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[3][2] == 0.);
        REQUIRE(static_cast<hsuptran*>(current.get())->T[3][3] == 1.);
        current.reset();
    }

    SECTION("Checking dispatch [hierarch].") {
        for (int i = 0; i < 32; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::HIERARCH);
        // HIERARCH  9.000000000e+00 1.000000000e+00 2.000000000e+00 1.00000000E+00
        //           2.000000000e+00 0.000000000e+00 0.000000000e+00 1.00000000E+00
        //           2.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000E+00
        REQUIRE(static_cast<hierarch*>(current.get())->NFIELD == 9);
        REQUIRE(static_cast<hierarch*>(current.get())->IHREF == 1);
        REQUIRE(static_cast<hierarch*>(current.get())->ISELTY == 2);
        REQUIRE(static_cast<hierarch*>(current.get())->INDSEL == 1);
        REQUIRE(static_cast<hierarch*>(current.get())->ISLEVL == 2);
        REQUIRE(static_cast<hierarch*>(current.get())->ITREF == 0);
        REQUIRE(static_cast<hierarch*>(current.get())->IHPREF == 0);
        REQUIRE(static_cast<hierarch*>(current.get())->NSUB == 1);
        REQUIRE(static_cast<hierarch*>(current.get())->IHSREFi ==
                vector<long>(1, 2));
        current.reset();
    }

    SECTION("Checking dispatch [tdload].") {
        for (int i = 0; i < 33; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::TDLOAD);
        // TDLOAD    4.000000000e+00 1.000000000e+00 1.04000000E+02  0.00000000E+00
        //         LC_1
        REQUIRE(static_cast<tdload*>(current.get())->NFIELD == 4);
        REQUIRE(static_cast<tdload*>(current.get())->ILREF == 1);
        REQUIRE(static_cast<tdload*>(current.get())->CODNAM == 104);
        REQUIRE(static_cast<tdload*>(current.get())->CODTXT == 0);
        REQUIRE(static_cast<tdload*>(current.get())->SET_NAME == "LC_1");
        REQUIRE(static_cast<tdload*>(current.get())->CONT ==
                vector<string>(0));
        current.reset();
    }

    SECTION("Checking dispatch [bsell].") {
        for (int i = 0; i < 34; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BSELL);
        // BSELL     1.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00
        //           1.000000000e+00 1.000000000e+00 2.000000000e+00-1.00000000E+00
        REQUIRE(static_cast<bsell*>(current.get())->LC == 1);
        REQUIRE(static_cast<bsell*>(current.get())->SUBNO == 1);
        REQUIRE(static_cast<bsell*>(current.get())->LLC ==
                vector<long>({1, 2}));
        REQUIRE(static_cast<bsell*>(current.get())->FACT ==
                vector<double>({1., -1.}));
        current.reset();
    }

    SECTION("Checking dispatch [bnbcd].") {
        for (int i = 0; i < 35; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BNBCD);
        // BNBCD     3.88350000E+04  6.000000000e+00 4.000000000e+00 4.00000000E+00
        //           4.000000000e+00 4.000000000e+00 4.000000000e+00 4.00000000E+00
        REQUIRE(static_cast<bnbcd*>(current.get())->NODENO == 38835);
        REQUIRE(static_cast<bnbcd*>(current.get())->NDOF == 6);
        REQUIRE(static_cast<bnbcd*>(current.get())->FIX ==
                vector<bnbcd::fix_key>(6, bnbcd::fix_key::RETAINED));
    }

    SECTION("Checking dispatch [beuslo].") {
        for (int i = 0; i < 36; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BEUSLO);
        // BEUSLO    1.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00
        //           1.000000000e+00 4.000000000e+00 0.000000000e+00 2.00000000E+00
        //           1.66046816E+04  3.86669189E+03  3.86368091E+03  1.62054932E+04
        REQUIRE(static_cast<beuslo*>(current.get())->LLC == 1);
        REQUIRE(static_cast<beuslo*>(current.get())->LOTYP == 1);
        REQUIRE(static_cast<beuslo*>(current.get())->COMPLX == false);
        REQUIRE(static_cast<beuslo*>(current.get())->LAYER == 0);
        REQUIRE(static_cast<beuslo*>(current.get())->ELNO == 1);
        REQUIRE(static_cast<beuslo*>(current.get())->NDOF == 4);
        REQUIRE(static_cast<beuslo*>(current.get())->INTNO == 0);
        REQUIRE(static_cast<beuslo*>(current.get())->SIDE == 2);
        REQUIRE(static_cast<beuslo*>(current.get())->RLOADi ==
                vector<double>({1.66046816e4, 3.86669189e3,
                            3.86368091e3, 1.62054932e4}));
        REQUIRE(static_cast<beuslo*>(current.get())->ILOADi ==
                vector<double>(0));
        current.reset();
    }

    SECTION("Checking dispatch [bnload].") {
        for (int i = 0; i < 37; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::BNLOAD);
        // BNLOAD    1.000000000e+00 0.000000000e+00 0.000000000e+00 0.00000000e+00
        //           1.000000000e+00 3.000000000e+00 1.100000000e+00 1.20000000e+00
        //           1.300000000e+00 0.000000000e+00 0.000000000e+00 0.00000000e+00
        REQUIRE(static_cast<bnload*>(current.get())->LLC == 1);
        REQUIRE(static_cast<bnload*>(current.get())->LOTYP == 0);
        REQUIRE_FALSE(static_cast<bnload*>(current.get())->COMPLX);
        REQUIRE(static_cast<bnload*>(current.get())->NODENO == 1);
        REQUIRE(static_cast<bnload*>(current.get())->NDOF == 3);
        REQUIRE(static_cast<bnload*>(current.get())->RLOAD ==
                vector<double>({1.1, 1.2, 1.3}));
        REQUIRE(static_cast<bnload*>(current.get())->ILOAD ==
                vector<double>(0));
        current.reset();
    }

    SECTION("Checking dispatch [iend].") {
        for (int i = 0; i < 38; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::IEND);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // IEND     0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<iend*>(current.get())->CONT == 0);
        current.reset();
    }

    SECTION("Checking dispatch [gbox].") {
        for (int i = 0; i < 39; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GBOX);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GBOX      1.00000000E+00  1.00000000E-01  9.99999978E-03  9.99999978E-03
        //           9.99999978E-03  1.00000000E-01  1.00000000E+00  1.00000000E+00
        REQUIRE(static_cast<gbox*>(current.get())->GEONO == 1);
        REQUIRE(static_cast<gbox*>(current.get())->HZ == .1);
        REQUIRE(static_cast<gbox*>(current.get())->TY == 9.99999978E-3);
        REQUIRE(static_cast<gbox*>(current.get())->TB == 9.99999978E-3);
        REQUIRE(static_cast<gbox*>(current.get())->TT == 9.99999978E-3);
        REQUIRE(static_cast<gbox*>(current.get())->BY == .1);
        REQUIRE(static_cast<gbox*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<gbox*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<gbox*>(current.get())->NLOBY == 0.);
        REQUIRE(static_cast<gbox*>(current.get())->NLOBZ == 0.);
        current.reset();
    }

    SECTION("Checking dispatch [gchan].") {
        for (int i = 0; i < 40; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GCHAN);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GCHAN    1.16000000e+002 2.00000000e-001 8.50000000e-003 7.50000000e-002
        //          1.15000000e-002 1.00000000e+000 1.00000000e+000 0.00000000e+000
        //          1.00000000e+000 1.00000000e+000 1.00000000e+000 0.00000000e+000
        REQUIRE(static_cast<gchan*>(current.get())->GEONO == 116);
        REQUIRE(static_cast<gchan*>(current.get())->HZ == .2);
        REQUIRE(static_cast<gchan*>(current.get())->TY == .0085);
        REQUIRE(static_cast<gchan*>(current.get())->BY == .075);
        REQUIRE(static_cast<gchan*>(current.get())->TZ == .0115);
        REQUIRE(static_cast<gchan*>(current.get())->SFY == 1);
        REQUIRE(static_cast<gchan*>(current.get())->SFZ == 1);
        REQUIRE(static_cast<gchan*>(current.get())->K == 1);
        REQUIRE(static_cast<gchan*>(current.get())->NLOBY == 1);
        REQUIRE(static_cast<gchan*>(current.get())->NLOBZ == 1);
        current.reset();
    }

    SECTION("Checking dispatch [gchanr].") {
        for (int i = 0; i < 41; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GCHANR);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GCHANR  +1.300000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01
        //         +2.500000000e-02+1.000000000e+00+1.000000000e+00
        //         +1.000000000e+00+5.000000000e-03
        REQUIRE(static_cast<gchanr*>(current.get())->GEONO == 13);
        REQUIRE(static_cast<gchanr*>(current.get())->HZ == .2);
        REQUIRE(static_cast<gchanr*>(current.get())->TY == .02);
        REQUIRE(static_cast<gchanr*>(current.get())->BY == .15);
        REQUIRE(static_cast<gchanr*>(current.get())->TZ == .025);
        REQUIRE(static_cast<gchanr*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<gchanr*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<gchanr*>(current.get())->K == 1);
        REQUIRE(static_cast<gchanr*>(current.get())->R == .005);
        REQUIRE(static_cast<gchanr*>(current.get())->NLOBY == 0.);
        REQUIRE(static_cast<gchanr*>(current.get())->NLOBZ == 0.);
        current.reset();
    }

    SECTION("Checking dispatch [gdobo].") {
        for (int i = 0; i < 42; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GDOBO);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GDOBO   +1.400000000e+01+2.000000000e+00+4.000000000e-02+1.500000000e+00
        //         +5.000000000e-02+6.000000000e-02+1.000000000e+00+1.000000000e+00
        REQUIRE(static_cast<gdobo*>(current.get())->GEONO == 14);
        REQUIRE(static_cast<gdobo*>(current.get())->HZ == 2);
        REQUIRE(static_cast<gdobo*>(current.get())->TY == .04);
        REQUIRE(static_cast<gdobo*>(current.get())->BY == 1.5);
        REQUIRE(static_cast<gdobo*>(current.get())->TT == .05);
        REQUIRE(static_cast<gdobo*>(current.get())->TB == .06);
        REQUIRE(static_cast<gdobo*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<gdobo*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<gdobo*>(current.get())->NLOBY == 0);
        REQUIRE(static_cast<gdobo*>(current.get())->NLOBZ == 0);
        current.reset();
    }

    SECTION("Checking dispatch [giorhr].") {
        for (int i = 0; i < 43; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GIORHR);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GIORHR  +1.500000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01
        //         +2.000000000e-02+1.800000000e-01+2.000000000e-02+1.000000000e+00
        //         +1.000000000e+00+5.000000000e-03+6.000000000e-03
        REQUIRE(static_cast<giorhr*>(current.get())->GEONO == 15);
        REQUIRE(static_cast<giorhr*>(current.get())->HZ == .2);
        REQUIRE(static_cast<giorhr*>(current.get())->TY == .02);
        REQUIRE(static_cast<giorhr*>(current.get())->BT == .15);
        REQUIRE(static_cast<giorhr*>(current.get())->TT == .02);
        REQUIRE(static_cast<giorhr*>(current.get())->BB == .18);
        REQUIRE(static_cast<giorhr*>(current.get())->TB == .02);
        REQUIRE(static_cast<giorhr*>(current.get())->SFY == 1);
        REQUIRE(static_cast<giorhr*>(current.get())->SFZ == 1);
        REQUIRE(static_cast<giorhr*>(current.get())->RT == .005);
        REQUIRE(static_cast<giorhr*>(current.get())->RB == .006);
        REQUIRE(static_cast<giorhr*>(current.get())->NLOBYT == 0);
        REQUIRE(static_cast<giorhr*>(current.get())->NLOBYB == 0);
        REQUIRE(static_cast<giorhr*>(current.get())->NLOBZ == 0);
        current.reset();
    }

    SECTION("Checking dispatch [glsecr].") {
        for (int i = 0; i < 44; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GLSECR);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GLSECR  +1.600000000e+01+2.000000000e-01+3.000000000e-02+1.500000000e-01
        //         +2.000000000e-02+1.000000000e+00+1.000000000e+00+1.000000000e+00
        //         +5.000000000e-03
        REQUIRE(static_cast<glsecr*>(current.get())->GEONO == 16);
        REQUIRE(static_cast<glsecr*>(current.get())->HZ == .2);
        REQUIRE(static_cast<glsecr*>(current.get())->TY == .03);
        REQUIRE(static_cast<glsecr*>(current.get())->BY == .15);
        REQUIRE(static_cast<glsecr*>(current.get())->TZ == .02);
        REQUIRE(static_cast<glsecr*>(current.get())->SFY == 1);
        REQUIRE(static_cast<glsecr*>(current.get())->SFZ == 1);
        REQUIRE(static_cast<glsecr*>(current.get())->K == 1);
        REQUIRE(static_cast<glsecr*>(current.get())->R == .005);
        REQUIRE(static_cast<glsecr*>(current.get())->NLOBY == 0);
        REQUIRE(static_cast<glsecr*>(current.get())->NLOBZ == 0);
        current.reset();
    }

    SECTION("Checking dispatch [gtonp].") {
        for (int i = 0; i < 45; i++) len = probe.get(l);
        string msg;
        for (size_t i=0; i < len; i++) msg += l.at(i) + "\n";
        CAPTURE(msg);
        len = __base::card::card_split(l, len, entries);
        cards::dispatch(entries, len, current);
        REQUIRE(current->card_type() == cards::types::GTONP);
        // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
        // GTONP   +1.700000000e+01+2.000000000e-01+2.000000000e-02+1.200000000e-01
        //         +3.000000000e-02+1.500000000e+00+4.000000000e-02+1.000000000e+00
        //         +1.000000000e+00
        REQUIRE(static_cast<gtonp*>(current.get())->GEONO == 17);
        REQUIRE(static_cast<gtonp*>(current.get())->HZ == .2);
        REQUIRE(static_cast<gtonp*>(current.get())->TY == .02);
        REQUIRE(static_cast<gtonp*>(current.get())->BT == .12);
        REQUIRE(static_cast<gtonp*>(current.get())->TT == .03);
        REQUIRE(static_cast<gtonp*>(current.get())->BP == 1.5);
        REQUIRE(static_cast<gtonp*>(current.get())->TP == .04);
        REQUIRE(static_cast<gtonp*>(current.get())->SFY == 1.);
        REQUIRE(static_cast<gtonp*>(current.get())->SFZ == 1.);
        REQUIRE(static_cast<gtonp*>(current.get())->NLOBYT == 0);
        REQUIRE(static_cast<gtonp*>(current.get())->NLOBYB == 0);
        REQUIRE(static_cast<gtonp*>(current.get())->NLOBZ == 0);
        current.reset();
    }

    SECTION("Testing writing.") {

        list<unique_ptr<__base::card>> cards;
        ostringstream test;

        cards.push_back(make_unique<ident>(
                            1, 1, ident::mod_type::DIM_3D));
        cards.push_back(
            make_unique<text>(
                0, 0,
                vector<string>(
                    {"CONVERSION DETAILS:",
                            "Msc Nastran File Format -> Sesam Interface File.",
                            "Input  : \\test_01.fem",
                            "Log    : \\test_01.txt"})));
        cards.push_back(
            make_unique<date>(
                0, 0,
                vector<string>(
                    {"DATE TIME:  11/03/2015 09:46:08",
                            "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013",
                            "COMPUTER: HAML130185",
                            "USER: berhol"})));
        cards.push_back(make_unique<tdload>(
                            1, "SubCase"));
        cards.push_back(make_unique<gnode>(
                            1, 1, 6, vector<int>({1, 2, 3, 4, 5, 6})));
        cards.push_back(make_unique<gcoord>(
                            1, 11152.5, 1800., 2100.));
        cards.push_back(make_unique<gelmnt1>(
                            339, 854, elements::el_types::FQUS_FFQ,
                            vector<long>({608, 618, 571, 565})));
        cards.push_back(make_unique<gelref1>(
                            464, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                            vector<long>(0), vector<long>(0),
                            vector<long>(0), vector<long>(0)));
        cards.push_back(make_unique<gbarm>(
                            2, 250., 32., 32., 1., 1.));
        cards.push_back(make_unique<gbeamg>(
                            1685, 1.115e4, 1e-8, 5.93e8, 1.5738e7, 0.,
                            1e-8, 1e-8, 1e-8, 1e-8, 1e-8, 1e-8, 1e-8,
                            1e-8, 1e-8));
        cards.push_back(make_unique<geccen>(
                            1372, 0., -248.199365, -9.05288207));
        cards.push_back(make_unique<gelth>(
                            654394, .1, 0));
        cards.push_back(make_unique<giorh>(
                            5, 466., 14.5, 125, 16., 14.5, 16., 1., 1.,
                            0, 0, 0));
        cards.push_back(make_unique<gusyi>(
                            6, 466., 14.5, 125., 16., 14.5, 16., 1, 1.,
                            0., 0., 0, 1, 0));
        cards.push_back(make_unique<glsec>(
                            19, 200., 10, 90., 14., 1., 1., true, 0, 0));
        cards.push_back(make_unique<gpipe>(
                            654391, .0, .312094257, .156047128, 1., 1.,
                            0, 0));
        cards.push_back(
            make_unique<bldep>(
                11114, 23047, 6,
                vector<long>({1, 1, 1, 2, 2, 2, 3, 3, 3}),
                vector<long>({1, 6, 5, 2, 4, 6, 3, 5, 4}),
                vector<double>({1., 2.27000996e+4, 9.07859961e+3,
                            1., -9.07859961e+3, 0.,
                            1., 0., -2.27000996e+4})));
        cards.push_back(
            make_unique<bnbcd>(
                23047, vector<bnbcd::fix_key>(6, bnbcd::fix_key::DISPL_FIX)));
        cards.push_back(make_unique<belfix>(
                            23047, belfix::n_opt::FIXATION, 0,
                            vector<double>({1., 1., 1., 1., 1., 0.})));
        cards.push_back(make_unique<bndispl>(
                            2, 1, 23046,
                            vector<double>({0., 0., 0., 0., 0., 0.})));
        cards.push_back(make_unique<bnload>(
                            1, 0, (long)15220,
                            vector<double>({0., 0., 2.e6, 0., 0., 0.})));
        cards.push_back(
            make_unique<mgsprng>(
                69,
                vector<vector<double> >(
                    {vector<double>{1e8, 0., 0., 0., 0., 0.},
                            vector<double>{0., 0., 0., 0., 0., 0.},
                                vector<double>{0., 0., 0., 0., 0., 0.},
                                    vector<double>{0., 0., 0., 0., 0., 0.},
                                        vector<double>{0., 0., 0., 0., 0., 0.},
                                            vector<double>{0., 0., 0., 0., 0., 0.}})));
        cards.push_back(make_unique<gsetmemb>(
                            5, 174, 1, gsetmemb::types::ELEM_SET, gsetmemb::origins::UNDEF_ORIGIN));
        cards.push_back(make_unique<gunivec>(
                            517, 0., 0., -1.));
        cards.push_back(make_unique<misosel>(
                            66, 2.06e8, 3.00036e-1, 7.8, 0., 0.));
        cards.push_back(make_unique<morsmel>(
                            8, 0., 0., 1., 0., 1.07820425e+11,
                            3.14079724e+10, 1.41541114e+11, 0., 0.,
                            3.26140006e+10, 2.21900001e-1, 2.91298896e-1,
                            2.99999993e-2, 2.99999993e-2, 1.20000004e-5,
                            1.20000004e-5));
        cards.push_back(make_unique<tdsetnam>(
                            166, "KEY_HOLE_ROOF"));
        cards.push_back(make_unique<gelmnt2>(
                            1, 1, 1, 0, 1., 0., 0., 0., 1., 0., 0., 0., 1., 0., 0., 0.,
                            vector<long>(1, 1)));
        cards.push_back(make_unique<hsupstat>(
                            9, 1, 232998, 6, 230333, 126810, 0, 2, -1));
        cards.push_back(make_unique<hsuptran>(
                            18, 2, 1., 0., 0., 0., 0., 1., 0., 0., 0., 0.,
                            1., 0., 0., 0., 0., 1.));
        cards.push_back(make_unique<hierarch>(
                            9, 1, 2, 1, 2, 0, 0, 1,
                            vector<long>(1, 2)));
        cards.push_back(make_unique<tdload>(1, "LC_1"));
        cards.push_back(make_unique<bsell>(
                            1, 1, vector<long>({1, 2}),
                            vector<double>({1., -1.})));
        cards.push_back(
            make_unique<bnbcd>(
                38835, vector<bnbcd::fix_key>(6, bnbcd::fix_key::RETAINED)));
        cards.push_back(
            make_unique<beuslo>(
                1, 1, 0, 1, 0, 2,
                vector<double>(
                    {1.66046816e4, 3.86669189e3, 3.86368091e3, 1.62054932e4})));
        cards.push_back(make_unique<bnload>(
                            1, 0, 1, vector<double>({1.1, 1.2, 1.3})));
        cards.push_back(make_unique<tdsupnam>(
                            166, "KEY_HOLE_ROOF"));
        cards.push_back(make_unique<iend>(0));
        cards.push_back(make_unique<gbox>(11, .2, .1, .03, .03, .03, 1., 1., 0));
        cards.push_back(make_unique<gchan>(12, .2, .02, .15, .025, 1., 1., 1));
        cards.push_back(make_unique<gchanr>(13, .2, .02, .15, .025, 1., 1., 1, .005));
        cards.push_back(make_unique<gdobo>(14, 2., .04, 1.5, .05, .06, 1., 1.));
        cards.push_back(make_unique<giorhr>(15, .2, .02, .15, .02, .18, .02, 1., 1., .005, .006));
        cards.push_back(make_unique<glsecr>(16, .2, .03, .15, .02, 1., 1., 1, .005));
        cards.push_back(make_unique<gtonp>(17, .2, .02, .12, .03, 1.5, .04, 1., 1.));

        for (auto const &card : cards)
            test << *card;

        cards.clear();

        REQUIRE("IDENT   +1.000000000e+00+1.000000000e+00+3.000000000e+00\n"
                "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n"
                "        CONVERSION DETAILS:                             \n"
                "        Msc Nastran File Format -> Sesam Interface File.\n"
                "        Input  : \\test_01.fem                           \n"
                "        Log    : \\test_01.txt                           \n"
                "DATE    +0.000000000e+00+0.000000000e+00+4.000000000e+00+6.000000000e+01\n"
                "        DATE TIME:  11/03/2015 09:46:08                     \n"
                "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013\n"
                "        COMPUTER: HAML130185                                \n"
                "        USER: berhol                                        \n"
                "TDLOAD  +4.000000000e+00+1.000000000e+00+1.070000000e+02+0.000000000e+00\n"
                "        SubCase\n"
                "GNODE   +1.000000000e+00+1.000000000e+00+6.000000000e+00 1.234560000e+05\n"
                "GCOORD  +1.000000000e+00+1.115250000e+04+1.800000000e+03+2.100000000e+03\n"
                "GELMNT1 +3.390000000e+02+8.540000000e+02+2.400000000e+01+0.000000000e+00\n"
                "        +6.080000000e+02+6.180000000e+02+5.710000000e+02+5.650000000e+02\n"
                "GELREF1 +4.640000000e+02+3.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "GBARM   +2.000000000e+00+2.500000000e+02+3.200000000e+01+3.200000000e+01\n"
                "        +1.000000000e+00+1.000000000e+00\n"
                "GBEAMG  +1.685000000e+03            0.00+1.115000000e+04+1.000000000e-08\n"
                "        +5.930000000e+08+1.573800000e+07+0.000000000e+00+1.000000000e-08\n"
                "        +1.000000000e-08+1.000000000e-08+1.000000000e-08+1.000000000e-08\n"
                "        +1.000000000e-08+1.000000000e-08+1.000000000e-08+1.000000000e-08\n"
                "GECCEN  +1.372000000e+03+0.000000000e+00-2.481993650e+02-9.052882070e+00\n"
                "GELTH   +6.543940000e+05+1.000000000e-01\n"
                "GIORH   +5.000000000e+00+4.660000000e+02+1.450000000e+01+1.250000000e+02\n"
                "        +1.600000000e+01+1.450000000e+01+1.600000000e+01+1.000000000e+00\n"
                "        +1.000000000e+00\n"
                "GUSYI   +6.000000000e+00+4.660000000e+02+1.450000000e+01+1.250000000e+02\n"
                "        +1.600000000e+01+1.450000000e+01+1.600000000e+01+1.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00\n"
                "GLSEC   +1.900000000e+01+2.000000000e+02+1.000000000e+01+9.000000000e+01\n"
                "        +1.400000000e+01+1.000000000e+00+1.000000000e+00           +1.00\n"
                "GPIPE   +6.543910000e+05+0.000000000e+00+3.120942570e-01+1.560471280e-01\n"
                "        +1.000000000e+00+1.000000000e+00\n"
                "BLDEP   +1.111400000e+04+2.304700000e+04+6.000000000e+00+9.000000000e+00\n"
                "        +1.000000000e+00+1.000000000e+00+1.000000000e+00            0.00\n"
                "        +1.000000000e+00+6.000000000e+00+2.270009960e+04            0.00\n"
                "        +1.000000000e+00+5.000000000e+00+9.078599610e+03            0.00\n"
                "        +2.000000000e+00+2.000000000e+00+1.000000000e+00            0.00\n"
                "        +2.000000000e+00+4.000000000e+00-9.078599610e+03            0.00\n"
                "        +2.000000000e+00+6.000000000e+00+0.000000000e+00            0.00\n"
                "        +3.000000000e+00+3.000000000e+00+1.000000000e+00            0.00\n"
                "        +3.000000000e+00+5.000000000e+00+0.000000000e+00            0.00\n"
                "        +3.000000000e+00+4.000000000e+00-2.270009960e+04            0.00\n"
                "BNBCD   +2.304700000e+04+6.000000000e+00+1.000000000e+00+1.000000000e+00\n"
                "        +1.000000000e+00+1.000000000e+00+1.000000000e+00+1.000000000e+00\n"
                "BELFIX  +2.304700000e+04+1.000000000e+00+0.000000000e+00            0.00\n"
                "        +1.000000000e+00+1.000000000e+00+1.000000000e+00+1.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00\n"
                "BNDISPL +2.000000000e+00+1.000000000e+00           +0.00            0.00\n"
                "        +2.304600000e+04+6.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "BNLOAD  +1.000000000e+00+0.000000000e+00           +0.00            0.00\n"
                "        +1.522000000e+04+6.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +2.000000000e+06+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "MGSPRNG +6.900000000e+01+6.000000000e+00+1.000000000e+08+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "GSETMEMB+5.000000000e+00+1.740000000e+02+1.000000000e+00+2.000000000e+00\n"
                "        +0.000000000e+00\n"
                "GUNIVEC +5.170000000e+02+0.000000000e+00+0.000000000e+00-1.000000000e+00\n"
                "MISOSEL +6.600000000e+01+2.060000000e+08+3.000360000e-01+7.800000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00\n"
                "MORSMEL +8.000000000e+00+0.000000000e+00+0.000000000e+00+1.000000000e+00\n"
                "        +0.000000000e+00+1.078204250e+11+3.140797240e+10+1.415411140e+11\n"
                "        +0.000000000e+00+0.000000000e+00+3.261400060e+10+2.219000010e-01\n"
                "        +2.912988960e-01+2.999999930e-02+2.999999930e-02+1.200000040e-05\n"
                "        +1.200000040e-05\n"
                "TDSETNAM+4.000000000e+00+1.660000000e+02+1.130000000e+02+0.000000000e+00\n"
                "        KEY_HOLE_ROOF\n"
                "GELMNT2 +1.000000000e+00+1.000000000e+00+1.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+1.000000000e+00\n"
                "HSUPSTAT+9.000000000e+00+1.000000000e+00+2.329980000e+05+6.000000000e+00\n"
                "        +2.303330000e+05+1.268100000e+05+0.000000000e+00+2.000000000e+00\n"
                "        -1.000000000e+00\n"
                "HSUPTRAN+1.800000000e+01+2.000000000e+00+1.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+1.000000000e+00\n"
                "        +0.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +1.000000000e+00+0.000000000e+00+0.000000000e+00+0.000000000e+00\n"
                "        +0.000000000e+00+1.000000000e+00\n"
                "HIERARCH+9.000000000e+00+1.000000000e+00+2.000000000e+00+1.000000000e+00\n"
                "        +2.000000000e+00+0.000000000e+00+0.000000000e+00+1.000000000e+00\n"
                "        +2.000000000e+00\n"
                "TDLOAD  +4.000000000e+00+1.000000000e+00+1.040000000e+02+0.000000000e+00\n"
                "        LC_1\n"
                "BSELL   +1.000000000e+00+1.000000000e+00            0.00            0.00\n"
                "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-1.000000000e+00\n"
                "BNBCD   +3.883500000e+04+6.000000000e+00+4.000000000e+00+4.000000000e+00\n"
                "        +4.000000000e+00+4.000000000e+00+4.000000000e+00+4.000000000e+00\n"
                "BEUSLO  +1.000000000e+00+1.000000000e+00           +0.00+0.000000000e+00\n"
                "        +1.000000000e+00+4.000000000e+00+0.000000000e+00+2.000000000e+00\n"
                "        +1.660468160e+04+3.866691890e+03+3.863680910e+03+1.620549320e+04\n"
                "BNLOAD  +1.000000000e+00+0.000000000e+00           +0.00            0.00\n"
                "        +1.000000000e+00+3.000000000e+00+1.100000000e+00+1.200000000e+00\n"
                "        +1.300000000e+00\n"
                "TDSUPNAM+4.000000000e+00+1.660000000e+02+1.130000000e+02+0.000000000e+00\n"
                "        KEY_HOLE_ROOF\n"
                "IEND    +0.000000000e+00            0.00            0.00            0.00\n"
                "GBOX    +1.100000000e+01+2.000000000e-01+1.000000000e-01+3.000000000e-02\n"
                "        +3.000000000e-02+3.000000000e-02+1.000000000e+00+1.000000000e+00\n"
                "GCHAN   +1.200000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01\n"
                "        +2.500000000e-02+1.000000000e+00+1.000000000e+00\n"
                "        +1.000000000e+00\n"
                "GCHANR  +1.300000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01\n"
                "        +2.500000000e-02+1.000000000e+00+1.000000000e+00\n"
                "        +1.000000000e+00+5.000000000e-03\n"
                "GDOBO   +1.400000000e+01+2.000000000e+00+4.000000000e-02+1.500000000e+00\n"
                "        +5.000000000e-02+6.000000000e-02+1.000000000e+00+1.000000000e+00\n"
                "GIORHR  +1.500000000e+01+2.000000000e-01+2.000000000e-02+1.500000000e-01\n"
                "        +2.000000000e-02+1.800000000e-01+2.000000000e-02+1.000000000e+00\n"
                "        +1.000000000e+00+5.000000000e-03+6.000000000e-03\n"
                "GLSECR  +1.600000000e+01+2.000000000e-01+3.000000000e-02+1.500000000e-01\n"
                "        +2.000000000e-02+1.000000000e+00+1.000000000e+00+1.000000000e+00\n"
                "        +5.000000000e-03\n"
                "GTONP   +1.700000000e+01+2.000000000e-01+2.000000000e-02+1.200000000e-01\n"
                "        +3.000000000e-02+1.500000000e+00+4.000000000e-02+1.000000000e+00\n"
                "        +1.000000000e+00\n"
                == test.str());
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
