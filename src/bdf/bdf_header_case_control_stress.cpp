/**
   \file bdf_header_case_control_stress.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of BDF file header STRESS entries

   Detailed description
   */

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_bdf_header_case_control_stress[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

stress::stress(
    std::vector<describer*> const &_describers,
    restype const &res, long const &res_n) :
    res(res), res_n(res_n) {
    for (auto p : _describers)
        describers.push_back(std::unique_ptr<describer>(p));
}

stress::stress(
    std::vector<describer*> const &describers,
    restype const &res/*=NONE*/) :
    stress(describers, res, 0) {}

stress::stress(
    std::vector<describer*> const &describers,
    long const &res) :
    stress(describers, restype::n, res) {}

std::ostream &stress::put(std::ostream &os) const {
    os << "STRESS";
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

stress::describer::describer() {}

stress::corner::corner() {}

std::string stress::corner::str() const {
    return "CORNER";
}

stress::sort1::sort1() {}

std::string stress::sort1::str() const {
    return "SORT1";
}

stress::print::print() {}

std::string stress::print::str() const {
    return "PRINT";
}

stress::punch::punch() {}

std::string stress::punch::str() const {
    return "PUNCH";
}

stress::phase::phase() {}

std::string stress::phase::str() const {
    return "PHASE";
}

stress::plot::plot() {}

std::string stress::plot::str() const {
    return "PLOT";
}

stress::psdf::psdf() {}

std::string stress::psdf::str() const {
    return "PSDF";
}

stress::crms::crms() {}

std::string stress::crms::str() const {
    return "CRMS";
}

stress::rpunch::rpunch() {}

std::string stress::rpunch::str() const {
    return "RPUNCH";
}

stress::rall::rall() {}

std::string stress::rall::str() const {
    return "RALL";
}

stress::norprint::norprint() {}

std::string stress::norprint::str() const {
    return "NORPRINT";
}

stress::sort2::sort2() {}

std::string stress::sort2::str() const {
    return "SORT2";
}

stress::real::real() {}

std::string stress::real::str() const {
    return "REAL";
}

stress::imag::imag() {}

std::string stress::imag::str() const {
    return "IMAG";
}

stress::atoc::atoc() {}

std::string stress::atoc::str() const {
    return "ATOC";
}

stress::vonmises::vonmises() {}

std::string stress::vonmises::str() const {
    return "VONMISES";
}

stress::maxs::maxs() {}

std::string stress::maxs::str() const {
    return "MAXS";
}

stress::shear::shear() {}

std::string stress::shear::str() const {
    return "SHEAR";
}

stress::center::center() {}

std::string stress::center::str() const {
    return "CENTER";
}

stress::cubic::cubic() {}

std::string stress::cubic::str() const {
    return "CUBIC";
}

stress::sgage::sgage() {}

std::string stress::sgage::str() const {
    return "SGAGE";
}

stress::bilin::bilin() {}

std::string stress::bilin::str() const {
    return "BILIN";
}

stress::rprint::rprint() {}

std::string stress::rprint::str() const {
    return "RPRINT";
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
