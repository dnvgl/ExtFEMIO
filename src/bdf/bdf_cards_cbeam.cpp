/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Defintions for Patran CBEAM cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_cards_cbeam[]) =
        "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;

using bdf::types::entry_type;

namespace {
    auto const cl1 = make_shared<long>(1);
    auto const cd0 = make_shared<double>(0.);
}

bdf::types::card cbeam::head = bdf::types::card("CBEAM");

// entry_type<long> cbeam::form_EID(
//    "EID", bound<long>(cl1));
entry_type<long> cbeam::form_PID("PID");
entry_type<long> cbeam::form_GA("GA");
entry_type<long> cbeam::form_GB("GB");
entry_type<double> cbeam::form_X1("X1");
namespace {
    auto const bound_G0 = make_shared<bound<long>>(cl1);
}
entry_type<long> cbeam::form_G0("G0", bound_G0);
namespace {
    auto const bound_X2 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> cbeam::form_X2("X2", bound_X2);
namespace {
    auto const bound_X3 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> cbeam::form_X3("X3", bound_X3);
namespace {
    auto const bound_BIT = make_shared<bound<double>>();
}
entry_type<double> cbeam::form_BIT("BIT", bound_BIT);
namespace {
    std::set<std::string> allowed{
        "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO"};
    auto std_val = make_shared<std::string>("GGG");
    auto const bound_OFFT = make_shared<bound<std::string>>(allowed, std_val);
}
entry_type<std::string> cbeam::form_OFFT("OFFT", bound_OFFT);
entry_type<vector<int>> cbeam::form_PA("PA"); // maxelem=5, minval=1, maxval=6, uniq=True);
entry_type<vector<int>> cbeam::form_PB("PB"); // maxelem=5, minval=1, maxval=6, uniq=True);
namespace {
    auto const bound_W1A = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> cbeam::form_W1A("W1A", bound_W1A);
namespace {
    auto const bound_W2A = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> cbeam::form_W2A("W2A", bound_W2A);
namespace {
    auto const bound_W3A = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> cbeam::form_W3A("W3A", bound_W3A);
namespace {
    auto const bound_W1B = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> cbeam::form_W1B("W1B", bound_W1B);
namespace {
    auto const bound_W2B = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> cbeam::form_W2B("W2B", bound_W2B);
namespace {
    auto const bound_W3B = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> cbeam::form_W3B("W3B", bound_W3B);
namespace {
    auto const bound_SA = make_shared<bound<long>>(
        cl1, nullptr, nullptr, true);
}
entry_type<long> cbeam::form_SA(
    "SA", bound_SA); // minval=1, default=None)
namespace {
    auto const bound_SB = make_shared<bound<long>>(
        cl1, nullptr, nullptr, true);
}
entry_type<long> cbeam::form_SB(
    "SB", bound_SB); // minval=1, default=None)

/**
 * \brief 
 */
cbeam::cbeam(list<std::string> const &inp) :
        element(inp) {
    this->cbeam::read(inp);
}

cbeam::cbeam(long *EID, long *PID, long *GA, long *GB,
             double *X1, double *X2, double *X3,
             std::string *OFFT/*=nullptr*/,
             vector<int> *PA/*=nullptr*/, vector<int> *PB/*=nullptr*/,
             double *W1A/*=nullptr*/, double *W2A/*=nullptr*/,
             double *W3A/*=nullptr*/, double *W1B/*=nullptr*/,
             double *W2B/*=nullptr*/, double *W3B/*=nullptr*/,
             long *SA/*=nullptr*/, long *SB/*=nullptr*/) :
        element(EID), choose_dir_code(CHOOSE_DIR_CODE::has_DVEC),
        choose_offt_bit(CHOOSE_OFFT_BIT::has_OFFT), PID(PID),
        GA(GA), GB(GB), X1(X1), G0(nullptr/*G0*/), X2(X2), X3(X3),
        BIT(nullptr/*BIT*/), OFFT(OFFT),
        PA(PA), PB(PB),
        W1A(W1A), W2A(W2A), W3A(W3A),
        W1B(W1B), W2B(W2B), W3B(W3B),
        SA(SA), SB(SB) {
    this->cbeam::check_data();
}

cbeam::cbeam(long *EID, long *PID, long *GA, long *GB,
             double *X1, double *X2, double *X3,
             double *BIT,
             vector<int> *PA/*=nullptr*/, vector<int> *PB/*=nullptr*/,
             double *W1A/*=nullptr*/, double *W2A/*=nullptr*/,
             double *W3A/*=nullptr*/, double *W1B/*=nullptr*/,
             double *W2B/*=nullptr*/, double *W3B/*=nullptr*/,
             long *SA/*=nullptr*/, long *SB/*=nullptr*/) :
        element(EID), choose_dir_code(CHOOSE_DIR_CODE::has_DVEC),
        choose_offt_bit(CHOOSE_OFFT_BIT::has_BIT), PID(PID),
        GA(GA), GB(GB), X1(X1), G0(nullptr/*G0*/), X2(X2), X3(X3),
        BIT(BIT), OFFT(nullptr/*OFFT*/),
        PA(PA), PB(PB),
        W1A(W1A), W2A(W2A), W3A(W3A),
        W1B(W1B), W2B(W2B), W3B(W3B),
        SA(SA), SB(SB) {
    this->cbeam::check_data();
}

cbeam::cbeam(long *EID, long *PID, long *GA, long *GB, long *G0,
             std::string *OFFT/*=nullptr*/,
             vector<int> *PA/*=nullptr*/, vector<int> *PB/*=nullptr*/,
             double *W1A/*=nullptr*/, double *W2A/*=nullptr*/,
             double *W3A/*=nullptr*/, double *W1B/*=nullptr*/,
             double *W2B/*=nullptr*/, double *W3B/*=nullptr*/,
             long *SA/*=nullptr*/, long *SB/*=nullptr*/) :
        element(EID), choose_dir_code(CHOOSE_DIR_CODE::has_DCODE),
        choose_offt_bit(CHOOSE_OFFT_BIT::has_OFFT), PID(PID),
        GA(GA), GB(GB), X1(nullptr/*X1*/), G0(G0), X2(nullptr/*X2*/), X3(nullptr/*X3*/),
        BIT(nullptr/*BIT*/), OFFT(OFFT),
        PA(PA), PB(PB),
        W1A(W1A), W2A(W2A), W3A(W3A),
        W1B(W1B), W2B(W2B), W3B(W3B),
        SA(SA), SB(SB) {
    this->cbeam::check_data();
}

cbeam::cbeam(long *EID, long *PID, long *GA, long *GB, long *G0,
             double *BIT,
             vector<int> *PA/*=nullptr*/, vector<int> *PB/*=nullptr*/,
             double *W1A/*=nullptr*/, double *W2A/*=nullptr*/,
             double *W3A/*=nullptr*/, double *W1B/*=nullptr*/,
             double *W2B/*=nullptr*/, double *W3B/*=nullptr*/,
             long *SA/*=nullptr*/, long *SB/*=nullptr*/) :
        element(EID), choose_dir_code(CHOOSE_DIR_CODE::has_DCODE),
        choose_offt_bit(CHOOSE_OFFT_BIT::has_BIT), PID(PID),
        GA(GA), GB(GB), X1(nullptr/*X1*/), G0(G0), X2(nullptr/*X2*/), X3(nullptr/*X3*/),
        BIT(BIT), OFFT(nullptr/*OFFT*/),
        PA(PA), PB(PB),
        W1A(W1A), W2A(W2A), W3A(W3A),
        W1B(W1B), W2B(W2B), W3B(W3B),
        SA(SA), SB(SB) {
    this->cbeam::check_data();
}

cards::types cbeam::card_type() const {
    return types::CBEAM;
}

void cbeam::read(list<std::string> const &inp) {
    auto pos = inp.rbegin();

    form_SB.set_value(SB, "");
    form_SA.set_value(SA, "");
    form_W3B.set_value(W3B, "");
    form_W2B.set_value(W2B, "");
    form_W1B.set_value(W1B, "");
    form_W3A.set_value(W3A, "");
    form_W2A.set_value(W2A, "");
    form_W1A.set_value(W1A, "");
    form_PB.set_value(PB, "");
    form_PA.set_value(PA, "");
    OFFT.is_value = false;
    BIT.is_value = false;

    switch (inp.size() - 1) {
    case 24:
        ++pos;
    case 23:
        ++pos;
    case 22:
        ++pos;
    case 21:
        ++pos;
    case 20:
        ++pos;
    case 19:
        ++pos;
    case 18:
        form_SB.set_value(SB, *(pos++));
    case 17:
        form_SA.set_value(SA, *(pos++));
    case 16:
        form_W3B.set_value(W3B, *(pos++));
    case 15:
        form_W2B.set_value(W2B, *(pos++));
    case 14:
        form_W1B.set_value(W1B, *(pos++));
    case 13:
        form_W3A.set_value(W3A, *(pos++));
    case 12:
        form_W2A.set_value(W2A, *(pos++));
    case 11:
        form_W1A.set_value(W1A, *(pos++));
    case 10:
        form_PB.set_value(PB, *(pos++));
    case 9:
        form_PA.set_value(PA, *(pos++));
    case 8:
        try {
            form_BIT.set_value(BIT, *pos);
            OFFT.is_value = false;
            choose_offt_bit = CHOOSE_OFFT_BIT::has_BIT;
        } catch (errors::float_error) {
            form_OFFT.set_value(OFFT, *pos);
            BIT.is_value = false;
            choose_offt_bit = CHOOSE_OFFT_BIT::has_OFFT;
        }
        ++pos;
    case 7:
        form_X3.set_value(X3, *(pos++));
    case 6:
        form_X2.set_value(X2, *(pos++));
    case 5:
        try {
            form_X1.set_value(X1, *(pos));
            if (!X2.is_value || !X3.is_value) {
                throw errors::parse_error(
                    "CBEAM", "Incomplete direction vector.");
            }
            G0.is_value = false;
            choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
        } catch (errors::float_error) {
            form_G0.set_value(G0, *pos);
            X1.is_value = false;
            choose_dir_code = CHOOSE_DIR_CODE::has_DCODE;
        }
        ++pos;
        form_GB.set_value(GB, *(pos++));
        form_GA.set_value(GA, *(pos++));
        form_PID.set_value(PID, *(pos));
        // form_EID.set_value(EID, *(pos++));
        break;
    default:
        throw errors::parse_error(
            "CBEAM", "Illegal number of entries for CBEAM");
    }

    if (!W3B) form_W3B.set_value(W3B, "");
    if (!W2B) form_W2B.set_value(W2B, "");
    if (!W1B) form_W1B.set_value(W1B, "");
    if (!W3A) form_W3A.set_value(W3A, "");
    if (!W2A) form_W2A.set_value(W2A, "");
    if (!W1A) form_W1A.set_value(W1A, "");
    if (!PB) form_PB.set_value(PB, "");
    if (!PA) form_PA.set_value(PA, "");
    if (!(bool(BIT) || bool(OFFT))) {
        choose_offt_bit = CHOOSE_OFFT_BIT::has_OFFT;
        form_OFFT.set_value(OFFT, "");
    }
}

void cbeam::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {

    if (!EID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_GA, GA)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_GB, GB)));
    if (choose_dir_code == CHOOSE_DIR_CODE::has_DCODE) {
        res.push_back(unique_ptr<format_entry>(format<long>(form_G0, G0)));
        if ((bool(OFFT) || bool(BIT)) || bool(PA) || bool(PB) || bool(W1A) ||
            bool(W2A) || bool(W3A) || bool(W1B) || bool(W2B) || bool(W3B)) {
            res.push_back(unique_ptr<format_entry>(format(empty)));
            res.push_back(unique_ptr<format_entry>(format(empty)));
        }
    } else {
        res.push_back(unique_ptr<format_entry>(format<double>(form_X1, X1)));
        res.push_back(unique_ptr<format_entry>(format<double>(form_X2, X2)));
        res.push_back(unique_ptr<format_entry>(format<double>(form_X3, X3)));
    }

    if ((bool(OFFT) || bool(BIT)) || bool(PA) || bool(PB) || bool(W1A) ||
        bool(W2A) || bool(W3A) || bool(W1B) || bool(W2B) || bool(W3B))
        if (choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_BIT)
            res.push_back(
                unique_ptr<format_entry>(format<double>(form_BIT, BIT)));
        else
            res.push_back(
                unique_ptr<format_entry>(format<std::string>(form_OFFT, OFFT)));
    else goto cont;

    if (bool(PA) || bool(PB) || bool(W1A) || bool(W2A) || bool(W3A) ||
        bool(W1B) || bool(W2B) || bool(W3B) || bool(SA) || bool(SB))
        res.push_back(
            unique_ptr<format_entry>(format<vector<int> >(form_PA, PA)));
    else goto cont;
    if (bool(PB) || bool(W1A) || bool(W2A) || bool(W3A) || bool(W1B) ||
        bool(W2B) || bool(W3B) || bool(SA) || bool(SB))
        res.push_back(
            unique_ptr<format_entry>(format<vector<int> >(form_PB, PB)));
    else goto cont;
    if (bool(W1A) || bool(W2A) || bool(W3A) || bool(W1B) || bool(W2B) ||
        bool(W3B) || bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<double>(form_W1A, W1A)));
    else goto cont;
    if (bool(W2A) || bool(W3A) || bool(W1B) || bool(W2B) || bool(W3B) ||
        bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<double>(form_W2A, W2A)));
    else goto cont;
    if (bool(W3A) || bool(W1B) || bool(W2B) || bool(W3B) || bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<double>(form_W3A, W3A)));
    else goto cont;
    if (bool(W1B) || bool(W2B) || bool(W3B) || bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<double>(form_W1B, W1B)));
    else goto cont;
    if (bool(W2B) || bool(W3B) || bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<double>(form_W2B, W2B)));
    else goto cont;
    if (bool(W3B) || bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<double>(form_W3B, W3B)));
    else goto cont;
    if (bool(SA) || bool(SB))
        res.push_back(unique_ptr<format_entry>(format<long>(form_SA, SA)));
    else goto cont;
    if (bool(SB))
        res.push_back(unique_ptr<format_entry>(format<long>(form_SB, SB)));
cont:
    return;
}

cards::__base::card const &cbeam::operator()(list<std::string> const &inp) {
    this->element::read(inp);
    this->cbeam::read(inp);
    return *this;
}

void cbeam::check_data() {
    if (PID) form_PID.check(this->PID);
    if (GA) form_GA.check(this->GA);
    if (GB) form_GB.check(this->GB);
    if (G0) form_G0.check(this->G0);
    if (X1) form_X1.check(this->X1);
    if (X2) form_X2.check(this->X2);
    if (X3) form_X3.check(this->X3);
    if (BIT) form_BIT.check(this->BIT);
    if (OFFT) form_OFFT.check(this->OFFT);
    if (PA) form_PA.check(this->PA);
    if (PB) form_PB.check(this->PB);
    if (W1A) form_W1A.check(this->W1A);
    if (W2A) form_W2A.check(this->W2A);
    if (W3A) form_W3A.check(this->W3A);
    if (W1B) form_W1B.check(this->W1B);
    if (W2B) form_W2B.check(this->W2B);
    if (W3B) form_W3B.check(this->W3B);
    if (SA) form_SA.check(this->SA);
    if (SB) form_SB.check(this->SB);
}

cards::__base::card const &cbeam::operator() (
    long const *EID, long const *PID,
    long const *GA, long const *GB,
    double const *X1, double const *X2, double const *X3,
    std::string const *OFFT/*=nullptr*/,
    vector<int> const *PA/*=nullptr*/, vector<int> const *PB/*=nullptr*/,
    double const *W1A/*=nullptr*/, double const *W2A/*=nullptr*/,
    double const *W3A/*=nullptr*/, double const *W1B/*=nullptr*/,
    double const *W2B/*=nullptr*/, double const *W3B/*=nullptr*/,
    long const *SA/*=nullptr*/, long const *SB/*=nullptr*/) {
    choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
    choose_offt_bit = CHOOSE_OFFT_BIT::has_OFFT;
    this->element::operator() (EID);
    this->PID(PID);
    this->GA(GA);
    this->GB(GB);
    this->X1(X1);
    this->G0(nullptr);
    this->X2(X2);
    this->X3(X3);
    this->BIT(nullptr);
    this->OFFT(OFFT);
    this->PA(PA);
    this->PB(PB);
    this->W1A(W1A);
    this->W2A(W2A);
    this->W3A(W3A);
    this->W1B(W1B);
    this->W2B(W2B);
    this->W3B(W3B);
    this->SA(SA);
    this->SB(SB);
    this->cbeam::check_data();
    return *this;
}

cards::__base::card const &cbeam::operator() (
    long const *EID, long const *PID,
    long const *GA, long const *GB,
    double const *X1, double const *X2, double const *X3,
    double const *BIT,
    vector<int> const *PA/*=nullptr*/, vector<int> const *PB/*=nullptr*/,
    double const *W1A/*=nullptr*/, double const *W2A/*=nullptr*/,
    double const *W3A/*=nullptr*/, double const *W1B/*=nullptr*/,
    double const *W2B/*=nullptr*/, double const *W3B/*=nullptr*/,
    long const *SA/*=nullptr*/, long const *SB/*=nullptr*/) {
    choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
    choose_offt_bit = CHOOSE_OFFT_BIT::has_BIT;
    this->element::operator() (EID);
    this->PID(PID);
    this->GA(GA);
    this->GB(GB);
    this->X1(X1);
    this->G0(nullptr);
    this->X2(X2);
    this->X3(X3);
    this->BIT(BIT);
    this->OFFT(nullptr);
    this->PA(PA);
    this->PB(PB);
    this->W1A(W1A);
    this->W2A(W2A);
    this->W3A(W3A);
    this->W1B(W1B);
    this->W2B(W2B);
    this->W3B(W3B);
    this->SA(SA);
    this->SB(SB);
    this->cbeam::check_data();
    return *this;
}

cards::__base::card const &cbeam::operator() (
    long const *EID, long const *PID,
    long const *GA, long const *GB, long const *G0,
    std::string const *OFFT/*=nullptr*/,
    vector<int> const *PA/*=nullptr*/, vector<int> const *PB/*=nullptr*/,
    double const *W1A/*=nullptr*/, double const *W2A/*=nullptr*/,
    double const *W3A/*=nullptr*/, double const *W1B/*=nullptr*/,
    double const *W2B/*=nullptr*/, double const *W3B/*=nullptr*/,
    long const *SA/*=nullptr*/, long const *SB/*=nullptr*/) {
    this->element::operator() (EID);
    choose_dir_code = CHOOSE_DIR_CODE::has_DCODE;
    choose_offt_bit = CHOOSE_OFFT_BIT::has_OFFT;
    this->PID(PID);
    this->GA(GA);
    this->GB(GB);
    this->X1(nullptr);
    this->G0(G0);
    this->X2(nullptr);
    this->X3(nullptr);
    this->BIT(nullptr);
    this->OFFT(OFFT);
    this->PA(PA);
    this->PB(PB);
    this->W1A(W1A);
    this->W2A(W2A);
    this->W3A(W3A);
    this->W1B(W1B);
    this->W2B(W2B);
    this->W3B(W3B);
    this->SA(SA);
    this->SB(SB);
    this->cbeam::check_data();
    return *this;
}

cards::__base::card const &cbeam::operator() (
    long const *EID, long const *PID,
    long const *GA, long const *GB, long const *G0,
    double const *BIT,
    vector<int> const *PA/*=nullptr*/, vector<int> const *PB/*=nullptr*/,
    double const *W1A/*=nullptr*/, double const *W2A/*=nullptr*/,
    double const *W3A/*=nullptr*/, double const *W1B/*=nullptr*/,
    double const *W2B/*=nullptr*/, double const *W3B/*=nullptr*/,
    long const *SA/*=nullptr*/, long const *SB/*=nullptr*/) {
    this->element::operator() (EID);
    choose_dir_code = CHOOSE_DIR_CODE::has_DCODE;
    choose_offt_bit = CHOOSE_OFFT_BIT::has_BIT;
    this->PID(PID);
    this->GA(GA);
    this->GB(GB);
    this->X1(nullptr);
    this->G0(G0);
    this->X2(nullptr);
    this->X3(nullptr);
    this->BIT(BIT);
    this->OFFT(nullptr);
    this->PA(PA);
    this->PB(PB);
    this->W1A(W1A);
    this->W2A(W2A);
    this->W3A(W3A);
    this->W1B(W1B);
    this->W2B(W2B);
    this->W3B(W3B);
    this->SA(SA);
    this->SB(SB);
    this->cbeam::check_data();
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
