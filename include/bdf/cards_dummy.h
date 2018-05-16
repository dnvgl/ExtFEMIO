/**
  \file
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2018 by DNV GL SE
  \brief Dummy classes for cards not implemented.

  Detailed description
*/

/* ID: $Id$
 */

#pragma once

#ifndef _BDF_CARDS_DUMMY_H_
#define _BDF_CARDS_DUMMY_H_

#include <memory>

#if !defined(_BDF_CARDS_H_)
#error include "bdf/cards.h" instead
#endif

namespace dnvgl {
    namespace extfem {
        namespace bdf {
            namespace cards {
                namespace __base {
                    class __dummy : public card {
                    public:
                        __dummy(const std::list<std::string> &);
                        card const
                        &operator()(std::list<std::string> const &) override;
                        void read(std::list<std::string> const &) override;
                    protected:
                        void collect_outdata(
                            std::list<std::unique_ptr<format_entry> >&)
                            const override;
                        void check_data() override;
                    };
                    class __element_dummy : public element {
                    public:
                        __element_dummy(const std::list<std::string> &);
                        card const
                        &operator()(std::list<std::string> const &) override;
                        void read(std::list<std::string> const &) override;
                    protected:
                        void collect_outdata(std::list<std::unique_ptr<format_entry> >&)
                            const override;
                        void check_data() override;
                    };
                }
                class caabsf : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caabsf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caero1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caero1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caero2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caero2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caero3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caero3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caero4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caero4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caero5 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caero5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caxif2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caxif2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caxif3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caxif3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caxif4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    caxif4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbend : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cbend(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbush1d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cbush1d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbutt : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cbutt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cconeax : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cconeax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ccrsfil : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ccrsfil(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp1d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp1d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp2d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdamp5 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdamp5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum5 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum6 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum7 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum7(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum8 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum8(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdum9 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cdum9(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class celas1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    celas1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class celas1d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    celas1d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class celas2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    celas2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class celas2d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    celas2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class celas3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    celas3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class celas4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    celas4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cfillet : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cfillet(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cfluid2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cfluid2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cfluid3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cfluid3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cfluid4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cfluid4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cgap : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cgap(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class chacab : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    chacab(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class chacbr : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    chacbr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class chbdye : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    chbdye(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class chbdyg : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    chbdyg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class chbdyp : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    chbdyp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class chexa : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    chexa(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cmass1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cmass1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cmass3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cmass3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class combwld : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    combwld(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class conm2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    conm2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class conrod : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    conrod(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cpenta : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cpenta(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cquad8 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cquad8(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cquad : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cquad(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cquadr : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cquadr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cquadx : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cquadx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class crac2d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    crac2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class crac3d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    crac3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cshear : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cshear(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cslot3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cslot3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cslot4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cslot4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cspot : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cspot(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctetra : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ctetra(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctria6 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ctria6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctriar : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ctriar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctriax6 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ctriax6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctriax : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ctriax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctube : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    ctube(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cvisc : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    cvisc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class genel : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    genel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmintc : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    gmintc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmints : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    gmints(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class plotel : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    plotel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbar1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbar1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbar : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbe1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbe2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe2d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbe2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbe3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe3d : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rbe3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rjoint : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rjoint(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rrod : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rrod(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rspline : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rspline(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rsscon : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rsscon(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rtrplt1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rtrplt1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rtrplt : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    rtrplt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline1 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    spline1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline2 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    spline2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline3 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    spline3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline4 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    spline4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline5 : public __base::__element_dummy {
                    bdf::types::card static head;
                public:
                    spline5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class _delete : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    _delete(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class abinfl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    abinfl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class acc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    acc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class accel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    accel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class accel1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    accel1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class accmetr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    accmetr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class accsspt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    accsspt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class acload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    acload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class acmodl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    acmodl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class acpemcp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    acpemcp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class acsrce : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    acsrce(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class activat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    activat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class actrim : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    actrim(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class adapt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    adapt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class adumi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    adumi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aecomp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aecomp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aecompl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aecompl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aedw : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aedw(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aefact : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aefact(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aeforce : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aeforce(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aegrid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aegrid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aelink : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aelink(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aelist : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aelist(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aelistc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aelistc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aeparm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aeparm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aepress : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aepress(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aequad4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aequad4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aero : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aero(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aeros : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aeros(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aescale : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aescale(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aestat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aestat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aesurf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aesurf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aesurfs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aesurfs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aetria3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aetria3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class airbag : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    airbag(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aliasm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aliasm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class aset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    aset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class axic : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    axic(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class axif : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    axif(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class axslot : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    axslot(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class baror : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    baror(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class barrier : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    barrier(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcbdprp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcbdprp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcbmrad : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcbmrad(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcbody : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcbody(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcbody1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcbody1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcbox : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcbox(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcbzier : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcbzier(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcgm700 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcgm700(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcgrid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcgrid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bchange : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bchange(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcmatl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcmatl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcmove : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcmove(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcnurb2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcnurb2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcnurbs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcnurbs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bconect : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bconect(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bconp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bconp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bconprg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bconprg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bconprp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bconprp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bconuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bconuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcpara : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcpara(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcpatch : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcpatch(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcpflg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcpflg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcprop : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcprop(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcprop1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcprop1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcrigid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcrigid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcrgsrf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcrgsrf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcscap : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcscap(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bcseg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bcseg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bctable : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bctable(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bctabl1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bctabl1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bctrim : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bctrim(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bdylist : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bdylist(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bdyforc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bdyforc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bdyor : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bdyor(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bdyrelx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bdyrelx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class beadvar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    beadvar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class beamor : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    beamor(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bfrlc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bfrlc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bias : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bias(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bjoin : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bjoin(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bldout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bldout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class blseg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    blseg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bndfix : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bndfix(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bndfix1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bndfix1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bndfree : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bndfree(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bndfre1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bndfre1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bndgrid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bndgrid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bolt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bolt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class boutput : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    boutput(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class brksql : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    brksql(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bsqueal : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bsqueal(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bsurf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bsurf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class bwidth : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    bwidth(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cacinf3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cacinf3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cacinf4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cacinf4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class campbll : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    campbll(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class caxisym : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    caxisym(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbarao : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cbarao(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbeam3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cbeam3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbelt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cbelt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cbush2d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cbush2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cdumi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cdumi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cfast : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cfast(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cfluidi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cfluidi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cifhex : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cifhex(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cifpent : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cifpent(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cifqdx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cifqdx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cifquad : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cifquad(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cintc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cintc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cmarkb2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cmarkb2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cmarkn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cmarkn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cmrebai : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cmrebai(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cmrebar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cmrebar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cntruds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cntruds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cohesiv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cohesiv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class conctl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    conctl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class conspot : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    conspot(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class contrlt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    contrlt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class conv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    conv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class conv3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    conv3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class convm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    convm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord1c : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord1c(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord1r : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord1r(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord1rx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord1rx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord1s : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord1s(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord2c : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord2c(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord2r : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord2r(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord2rx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord2rx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord2s : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord2s(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord3g : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord3g(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord3r : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord3r(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cord3rx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cord3rx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class couopt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    couopt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class coup1fl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    coup1fl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class coupint : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    coupint(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class couple : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    couple(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class creep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    creep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class crossec : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    crossec(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cseam : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cseam(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csph : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csph(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cspr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cspr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csschd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csschd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csshl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csshl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csshlh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csshlh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csshlm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csshlm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csshlp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csshlp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csuper : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csuper(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class csupext : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    csupext(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ctquad : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ctquad(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cttria : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cttria(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cweld : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cweld(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cyax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cyax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cyjoin : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cyjoin(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cylindr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cylindr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cysup : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cysup(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class cysym : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    cysym(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class d2r0000 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    d2r0000(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class d2rauto : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    d2rauto(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class d2riner : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    d2riner(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dampgbl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dampgbl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class damping : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    damping(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dampmas : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dampmas(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dampstf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dampstf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class darea : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    darea(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dbexsss : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dbexsss(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dbreg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dbreg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dconadd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dconadd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dconstr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dconstr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ddval : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ddval(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class deactel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    deactel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class deform : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    deform(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class defuset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    defuset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class delay : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    delay(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class deqatn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    deqatn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class desvar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    desvar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class detsph : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    detsph(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class diverg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    diverg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dlink : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dlink(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmiax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmiax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmig : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmig(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmigout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmigout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmigrot : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmigrot(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmij : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmij(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmiji : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmiji(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dmik : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dmik(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class doptprm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    doptprm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dphase : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dphase(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dresp1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dresp1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dresp2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dresp2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dresp3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dresp3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dscreen : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dscreen(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dtable : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dtable(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dtable2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dtable2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dti : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dti(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvbshap : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvbshap(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvcrel1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvcrel1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvcrel2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvcrel2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvgrid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvgrid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvlrel1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvlrel1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvmrel1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvmrel1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvmrel2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvmrel2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvprel1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvprel1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvprel2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvprel2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvshap : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvshap(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dvpsurf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dvpsurf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dychang : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dychang(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dydelem : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dydelem(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dyfsisw : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dyfsisw(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dyparam : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dyparam(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dyrigsw : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dyrigsw(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dytermt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dytermt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class dytimhs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    dytimhs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class echooff : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    echooff(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class echoon : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    echoon(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eigb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eigb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eigc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eigc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eigp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eigp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eigr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eigr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eigrl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eigrl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class elemuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    elemuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class elist : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    elist(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class enddyna : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    enddyna(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class entuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    entuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosgam : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosgam(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosgrun : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosgrun(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosig : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosig(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosjwl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosjwl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosmg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosmg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosmg2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosmg2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eospol : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eospol(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eostab : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eostab(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eostabc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eostabc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eostait : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eostait(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eosuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eosuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class epoint : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    epoint(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class erppnl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    erppnl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eulfor : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eulfor(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eulfor1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eulfor1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class eulfreg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    eulfreg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class explsv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    explsv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class extrn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    extrn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class failjc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    failjc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class failmps : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    failmps(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class failuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    failuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fbadlay : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fbadlay(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fbaload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fbaload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fbaphas : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fbaphas(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fbodyld : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fbodyld(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fbodysb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fbodysb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class feedge : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    feedge(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class feface : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    feface(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ffcontr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ffcontr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flfact : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flfact(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flow : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flow(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flowdef : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flowdef(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flowsph : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flowsph(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flowt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flowt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flowuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flowuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flsym : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flsym(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class flutter : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    flutter(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class force1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    force1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class force2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    force2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class forceax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    forceax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freept : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freept(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freq : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freq(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freq1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freq1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freq2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freq2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freq3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freq3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freq4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freq4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class freq5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    freq5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfcomp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfcomp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfconn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfconn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfflex : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfflex(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfrels : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfrels(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfspc1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfspc1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfxit : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfxit(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class frfxit1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    frfxit1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fsictrl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fsictrl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class fslist : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    fslist(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ftgdef : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ftgdef(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ftgevnt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ftgevnt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ftgload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ftgload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ftgparm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ftgparm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ftgseq : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ftgseq(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gbag : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gbag(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gbagcou : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gbagcou(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class genuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    genuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmbc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmbc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmbndc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmbndc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmbnds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmbnds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmconv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmconv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmcord : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmcord(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmcurv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmcurv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmnurb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmnurb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmqvol : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmqvol(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmspc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmspc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gmsurf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gmsurf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class grdset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    grdset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gria : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gria(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class grida : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    grida(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gridb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gridb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gridf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gridf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class grids : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    grids(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class gust : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    gust(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class hadacri : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    hadacri(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class hadaptl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    hadaptl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class heatlos : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    heatlos(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class hgsuppr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    hgsuppr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class htrconv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    htrconv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class htrrad : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    htrrad(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class hybdamp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    hybdamp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class hydstat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    hydstat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class include : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    include(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class inflcg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    inflcg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class inflfrc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    inflfrc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class inflgas : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    inflgas(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class inflhb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    inflhb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class infltnk : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    infltnk(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class infltr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    infltr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class initgas : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    initgas(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ipstrain : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ipstrain(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ipstrn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ipstrn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istress : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istress(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrnsh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrnsh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrnso : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrnso(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrnts : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrnts(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrsbe : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrsbe(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrssh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrssh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrsso : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrsso(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrsss : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrsss(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class istrsts : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    istrsts(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class iter : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    iter(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class leakage : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    leakage(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadclid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadclid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadcnam : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadcnam(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadcsub : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadcsub(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadcyh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadcyh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadcyn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadcyn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadcyt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadcyt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadof : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadof(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class loadt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    loadt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class lorenzi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    lorenzi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class lseq : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    lseq(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class macreep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    macreep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class marcin : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    marcin(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class marcout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    marcout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class marprn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    marprn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mat3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mat3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mat4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mat4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mat5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mat5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mat8 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mat8(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mat9 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mat9(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mat10 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mat10(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd001 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd001(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd2an : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd2an(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd2or : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd2or(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd003 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd003(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd004 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd004(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd005 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd005(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd006 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd006(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd007 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd007(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd009 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd009(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd010 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd010(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd012 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd012(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd013 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd013(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd014 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd014(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd015 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd015(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd016 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd016(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd018 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd018(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd019 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd019(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd020 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd020(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd20m : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd20m(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd021 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd021(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd022 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd022(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd024 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd024(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd025 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd025(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd026 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd026(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd027 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd027(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd028 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd028(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd029 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd029(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd030 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd030(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd031 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd031(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd032 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd032(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd034 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd034(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd036 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd036(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd037 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd037(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd038 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd038(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd039 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd039(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd040 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd040(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd053 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd053(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd054 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd054(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd057 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd057(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd058 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd058(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd059 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd059(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd062 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd062(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd063 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd063(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd064 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd064(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd065 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd065(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd066 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd066(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd067 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd067(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd068 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd068(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd069 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd069(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd070 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd070(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd071 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd071(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd072 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd072(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd72r : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd72r(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd073 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd073(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd074 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd074(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd076 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd076(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd077 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd077(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd77h : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd77h(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd77o : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd77o(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd078 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd078(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd080 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd080(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd081 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd081(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd083 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd083(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd084 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd084(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd087 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd087(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd089 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd089(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd091 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd091(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd092 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd092(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd093 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd093(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd094 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd094(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd095 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd095(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd096 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd096(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd097 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd097(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd098 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd098(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd099 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd099(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd100 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd100(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd106 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd106(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd107 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd107(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd110 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd110(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd111 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd111(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd112 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd112(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd114 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd114(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd115 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd115(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd116 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd116(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd119 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd119(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd120 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd120(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd12j : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd12j(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd12r : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd12r(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd121 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd121(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd123 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd123(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd124 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd124(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd126 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd126(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd127 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd127(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd128 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd128(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd129 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd129(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd130 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd130(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd143 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd143(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd145 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd145(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd147 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd147(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd155 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd155(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd156 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd156(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd158 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd158(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd159 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd159(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd163 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd163(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd164 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd164(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd170 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd170(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd173 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd173(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd176 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd176(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd181 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd181(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd184 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd184(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd185 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd185(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd186 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd186(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd188 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd188(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd190 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd190(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd193 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd193(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd196 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd196(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd224 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd224(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd266 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd266(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matd272 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matd272(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdb01 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdb01(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdero : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdero(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdeul : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdeul(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdigi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdigi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdmg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdmg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds01 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds01(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds02 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds02(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds03 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds03(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds04 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds04(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds05 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds05(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds06 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds06(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds07 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds07(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds08 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds08(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds13 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds13(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds14 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds14(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matds15 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matds15(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdt01 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdt01(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdt02 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdt02(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdt03 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdt03(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdt04 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdt04(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdt05 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdt05(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdt06 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdt06(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdsw1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdsw1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdsw2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdsw2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdsw3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdsw3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdsw4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdsw4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matdsw5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matdsw5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matf1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matf1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matftg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matftg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mathe : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mathe(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mathed : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mathed(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mathp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mathp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matnle : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matnle(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matort : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matort(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matpe1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matpe1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matrig : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matrig(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mats1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mats1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mats3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mats3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mats8 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mats8(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matsma : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matsma(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matsort : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matsort(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt8 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt8(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matt9 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matt9(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mattep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mattep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mattf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mattf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mattg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mattg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matthe : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matthe(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mattort : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mattort(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mattusr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mattusr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mattve : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mattve(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matusr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matusr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matve : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matve(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class matvp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    matvp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mauxcmd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mauxcmd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mbolt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mbolt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mboltus : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mboltus(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mchstat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mchstat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mcohe : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mcohe(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mdelam : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mdelam(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mdlprm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mdlprm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mdmiaux : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mdmiaux(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mdmiout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mdmiout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mesh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mesh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mesuper : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mesuper(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class metadata : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    metadata(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mfluid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mfluid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mgrspr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mgrspr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class minstat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    minstat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class misland : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    misland(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mixture : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mixture(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mkaero1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mkaero1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mkaero2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mkaero2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mlayout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mlayout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mnf600 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mnf600(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class modtrak : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    modtrak(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class momax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    momax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class moment1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    moment1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class moment2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    moment2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class moncarl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    moncarl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class moncncm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    moncncm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mondsp1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mondsp1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mongrp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mongrp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class monpnt1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    monpnt1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class monpnt2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    monpnt2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class monpnt3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    monpnt3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class monsum : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    monsum(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class monsum1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    monsum1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class monsumt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    monsumt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpcadd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpcadd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpcax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpcax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpcd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpcd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpcreep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpcreep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpcy : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpcy(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mpheat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mpheat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mprocs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mprocs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mrevers : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mrevers(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mrsscon : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mrsscon(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mstack : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mstack(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mt16sel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mt16sel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mt16spl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mt16spl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mtabrv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mtabrv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mtcreep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mtcreep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class mtherm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    mtherm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nladapt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nladapt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlauto : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlauto(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlcysym : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlcysym(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nldamp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nldamp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlfreq : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlfreq(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlfreq1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlfreq1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlharm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlharm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlheatc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlheatc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlmopts : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlmopts(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nloutud : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nloutud(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlparm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlparm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlpci : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlpci(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlrgap : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlrgap(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlrsfd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlrsfd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlstep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlstep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nlstrat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nlstrat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nolin1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nolin1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nolin2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nolin2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nolin3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nolin3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nolin4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nolin4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nsm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nsm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nsm1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nsm1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nsmadd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nsmadd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nsml : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nsml(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nsml1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nsml1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class nthick : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    nthick(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class omit : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    omit(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class omit1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    omit1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class omitax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    omitax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class output : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    output(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class outrcv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    outrcv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paabsf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paabsf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pacabs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pacabs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pacbar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pacbar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pacinf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pacinf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paero1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paero1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paero2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paero2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paero3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paero3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paero4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paero4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paero5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paero5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class panel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    panel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paramarc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paramarc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paxisym : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paxisym(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class paxsymh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    paxsymh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbarn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbarn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbcomp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbcomp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbdiscr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbdiscr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbeam3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbeam3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbeam71 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbeam71(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbeamd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbeamd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbeltd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbeltd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbemn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbemn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbend : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbend(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbmarb6 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbmarb6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbmnum6 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbmnum6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbmsect : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbmsect(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbrsect : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbrsect(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbspot : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbspot(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbush1d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbush1d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbush2d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbush2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pbusht : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pbusht(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pcohe : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pcohe(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pcomp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pcomp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pcompa : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pcompa(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pcompf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pcompf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pcompg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pcompg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pcompls : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pcompls(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pconeax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pconeax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pconv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pconv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pconvm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pconvm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pconv1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pconv1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pdamp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pdamp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pdamp5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pdamp5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pdampt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pdampt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pdumi : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pdumi(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pelas : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pelas(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pelas1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pelas1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pelast : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pelast(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class permeab : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    permeab(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class permgbg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    permgbg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class peuler : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    peuler(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class peuler1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    peuler1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pfast : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pfast(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pftg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pftg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pgap : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pgap(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class phbdy : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    phbdy(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pintc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pintc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pints : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pints(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class plblast : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    plblast(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class plcomp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    plcomp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pload1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pload1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pload2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pload2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pload4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pload4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ploadb3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ploadb3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ploadx1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ploadx1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class plplane : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    plplane(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class plsolid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    plsolid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pmarker : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pmarker(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pmass : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pmass(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pminc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pminc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pmrebai : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pmrebai(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pmrebar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pmrebar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class point : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    point(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pointax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pointax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class porfcpl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    porfcpl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class porfgbg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    porfgbg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class porflow : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    porflow(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class porflwt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    porflwt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class porhole : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    porhole(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class porhyds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    porhyds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class poruds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    poruds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class prac2d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    prac2d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class prac3d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    prac3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class presax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    presax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class prespt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    prespt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class prestrs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    prestrs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class primx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    primx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class prjcon : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    prjcon(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class prodn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    prodn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pseam : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pseam(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pshear : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pshear(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pshearn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pshearn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pshell1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pshell1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pshelld : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pshelld(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pshln1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pshln1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pshln2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pshln2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class psldn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    psldn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class psolid : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    psolid(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class psolidd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    psolidd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class psph : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    psph(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class psprmat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    psprmat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class psshl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    psshl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ptshell : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ptshell(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ptube : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ptube(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pval : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pval(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pvisc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pvisc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class pweld : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    pweld(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qbdy1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qbdy1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qbdy2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qbdy2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qbdy3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qbdy3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qbdy4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qbdy4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qhbdy : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qhbdy(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qvect : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qvect(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class qvol : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    qvol(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radbc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radbc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radbc2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radbc2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radbnd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radbnd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radcav : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radcav(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radcol : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radcol(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radct : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radct(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radlst : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radlst(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radmt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radmt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radmtx : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radmtx(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class radset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    radset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class randps : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    randps(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class randt1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    randt1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbax3d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbax3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe2a : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbe2a(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe2f : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbe2f(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe2gs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbe2gs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbe3u : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbe3u(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbjoint : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbjoint(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rbjstif : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rbjstif(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rconn : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rconn(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rcparm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rcparm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rcross : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rcross(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class release : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    release(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class restart : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    restart(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rforce : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rforce(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rgyro : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rgyro(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ringax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ringax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ringfl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ringfl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rload1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rload1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rload2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rload2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rothybd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rothybd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rotor : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rotor(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rotorax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rotorax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rotorg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rotorg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rotorse : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rotorse(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rspinr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rspinr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rspint : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rspint(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rvdof : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rvdof(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class rvdof1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    rvdof1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sangle : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sangle(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sbpret : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sbpret(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sbretr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sbretr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sbsensr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sbsensr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sbslpr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sbslpr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sebndry : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sebndry(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sebset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sebset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sebset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sebset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sebulk : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sebulk(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seconct : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seconct(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class secset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    secset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class secset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    secset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sectax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sectax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sedlink : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sedlink(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sedrsp2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sedrsp2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sedrsp3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sedrsp3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seelt : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seelt(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seexcld : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seexcld(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class selabel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    selabel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seloc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seloc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sempln : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sempln(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class senqset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    senqset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seqgp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seqgp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seqrout : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seqrout(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seqsep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seqsep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seqset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seqset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seqset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seqset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sesup : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sesup(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class set1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    set1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class set2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    set2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class set3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    set3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class set4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    set4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class setree : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    setree(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seuset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seuset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class seuset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    seuset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class shrel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    shrel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class shrpol : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    shrpol(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class shruds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    shruds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class slbdy : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    slbdy(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sloadn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sloadn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class snorm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    snorm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sol2sph : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sol2sph(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spblnd1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spblnd1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spblnd2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spblnd2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spc1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spc1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcadd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcadd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcd2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcd2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcnr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcnr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcoff : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcoff(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcoff1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcoff1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spcr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spcr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sphdef : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sphdef(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sphere : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sphere(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sphsym : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sphsym(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline6 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spline6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spline7 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spline7(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class splinex : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    splinex(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class splinrb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    splinrb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spoint : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spoint(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sprbck : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sprbck(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class sprelax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    sprelax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class spwrs : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    spwrs(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class stochas : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    stochas(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class supax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    supax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class suport : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    suport(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class suport1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    suport1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class suport6 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    suport6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class surfini : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    surfini(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class swldprm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    swldprm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabd1md : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabd1md(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabdmp1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabdmp1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabistr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabistr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabl3d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabl3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class table3d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    table3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabled1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabled1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabled2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabled2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabled3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabled3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabled4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabled4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabled5 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabled5(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tableht : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tableht(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabledr : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabledr(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tableh1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tableh1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablel1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablel1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablem1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablem1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablem2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablem2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablem3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablem3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablem4 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablem4(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tables1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tables1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablest : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablest(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tablftg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tablftg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabrnd1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabrnd1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabrndg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabrndg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tabsctl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tabsctl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class temp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    temp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempax : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempax(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempb3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempb3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempbc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempbc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempn1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempn1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempp1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempp1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tempp3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tempp3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class temprb : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    temprb(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class termin : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    termin(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class thpad : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    thpad(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tic : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tic(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ticd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ticd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ticel : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ticel(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ticeuds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ticeuds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ticeul1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ticeul1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ticreg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ticreg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ticval : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ticval(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tic3 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tic3(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tim2psd : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tim2psd(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class timnat : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    timnat(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class timnvh : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    timnvh(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class timsml : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    timsml(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tire1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tire1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tload1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tload1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tload2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tload2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tmpset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tmpset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class todyna : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    todyna(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tomvar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tomvar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class topvar : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    topvar(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class trim : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    trim(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class trim2 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    trim2(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class trmcpl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    trmcpl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tstep : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tstep(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class tstepnl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    tstepnl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ttemp : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ttemp(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class udname : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    udname(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class udsesv : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    udsesv(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class unbalnc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    unbalnc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class unglue : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    unglue(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class uset : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    uset(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class uset1 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    uset1(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class usrsub6 : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    usrsub6(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class uxvec : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    uxvec(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class vcct : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    vcct(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class view : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    view(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class view3d : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    view3d(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class viewex : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    viewex(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wall : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wall(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wallgeo : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wallgeo(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wear : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wear(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wetelme : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wetelme(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wetelmg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wetelmg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wetload : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wetload(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class wetsurf : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    wetsurf(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldhy : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldhy(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldjc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldjc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldmc : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldmc(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldmss : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldmss(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldpol : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldpol(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldrpl : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldrpl(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldsg : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldsg(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldtm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldtm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class ylduds : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    ylduds(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldvm : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldvm(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
                class yldza : public __base::__dummy {
                    bdf::types::card static head;
                public:
                    yldza(const std::list<std::string> &inp);
                    cards::types card_type() const;
                };
            }
        }
    }
}

#endif // _BDF_CARDS_DUMMY_H_

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
