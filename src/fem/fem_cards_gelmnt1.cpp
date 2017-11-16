/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELMNT1` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_fem_cards_gelmnt1[]) =
        "@(#) $Id$";
}

#include <unordered_map>

#include "fem/cards.h"
#include "fem/types.h"

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
using namespace fem;
using namespace cards;
using namespace types;

const unordered_map<long, const elements::el_types>
gelmnt1::eltyp_map({
        {2, elements::el_types::BEPS},
        {3, elements::el_types::CSTA},
        {5, elements::el_types::RPBQ},
        {6, elements::el_types::ILST},
        {8, elements::el_types::IQQE},
        {9, elements::el_types::LQUA},
        {10, elements::el_types::TESS},
        {11, elements::el_types::GMAS},
        {12, elements::el_types::GLMA},
        {13, elements::el_types::GLDA},
        {15, elements::el_types::BEAS},
        {16, elements::el_types::AXIS},
        {17, elements::el_types::AXDA},
        {18, elements::el_types::GSPR},
        {19, elements::el_types::GDAM},
        {20, elements::el_types::IHEX},
        {21, elements::el_types::LHEX},
        {22, elements::el_types::SECB},
        {23, elements::el_types::BTSS},
        {24, elements::el_types::FQUS_FFQ},
        {25, elements::el_types::FTRS_FFTR},
        {26, elements::el_types::SCTS},
        {27, elements::el_types::MCTS},
        {28, elements::el_types::SCQS},
        {29, elements::el_types::MCQS},
        {30, elements::el_types::IPRI},
        {31, elements::el_types::ITET},
        {32, elements::el_types::TPRI},
        {33, elements::el_types::TETR},
        {34, elements::el_types::LCTS},
        {35, elements::el_types::LCQS},
        {36, elements::el_types::TRS1},
        {37, elements::el_types::TRS2},
        {38, elements::el_types::TRS3},
        {40, elements::el_types::GLSH},
        {41, elements::el_types::AXCS},
        {42, elements::el_types::AXLQ},
        {43, elements::el_types::AXLS},
        {44, elements::el_types::AXQQ},
        {45, elements::el_types::PILS},
        {46, elements::el_types::PCAB},
        {47, elements::el_types::PSPR},
        {48, elements::el_types::ADVA_4},
        {49, elements::el_types::ADVA_2},
        {51, elements::el_types::CTCP},
        {52, elements::el_types::CTCL},
        {53, elements::el_types::CTAL},
        {54, elements::el_types::CTCC},
        {55, elements::el_types::CTAQ},
        {56, elements::el_types::CTLQ},
        {57, elements::el_types::CTCQ},
        {58, elements::el_types::CTMQ},
        {61, elements::el_types::HCQS},
        {66, elements::el_types::SLQS},
        {67, elements::el_types::SLTS},
        {68, elements::el_types::SLCB},
        {70, elements::el_types::MATR},
        {100, elements::el_types::GHEX100},
        {101, elements::el_types::GHEX101},
        {102, elements::el_types::GHEX102},
        {103, elements::el_types::GHEX103},
        {104, elements::el_types::GHEX104},
        {105, elements::el_types::GHEX105},
        {106, elements::el_types::GHEX106},
        {107, elements::el_types::GHEX107},
        {108, elements::el_types::GHEX108},
        {109, elements::el_types::GHEX109},
        {110, elements::el_types::GHEX110},
        {111, elements::el_types::GHEX111},
        {112, elements::el_types::GHEX112},
        {113, elements::el_types::GHEX113},
        {114, elements::el_types::GHEX114},
        {115, elements::el_types::GHEX115},
        {116, elements::el_types::GHEX116},
        {117, elements::el_types::GHEX117},
        {118, elements::el_types::GHEX118},
        {119, elements::el_types::GHEX119},
        {120, elements::el_types::GHEX120},
        {121, elements::el_types::GHEX121},
        {122, elements::el_types::GHEX122},
        {123, elements::el_types::GHEX123},
        {124, elements::el_types::GHEX124},
        {125, elements::el_types::GHEX125},
        {126, elements::el_types::GHEX126},
        {127, elements::el_types::GHEX127},
        {128, elements::el_types::GHEX128},
        {129, elements::el_types::GHEX129},
        {130, elements::el_types::GHEX130},
        {131, elements::el_types::GHEX131},
        {132, elements::el_types::GHEX132},
        {133, elements::el_types::GHEX133},
        {134, elements::el_types::GHEX134},
        {135, elements::el_types::GHEX135},
        {136, elements::el_types::GHEX136},
        {137, elements::el_types::GHEX137},
        {138, elements::el_types::GHEX138},
        {139, elements::el_types::GHEX139},
        {140, elements::el_types::GHEX140},
        {141, elements::el_types::GHEX141},
        {142, elements::el_types::GHEX142},
        {143, elements::el_types::GHEX143},
        {144, elements::el_types::GHEX144},
        {145, elements::el_types::GHEX145},
        {146, elements::el_types::GHEX146},
        {147, elements::el_types::GHEX147},
        {148, elements::el_types::GHEX148},
        {149, elements::el_types::GHEX149},
        {150, elements::el_types::GHEX150},
        {151, elements::el_types::GHEX151},
        {152, elements::el_types::GHEX152},
        {153, elements::el_types::GHEX153},
        {154, elements::el_types::GHEX154},
        {155, elements::el_types::GHEX155},
        {156, elements::el_types::GHEX156},
        {157, elements::el_types::GHEX157},
        {158, elements::el_types::GHEX158},
        {159, elements::el_types::GHEX159},
        {160, elements::el_types::GHEX160},
        {161, elements::el_types::GHEX161},
        {162, elements::el_types::GHEX162},
        {163, elements::el_types::GHEX163}});

const card gelmnt1::head("GELMNT1");

const entry_type<long> gelmnt1::_form_ELNOX("ELNOX");
const entry_type<long> gelmnt1::_form_ELNO("ELNO");
const entry_type<long> gelmnt1::_form_ELTYP("ELTYP");
const entry_type<long> gelmnt1::_form_ELTYAD("ELTYAD");
const entry_type<long> gelmnt1::_form_NODIN("NODIN");

gelmnt1::gelmnt1(const vector<std::string> &inp, size_t const len) :
        card(types::GELMNT1) {
    gelmnt1::read(inp, len);
}

void gelmnt1::read(const vector<std::string> &inp, size_t const len) {
    std::string static const empty(16, ' ');

    if (len < 6)
        throw errors::parse_error(
            "GELMNT1", "Illegal number of entries.");

    ELNOX = _form_ELNOX(inp.at(1));
    ELNO = _form_ELNO(inp.at(2));
    long tmp{_form_ELTYP(inp.at(3))};
    try {
        ELTYP = eltyp_map.at(tmp);
    } catch (out_of_range) {
        errors::parse_error(
            "gelmnt1", "wrong element type");
    }
    ELTYAD = _form_ELTYAD(inp.at(4));
    size_t i{4};
    while (++i < len && inp.at(i) != empty) {
        tmp = _form_NODIN(inp[i]);
        if (tmp == 0) break;
        NODIN.push_back(tmp);
    }
}

gelmnt1::gelmnt1() : gelmnt1(-1, 0, elements::el_types::INVALID, {}) {}

gelmnt1::gelmnt1(long const ELNOX,
                 long const ELNO,
                 elements::el_types const &ELTYP,
                 long const ELTYAD,
                 vector<long> const &NODIN) :
        card(types::GELMNT1),
        ELNOX(ELNOX), ELNO(ELNO), ELTYP(ELTYP), ELTYAD(ELTYAD),
        NODIN(NODIN) {}

gelmnt1::gelmnt1(long const ELNOX,
                 long const ELNO,
                 elements::el_types const &ELTYP,
                 vector<long> const &NODIN) :
        gelmnt1(ELNOX, ELNO, ELTYP, 0, NODIN) {}

cards::__base::card const &gelmnt1::operator() (
    long const ELNOX,
    long const ELNO,
    elements::el_types const &ELTYP,
    long const ELTYAD,
    vector<long> const &NODIN) {
    this->ELNOX = ELNOX;
    this->ELNO = ELNO;
    this->ELTYP = ELTYP;
    this->ELTYAD = ELTYAD;
    this->NODIN = NODIN;
    return *this;
}

cards::__base::card const &gelmnt1::operator() (
    long const ELNOX,
    long const ELNO,
    elements::el_types const &ELTYP,
    vector<long> const &NODIN) {
    return (*this)(ELNOX, ELNO, ELTYP, 0, NODIN);
}

ostream &gelmnt1::put(ostream& os) const {
    if (ELTYP == elements::el_types::INVALID) return os;
    os << head.format()
       << _form_ELNOX.format(ELNOX)
       << _form_ELNO.format(ELNO)
       << _form_ELTYP.format(static_cast<long>(ELTYP))
       << _form_ELTYAD.format(ELTYAD);
    long i = 0;
    for (auto p : NODIN) {
        if (!(i++ % 4))
            os << endl << fem::types::card().format();
        os << _form_NODIN.format(p);
    }
    return os << endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
