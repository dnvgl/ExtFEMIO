/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Definitions for Nastran BDF PBUSH cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
   char const cID_bdf_cards_pbush[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/errors.h"

#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using type_bounds::bound;
using bdf::types::entry_type;
using bdf::types::entry_value;

/// Constant values used in bound definitions.
namespace {
    auto const cd0 = make_shared<double>(0.);
    auto const cd1 = make_shared<double>(1.);
}

bdf::types::card pbush::head = bdf::types::card("PBUSH");

// PID is defined in parent class.
// const entry_type<long> pbush::form_PID(
//     "PID", bound<long>(cl1));
namespace {
    auto const bound_K = make_shared<bound<double>>(
        nullptr, nullptr, cd0, true);
}
entry_type<double> pbush::form_K("K", bound_K);
namespace {
    auto const bound_B = make_shared<bound<double>>(
        nullptr, nullptr, cd0, true);
}
entry_type<double> pbush::form_B("B", bound_B);
namespace {
    auto const bound_GE = make_shared<bound<double>>(
        nullptr, nullptr, cd0, true);
}
entry_type<double> pbush::form_GE("GE", bound_GE);
namespace {
    auto const bound_SA = make_shared<bound<double>>(
        nullptr, nullptr, cd1);
}
entry_type<double> pbush::form_SA("SA", bound_SA);
namespace {
    auto const bound_ST = make_shared<bound<double>>(
        nullptr, nullptr, cd1);
}
entry_type<double> pbush::form_ST("ST", bound_ST);
namespace {
    auto const bound_EA = make_shared<bound<double>>(
        nullptr, nullptr, cd1);
}
entry_type<double> pbush::form_EA("EA", bound_EA);
namespace {
    auto const bound_ET = make_shared<bound<double>>(
        nullptr, nullptr, cd1);
}
entry_type<double> pbush::form_ET("ET", bound_ET);

pbush::pbush(long *PID,
             vector<double> *K/*=nullptr*/, vector<double> *B/*=nullptr*/,
             vector<double> *GE/*=nullptr*/,
             double *SA/*=nullptr*/, double *ST/*=nullptr*/,
             double *EA/*=nullptr*/, double *ET/*=nullptr*/) :
        property(PID) {
    if (K != nullptr) {
        assert(K->size() == 6);
        this->K.assign(K->begin(), K->end());
    }
    if (B != nullptr) {
        assert(B->size() == 6);
        this->B.assign(B->begin(), B->end());
    }
    if (GE != nullptr) {
        assert(GE->size() == 6);
        this->GE.assign(GE->begin(), GE->end());
    }
    this->RCV = (SA != nullptr || ST != nullptr ||
                 EA != nullptr || ET != nullptr);
    if (SA != nullptr) this->SA = *SA;
    if (ST != nullptr) this->ST = *ST;
    if (EA != nullptr) this->EA = *EA;
    if (ET != nullptr) this->ET = *ET;
    this->pbush::check_data();
}

pbush::pbush(list<std::string> const &inp) :
        property(inp) {
    this->pbush::read(inp);
}

void pbush::read(list<std::string> const &inp) {

    auto pos = inp.begin();
    size_t i;

    K = {};
    B = {};
    GE = {};
    RCV = false;
    form_SA.set_value(SA, "");
    form_ST.set_value(ST, "");
    form_EA.set_value(EA, "");
    form_ET.set_value(ET, "");

    pos++;
    pos++;
    // if (pos == inp.end())
    //     throw errors::parse_error(
    //         "PBUSH", "Illegal number of entries (no PID).");
    // form_PID.set_value(PID, *(pos++));
    if (pos == inp.end())
        throw errors::parse_error(
            "PBUSH", "Illegal number of entries (no indicator).");
    while (pos != inp.end()) {
        if (*pos == "K") {
            K.assign(6, entry_value<double>(0.));
            if (++pos == inp.end())
                throw errors::parse_error(
                    "PBUSH", "Illegal number of entries (K).");
            i = 0;
            while (pos != inp.end() && i < 6) {
                form_K.set_value(K[i++], *(pos++));
            }
            if (pos != inp.end()) pos++;
        } else if (*pos == "B") {
            B.assign(6, entry_value<double>(0.));
            if (++pos == inp.end())
                throw errors::parse_error(
                    "PBUSH", "Illegal number of entries (B).");
            i = 0;
            while (pos != inp.end() && i < 6) {
                form_B.set_value(B[i++], *(pos++));
            }
            if (pos != inp.end()) pos++;
        } else if (*pos == "GE") {
            GE.assign(6, entry_value<double>(0.));
            if (++pos == inp.end())
                throw errors::parse_error(
                    "PBUSH", "Illegal number of entries (GE).");
            i = 0;
            while (pos != inp.end() && i < 6) {
                form_GE.set_value(GE[i++], *(pos++));
            }
            if (pos != inp.end()) pos++;
        } else if (*pos == "RCV") {
            RCV = true;
            if (++pos == inp.end())
                throw errors::parse_error(
                    "PBUSH", "Illegal number of entries (RCV).");
            form_SA.set_value(SA, *(pos++));
            if (pos != inp.end()) form_ST.set_value(ST, *(pos++));
            if (pos != inp.end()) form_EA.set_value(EA, *(pos++));
            if (pos != inp.end()) form_ET.set_value(ET, *(pos++));
            if (pos != inp.end()) pos++;
            if (pos != inp.end()) pos++;
        } else {
            ostringstream msg("Invalid property flag: ", ostringstream::ate);
            msg << *pos << "." << std::endl;
            throw errors::parse_error(
                "PBUSH", msg.str());
        }
    }
}

cards::types pbush::card_type() const {
    return cards::types::PBUSH;
}

void pbush::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
        if (!PID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));

    if (K.size() != 0) {
        res.push_back(unique_ptr<format_entry>(format("K")));
        for (size_t i=0; i<6; i++)
            res.push_back(
                unique_ptr<format_entry>(
                    bool(K[i]) ?
                    format<double>(form_K, K[i]) :
                    format(empty)));
        res.push_back(
            unique_ptr<format_entry>(format(empty)));
    }
    if (B.size() != 0) {
        res.push_back(unique_ptr<format_entry>(format("B")));
        for (size_t i=0; i<6; i++)
            res.push_back(
                unique_ptr<format_entry>(
                    bool(B[i]) ?
                    format<double>(form_B, B[i]) :
                    format(empty)));
        res.push_back(
            unique_ptr<format_entry>(format(empty)));
    }
    if (GE.size() != 0) {
        res.push_back(unique_ptr<format_entry>(format("GE")));
        for (size_t i=0; i<6; i++)
            res.push_back(
                unique_ptr<format_entry>(
                    bool(GE[i]) ?
                    format<double>(form_GE, GE[i]) :
                    format(empty)));
        res.push_back(
            unique_ptr<format_entry>(format(empty)));
    }
    if (RCV) {
        res.push_back(unique_ptr<format_entry>(format("RCV")));
        res.push_back(
            unique_ptr<format_entry>(
                bool(SA) ? format<double>(form_SA, SA) : format(empty)));
        res.push_back(
            unique_ptr<format_entry>(
                bool(ST) ? format<double>(form_ST, ST) : format(empty)));
        res.push_back(
            unique_ptr<format_entry>(
                bool(EA) ? format<double>(form_EA, EA) : format(empty)));
        res.push_back(
            unique_ptr<format_entry>(
                bool(ET) ? format<double>(form_ET, ET) : format(empty)));
    }
}

void pbush::check_data() {
    // this->property::check_data();
    if (K.size()>0)
        for (size_t i=0; i<6; i++)
            if (bool(K[i]))
                pbush::form_K.check(K[i]);
    if (B.size()>0)
        for (size_t i=0; i<6; i++)
            if (bool(B[i]))
                pbush::form_B.check(B[i]);
    if (GE.size()>0)
        for (size_t i=0; i<6; i++)
            if (bool(GE[i]))
                pbush::form_GE.check(GE[i]);
    if (SA) pbush::form_SA.check(SA);
    if (ST) pbush::form_ST.check(ST);
    if (EA) pbush::form_EA.check(EA);
    if (ET) pbush::form_ET.check(ET);
}

cards::__base::card const &pbush::operator() (list<std::string> const &inp) {
    this->property::read(inp);
    this->pbush::read(inp);
    return *this;
}

cards::__base::card const &pbush::operator() (
    long *PID,
    std::vector<double> *K/*=nullptr*/,
    std::vector<double> *B/*=nullptr*/,
    std::vector<double> *GE/*=nullptr*/,
    double *SA/*=nullptr*/, double *ST/*=nullptr*/,
    double *EA/*=nullptr*/, double *ET/*=nullptr*/) {
    this->property::operator()(PID);

    if (K != nullptr) this->K.assign(K->begin(), K->end());
    if (B != nullptr) this->B.assign(B->begin(), B->end());
    if (GE != nullptr) this->GE.assign(GE->begin(), GE->end());
    if (SA != nullptr) this->SA = *SA;
    if (ST != nullptr) this->ST = *ST;
    if (EA != nullptr) this->EA = *EA;
    if (ET != nullptr) this->ET = *ET;
    this->pbush::check_data();
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
