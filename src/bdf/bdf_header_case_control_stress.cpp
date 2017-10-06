/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of BDF file header STRESS entries

   Detailed description
   */

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_bdf_header_case_control_stress[]) =
        "@(#) $Id$";
}

#include "bdf/header.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf::header::case_control;

 stress::stress(
    vector<shared_ptr<describer>> const &_describers,
    restype const res, long const res_n) :
    res(res), res_n(res_n) {
    for (auto p : _describers)
        describers.push_back(shared_ptr<describer>(p));
}

stress::stress(
    vector<shared_ptr<describer>> const &describers,
    restype const res/*=NONE*/) :
    stress(describers, res, 0) {}

stress::stress(
    vector<shared_ptr<describer>> const &describers,
    long const res) :
    stress(describers, restype::n, res) {}

ostream &stress::put(ostream &os) const {
    os.imbue(std::locale::classic());
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
    return os << endl;
}

std::string stress::corner::str() const {
    return "CORNER";
}

std::string stress::sort1::str() const {
    return "SORT1";
}

std::string stress::print::str() const {
    return "PRINT";
}

std::string stress::punch::str() const {
    return "PUNCH";
}

std::string stress::phase::str() const {
    return "PHASE";
}

std::string stress::plot::str() const {
    return "PLOT";
}

std::string stress::psdf::str() const {
    return "PSDF";
}

std::string stress::crms::str() const {
    return "CRMS";
}

std::string stress::rpunch::str() const {
    return "RPUNCH";
}

std::string stress::rall::str() const {
    return "RALL";
}

std::string stress::norprint::str() const {
    return "NORPRINT";
}

std::string stress::sort2::str() const {
    return "SORT2";
}

std::string stress::real::str() const {
    return "REAL";
}

std::string stress::imag::str() const {
    return "IMAG";
}

std::string stress::atoc::str() const {
    return "ATOC";
}

std::string stress::vonmises::str() const {
    return "VONMISES";
}

std::string stress::maxs::str() const {
    return "MAXS";
}

std::string stress::shear::str() const {
    return "SHEAR";
}

std::string stress::center::str() const {
    return "CENTER";
}

std::string stress::cubic::str() const {
    return "CUBIC";
}

std::string stress::sgage::str() const {
    return "SGAGE";
}

std::string stress::bilin::str() const {
    return "BILIN";
}

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
