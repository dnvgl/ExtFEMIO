/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELREF1` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_fem_cards_gelref1[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/types.h"
#include "fem/errors.h"

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

card const gelref1::head("GELREF1");

entry_type<long> const gelref1::_form_ELNO("ELNO");
entry_type<long> const gelref1::_form_MATNO("MATNO");
entry_type<long> const gelref1::_form_ADDNO("ADDNO");
entry_type<long> const gelref1::_form_INTNO("INTNO");
entry_type<long> const gelref1::_form_MINTNO("MINTNO");
entry_type<long> const gelref1::_form_STRANO("STRANO");
entry_type<long> const gelref1::_form_STRENO("STRENO");
entry_type<long> const gelref1::_form_STREPONO("STREPONO");
entry_type<long> const gelref1::_form_GEONO_OPT("GEONO_OPT");
entry_type<long> const gelref1::_form_FIXNO_OPT("FIXNO_OPT");
entry_type<long> const gelref1::_form_ECCNO_OPT("ECCNO_OPT");
entry_type<long> const gelref1::_form_TRANSNO_OPT("TRANSNO_OPT");
entry_type<long> const gelref1::_form_GEONO("GEONO");
entry_type<long> const gelref1::_form_FIXNO("FIXNO");
entry_type<long> const gelref1::_form_ECCNO("ECCNO");
entry_type<long> const gelref1::_form_TRANSNO("TRANSNO");

gelref1::gelref1(const vector<std::string> &inp, size_t const len) :
        GEONO(0), FIXNO(0), ECCNO(0), TRANSNO(0) {
    this->gelref1::read(inp, len);
}

void gelref1::read(const vector<std::string> &inp, size_t const len) {
    std::string static const empty{"                "};
    if (len < 13)
        throw errors::parse_error(
            "GELREF1", "Illegal number of entries.");

    vector<std::string> static node_vals;
    entry_type<long> static const lval("lval");

    size_t nvals{0}, ind_offset{0};

    ELNO = _form_ELNO(inp.at(1));
    MATNO = _form_MATNO(inp.at(2));
    ADDNO = _form_ADDNO(inp.at(3));
    INTNO = _form_INTNO(inp.at(4));
    MINTNO = _form_MINTNO(inp.at(5));
    STRANO = _form_STRANO(inp.at(6));
    STRENO = _form_STRENO(inp.at(7));
    STREPONO = _form_STREPONO(inp.at(8));
    GEONO_OPT = _form_GEONO_OPT(inp.at(9));
    if (GEONO_OPT == -1) nvals += 1;
    FIXNO_OPT = _form_FIXNO_OPT(inp.at(10));
    if (FIXNO_OPT == -1) nvals += 1;
    ECCNO_OPT = _form_ECCNO_OPT(inp.at(11));
    if (ECCNO_OPT == -1) nvals += 1;
    TRANSNO_OPT = _form_TRANSNO_OPT(inp.at(12));
    if (TRANSNO_OPT == -1) nvals += 1;

    size_t i{12};
    size_t num_vals{0};
    while (++i < len && inp.at(i) != empty) {
        long const tmp{lval(inp[i])};
        if (tmp == 0) break;
        try {
            node_vals.at(num_vals).assign(inp[i]);
        } catch (out_of_range) {
            node_vals.emplace_back(inp[i]);
        }
        num_vals++;
    };

    if (num_vals > 0) {
        auto const divmod = ldiv(static_cast<long>(num_vals), static_cast<long>(nvals));
        if (divmod.rem != 0)
            throw errors::parse_error(
                "GELREF1", "Number of node values is not "
                "as required.");

        if (GEONO_OPT == -1) {
            for (size_t i1{0}; i1 < static_cast<size_t>(divmod.quot); i1++)
                GEONO.push_back(_form_GEONO(node_vals[i1]));
            ind_offset = nvals;
        }
        if (FIXNO_OPT == -1) {
            for (size_t i2{0}; i2 < static_cast<size_t>(divmod.quot); i2++)
                FIXNO.push_back(_form_FIXNO(node_vals[i2+ind_offset]));
            ind_offset += nvals;
        }
        if (ECCNO_OPT == -1) {
            for (size_t i3{0}; i3 < static_cast<size_t>(divmod.quot); i3++)
                ECCNO.push_back(_form_ECCNO(node_vals[i3+ind_offset]));
            ind_offset += nvals;
        }
        if (TRANSNO_OPT == -1) {
            for (size_t i4{0}; i4 < static_cast<size_t>(divmod.quot); i4++)
                TRANSNO.push_back(_form_TRANSNO(node_vals[i4+ind_offset]));
        }
    }
}

gelref1::gelref1() : gelref1(-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             {}, {}, {}, {}) {}

gelref1::gelref1(
    long const ELNO, long const MATNO, long const ADDNO, long const INTNO,
    long const MINTNO, long const STRANO, long const STRENO,
    long const STREPONO, long const GEONO_OPT, long const FIXNO_OPT,
    long const ECCNO_OPT, long const TRANSNO_OPT, const vector<long> &GEONO,
    const vector<long> &FIXNO, const vector<long> &ECCNO,
    const vector<long> &TRANSNO) :
        card(),
        ELNO(ELNO), MATNO(MATNO), ADDNO(ADDNO), INTNO(INTNO),
        MINTNO(MINTNO), STRANO(STRANO), STRENO(STRENO),
        STREPONO(STREPONO), GEONO_OPT(GEONO_OPT),
        FIXNO_OPT(FIXNO_OPT), ECCNO_OPT(ECCNO_OPT),
        TRANSNO_OPT(TRANSNO_OPT) {

    size_t lmax = 0, lmin = 0;
    bool min_max_set = false;

    if (GEONO.size()) {
        min_max_set = true;
        lmin = lmax = GEONO.size();
        this->GEONO.resize(GEONO.size());
        copy(GEONO.begin(), GEONO.end(), this->GEONO.begin());
    }
    if (FIXNO.size()) {
        if (min_max_set) {
            lmin = lmin ? FIXNO.size() > lmin : FIXNO.size();
            lmax = lmax ? FIXNO.size() < lmax : FIXNO.size();
        } else {
            min_max_set = true;
            lmin = lmax = FIXNO.size();
        }
        this->FIXNO.resize(FIXNO.size());
        copy(FIXNO.begin(), FIXNO.end(), this->FIXNO.begin());
    }
    if (ECCNO.size()) {
        if (min_max_set) {
            lmin = lmin ? ECCNO.size() > lmin : ECCNO.size();
            lmax = lmax ? ECCNO.size() < lmax : ECCNO.size();
        } else {
            min_max_set = true;
            lmin = lmax = ECCNO.size();
        }
        this->ECCNO.resize(ECCNO.size());
        copy(ECCNO.begin(), ECCNO.end(), this->ECCNO.begin());
    }
    if (TRANSNO.size()) {
        if (min_max_set) {
            lmin = lmin ? TRANSNO.size() > lmin : TRANSNO.size();
            lmax = lmax ? TRANSNO.size() < lmax : TRANSNO.size();
        } else {
            lmin = lmax = TRANSNO.size();
        }
        this->TRANSNO.resize(TRANSNO.size());
        copy(TRANSNO.begin(), TRANSNO.end(), this->TRANSNO.begin());
    }

    if (lmin != lmax) {
        throw errors::usage_error(
            "GELREF1",
            "GEONO, FIXNO, ECCNO, and TRANSNO if not empty, have "
            "to be of same size");
    }
        }

cards::__base::card const &gelref1::operator() (
    long const ELNO, long const MATNO, long const ADDNO, long const INTNO,
    long const MINTNO, long const STRANO, long const STRENO,
    long const STREPONO, long const GEONO_OPT, long const FIXNO_OPT,
    long const ECCNO_OPT, long const TRANSNO_OPT,
    vector<long> const &GEONO/*={}*/, vector<long> const &FIXNO/*={}*/,
    vector<long> const &ECCNO/*={}*/, vector<long> const &TRANSNO/*={}*/) {
    this->ELNO = ELNO;
    this->MATNO = MATNO;
    this->ADDNO = ADDNO;
    this->INTNO = INTNO;
    this->MINTNO = MINTNO;
    this->STRANO = STRANO;
    this->STRENO = STRENO;
    this->STREPONO = STREPONO;
    this->GEONO_OPT = GEONO_OPT;
    this->FIXNO_OPT = FIXNO_OPT;
    this->ECCNO_OPT = ECCNO_OPT;
    this->TRANSNO_OPT = TRANSNO_OPT;

    size_t lmax = 0, lmin = 0;
    bool min_max_set = false;

    if (GEONO.size()) {
        min_max_set = true;
        lmin = lmax = GEONO.size();
        this->GEONO.resize(GEONO.size());
        copy(GEONO.begin(), GEONO.end(), this->GEONO.begin());
    }
    if (FIXNO.size()) {
        if (min_max_set) {
            lmin = lmin ? FIXNO.size() > lmin : FIXNO.size();
            lmax = lmax ? FIXNO.size() < lmax : FIXNO.size();
        } else {
            min_max_set = true;
            lmin = lmax = FIXNO.size();
        }
        this->FIXNO.resize(FIXNO.size());
        copy(FIXNO.begin(), FIXNO.end(), this->FIXNO.begin());
    }
    if (ECCNO.size()) {
        if (min_max_set) {
            lmin = lmin ? ECCNO.size() > lmin : ECCNO.size();
            lmax = lmax ? ECCNO.size() < lmax : ECCNO.size();
        } else {
            min_max_set = true;
            lmin = lmax = ECCNO.size();
        }
        this->ECCNO.resize(ECCNO.size());
        copy(ECCNO.begin(), ECCNO.end(), this->ECCNO.begin());
    }
    if (TRANSNO.size()) {
        if (min_max_set) {
            lmin = lmin ? TRANSNO.size() > lmin : TRANSNO.size();
            lmax = lmax ? TRANSNO.size() < lmax : TRANSNO.size();
        } else {
            lmin = lmax = TRANSNO.size();
        }
        this->TRANSNO.resize(TRANSNO.size());
        copy(TRANSNO.begin(), TRANSNO.end(), this->TRANSNO.begin());
    }

    if (lmin != lmax) {
        throw errors::usage_error(
            "GELREF1",
            "GEONO, FIXNO, ECCNO, and TRANSNO if not empty, have "
            "to be of same size");
    }
    return *this;
}

cards::types gelref1::card_type() const {
    return types::GELREF1;
}

ostream &gelref1::put(ostream& os) const {
    if (ELNO == -1) return os;
    os << head.format()
       << _form_ELNO.format(ELNO) << _form_MATNO.format(MATNO)
       << _form_ADDNO.format(ADDNO) << _form_INTNO.format(INTNO) << endl
       << fem::types::card().format()
       << _form_MINTNO.format(MINTNO) << _form_STRANO.format(STRANO)
       << _form_STRENO.format(STRENO) << _form_STREPONO.format(STREPONO) << endl
       << fem::types::card().format()
       << _form_GEONO_OPT.format(GEONO_OPT) << _form_FIXNO_OPT.format(FIXNO_OPT)
       << _form_ECCNO_OPT.format(ECCNO_OPT)
       << _form_TRANSNO_OPT.format(TRANSNO_OPT);

    size_t i = 0;
    for (auto p : GEONO) {
        if (!(i++ % 4))
            os << endl << fem::types::card().format();
        os << _form_GEONO.format(p);
    }
    for (auto p : FIXNO) {
        if (!(i++ % 4))
            os << endl << fem::types::card().format();
        os << _form_FIXNO.format(p);
    }
    for (auto p : ECCNO) {
        if (!(i++ % 4))
            os << endl << fem::types::card().format();
        os << _form_ECCNO.format(p);
    }
    for (auto p : TRANSNO) {
        if (!(i++ % 4))
            os << endl << fem::types::card().format();
        os << _form_TRANSNO.format(p);
    }
    return os << endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
