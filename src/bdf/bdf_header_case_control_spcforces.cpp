/**
   \file bdf_header_case_control_spcforces.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Support for BDF SPCFORCES case control entries.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_spcforces[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

spcforces::spcforces(
    std::list<describer*> const &_describers, restype const &res, long const &n) :
    res(res), res_n(n) {
    for (auto p : _describers)
        describers.push_back(std::unique_ptr<describer>(p));
}

spcforces::spcforces(
    std::list<describer*> const &describers, restype const &res) :
    spcforces(describers, res, 0) {}

spcforces::spcforces(
    std::list<describer*> const &describers, long const &res) :
    spcforces(describers, restype::n, res) {}

std::ostream &spcforces::put(std::ostream &os) const {
    os << "SPCFORCES";
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

spcforces::describer::describer() {}

spcforces::print::print() {}
std::string spcforces::print::str() const {
    return "PRINT";
}

spcforces::nozprint::nozprint() {}
std::string spcforces::nozprint::str() const {
    return "NOZPRINT";
}

spcforces::sort2::sort2() {}
std::string spcforces::sort2::str() const {
    return "SORT2";
}

spcforces::punch::punch() {}
std::string spcforces::punch::str() const {
    return "PUNCH";
}

spcforces::imag::imag() {}
std::string spcforces::imag::str() const {
    return "IMAG";
}

spcforces::phase::phase() {}
std::string spcforces::phase::str() const {
    return "PHASE";
}

spcforces::psdf::psdf() {}
std::string spcforces::psdf::str() const {
    return "PSDF";
}

spcforces::crms::crms() {}
std::string spcforces::crms::str() const {
    return "CRMS";
}

spcforces::rpunch::rpunch() {}
std::string spcforces::rpunch::str() const {
    return "RPUNCH";
}

spcforces::rall::rall() {}
std::string spcforces::rall::str() const {
    return "RALL";
}

spcforces::norprint::norprint() {}
std::string spcforces::norprint::str() const {
    return "NORPRINT";
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
