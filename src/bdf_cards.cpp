// Copyright © 2015 by DNV GL SE

// Purpose: Base definition for Nastran BDF cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_cards.h"
#include "bdf_string.h"

using namespace std;
using namespace bdf;
using namespace bdf::cards;

_bdf_base_card::_bdf_base_card() {}

vector<::std::string> _bdf_base_card::card_split(vector<::std::string> inp) {
  vector<::std::string> res;

  for (vector<::std::string>::iterator pos=inp.begin(); pos<inp.end(); ++pos) {
    ::std::string head(string::string(pos->substr(0, 8)).trim());
    if (head.find(',') != ::std::string::npos) {
      ::std::string tmp(*pos);
      tmp = tmp.substr(tmp.find(','));
      throw("Free Field Format not yet supported.\n");
    } else if (head.back() == '*') {
      ::std::string tmp(pos->substr(8));
      tmp.resize(64, ' ');
      ++pos;
      tmp += pos->substr(8);
      tmp.resize(128, ' ');
      for (int i=0; i<8; ++i) {
        res.push_back(tmp.substr(i*16, 16));
      }
    } else {
      ::std::string tmp(pos->substr(8));
      tmp.resize(64, ' ');
      for (int i=0; i<8; ++i) {
        res.push_back(tmp.substr(i*8, 8));
      }
    }
  }
  return res;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 7"
// End:
