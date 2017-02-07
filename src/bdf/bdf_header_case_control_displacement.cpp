/**
   \file bdf/bdf_header_case_control_displacement.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of BDF DISPLACEMENT case control entries.

   Detailed description
   */

#include "StdAfx.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_displacement[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

displacement::displacement(
std::list<describer*> const &_describers, restype const &res, long const &n) :
res(res), res_n(n) {
    for (auto p : _describers)
        describers.push_back(std::unique_ptr<displacement::describer>(p));
}

displacement::displacement(
    std::list<describer*> const &describers, restype const &res) :
    displacement::displacement(describers, res, 0) {}

displacement::displacement(
    std::list<describer*> const &describers, long const &res) :
    displacement::displacement(describers, displacement::restype::n, res) {}

std::ostream &displacement::put(std::ostream &os) const {
    os << "DISPLACEMENT";
    if (this->describers.size() > 0) {
        bool first = true;
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
    case displacement::restype::n:
        os << " = " << this->res_n;
        break;
    case displacement::restype::ALL:
        os << " = ALL";
        break;
    case displacement::restype::NONE:
        os << " = NONE";
        break;
    }
    return os << std::endl;
}

displacement::describer::describer() {}

displacement::sort1::sort1() {}
std::string const displacement::sort1::str(void) const {
    return "SORT1";
}

displacement::sort2::sort2() {}
std::string const displacement::sort2::str(void) const {
    return "SORT2";
}

displacement::print::print() {}
std::string const displacement::print::str(void) const {
    return "PRINT";
}

displacement::punch::punch() {}
std::string const displacement::punch::str(void) const {
    return "PUNCH";
}

displacement::plot::plot() {}
std::string const displacement::plot::str(void) const {
    return "PLOT";
}

displacement::real::real() {}
std::string const displacement::real::str(void) const {
    return "REAL";
}

displacement::imag::imag() {}
std::string const displacement::imag::str(void) const {
    return "IMAG";
}

displacement::phase::phase() {}
std::string const displacement::phase::str(void) const {
    return "PHASE";
}

displacement::psdf::psdf() {}
std::string const displacement::psdf::str(void) const {
    return "PSDF";
}

displacement::atoc::atoc() {}
std::string const displacement::atoc::str(void) const {
    return "ATOC";
}

displacement::crms::crms() {}
std::string const displacement::crms::str(void) const {
    return "CRMS";
}

displacement::rall::rall() {}
std::string const displacement::rall::str(void) const {
    return "RALL";
}

displacement::rprint::rprint() {}
std::string const displacement::rprint::str(void) const {
    return "RPRINT";
}

displacement::noprint::noprint() {}
std::string const displacement::noprint::str(void) const {
    return "NOPRINT";
}

displacement::rpunch::rpunch() {}
std::string const displacement::rpunch::str(void) const {
    return "rpunch";
}

displacement::cid::cid() {}
std::string const displacement::cid::str(void) const {
    return "CID";
}

displacement::tm::tm(double &value) :
value(value) {}
std::string const displacement::tm::str(void) const {
    std::ostringstream res(
        "TM = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::t1::t1(double &value) :
value(value) {}
std::string const displacement::t1::str(void) const {
    std::ostringstream res(
        "T1 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::t2::t2(double &value) :
value(value) {}
std::string const displacement::t2::str(void) const {
    std::ostringstream res(
        "T2 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::t3::t3(double &value) :
value(value) {}
std::string const displacement::t3::str(void) const {
    std::ostringstream res(
        "T3 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::rm::rm(double &value) :
value(value) {}
std::string const displacement::rm::str(void) const {
    std::ostringstream res(
        "RM = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::r1::r1(double &value) :
value(value) {}
std::string const displacement::r1::str(void) const {
    std::ostringstream res(
        "R1 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::r2::r2(double &value) :
value(value) {}
std::string const displacement::r2::str(void) const {
    std::ostringstream res(
        "R2 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::r3::r3(double &value) :
value(value) {}
std::string const displacement::r3::str(void) const {
    std::ostringstream res(
        "R3 = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

displacement::f::f(double &value) : value(value) {}
std::string const displacement::f::str(void) const {
    std::ostringstream res(
        "F = ", std::ostringstream::ate);
    res << value;
    return res.str();
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
