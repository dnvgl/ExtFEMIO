/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Support for BDF SPCFORCES case control entries.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_spcforces[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace std;

using namespace dnvgl::extfem::bdf::header::case_control;

spcforces::spcforces(
    vector<shared_ptr<describer>> const &describers,
    restype const res, long const n) :
    res(res), res_n(n) {
    for (auto p : describers)
        this->describers.push_back(shared_ptr<describer>(p));
}

spcforces::spcforces(
    vector<shared_ptr<describer>> const &describers,
    restype const res) :
    spcforces(describers, res, 0) {}

spcforces::spcforces(
    vector<shared_ptr<describer>> const &describers, long const res) :
    spcforces(describers, restype::n, res) {}

ostream &spcforces::put(ostream &os) const {
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
    return os << endl;
}

std::string spcforces::print::str() const {
    return "PRINT";
}

std::string spcforces::nozprint::str() const {
    return "NOZPRINT";
}

std::string spcforces::sort2::str() const {
    return "SORT2";
}

std::string spcforces::punch::str() const {
    return "PUNCH";
}

std::string spcforces::imag::str() const {
    return "IMAG";
}

std::string spcforces::phase::str() const {
    return "PHASE";
}

std::string spcforces::psdf::str() const {
    return "PSDF";
}

std::string spcforces::crms::str() const {
    return "CRMS";
}

std::string spcforces::rpunch::str() const {
    return "RPUNCH";
}

std::string spcforces::rall::str() const {
    return "RALL";
}

std::string spcforces::norprint::str() const {
    return "NORPRINT";
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test ;
//    ../../cbuild/tests/test_bdf_header --use-colour no)"
// End:
