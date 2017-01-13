 /**
   \file bdf/bdf_header_case_control_echo.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implement output for CASE ECHO

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_echo[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#include <my_c++14.h>

#include "bdf/header.h"

using namespace std;

using namespace dnvgl::extfem::bdf::header::case_control;

echo::echo(std::list<echo::describer*> const &_oper) {
    if (_oper.size() > 0)
        for (const auto &p : _oper)
            oper.push_back(p);
    else
        oper.push_back(new echo::none());
}

echo::~echo(void) {
    for (const auto &p : oper)
        delete p;
    oper.clear();
}

std::ostream &echo::put(std::ostream &os) const {
    os << "ECHO = ";
    bool first = true;
    for (auto &p : this->oper) {
        if (first)
            first = false;
        else
            os << ", ";
        os << p->str();
    }
    return os << std::endl;
}

echo::describer::describer() {}

echo::describer::~describer() {}

echo::unsort::unsort() {}

std::string const echo::unsort::str() const {
    return "UNSORT";
}

echo::sort::sort(
    std::list<echo::sort::cdni_entry> const &cdni) :
        describer(), cdni(cdni) {}

std::string const echo::sort::str(void) const {
    std::list<echo::sort::cdni_entry> l_cdni(cdni);
    std::ostringstream res(
        "SORT(", std::ostringstream::ate);
    res << l_cdni.front().str();
    l_cdni.pop_front();
    for (auto p : l_cdni)
        res << ", " << p.str();
    res << ")";
    return res.str();
}

echo::sort::~sort(void) {
    cdni.clear();
}

echo::sort::cdni_entry::cdni_entry(
    std::string const &name, bool const except) :
        name(name), except(except) {}

echo::sort::cdni_entry::~cdni_entry(void) {}

std::string const echo::sort::cdni_entry::str(void) const {
    std::string res("");
    if (except)
        res += "EXCEPT ";
    return res + name;
}

echo::both::both() {}

std::string const echo::both::str(void) const {
    return "BOTH";
}

echo::none::none() {}

std::string const echo::none::str(void) const {
    return "NONE";
}

echo::punch::punch(std::list<option_type> const &options) :
        options(options) {}

std::string const echo::punch::str(void) const {
    std::ostringstream res(
        "PUNCH", std::ostringstream::ate);
    if (options.size() > 0) {
        res << "(";
        bool first = true;
        for (auto p : options) {
            if (!first) {
                res << ", ";
                first = false;
            }
            switch (p) {
            case echo::punch::option_type::SORT:
                res << "SORT";
                break;
            case echo::punch::option_type::BOTH:
                res << "BOTH";
                break;
            case echo::punch::option_type::NEWBULK:
                res << "NEWBULK";
            }
        }
        res << ")";
    }
    return res.str();
}

echo::file::file() {}

std::string const echo::file::str(void) const {
    return "FILE";
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
