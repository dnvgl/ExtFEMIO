/**
   \file bdf/bdf_header_case_control_displacement.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of BDF DISPLACEMENT case control entries.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_displacement[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

displacement::displacement(
std::vector<describer*> const &_describers, restype const &res, long const &n) :
res(res), res_n(n) {
    for (auto p : _describers)
        describers.push_back(std::unique_ptr<describer>(p));
}

displacement::displacement(
    std::vector<describer*> const &describers, restype const &res) :
    displacement(describers, res, 0) {}

displacement::displacement(
    std::vector<describer*> const &describers, long const &res) :
    displacement(describers, restype::n, res) {}

std::ostream &displacement::put(std::ostream &os) const {
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
    return os << std::endl;
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
    std::ostringstream res(
        "TM = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::t1::t1(double &value) :
value(value) {}
std::string displacement::t1::str() const {
    std::ostringstream res(
        "T1 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::t2::t2(double &value) :
value(value) {}
std::string displacement::t2::str() const {
    std::ostringstream res(
        "T2 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::t3::t3(double &value) :
value(value) {}
std::string displacement::t3::str() const {
    std::ostringstream res(
        "T3 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::rm::rm(double &value) :
value(value) {}
std::string displacement::rm::str() const {
    std::ostringstream res(
        "RM = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::r1::r1(double &value) :
value(value) {}
std::string displacement::r1::str() const {
    std::ostringstream res(
        "R1 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::r2::r2(double &value) :
value(value) {}
std::string displacement::r2::str() const {
    std::ostringstream res(
        "R2 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::r3::r3(double &value) :
value(value) {}
std::string displacement::r3::str() const {
    std::ostringstream res(
        "R3 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::f::f(double &value) : value(value) {}
std::string displacement::f::str() const {
    std::ostringstream res(
        "F = ", std::ostringstream::ate);
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
