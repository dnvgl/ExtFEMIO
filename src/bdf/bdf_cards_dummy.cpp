/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2018 by DNV GL SE
   \brief Dummy classes for BDF cards not supported.

   Detailed description
*/
#include "extfemio_stdafx.h"
#include "extfem_misc.h"

// ID:
namespace {
   char const cID_bdf_cards_dummy[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "bdf/cards.h"

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;

using bdf::types::entry_type;

cards::__base::__dummy::__dummy(const std::list<std::string> &inp) {
    this->read(inp);
}
cards::__base::card const
&cards::__base::__dummy::operator()(std::list<std::string> const &inp) {
    this->read(inp);
    return *this;
}
void cards::__base::__dummy::read(std::list<std::string> const &inp) {}
void cards::__base::__dummy::collect_outdata(std::list<std::unique_ptr<format_entry> >&) const {}
void cards::__base::__dummy::check_data() {}

cards::__base::__element_dummy::__element_dummy(const std::list<std::string> &inp) : element(inp) {}
cards::__base::card const
&cards::__base::__element_dummy::operator()(std::list<std::string> const &inp) {
    this->element::read(inp);
    return *this;
}
void cards::__base::__element_dummy::read(std::list<std::string> const &inp) {
    this->element::read(inp);
}
void cards::__base::__element_dummy::collect_outdata(
     std::list<std::unique_ptr<format_entry>> &str) const
{}
void cards::__base::__element_dummy::check_data() {}

bdf::types::card caabsf::head = bdf::types::card("CAABSF");
caabsf::caabsf(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caabsf::card_type() const {
    return cards::types::CAABSF;
}

bdf::types::card caero1::head = bdf::types::card("CAERO1");
caero1::caero1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caero1::card_type() const {
    return cards::types::CAERO1;
}

bdf::types::card caero2::head = bdf::types::card("CAERO2");
caero2::caero2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caero2::card_type() const {
    return cards::types::CAERO2;
}

bdf::types::card caero3::head = bdf::types::card("CAERO3");
caero3::caero3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caero3::card_type() const {
    return cards::types::CAERO3;
}

bdf::types::card caero4::head = bdf::types::card("CAERO4");
caero4::caero4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caero4::card_type() const {
    return cards::types::CAERO4;
}

bdf::types::card caero5::head = bdf::types::card("CAERO5");
caero5::caero5(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caero5::card_type() const {
    return cards::types::CAERO5;
}

bdf::types::card caxif2::head = bdf::types::card("CAXIF2");
caxif2::caxif2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caxif2::card_type() const {
    return cards::types::CAXIF2;
}

bdf::types::card caxif3::head = bdf::types::card("CAXIF3");
caxif3::caxif3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caxif3::card_type() const {
    return cards::types::CAXIF3;
}

bdf::types::card caxif4::head = bdf::types::card("CAXIF4");
caxif4::caxif4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types caxif4::card_type() const {
    return cards::types::CAXIF4;
}

bdf::types::card cbend::head = bdf::types::card("CBEND");
cbend::cbend(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cbend::card_type() const {
    return cards::types::CBEND;
}

bdf::types::card cbush1d::head = bdf::types::card("CBUSH1D");
cbush1d::cbush1d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cbush1d::card_type() const {
    return cards::types::CBUSH1D;
}

bdf::types::card cbutt::head = bdf::types::card("CBUTT");
cbutt::cbutt(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cbutt::card_type() const {
    return cards::types::CBUTT;
}

bdf::types::card cconeax::head = bdf::types::card("CCONEAX");
cconeax::cconeax(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cconeax::card_type() const {
    return cards::types::CCONEAX;
}

bdf::types::card ccrsfil::head = bdf::types::card("CCRSFIL");
ccrsfil::ccrsfil(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ccrsfil::card_type() const {
    return cards::types::CCRSFIL;
}

bdf::types::card cdamp1::head = bdf::types::card("CDAMP1");
cdamp1::cdamp1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp1::card_type() const {
    return cards::types::CDAMP1;
}

bdf::types::card cdamp1d::head = bdf::types::card("CDAMP1D");
cdamp1d::cdamp1d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp1d::card_type() const {
    return cards::types::CDAMP1D;
}

bdf::types::card cdamp2::head = bdf::types::card("CDAMP2");
cdamp2::cdamp2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp2::card_type() const {
    return cards::types::CDAMP2;
}

bdf::types::card cdamp2d::head = bdf::types::card("CDAMP2D");
cdamp2d::cdamp2d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp2d::card_type() const {
    return cards::types::CDAMP2D;
}

bdf::types::card cdamp3::head = bdf::types::card("CDAMP3");
cdamp3::cdamp3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp3::card_type() const {
    return cards::types::CDAMP3;
}

bdf::types::card cdamp4::head = bdf::types::card("CDAMP4");
cdamp4::cdamp4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp4::card_type() const {
    return cards::types::CDAMP4;
}

bdf::types::card cdamp5::head = bdf::types::card("CDAMP5");
cdamp5::cdamp5(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdamp5::card_type() const {
    return cards::types::CDAMP5;
}

bdf::types::card cdum1::head = bdf::types::card("CDUM1");
cdum1::cdum1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum1::card_type() const {
    return cards::types::CDUM1;
}

bdf::types::card cdum2::head = bdf::types::card("CDUM2");
cdum2::cdum2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum2::card_type() const {
    return cards::types::CDUM2;
}

bdf::types::card cdum3::head = bdf::types::card("CDUM3");
cdum3::cdum3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum3::card_type() const {
    return cards::types::CDUM3;
}

bdf::types::card cdum4::head = bdf::types::card("CDUM4");
cdum4::cdum4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum4::card_type() const {
    return cards::types::CDUM4;
}

bdf::types::card cdum5::head = bdf::types::card("CDUM5");
cdum5::cdum5(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum5::card_type() const {
    return cards::types::CDUM5;
}

bdf::types::card cdum6::head = bdf::types::card("CDUM6");
cdum6::cdum6(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum6::card_type() const {
    return cards::types::CDUM6;
}

bdf::types::card cdum7::head = bdf::types::card("CDUM7");
cdum7::cdum7(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum7::card_type() const {
    return cards::types::CDUM7;
}

bdf::types::card cdum8::head = bdf::types::card("CDUM8");
cdum8::cdum8(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum8::card_type() const {
    return cards::types::CDUM8;
}

bdf::types::card cdum9::head = bdf::types::card("CDUM9");
cdum9::cdum9(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cdum9::card_type() const {
    return cards::types::CDUM9;
}

bdf::types::card celas1::head = bdf::types::card("CELAS1");
celas1::celas1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types celas1::card_type() const {
    return cards::types::CELAS1;
}

bdf::types::card celas1d::head = bdf::types::card("CELAS1D");
celas1d::celas1d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types celas1d::card_type() const {
    return cards::types::CELAS1D;
}

bdf::types::card celas2::head = bdf::types::card("CELAS2");
celas2::celas2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types celas2::card_type() const {
    return cards::types::CELAS2;
}

bdf::types::card celas2d::head = bdf::types::card("CELAS2D");
celas2d::celas2d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types celas2d::card_type() const {
    return cards::types::CELAS2D;
}

bdf::types::card celas3::head = bdf::types::card("CELAS3");
celas3::celas3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types celas3::card_type() const {
    return cards::types::CELAS3;
}

bdf::types::card celas4::head = bdf::types::card("CELAS4");
celas4::celas4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types celas4::card_type() const {
    return cards::types::CELAS4;
}

bdf::types::card cfillet::head = bdf::types::card("CFILLET");
cfillet::cfillet(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cfillet::card_type() const {
    return cards::types::CFILLET;
}

bdf::types::card cfluid2::head = bdf::types::card("CFLUID2");
cfluid2::cfluid2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cfluid2::card_type() const {
    return cards::types::CFLUID2;
}

bdf::types::card cfluid3::head = bdf::types::card("CFLUID3");
cfluid3::cfluid3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cfluid3::card_type() const {
    return cards::types::CFLUID3;
}

bdf::types::card cfluid4::head = bdf::types::card("CFLUID4");
cfluid4::cfluid4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cfluid4::card_type() const {
    return cards::types::CFLUID4;
}

bdf::types::card cgap::head = bdf::types::card("CGAP");
cgap::cgap(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cgap::card_type() const {
    return cards::types::CGAP;
}

bdf::types::card chacab::head = bdf::types::card("CHACAB");
chacab::chacab(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types chacab::card_type() const {
    return cards::types::CHACAB;
}

bdf::types::card chacbr::head = bdf::types::card("CHACBR");
chacbr::chacbr(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types chacbr::card_type() const {
    return cards::types::CHACBR;
}

bdf::types::card chbdye::head = bdf::types::card("CHBDYE");
chbdye::chbdye(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types chbdye::card_type() const {
    return cards::types::CHBDYE;
}

bdf::types::card chbdyg::head = bdf::types::card("CHBDYG");
chbdyg::chbdyg(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types chbdyg::card_type() const {
    return cards::types::CHBDYG;
}

bdf::types::card chbdyp::head = bdf::types::card("CHBDYP");
chbdyp::chbdyp(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types chbdyp::card_type() const {
    return cards::types::CHBDYP;
}

bdf::types::card chexa::head = bdf::types::card("CHEXA");
chexa::chexa(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types chexa::card_type() const {
    return cards::types::CHEXA;
}

bdf::types::card cmass1::head = bdf::types::card("CMASS1");
cmass1::cmass1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cmass1::card_type() const {
    return cards::types::CMASS1;
}

bdf::types::card cmass3::head = bdf::types::card("CMASS3");
cmass3::cmass3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cmass3::card_type() const {
    return cards::types::CMASS3;
}

bdf::types::card combwld::head = bdf::types::card("COMBWLD");
combwld::combwld(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types combwld::card_type() const {
    return cards::types::COMBWLD;
}

bdf::types::card conm2::head = bdf::types::card("CONM2");
conm2::conm2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types conm2::card_type() const {
    return cards::types::CONM2;
}

bdf::types::card conrod::head = bdf::types::card("CONROD");
conrod::conrod(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types conrod::card_type() const {
    return cards::types::CONROD;
}

bdf::types::card cpenta::head = bdf::types::card("CPENTA");
cpenta::cpenta(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cpenta::card_type() const {
    return cards::types::CPENTA;
}

bdf::types::card cquad8::head = bdf::types::card("CQUAD8");
cquad8::cquad8(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cquad8::card_type() const {
    return cards::types::CQUAD8;
}

bdf::types::card cquad::head = bdf::types::card("CQUAD");
cquad::cquad(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cquad::card_type() const {
    return cards::types::CQUAD;
}

bdf::types::card cquadr::head = bdf::types::card("CQUADR");
cquadr::cquadr(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cquadr::card_type() const {
    return cards::types::CQUADR;
}

bdf::types::card cquadx::head = bdf::types::card("CQUADX");
cquadx::cquadx(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cquadx::card_type() const {
    return cards::types::CQUADX;
}

bdf::types::card crac2d::head = bdf::types::card("CRAC2D");
crac2d::crac2d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types crac2d::card_type() const {
    return cards::types::CRAC2D;
}

bdf::types::card crac3d::head = bdf::types::card("CRAC3D");
crac3d::crac3d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types crac3d::card_type() const {
    return cards::types::CRAC3D;
}

bdf::types::card cshear::head = bdf::types::card("CSHEAR");
cshear::cshear(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cshear::card_type() const {
    return cards::types::CSHEAR;
}

bdf::types::card cslot3::head = bdf::types::card("CSLOT3");
cslot3::cslot3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cslot3::card_type() const {
    return cards::types::CSLOT3;
}

bdf::types::card cslot4::head = bdf::types::card("CSLOT4");
cslot4::cslot4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cslot4::card_type() const {
    return cards::types::CSLOT4;
}

bdf::types::card cspot::head = bdf::types::card("CSPOT");
cspot::cspot(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cspot::card_type() const {
    return cards::types::CSPOT;
}

bdf::types::card ctetra::head = bdf::types::card("CTETRA");
ctetra::ctetra(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ctetra::card_type() const {
    return cards::types::CTETRA;
}

bdf::types::card ctria6::head = bdf::types::card("CTRIA6");
ctria6::ctria6(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ctria6::card_type() const {
    return cards::types::CTRIA6;
}

bdf::types::card ctriar::head = bdf::types::card("CTRIAR");
ctriar::ctriar(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ctriar::card_type() const {
    return cards::types::CTRIAR;
}

bdf::types::card ctriax6::head = bdf::types::card("CTRIAX6");
ctriax6::ctriax6(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ctriax6::card_type() const {
    return cards::types::CTRIAX6;
}

bdf::types::card ctriax::head = bdf::types::card("CTRIAX");
ctriax::ctriax(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ctriax::card_type() const {
    return cards::types::CTRIAX;
}

bdf::types::card ctube::head = bdf::types::card("CTUBE");
ctube::ctube(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types ctube::card_type() const {
    return cards::types::CTUBE;
}

bdf::types::card cvisc::head = bdf::types::card("CVISC");
cvisc::cvisc(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types cvisc::card_type() const {
    return cards::types::CVISC;
}

bdf::types::card genel::head = bdf::types::card("GENEL");
genel::genel(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types genel::card_type() const {
    return cards::types::GENEL;
}

bdf::types::card gmintc::head = bdf::types::card("GMINTC");
gmintc::gmintc(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types gmintc::card_type() const {
    return cards::types::GMINTC;
}

bdf::types::card gmints::head = bdf::types::card("GMINTS");
gmints::gmints(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types gmints::card_type() const {
    return cards::types::GMINTS;
}

bdf::types::card plotel::head = bdf::types::card("PLOTEL");
plotel::plotel(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types plotel::card_type() const {
    return cards::types::PLOTEL;
}

bdf::types::card rbar1::head = bdf::types::card("RBAR1");
rbar1::rbar1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbar1::card_type() const {
    return cards::types::RBAR1;
}

bdf::types::card rbar::head = bdf::types::card("RBAR");
rbar::rbar(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbar::card_type() const {
    return cards::types::RBAR;
}

bdf::types::card rbe1::head = bdf::types::card("RBE1");
rbe1::rbe1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbe1::card_type() const {
    return cards::types::RBE1;
}

bdf::types::card rbe2::head = bdf::types::card("RBE2");
rbe2::rbe2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbe2::card_type() const {
    return cards::types::RBE2;
}

bdf::types::card rbe2d::head = bdf::types::card("RBE2D");
rbe2d::rbe2d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbe2d::card_type() const {
    return cards::types::RBE2D;
}

bdf::types::card rbe3::head = bdf::types::card("RBE3");
rbe3::rbe3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbe3::card_type() const {
    return cards::types::RBE3;
}

bdf::types::card rbe3d::head = bdf::types::card("RBE3D");
rbe3d::rbe3d(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rbe3d::card_type() const {
    return cards::types::RBE3D;
}

bdf::types::card rjoint::head = bdf::types::card("RJOINT");
rjoint::rjoint(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rjoint::card_type() const {
    return cards::types::RJOINT;
}

bdf::types::card rrod::head = bdf::types::card("RROD");
rrod::rrod(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rrod::card_type() const {
    return cards::types::RROD;
}

bdf::types::card rspline::head = bdf::types::card("RSPLINE");
rspline::rspline(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rspline::card_type() const {
    return cards::types::RSPLINE;
}

bdf::types::card rsscon::head = bdf::types::card("RSSCON");
rsscon::rsscon(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rsscon::card_type() const {
    return cards::types::RSSCON;
}

bdf::types::card rtrplt1::head = bdf::types::card("RTRPLT1");
rtrplt1::rtrplt1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rtrplt1::card_type() const {
    return cards::types::RTRPLT1;
}

bdf::types::card rtrplt::head = bdf::types::card("RTRPLT");
rtrplt::rtrplt(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types rtrplt::card_type() const {
    return cards::types::RTRPLT;
}

bdf::types::card spline1::head = bdf::types::card("SPLINE1");
spline1::spline1(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types spline1::card_type() const {
    return cards::types::SPLINE1;
}

bdf::types::card spline2::head = bdf::types::card("SPLINE2");
spline2::spline2(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types spline2::card_type() const {
    return cards::types::SPLINE2;
}

bdf::types::card spline3::head = bdf::types::card("SPLINE3");
spline3::spline3(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types spline3::card_type() const {
    return cards::types::SPLINE3;
}

bdf::types::card spline4::head = bdf::types::card("SPLINE4");
spline4::spline4(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types spline4::card_type() const {
    return cards::types::SPLINE4;
}

bdf::types::card spline5::head = bdf::types::card("SPLINE5");
spline5::spline5(const list<std::string> &inp) : cards::__base::__element_dummy(inp) {}
cards::types spline5::card_type() const {
    return cards::types::SPLINE5;
}

bdf::types::card _delete::head = bdf::types::card("_DELETE");
_delete::_delete(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types _delete::card_type() const {
    return cards::types::DELETE;
}

bdf::types::card abinfl::head = bdf::types::card("ABINFL");
abinfl::abinfl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types abinfl::card_type() const {
    return cards::types::ABINFL;
}

bdf::types::card acc::head = bdf::types::card("ACC");
acc::acc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types acc::card_type() const {
    return cards::types::ACC;
}

bdf::types::card accel::head = bdf::types::card("ACCEL");
accel::accel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types accel::card_type() const {
    return cards::types::ACCEL;
}

bdf::types::card accel1::head = bdf::types::card("ACCEL1");
accel1::accel1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types accel1::card_type() const {
    return cards::types::ACCEL1;
}

bdf::types::card accmetr::head = bdf::types::card("ACCMETR");
accmetr::accmetr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types accmetr::card_type() const {
    return cards::types::ACCMETR;
}

bdf::types::card accsspt::head = bdf::types::card("ACCSSPT");
accsspt::accsspt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types accsspt::card_type() const {
    return cards::types::ACCSSPT;
}

bdf::types::card acload::head = bdf::types::card("ACLOAD");
acload::acload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types acload::card_type() const {
    return cards::types::ACLOAD;
}

bdf::types::card acmodl::head = bdf::types::card("ACMODL");
acmodl::acmodl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types acmodl::card_type() const {
    return cards::types::ACMODL;
}

bdf::types::card acpemcp::head = bdf::types::card("ACPEMCP");
acpemcp::acpemcp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types acpemcp::card_type() const {
    return cards::types::ACPEMCP;
}

bdf::types::card acsrce::head = bdf::types::card("ACSRCE");
acsrce::acsrce(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types acsrce::card_type() const {
    return cards::types::ACSRCE;
}

bdf::types::card activat::head = bdf::types::card("ACTIVAT");
activat::activat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types activat::card_type() const {
    return cards::types::ACTIVAT;
}

bdf::types::card actrim::head = bdf::types::card("ACTRIM");
actrim::actrim(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types actrim::card_type() const {
    return cards::types::ACTRIM;
}

bdf::types::card adapt::head = bdf::types::card("ADAPT");
adapt::adapt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types adapt::card_type() const {
    return cards::types::ADAPT;
}

bdf::types::card adumi::head = bdf::types::card("ADUMi");
adumi::adumi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types adumi::card_type() const {
    return cards::types::ADUMi;
}

bdf::types::card aecomp::head = bdf::types::card("AECOMP");
aecomp::aecomp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aecomp::card_type() const {
    return cards::types::AECOMP;
}

bdf::types::card aecompl::head = bdf::types::card("AECOMPL");
aecompl::aecompl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aecompl::card_type() const {
    return cards::types::AECOMPL;
}

bdf::types::card aedw::head = bdf::types::card("AEDW");
aedw::aedw(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aedw::card_type() const {
    return cards::types::AEDW;
}

bdf::types::card aefact::head = bdf::types::card("AEFACT");
aefact::aefact(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aefact::card_type() const {
    return cards::types::AEFACT;
}

bdf::types::card aeforce::head = bdf::types::card("AEFORCE");
aeforce::aeforce(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aeforce::card_type() const {
    return cards::types::AEFORCE;
}

bdf::types::card aegrid::head = bdf::types::card("AEGRID");
aegrid::aegrid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aegrid::card_type() const {
    return cards::types::AEGRID;
}

bdf::types::card aelink::head = bdf::types::card("AELINK");
aelink::aelink(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aelink::card_type() const {
    return cards::types::AELINK;
}

bdf::types::card aelist::head = bdf::types::card("AELIST");
aelist::aelist(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aelist::card_type() const {
    return cards::types::AELIST;
}

bdf::types::card aelistc::head = bdf::types::card("AELISTC");
aelistc::aelistc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aelistc::card_type() const {
    return cards::types::AELISTC;
}

bdf::types::card aeparm::head = bdf::types::card("AEPARM");
aeparm::aeparm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aeparm::card_type() const {
    return cards::types::AEPARM;
}

bdf::types::card aepress::head = bdf::types::card("AEPRESS");
aepress::aepress(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aepress::card_type() const {
    return cards::types::AEPRESS;
}

bdf::types::card aequad4::head = bdf::types::card("AEQUAD4");
aequad4::aequad4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aequad4::card_type() const {
    return cards::types::AEQUAD4;
}

bdf::types::card aero::head = bdf::types::card("AERO");
aero::aero(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aero::card_type() const {
    return cards::types::AERO;
}

bdf::types::card aeros::head = bdf::types::card("AEROS");
aeros::aeros(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aeros::card_type() const {
    return cards::types::AEROS;
}

bdf::types::card aescale::head = bdf::types::card("AESCALE");
aescale::aescale(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aescale::card_type() const {
    return cards::types::AESCALE;
}

bdf::types::card aestat::head = bdf::types::card("AESTAT");
aestat::aestat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aestat::card_type() const {
    return cards::types::AESTAT;
}

bdf::types::card aesurf::head = bdf::types::card("AESURF");
aesurf::aesurf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aesurf::card_type() const {
    return cards::types::AESURF;
}

bdf::types::card aesurfs::head = bdf::types::card("AESURFS");
aesurfs::aesurfs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aesurfs::card_type() const {
    return cards::types::AESURFS;
}

bdf::types::card aetria3::head = bdf::types::card("AETRIA3");
aetria3::aetria3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aetria3::card_type() const {
    return cards::types::AETRIA3;
}

bdf::types::card airbag::head = bdf::types::card("AIRBAG");
airbag::airbag(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types airbag::card_type() const {
    return cards::types::AIRBAG;
}

bdf::types::card aliasm::head = bdf::types::card("ALIASM");
aliasm::aliasm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aliasm::card_type() const {
    return cards::types::ALIASM;
}

bdf::types::card aset::head = bdf::types::card("ASET");
aset::aset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aset::card_type() const {
    return cards::types::ASET;
}

bdf::types::card aset1::head = bdf::types::card("ASET1");
aset1::aset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types aset1::card_type() const {
    return cards::types::ASET1;
}

bdf::types::card axic::head = bdf::types::card("AXIC");
axic::axic(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types axic::card_type() const {
    return cards::types::AXIC;
}

bdf::types::card axif::head = bdf::types::card("AXIF");
axif::axif(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types axif::card_type() const {
    return cards::types::AXIF;
}

bdf::types::card axslot::head = bdf::types::card("AXSLOT");
axslot::axslot(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types axslot::card_type() const {
    return cards::types::AXSLOT;
}

bdf::types::card baror::head = bdf::types::card("BAROR");
baror::baror(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types baror::card_type() const {
    return cards::types::BAROR;
}

bdf::types::card barrier::head = bdf::types::card("BARRIER");
barrier::barrier(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types barrier::card_type() const {
    return cards::types::BARRIER;
}

bdf::types::card bcbdprp::head = bdf::types::card("BCBDPRP");
bcbdprp::bcbdprp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcbdprp::card_type() const {
    return cards::types::BCBDPRP;
}

bdf::types::card bcbmrad::head = bdf::types::card("BCBMRAD");
bcbmrad::bcbmrad(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcbmrad::card_type() const {
    return cards::types::BCBMRAD;
}

bdf::types::card bcbody::head = bdf::types::card("BCBODY");
bcbody::bcbody(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcbody::card_type() const {
    return cards::types::BCBODY;
}

bdf::types::card bcbody1::head = bdf::types::card("BCBODY1");
bcbody1::bcbody1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcbody1::card_type() const {
    return cards::types::BCBODY1;
}

bdf::types::card bcbox::head = bdf::types::card("BCBOX");
bcbox::bcbox(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcbox::card_type() const {
    return cards::types::BCBOX;
}

bdf::types::card bcbzier::head = bdf::types::card("BCBZIER");
bcbzier::bcbzier(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcbzier::card_type() const {
    return cards::types::BCBZIER;
}

bdf::types::card bcgm700::head = bdf::types::card("BCGM700");
bcgm700::bcgm700(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcgm700::card_type() const {
    return cards::types::BCGM700;
}

bdf::types::card bcgrid::head = bdf::types::card("BCGRID");
bcgrid::bcgrid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcgrid::card_type() const {
    return cards::types::BCGRID;
}

bdf::types::card bchange::head = bdf::types::card("BCHANGE");
bchange::bchange(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bchange::card_type() const {
    return cards::types::BCHANGE;
}

bdf::types::card bcmatl::head = bdf::types::card("BCMATL");
bcmatl::bcmatl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcmatl::card_type() const {
    return cards::types::BCMATL;
}

bdf::types::card bcmove::head = bdf::types::card("BCMOVE");
bcmove::bcmove(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcmove::card_type() const {
    return cards::types::BCMOVE;
}

bdf::types::card bcnurb2::head = bdf::types::card("BCNURB2");
bcnurb2::bcnurb2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcnurb2::card_type() const {
    return cards::types::BCNURB2;
}

bdf::types::card bcnurbs::head = bdf::types::card("BCNURBS");
bcnurbs::bcnurbs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcnurbs::card_type() const {
    return cards::types::BCNURBS;
}

bdf::types::card bconect::head = bdf::types::card("BCONECT");
bconect::bconect(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bconect::card_type() const {
    return cards::types::BCONECT;
}

bdf::types::card bconp::head = bdf::types::card("BCONP");
bconp::bconp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bconp::card_type() const {
    return cards::types::BCONP;
}

bdf::types::card bconprg::head = bdf::types::card("BCONPRG");
bconprg::bconprg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bconprg::card_type() const {
    return cards::types::BCONPRG;
}

bdf::types::card bconprp::head = bdf::types::card("BCONPRP");
bconprp::bconprp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bconprp::card_type() const {
    return cards::types::BCONPRP;
}

bdf::types::card bconuds::head = bdf::types::card("BCONUDS");
bconuds::bconuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bconuds::card_type() const {
    return cards::types::BCONUDS;
}

bdf::types::card bcpara::head = bdf::types::card("BCPARA");
bcpara::bcpara(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcpara::card_type() const {
    return cards::types::BCPARA;
}

bdf::types::card bcpatch::head = bdf::types::card("BCPATCH");
bcpatch::bcpatch(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcpatch::card_type() const {
    return cards::types::BCPATCH;
}

bdf::types::card bcpflg::head = bdf::types::card("BCPFLG");
bcpflg::bcpflg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcpflg::card_type() const {
    return cards::types::BCPFLG;
}

bdf::types::card bcprop::head = bdf::types::card("BCPROP");
bcprop::bcprop(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcprop::card_type() const {
    return cards::types::BCPROP;
}

bdf::types::card bcprop1::head = bdf::types::card("BCPROP1");
bcprop1::bcprop1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcprop1::card_type() const {
    return cards::types::BCPROP1;
}

bdf::types::card bcrigid::head = bdf::types::card("BCRIGID");
bcrigid::bcrigid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcrigid::card_type() const {
    return cards::types::BCRIGID;
}

bdf::types::card bcrgsrf::head = bdf::types::card("BCRGSRF");
bcrgsrf::bcrgsrf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcrgsrf::card_type() const {
    return cards::types::BCRGSRF;
}

bdf::types::card bcscap::head = bdf::types::card("BCSCAP");
bcscap::bcscap(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcscap::card_type() const {
    return cards::types::BCSCAP;
}

bdf::types::card bcseg::head = bdf::types::card("BCSEG");
bcseg::bcseg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bcseg::card_type() const {
    return cards::types::BCSEG;
}

bdf::types::card bctable::head = bdf::types::card("BCTABLE");
bctable::bctable(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bctable::card_type() const {
    return cards::types::BCTABLE;
}

bdf::types::card bctabl1::head = bdf::types::card("BCTABL1");
bctabl1::bctabl1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bctabl1::card_type() const {
    return cards::types::BCTABL1;
}

bdf::types::card bctrim::head = bdf::types::card("BCTRIM");
bctrim::bctrim(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bctrim::card_type() const {
    return cards::types::BCTRIM;
}

bdf::types::card bdylist::head = bdf::types::card("BDYLIST");
bdylist::bdylist(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bdylist::card_type() const {
    return cards::types::BDYLIST;
}

bdf::types::card bdyforc::head = bdf::types::card("BDYFORC");
bdyforc::bdyforc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bdyforc::card_type() const {
    return cards::types::BDYFORC;
}

bdf::types::card bdyor::head = bdf::types::card("BDYOR");
bdyor::bdyor(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bdyor::card_type() const {
    return cards::types::BDYOR;
}

bdf::types::card bdyrelx::head = bdf::types::card("BDYRELX");
bdyrelx::bdyrelx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bdyrelx::card_type() const {
    return cards::types::BDYRELX;
}

bdf::types::card beadvar::head = bdf::types::card("BEADVAR");
beadvar::beadvar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types beadvar::card_type() const {
    return cards::types::BEADVAR;
}

bdf::types::card beamor::head = bdf::types::card("BEAMOR");
beamor::beamor(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types beamor::card_type() const {
    return cards::types::BEAMOR;
}

bdf::types::card bfrlc::head = bdf::types::card("BFRllC");
bfrlc::bfrlc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bfrlc::card_type() const {
    return cards::types::BFRlC;
}

bdf::types::card bias::head = bdf::types::card("BIAS");
bias::bias(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bias::card_type() const {
    return cards::types::BIAS;
}

bdf::types::card bjoin::head = bdf::types::card("BJOIN");
bjoin::bjoin(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bjoin::card_type() const {
    return cards::types::BJOIN;
}

bdf::types::card bldout::head = bdf::types::card("BLDOUT");
bldout::bldout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bldout::card_type() const {
    return cards::types::BLDOUT;
}

bdf::types::card blseg::head = bdf::types::card("BLSEG");
blseg::blseg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types blseg::card_type() const {
    return cards::types::BLSEG;
}

bdf::types::card bndfix::head = bdf::types::card("BNDFIX");
bndfix::bndfix(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bndfix::card_type() const {
    return cards::types::BNDFIX;
}

bdf::types::card bndfix1::head = bdf::types::card("BNDFIX1");
bndfix1::bndfix1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bndfix1::card_type() const {
    return cards::types::BNDFIX1;
}

bdf::types::card bndfree::head = bdf::types::card("BNDFREE");
bndfree::bndfree(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bndfree::card_type() const {
    return cards::types::BNDFREE;
}

bdf::types::card bndfre1::head = bdf::types::card("BNDFRE1");
bndfre1::bndfre1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bndfre1::card_type() const {
    return cards::types::BNDFRE1;
}

bdf::types::card bndgrid::head = bdf::types::card("BNDGRID");
bndgrid::bndgrid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bndgrid::card_type() const {
    return cards::types::BNDGRID;
}

bdf::types::card bolt::head = bdf::types::card("BOLT");
bolt::bolt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bolt::card_type() const {
    return cards::types::BOLT;
}

bdf::types::card boutput::head = bdf::types::card("BOUTPUT");
boutput::boutput(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types boutput::card_type() const {
    return cards::types::BOUTPUT;
}

bdf::types::card brksql::head = bdf::types::card("BRKSQL");
brksql::brksql(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types brksql::card_type() const {
    return cards::types::BRKSQL;
}

bdf::types::card bset::head = bdf::types::card("BSET");
bset::bset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bset::card_type() const {
    return cards::types::BSET;
}

bdf::types::card bset1::head = bdf::types::card("BSET1");
bset1::bset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bset1::card_type() const {
    return cards::types::BSET1;
}

bdf::types::card bsqueal::head = bdf::types::card("BSQUEAL");
bsqueal::bsqueal(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bsqueal::card_type() const {
    return cards::types::BSQUEAL;
}

bdf::types::card bsurf::head = bdf::types::card("BSURF");
bsurf::bsurf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bsurf::card_type() const {
    return cards::types::BSURF;
}

bdf::types::card bwidth::head = bdf::types::card("BWIDTH");
bwidth::bwidth(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types bwidth::card_type() const {
    return cards::types::BWIDTH;
}

bdf::types::card cacinf3::head = bdf::types::card("CACINF3");
cacinf3::cacinf3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cacinf3::card_type() const {
    return cards::types::CACINF3;
}

bdf::types::card cacinf4::head = bdf::types::card("CACINF4");
cacinf4::cacinf4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cacinf4::card_type() const {
    return cards::types::CACINF4;
}

bdf::types::card campbll::head = bdf::types::card("CAMPBLL");
campbll::campbll(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types campbll::card_type() const {
    return cards::types::CAMPBLL;
}

bdf::types::card caxisym::head = bdf::types::card("CAXISYM");
caxisym::caxisym(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types caxisym::card_type() const {
    return cards::types::CAXISYM;
}

bdf::types::card cbarao::head = bdf::types::card("CBARAO");
cbarao::cbarao(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cbarao::card_type() const {
    return cards::types::CBARAO;
}

bdf::types::card cbeam3::head = bdf::types::card("CBEAM3");
cbeam3::cbeam3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cbeam3::card_type() const {
    return cards::types::CBEAM3;
}

bdf::types::card cbelt::head = bdf::types::card("CBELT");
cbelt::cbelt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cbelt::card_type() const {
    return cards::types::CBELT;
}

bdf::types::card cbush2d::head = bdf::types::card("CBUSH2D");
cbush2d::cbush2d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cbush2d::card_type() const {
    return cards::types::CBUSH2D;
}

bdf::types::card cdumi::head = bdf::types::card("CDUMi");
cdumi::cdumi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cdumi::card_type() const {
    return cards::types::CDUMi;
}

bdf::types::card cfast::head = bdf::types::card("CFAST");
cfast::cfast(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cfast::card_type() const {
    return cards::types::CFAST;
}

bdf::types::card cfluidi::head = bdf::types::card("CFLUIDi");
cfluidi::cfluidi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cfluidi::card_type() const {
    return cards::types::CFLUIDi;
}

bdf::types::card cifhex::head = bdf::types::card("CIFHEX");
cifhex::cifhex(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cifhex::card_type() const {
    return cards::types::CIFHEX;
}

bdf::types::card cifpent::head = bdf::types::card("CIFPENT");
cifpent::cifpent(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cifpent::card_type() const {
    return cards::types::CIFPENT;
}

bdf::types::card cifqdx::head = bdf::types::card("CIFQDX");
cifqdx::cifqdx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cifqdx::card_type() const {
    return cards::types::CIFQDX;
}

bdf::types::card cifquad::head = bdf::types::card("CIFQUAD");
cifquad::cifquad(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cifquad::card_type() const {
    return cards::types::CIFQUAD;
}

bdf::types::card cintc::head = bdf::types::card("CINTC");
cintc::cintc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cintc::card_type() const {
    return cards::types::CINTC;
}

bdf::types::card cload::head = bdf::types::card("CLOAD");
cload::cload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cload::card_type() const {
    return cards::types::CLOAD;
}

bdf::types::card cmarkb2::head = bdf::types::card("CMARKB2");
cmarkb2::cmarkb2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cmarkb2::card_type() const {
    return cards::types::CMARKB2;
}

bdf::types::card cmarkn1::head = bdf::types::card("CMARKN1");
cmarkn1::cmarkn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cmarkn1::card_type() const {
    return cards::types::CMARKN1;
}

bdf::types::card cmrebai::head = bdf::types::card("CMREBAI");
cmrebai::cmrebai(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cmrebai::card_type() const {
    return cards::types::CMREBAI;
}

bdf::types::card cmrebar::head = bdf::types::card("CMREBAR");
cmrebar::cmrebar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cmrebar::card_type() const {
    return cards::types::CMREBAR;
}

bdf::types::card cntruds::head = bdf::types::card("CNTRUDS");
cntruds::cntruds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cntruds::card_type() const {
    return cards::types::CNTRUDS;
}

bdf::types::card cohesiv::head = bdf::types::card("COHESIV");
cohesiv::cohesiv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cohesiv::card_type() const {
    return cards::types::COHESIV;
}

bdf::types::card conctl::head = bdf::types::card("CONCTL");
conctl::conctl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types conctl::card_type() const {
    return cards::types::CONCTL;
}

bdf::types::card conspot::head = bdf::types::card("CONSPOT");
conspot::conspot(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types conspot::card_type() const {
    return cards::types::CONSPOT;
}

bdf::types::card contrlt::head = bdf::types::card("CONTRLT");
contrlt::contrlt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types contrlt::card_type() const {
    return cards::types::CONTRLT;
}

bdf::types::card conv::head = bdf::types::card("CONV");
conv::conv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types conv::card_type() const {
    return cards::types::CONV;
}

bdf::types::card conv3::head = bdf::types::card("CONV3");
conv3::conv3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types conv3::card_type() const {
    return cards::types::CONV3;
}

bdf::types::card convm::head = bdf::types::card("CONVM");
convm::convm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types convm::card_type() const {
    return cards::types::CONVM;
}

bdf::types::card cord1c::head = bdf::types::card("CORD1C");
cord1c::cord1c(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord1c::card_type() const {
    return cards::types::CORD1C;
}

bdf::types::card cord1r::head = bdf::types::card("CORD1R");
cord1r::cord1r(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord1r::card_type() const {
    return cards::types::CORD1R;
}

bdf::types::card cord1rx::head = bdf::types::card("CORD1RX");
cord1rx::cord1rx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord1rx::card_type() const {
    return cards::types::CORD1RX;
}

bdf::types::card cord1s::head = bdf::types::card("CORD1S");
cord1s::cord1s(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord1s::card_type() const {
    return cards::types::CORD1S;
}

bdf::types::card cord2c::head = bdf::types::card("CORD2C");
cord2c::cord2c(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord2c::card_type() const {
    return cards::types::CORD2C;
}

bdf::types::card cord2r::head = bdf::types::card("CORD2R");
cord2r::cord2r(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord2r::card_type() const {
    return cards::types::CORD2R;
}

bdf::types::card cord2rx::head = bdf::types::card("CORD2RX");
cord2rx::cord2rx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord2rx::card_type() const {
    return cards::types::CORD2RX;
}

bdf::types::card cord2s::head = bdf::types::card("CORD2S");
cord2s::cord2s(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord2s::card_type() const {
    return cards::types::CORD2S;
}

bdf::types::card cord3g::head = bdf::types::card("CORD3G");
cord3g::cord3g(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord3g::card_type() const {
    return cards::types::CORD3G;
}

bdf::types::card cord3r::head = bdf::types::card("CORD3R");
cord3r::cord3r(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord3r::card_type() const {
    return cards::types::CORD3R;
}

bdf::types::card cord3rx::head = bdf::types::card("CORD3RX");
cord3rx::cord3rx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cord3rx::card_type() const {
    return cards::types::CORD3RX;
}

bdf::types::card couopt::head = bdf::types::card("COUOPT");
couopt::couopt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types couopt::card_type() const {
    return cards::types::COUOPT;
}

bdf::types::card coup1fl::head = bdf::types::card("COUP1FL");
coup1fl::coup1fl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types coup1fl::card_type() const {
    return cards::types::COUP1FL;
}

bdf::types::card coupint::head = bdf::types::card("COUPINT");
coupint::coupint(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types coupint::card_type() const {
    return cards::types::COUPINT;
}

bdf::types::card couple::head = bdf::types::card("COUPLE");
couple::couple(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types couple::card_type() const {
    return cards::types::COUPLE;
}

bdf::types::card creep::head = bdf::types::card("CREEP");
creep::creep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types creep::card_type() const {
    return cards::types::CREEP;
}

bdf::types::card crossec::head = bdf::types::card("CROSSEC");
crossec::crossec(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types crossec::card_type() const {
    return cards::types::CROSSEC;
}

bdf::types::card cseam::head = bdf::types::card("CSEAM");
cseam::cseam(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cseam::card_type() const {
    return cards::types::CSEAM;
}

bdf::types::card cset::head = bdf::types::card("CSET");
cset::cset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cset::card_type() const {
    return cards::types::CSET;
}

bdf::types::card cset1::head = bdf::types::card("CSET1");
cset1::cset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cset1::card_type() const {
    return cards::types::CSET1;
}

bdf::types::card csph::head = bdf::types::card("CSPH");
csph::csph(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csph::card_type() const {
    return cards::types::CSPH;
}

bdf::types::card cspr::head = bdf::types::card("CSPR");
cspr::cspr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cspr::card_type() const {
    return cards::types::CSPR;
}

bdf::types::card csschd::head = bdf::types::card("CSSCHD");
csschd::csschd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csschd::card_type() const {
    return cards::types::CSSCHD;
}

bdf::types::card csshl::head = bdf::types::card("CSSHL");
csshl::csshl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csshl::card_type() const {
    return cards::types::CSSHL;
}

bdf::types::card csshlh::head = bdf::types::card("CSSHLH");
csshlh::csshlh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csshlh::card_type() const {
    return cards::types::CSSHLH;
}

bdf::types::card csshlm::head = bdf::types::card("CSSHLM");
csshlm::csshlm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csshlm::card_type() const {
    return cards::types::CSSHLM;
}

bdf::types::card csshlp::head = bdf::types::card("CSSHLP");
csshlp::csshlp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csshlp::card_type() const {
    return cards::types::CSSHLP;
}

bdf::types::card csuper::head = bdf::types::card("CSUPER");
csuper::csuper(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csuper::card_type() const {
    return cards::types::CSUPER;
}

bdf::types::card csupext::head = bdf::types::card("CSUPEXT");
csupext::csupext(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types csupext::card_type() const {
    return cards::types::CSUPEXT;
}

bdf::types::card ctquad::head = bdf::types::card("CTQUAD");
ctquad::ctquad(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ctquad::card_type() const {
    return cards::types::CTQUAD;
}

bdf::types::card cttria::head = bdf::types::card("CTTRIA");
cttria::cttria(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cttria::card_type() const {
    return cards::types::CTTRIA;
}

bdf::types::card cweld::head = bdf::types::card("CWELD");
cweld::cweld(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cweld::card_type() const {
    return cards::types::CWELD;
}

bdf::types::card cyax::head = bdf::types::card("CYAX");
cyax::cyax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cyax::card_type() const {
    return cards::types::CYAX;
}

bdf::types::card cyjoin::head = bdf::types::card("CYJOIN");
cyjoin::cyjoin(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cyjoin::card_type() const {
    return cards::types::CYJOIN;
}

bdf::types::card cylindr::head = bdf::types::card("CYLINDR");
cylindr::cylindr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cylindr::card_type() const {
    return cards::types::CYLINDR;
}

bdf::types::card cysup::head = bdf::types::card("CYSUP");
cysup::cysup(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cysup::card_type() const {
    return cards::types::CYSUP;
}

bdf::types::card cysym::head = bdf::types::card("CYSYM");
cysym::cysym(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types cysym::card_type() const {
    return cards::types::CYSYM;
}

bdf::types::card d2r0000::head = bdf::types::card("D2R0000");
d2r0000::d2r0000(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types d2r0000::card_type() const {
    return cards::types::D2R0000;
}

bdf::types::card d2rauto::head = bdf::types::card("D2RAUTO");
d2rauto::d2rauto(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types d2rauto::card_type() const {
    return cards::types::D2RAUTO;
}

bdf::types::card d2riner::head = bdf::types::card("D2RINER");
d2riner::d2riner(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types d2riner::card_type() const {
    return cards::types::D2RINER;
}

bdf::types::card dampgbl::head = bdf::types::card("DAMPGBL");
dampgbl::dampgbl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dampgbl::card_type() const {
    return cards::types::DAMPGBL;
}

bdf::types::card damping::head = bdf::types::card("DAMPING");
damping::damping(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types damping::card_type() const {
    return cards::types::DAMPING;
}

bdf::types::card dampmas::head = bdf::types::card("DAMPMAS");
dampmas::dampmas(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dampmas::card_type() const {
    return cards::types::DAMPMAS;
}

bdf::types::card dampstf::head = bdf::types::card("DAMPSTF");
dampstf::dampstf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dampstf::card_type() const {
    return cards::types::DAMPSTF;
}

bdf::types::card darea::head = bdf::types::card("DAREA");
darea::darea(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types darea::card_type() const {
    return cards::types::DAREA;
}

bdf::types::card dbexsss::head = bdf::types::card("DBEXSSS");
dbexsss::dbexsss(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dbexsss::card_type() const {
    return cards::types::DBEXSSS;
}

bdf::types::card dbreg::head = bdf::types::card("DBREG");
dbreg::dbreg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dbreg::card_type() const {
    return cards::types::DBREG;
}

bdf::types::card dconadd::head = bdf::types::card("DCONADD");
dconadd::dconadd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dconadd::card_type() const {
    return cards::types::DCONADD;
}

bdf::types::card dconstr::head = bdf::types::card("DCONSTR");
dconstr::dconstr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dconstr::card_type() const {
    return cards::types::DCONSTR;
}

bdf::types::card ddval::head = bdf::types::card("DDVAL");
ddval::ddval(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ddval::card_type() const {
    return cards::types::DDVAL;
}

bdf::types::card deactel::head = bdf::types::card("DEACTEL");
deactel::deactel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types deactel::card_type() const {
    return cards::types::DEACTEL;
}

bdf::types::card deform::head = bdf::types::card("DEFORM");
deform::deform(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types deform::card_type() const {
    return cards::types::DEFORM;
}

bdf::types::card defuset::head = bdf::types::card("DEFUSET");
defuset::defuset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types defuset::card_type() const {
    return cards::types::DEFUSET;
}

bdf::types::card delay::head = bdf::types::card("DELAY");
delay::delay(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types delay::card_type() const {
    return cards::types::DELAY;
}

bdf::types::card deqatn::head = bdf::types::card("DEQATN");
deqatn::deqatn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types deqatn::card_type() const {
    return cards::types::DEQATN;
}

bdf::types::card desvar::head = bdf::types::card("DESVAR");
desvar::desvar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types desvar::card_type() const {
    return cards::types::DESVAR;
}

bdf::types::card detsph::head = bdf::types::card("DETSPH");
detsph::detsph(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types detsph::card_type() const {
    return cards::types::DETSPH;
}

bdf::types::card diverg::head = bdf::types::card("DIVERG");
diverg::diverg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types diverg::card_type() const {
    return cards::types::DIVERG;
}

bdf::types::card dlink::head = bdf::types::card("DLINK");
dlink::dlink(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dlink::card_type() const {
    return cards::types::DLINK;
}

bdf::types::card dload::head = bdf::types::card("DLOAD");
dload::dload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dload::card_type() const {
    return cards::types::DLOAD;
}

bdf::types::card dmi::head = bdf::types::card("DMI");
dmi::dmi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmi::card_type() const {
    return cards::types::DMI;
}

bdf::types::card dmiax::head = bdf::types::card("DMIAX");
dmiax::dmiax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmiax::card_type() const {
    return cards::types::DMIAX;
}

bdf::types::card dmig::head = bdf::types::card("DMIG");
dmig::dmig(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmig::card_type() const {
    return cards::types::DMIG;
}

bdf::types::card dmigout::head = bdf::types::card("DMIGOUT");
dmigout::dmigout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmigout::card_type() const {
    return cards::types::DMIGOUT;
}

bdf::types::card dmigrot::head = bdf::types::card("DMIGROT");
dmigrot::dmigrot(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmigrot::card_type() const {
    return cards::types::DMIGROT;
}

bdf::types::card dmij::head = bdf::types::card("DMIJ");
dmij::dmij(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmij::card_type() const {
    return cards::types::DMIJ;
}

bdf::types::card dmiji::head = bdf::types::card("DMIJI");
dmiji::dmiji(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmiji::card_type() const {
    return cards::types::DMIJI;
}

bdf::types::card dmik::head = bdf::types::card("DMIK");
dmik::dmik(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dmik::card_type() const {
    return cards::types::DMIK;
}

bdf::types::card doptprm::head = bdf::types::card("DOPTPRM");
doptprm::doptprm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types doptprm::card_type() const {
    return cards::types::DOPTPRM;
}

bdf::types::card dphase::head = bdf::types::card("DPHASE");
dphase::dphase(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dphase::card_type() const {
    return cards::types::DPHASE;
}

bdf::types::card dresp1::head = bdf::types::card("DRESP1");
dresp1::dresp1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dresp1::card_type() const {
    return cards::types::DRESP1;
}

bdf::types::card dresp2::head = bdf::types::card("DRESP2");
dresp2::dresp2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dresp2::card_type() const {
    return cards::types::DRESP2;
}

bdf::types::card dresp3::head = bdf::types::card("DRESP3");
dresp3::dresp3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dresp3::card_type() const {
    return cards::types::DRESP3;
}

bdf::types::card dscreen::head = bdf::types::card("DSCREEN");
dscreen::dscreen(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dscreen::card_type() const {
    return cards::types::DSCREEN;
}

bdf::types::card dtable::head = bdf::types::card("DTABLE");
dtable::dtable(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dtable::card_type() const {
    return cards::types::DTABLE;
}

bdf::types::card dtable2::head = bdf::types::card("DTABLE2");
dtable2::dtable2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dtable2::card_type() const {
    return cards::types::DTABLE2;
}

bdf::types::card dti::head = bdf::types::card("DTI");
dti::dti(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dti::card_type() const {
    return cards::types::DTI;
}

bdf::types::card dvbshap::head = bdf::types::card("DVBSHAP");
dvbshap::dvbshap(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvbshap::card_type() const {
    return cards::types::DVBSHAP;
}

bdf::types::card dvcrel1::head = bdf::types::card("DVCREL1");
dvcrel1::dvcrel1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvcrel1::card_type() const {
    return cards::types::DVCREL1;
}

bdf::types::card dvcrel2::head = bdf::types::card("DVCREL2");
dvcrel2::dvcrel2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvcrel2::card_type() const {
    return cards::types::DVCREL2;
}

bdf::types::card dvgrid::head = bdf::types::card("DVGRID");
dvgrid::dvgrid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvgrid::card_type() const {
    return cards::types::DVGRID;
}

bdf::types::card dvlrel1::head = bdf::types::card("DVLREL1");
dvlrel1::dvlrel1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvlrel1::card_type() const {
    return cards::types::DVLREL1;
}

bdf::types::card dvmrel1::head = bdf::types::card("DVMREL1");
dvmrel1::dvmrel1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvmrel1::card_type() const {
    return cards::types::DVMREL1;
}

bdf::types::card dvmrel2::head = bdf::types::card("DVMREL2");
dvmrel2::dvmrel2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvmrel2::card_type() const {
    return cards::types::DVMREL2;
}

bdf::types::card dvprel1::head = bdf::types::card("DVPREL1");
dvprel1::dvprel1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvprel1::card_type() const {
    return cards::types::DVPREL1;
}

bdf::types::card dvprel2::head = bdf::types::card("DVPREL2");
dvprel2::dvprel2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvprel2::card_type() const {
    return cards::types::DVPREL2;
}

bdf::types::card dvshap::head = bdf::types::card("DVSHAP");
dvshap::dvshap(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvshap::card_type() const {
    return cards::types::DVSHAP;
}

bdf::types::card dvpsurf::head = bdf::types::card("DVPSURF");
dvpsurf::dvpsurf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dvpsurf::card_type() const {
    return cards::types::DVPSURF;
}

bdf::types::card dychang::head = bdf::types::card("DYCHANG");
dychang::dychang(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dychang::card_type() const {
    return cards::types::DYCHANG;
}

bdf::types::card dydelem::head = bdf::types::card("DYDELEM");
dydelem::dydelem(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dydelem::card_type() const {
    return cards::types::DYDELEM;
}

bdf::types::card dyfsisw::head = bdf::types::card("DYFSISW");
dyfsisw::dyfsisw(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dyfsisw::card_type() const {
    return cards::types::DYFSISW;
}

bdf::types::card dyparam::head = bdf::types::card("DYPARAM");
dyparam::dyparam(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dyparam::card_type() const {
    return cards::types::DYPARAM;
}

bdf::types::card dyrigsw::head = bdf::types::card("DYRIGSW");
dyrigsw::dyrigsw(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dyrigsw::card_type() const {
    return cards::types::DYRIGSW;
}

bdf::types::card dytermt::head = bdf::types::card("DYTERMT");
dytermt::dytermt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dytermt::card_type() const {
    return cards::types::DYTERMT;
}

bdf::types::card dytimhs::head = bdf::types::card("DYTIMHS");
dytimhs::dytimhs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types dytimhs::card_type() const {
    return cards::types::DYTIMHS;
}

bdf::types::card echooff::head = bdf::types::card("ECHOOFF");
echooff::echooff(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types echooff::card_type() const {
    return cards::types::ECHOOFF;
}

bdf::types::card echoon::head = bdf::types::card("ECHOON");
echoon::echoon(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types echoon::card_type() const {
    return cards::types::ECHOON;
}

bdf::types::card eigb::head = bdf::types::card("EIGB");
eigb::eigb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eigb::card_type() const {
    return cards::types::EIGB;
}

bdf::types::card eigc::head = bdf::types::card("EIGC");
eigc::eigc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eigc::card_type() const {
    return cards::types::EIGC;
}

bdf::types::card eigp::head = bdf::types::card("EIGP");
eigp::eigp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eigp::card_type() const {
    return cards::types::EIGP;
}

bdf::types::card eigr::head = bdf::types::card("EIGR");
eigr::eigr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eigr::card_type() const {
    return cards::types::EIGR;
}

bdf::types::card eigrl::head = bdf::types::card("EIGRL");
eigrl::eigrl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eigrl::card_type() const {
    return cards::types::EIGRL;
}

bdf::types::card elemuds::head = bdf::types::card("ELEMUDS");
elemuds::elemuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types elemuds::card_type() const {
    return cards::types::ELEMUDS;
}

bdf::types::card elist::head = bdf::types::card("ELIST");
elist::elist(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types elist::card_type() const {
    return cards::types::ELIST;
}

bdf::types::card enddyna::head = bdf::types::card("ENDDYNA");
enddyna::enddyna(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types enddyna::card_type() const {
    return cards::types::ENDDYNA;
}

bdf::types::card entuds::head = bdf::types::card("ENTUDS");
entuds::entuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types entuds::card_type() const {
    return cards::types::ENTUDS;
}

bdf::types::card eosgam::head = bdf::types::card("EOSGAM");
eosgam::eosgam(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosgam::card_type() const {
    return cards::types::EOSGAM;
}

bdf::types::card eosgrun::head = bdf::types::card("EOSGRUN");
eosgrun::eosgrun(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosgrun::card_type() const {
    return cards::types::EOSGRUN;
}

bdf::types::card eosig::head = bdf::types::card("EOSIG");
eosig::eosig(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosig::card_type() const {
    return cards::types::EOSIG;
}

bdf::types::card eosjwl::head = bdf::types::card("EOSJWL");
eosjwl::eosjwl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosjwl::card_type() const {
    return cards::types::EOSJWL;
}

bdf::types::card eosmg::head = bdf::types::card("EOSMG");
eosmg::eosmg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosmg::card_type() const {
    return cards::types::EOSMG;
}

bdf::types::card eosmg2::head = bdf::types::card("EOSMG2");
eosmg2::eosmg2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosmg2::card_type() const {
    return cards::types::EOSMG2;
}

bdf::types::card eospol::head = bdf::types::card("EOSPOL");
eospol::eospol(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eospol::card_type() const {
    return cards::types::EOSPOL;
}

bdf::types::card eostab::head = bdf::types::card("EOSTAB");
eostab::eostab(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eostab::card_type() const {
    return cards::types::EOSTAB;
}

bdf::types::card eostabc::head = bdf::types::card("EOSTABC");
eostabc::eostabc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eostabc::card_type() const {
    return cards::types::EOSTABC;
}

bdf::types::card eostait::head = bdf::types::card("EOSTAIT");
eostait::eostait(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eostait::card_type() const {
    return cards::types::EOSTAIT;
}

bdf::types::card eosuds::head = bdf::types::card("EOSUDS");
eosuds::eosuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eosuds::card_type() const {
    return cards::types::EOSUDS;
}

bdf::types::card epoint::head = bdf::types::card("EPOINT");
epoint::epoint(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types epoint::card_type() const {
    return cards::types::EPOINT;
}

bdf::types::card erppnl::head = bdf::types::card("ERPPNL");
erppnl::erppnl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types erppnl::card_type() const {
    return cards::types::ERPPNL;
}

bdf::types::card eulfor::head = bdf::types::card("EULFOR");
eulfor::eulfor(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eulfor::card_type() const {
    return cards::types::EULFOR;
}

bdf::types::card eulfor1::head = bdf::types::card("EULFOR1");
eulfor1::eulfor1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eulfor1::card_type() const {
    return cards::types::EULFOR1;
}

bdf::types::card eulfreg::head = bdf::types::card("EULFREG");
eulfreg::eulfreg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types eulfreg::card_type() const {
    return cards::types::EULFREG;
}

bdf::types::card explsv::head = bdf::types::card("EXPLSV");
explsv::explsv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types explsv::card_type() const {
    return cards::types::EXPLSV;
}

bdf::types::card extrn::head = bdf::types::card("EXTRN");
extrn::extrn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types extrn::card_type() const {
    return cards::types::EXTRN;
}

bdf::types::card failjc::head = bdf::types::card("FAILJC");
failjc::failjc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types failjc::card_type() const {
    return cards::types::FAILJC;
}

bdf::types::card failmps::head = bdf::types::card("FAILMPS");
failmps::failmps(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types failmps::card_type() const {
    return cards::types::FAILMPS;
}

bdf::types::card failuds::head = bdf::types::card("FAILUDS");
failuds::failuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types failuds::card_type() const {
    return cards::types::FAILUDS;
}

bdf::types::card fbadlay::head = bdf::types::card("FBADLAY");
fbadlay::fbadlay(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fbadlay::card_type() const {
    return cards::types::FBADLAY;
}

bdf::types::card fbaload::head = bdf::types::card("FBALOAD");
fbaload::fbaload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fbaload::card_type() const {
    return cards::types::FBALOAD;
}

bdf::types::card fbaphas::head = bdf::types::card("FBAPHAS");
fbaphas::fbaphas(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fbaphas::card_type() const {
    return cards::types::FBAPHAS;
}

bdf::types::card fbodyld::head = bdf::types::card("FBODYLD");
fbodyld::fbodyld(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fbodyld::card_type() const {
    return cards::types::FBODYLD;
}

bdf::types::card fbodysb::head = bdf::types::card("FBODYSB");
fbodysb::fbodysb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fbodysb::card_type() const {
    return cards::types::FBODYSB;
}

bdf::types::card feedge::head = bdf::types::card("FEEDGE");
feedge::feedge(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types feedge::card_type() const {
    return cards::types::FEEDGE;
}

bdf::types::card feface::head = bdf::types::card("FEFACE");
feface::feface(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types feface::card_type() const {
    return cards::types::FEFACE;
}

bdf::types::card ffcontr::head = bdf::types::card("FFCONTR");
ffcontr::ffcontr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ffcontr::card_type() const {
    return cards::types::FFCONTR;
}

bdf::types::card flfact::head = bdf::types::card("FLFACT");
flfact::flfact(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flfact::card_type() const {
    return cards::types::FLFACT;
}

bdf::types::card flow::head = bdf::types::card("FLOW");
flow::flow(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flow::card_type() const {
    return cards::types::FLOW;
}

bdf::types::card flowdef::head = bdf::types::card("FLOWDEF");
flowdef::flowdef(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flowdef::card_type() const {
    return cards::types::FLOWDEF;
}

bdf::types::card flowsph::head = bdf::types::card("FLOWSPH");
flowsph::flowsph(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flowsph::card_type() const {
    return cards::types::FLOWSPH;
}

bdf::types::card flowt::head = bdf::types::card("FLOWT");
flowt::flowt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flowt::card_type() const {
    return cards::types::FLOWT;
}

bdf::types::card flowuds::head = bdf::types::card("FLOWUDS");
flowuds::flowuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flowuds::card_type() const {
    return cards::types::FLOWUDS;
}

bdf::types::card flsym::head = bdf::types::card("FLSYM");
flsym::flsym(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flsym::card_type() const {
    return cards::types::FLSYM;
}

bdf::types::card flutter::head = bdf::types::card("FLUTTER");
flutter::flutter(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types flutter::card_type() const {
    return cards::types::FLUTTER;
}

bdf::types::card force1::head = bdf::types::card("FORCE1");
force1::force1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types force1::card_type() const {
    return cards::types::FORCE1;
}

bdf::types::card force2::head = bdf::types::card("FORCE2");
force2::force2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types force2::card_type() const {
    return cards::types::FORCE2;
}

bdf::types::card forceax::head = bdf::types::card("FORCEAX");
forceax::forceax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types forceax::card_type() const {
    return cards::types::FORCEAX;
}

bdf::types::card freept::head = bdf::types::card("FREEPT");
freept::freept(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freept::card_type() const {
    return cards::types::FREEPT;
}

bdf::types::card freq::head = bdf::types::card("FREQ");
freq::freq(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freq::card_type() const {
    return cards::types::FREQ;
}

bdf::types::card freq1::head = bdf::types::card("FREQ1");
freq1::freq1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freq1::card_type() const {
    return cards::types::FREQ1;
}

bdf::types::card freq2::head = bdf::types::card("FREQ2");
freq2::freq2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freq2::card_type() const {
    return cards::types::FREQ2;
}

bdf::types::card freq3::head = bdf::types::card("FREQ3");
freq3::freq3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freq3::card_type() const {
    return cards::types::FREQ3;
}

bdf::types::card freq4::head = bdf::types::card("FREQ4");
freq4::freq4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freq4::card_type() const {
    return cards::types::FREQ4;
}

bdf::types::card freq5::head = bdf::types::card("FREQ5");
freq5::freq5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types freq5::card_type() const {
    return cards::types::FREQ5;
}

bdf::types::card frfcomp::head = bdf::types::card("FRFCOMP");
frfcomp::frfcomp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfcomp::card_type() const {
    return cards::types::FRFCOMP;
}

bdf::types::card frfconn::head = bdf::types::card("FRFCONN");
frfconn::frfconn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfconn::card_type() const {
    return cards::types::FRFCONN;
}

bdf::types::card frfflex::head = bdf::types::card("FRFFLEX");
frfflex::frfflex(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfflex::card_type() const {
    return cards::types::FRFFLEX;
}

bdf::types::card frfrels::head = bdf::types::card("FRFRELS");
frfrels::frfrels(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfrels::card_type() const {
    return cards::types::FRFRELS;
}

bdf::types::card frfspc1::head = bdf::types::card("FRFSPC1");
frfspc1::frfspc1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfspc1::card_type() const {
    return cards::types::FRFSPC1;
}

bdf::types::card frfxit::head = bdf::types::card("FRFXIT");
frfxit::frfxit(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfxit::card_type() const {
    return cards::types::FRFXIT;
}

bdf::types::card frfxit1::head = bdf::types::card("FRFXIT1");
frfxit1::frfxit1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types frfxit1::card_type() const {
    return cards::types::FRFXIT1;
}

bdf::types::card fsictrl::head = bdf::types::card("FSICTRL");
fsictrl::fsictrl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fsictrl::card_type() const {
    return cards::types::FSICTRL;
}

bdf::types::card fslist::head = bdf::types::card("FSLIST");
fslist::fslist(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types fslist::card_type() const {
    return cards::types::FSLIST;
}

bdf::types::card ftgdef::head = bdf::types::card("FTGDEF");
ftgdef::ftgdef(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ftgdef::card_type() const {
    return cards::types::FTGDEF;
}

bdf::types::card ftgevnt::head = bdf::types::card("FTGEVNT");
ftgevnt::ftgevnt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ftgevnt::card_type() const {
    return cards::types::FTGEVNT;
}

bdf::types::card ftgload::head = bdf::types::card("FTGLOAD");
ftgload::ftgload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ftgload::card_type() const {
    return cards::types::FTGLOAD;
}

bdf::types::card ftgparm::head = bdf::types::card("FTGPARM");
ftgparm::ftgparm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ftgparm::card_type() const {
    return cards::types::FTGPARM;
}

bdf::types::card ftgseq::head = bdf::types::card("FTGSEQ");
ftgseq::ftgseq(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ftgseq::card_type() const {
    return cards::types::FTGSEQ;
}

bdf::types::card gbag::head = bdf::types::card("GBAG");
gbag::gbag(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gbag::card_type() const {
    return cards::types::GBAG;
}

bdf::types::card gbagcou::head = bdf::types::card("GBAGCOU");
gbagcou::gbagcou(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gbagcou::card_type() const {
    return cards::types::GBAGCOU;
}

bdf::types::card genuds::head = bdf::types::card("GENUDS");
genuds::genuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types genuds::card_type() const {
    return cards::types::GENUDS;
}

bdf::types::card gmbc::head = bdf::types::card("GMBC");
gmbc::gmbc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmbc::card_type() const {
    return cards::types::GMBC;
}

bdf::types::card gmbndc::head = bdf::types::card("GMBNDC");
gmbndc::gmbndc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmbndc::card_type() const {
    return cards::types::GMBNDC;
}

bdf::types::card gmbnds::head = bdf::types::card("GMBNDS");
gmbnds::gmbnds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmbnds::card_type() const {
    return cards::types::GMBNDS;
}

bdf::types::card gmconv::head = bdf::types::card("GMCONV");
gmconv::gmconv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmconv::card_type() const {
    return cards::types::GMCONV;
}

bdf::types::card gmcord::head = bdf::types::card("GMCORD");
gmcord::gmcord(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmcord::card_type() const {
    return cards::types::GMCORD;
}

bdf::types::card gmcurv::head = bdf::types::card("GMCURV");
gmcurv::gmcurv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmcurv::card_type() const {
    return cards::types::GMCURV;
}

bdf::types::card gmload::head = bdf::types::card("GMLOAD");
gmload::gmload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmload::card_type() const {
    return cards::types::GMLOAD;
}

bdf::types::card gmnurb::head = bdf::types::card("GMNURB");
gmnurb::gmnurb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmnurb::card_type() const {
    return cards::types::GMNURB;
}

bdf::types::card gmqvol::head = bdf::types::card("GMQVOL");
gmqvol::gmqvol(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmqvol::card_type() const {
    return cards::types::GMQVOL;
}

bdf::types::card gmspc::head = bdf::types::card("GMSPC");
gmspc::gmspc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmspc::card_type() const {
    return cards::types::GMSPC;
}

bdf::types::card gmsurf::head = bdf::types::card("GMSURF");
gmsurf::gmsurf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gmsurf::card_type() const {
    return cards::types::GMSURF;
}

bdf::types::card grdset::head = bdf::types::card("GRDSET");
grdset::grdset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types grdset::card_type() const {
    return cards::types::GRDSET;
}

bdf::types::card gria::head = bdf::types::card("GRIA");
gria::gria(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gria::card_type() const {
    return cards::types::GRIA;
}

bdf::types::card grida::head = bdf::types::card("GRIDA");
grida::grida(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types grida::card_type() const {
    return cards::types::GRIDA;
}

bdf::types::card gridb::head = bdf::types::card("GRIDB");
gridb::gridb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gridb::card_type() const {
    return cards::types::GRIDB;
}

bdf::types::card gridf::head = bdf::types::card("GRIDF");
gridf::gridf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gridf::card_type() const {
    return cards::types::GRIDF;
}

bdf::types::card grids::head = bdf::types::card("GRIDS");
grids::grids(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types grids::card_type() const {
    return cards::types::GRIDS;
}

bdf::types::card gust::head = bdf::types::card("GUST");
gust::gust(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types gust::card_type() const {
    return cards::types::GUST;
}

bdf::types::card hadacri::head = bdf::types::card("HADACRI");
hadacri::hadacri(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types hadacri::card_type() const {
    return cards::types::HADACRI;
}

bdf::types::card hadaptl::head = bdf::types::card("HADAPTL");
hadaptl::hadaptl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types hadaptl::card_type() const {
    return cards::types::HADAPTL;
}

bdf::types::card heatlos::head = bdf::types::card("HEATLOS");
heatlos::heatlos(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types heatlos::card_type() const {
    return cards::types::HEATLOS;
}

bdf::types::card hgsuppr::head = bdf::types::card("HGSUPPR");
hgsuppr::hgsuppr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types hgsuppr::card_type() const {
    return cards::types::HGSUPPR;
}

bdf::types::card htrconv::head = bdf::types::card("HTRCONV");
htrconv::htrconv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types htrconv::card_type() const {
    return cards::types::HTRCONV;
}

bdf::types::card htrrad::head = bdf::types::card("HTRRAD");
htrrad::htrrad(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types htrrad::card_type() const {
    return cards::types::HTRRAD;
}

bdf::types::card hybdamp::head = bdf::types::card("HYBDAMP");
hybdamp::hybdamp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types hybdamp::card_type() const {
    return cards::types::HYBDAMP;
}

bdf::types::card hydstat::head = bdf::types::card("HYDSTAT");
hydstat::hydstat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types hydstat::card_type() const {
    return cards::types::HYDSTAT;
}

bdf::types::card include::head = bdf::types::card("INCLUDE");
include::include(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types include::card_type() const {
    return cards::types::INCLUDE;
}

bdf::types::card inflcg::head = bdf::types::card("INFLCG");
inflcg::inflcg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types inflcg::card_type() const {
    return cards::types::INFLCG;
}

bdf::types::card inflfrc::head = bdf::types::card("INFLFRC");
inflfrc::inflfrc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types inflfrc::card_type() const {
    return cards::types::INFLFRC;
}

bdf::types::card inflgas::head = bdf::types::card("INFLGAS");
inflgas::inflgas(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types inflgas::card_type() const {
    return cards::types::INFLGAS;
}

bdf::types::card inflhb::head = bdf::types::card("INFLHB");
inflhb::inflhb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types inflhb::card_type() const {
    return cards::types::INFLHB;
}

bdf::types::card infltnk::head = bdf::types::card("INFLTNK");
infltnk::infltnk(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types infltnk::card_type() const {
    return cards::types::INFLTNK;
}

bdf::types::card infltr::head = bdf::types::card("INFLTR");
infltr::infltr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types infltr::card_type() const {
    return cards::types::INFLTR;
}

bdf::types::card initgas::head = bdf::types::card("INITGAS");
initgas::initgas(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types initgas::card_type() const {
    return cards::types::INITGAS;
}

bdf::types::card ipstrain::head = bdf::types::card("IPSTRAIN");
ipstrain::ipstrain(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ipstrain::card_type() const {
    return cards::types::IPSTRAIN;
}

bdf::types::card ipstrn::head = bdf::types::card("IPSTRN");
ipstrn::ipstrn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ipstrn::card_type() const {
    return cards::types::IPSTRN;
}

bdf::types::card istress::head = bdf::types::card("ISTRESS");
istress::istress(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istress::card_type() const {
    return cards::types::ISTRESS;
}

bdf::types::card istrnsh::head = bdf::types::card("ISTRNSH");
istrnsh::istrnsh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrnsh::card_type() const {
    return cards::types::ISTRNSH;
}

bdf::types::card istrnso::head = bdf::types::card("ISTRNSO");
istrnso::istrnso(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrnso::card_type() const {
    return cards::types::ISTRNSO;
}

bdf::types::card istrnts::head = bdf::types::card("ISTRNTS");
istrnts::istrnts(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrnts::card_type() const {
    return cards::types::ISTRNTS;
}

bdf::types::card istrsbe::head = bdf::types::card("ISTRSBE");
istrsbe::istrsbe(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrsbe::card_type() const {
    return cards::types::ISTRSBE;
}

bdf::types::card istrssh::head = bdf::types::card("ISTRSSH");
istrssh::istrssh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrssh::card_type() const {
    return cards::types::ISTRSSH;
}

bdf::types::card istrsso::head = bdf::types::card("ISTRSSO");
istrsso::istrsso(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrsso::card_type() const {
    return cards::types::ISTRSSO;
}

bdf::types::card istrsss::head = bdf::types::card("ISTRSSS");
istrsss::istrsss(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrsss::card_type() const {
    return cards::types::ISTRSSS;
}

bdf::types::card istrsts::head = bdf::types::card("ISTRSTS");
istrsts::istrsts(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types istrsts::card_type() const {
    return cards::types::ISTRSTS;
}

bdf::types::card iter::head = bdf::types::card("ITER");
iter::iter(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types iter::card_type() const {
    return cards::types::ITER;
}

bdf::types::card leakage::head = bdf::types::card("LEAKAGE");
leakage::leakage(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types leakage::card_type() const {
    return cards::types::LEAKAGE;
}

bdf::types::card loadclid::head = bdf::types::card("LOADCLID");
loadclid::loadclid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadclid::card_type() const {
    return cards::types::LOADCLID;
}

bdf::types::card loadcnam::head = bdf::types::card("LOADCNAM");
loadcnam::loadcnam(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadcnam::card_type() const {
    return cards::types::LOADCNAM;
}

bdf::types::card loadcsub::head = bdf::types::card("LOADCSUB");
loadcsub::loadcsub(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadcsub::card_type() const {
    return cards::types::LOADCSUB;
}

bdf::types::card loadcyh::head = bdf::types::card("LOADCYH");
loadcyh::loadcyh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadcyh::card_type() const {
    return cards::types::LOADCYH;
}

bdf::types::card loadcyn::head = bdf::types::card("LOADCYN");
loadcyn::loadcyn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadcyn::card_type() const {
    return cards::types::LOADCYN;
}

bdf::types::card loadcyt::head = bdf::types::card("LOADCYT");
loadcyt::loadcyt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadcyt::card_type() const {
    return cards::types::LOADCYT;
}

bdf::types::card loadof::head = bdf::types::card("LOADOF");
loadof::loadof(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadof::card_type() const {
    return cards::types::LOADOF;
}

bdf::types::card loadt::head = bdf::types::card("LOADT");
loadt::loadt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types loadt::card_type() const {
    return cards::types::LOADT;
}

bdf::types::card lorenzi::head = bdf::types::card("LORENZI");
lorenzi::lorenzi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types lorenzi::card_type() const {
    return cards::types::LORENZI;
}

bdf::types::card lseq::head = bdf::types::card("LSEQ");
lseq::lseq(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types lseq::card_type() const {
    return cards::types::LSEQ;
}

bdf::types::card macreep::head = bdf::types::card("MACREEP");
macreep::macreep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types macreep::card_type() const {
    return cards::types::MACREEP;
}

bdf::types::card marcin::head = bdf::types::card("MARCIN");
marcin::marcin(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types marcin::card_type() const {
    return cards::types::MARCIN;
}

bdf::types::card marcout::head = bdf::types::card("MARCOUT");
marcout::marcout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types marcout::card_type() const {
    return cards::types::MARCOUT;
}

bdf::types::card marprn::head = bdf::types::card("MARPRN");
marprn::marprn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types marprn::card_type() const {
    return cards::types::MARPRN;
}

bdf::types::card mat3::head = bdf::types::card("MAT3");
mat3::mat3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mat3::card_type() const {
    return cards::types::MAT3;
}

bdf::types::card mat4::head = bdf::types::card("MAT4");
mat4::mat4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mat4::card_type() const {
    return cards::types::MAT4;
}

bdf::types::card mat5::head = bdf::types::card("MAT5");
mat5::mat5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mat5::card_type() const {
    return cards::types::MAT5;
}

bdf::types::card mat8::head = bdf::types::card("MAT8");
mat8::mat8(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mat8::card_type() const {
    return cards::types::MAT8;
}

bdf::types::card mat9::head = bdf::types::card("MAT9");
mat9::mat9(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mat9::card_type() const {
    return cards::types::MAT9;
}

bdf::types::card mat10::head = bdf::types::card("MAT10");
mat10::mat10(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mat10::card_type() const {
    return cards::types::MAT10;
}

bdf::types::card matd001::head = bdf::types::card("MATD001");
matd001::matd001(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd001::card_type() const {
    return cards::types::MATD001;
}

bdf::types::card matd2an::head = bdf::types::card("MATD2AN");
matd2an::matd2an(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd2an::card_type() const {
    return cards::types::MATD2AN;
}

bdf::types::card matd2or::head = bdf::types::card("MATD2OR");
matd2or::matd2or(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd2or::card_type() const {
    return cards::types::MATD2OR;
}

bdf::types::card matd003::head = bdf::types::card("MATD003");
matd003::matd003(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd003::card_type() const {
    return cards::types::MATD003;
}

bdf::types::card matd004::head = bdf::types::card("MATD004");
matd004::matd004(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd004::card_type() const {
    return cards::types::MATD004;
}

bdf::types::card matd005::head = bdf::types::card("MATD005");
matd005::matd005(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd005::card_type() const {
    return cards::types::MATD005;
}

bdf::types::card matd006::head = bdf::types::card("MATD006");
matd006::matd006(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd006::card_type() const {
    return cards::types::MATD006;
}

bdf::types::card matd007::head = bdf::types::card("MATD007");
matd007::matd007(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd007::card_type() const {
    return cards::types::MATD007;
}

bdf::types::card matd009::head = bdf::types::card("MATD009");
matd009::matd009(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd009::card_type() const {
    return cards::types::MATD009;
}

bdf::types::card matd010::head = bdf::types::card("MATD010");
matd010::matd010(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd010::card_type() const {
    return cards::types::MATD010;
}

bdf::types::card matd012::head = bdf::types::card("MATD012");
matd012::matd012(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd012::card_type() const {
    return cards::types::MATD012;
}

bdf::types::card matd013::head = bdf::types::card("MATD013");
matd013::matd013(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd013::card_type() const {
    return cards::types::MATD013;
}

bdf::types::card matd014::head = bdf::types::card("MATD014");
matd014::matd014(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd014::card_type() const {
    return cards::types::MATD014;
}

bdf::types::card matd015::head = bdf::types::card("MATD015");
matd015::matd015(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd015::card_type() const {
    return cards::types::MATD015;
}

bdf::types::card matd016::head = bdf::types::card("MATD016");
matd016::matd016(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd016::card_type() const {
    return cards::types::MATD016;
}

bdf::types::card matd018::head = bdf::types::card("MATD018");
matd018::matd018(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd018::card_type() const {
    return cards::types::MATD018;
}

bdf::types::card matd019::head = bdf::types::card("MATD019");
matd019::matd019(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd019::card_type() const {
    return cards::types::MATD019;
}

bdf::types::card matd020::head = bdf::types::card("MATD020");
matd020::matd020(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd020::card_type() const {
    return cards::types::MATD020;
}

bdf::types::card matd20m::head = bdf::types::card("MATD20M");
matd20m::matd20m(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd20m::card_type() const {
    return cards::types::MATD20M;
}

bdf::types::card matd021::head = bdf::types::card("MATD021");
matd021::matd021(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd021::card_type() const {
    return cards::types::MATD021;
}

bdf::types::card matd022::head = bdf::types::card("MATD022");
matd022::matd022(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd022::card_type() const {
    return cards::types::MATD022;
}

bdf::types::card matd024::head = bdf::types::card("MATD024");
matd024::matd024(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd024::card_type() const {
    return cards::types::MATD024;
}

bdf::types::card matd025::head = bdf::types::card("MATD025");
matd025::matd025(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd025::card_type() const {
    return cards::types::MATD025;
}

bdf::types::card matd026::head = bdf::types::card("MATD026");
matd026::matd026(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd026::card_type() const {
    return cards::types::MATD026;
}

bdf::types::card matd027::head = bdf::types::card("MATD027");
matd027::matd027(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd027::card_type() const {
    return cards::types::MATD027;
}

bdf::types::card matd028::head = bdf::types::card("MATD028");
matd028::matd028(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd028::card_type() const {
    return cards::types::MATD028;
}

bdf::types::card matd029::head = bdf::types::card("MATD029");
matd029::matd029(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd029::card_type() const {
    return cards::types::MATD029;
}

bdf::types::card matd030::head = bdf::types::card("MATD030");
matd030::matd030(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd030::card_type() const {
    return cards::types::MATD030;
}

bdf::types::card matd031::head = bdf::types::card("MATD031");
matd031::matd031(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd031::card_type() const {
    return cards::types::MATD031;
}

bdf::types::card matd032::head = bdf::types::card("MATD032");
matd032::matd032(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd032::card_type() const {
    return cards::types::MATD032;
}

bdf::types::card matd034::head = bdf::types::card("MATD034");
matd034::matd034(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd034::card_type() const {
    return cards::types::MATD034;
}

bdf::types::card matd036::head = bdf::types::card("MATD036");
matd036::matd036(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd036::card_type() const {
    return cards::types::MATD036;
}

bdf::types::card matd037::head = bdf::types::card("MATD037");
matd037::matd037(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd037::card_type() const {
    return cards::types::MATD037;
}

bdf::types::card matd038::head = bdf::types::card("MATD038");
matd038::matd038(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd038::card_type() const {
    return cards::types::MATD038;
}

bdf::types::card matd039::head = bdf::types::card("MATD039");
matd039::matd039(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd039::card_type() const {
    return cards::types::MATD039;
}

bdf::types::card matd040::head = bdf::types::card("MATD040");
matd040::matd040(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd040::card_type() const {
    return cards::types::MATD040;
}

bdf::types::card matd053::head = bdf::types::card("MATD053");
matd053::matd053(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd053::card_type() const {
    return cards::types::MATD053;
}

bdf::types::card matd054::head = bdf::types::card("MATD054");
matd054::matd054(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd054::card_type() const {
    return cards::types::MATD054;
}

bdf::types::card matd057::head = bdf::types::card("MATD057");
matd057::matd057(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd057::card_type() const {
    return cards::types::MATD057;
}

bdf::types::card matd058::head = bdf::types::card("MATD058");
matd058::matd058(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd058::card_type() const {
    return cards::types::MATD058;
}

bdf::types::card matd059::head = bdf::types::card("MATD059");
matd059::matd059(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd059::card_type() const {
    return cards::types::MATD059;
}

bdf::types::card matd062::head = bdf::types::card("MATD062");
matd062::matd062(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd062::card_type() const {
    return cards::types::MATD062;
}

bdf::types::card matd063::head = bdf::types::card("MATD063");
matd063::matd063(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd063::card_type() const {
    return cards::types::MATD063;
}

bdf::types::card matd064::head = bdf::types::card("MATD064");
matd064::matd064(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd064::card_type() const {
    return cards::types::MATD064;
}

bdf::types::card matd065::head = bdf::types::card("MATD065");
matd065::matd065(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd065::card_type() const {
    return cards::types::MATD065;
}

bdf::types::card matd066::head = bdf::types::card("MATD066");
matd066::matd066(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd066::card_type() const {
    return cards::types::MATD066;
}

bdf::types::card matd067::head = bdf::types::card("MATD067");
matd067::matd067(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd067::card_type() const {
    return cards::types::MATD067;
}

bdf::types::card matd068::head = bdf::types::card("MATD068");
matd068::matd068(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd068::card_type() const {
    return cards::types::MATD068;
}

bdf::types::card matd069::head = bdf::types::card("MATD069");
matd069::matd069(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd069::card_type() const {
    return cards::types::MATD069;
}

bdf::types::card matd070::head = bdf::types::card("MATD070");
matd070::matd070(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd070::card_type() const {
    return cards::types::MATD070;
}

bdf::types::card matd071::head = bdf::types::card("MATD071");
matd071::matd071(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd071::card_type() const {
    return cards::types::MATD071;
}

bdf::types::card matd072::head = bdf::types::card("MATD072");
matd072::matd072(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd072::card_type() const {
    return cards::types::MATD072;
}

bdf::types::card matd72r::head = bdf::types::card("MATD72R");
matd72r::matd72r(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd72r::card_type() const {
    return cards::types::MATD72R;
}

bdf::types::card matd073::head = bdf::types::card("MATD073");
matd073::matd073(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd073::card_type() const {
    return cards::types::MATD073;
}

bdf::types::card matd074::head = bdf::types::card("MATD074");
matd074::matd074(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd074::card_type() const {
    return cards::types::MATD074;
}

bdf::types::card matd076::head = bdf::types::card("MATD076");
matd076::matd076(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd076::card_type() const {
    return cards::types::MATD076;
}

bdf::types::card matd077::head = bdf::types::card("MATD077");
matd077::matd077(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd077::card_type() const {
    return cards::types::MATD077;
}

bdf::types::card matd77h::head = bdf::types::card("MATD77H");
matd77h::matd77h(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd77h::card_type() const {
    return cards::types::MATD77H;
}

bdf::types::card matd77o::head = bdf::types::card("MATD77O");
matd77o::matd77o(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd77o::card_type() const {
    return cards::types::MATD77O;
}

bdf::types::card matd078::head = bdf::types::card("MATD078");
matd078::matd078(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd078::card_type() const {
    return cards::types::MATD078;
}

bdf::types::card matd080::head = bdf::types::card("MATD080");
matd080::matd080(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd080::card_type() const {
    return cards::types::MATD080;
}

bdf::types::card matd081::head = bdf::types::card("MATD081");
matd081::matd081(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd081::card_type() const {
    return cards::types::MATD081;
}

bdf::types::card matd083::head = bdf::types::card("MATD083");
matd083::matd083(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd083::card_type() const {
    return cards::types::MATD083;
}

bdf::types::card matd084::head = bdf::types::card("MATD084");
matd084::matd084(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd084::card_type() const {
    return cards::types::MATD084;
}

bdf::types::card matd087::head = bdf::types::card("MATD087");
matd087::matd087(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd087::card_type() const {
    return cards::types::MATD087;
}

bdf::types::card matd089::head = bdf::types::card("MATD089");
matd089::matd089(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd089::card_type() const {
    return cards::types::MATD089;
}

bdf::types::card matd091::head = bdf::types::card("MATD091");
matd091::matd091(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd091::card_type() const {
    return cards::types::MATD091;
}

bdf::types::card matd092::head = bdf::types::card("MATD092");
matd092::matd092(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd092::card_type() const {
    return cards::types::MATD092;
}

bdf::types::card matd093::head = bdf::types::card("MATD093");
matd093::matd093(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd093::card_type() const {
    return cards::types::MATD093;
}

bdf::types::card matd094::head = bdf::types::card("MATD094");
matd094::matd094(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd094::card_type() const {
    return cards::types::MATD094;
}

bdf::types::card matd095::head = bdf::types::card("MATD095");
matd095::matd095(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd095::card_type() const {
    return cards::types::MATD095;
}

bdf::types::card matd096::head = bdf::types::card("MATD096");
matd096::matd096(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd096::card_type() const {
    return cards::types::MATD096;
}

bdf::types::card matd097::head = bdf::types::card("MATD097");
matd097::matd097(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd097::card_type() const {
    return cards::types::MATD097;
}

bdf::types::card matd098::head = bdf::types::card("MATD098");
matd098::matd098(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd098::card_type() const {
    return cards::types::MATD098;
}

bdf::types::card matd099::head = bdf::types::card("MATD099");
matd099::matd099(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd099::card_type() const {
    return cards::types::MATD099;
}

bdf::types::card matd100::head = bdf::types::card("MATD100");
matd100::matd100(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd100::card_type() const {
    return cards::types::MATD100;
}

bdf::types::card matd106::head = bdf::types::card("MATD106");
matd106::matd106(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd106::card_type() const {
    return cards::types::MATD106;
}

bdf::types::card matd107::head = bdf::types::card("MATD107");
matd107::matd107(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd107::card_type() const {
    return cards::types::MATD107;
}

bdf::types::card matd110::head = bdf::types::card("MATD110");
matd110::matd110(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd110::card_type() const {
    return cards::types::MATD110;
}

bdf::types::card matd111::head = bdf::types::card("MATD111");
matd111::matd111(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd111::card_type() const {
    return cards::types::MATD111;
}

bdf::types::card matd112::head = bdf::types::card("MATD112");
matd112::matd112(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd112::card_type() const {
    return cards::types::MATD112;
}

bdf::types::card matd114::head = bdf::types::card("MATD114");
matd114::matd114(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd114::card_type() const {
    return cards::types::MATD114;
}

bdf::types::card matd115::head = bdf::types::card("MATD115");
matd115::matd115(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd115::card_type() const {
    return cards::types::MATD115;
}

bdf::types::card matd116::head = bdf::types::card("MATD116");
matd116::matd116(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd116::card_type() const {
    return cards::types::MATD116;
}

bdf::types::card matd119::head = bdf::types::card("MATD119");
matd119::matd119(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd119::card_type() const {
    return cards::types::MATD119;
}

bdf::types::card matd120::head = bdf::types::card("MATD120");
matd120::matd120(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd120::card_type() const {
    return cards::types::MATD120;
}

bdf::types::card matd12j::head = bdf::types::card("MATD12J");
matd12j::matd12j(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd12j::card_type() const {
    return cards::types::MATD12J;
}

bdf::types::card matd12r::head = bdf::types::card("MATD12R");
matd12r::matd12r(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd12r::card_type() const {
    return cards::types::MATD12R;
}

bdf::types::card matd121::head = bdf::types::card("MATD121");
matd121::matd121(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd121::card_type() const {
    return cards::types::MATD121;
}

bdf::types::card matd123::head = bdf::types::card("MATD123");
matd123::matd123(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd123::card_type() const {
    return cards::types::MATD123;
}

bdf::types::card matd124::head = bdf::types::card("MATD124");
matd124::matd124(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd124::card_type() const {
    return cards::types::MATD124;
}

bdf::types::card matd126::head = bdf::types::card("MATD126");
matd126::matd126(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd126::card_type() const {
    return cards::types::MATD126;
}

bdf::types::card matd127::head = bdf::types::card("MATD127");
matd127::matd127(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd127::card_type() const {
    return cards::types::MATD127;
}

bdf::types::card matd128::head = bdf::types::card("MATD128");
matd128::matd128(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd128::card_type() const {
    return cards::types::MATD128;
}

bdf::types::card matd129::head = bdf::types::card("MATD129");
matd129::matd129(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd129::card_type() const {
    return cards::types::MATD129;
}

bdf::types::card matd130::head = bdf::types::card("MATD130");
matd130::matd130(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd130::card_type() const {
    return cards::types::MATD130;
}

bdf::types::card matd143::head = bdf::types::card("MATD143");
matd143::matd143(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd143::card_type() const {
    return cards::types::MATD143;
}

bdf::types::card matd145::head = bdf::types::card("MATD145");
matd145::matd145(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd145::card_type() const {
    return cards::types::MATD145;
}

bdf::types::card matd147::head = bdf::types::card("MATD147");
matd147::matd147(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd147::card_type() const {
    return cards::types::MATD147;
}

bdf::types::card matd155::head = bdf::types::card("MATD155");
matd155::matd155(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd155::card_type() const {
    return cards::types::MATD155;
}

bdf::types::card matd156::head = bdf::types::card("MATD156");
matd156::matd156(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd156::card_type() const {
    return cards::types::MATD156;
}

bdf::types::card matd158::head = bdf::types::card("MATD158");
matd158::matd158(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd158::card_type() const {
    return cards::types::MATD158;
}

bdf::types::card matd159::head = bdf::types::card("MATD159");
matd159::matd159(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd159::card_type() const {
    return cards::types::MATD159;
}

bdf::types::card matd163::head = bdf::types::card("MATD163");
matd163::matd163(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd163::card_type() const {
    return cards::types::MATD163;
}

bdf::types::card matd164::head = bdf::types::card("MATD164");
matd164::matd164(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd164::card_type() const {
    return cards::types::MATD164;
}

bdf::types::card matd170::head = bdf::types::card("MATD170");
matd170::matd170(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd170::card_type() const {
    return cards::types::MATD170;
}

bdf::types::card matd173::head = bdf::types::card("MATD173");
matd173::matd173(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd173::card_type() const {
    return cards::types::MATD173;
}

bdf::types::card matd176::head = bdf::types::card("MATD176");
matd176::matd176(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd176::card_type() const {
    return cards::types::MATD176;
}

bdf::types::card matd181::head = bdf::types::card("MATD181");
matd181::matd181(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd181::card_type() const {
    return cards::types::MATD181;
}

bdf::types::card matd184::head = bdf::types::card("MATD184");
matd184::matd184(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd184::card_type() const {
    return cards::types::MATD184;
}

bdf::types::card matd185::head = bdf::types::card("MATD185");
matd185::matd185(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd185::card_type() const {
    return cards::types::MATD185;
}

bdf::types::card matd186::head = bdf::types::card("MATD186");
matd186::matd186(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd186::card_type() const {
    return cards::types::MATD186;
}

bdf::types::card matd188::head = bdf::types::card("MATD188");
matd188::matd188(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd188::card_type() const {
    return cards::types::MATD188;
}

bdf::types::card matd190::head = bdf::types::card("MATD190");
matd190::matd190(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd190::card_type() const {
    return cards::types::MATD190;
}

bdf::types::card matd193::head = bdf::types::card("MATD193");
matd193::matd193(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd193::card_type() const {
    return cards::types::MATD193;
}

bdf::types::card matd196::head = bdf::types::card("MATD196");
matd196::matd196(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd196::card_type() const {
    return cards::types::MATD196;
}

bdf::types::card matd224::head = bdf::types::card("MATD224");
matd224::matd224(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd224::card_type() const {
    return cards::types::MATD224;
}

bdf::types::card matd266::head = bdf::types::card("MATD266");
matd266::matd266(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd266::card_type() const {
    return cards::types::MATD266;
}

bdf::types::card matd272::head = bdf::types::card("MATD272");
matd272::matd272(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matd272::card_type() const {
    return cards::types::MATD272;
}

bdf::types::card matdb01::head = bdf::types::card("MATDB01");
matdb01::matdb01(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdb01::card_type() const {
    return cards::types::MATDB01;
}

bdf::types::card matdero::head = bdf::types::card("MATDERO");
matdero::matdero(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdero::card_type() const {
    return cards::types::MATDERO;
}

bdf::types::card matdeul::head = bdf::types::card("MATDEUL");
matdeul::matdeul(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdeul::card_type() const {
    return cards::types::MATDEUL;
}

bdf::types::card matdigi::head = bdf::types::card("MATDIGI");
matdigi::matdigi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdigi::card_type() const {
    return cards::types::MATDIGI;
}

bdf::types::card matdmg::head = bdf::types::card("MATDMG");
matdmg::matdmg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdmg::card_type() const {
    return cards::types::MATDMG;
}

bdf::types::card matds01::head = bdf::types::card("MATDS01");
matds01::matds01(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds01::card_type() const {
    return cards::types::MATDS01;
}

bdf::types::card matds02::head = bdf::types::card("MATDS02");
matds02::matds02(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds02::card_type() const {
    return cards::types::MATDS02;
}

bdf::types::card matds03::head = bdf::types::card("MATDS03");
matds03::matds03(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds03::card_type() const {
    return cards::types::MATDS03;
}

bdf::types::card matds04::head = bdf::types::card("MATDS04");
matds04::matds04(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds04::card_type() const {
    return cards::types::MATDS04;
}

bdf::types::card matds05::head = bdf::types::card("MATDS05");
matds05::matds05(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds05::card_type() const {
    return cards::types::MATDS05;
}

bdf::types::card matds06::head = bdf::types::card("MATDS06");
matds06::matds06(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds06::card_type() const {
    return cards::types::MATDS06;
}

bdf::types::card matds07::head = bdf::types::card("MATDS07");
matds07::matds07(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds07::card_type() const {
    return cards::types::MATDS07;
}

bdf::types::card matds08::head = bdf::types::card("MATDS08");
matds08::matds08(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds08::card_type() const {
    return cards::types::MATDS08;
}

bdf::types::card matds13::head = bdf::types::card("MATDS13");
matds13::matds13(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds13::card_type() const {
    return cards::types::MATDS13;
}

bdf::types::card matds14::head = bdf::types::card("MATDS14");
matds14::matds14(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds14::card_type() const {
    return cards::types::MATDS14;
}

bdf::types::card matds15::head = bdf::types::card("MATDS15");
matds15::matds15(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matds15::card_type() const {
    return cards::types::MATDS15;
}

bdf::types::card matdt01::head = bdf::types::card("MATDT01");
matdt01::matdt01(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdt01::card_type() const {
    return cards::types::MATDT01;
}

bdf::types::card matdt02::head = bdf::types::card("MATDT02");
matdt02::matdt02(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdt02::card_type() const {
    return cards::types::MATDT02;
}

bdf::types::card matdt03::head = bdf::types::card("MATDT03");
matdt03::matdt03(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdt03::card_type() const {
    return cards::types::MATDT03;
}

bdf::types::card matdt04::head = bdf::types::card("MATDT04");
matdt04::matdt04(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdt04::card_type() const {
    return cards::types::MATDT04;
}

bdf::types::card matdt05::head = bdf::types::card("MATDT05");
matdt05::matdt05(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdt05::card_type() const {
    return cards::types::MATDT05;
}

bdf::types::card matdt06::head = bdf::types::card("MATDT06");
matdt06::matdt06(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdt06::card_type() const {
    return cards::types::MATDT06;
}

bdf::types::card matdsw1::head = bdf::types::card("MATDSW1");
matdsw1::matdsw1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdsw1::card_type() const {
    return cards::types::MATDSW1;
}

bdf::types::card matdsw2::head = bdf::types::card("MATDSW2");
matdsw2::matdsw2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdsw2::card_type() const {
    return cards::types::MATDSW2;
}

bdf::types::card matdsw3::head = bdf::types::card("MATDSW3");
matdsw3::matdsw3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdsw3::card_type() const {
    return cards::types::MATDSW3;
}

bdf::types::card matdsw4::head = bdf::types::card("MATDSW4");
matdsw4::matdsw4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdsw4::card_type() const {
    return cards::types::MATDSW4;
}

bdf::types::card matdsw5::head = bdf::types::card("MATDSW5");
matdsw5::matdsw5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matdsw5::card_type() const {
    return cards::types::MATDSW5;
}

bdf::types::card matep::head = bdf::types::card("MATEP");
matep::matep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matep::card_type() const {
    return cards::types::MATEP;
}

bdf::types::card matf::head = bdf::types::card("MATF");
matf::matf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matf::card_type() const {
    return cards::types::MATF;
}

bdf::types::card matf1::head = bdf::types::card("MATF1");
matf1::matf1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matf1::card_type() const {
    return cards::types::MATF1;
}

bdf::types::card matftg::head = bdf::types::card("MATFTG");
matftg::matftg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matftg::card_type() const {
    return cards::types::MATFTG;
}

bdf::types::card matg::head = bdf::types::card("MATG");
matg::matg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matg::card_type() const {
    return cards::types::MATG;
}

bdf::types::card mathe::head = bdf::types::card("MATHE");
mathe::mathe(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mathe::card_type() const {
    return cards::types::MATHE;
}

bdf::types::card mathed::head = bdf::types::card("MATHED");
mathed::mathed(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mathed::card_type() const {
    return cards::types::MATHED;
}

bdf::types::card mathp::head = bdf::types::card("MATHP");
mathp::mathp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mathp::card_type() const {
    return cards::types::MATHP;
}

bdf::types::card matnle::head = bdf::types::card("MATNLE");
matnle::matnle(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matnle::card_type() const {
    return cards::types::MATNLE;
}

bdf::types::card matort::head = bdf::types::card("MATORT");
matort::matort(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matort::card_type() const {
    return cards::types::MATORT;
}

bdf::types::card matpe1::head = bdf::types::card("MATPE1");
matpe1::matpe1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matpe1::card_type() const {
    return cards::types::MATPE1;
}

bdf::types::card matrig::head = bdf::types::card("MATRIG");
matrig::matrig(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matrig::card_type() const {
    return cards::types::MATRIG;
}

bdf::types::card mats1::head = bdf::types::card("MATS1");
mats1::mats1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mats1::card_type() const {
    return cards::types::MATS1;
}

bdf::types::card mats3::head = bdf::types::card("MATS3");
mats3::mats3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mats3::card_type() const {
    return cards::types::MATS3;
}

bdf::types::card mats8::head = bdf::types::card("MATS8");
mats8::mats8(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mats8::card_type() const {
    return cards::types::MATS8;
}

bdf::types::card matsma::head = bdf::types::card("MATSMA");
matsma::matsma(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matsma::card_type() const {
    return cards::types::MATSMA;
}

bdf::types::card matsort::head = bdf::types::card("MATSORT");
matsort::matsort(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matsort::card_type() const {
    return cards::types::MATSORT;
}

bdf::types::card matt1::head = bdf::types::card("MATT1");
matt1::matt1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt1::card_type() const {
    return cards::types::MATT1;
}

bdf::types::card matt2::head = bdf::types::card("MATT2");
matt2::matt2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt2::card_type() const {
    return cards::types::MATT2;
}

bdf::types::card matt3::head = bdf::types::card("MATT3");
matt3::matt3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt3::card_type() const {
    return cards::types::MATT3;
}

bdf::types::card matt4::head = bdf::types::card("MATT4");
matt4::matt4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt4::card_type() const {
    return cards::types::MATT4;
}

bdf::types::card matt5::head = bdf::types::card("MATT5");
matt5::matt5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt5::card_type() const {
    return cards::types::MATT5;
}

bdf::types::card matt8::head = bdf::types::card("MATT8");
matt8::matt8(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt8::card_type() const {
    return cards::types::MATT8;
}

bdf::types::card matt9::head = bdf::types::card("MATT9");
matt9::matt9(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matt9::card_type() const {
    return cards::types::MATT9;
}

bdf::types::card mattep::head = bdf::types::card("MATTEP");
mattep::mattep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mattep::card_type() const {
    return cards::types::MATTEP;
}

bdf::types::card mattf::head = bdf::types::card("MATTF");
mattf::mattf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mattf::card_type() const {
    return cards::types::MATTF;
}

bdf::types::card mattg::head = bdf::types::card("MATTG");
mattg::mattg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mattg::card_type() const {
    return cards::types::MATTG;
}

bdf::types::card matthe::head = bdf::types::card("MATTHE");
matthe::matthe(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matthe::card_type() const {
    return cards::types::MATTHE;
}

bdf::types::card mattort::head = bdf::types::card("MATTORT");
mattort::mattort(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mattort::card_type() const {
    return cards::types::MATTORT;
}

bdf::types::card mattusr::head = bdf::types::card("MATTUSR");
mattusr::mattusr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mattusr::card_type() const {
    return cards::types::MATTUSR;
}

bdf::types::card mattve::head = bdf::types::card("MATTVE");
mattve::mattve(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mattve::card_type() const {
    return cards::types::MATTVE;
}

bdf::types::card matuds::head = bdf::types::card("MATUDS");
matuds::matuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matuds::card_type() const {
    return cards::types::MATUDS;
}

bdf::types::card matusr::head = bdf::types::card("MATUSR");
matusr::matusr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matusr::card_type() const {
    return cards::types::MATUSR;
}

bdf::types::card matve::head = bdf::types::card("MATVE");
matve::matve(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matve::card_type() const {
    return cards::types::MATVE;
}

bdf::types::card matvp::head = bdf::types::card("MATVP");
matvp::matvp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types matvp::card_type() const {
    return cards::types::MATVP;
}

bdf::types::card mauxcmd::head = bdf::types::card("MAUXCMD");
mauxcmd::mauxcmd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mauxcmd::card_type() const {
    return cards::types::MAUXCMD;
}

bdf::types::card mbolt::head = bdf::types::card("MBOLT");
mbolt::mbolt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mbolt::card_type() const {
    return cards::types::MBOLT;
}

bdf::types::card mboltus::head = bdf::types::card("MBOLTUS");
mboltus::mboltus(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mboltus::card_type() const {
    return cards::types::MBOLTUS;
}

bdf::types::card mchstat::head = bdf::types::card("MCHSTAT");
mchstat::mchstat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mchstat::card_type() const {
    return cards::types::MCHSTAT;
}

bdf::types::card mcohe::head = bdf::types::card("MCOHE");
mcohe::mcohe(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mcohe::card_type() const {
    return cards::types::MCOHE;
}

bdf::types::card mdelam::head = bdf::types::card("MDELAM");
mdelam::mdelam(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mdelam::card_type() const {
    return cards::types::MDELAM;
}

bdf::types::card mdlprm::head = bdf::types::card("MDLPRM");
mdlprm::mdlprm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mdlprm::card_type() const {
    return cards::types::MDLPRM;
}

bdf::types::card mdmiaux::head = bdf::types::card("MDMIAUX");
mdmiaux::mdmiaux(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mdmiaux::card_type() const {
    return cards::types::MDMIAUX;
}

bdf::types::card mdmiout::head = bdf::types::card("MDMIOUT");
mdmiout::mdmiout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mdmiout::card_type() const {
    return cards::types::MDMIOUT;
}

bdf::types::card mesh::head = bdf::types::card("MESH");
mesh::mesh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mesh::card_type() const {
    return cards::types::MESH;
}

bdf::types::card mesuper::head = bdf::types::card("MESUPER");
mesuper::mesuper(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mesuper::card_type() const {
    return cards::types::MESUPER;
}

bdf::types::card metadata::head = bdf::types::card("METADATA");
metadata::metadata(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types metadata::card_type() const {
    return cards::types::METADATA;
}

bdf::types::card mfluid::head = bdf::types::card("MFLUID");
mfluid::mfluid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mfluid::card_type() const {
    return cards::types::MFLUID;
}

bdf::types::card mgrspr::head = bdf::types::card("MGRSPR");
mgrspr::mgrspr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mgrspr::card_type() const {
    return cards::types::MGRSPR;
}

bdf::types::card minstat::head = bdf::types::card("MINSTAT");
minstat::minstat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types minstat::card_type() const {
    return cards::types::MINSTAT;
}

bdf::types::card misland::head = bdf::types::card("MISLAND");
misland::misland(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types misland::card_type() const {
    return cards::types::MISLAND;
}

bdf::types::card mixture::head = bdf::types::card("MIXTURE");
mixture::mixture(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mixture::card_type() const {
    return cards::types::MIXTURE;
}

bdf::types::card mkaero1::head = bdf::types::card("MKAERO1");
mkaero1::mkaero1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mkaero1::card_type() const {
    return cards::types::MKAERO1;
}

bdf::types::card mkaero2::head = bdf::types::card("MKAERO2");
mkaero2::mkaero2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mkaero2::card_type() const {
    return cards::types::MKAERO2;
}

bdf::types::card mlayout::head = bdf::types::card("MLAYOUT");
mlayout::mlayout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mlayout::card_type() const {
    return cards::types::MLAYOUT;
}

bdf::types::card mnf600::head = bdf::types::card("MNF600");
mnf600::mnf600(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mnf600::card_type() const {
    return cards::types::MNF600;
}

bdf::types::card modtrak::head = bdf::types::card("MODTRAK");
modtrak::modtrak(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types modtrak::card_type() const {
    return cards::types::MODTRAK;
}

bdf::types::card momax::head = bdf::types::card("MOMAX");
momax::momax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types momax::card_type() const {
    return cards::types::MOMAX;
}

bdf::types::card moment1::head = bdf::types::card("MOMENT1");
moment1::moment1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types moment1::card_type() const {
    return cards::types::MOMENT1;
}

bdf::types::card moment2::head = bdf::types::card("MOMENT2");
moment2::moment2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types moment2::card_type() const {
    return cards::types::MOMENT2;
}

bdf::types::card moncarl::head = bdf::types::card("MONCARL");
moncarl::moncarl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types moncarl::card_type() const {
    return cards::types::MONCARL;
}

bdf::types::card moncncm::head = bdf::types::card("MONCNCM");
moncncm::moncncm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types moncncm::card_type() const {
    return cards::types::MONCNCM;
}

bdf::types::card mondsp1::head = bdf::types::card("MONDSP1");
mondsp1::mondsp1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mondsp1::card_type() const {
    return cards::types::MONDSP1;
}

bdf::types::card mongrp::head = bdf::types::card("MONGRP");
mongrp::mongrp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mongrp::card_type() const {
    return cards::types::MONGRP;
}

bdf::types::card monpnt1::head = bdf::types::card("MONPNT1");
monpnt1::monpnt1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types monpnt1::card_type() const {
    return cards::types::MONPNT1;
}

bdf::types::card monpnt2::head = bdf::types::card("MONPNT2");
monpnt2::monpnt2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types monpnt2::card_type() const {
    return cards::types::MONPNT2;
}

bdf::types::card monpnt3::head = bdf::types::card("MONPNT3");
monpnt3::monpnt3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types monpnt3::card_type() const {
    return cards::types::MONPNT3;
}

bdf::types::card monsum::head = bdf::types::card("MONSUM");
monsum::monsum(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types monsum::card_type() const {
    return cards::types::MONSUM;
}

bdf::types::card monsum1::head = bdf::types::card("MONSUM1");
monsum1::monsum1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types monsum1::card_type() const {
    return cards::types::MONSUM1;
}

bdf::types::card monsumt::head = bdf::types::card("MONSUMT");
monsumt::monsumt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types monsumt::card_type() const {
    return cards::types::MONSUMT;
}

bdf::types::card mpc::head = bdf::types::card("MPC");
mpc::mpc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpc::card_type() const {
    return cards::types::MPC;
}

bdf::types::card mpcadd::head = bdf::types::card("MPCADD");
mpcadd::mpcadd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpcadd::card_type() const {
    return cards::types::MPCADD;
}

bdf::types::card mpcax::head = bdf::types::card("MPCAX");
mpcax::mpcax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpcax::card_type() const {
    return cards::types::MPCAX;
}

bdf::types::card mpcd::head = bdf::types::card("MPCD");
mpcd::mpcd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpcd::card_type() const {
    return cards::types::MPCD;
}

bdf::types::card mpcreep::head = bdf::types::card("MPCREEP");
mpcreep::mpcreep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpcreep::card_type() const {
    return cards::types::MPCREEP;
}

bdf::types::card mpcy::head = bdf::types::card("MPCY");
mpcy::mpcy(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpcy::card_type() const {
    return cards::types::MPCY;
}

bdf::types::card mpheat::head = bdf::types::card("MPHEAT");
mpheat::mpheat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mpheat::card_type() const {
    return cards::types::MPHEAT;
}

bdf::types::card mprocs::head = bdf::types::card("MPROCS");
mprocs::mprocs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mprocs::card_type() const {
    return cards::types::MPROCS;
}

bdf::types::card mrevers::head = bdf::types::card("MREVERS");
mrevers::mrevers(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mrevers::card_type() const {
    return cards::types::MREVERS;
}

bdf::types::card mrsscon::head = bdf::types::card("MRSSCON");
mrsscon::mrsscon(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mrsscon::card_type() const {
    return cards::types::MRSSCON;
}

bdf::types::card mstack::head = bdf::types::card("MSTACK");
mstack::mstack(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mstack::card_type() const {
    return cards::types::MSTACK;
}

bdf::types::card mt16sel::head = bdf::types::card("MT16SEL");
mt16sel::mt16sel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mt16sel::card_type() const {
    return cards::types::MT16SEL;
}

bdf::types::card mt16spl::head = bdf::types::card("MT16SPL");
mt16spl::mt16spl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mt16spl::card_type() const {
    return cards::types::MT16SPL;
}

bdf::types::card mtabrv::head = bdf::types::card("MTABRV");
mtabrv::mtabrv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mtabrv::card_type() const {
    return cards::types::MTABRV;
}

bdf::types::card mtcreep::head = bdf::types::card("MTCREEP");
mtcreep::mtcreep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mtcreep::card_type() const {
    return cards::types::MTCREEP;
}

bdf::types::card mtherm::head = bdf::types::card("MTHERM");
mtherm::mtherm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types mtherm::card_type() const {
    return cards::types::MTHERM;
}

bdf::types::card nladapt::head = bdf::types::card("NLADAPT");
nladapt::nladapt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nladapt::card_type() const {
    return cards::types::NLADAPT;
}

bdf::types::card nlauto::head = bdf::types::card("NLAUTO");
nlauto::nlauto(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlauto::card_type() const {
    return cards::types::NLAUTO;
}

bdf::types::card nlcysym::head = bdf::types::card("NLCYSYM");
nlcysym::nlcysym(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlcysym::card_type() const {
    return cards::types::NLCYSYM;
}

bdf::types::card nldamp::head = bdf::types::card("NLDAMP");
nldamp::nldamp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nldamp::card_type() const {
    return cards::types::NLDAMP;
}

bdf::types::card nlfreq::head = bdf::types::card("NLFREQ");
nlfreq::nlfreq(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlfreq::card_type() const {
    return cards::types::NLFREQ;
}

bdf::types::card nlfreq1::head = bdf::types::card("NLFREQ1");
nlfreq1::nlfreq1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlfreq1::card_type() const {
    return cards::types::NLFREQ1;
}

bdf::types::card nlharm::head = bdf::types::card("NLHARM");
nlharm::nlharm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlharm::card_type() const {
    return cards::types::NLHARM;
}

bdf::types::card nlheatc::head = bdf::types::card("NLHEATC");
nlheatc::nlheatc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlheatc::card_type() const {
    return cards::types::NLHEATC;
}

bdf::types::card nlmopts::head = bdf::types::card("NLMOPTS");
nlmopts::nlmopts(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlmopts::card_type() const {
    return cards::types::NLMOPTS;
}

bdf::types::card nlout::head = bdf::types::card("NLOUT");
nlout::nlout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlout::card_type() const {
    return cards::types::NLOUT;
}

bdf::types::card nloutud::head = bdf::types::card("NLOUTUD");
nloutud::nloutud(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nloutud::card_type() const {
    return cards::types::NLOUTUD;
}

bdf::types::card nlparm::head = bdf::types::card("NLPARM");
nlparm::nlparm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlparm::card_type() const {
    return cards::types::NLPARM;
}

bdf::types::card nlpci::head = bdf::types::card("NLPCI");
nlpci::nlpci(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlpci::card_type() const {
    return cards::types::NLPCI;
}

bdf::types::card nlrgap::head = bdf::types::card("NLRGAP");
nlrgap::nlrgap(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlrgap::card_type() const {
    return cards::types::NLRGAP;
}

bdf::types::card nlrsfd::head = bdf::types::card("NLRSFD");
nlrsfd::nlrsfd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlrsfd::card_type() const {
    return cards::types::NLRSFD;
}

bdf::types::card nlstep::head = bdf::types::card("NLSTEP");
nlstep::nlstep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlstep::card_type() const {
    return cards::types::NLSTEP;
}

bdf::types::card nlstrat::head = bdf::types::card("NLSTRAT");
nlstrat::nlstrat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nlstrat::card_type() const {
    return cards::types::NLSTRAT;
}

bdf::types::card nolin1::head = bdf::types::card("NOLIN1");
nolin1::nolin1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nolin1::card_type() const {
    return cards::types::NOLIN1;
}

bdf::types::card nolin2::head = bdf::types::card("NOLIN2");
nolin2::nolin2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nolin2::card_type() const {
    return cards::types::NOLIN2;
}

bdf::types::card nolin3::head = bdf::types::card("NOLIN3");
nolin3::nolin3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nolin3::card_type() const {
    return cards::types::NOLIN3;
}

bdf::types::card nolin4::head = bdf::types::card("NOLIN4");
nolin4::nolin4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nolin4::card_type() const {
    return cards::types::NOLIN4;
}

bdf::types::card nsm::head = bdf::types::card("NSM");
nsm::nsm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nsm::card_type() const {
    return cards::types::NSM;
}

bdf::types::card nsm1::head = bdf::types::card("NSM1");
nsm1::nsm1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nsm1::card_type() const {
    return cards::types::NSM1;
}

bdf::types::card nsmadd::head = bdf::types::card("NSMADD");
nsmadd::nsmadd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nsmadd::card_type() const {
    return cards::types::NSMADD;
}

bdf::types::card nsml::head = bdf::types::card("NSML");
nsml::nsml(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nsml::card_type() const {
    return cards::types::NSML;
}

bdf::types::card nsml1::head = bdf::types::card("NSML1");
nsml1::nsml1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nsml1::card_type() const {
    return cards::types::NSML1;
}

bdf::types::card nthick::head = bdf::types::card("NTHICK");
nthick::nthick(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types nthick::card_type() const {
    return cards::types::NTHICK;
}

bdf::types::card omit::head = bdf::types::card("OMIT");
omit::omit(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types omit::card_type() const {
    return cards::types::OMIT;
}

bdf::types::card omit1::head = bdf::types::card("OMIT1");
omit1::omit1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types omit1::card_type() const {
    return cards::types::OMIT1;
}

bdf::types::card omitax::head = bdf::types::card("OMITAX");
omitax::omitax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types omitax::card_type() const {
    return cards::types::OMITAX;
}

bdf::types::card output::head = bdf::types::card("OUTPUT");
output::output(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types output::card_type() const {
    return cards::types::OUTPUT;
}

bdf::types::card outrcv::head = bdf::types::card("OUTRCV");
outrcv::outrcv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types outrcv::card_type() const {
    return cards::types::OUTRCV;
}

bdf::types::card paabsf::head = bdf::types::card("PAABSF");
paabsf::paabsf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paabsf::card_type() const {
    return cards::types::PAABSF;
}

bdf::types::card pacabs::head = bdf::types::card("PACABS");
pacabs::pacabs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pacabs::card_type() const {
    return cards::types::PACABS;
}

bdf::types::card pacbar::head = bdf::types::card("PACBAR");
pacbar::pacbar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pacbar::card_type() const {
    return cards::types::PACBAR;
}

bdf::types::card pacinf::head = bdf::types::card("PACINF");
pacinf::pacinf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pacinf::card_type() const {
    return cards::types::PACINF;
}

bdf::types::card paero1::head = bdf::types::card("PAERO1");
paero1::paero1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paero1::card_type() const {
    return cards::types::PAERO1;
}

bdf::types::card paero2::head = bdf::types::card("PAERO2");
paero2::paero2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paero2::card_type() const {
    return cards::types::PAERO2;
}

bdf::types::card paero3::head = bdf::types::card("PAERO3");
paero3::paero3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paero3::card_type() const {
    return cards::types::PAERO3;
}

bdf::types::card paero4::head = bdf::types::card("PAERO4");
paero4::paero4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paero4::card_type() const {
    return cards::types::PAERO4;
}

bdf::types::card paero5::head = bdf::types::card("PAERO5");
paero5::paero5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paero5::card_type() const {
    return cards::types::PAERO5;
}

bdf::types::card panel::head = bdf::types::card("PANEL");
panel::panel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types panel::card_type() const {
    return cards::types::PANEL;
}

bdf::types::card paramarc::head = bdf::types::card("PARAMARC");
paramarc::paramarc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paramarc::card_type() const {
    return cards::types::PARAMARC;
}

bdf::types::card paxisym::head = bdf::types::card("PAXISYM");
paxisym::paxisym(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paxisym::card_type() const {
    return cards::types::PAXISYM;
}

bdf::types::card paxsymh::head = bdf::types::card("PAXSYMH");
paxsymh::paxsymh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types paxsymh::card_type() const {
    return cards::types::PAXSYMH;
}

bdf::types::card pbarn1::head = bdf::types::card("PBARN1");
pbarn1::pbarn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbarn1::card_type() const {
    return cards::types::PBARN1;
}

bdf::types::card pbcomp::head = bdf::types::card("PBCOMP");
pbcomp::pbcomp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbcomp::card_type() const {
    return cards::types::PBCOMP;
}

bdf::types::card pbdiscr::head = bdf::types::card("PBDISCR");
pbdiscr::pbdiscr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbdiscr::card_type() const {
    return cards::types::PBDISCR;
}

bdf::types::card pbeam3::head = bdf::types::card("PBEAM3");
pbeam3::pbeam3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbeam3::card_type() const {
    return cards::types::PBEAM3;
}

bdf::types::card pbeam71::head = bdf::types::card("PBEAM71");
pbeam71::pbeam71(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbeam71::card_type() const {
    return cards::types::PBEAM71;
}

bdf::types::card pbeamd::head = bdf::types::card("PBEAMD");
pbeamd::pbeamd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbeamd::card_type() const {
    return cards::types::PBEAMD;
}

bdf::types::card pbeltd::head = bdf::types::card("PBELTD");
pbeltd::pbeltd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbeltd::card_type() const {
    return cards::types::PBELTD;
}

bdf::types::card pbemn1::head = bdf::types::card("PBEMN1");
pbemn1::pbemn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbemn1::card_type() const {
    return cards::types::PBEMN1;
}

bdf::types::card pbend::head = bdf::types::card("PBEND");
pbend::pbend(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbend::card_type() const {
    return cards::types::PBEND;
}

bdf::types::card pbmarb6::head = bdf::types::card("PBMARB6");
pbmarb6::pbmarb6(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbmarb6::card_type() const {
    return cards::types::PBMARB6;
}

bdf::types::card pbmnum6::head = bdf::types::card("PBMNUM6");
pbmnum6::pbmnum6(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbmnum6::card_type() const {
    return cards::types::PBMNUM6;
}

bdf::types::card pbmsect::head = bdf::types::card("PBMSECT");
pbmsect::pbmsect(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbmsect::card_type() const {
    return cards::types::PBMSECT;
}

bdf::types::card pbrsect::head = bdf::types::card("PBRSECT");
pbrsect::pbrsect(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbrsect::card_type() const {
    return cards::types::PBRSECT;
}

bdf::types::card pbspot::head = bdf::types::card("PBSPOT");
pbspot::pbspot(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbspot::card_type() const {
    return cards::types::PBSPOT;
}

bdf::types::card pbush1d::head = bdf::types::card("PBUSH1D");
pbush1d::pbush1d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbush1d::card_type() const {
    return cards::types::PBUSH1D;
}

bdf::types::card pbush2d::head = bdf::types::card("PBUSH2D");
pbush2d::pbush2d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbush2d::card_type() const {
    return cards::types::PBUSH2D;
}

bdf::types::card pbusht::head = bdf::types::card("PBUSHT");
pbusht::pbusht(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pbusht::card_type() const {
    return cards::types::PBUSHT;
}

bdf::types::card pcohe::head = bdf::types::card("PCOHE");
pcohe::pcohe(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pcohe::card_type() const {
    return cards::types::PCOHE;
}

bdf::types::card pcomp::head = bdf::types::card("PCOMP");
pcomp::pcomp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pcomp::card_type() const {
    return cards::types::PCOMP;
}

bdf::types::card pcompa::head = bdf::types::card("PCOMPA");
pcompa::pcompa(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pcompa::card_type() const {
    return cards::types::PCOMPA;
}

bdf::types::card pcompf::head = bdf::types::card("PCOMPF");
pcompf::pcompf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pcompf::card_type() const {
    return cards::types::PCOMPF;
}

bdf::types::card pcompg::head = bdf::types::card("PCOMPG");
pcompg::pcompg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pcompg::card_type() const {
    return cards::types::PCOMPG;
}

bdf::types::card pcompls::head = bdf::types::card("PCOMPLS");
pcompls::pcompls(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pcompls::card_type() const {
    return cards::types::PCOMPLS;
}

bdf::types::card pconeax::head = bdf::types::card("PCONEAX");
pconeax::pconeax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pconeax::card_type() const {
    return cards::types::PCONEAX;
}

bdf::types::card pconv::head = bdf::types::card("PCONV");
pconv::pconv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pconv::card_type() const {
    return cards::types::PCONV;
}

bdf::types::card pconvm::head = bdf::types::card("PCONVM");
pconvm::pconvm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pconvm::card_type() const {
    return cards::types::PCONVM;
}

bdf::types::card pconv1::head = bdf::types::card("PCONV1");
pconv1::pconv1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pconv1::card_type() const {
    return cards::types::PCONV1;
}

bdf::types::card pdamp::head = bdf::types::card("PDAMP");
pdamp::pdamp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pdamp::card_type() const {
    return cards::types::PDAMP;
}

bdf::types::card pdamp5::head = bdf::types::card("PDAMP5");
pdamp5::pdamp5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pdamp5::card_type() const {
    return cards::types::PDAMP5;
}

bdf::types::card pdampt::head = bdf::types::card("PDAMPT");
pdampt::pdampt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pdampt::card_type() const {
    return cards::types::PDAMPT;
}

bdf::types::card pdumi::head = bdf::types::card("PDUMi");
pdumi::pdumi(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pdumi::card_type() const {
    return cards::types::PDUMi;
}

bdf::types::card pelas::head = bdf::types::card("PELAS");
pelas::pelas(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pelas::card_type() const {
    return cards::types::PELAS;
}

bdf::types::card pelas1::head = bdf::types::card("PELAS1");
pelas1::pelas1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pelas1::card_type() const {
    return cards::types::PELAS1;
}

bdf::types::card pelast::head = bdf::types::card("PELAST");
pelast::pelast(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pelast::card_type() const {
    return cards::types::PELAST;
}

bdf::types::card permeab::head = bdf::types::card("PERMEAB");
permeab::permeab(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types permeab::card_type() const {
    return cards::types::PERMEAB;
}

bdf::types::card permgbg::head = bdf::types::card("PERMGBG");
permgbg::permgbg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types permgbg::card_type() const {
    return cards::types::PERMGBG;
}

bdf::types::card peuler::head = bdf::types::card("PEULER");
peuler::peuler(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types peuler::card_type() const {
    return cards::types::PEULER;
}

bdf::types::card peuler1::head = bdf::types::card("PEULER1");
peuler1::peuler1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types peuler1::card_type() const {
    return cards::types::PEULER1;
}

bdf::types::card pfast::head = bdf::types::card("PFAST");
pfast::pfast(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pfast::card_type() const {
    return cards::types::PFAST;
}

bdf::types::card pftg::head = bdf::types::card("PFTG");
pftg::pftg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pftg::card_type() const {
    return cards::types::PFTG;
}

bdf::types::card pgap::head = bdf::types::card("PGAP");
pgap::pgap(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pgap::card_type() const {
    return cards::types::PGAP;
}

bdf::types::card phbdy::head = bdf::types::card("PHBDY");
phbdy::phbdy(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types phbdy::card_type() const {
    return cards::types::PHBDY;
}

bdf::types::card pintc::head = bdf::types::card("PINTC");
pintc::pintc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pintc::card_type() const {
    return cards::types::PINTC;
}

bdf::types::card pints::head = bdf::types::card("PINTS");
pints::pints(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pints::card_type() const {
    return cards::types::PINTS;
}

bdf::types::card plblast::head = bdf::types::card("PLBLAST");
plblast::plblast(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types plblast::card_type() const {
    return cards::types::PLBLAST;
}

bdf::types::card plcomp::head = bdf::types::card("PLCOMP");
plcomp::plcomp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types plcomp::card_type() const {
    return cards::types::PLCOMP;
}

bdf::types::card pload::head = bdf::types::card("PLOAD");
pload::pload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pload::card_type() const {
    return cards::types::PLOAD;
}

bdf::types::card pload1::head = bdf::types::card("PLOAD1");
pload1::pload1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pload1::card_type() const {
    return cards::types::PLOAD1;
}

bdf::types::card pload2::head = bdf::types::card("PLOAD2");
pload2::pload2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pload2::card_type() const {
    return cards::types::PLOAD2;
}

bdf::types::card pload4::head = bdf::types::card("PLOAD4");
pload4::pload4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pload4::card_type() const {
    return cards::types::PLOAD4;
}

bdf::types::card ploadb3::head = bdf::types::card("PLOADB3");
ploadb3::ploadb3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ploadb3::card_type() const {
    return cards::types::PLOADB3;
}

bdf::types::card ploadx1::head = bdf::types::card("PLOADX1");
ploadx1::ploadx1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ploadx1::card_type() const {
    return cards::types::PLOADX1;
}

bdf::types::card plplane::head = bdf::types::card("PLPLANE");
plplane::plplane(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types plplane::card_type() const {
    return cards::types::PLPLANE;
}

bdf::types::card plsolid::head = bdf::types::card("PLSOLID");
plsolid::plsolid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types plsolid::card_type() const {
    return cards::types::PLSOLID;
}

bdf::types::card pmarker::head = bdf::types::card("PMARKER");
pmarker::pmarker(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pmarker::card_type() const {
    return cards::types::PMARKER;
}

bdf::types::card pmass::head = bdf::types::card("PMASS");
pmass::pmass(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pmass::card_type() const {
    return cards::types::PMASS;
}

bdf::types::card pminc::head = bdf::types::card("PMINC");
pminc::pminc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pminc::card_type() const {
    return cards::types::PMINC;
}

bdf::types::card pmrebai::head = bdf::types::card("PMREBAI");
pmrebai::pmrebai(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pmrebai::card_type() const {
    return cards::types::PMREBAI;
}

bdf::types::card pmrebar::head = bdf::types::card("PMREBAR");
pmrebar::pmrebar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pmrebar::card_type() const {
    return cards::types::PMREBAR;
}

bdf::types::card point::head = bdf::types::card("POINT");
point::point(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types point::card_type() const {
    return cards::types::POINT;
}

bdf::types::card pointax::head = bdf::types::card("POINTAX");
pointax::pointax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pointax::card_type() const {
    return cards::types::POINTAX;
}

bdf::types::card porfcpl::head = bdf::types::card("PORFCPL");
porfcpl::porfcpl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types porfcpl::card_type() const {
    return cards::types::PORFCPL;
}

bdf::types::card porfgbg::head = bdf::types::card("PORFGBG");
porfgbg::porfgbg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types porfgbg::card_type() const {
    return cards::types::PORFGBG;
}

bdf::types::card porflow::head = bdf::types::card("PORFLOW");
porflow::porflow(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types porflow::card_type() const {
    return cards::types::PORFLOW;
}

bdf::types::card porflwt::head = bdf::types::card("PORFLWT");
porflwt::porflwt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types porflwt::card_type() const {
    return cards::types::PORFLWT;
}

bdf::types::card porhole::head = bdf::types::card("PORHOLE");
porhole::porhole(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types porhole::card_type() const {
    return cards::types::PORHOLE;
}

bdf::types::card porhyds::head = bdf::types::card("PORHYDS");
porhyds::porhyds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types porhyds::card_type() const {
    return cards::types::PORHYDS;
}

bdf::types::card poruds::head = bdf::types::card("PORUDS");
poruds::poruds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types poruds::card_type() const {
    return cards::types::PORUDS;
}

bdf::types::card prac2d::head = bdf::types::card("PRAC2D");
prac2d::prac2d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types prac2d::card_type() const {
    return cards::types::PRAC2D;
}

bdf::types::card prac3d::head = bdf::types::card("PRAC3D");
prac3d::prac3d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types prac3d::card_type() const {
    return cards::types::PRAC3D;
}

bdf::types::card presax::head = bdf::types::card("PRESAX");
presax::presax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types presax::card_type() const {
    return cards::types::PRESAX;
}

bdf::types::card prespt::head = bdf::types::card("PRESPT");
prespt::prespt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types prespt::card_type() const {
    return cards::types::PRESPT;
}

bdf::types::card prestrs::head = bdf::types::card("PRESTRS");
prestrs::prestrs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types prestrs::card_type() const {
    return cards::types::PRESTRS;
}

bdf::types::card primx::head = bdf::types::card("PRIMx");
primx::primx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types primx::card_type() const {
    return cards::types::PRIMx;
}

bdf::types::card prjcon::head = bdf::types::card("PRJCON");
prjcon::prjcon(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types prjcon::card_type() const {
    return cards::types::PRJCON;
}

bdf::types::card prodn1::head = bdf::types::card("PRODN1");
prodn1::prodn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types prodn1::card_type() const {
    return cards::types::PRODN1;
}

bdf::types::card pseam::head = bdf::types::card("PSEAM");
pseam::pseam(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pseam::card_type() const {
    return cards::types::PSEAM;
}

bdf::types::card pset::head = bdf::types::card("PSET");
pset::pset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pset::card_type() const {
    return cards::types::PSET;
}

bdf::types::card pshear::head = bdf::types::card("PSHEAR");
pshear::pshear(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pshear::card_type() const {
    return cards::types::PSHEAR;
}

bdf::types::card pshearn::head = bdf::types::card("PSHEARN");
pshearn::pshearn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pshearn::card_type() const {
    return cards::types::PSHEARN;
}

bdf::types::card pshell1::head = bdf::types::card("PSHELL1");
pshell1::pshell1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pshell1::card_type() const {
    return cards::types::PSHELL1;
}

bdf::types::card pshelld::head = bdf::types::card("PSHELLD");
pshelld::pshelld(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pshelld::card_type() const {
    return cards::types::PSHELLD;
}

bdf::types::card pshln1::head = bdf::types::card("PSHLN1");
pshln1::pshln1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pshln1::card_type() const {
    return cards::types::PSHLN1;
}

bdf::types::card pshln2::head = bdf::types::card("PSHLN2");
pshln2::pshln2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pshln2::card_type() const {
    return cards::types::PSHLN2;
}

bdf::types::card psldn1::head = bdf::types::card("PSLDN1");
psldn1::psldn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types psldn1::card_type() const {
    return cards::types::PSLDN1;
}

bdf::types::card psolid::head = bdf::types::card("PSOLID");
psolid::psolid(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types psolid::card_type() const {
    return cards::types::PSOLID;
}

bdf::types::card psolidd::head = bdf::types::card("PSOLIDD");
psolidd::psolidd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types psolidd::card_type() const {
    return cards::types::PSOLIDD;
}

bdf::types::card psph::head = bdf::types::card("PSPH");
psph::psph(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types psph::card_type() const {
    return cards::types::PSPH;
}

bdf::types::card psprmat::head = bdf::types::card("PSPRMAT");
psprmat::psprmat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types psprmat::card_type() const {
    return cards::types::PSPRMAT;
}

bdf::types::card psshl::head = bdf::types::card("PSSHL");
psshl::psshl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types psshl::card_type() const {
    return cards::types::PSSHL;
}

bdf::types::card ptshell::head = bdf::types::card("PTSHELL");
ptshell::ptshell(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ptshell::card_type() const {
    return cards::types::PTSHELL;
}

bdf::types::card ptube::head = bdf::types::card("PTUBE");
ptube::ptube(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ptube::card_type() const {
    return cards::types::PTUBE;
}

bdf::types::card pval::head = bdf::types::card("PVAL");
pval::pval(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pval::card_type() const {
    return cards::types::PVAL;
}

bdf::types::card pvisc::head = bdf::types::card("PVISC");
pvisc::pvisc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pvisc::card_type() const {
    return cards::types::PVISC;
}

bdf::types::card pweld::head = bdf::types::card("PWELD");
pweld::pweld(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types pweld::card_type() const {
    return cards::types::PWELD;
}

bdf::types::card qbdy1::head = bdf::types::card("QBDY1");
qbdy1::qbdy1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qbdy1::card_type() const {
    return cards::types::QBDY1;
}

bdf::types::card qbdy2::head = bdf::types::card("QBDY2");
qbdy2::qbdy2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qbdy2::card_type() const {
    return cards::types::QBDY2;
}

bdf::types::card qbdy3::head = bdf::types::card("QBDY3");
qbdy3::qbdy3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qbdy3::card_type() const {
    return cards::types::QBDY3;
}

bdf::types::card qbdy4::head = bdf::types::card("QBDY4");
qbdy4::qbdy4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qbdy4::card_type() const {
    return cards::types::QBDY4;
}

bdf::types::card qhbdy::head = bdf::types::card("QHBDY");
qhbdy::qhbdy(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qhbdy::card_type() const {
    return cards::types::QHBDY;
}

bdf::types::card qset::head = bdf::types::card("QSET");
qset::qset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qset::card_type() const {
    return cards::types::QSET;
}

bdf::types::card qset1::head = bdf::types::card("QSET1");
qset1::qset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qset1::card_type() const {
    return cards::types::QSET1;
}

bdf::types::card qvect::head = bdf::types::card("QVECT");
qvect::qvect(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qvect::card_type() const {
    return cards::types::QVECT;
}

bdf::types::card qvol::head = bdf::types::card("QVOL");
qvol::qvol(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types qvol::card_type() const {
    return cards::types::QVOL;
}

bdf::types::card radbc::head = bdf::types::card("RADBC");
radbc::radbc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radbc::card_type() const {
    return cards::types::RADBC;
}

bdf::types::card radbc2::head = bdf::types::card("RADBC2");
radbc2::radbc2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radbc2::card_type() const {
    return cards::types::RADBC2;
}

bdf::types::card radbnd::head = bdf::types::card("RADBND");
radbnd::radbnd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radbnd::card_type() const {
    return cards::types::RADBND;
}

bdf::types::card radc::head = bdf::types::card("RADC");
radc::radc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radc::card_type() const {
    return cards::types::RADC;
}

bdf::types::card radcav::head = bdf::types::card("RADCAV");
radcav::radcav(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radcav::card_type() const {
    return cards::types::RADCAV;
}

bdf::types::card radcol::head = bdf::types::card("RADCOL");
radcol::radcol(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radcol::card_type() const {
    return cards::types::RADCOL;
}

bdf::types::card radct::head = bdf::types::card("RADCT");
radct::radct(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radct::card_type() const {
    return cards::types::RADCT;
}

bdf::types::card radlst::head = bdf::types::card("RADLST");
radlst::radlst(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radlst::card_type() const {
    return cards::types::RADLST;
}

bdf::types::card radm::head = bdf::types::card("RADM");
radm::radm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radm::card_type() const {
    return cards::types::RADM;
}

bdf::types::card radmt::head = bdf::types::card("RADMT");
radmt::radmt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radmt::card_type() const {
    return cards::types::RADMT;
}

bdf::types::card radmtx::head = bdf::types::card("RADMTX");
radmtx::radmtx(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radmtx::card_type() const {
    return cards::types::RADMTX;
}

bdf::types::card radset::head = bdf::types::card("RADSET");
radset::radset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types radset::card_type() const {
    return cards::types::RADSET;
}

bdf::types::card randps::head = bdf::types::card("RANDPS");
randps::randps(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types randps::card_type() const {
    return cards::types::RANDPS;
}

bdf::types::card randt1::head = bdf::types::card("RANDT1");
randt1::randt1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types randt1::card_type() const {
    return cards::types::RANDT1;
}

bdf::types::card rbax3d::head = bdf::types::card("RBAX3D");
rbax3d::rbax3d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbax3d::card_type() const {
    return cards::types::RBAX3D;
}

bdf::types::card rbe2a::head = bdf::types::card("RBE2A");
rbe2a::rbe2a(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbe2a::card_type() const {
    return cards::types::RBE2A;
}

bdf::types::card rbe2f::head = bdf::types::card("RBE2F");
rbe2f::rbe2f(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbe2f::card_type() const {
    return cards::types::RBE2F;
}

bdf::types::card rbe2gs::head = bdf::types::card("RBE2GS");
rbe2gs::rbe2gs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbe2gs::card_type() const {
    return cards::types::RBE2GS;
}

bdf::types::card rbe3u::head = bdf::types::card("RBE3U");
rbe3u::rbe3u(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbe3u::card_type() const {
    return cards::types::RBE3U;
}

bdf::types::card rbjoint::head = bdf::types::card("RBJOINT");
rbjoint::rbjoint(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbjoint::card_type() const {
    return cards::types::RBJOINT;
}

bdf::types::card rbjstif::head = bdf::types::card("RBJSTIF");
rbjstif::rbjstif(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rbjstif::card_type() const {
    return cards::types::RBJSTIF;
}

bdf::types::card rconn::head = bdf::types::card("RCONN");
rconn::rconn(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rconn::card_type() const {
    return cards::types::RCONN;
}

bdf::types::card rcparm::head = bdf::types::card("RCPARM");
rcparm::rcparm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rcparm::card_type() const {
    return cards::types::RCPARM;
}

bdf::types::card rcross::head = bdf::types::card("RCROSS");
rcross::rcross(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rcross::card_type() const {
    return cards::types::RCROSS;
}

bdf::types::card release::head = bdf::types::card("RELEASE");
release::release(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types release::card_type() const {
    return cards::types::RELEASE;
}

bdf::types::card restart::head = bdf::types::card("RESTART");
restart::restart(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types restart::card_type() const {
    return cards::types::RESTART;
}

bdf::types::card rforce::head = bdf::types::card("RFORCE");
rforce::rforce(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rforce::card_type() const {
    return cards::types::RFORCE;
}

bdf::types::card rgyro::head = bdf::types::card("RGYRO");
rgyro::rgyro(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rgyro::card_type() const {
    return cards::types::RGYRO;
}

bdf::types::card ringax::head = bdf::types::card("RINGAX");
ringax::ringax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ringax::card_type() const {
    return cards::types::RINGAX;
}

bdf::types::card ringfl::head = bdf::types::card("RINGFL");
ringfl::ringfl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ringfl::card_type() const {
    return cards::types::RINGFL;
}

bdf::types::card rload1::head = bdf::types::card("RLOAD1");
rload1::rload1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rload1::card_type() const {
    return cards::types::RLOAD1;
}

bdf::types::card rload2::head = bdf::types::card("RLOAD2");
rload2::rload2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rload2::card_type() const {
    return cards::types::RLOAD2;
}

bdf::types::card rothybd::head = bdf::types::card("ROTHYBD");
rothybd::rothybd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rothybd::card_type() const {
    return cards::types::ROTHYBD;
}

bdf::types::card rotor::head = bdf::types::card("ROTOR");
rotor::rotor(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rotor::card_type() const {
    return cards::types::ROTOR;
}

bdf::types::card rotorax::head = bdf::types::card("ROTORAX");
rotorax::rotorax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rotorax::card_type() const {
    return cards::types::ROTORAX;
}

bdf::types::card rotorg::head = bdf::types::card("ROTORG");
rotorg::rotorg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rotorg::card_type() const {
    return cards::types::ROTORG;
}

bdf::types::card rotorse::head = bdf::types::card("ROTORSE");
rotorse::rotorse(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rotorse::card_type() const {
    return cards::types::ROTORSE;
}

bdf::types::card rspinr::head = bdf::types::card("RSPINR");
rspinr::rspinr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rspinr::card_type() const {
    return cards::types::RSPINR;
}

bdf::types::card rspint::head = bdf::types::card("RSPINT");
rspint::rspint(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rspint::card_type() const {
    return cards::types::RSPINT;
}

bdf::types::card rvdof::head = bdf::types::card("RVDOF");
rvdof::rvdof(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rvdof::card_type() const {
    return cards::types::RVDOF;
}

bdf::types::card rvdof1::head = bdf::types::card("RVDOF1");
rvdof1::rvdof1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types rvdof1::card_type() const {
    return cards::types::RVDOF1;
}

bdf::types::card sangle::head = bdf::types::card("SANGLE");
sangle::sangle(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sangle::card_type() const {
    return cards::types::SANGLE;
}

bdf::types::card sbpret::head = bdf::types::card("SBPRET");
sbpret::sbpret(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sbpret::card_type() const {
    return cards::types::SBPRET;
}

bdf::types::card sbretr::head = bdf::types::card("SBRETR");
sbretr::sbretr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sbretr::card_type() const {
    return cards::types::SBRETR;
}

bdf::types::card sbsensr::head = bdf::types::card("SBSENSR");
sbsensr::sbsensr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sbsensr::card_type() const {
    return cards::types::SBSENSR;
}

bdf::types::card sbslpr::head = bdf::types::card("SBSLPR");
sbslpr::sbslpr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sbslpr::card_type() const {
    return cards::types::SBSLPR;
}

bdf::types::card sebndry::head = bdf::types::card("SEBNDRY");
sebndry::sebndry(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sebndry::card_type() const {
    return cards::types::SEBNDRY;
}

bdf::types::card sebset::head = bdf::types::card("SEBSET");
sebset::sebset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sebset::card_type() const {
    return cards::types::SEBSET;
}

bdf::types::card sebset1::head = bdf::types::card("SEBSET1");
sebset1::sebset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sebset1::card_type() const {
    return cards::types::SEBSET1;
}

bdf::types::card sebulk::head = bdf::types::card("SEBULK");
sebulk::sebulk(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sebulk::card_type() const {
    return cards::types::SEBULK;
}

bdf::types::card seconct::head = bdf::types::card("SECONCT");
seconct::seconct(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seconct::card_type() const {
    return cards::types::SECONCT;
}

bdf::types::card secset::head = bdf::types::card("SECSET");
secset::secset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types secset::card_type() const {
    return cards::types::SECSET;
}

bdf::types::card secset1::head = bdf::types::card("SECSET1");
secset1::secset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types secset1::card_type() const {
    return cards::types::SECSET1;
}

bdf::types::card sectax::head = bdf::types::card("SECTAX");
sectax::sectax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sectax::card_type() const {
    return cards::types::SECTAX;
}

bdf::types::card sedlink::head = bdf::types::card("SEDLINK");
sedlink::sedlink(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sedlink::card_type() const {
    return cards::types::SEDLINK;
}

bdf::types::card sedrsp2::head = bdf::types::card("SEDRSP2");
sedrsp2::sedrsp2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sedrsp2::card_type() const {
    return cards::types::SEDRSP2;
}

bdf::types::card sedrsp3::head = bdf::types::card("SEDRSP3");
sedrsp3::sedrsp3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sedrsp3::card_type() const {
    return cards::types::SEDRSP3;
}

bdf::types::card seelt::head = bdf::types::card("SEELT");
seelt::seelt(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seelt::card_type() const {
    return cards::types::SEELT;
}

bdf::types::card seexcld::head = bdf::types::card("SEEXCLD");
seexcld::seexcld(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seexcld::card_type() const {
    return cards::types::SEEXCLD;
}

bdf::types::card selabel::head = bdf::types::card("SELABEL");
selabel::selabel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types selabel::card_type() const {
    return cards::types::SELABEL;
}

bdf::types::card seloc::head = bdf::types::card("SELOC");
seloc::seloc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seloc::card_type() const {
    return cards::types::SELOC;
}

bdf::types::card sempln::head = bdf::types::card("SEMPLN");
sempln::sempln(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sempln::card_type() const {
    return cards::types::SEMPLN;
}

bdf::types::card senqset::head = bdf::types::card("SENQSET");
senqset::senqset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types senqset::card_type() const {
    return cards::types::SENQSET;
}

bdf::types::card seqgp::head = bdf::types::card("SEQGP");
seqgp::seqgp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seqgp::card_type() const {
    return cards::types::SEQGP;
}

bdf::types::card seqrout::head = bdf::types::card("SEQROUT");
seqrout::seqrout(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seqrout::card_type() const {
    return cards::types::SEQROUT;
}

bdf::types::card seqsep::head = bdf::types::card("SEQSEP");
seqsep::seqsep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seqsep::card_type() const {
    return cards::types::SEQSEP;
}

bdf::types::card seqset::head = bdf::types::card("SEQSET");
seqset::seqset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seqset::card_type() const {
    return cards::types::SEQSET;
}

bdf::types::card seqset1::head = bdf::types::card("SEQSET1");
seqset1::seqset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seqset1::card_type() const {
    return cards::types::SEQSET1;
}

bdf::types::card seset::head = bdf::types::card("SESET");
seset::seset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seset::card_type() const {
    return cards::types::SESET;
}

bdf::types::card sesup::head = bdf::types::card("SESUP");
sesup::sesup(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sesup::card_type() const {
    return cards::types::SESUP;
}

bdf::types::card set1::head = bdf::types::card("SET1");
set1::set1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types set1::card_type() const {
    return cards::types::SET1;
}

bdf::types::card set2::head = bdf::types::card("SET2");
set2::set2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types set2::card_type() const {
    return cards::types::SET2;
}

bdf::types::card set3::head = bdf::types::card("SET3");
set3::set3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types set3::card_type() const {
    return cards::types::SET3;
}

bdf::types::card set4::head = bdf::types::card("SET4");
set4::set4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types set4::card_type() const {
    return cards::types::SET4;
}

bdf::types::card setree::head = bdf::types::card("SETREE");
setree::setree(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types setree::card_type() const {
    return cards::types::SETREE;
}

bdf::types::card seuset::head = bdf::types::card("SEUSET");
seuset::seuset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seuset::card_type() const {
    return cards::types::SEUSET;
}

bdf::types::card seuset1::head = bdf::types::card("SEUSET1");
seuset1::seuset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types seuset1::card_type() const {
    return cards::types::SEUSET1;
}

bdf::types::card shrel::head = bdf::types::card("SHREL");
shrel::shrel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types shrel::card_type() const {
    return cards::types::SHREL;
}

bdf::types::card shrpol::head = bdf::types::card("SHRPOL");
shrpol::shrpol(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types shrpol::card_type() const {
    return cards::types::SHRPOL;
}

bdf::types::card shruds::head = bdf::types::card("SHRUDS");
shruds::shruds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types shruds::card_type() const {
    return cards::types::SHRUDS;
}

bdf::types::card slbdy::head = bdf::types::card("SLBDY");
slbdy::slbdy(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types slbdy::card_type() const {
    return cards::types::SLBDY;
}

bdf::types::card sload::head = bdf::types::card("SLOAD");
sload::sload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sload::card_type() const {
    return cards::types::SLOAD;
}

bdf::types::card sloadn1::head = bdf::types::card("SLOADN1");
sloadn1::sloadn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sloadn1::card_type() const {
    return cards::types::SLOADN1;
}

bdf::types::card snorm::head = bdf::types::card("SNORM");
snorm::snorm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types snorm::card_type() const {
    return cards::types::SNORM;
}

bdf::types::card sol2sph::head = bdf::types::card("SOL2SPH");
sol2sph::sol2sph(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sol2sph::card_type() const {
    return cards::types::SOL2SPH;
}

bdf::types::card spblnd1::head = bdf::types::card("SPBLND1");
spblnd1::spblnd1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spblnd1::card_type() const {
    return cards::types::SPBLND1;
}

bdf::types::card spblnd2::head = bdf::types::card("SPBLND2");
spblnd2::spblnd2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spblnd2::card_type() const {
    return cards::types::SPBLND2;
}

bdf::types::card spc::head = bdf::types::card("SPC");
spc::spc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spc::card_type() const {
    return cards::types::SPC;
}

bdf::types::card spc1::head = bdf::types::card("SPC1");
spc1::spc1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spc1::card_type() const {
    return cards::types::SPC1;
}

bdf::types::card spcadd::head = bdf::types::card("SPCADD");
spcadd::spcadd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcadd::card_type() const {
    return cards::types::SPCADD;
}

bdf::types::card spcax::head = bdf::types::card("SPCAX");
spcax::spcax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcax::card_type() const {
    return cards::types::SPCAX;
}

bdf::types::card spcd::head = bdf::types::card("SPCD");
spcd::spcd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcd::card_type() const {
    return cards::types::SPCD;
}

bdf::types::card spcd2::head = bdf::types::card("SPCD2");
spcd2::spcd2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcd2::card_type() const {
    return cards::types::SPCD2;
}

bdf::types::card spcnr::head = bdf::types::card("SPCNR");
spcnr::spcnr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcnr::card_type() const {
    return cards::types::SPCNR;
}

bdf::types::card spcoff::head = bdf::types::card("SPCOFF");
spcoff::spcoff(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcoff::card_type() const {
    return cards::types::SPCOFF;
}

bdf::types::card spcoff1::head = bdf::types::card("SPCOFF1");
spcoff1::spcoff1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcoff1::card_type() const {
    return cards::types::SPCOFF1;
}

bdf::types::card spcr::head = bdf::types::card("SPCR");
spcr::spcr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spcr::card_type() const {
    return cards::types::SPCR;
}

bdf::types::card sphdef::head = bdf::types::card("SPHDEF");
sphdef::sphdef(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sphdef::card_type() const {
    return cards::types::SPHDEF;
}

bdf::types::card sphere::head = bdf::types::card("SPHERE");
sphere::sphere(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sphere::card_type() const {
    return cards::types::SPHERE;
}

bdf::types::card sphsym::head = bdf::types::card("SPHSYM");
sphsym::sphsym(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sphsym::card_type() const {
    return cards::types::SPHSYM;
}

bdf::types::card spline6::head = bdf::types::card("SPLINE6");
spline6::spline6(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spline6::card_type() const {
    return cards::types::SPLINE6;
}

bdf::types::card spline7::head = bdf::types::card("SPLINE7");
spline7::spline7(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spline7::card_type() const {
    return cards::types::SPLINE7;
}

bdf::types::card splinex::head = bdf::types::card("SPLINEX");
splinex::splinex(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types splinex::card_type() const {
    return cards::types::SPLINEX;
}

bdf::types::card splinrb::head = bdf::types::card("SPLINRB");
splinrb::splinrb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types splinrb::card_type() const {
    return cards::types::SPLINRB;
}

bdf::types::card spoint::head = bdf::types::card("SPOINT");
spoint::spoint(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spoint::card_type() const {
    return cards::types::SPOINT;
}

bdf::types::card sprbck::head = bdf::types::card("SPRBCK");
sprbck::sprbck(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sprbck::card_type() const {
    return cards::types::SPRBCK;
}

bdf::types::card sprelax::head = bdf::types::card("SPRELAX");
sprelax::sprelax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types sprelax::card_type() const {
    return cards::types::SPRELAX;
}

bdf::types::card spwrs::head = bdf::types::card("SPWRS");
spwrs::spwrs(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types spwrs::card_type() const {
    return cards::types::SPWRS;
}

bdf::types::card stochas::head = bdf::types::card("STOCHAS");
stochas::stochas(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types stochas::card_type() const {
    return cards::types::STOCHAS;
}

bdf::types::card supax::head = bdf::types::card("SUPAX");
supax::supax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types supax::card_type() const {
    return cards::types::SUPAX;
}

bdf::types::card suport::head = bdf::types::card("SUPORT");
suport::suport(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types suport::card_type() const {
    return cards::types::SUPORT;
}

bdf::types::card suport1::head = bdf::types::card("SUPORT1");
suport1::suport1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types suport1::card_type() const {
    return cards::types::SUPORT1;
}

bdf::types::card suport6::head = bdf::types::card("SUPORT6");
suport6::suport6(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types suport6::card_type() const {
    return cards::types::SUPORT6;
}

bdf::types::card surfini::head = bdf::types::card("SURFINI");
surfini::surfini(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types surfini::card_type() const {
    return cards::types::SURFINI;
}

bdf::types::card swldprm::head = bdf::types::card("SWLDPRM");
swldprm::swldprm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types swldprm::card_type() const {
    return cards::types::SWLDPRM;
}

bdf::types::card tabd1md::head = bdf::types::card("TABD1MD");
tabd1md::tabd1md(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabd1md::card_type() const {
    return cards::types::TABD1MD;
}

bdf::types::card tabdmp1::head = bdf::types::card("TABDMP1");
tabdmp1::tabdmp1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabdmp1::card_type() const {
    return cards::types::TABDMP1;
}

bdf::types::card tabistr::head = bdf::types::card("TABISTR");
tabistr::tabistr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabistr::card_type() const {
    return cards::types::TABISTR;
}

bdf::types::card tabl3d::head = bdf::types::card("TABL3D");
tabl3d::tabl3d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabl3d::card_type() const {
    return cards::types::TABL3D;
}

bdf::types::card table3d::head = bdf::types::card("TABLE3D");
table3d::table3d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types table3d::card_type() const {
    return cards::types::TABLE3D;
}

bdf::types::card tabled1::head = bdf::types::card("TABLED1");
tabled1::tabled1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabled1::card_type() const {
    return cards::types::TABLED1;
}

bdf::types::card tabled2::head = bdf::types::card("TABLED2");
tabled2::tabled2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabled2::card_type() const {
    return cards::types::TABLED2;
}

bdf::types::card tabled3::head = bdf::types::card("TABLED3");
tabled3::tabled3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabled3::card_type() const {
    return cards::types::TABLED3;
}

bdf::types::card tabled4::head = bdf::types::card("TABLED4");
tabled4::tabled4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabled4::card_type() const {
    return cards::types::TABLED4;
}

bdf::types::card tabled5::head = bdf::types::card("TABLED5");
tabled5::tabled5(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabled5::card_type() const {
    return cards::types::TABLED5;
}

bdf::types::card tableht::head = bdf::types::card("TABLEHT");
tableht::tableht(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tableht::card_type() const {
    return cards::types::TABLEHT;
}

bdf::types::card tabledr::head = bdf::types::card("TABLEDR");
tabledr::tabledr(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabledr::card_type() const {
    return cards::types::TABLEDR;
}

bdf::types::card tableh1::head = bdf::types::card("TABLEH1");
tableh1::tableh1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tableh1::card_type() const {
    return cards::types::TABLEH1;
}

bdf::types::card tablel1::head = bdf::types::card("TABLEL1");
tablel1::tablel1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablel1::card_type() const {
    return cards::types::TABLEL1;
}

bdf::types::card tablem1::head = bdf::types::card("TABLEM1");
tablem1::tablem1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablem1::card_type() const {
    return cards::types::TABLEM1;
}

bdf::types::card tablem2::head = bdf::types::card("TABLEM2");
tablem2::tablem2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablem2::card_type() const {
    return cards::types::TABLEM2;
}

bdf::types::card tablem3::head = bdf::types::card("TABLEM3");
tablem3::tablem3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablem3::card_type() const {
    return cards::types::TABLEM3;
}

bdf::types::card tablem4::head = bdf::types::card("TABLEM4");
tablem4::tablem4(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablem4::card_type() const {
    return cards::types::TABLEM4;
}

bdf::types::card tables1::head = bdf::types::card("TABLES1");
tables1::tables1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tables1::card_type() const {
    return cards::types::TABLES1;
}

bdf::types::card tablest::head = bdf::types::card("TABLEST");
tablest::tablest(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablest::card_type() const {
    return cards::types::TABLEST;
}

bdf::types::card tablftg::head = bdf::types::card("TABLFTG");
tablftg::tablftg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tablftg::card_type() const {
    return cards::types::TABLFTG;
}

bdf::types::card tabrnd1::head = bdf::types::card("TABRND1");
tabrnd1::tabrnd1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabrnd1::card_type() const {
    return cards::types::TABRND1;
}

bdf::types::card tabrndg::head = bdf::types::card("TABRNDG");
tabrndg::tabrndg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabrndg::card_type() const {
    return cards::types::TABRNDG;
}

bdf::types::card tabsctl::head = bdf::types::card("TABSCTL");
tabsctl::tabsctl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tabsctl::card_type() const {
    return cards::types::TABSCTL;
}

bdf::types::card temp::head = bdf::types::card("TEMP");
temp::temp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types temp::card_type() const {
    return cards::types::TEMP;
}

bdf::types::card tempax::head = bdf::types::card("TEMPAX");
tempax::tempax(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempax::card_type() const {
    return cards::types::TEMPAX;
}

bdf::types::card tempb3::head = bdf::types::card("TEMPB3");
tempb3::tempb3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempb3::card_type() const {
    return cards::types::TEMPB3;
}

bdf::types::card tempbc::head = bdf::types::card("TEMPBC");
tempbc::tempbc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempbc::card_type() const {
    return cards::types::TEMPBC;
}

bdf::types::card tempd::head = bdf::types::card("TEMPD");
tempd::tempd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempd::card_type() const {
    return cards::types::TEMPD;
}

bdf::types::card tempf::head = bdf::types::card("TEMPF");
tempf::tempf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempf::card_type() const {
    return cards::types::TEMPF;
}

bdf::types::card tempn1::head = bdf::types::card("TEMPN1");
tempn1::tempn1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempn1::card_type() const {
    return cards::types::TEMPN1;
}

bdf::types::card tempp1::head = bdf::types::card("TEMPP1");
tempp1::tempp1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempp1::card_type() const {
    return cards::types::TEMPP1;
}

bdf::types::card tempp3::head = bdf::types::card("TEMPP3");
tempp3::tempp3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tempp3::card_type() const {
    return cards::types::TEMPP3;
}

bdf::types::card temprb::head = bdf::types::card("TEMPRB");
temprb::temprb(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types temprb::card_type() const {
    return cards::types::TEMPRB;
}

bdf::types::card termin::head = bdf::types::card("TERMIN");
termin::termin(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types termin::card_type() const {
    return cards::types::TERMIN;
}

bdf::types::card tf::head = bdf::types::card("TF");
tf::tf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tf::card_type() const {
    return cards::types::TF;
}

bdf::types::card thpad::head = bdf::types::card("THPAD");
thpad::thpad(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types thpad::card_type() const {
    return cards::types::THPAD;
}

bdf::types::card tic::head = bdf::types::card("TIC");
tic::tic(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tic::card_type() const {
    return cards::types::TIC;
}

bdf::types::card ticd::head = bdf::types::card("TICD");
ticd::ticd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ticd::card_type() const {
    return cards::types::TICD;
}

bdf::types::card ticel::head = bdf::types::card("TICEL");
ticel::ticel(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ticel::card_type() const {
    return cards::types::TICEL;
}

bdf::types::card ticeuds::head = bdf::types::card("TICEUDS");
ticeuds::ticeuds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ticeuds::card_type() const {
    return cards::types::TICEUDS;
}

bdf::types::card ticeul1::head = bdf::types::card("TICEUL1");
ticeul1::ticeul1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ticeul1::card_type() const {
    return cards::types::TICEUL1;
}

bdf::types::card ticreg::head = bdf::types::card("TICREG");
ticreg::ticreg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ticreg::card_type() const {
    return cards::types::TICREG;
}

bdf::types::card ticval::head = bdf::types::card("TICVAL");
ticval::ticval(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ticval::card_type() const {
    return cards::types::TICVAL;
}

bdf::types::card tic3::head = bdf::types::card("TIC3");
tic3::tic3(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tic3::card_type() const {
    return cards::types::TIC3;
}

bdf::types::card tim2psd::head = bdf::types::card("TIM2PSD");
tim2psd::tim2psd(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tim2psd::card_type() const {
    return cards::types::TIM2PSD;
}

bdf::types::card timnat::head = bdf::types::card("TIMNAT");
timnat::timnat(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types timnat::card_type() const {
    return cards::types::TIMNAT;
}

bdf::types::card timnvh::head = bdf::types::card("TIMNVH");
timnvh::timnvh(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types timnvh::card_type() const {
    return cards::types::TIMNVH;
}

bdf::types::card timsml::head = bdf::types::card("TIMSML");
timsml::timsml(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types timsml::card_type() const {
    return cards::types::TIMSML;
}

bdf::types::card tire1::head = bdf::types::card("TIRE1");
tire1::tire1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tire1::card_type() const {
    return cards::types::TIRE1;
}

bdf::types::card tload1::head = bdf::types::card("TLOAD1");
tload1::tload1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tload1::card_type() const {
    return cards::types::TLOAD1;
}

bdf::types::card tload2::head = bdf::types::card("TLOAD2");
tload2::tload2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tload2::card_type() const {
    return cards::types::TLOAD2;
}

bdf::types::card tmpset::head = bdf::types::card("TMPSET");
tmpset::tmpset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tmpset::card_type() const {
    return cards::types::TMPSET;
}

bdf::types::card todyna::head = bdf::types::card("TODYNA");
todyna::todyna(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types todyna::card_type() const {
    return cards::types::TODYNA;
}

bdf::types::card tomvar::head = bdf::types::card("TOMVAR");
tomvar::tomvar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tomvar::card_type() const {
    return cards::types::TOMVAR;
}

bdf::types::card topvar::head = bdf::types::card("TOPVAR");
topvar::topvar(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types topvar::card_type() const {
    return cards::types::TOPVAR;
}

bdf::types::card trim::head = bdf::types::card("TRIM");
trim::trim(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types trim::card_type() const {
    return cards::types::TRIM;
}

bdf::types::card trim2::head = bdf::types::card("TRIM2");
trim2::trim2(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types trim2::card_type() const {
    return cards::types::TRIM2;
}

bdf::types::card trmcpl::head = bdf::types::card("TRMCPL");
trmcpl::trmcpl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types trmcpl::card_type() const {
    return cards::types::TRMCPL;
}

bdf::types::card tstep::head = bdf::types::card("TSTEP");
tstep::tstep(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tstep::card_type() const {
    return cards::types::TSTEP;
}

bdf::types::card tstepnl::head = bdf::types::card("TSTEPNL");
tstepnl::tstepnl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types tstepnl::card_type() const {
    return cards::types::TSTEPNL;
}

bdf::types::card ttemp::head = bdf::types::card("TTEMP");
ttemp::ttemp(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ttemp::card_type() const {
    return cards::types::TTEMP;
}

bdf::types::card udname::head = bdf::types::card("UDNAME");
udname::udname(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types udname::card_type() const {
    return cards::types::UDNAME;
}

bdf::types::card udsesv::head = bdf::types::card("UDSESV");
udsesv::udsesv(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types udsesv::card_type() const {
    return cards::types::UDSESV;
}

bdf::types::card unbalnc::head = bdf::types::card("UNBALNC");
unbalnc::unbalnc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types unbalnc::card_type() const {
    return cards::types::UNBALNC;
}

bdf::types::card unglue::head = bdf::types::card("UNGLUE");
unglue::unglue(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types unglue::card_type() const {
    return cards::types::UNGLUE;
}

bdf::types::card uset::head = bdf::types::card("USET");
uset::uset(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types uset::card_type() const {
    return cards::types::USET;
}

bdf::types::card uset1::head = bdf::types::card("USET1");
uset1::uset1(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types uset1::card_type() const {
    return cards::types::USET1;
}

bdf::types::card usrsub6::head = bdf::types::card("USRSUB6");
usrsub6::usrsub6(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types usrsub6::card_type() const {
    return cards::types::USRSUB6;
}

bdf::types::card uxvec::head = bdf::types::card("UXVEC");
uxvec::uxvec(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types uxvec::card_type() const {
    return cards::types::UXVEC;
}

bdf::types::card vcct::head = bdf::types::card("VCCT");
vcct::vcct(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types vcct::card_type() const {
    return cards::types::VCCT;
}

bdf::types::card view::head = bdf::types::card("VIEW");
view::view(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types view::card_type() const {
    return cards::types::VIEW;
}

bdf::types::card view3d::head = bdf::types::card("VIEW3D");
view3d::view3d(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types view3d::card_type() const {
    return cards::types::VIEW3D;
}

bdf::types::card viewex::head = bdf::types::card("VIEWEX");
viewex::viewex(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types viewex::card_type() const {
    return cards::types::VIEWEX;
}

bdf::types::card wall::head = bdf::types::card("WALL");
wall::wall(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wall::card_type() const {
    return cards::types::WALL;
}

bdf::types::card wallgeo::head = bdf::types::card("WALLGEO");
wallgeo::wallgeo(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wallgeo::card_type() const {
    return cards::types::WALLGEO;
}

bdf::types::card wear::head = bdf::types::card("WEAR");
wear::wear(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wear::card_type() const {
    return cards::types::WEAR;
}

bdf::types::card wetelme::head = bdf::types::card("WETELME");
wetelme::wetelme(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wetelme::card_type() const {
    return cards::types::WETELME;
}

bdf::types::card wetelmg::head = bdf::types::card("WETELMG");
wetelmg::wetelmg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wetelmg::card_type() const {
    return cards::types::WETELMG;
}

bdf::types::card wetload::head = bdf::types::card("WETLOAD");
wetload::wetload(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wetload::card_type() const {
    return cards::types::WETLOAD;
}

bdf::types::card wetsurf::head = bdf::types::card("WETSURF");
wetsurf::wetsurf(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types wetsurf::card_type() const {
    return cards::types::WETSURF;
}

bdf::types::card yldhy::head = bdf::types::card("YLDHY");
yldhy::yldhy(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldhy::card_type() const {
    return cards::types::YLDHY;
}

bdf::types::card yldjc::head = bdf::types::card("YLDJC");
yldjc::yldjc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldjc::card_type() const {
    return cards::types::YLDJC;
}

bdf::types::card yldmc::head = bdf::types::card("YLDMC");
yldmc::yldmc(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldmc::card_type() const {
    return cards::types::YLDMC;
}

bdf::types::card yldmss::head = bdf::types::card("YLDMSS");
yldmss::yldmss(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldmss::card_type() const {
    return cards::types::YLDMSS;
}

bdf::types::card yldpol::head = bdf::types::card("YLDPOL");
yldpol::yldpol(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldpol::card_type() const {
    return cards::types::YLDPOL;
}

bdf::types::card yldrpl::head = bdf::types::card("YLDRPL");
yldrpl::yldrpl(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldrpl::card_type() const {
    return cards::types::YLDRPL;
}

bdf::types::card yldsg::head = bdf::types::card("YLDSG");
yldsg::yldsg(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldsg::card_type() const {
    return cards::types::YLDSG;
}

bdf::types::card yldtm::head = bdf::types::card("YLDTM");
yldtm::yldtm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldtm::card_type() const {
    return cards::types::YLDTM;
}

bdf::types::card ylduds::head = bdf::types::card("YLDUDS");
ylduds::ylduds(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types ylduds::card_type() const {
    return cards::types::YLDUDS;
}

bdf::types::card yldvm::head = bdf::types::card("YLDVM");
yldvm::yldvm(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldvm::card_type() const {
    return cards::types::YLDVM;
}

bdf::types::card yldza::head = bdf::types::card("YLDZA");
yldza::yldza(const list<std::string> &inp) : cards::__base::__dummy(inp) {}
cards::types yldza::card_type() const {
    return cards::types::YLDZA;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//       ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
