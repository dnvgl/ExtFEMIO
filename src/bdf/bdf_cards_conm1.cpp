/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Definitions for Nastran BDF CONM1 cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_bdf_cards_cmass2[]) =
        "@(#) $Id$";
}

#include <cassert>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;

bdf::types::card conm1::head = bdf::types::card("CONM1");

bool conm1::keep_all_entries() const {
    return true;
}

namespace {
    auto const c_l0 = make_shared<long>(0);
    auto const c_l1 = make_shared<long>(1);
    auto const c_d0 = make_shared<double>(0);
}

// entry_type<long> conm1::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
namespace {
    auto const bound_G = make_shared<bound<long>>(c_l1);
}
entry_type<long> conm1::form_G("G", bound_G);
namespace {
    auto const bound_CID = make_shared<bound<long>>(c_l0);
}
entry_type<long> conm1::form_CID("CID", bound_CID);
namespace {
    auto const bound_Mij = make_shared<bound<double>>(
        nullptr, nullptr, c_d0, true);
}
entry_type<double> conm1::form_Mij("Mij", bound_Mij);

conm1::conm1(std::list<std::string> const &inp) :
        element(inp) {
    this->conm1::read(inp);
    this->conm1::check_data();
}

conm1::conm1(long const *EID, long const *G, long const *CID,
             double const *M11,
             double const *M21/*=nullptr*/, double const *M22/*=nullptr*/,
             double const *M31/*=nullptr*/, double const *M32/*=nullptr*/,
             double const *M33/*=nullptr*/,
             double const *M41/*=nullptr*/, double const *M42/*=nullptr*/,
             double const *M43/*=nullptr*/, double const *M44/*=nullptr*/,
             double const *M51/*=nullptr*/, double const *M52/*=nullptr*/,
             double const *M53/*=nullptr*/, double const *M54/*=nullptr*/,
             double const *M55/*=nullptr*/,
             double const *M61/*=nullptr*/, double const *M62/*=nullptr*/,
             double const *M63/*=nullptr*/, double const *M64/*=nullptr*/,
             double const *M65/*=nullptr*/, double const *M66/*=nullptr*/) :
    element(EID), G(G), CID(CID),
    M11(M11),
    M21(M21), M22(M22),
    M31(M31), M32(M32), M33(M33),
    M41(M41), M42(M42), M43(M43), M44(M44),
    M51(M51), M52(M52), M53(M53), M54(M54), M55(M55),
    M61(M61), M62(M62), M63(M63), M64(M64), M65(M65), M66(M66) {
    this->conm1::check_data();
}

namespace {
    long sEID{0};
}

conm1::conm1(long const *G, long const *CID,
             double const *M11,
             double const *M21/*=nullptr*/, double const *M22/*=nullptr*/,
             double const *M31/*=nullptr*/, double const *M32/*=nullptr*/,
             double const *M33/*=nullptr*/,
             double const *M41/*=nullptr*/, double const *M42/*=nullptr*/,
             double const *M43/*=nullptr*/, double const *M44/*=nullptr*/,
             double const *M51/*=nullptr*/, double const *M52/*=nullptr*/,
             double const *M53/*=nullptr*/, double const *M54/*=nullptr*/,
             double const *M55/*=nullptr*/,
             double const *M61/*=nullptr*/, double const *M62/*=nullptr*/,
             double const *M63/*=nullptr*/, double const *M64/*=nullptr*/,
             double const *M65/*=nullptr*/, double const *M66/*=nullptr*/) :
    element(&sEID), G(G), CID(CID),
    M11(M11),
    M21(M21), M22(M22),
    M31(M31), M32(M32), M33(M33),
    M41(M41), M42(M42), M43(M43), M44(M44),
    M51(M51), M52(M52), M53(M53), M54(M54), M55(M55),
    M61(M61), M62(M62), M63(M63), M64(M64), M65(M65), M66(M66) {
    this->conm1::check_data();
}

conm1::conm1(long const *EID, long const *G, long const *CID,
             std::vector<double> const *Mij) :
    element(EID), G(G), CID(CID),
    M11(nullptr),
    M21(nullptr), M22(nullptr),
    M31(nullptr), M32(nullptr), M33(nullptr),
    M41(nullptr), M42(nullptr), M43(nullptr), M44(nullptr),
    M51(nullptr), M52(nullptr), M53(nullptr), M54(nullptr), M55(nullptr),
    M61(nullptr), M62(nullptr), M63(nullptr), M64(nullptr), M65(nullptr),
    M66(nullptr) {
    assert(Mij->size() > 0);
    assert(Mij->size() <= 6);
    switch (Mij->size()) {
    case 6:  M66 = (*Mij)[5];
    case 5:  M55 = (*Mij)[4];
    case 4:  M44 = (*Mij)[3];
    case 3:  M33 = (*Mij)[2];
    case 2:  M22 = (*Mij)[1];
    default: M11 = (*Mij)[0];
    }
    this->conm1::check_data();
}

conm1::conm1(long const *G, long const *CID,
             std::vector<double> const *Mij) :
    element(&sEID), G(G), CID(CID),
    M11(nullptr),
    M21(nullptr), M22(nullptr),
    M31(nullptr), M32(nullptr), M33(nullptr),
    M41(nullptr), M42(nullptr), M43(nullptr), M44(nullptr),
    M51(nullptr), M52(nullptr), M53(nullptr), M54(nullptr), M55(nullptr),
    M61(nullptr), M62(nullptr), M63(nullptr), M64(nullptr), M65(nullptr),
    M66(nullptr) {
    assert(Mij->size() > 0);
    assert(Mij->size() <= 6);
    switch (Mij->size()) {
    case 6:  M66 = (*Mij)[5];
    case 5:  M55 = (*Mij)[4];
    case 4:  M44 = (*Mij)[3];
    case 3:  M33 = (*Mij)[2];
    case 2:  M22 = (*Mij)[1];
    default: M11 = (*Mij)[0];
    }
    this->conm1::check_data();
}

card const &conm1::operator() (
    long const *EID, long const *G, long const *CID,
    double const *M11,
    double const *M21/*=nullptr*/, double const *M22/*=nullptr*/,
    double const *M31/*=nullptr*/, double const *M32/*=nullptr*/,
    double const *M33/*=nullptr*/,
    double const *M41/*=nullptr*/, double const *M42/*=nullptr*/,
    double const *M43/*=nullptr*/, double const *M44/*=nullptr*/,
    double const *M51/*=nullptr*/, double const *M52/*=nullptr*/,
    double const *M53/*=nullptr*/, double const *M54/*=nullptr*/,
    double const *M55/*=nullptr*/,
    double const *M61/*=nullptr*/, double const *M62/*=nullptr*/,
    double const *M63/*=nullptr*/, double const *M64/*=nullptr*/,
    double const *M65/*=nullptr*/, double const *M66/*=nullptr*/) {

    this->EID(EID);
    this->G(G);
    this->CID(CID);
    this->M11(M11);
    this->M21(M21);
    this->M22(M22);
    this->M31(M31);
    this->M32(M32);
    this->M33(M33);
    this->M41(M41);
    this->M42(M42);
    this->M43(M43);
    this->M44(M44);
    this->M51(M51);
    this->M52(M52);
    this->M53(M53);
    this->M54(M54);
    this->M55(M55);
    this->M61(M61);
    this->M62(M62);
    this->M63(M63);
    this->M64(M64);
    this->M65(M65);
    this->M66(M66);

    this->conm1::check_data();
    return *this;
}

card const &conm1::operator() (
    long const *G, long const *CID,
    double const *M11,
    double const *M21/*=nullptr*/, double const *M22/*=nullptr*/,
    double const *M31/*=nullptr*/, double const *M32/*=nullptr*/,
    double const *M33/*=nullptr*/,
    double const *M41/*=nullptr*/, double const *M42/*=nullptr*/,
    double const *M43/*=nullptr*/, double const *M44/*=nullptr*/,
    double const *M51/*=nullptr*/, double const *M52/*=nullptr*/,
    double const *M53/*=nullptr*/, double const *M54/*=nullptr*/,
    double const *M55/*=nullptr*/,
    double const *M61/*=nullptr*/, double const *M62/*=nullptr*/,
    double const *M63/*=nullptr*/, double const *M64/*=nullptr*/,
    double const *M65/*=nullptr*/, double const *M66/*=nullptr*/) {

    this->EID(EID);
    this->G(G);
    this->CID(CID);
    this->M11(M11);
    this->M21(M21);
    this->M22(M22);
    this->M31(M31);
    this->M32(M32);
    this->M33(M33);
    this->M41(M41);
    this->M42(M42);
    this->M43(M43);
    this->M44(M44);
    this->M51(M51);
    this->M52(M52);
    this->M53(M53);
    this->M54(M54);
    this->M55(M55);
    this->M61(M61);
    this->M62(M62);
    this->M63(M63);
    this->M64(M64);
    this->M65(M65);
    this->M66(M66);

    this->conm1::check_data();
    return *this;
}

card const &conm1::operator() (
    long const *EID, long const *G, long const *CID,
    std::vector<double> const *Mij) {

    assert(Mij->size() > 0);
    assert(Mij->size() <= 6);

    this->element::operator() (EID);
    this->G(G);
    this->CID(CID);
    this->M11 = (*Mij)[0];
    this->M21(nullptr);
    if (Mij->size()>1)
        this->M22 = (*Mij)[1];
    else
        this->M22(nullptr);
    this->M31(nullptr);
    this->M32(nullptr);
    if (Mij->size()>2)
        this->M33 = (*Mij)[2];
    else
        this->M33(nullptr);
    this->M41(nullptr);
    this->M42(nullptr);
    this->M43(nullptr);
    if (Mij->size()>3)
        this->M44 = (*Mij)[3];
    else
        this->M44(nullptr);
    this->M51(nullptr);
    this->M52(nullptr);
    this->M53(nullptr);
    this->M54(nullptr);
    if (Mij->size()>4)
        this->M55 = (*Mij)[4];
    else
        this->M55(nullptr);
    this->M61(nullptr);
    this->M62(nullptr);
    this->M63(nullptr);
    this->M64(nullptr);
    this->M65(nullptr);
    if (Mij->size()>5)
        this->M66 = (*Mij)[5];
    else
        this->M66(nullptr);

    this->conm1::check_data();
    return *this;
}

card const &conm1::operator() (
    long const *G, long const *CID,
    std::vector<double> const *Mij) {

    assert(Mij->size() > 0);
    assert(Mij->size() <= 6);

    long xEID{0};
    this->element::operator() (&xEID);
    this->G(G);
    this->CID(CID);
    this->M11 = (*Mij)[0];
    this->M21(nullptr);
    if (Mij->size()>1)
        this->M22 = (*Mij)[1];
    else
        this->M22(nullptr);
    this->M31(nullptr);
    this->M32(nullptr);
    if (Mij->size()>2)
        this->M33 = (*Mij)[2];
    else
        this->M33(nullptr);
    this->M41(nullptr);
    this->M42(nullptr);
    this->M43(nullptr);
    if (Mij->size()>3)
        this->M44 = (*Mij)[3];
    else
        this->M44(nullptr);
    this->M51(nullptr);
    this->M52(nullptr);
    this->M53(nullptr);
    this->M54(nullptr);
    if (Mij->size()>4)
        this->M55 = (*Mij)[4];
    else
        this->M55(nullptr);
    this->M61(nullptr);
    this->M62(nullptr);
    this->M63(nullptr);
    this->M64(nullptr);
    this->M65(nullptr);
    if (Mij->size()>5)
        this->M66 = (*Mij)[5];
    else
        this->M66(nullptr);

    this->conm1::check_data();
    return *this;
}

cards::types conm1::card_type() const {
    return types::CONM1;
}

void conm1::read(list<std::string> const &inp) {

    if (inp.size() < 18 || inp.size() > 25)
        throw errors::parse_error("CONM1", "Illegal number of entries.");

    auto pos = inp.begin();

    ++pos;
    ++pos;
    form_G  .set_value(G  , *(pos++));
    form_CID.set_value(CID, *(pos++));
    form_Mij.set_value(M11, *(pos++));
    form_Mij.set_value(M21, *(pos++));
    form_Mij.set_value(M22, *(pos++));
    form_Mij.set_value(M31, *(pos++));
    form_Mij.set_value(M32, *(pos++));
    form_Mij.set_value(M33, *(pos++));
    form_Mij.set_value(M41, *(pos++));
    form_Mij.set_value(M42, *(pos++));
    form_Mij.set_value(M43, *(pos++));
    form_Mij.set_value(M44, *(pos++));
    form_Mij.set_value(M51, *(pos++));
    form_Mij.set_value(M52, *(pos++));
    form_Mij.set_value(M53, *(pos++));
    form_Mij.set_value(M54, *(pos++));
    form_Mij.set_value(M55, *(pos++));
    form_Mij.set_value(M61, *(pos++));
    form_Mij.set_value(M62, *(pos++));
    form_Mij.set_value(M63, *(pos++));
    form_Mij.set_value(M64, *(pos++));
    form_Mij.set_value(M65, *(pos++));
    form_Mij.set_value(M66, *pos);
    this->conm1::check_data();
}

card const &conm1::operator() (const std::list<std::string> &inp) {
    this->element::read(inp);
    this->conm1::read(inp);
    return *this;
}

void conm1::collect_outdata(
    std::list<std::unique_ptr<format_entry>> &res) const {
    if (!EID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G  , G  )));
    res.push_back(unique_ptr<format_entry>(format<long>(form_CID, CID)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M11) && !form_Mij.is_default(&M11) ?
                      format<double>(form_Mij, M11) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M21) && !form_Mij.is_default(&M21) ?
                      format<double>(form_Mij, M21) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M22) && !form_Mij.is_default(&M22) ?
                      format<double>(form_Mij, M22) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M31) && !form_Mij.is_default(&M31) ?
                      format<double>(form_Mij, M31) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M32) && !form_Mij.is_default(&M32) ?
                      format<double>(form_Mij, M32) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M33) && !form_Mij.is_default(&M33) ?
                      format<double>(form_Mij, M33) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M41) && !form_Mij.is_default(&M41) ?
                      format<double>(form_Mij, M41) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M42) && !form_Mij.is_default(&M42) ?
                      format<double>(form_Mij, M42) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M43) && !form_Mij.is_default(&M43) ?
                      format<double>(form_Mij, M43) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M44) && !form_Mij.is_default(&M44) ?
                      format<double>(form_Mij, M44) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M51) && !form_Mij.is_default(&M51) ?
                      format<double>(form_Mij, M51) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M52) && !form_Mij.is_default(&M62) ?
                      format<double>(form_Mij, M52) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M53) && !form_Mij.is_default(&M63) ?
                      format<double>(form_Mij, M53) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M54) && !form_Mij.is_default(&M54) ?
                      format<double>(form_Mij, M54) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M55) && !form_Mij.is_default(&M55) ?
                      format<double>(form_Mij, M55) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M61) && !form_Mij.is_default(&M61) ?
                      format<double>(form_Mij, M61) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M62) && !form_Mij.is_default(&M62) ?
                      format<double>(form_Mij, M62) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M63) && !form_Mij.is_default(&M63) ?
                      format<double>(form_Mij, M63) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M64) && !form_Mij.is_default(&M64) ?
                      format<double>(form_Mij, M64) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M65) && !form_Mij.is_default(&M65) ?
                      format<double>(form_Mij, M65) : format(empty)));
    res.push_back(unique_ptr<format_entry>(
                      bool(M66) && !form_Mij.is_default(&M66) ?
                      format<double>(form_Mij, M66) : format(empty)));

}

void conm1::check_data() {
    if (G  ) form_G.check(G);
    if (CID) form_CID.check(CID);
    if (M11) form_Mij.check(M11);
    if (M21) form_Mij.check(M21);
    if (M22) form_Mij.check(M22);
    if (M31) form_Mij.check(M31);
    if (M32) form_Mij.check(M32);
    if (M33) form_Mij.check(M33);
    if (M41) form_Mij.check(M41);
    if (M42) form_Mij.check(M42);
    if (M43) form_Mij.check(M43);
    if (M44) form_Mij.check(M44);
    if (M51) form_Mij.check(M51);
    if (M52) form_Mij.check(M52);
    if (M53) form_Mij.check(M53);
    if (M54) form_Mij.check(M54);
    if (M55) form_Mij.check(M55);
    if (M61) form_Mij.check(M61);
    if (M62) form_Mij.check(M62);
    if (M63) form_Mij.check(M63);
    if (M64) form_Mij.check(M64);
    if (M65) form_Mij.check(M65);
    if (M66) form_Mij.check(M66);
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
