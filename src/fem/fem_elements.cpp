/**
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2015 by DNV GL SE
  \brief Common definitions for FEm elements.

  Detailed description
*/

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include <memory>

#include "fem/elements.h"

using namespace ::dnvgl::extfem::fem::elements;

std::unique_ptr<__base> dispatch(const long &id) {

  switch (id) {
  case 2: return ::std::make_unique<BEPS>();
  case 3: return ::std::make_unique<CSTA>();
  case 5: return ::std::make_unique<RPBQ>();
  case 6: return ::std::make_unique<ILST>();
  case 8: return ::std::make_unique<IQQE>();
  case 9: return ::std::make_unique<LQUA>();
  case 10: return ::std::make_unique<TESS>();
  case 11: return ::std::make_unique<GMAS>();
  case 12: return ::std::make_unique<GLMA>();
  case 13: return ::std::make_unique<GLDA>();
  case 15: return ::std::make_unique<BEAS>();
  case 16: return ::std::make_unique<AXIS>();
  case 17: return ::std::make_unique<AXDA>();
  case 18: return ::std::make_unique<GSPR>();
  case 19: return ::std::make_unique<GDAM>();
  case 20: return ::std::make_unique<IHEX>();
  case 21: return ::std::make_unique<LHEX>();
  case 22: return ::std::make_unique<SECB>();
  case 23: return ::std::make_unique<BTSS>();
  case 24: return ::std::make_unique<FQUS_FFQ>();
  case 25: return ::std::make_unique<FTRS_FFTR>();
  case 26: return ::std::make_unique<SCTS>();
  case 27: return ::std::make_unique<MCTS>();
  case 28: return ::std::make_unique<SCQS>();
  case 29: return ::std::make_unique<MCQS>();
  case 30: return ::std::make_unique<IPRI>();
  case 31: return ::std::make_unique<ITET>();
  case 32: return ::std::make_unique<TPRI>();
  case 33: return ::std::make_unique<TETR>();
  case 34: return ::std::make_unique<LCTS>();
  case 35: return ::std::make_unique<LCQS>();
  case 36: return ::std::make_unique<TRS1>();
  case 37: return ::std::make_unique<TRS2>();
  case 38: return ::std::make_unique<TRS3>();
  case 40: return ::std::make_unique<GLSH>();
  case 41: return ::std::make_unique<AXCS>();
  case 42: return ::std::make_unique<AXLQ>();
  case 43: return ::std::make_unique<AXLS>();
  case 44: return ::std::make_unique<AXQQ>();
  case 45: return ::std::make_unique<PILS>();
  case 46: return ::std::make_unique<PCAB>();
  case 47: return ::std::make_unique<PSPR>();
  case 48: return ::std::make_unique<ann4>();
  case 49: return ::std::make_unique<ann2>();
  case 51: return ::std::make_unique<CTCP>();
  case 52: return ::std::make_unique<CTCL>();
  case 53: return ::std::make_unique<CTAL>();
  case 54: return ::std::make_unique<CTCC>();
  case 55: return ::std::make_unique<CTAQ>();
  case 56: return ::std::make_unique<CTLQ>();
  case 57: return ::std::make_unique<CTCQ>();
  case 58: return ::std::make_unique<CTMQ>();
  case 61: return ::std::make_unique<HCQS>();
  case 66: return ::std::make_unique<SLQS>();
  case 67: return ::std::make_unique<SLTS>();
  case 68: return ::std::make_unique<SLCB>();
  case 70: return ::std::make_unique<MATR>();
  case 100: return ::std::make_unique<GHEX100>();
  case 163: return ::std::make_unique<GHEX163>();
  default:
    return ::std::make_unique<undef>();
  };
}

long undef::undef::nnodes = -1;
long BEPS::BEPS::nnodes = 2;
long CSTA::CSTA::nnodes = 3;
long RPBQ::RPBQ::nnodes = 4;
long ILST::ILST::nnodes = 6;
long IQQE::IQQE::nnodes = 8;
long LQUA::LQUA::nnodes = 4;
long TESS::TESS::nnodes = 2;
long GMAS::GMAS::nnodes = 1;
long GLMA::GLMA::nnodes = 2;
long GLDA::GLDA::nnodes = 2;
long BEAS::BEAS::nnodes = 2;
long AXIS::AXIS::nnodes = 2;
long AXDA::AXDA::nnodes = 2;
long GSPR::GSPR::nnodes = 1;
long GDAM::GDAM::nnodes = 1;
long IHEX::IHEX::nnodes = 20;
long LHEX::LHEX::nnodes = 8;
long SECB::SECB::nnodes = 3;
long BTSS::BTSS::nnodes = 3;
long FQUS_FFQ::FQUS_FFQ::nnodes = 4;
long FTRS_FFTR::FTRS_FFTR::nnodes = 3;
long SCTS::SCTS::nnodes = 6;
long MCTS::MCTS::nnodes = 6;
long SCQS::SCQS::nnodes = 8;
long MCQS::MCQS::nnodes = 8;
long IPRI::IPRI::nnodes = 15;
long ITET::ITET::nnodes = 10;
long TPRI::TPRI::nnodes = 6;
long TETR::TETR::nnodes = 4;
long LCTS::LCTS::nnodes = 6;
long LCQS::LCQS::nnodes = 8;
long TRS1::TRS1::nnodes = 18;
long TRS2::TRS2::nnodes = 15;
long TRS3::TRS3::nnodes = 12;
long GLSH::GLSH::nnodes = 2;
long AXCS::AXCS::nnodes = 3;
long AXLQ::AXLQ::nnodes = 4;
long AXLS::AXLS::nnodes = 6;
long AXQQ::AXQQ::nnodes = 8;
long PILS::PILS::nnodes = 1;
long PCAB::PCAB::nnodes = 2;
long PSPR::PSPR::nnodes = 1;
long ann4::ann4::nnodes = 4;
long ann2::ann2::nnodes = 2;
long CTCP::CTCP::nnodes = 2;
long CTCL::CTCL::nnodes = 4;
long CTAL::CTAL::nnodes = 4;
long CTCC::CTCC::nnodes = 6;
long CTAQ::CTAQ::nnodes = 6;
long CTLQ::CTLQ::nnodes = 8;
long CTCQ::CTCQ::nnodes = 16;
long CTMQ::CTMQ::nnodes = 18;
long HCQS::HCQS::nnodes = 9;
long SLQS::SLQS::nnodes = 8;
long SLTS::SLTS::nnodes = 6;
long SLCB::SLCB::nnodes = 3;
long MATR::MATR::nnodes = 0;
long GHEX100::GHEX100::nnodes = 21;
long GHEX163::GHEX163::nnodes = 27;


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
