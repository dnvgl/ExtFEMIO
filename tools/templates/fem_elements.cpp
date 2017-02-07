/*
   #####     #    #     # ####### ### ####### #     # ###
  #     #   # #   #     #    #     #  #     # ##    # ###
  #        #   #  #     #    #     #  #     # # #   # ###
  #       #     # #     #    #     #  #     # #  #  #  #
  #       ####### #     #    #     #  #     # #   # #
  #     # #     # #     #    #     #  #     # #    ## ###
   #####  #     #  #####     #    ### ####### #     # ###

   Automatically generated source file. Contact author if changes are
   required.
 */

/**
   \file fem/fem_elements.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for FEM elements.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
   char const cID_fem_elements[] _EXTFEMIO_UNUSED =
       "@(#) $Id$";
}

#include <memory>

#include "my_c++14.h"
#include "fem/cards.h"
#include "fem/elements.h"
#include "fem/errors.h"

#if defined(__AFX_H__) & defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if defined(_MSC_VER) & _MSC_VER < 1900
#define NOEXCEPT
#else
#define NOEXCEPT noexcept
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace elements;

void elements::dispatch(
    unique_ptr<elements::__base::elem> &res, cards::gelmnt1 const *data) {

    switch (data->ELTYP) {
    {% for e in enum -%}
    case el_types::{{ e[0]|upper() }}:
        res = make_unique<{{ e[0]|lower() }}>(data); break;
    {% endfor %}case el_types::UNDEFINED:
        res = make_unique<undef>(); break;
    case el_types::INVALID:
        throw errors::parse_error("GELMNT1", "invalid element type"); break;
    };
{% line %}
}

std::string dnvgl::extfem::fem::elements::name_elem(el_types const type) {
    switch (type) {
    {% for e in enum %}case el_types::{{ e[0]|upper() }}: return "{{ e[0]|upper() }}";
    {% endfor %}case el_types::UNDEFINED: return "UNDEFINED";
{% line %}
    case el_types::INVALID: return "INVALID";
    }
    return "";
};

undef::undef(void) {}

long undef::nnodes(void) const {return -1;}

el_types undef::get_type(void) const {return el_types::UNDEFINED;}

elements::__base::elem::elem(void) :
    eleno(-1), elident(-1), el_add(-1), nodes({}), matref(-1), add_no(-1),
    intno(-1), mass_intno(-1), i_strain_ref(-1), i_stress_ref(-1),
    strpoint_ref(-1), section({}), fixations({}), eccentrities({}),
    csys({}) {}

elements::__base::elem::elem(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        eleno(get_eleno(eleno)), elident(get_elident(elident)), el_add(el_add),
        nodes(nodes), matref(matref), add_no(add_no), intno(intno),
        mass_intno(mass_intno), i_strain_ref(i_strain_ref),
        i_stress_ref(i_stress_ref), strpoint_ref(strpoint_ref),
        section(section), fixations(fixations), eccentrities(eccentrities),
        csys(csys) { }

elements::__base::elem::elem(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        elem(eleno, 0, el_add, nodes, matref, add_no, intno,
             mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
             section, fixations, eccentrities, csys) { }

elements::__base::elem::elem(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        elem(0, 0, el_add, nodes, matref, add_no, intno,
             mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
             section, fixations, eccentrities, csys) {}

elements::__base::elem::elem(cards::gelmnt1 const *data) :
    eleno(0), elident(0), matref(-1), add_no(0),
    intno(0), mass_intno(0), i_strain_ref(0),
    i_stress_ref(0), strpoint_ref(0),
    section(), fixations(), eccentrities(),
    csys() {
    this->add(data);
}

elements::__base::elem::elem(cards::gelref1 const *data) :
    eleno(0), elident(0), el_add(0), nodes() {
    this->add(data);
}

elements::__base::elem::elem(elem const *data) {
    this->eleno = data->eleno;
    this->elident = data->elident;
    this->el_add = data->el_add;
    this->nodes = data->nodes;
    this->matref = data->matref;
    this->add_no = data->add_no;
    this->intno = data->intno;
    this->mass_intno = data->mass_intno;
    this->i_strain_ref = data->i_strain_ref;
    this->i_stress_ref = data->i_stress_ref;
    this->strpoint_ref = data->strpoint_ref;
    this->section = data->section;
    this->fixations = data->fixations;
    this->eccentrities = data->eccentrities;
    this->csys = data->csys;
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) {
    return set_values(get_eleno(eleno), get_elident(elident), el_add, nodes,
                      matref, add_no, intno, mass_intno, i_strain_ref,
                      i_stress_ref, strpoint_ref, section, fixations,
                      eccentrities, csys);
}

elements::__base::elem::~elem(void) {
    section.clear();
    fixations.clear();
    eccentrities.clear();
    csys.clear();
}

/** Set attribute values for new element representation. No value
    checking.
 */
elements::__base::elem const &elements::__base::elem::set_values(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) {
    this->eleno = eleno;
    this->elident = elident;
    this->el_add = el_add;
    this->nodes = nodes;
    this->matref = matref;
    this->add_no = add_no;
    this->intno = intno;
    this->mass_intno = mass_intno;
    this->i_strain_ref = i_strain_ref;
    this->i_stress_ref = i_stress_ref;
    this->strpoint_ref = strpoint_ref;
    this->section = section;
    this->fixations = fixations;
    this->eccentrities = eccentrities;
    this->csys = csys;
    return *this;
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) {
    return (*this)(eleno, 0, el_add, nodes, matref, add_no, intno,
                   mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) {
    return (*this)(0, 0, el_add, nodes, matref, add_no, intno, mass_intno,
                   i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const eleno, vector<long> const &nodes, long const matref,
    vector<long> const &section/*={}*/, long const el_add/*=0*/,
    long const add_no/*=0*/, long const intno/*=0*/,
    long const mass_intno/*=0*/, long const i_strain_ref/*=0*/,
    long const i_stress_ref/*=0*/, long const strpoint_ref/*=0*/,
    vector<long> const &fixations/*={}*/,
    vector<long> const &eccentrities/*={}*/, vector<long> const &csys/*={}*/) {
    throw not_implemented(__FILE__, __LINE__);
    return *this;
}

elements::__base::elem const &elements::__base::elem::operator() (
    vector<long> const &nodes, long const matref,
    vector<long> const &section/*={}*/, vector<long> const &fixations/*={}*/,
    vector<long> const &eccentrities/*={}*/, long const el_add/*=0*/,
    long const add_no/*=0*/, long const intno/*=0*/,
    long const mass_intno/*=0*/, long const i_strain_ref/*=0*/,
    long const i_stress_ref/*=0*/, long const strpoint_ref/*=0*/,
    vector<long> const &csys/*={}*/) {
    return (*this)(0, 0, el_add, nodes, matref, add_no,
                   intno, mass_intno, i_strain_ref, i_stress_ref,
                   strpoint_ref, section, fixations, eccentrities, csys);
}

long elements::__base::elem::get_eleno(long const eleno) {
    long res{eleno};
    if (eleno == 0 || !used_nos.insert(eleno).second)
        res = get_eleno();
    return res;
}

long const elements::__base::elem::get_eleno(void) {
    do {;} while (used_nos.find(++max_no) != used_nos.end());
    used_nos.insert(max_no);
    return max_no;
}

long elements::__base::elem::get_elident(long const elident) {
    long res{elident};
    if (elident == 0 || !used_ids.insert(elident).second)
        res = get_elident();
    return res;
}

long const elements::__base::elem::get_elident(void) {
    do {;} while (used_ids.find(++max_id) != used_ids.end());
    used_ids.insert(max_id);
    return max_id;
}

void elements::__base::elem::add(cards::gelmnt1 const *data) {
    this->eleno = get_eleno(data->ELNOX);
    if (this->elident == 0)
        this->elident = get_elident(data->ELNO);
    else if (this->elident > 0 && this->elident != data->ELNO)
        throw dnvgl::extfem::fem::errors::data_not_matching_id(
            this->elident, data->ELNO);
    this->el_add = data->ELTYAD;
    this->nodes = data->NODIN;
}

void elements::__base::elem::add(cards::gelref1 const *data) {
    if (this->elident == 0)
        this->elident = get_elident(data->ELNO);
    else if (this->elident > 0 && this->elident != data->ELNO)
        throw dnvgl::extfem::fem::errors::data_not_matching_id(
            this->elident, data->ELNO);
    this->matref = data->MATNO;
    this->add_no = data->ADDNO;
    this->intno = data->INTNO;
    this->mass_intno = data->MINTNO;
    this->i_strain_ref = data->STRANO;
    this->i_stress_ref = data->STRENO;
    this->strpoint_ref = data->STREPONO;
    if (data->GEONO_OPT == -1)
        this->section = data->GEONO;
    else if (data->GEONO_OPT != 0)
        this->section.push_back(data->GEONO_OPT);
    if (data->FIXNO_OPT == -1)
        this->fixations = data->FIXNO;
    else if (data->FIXNO_OPT != 0)
        this->fixations.push_back(data->FIXNO_OPT);
    if (data->ECCNO_OPT == -1)
        this->eccentrities = data->ECCNO;
    else if (data->ECCNO_OPT != 0)
        this->eccentrities.push_back(data->ECCNO_OPT);
    if (data->TRANSNO_OPT == -1)
        this->csys = data->TRANSNO;
    else if (data->TRANSNO_OPT != 0)
        this->csys.push_back(data->TRANSNO_OPT);
}

cards::__base::card const &elements::__base::elem::gelmnt1(void) const {
    return d_gelmnt1(
        this->eleno,   // ELNOX
        this->elident, // ELNO
        this->get_type(),
        this->el_add,  // ELTYAD
        this->nodes);  // NODIN
}

cards::__base::card const &elements::__base::elem::gelref1(void) const {
    long geono_opt;
    long fixno_opt;
    long eccno_opt;
    long transno_opt;

    if (this->section.size() == 0) {
        geono_opt = 0;
    } else if (this->section.size() == 1) {
        geono_opt = this->section[0];
    } else {
        geono_opt = -1;
    }
    if (this->fixations.size() == 0) {
        fixno_opt = 0;
    } else if (this->fixations.size() == 1) {
        fixno_opt = this->fixations[0];
    } else {
        fixno_opt = -1;
    }
    if (this->eccentrities.size() == 0) {
        eccno_opt = 0;
    } else if (this->eccentrities.size() == 1) {
        eccno_opt = this->eccentrities[0];
    } else {
        eccno_opt = -1;
    }
    if (this->csys.size() == 0) {
        transno_opt = 0;
    } else if (this->csys.size() == 1) {
        transno_opt = this->csys[0];
    } else {
        transno_opt = -1;
    }

    return d_gelref1(
        this->elident,      // ELNO
        this->matref,       // MATNO
        this->add_no,       // ADDNO
        this->intno,        // INTNO;
        this->mass_intno,   // MINTNO;
        this->i_strain_ref, // STRANO;
        this->i_stress_ref, // STRENO;
        this->strpoint_ref, // STREPONO;
        geono_opt,
        fixno_opt,
        eccno_opt,
        transno_opt,
        this->section.size() > 1 ? this->section : vector<long>({}),
        this->fixations.size() > 1 ? this->fixations : vector<long>({}),
        this->eccentrities.size() > 1 ? this->eccentrities : vector<long>({}),
        this->csys.size() > 1 ? this->csys : vector<long>({}));
}

void elements::__base::elem::reset(void) {
    used_ids.clear();
    max_id = 0;
    used_nos.clear();
    max_no = 0;
}

cards::gelmnt1 elements::__base::elem::d_gelmnt1;
cards::gelref1 elements::__base::elem::d_gelref1;
set<long> elements::__base::elem::used_ids;
long elements::__base::elem::max_id(0);
set<long> elements::__base::elem::used_nos;
long elements::__base::elem::max_no(0);

undef::undef(cards::gelref1 const *data) :
    __base::elem(data) {}

ostream &operator<<(
    ostream &os, elements::__base::elem const &data) {
    if (data.elident < 0) return os;
    os << data.gelmnt1();
    os << data.gelref1();
    return os;
}

{%- for elem, vals in elements %}

/**
   \brief FEM element definition for {{ elem }}.

   {{ doc }}
*/
{% line %}

long {{ elem }}::nnodes(void) const {return {{ vals.nnodes }};}

el_types {{ elem }}::get_type(void) const {return el_types::{{ elem|upper() }};}

set<el_processor> const {{ elem }}::processors{
        {{ vals.procs|join(', ') }}
    };

{{ elem }}::{{ elem }}(void) : {{ vals.base }}() {}

{{ elem }}::{{ elem }}(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

{{ elem }}::{{ elem }}(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

{{ elem }}::{{ elem }}(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

{{ elem }}::{{ elem }}(cards::gelmnt1 const *data) : __base::elem(data) {}

{{ elem }}::{{ elem }}(cards::gelref1 const *data) : __base::elem(data) {}

{{ elem }}::{{ elem }}(elements::__base::elem const *data) :
         __base::elem(data) {}{% endfor %}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
