/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of BDF DISPLACEMENT case control entries.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_displacement[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace std;

using namespace dnvgl::extfem::bdf::header::case_control;

displacement::displacement(
vector<shared_ptr<describer>> const &describers, restype const res,
long const n) :
res(res), res_n(n) {
     // copy(describers.begin(), describers.end(), this->describers);
    for (auto p : describers)
        this->describers.push_back(shared_ptr<describer>(p));
}

displacement::displacement(
    vector<shared_ptr<describer>> const &describers,
    restype const res) :
    displacement(describers, res, 0) {}

displacement::displacement(
    vector<shared_ptr<describer>> const &describers, long const res) :
    displacement(describers, restype::n, res) {}

ostream &displacement::put(ostream &os) const {
    os.imbue(std::locale::classic());
    os << "DISPLACEMENT";
    if (this->describers.size() > 0) {
        auto first = true;
        for (auto &p : this->describers) {
            if (first) {
                os << "(";
                first = false;
            } else
                os << ", ";
            os << p->str();
        }
        os << ")";
    }
    switch (this->res) {
    case restype::n:
        os << " = " << this->res_n;
        break;
    case restype::ALL:
        os << " = ALL";
        break;
    case restype::NONE:
        os << " = NONE";
        break;
    }
    return os << endl;
}

std::string displacement::sort1::str() const {
    return "SORT1";
}

std::string displacement::sort2::str() const {
    return "SORT2";
}

std::string displacement::print::str() const {
    return "PRINT";
}

std::string displacement::punch::str() const {
    return "PUNCH";
}

std::string displacement::plot::str() const {
    return "PLOT";
}

std::string displacement::real::str() const {
    return "REAL";
}

std::string displacement::imag::str() const {
    return "IMAG";
}

std::string displacement::phase::str() const {
    return "PHASE";
}

std::string displacement::psdf::str() const {
    return "PSDF";
}

std::string displacement::atoc::str() const {
    return "ATOC";
}

std::string displacement::crms::str() const {
    return "CRMS";
}

std::string displacement::rall::str() const {
    return "RALL";
}

std::string displacement::rprint::str() const {
    return "RPRINT";
}

std::string displacement::noprint::str() const {
    return "NOPRINT";
}

std::string displacement::rpunch::str() const {
    return "rpunch";
}

std::string displacement::cid::str() const {
    return "CID";
}

displacement::tm::tm(double &value) :
value(value) {}
std::string displacement::tm::str() const {
    ostringstream res(
        "TM = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::t1::t1(double &value) :
value(value) {}
std::string displacement::t1::str() const {
    ostringstream res(
        "T1 = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::t2::t2(double &value) :
value(value) {}
std::string displacement::t2::str() const {
    ostringstream res(
        "T2 = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::t3::t3(double &value) :
value(value) {}
std::string displacement::t3::str() const {
    ostringstream res(
        "T3 = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::rm::rm(double &value) :
value(value) {}
std::string displacement::rm::str() const {
    ostringstream res(
        "RM = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::r1::r1(double &value) :
value(value) {}
std::string displacement::r1::str() const {
    ostringstream res(
        "R1 = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::r2::r2(double &value) :
value(value) {}
std::string displacement::r2::str() const {
    ostringstream res(
        "R2 = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::r3::r3(double &value) :
value(value) {}
std::string displacement::r3::str() const {
    ostringstream res(
        "R3 = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

displacement::f::f(double &value) : value(value) {}
std::string displacement::f::str() const {
    ostringstream res(
        "F = ", ostringstream::ate);
    res.imbue(std::locale::classic());
    res << value;
    return res.str();
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_header --use-colour no)"
// End:
