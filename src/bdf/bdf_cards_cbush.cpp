/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Definitions for Nastran BDF CBUSH cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    // ReSharper disable CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_bdf_cards_cbush[]) =
       "@(#) $Id$";
    // ReSharper restore CppDeclaratorNeverUsed
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

/// Constant values used in bound definitions.
namespace {
    auto const cl_1 = make_shared<long>(-1);
    auto const cl0 = make_shared<long>(0);
    auto const cd0 = make_shared<double>(0.);
    auto const cd05 = make_shared<double>(.5);
    auto const cl1 = make_shared<long>(1);
    auto const cd1 = make_shared<double>(1.);
    auto const clinf = make_shared<long>(100000000 - 1);
}

namespace {
    auto const bound_PID = make_shared<bound<long>>(cl1, clinf);
}
entry_type<long> cbush::form_PID("PID", bound_PID);
namespace {
    auto const bound_GA = make_shared<bound<long>>(cl1);
}
entry_type<long> cbush::form_GA("GA", bound_GA);
namespace {
    auto const bound_GB = make_shared<bound<long>>(cl1, nullptr, nullptr, true);
}
entry_type<long> cbush::form_GB("GB", bound_GB);
namespace {
    auto const bound_GO = make_shared<bound<long>>(cl1, nullptr, nullptr, true);
}
entry_type<long> cbush::form_GO("GO", bound_GO);
namespace {
    auto const bound_X1 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> cbush::form_X1("X1", bound_X1);
namespace {
    auto const bound_X2 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> cbush::form_X2("X2", bound_X2);
namespace {
    auto const bound_X3 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> cbush::form_X3("X3", bound_X3);
namespace {
    auto const bound_CID = make_shared<bound<long>>(
        cl0, nullptr, nullptr, true);
}
entry_type<long> cbush::form_CID("CID", bound_CID);
namespace {
    auto const bound_S = make_shared<bound<double>>(cd0, cd1, cd05, true);
}
entry_type<double> cbush::form_S("S", bound_S);
namespace {
    auto const bound_OCID = make_shared<bound<long>>(
        cl_1, nullptr, nullptr, true);
}
entry_type<long> cbush::form_OCID("OCID", bound_OCID);
namespace {
    auto const bound_S1 = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
}
entry_type<double> cbush::form_S1("S1", bound_S1);
namespace {
    auto const bound_S2 = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
}
entry_type<double> cbush::form_S2("S2", bound_S2);
namespace {
    auto const bound_S3 = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
}
entry_type<double> cbush::form_S3(
    "S3", bound_S3);

bdf::types::card cbush::head = bdf::types::card("CBUSH");

cards::types cbush::card_type() const {
    return cards::types::CBUSH;
}

cbush::cbush(list<std::string> const &inp) :
        element(inp) {
    this->cbush::read(inp);
}

cards::__base::card const &cbush::operator() (list<std::string> const &inp) {
    this->element::read(inp);
    this->cbush::read(inp);
    return *this;
}

void cbush::read(list<std::string> const &inp) {
    auto pos = inp.rbegin();

    choose_dir_code = CHOOSE_DIR_CODE::UNDEF;

    switch (inp.size() - 1) {
    case 16: ++pos;
    case 15: ++pos;
    case 14: ++pos;
    case 13: form_S3.set_value(S3, *(pos++));
    case 12: form_S2.set_value(S2, *(pos++));
    case 11: form_S1.set_value(S1, *(pos++));
    case 10: form_OCID.set_value(OCID, *(pos++));
    case 9: form_S.set_value(S, *(pos++));
    case 8: form_CID.set_value(CID, *(pos++));
    case 7: form_X3.set_value(X3, *(pos++));
    case 6: form_X2.set_value(X2, *(pos++));
    case 5:
        try {
            form_X1.set_value(X1, *pos);
            if (bool(X1) && (!bool(X2) || !bool(X3))) {
                ostringstream msg(
                    "Incomplete direction vector: ", ostringstream::ate);
                msg << *pos << ", ";
                if (bool(X2))
                    msg << double(X2);
                else
                    msg << "***";
                msg << ", ";
                if (bool(X3))
                    msg << double(X3);
                else
                    msg << "***";
                msg << endl;
                throw errors::parse_error(
                    "CBUSH", msg.str());
            }
            GO.is_value = false;
            choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
        } catch (errors::float_error) {
            form_GO.set_value(GO, *pos);
            X1.is_value = false;
            choose_dir_code = CHOOSE_DIR_CODE::has_DNODE;
        }
        ++pos;
    case 4: form_GB.set_value(GB, *(pos++));
    case 3:
        form_GA.set_value(GA, *(pos++));
        form_PID.set_value(PID, *pos);
        break;
    default:
        std::cerr << "PARSE ERROR" << std::endl;
        throw errors::parse_error(
            "CBUSH", "Illegal number of entries.");
    }
}

cbush::cbush(
    long *EID, long *PID, long *GA, long *GB/*=nullptr*/,
    double *X1/*=nullptr*/, double *X2/*=nullptr*/, double *X3/*=nullptr*/,
    long *GO/*=nullptr*/,
    long *CID/*=nullptr*/,
    double *S/*=nullptr*/, long *OCID/*=nullptr*/,
    double *S1/*=nullptr*/, double *S2/*=nullptr*/,
    double *S3/*=nullptr*/) :
        element(EID),
        PID(PID),
        GA(GA), GB(GB),
        X1(X1), X2(X2), X3(X3),
        GO(GO),
        CID(CID),
        S(S),
        OCID(OCID),
        S1(S1), S2(S2), S3(S3)
{
    choose_dir_code = CHOOSE_DIR_CODE::UNDEF;
    if (bool(this->GB)) choose_dir_code = CHOOSE_DIR_CODE::has_DNODE;
    if (bool(this->X1)) {
        if (!bool(this->X2) || !bool(this->X3))
            throw errors::usage_error(
                "CBUSH", "Give either GO or X1, X2, X3.");
        else
            choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
    }
    this->cbush::check_data();
}

/**
 * \brief Return instance with changed values.
 */
cards::__base::card const &cbush::operator() (
    long *EID, long *PID, long *GA, long *GB/*=nullptr*/,
    double *X1/*=nullptr*/, double *X2/*=nullptr*/, double *X3/*=nullptr*/,
    long *GO/*=nullptr*/,
    long *CID/*=nullptr*/,
    double *S/*=nullptr*/, long *OCID/*=nullptr*/,
    double *S1/*=nullptr*/, double *S2/*=nullptr*/,
    double *S3/*=nullptr*/) {
    this->element::operator() (EID);
    this->PID(PID);
    this->GA(GA);
    this->GB(GB);
    this->X1(X1);
    this->X2(X2);
    this->X3(X3);
    this->GO(GO);
    this->CID(CID);
    this->S(S);
    this->OCID(OCID);
    this->S1(S1);
    this->S2(S2);
    this->S3(S3);
    choose_dir_code = CHOOSE_DIR_CODE::UNDEF;
    if (bool(this->GB)) choose_dir_code = CHOOSE_DIR_CODE::has_DNODE;
    if (bool(this->X1)) {
        if (!bool(this->X2) || !bool(this->X3))
            throw errors::usage_error(
                "CBUSH", "Give either GO or X1, X2, X3.");
        else
            choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
    }
    this->cbush::check_data();
    return *this;
}

void cbush::collect_outdata(
    list<unique_ptr<format_entry>> &res) const {
    if (!EID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_GA, GA)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(GB) ? format<long>(form_GB, GB) : format(empty)));
    if (choose_dir_code == CHOOSE_DIR_CODE::has_DNODE) {
        res.push_back(unique_ptr<format_entry>(format<long>(form_GO, GO)));
            res.push_back(unique_ptr<format_entry>(format(empty)));
            res.push_back(unique_ptr<format_entry>(format(empty)));
    } else {
        res.push_back(
            unique_ptr<format_entry>(
                bool(X1) ? format<double>(form_X1, X1) : format(empty)));
        res.push_back(
            unique_ptr<format_entry>(
                bool(X2) ? format<double>(form_X2, X2) : format(empty)));
        res.push_back(
            unique_ptr<format_entry>(
                bool(X3) ? format<double>(form_X3, X3) : format(empty)));
    }
    res.push_back(
        unique_ptr<format_entry>(
            bool(CID) ? format<long>(form_CID, CID) : format(empty)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(S) ? format<double>(form_S, S) : format(empty)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(OCID) ? format<long>(form_OCID, OCID) : format(empty)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(S1) ? format<double>(form_S1, S1) : format(empty)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(S2) ? format<double>(form_S2, S2) : format(empty)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(S3) ? format<double>(form_S3, S3) : format(empty)));
}

void cbush::check_data() {
    // this->element::check_data();
    PID(PID);
        if (bool(GA)) cbush::form_GA.check(this->GA);
        if (bool(GB)) cbush::form_GB.check(this->GB);
        if (bool(X1)) cbush::form_X1.check(this->X1);
        if (bool(X2)) cbush::form_X2.check(this->X2);
        if (bool(X3)) cbush::form_X3.check(this->X3);
        if (bool(GO)) cbush::form_GO.check(this->GO);
        if (bool(CID)) cbush::form_CID.check(this->CID);
        if (bool(S)) cbush::form_S.check(this->S);
        if (bool(OCID)) cbush::form_OCID.check(this->OCID);
        if (bool(S1)) cbush::form_S1.check(this->S1);
        if (bool(S2)) cbush::form_S2.check(this->S2);
        if (bool(S3)) cbush::form_S3.check(this->S3);
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
