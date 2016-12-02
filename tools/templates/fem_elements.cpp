/*
   #####     #    #     # #######   ###   ####### #     #   ###
  #     #   # #   #     #    #       #    #     # ##    #   ###
  #        #   #  #     #    #       #    #     # # #   #   ###
  #       #     # #     #    #       #    #     # #  #  #    #
  #       ####### #     #    #       #    #     # #   # #
  #     # #     # #     #    #       #    #     # #    ##   ###
   #####  #     #  #####     #      ###   ####### #     #   ###

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

{% line %}

// ID:
namespace {
   char const cID_fem_elements[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
       = "@(#) $Id$";
}

#include <memory>

#include "my_c++14.h"
#include "fem/cards.h"
#include "fem/elements.h"

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

class NotImplemented : public logic_error {
protected:
    std::string what_arg;
    virtual const char *what() const NOEXCEPT {
        return what_arg.c_str();
    };
public:
    NotImplemented(std::string const &fname, long const &line) :
        logic_error("") {
        ostringstream res;
        res << "Not implemented yet " << fname << ":" << line << endl;
        this->what_arg = res.str();
    };
};

class NoUsed : public invalid_argument {
protected:
    std::string what_arg;
    virtual const char *what() const NOEXCEPT {
        return what_arg.c_str();
    };
public:
    NoUsed(long const &no) : invalid_argument("") {
        ostringstream res;
        res << "Element number " << no << " already used." << endl;
        this->what_arg = res.str();
    };
};

class IdUsed : public invalid_argument {
protected:
    std::string what_arg;
    virtual const char *what() const NOEXCEPT {
        return what_arg.c_str();
    };
public:
    IdUsed(long const &id) : invalid_argument("") {
        ostringstream res;
        res << "Element id " << id << " already used." << endl;
        this->what_arg = res.str();
    };
};

class DataNotMatchingId : public invalid_argument {
protected:
    std::string what_arg;
    virtual const char *what() const NOEXCEPT {
        return what_arg.c_str();
    };
public:
    DataNotMatchingId(long const &id_ex, long const &id_new) :
        invalid_argument("") {
        ostringstream res;
        res << "Element id already set to " << id_ex
            << " with attempt to set to " << id_new << "."<< endl;
        this->what_arg = res.str();
    };
};

using namespace dnvgl::extfem;
using namespace fem;
using namespace elements;

void elements::dispatch(
    unique_ptr<elements::__base::elem> &res, cards::gelmnt1 const *data) {

    switch (data->ELTYP) {
        {% for e in enum -%}
    case el_types::{{ e[0]|upper() }}:
    res = make_unique<{{ e[0]|lower() }}>(data); break;
    {% endfor %}   case el_types::UNDEFINED: res = make_unique<undef>(); break;
    case el_types::INVALID: throw errors::parse_error(
        "GELMNT1", "invalid element type"); break;
    };
    {% line %}
}

std::string dnvgl::extfem::fem::elements::name_elem(el_types const &type) {
    switch (type) {
        {% for e in enum %}   case el_types::{{ e[0]|upper() }}: return "{{ e[0]|upper() }}";
        {% endfor %}   case el_types::UNDEFINED: return "UNDEFINED";
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

elements::__base::elem::elem(long const &eleno,
                             long const &elident,
                             long const &el_add,
                             vector<long> const &nodes,
                             long const &matref,
                             long const &add_no,
                             long const &intno,
                             long const &mass_intno,
                             long const &i_strain_ref,
                             long const &i_stress_ref,
                             long const &strpoint_ref,
                             vector<long> const &section,
                             vector<long> const &fixations,
                             vector<long> const &eccentrities,
                             vector<long> const &csys) :
    eleno(eleno), elident(elident), el_add(el_add),
    nodes(nodes), matref(matref), add_no(add_no),
    intno(intno), mass_intno(mass_intno),
    i_strain_ref(i_strain_ref),
    i_stress_ref(i_stress_ref),
    strpoint_ref(strpoint_ref),
    section(section), fixations(fixations),
    eccentrities(eccentrities), csys(csys) {
    if (!used_nos.insert(eleno).second)
        throw NoUsed(eleno);
    if (!used_ids.insert(elident).second)
        throw IdUsed(elident);
}

elements::__base::elem::elem(long const &eleno,
                             long const &el_add,
                             vector<long> const &nodes,
                             long const &matref,
                             long const &add_no,
                             long const &intno,
                             long const &mass_intno,
                             long const &i_strain_ref,
                             long const &i_stress_ref,
                             long const &strpoint_ref,
                             vector<long> const &section,
                             vector<long> const &fixations,
                             vector<long> const &eccentrities,
                             vector<long> const &csys) :
        elem(eleno, get_elident(), el_add, nodes, matref, add_no, intno,
             mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
             section, fixations, eccentrities, csys) {
}

elements::__base::elem::elem(long const &el_add,
                             vector<long> const &nodes,
                             long const &matref,
                             long const &add_no,
                             long const &intno,
                             long const &mass_intno,
                             long const &i_strain_ref,
                             long const &i_stress_ref,
                             long const &strpoint_ref,
                             vector<long> const &section,
                             vector<long> const &fixations,
                             vector<long> const &eccentrities,
                             vector<long> const &csys) :
        elem(get_eleno(), el_add, nodes, matref, add_no, intno,
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
    long const &eleno,
    long const &elident,
    long const &el_add,
    vector<long> const &nodes,
    long const &matref,
    long const &add_no,
    long const &intno,
    long const &mass_intno,
    long const &i_strain_ref,
    long const &i_stress_ref,
    long const &strpoint_ref,
    vector<long> const &section,
    vector<long> const &fixations,
    vector<long> const &eccentrities,
    vector<long> const &csys) {
    if (!used_nos.insert(eleno).second)
        throw NoUsed(eleno);
    this->eleno = eleno;
    if (!used_ids.insert(elident).second)
        throw IdUsed(elident);
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
    long const &eleno,
    long const &el_add,
    vector<long> const &nodes,
    long const &matref,
    long const &add_no,
    long const &intno,
    long const &mass_intno,
    long const &i_strain_ref,
    long const &i_stress_ref,
    long const &strpoint_ref,
    vector<long> const &section,
    vector<long> const &fixations,
    vector<long> const &eccentrities,
    vector<long> const &csys) {
    long id(get_elident());
    return (*this)(eleno, id, el_add, nodes, matref, add_no, intno,
                   mass_intno, i_strain_ref, i_stress_ref, strpoint_ref, section,
                   fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const &eleno,
    vector<long> const &nodes,
    long const &matref,
    long const &add_no,
    long const &intno,
    long const &mass_intno,
    long const &i_strain_ref,
    long const &i_stress_ref,
    long const &strpoint_ref,
    vector<long> const &section,
    vector<long> const &fixations,
    vector<long> const &eccentrities,
    vector<long> const &csys) {
    return (*this)(eleno, get_elident(), 0, nodes, matref, add_no,
                   intno, mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const &elno,
    vector<long> const &nodes,
    long const &matref,
    vector<long> const &sections/*={}*/,
    long const &el_add/*=0*/,
    long const &add_no/*=0*/,
    long const &intno/*=0*/,
    long const &mass_intno/*=0*/,
    long const &i_strain_ref/*=0*/,
    long const &i_stress_ref/*=0*/,
    long const &strpoint_ref/*=0*/,
    vector<long> const &fixations/*={}*/,
    vector<long> const &eccentrities/*={}*/,
    vector<long> const &csys/*={}*/) {
    throw NotImplemented(__FILE__, __LINE__);
    return *this;
}

elements::__base::elem const &elements::__base::elem::operator() (
    vector<long> const &nodes,
    long const &matref,
    vector<long> const &sections/*={}*/,
    vector<long> const &fixations/*={}*/,
    vector<long> const &eccentrities/*={}*/,
    long const &el_add/*=0*/,
    long const &add_no/*=0*/,
    long const &intno/*=0*/,
    long const &mass_intno/*=0*/,
    long const &i_strain_ref/*=0*/,
    long const &i_stress_ref/*=0*/,
    long const &strpoint_ref/*=0*/,
    vector<long> const &csys/*={}*/) {
    this->eleno = get_eleno();
    this->elident = get_elident();
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

long const &elements::__base::elem::get_eleno(long const &eleno) {
    max_no = eleno == 0 ? max_no : eleno;
    if (max_no == 0)
        do {;} while (used_ids.find(++max_no) != used_ids.end());
    return max_no;
}

long const &elements::__base::elem::get_elident(long const &elident) {
    max_id = elident == 0 ? max_id : elident;
    if (max_id == 0)
        do {;} while (used_nos.find(++max_id) != used_nos.end());
    return max_id;
}

void elements::__base::elem::add(cards::gelmnt1 const *data) {
    if (!used_nos.insert(data->ELNOX).second)
        throw NoUsed(data->ELNOX);
    this->eleno = data->ELNOX;
    if (this->elident == 0) {
        if (!used_ids.insert(data->ELNO).second)
            throw IdUsed(data->ELNO);
        this->elident = data->ELNO;
    } else if (this->elident != data->ELNO)
        throw DataNotMatchingId(this->elident, data->ELNO);
    this->el_add = data->ELTYAD;
    this->nodes = data->NODIN;
}

void elements::__base::elem::add(cards::gelref1 const *data) {
    if (this->elident == 0) {
        if (!used_ids.insert(data->ELNO).second)
            throw IdUsed(data->ELNO);
        this->elident = data->ELNO;
    } else if (this->elident != data->ELNO)
        throw DataNotMatchingId(this->elident, data->ELNO);
    this->elident = data->ELNO;
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

namespace dnvgl {
    namespace extfem {
        namespace fem {
            namespace elements {
                namespace __base {
                    ostream &operator<<(
                        ostream &os, elements::__base::elem const &data) {
                        if (data.elident < 0) return os;
                        os << data.gelmnt1();
                        os << data.gelref1();
                        return os;
                    }
                }
            }
        }
    }
}

/**
   \brief FEM element definition for fem_thin_shell.

   Flat Quadrilateral/Triangular Thin Shell / Free Formulation
   Quadrilateral/Triangular Shell
*/

elements::__base::fem_thin_shell::fem_thin_shell(void) :
    elem() {}

elements::__base::fem_thin_shell::fem_thin_shell(
    long const &elno,
    long const &elident,
    long const &el_add,
    vector<long> const &nodes,
    long const &matref,
    long const &add_no,
    long const &intno,
    long const &mass_intno,
    long const &i_strain_ref,
    long const &i_stress_ref,
    long const &strpoint_ref,
    vector<long> const &sections,
    vector<long> const &fixations,
    vector<long> const &eccentrities,
    vector<long> const &csys) :
        elem(elno, elident, el_add, nodes, matref, add_no,
             intno, mass_intno, i_strain_ref, i_stress_ref,
             strpoint_ref, sections, fixations,
             eccentrities, csys) {}

elements::__base::fem_thin_shell::fem_thin_shell(
    long const &elno,
    long const &el_add,
    vector<long> const &nodes,
    long const &matref,
    long const &add_no,
    long const &intno,
    long const &mass_intno,
    long const &i_strain_ref,
    long const &i_stress_ref,
    long const &strpoint_ref,
    vector<long> const &sections,
    vector<long> const &fixations,
    vector<long> const &eccentrities,
    vector<long> const &csys) :
        fem_thin_shell(elno, get_elident(), el_add, nodes, matref, add_no,
                       intno, mass_intno, i_strain_ref, i_stress_ref,
                       strpoint_ref, sections, fixations,
                       eccentrities, csys) {}

elements::__base::fem_thin_shell::fem_thin_shell(
    long const &el_add,
    vector<long> const &nodes,
    long const &matref,
    long const &add_no,
    long const &intno,
    long const &mass_intno,
    long const &i_strain_ref,
    long const &i_stress_ref,
    long const &strpoint_ref,
    vector<long> const &sections,
    vector<long> const &fixations,
    vector<long> const &eccentrities,
    vector<long> const &csys) :
        fem_thin_shell(get_eleno(), el_add, nodes, matref, add_no,
                       intno, mass_intno, i_strain_ref, i_stress_ref,
                       strpoint_ref, sections, fixations,
                       eccentrities, csys) {}

elements::__base::fem_thin_shell::fem_thin_shell(cards::gelmnt1 const *data) :
    elem(data) {}

elements::__base::fem_thin_shell::fem_thin_shell(cards::gelref1 const *data) :
    elem(data) {}

elements::__base::fem_thin_shell::fem_thin_shell(__base::elem const *data) :
    elem(data) {}
{%- for elem, vals in elements %}

/**
   \brief FEM element definition for {{ elem }}.

   {{ doc }}
*/
{% line %}

namespace {
    size_t const {{ elem }}_procs_len = {{ vals.procs|length() }};
    el_processor {{ elem }}_procs[{{ elem }}_procs_len] = {
        {{ vals.procs|join(', ') }}
    };
}

long {{ elem }}::nnodes(void) const {return {{ vals.nnodes }};}

el_types {{ elem }}::get_type(void) const {return el_types::{{ elem|upper() }};}

set<el_processor> const {{ elem }}::processors(
    {{ elem }}_procs, {{ elem }}_procs+{{ elem }}_procs_len);

{{ elem }}::{{ elem }}(void) : {{ vals.base }}() {}

{{ elem }}::{{ elem }}(long const &eleno,
                       long const &elident,
                       long const &el_add,
                       vector<long> const &nodes,
                       long const &matref,
                       long const &add_no,
                       long const &intno,
                       long const &mass_intno,
                       long const &i_strain_ref,
                       long const &i_stress_ref,
                       long const &strpoint_ref,
                       vector<long> const &section,
                       vector<long> const &fixations,
                       vector<long> const &eccentrities,
                       vector<long> const &csys) :
        {{ vals.base }}(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

{{ elem }}::{{ elem }}(long const &eleno,
                       long const &el_add,
                       vector<long> const &nodes,
                       long const &matref,
                       long const &add_no,
                       long const &intno,
                       long const &mass_intno,
                       long const &i_strain_ref,
                       long const &i_stress_ref,
                       long const &strpoint_ref,
                       vector<long> const &sections,
                       vector<long> const &fixations,
                       vector<long> const &eccentrities,
                       vector<long> const &csys) :
        {{ elem }}(
            eleno, get_elident(), el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, sections, fixations, eccentrities,
            csys) {}

{{ elem }}::{{ elem }}(long const &el_add,
                       vector<long> const &nodes,
                       long const &matref,
                       long const &add_no,
                       long const &intno,
                       long const &mass_intno,
                       long const &i_strain_ref,
                       long const &i_stress_ref,
                       long const &strpoint_ref,
                       vector<long> const &sections,
                       vector<long> const &fixations,
                       vector<long> const &eccentrities,
                       vector<long> const &csys) :
        {{ elem }}(
            get_eleno(), el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

{{ elem }}::{{ elem }}(cards::gelmnt1 const *data) : {{ vals.base }}(data) {}

{{ elem }}::{{ elem }}(cards::gelref1 const *data) : {{ vals.base }}(data) {}

{{ elem }}::{{ elem }}(elements::__base::elem const *data) :
__base::{{ vals.base }}(data) {}{% endfor %}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
