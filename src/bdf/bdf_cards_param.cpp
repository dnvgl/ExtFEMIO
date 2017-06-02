/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF PARAM cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_param[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using bdf::types::entry_type;

bdf::types::card param::head = bdf::types::card("PARAM");

entry_type<std::string> param::form_N("N");
entry_type<long> param::form_IVAL("IVAL");
entry_type<double> param::form_RVAL("RVAL");
entry_type<std::string> param::form_CVAL("CVAL");
entry_type<complex<double> > param::form_CPLXVAL("CPLXVAL");

param::param() : card(), value_type(), IVAL(), RVAL(), CVAL(), CPLXVAL() {
}

param::param(std::string const &n) : param() {
    N = string::string(n).upper();
    this->param::check_data();
}

param::param(std::string &n, long ival) :
param(n) {
    IVAL = ival;
    this->param::check_data();
}

param::param(std::string &n, std::string &cval) :
param(n) {
    CVAL = cval;
    this->param::check_data();
}

param::param(std::string &n, double rval) :
param(n) {
    RVAL = rval;
    this->param::check_data();
}

param::param(std::string &n,
             double cplxval_r, double cplxval_i) :
             param(n) {
    CPLXVAL = complex<double>(cplxval_r, cplxval_i);
    this->param::check_data();
}

param::param(std::string &n, complex<double> &cplxval) :
param(n) {
    CPLXVAL = cplxval;
    this->param::check_data();
}

param::param(list<std::string> const &inp) :
card(inp) {
    this->param::read(inp);
}

cards::types param::card_type() const {
    return cards::types::PARAM;
}

void param::read(list<std::string> const &inp) {

    const bdf::types::entry_type<long> form_V_I("int val");
    const bdf::types::entry_type<double> form_V_R("double_val");
    const bdf::types::entry_type<std::string> form_V_C("char val");

    std::string tmp("");

    auto pos = inp.rbegin();

    switch (inp.size() - 1) {
    default:
        throw errors::parse_error("PARAM", "invalid number of arguments.");
    case 8:
        ++pos;
    case 7:
        ++pos;
    case 6:
        ++pos;
    case 5:
        ++pos;
    case 4:
        ++pos;
    case 3:
        tmp = string::string(*(pos++)).trim();
    case 2:
        try {
            if (tmp.length() > 0)
                form_CPLXVAL.set_value(CPLXVAL, *pos, tmp);
            else
                form_RVAL.set_value(RVAL, *pos);
        } catch (errors::float_error) {
            try {
                form_IVAL.set_value(IVAL, *pos);
                if (tmp.length() > 0)
                    throw errors::parse_error(
                    "PARAM", "Complex from int.");
            } catch (errors::int_error) {
                form_CVAL.set_value(CVAL, *pos);
                if (tmp.length() > 0)
                    throw errors::parse_error(
                    "PARAM", "Complex from char.");
            }
        }
        form_N.set_value(N, *(++pos));
    }
}

void param::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<std::string>(form_N, N)));

    if (IVAL)
        res.push_back(
            unique_ptr<format_entry>(format<long>(form_IVAL, IVAL)));
    else if (RVAL)
        res.push_back(
            unique_ptr<format_entry>(format<double>(form_RVAL, RVAL)));
    else if (CVAL)
        res.push_back(
            unique_ptr<format_entry>(format<std::string>(form_CVAL, CVAL)));
    else if (CPLXVAL)
        res.push_back(
            unique_ptr<format_entry>(
                format<complex<double>>(form_CPLXVAL, CPLXVAL)));
    else
        throw errors::output_error("PARAM", "no output value.");
}

void param::check_data() {
    if(N) param::form_N.check(N);
    if(IVAL) param::form_IVAL.check(IVAL);
    if(RVAL) param::form_RVAL.check(RVAL);
    if(CVAL) param::form_CVAL.check(CVAL);
    if(CPLXVAL) param::form_CPLXVAL.check(CPLXVAL);
}

cards::__base::card const &cards::param::operator() (
    list<std::string> const &inp) {
    this->param::read(inp);
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
