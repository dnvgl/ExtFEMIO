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

namespace {
  const char* const initVals[2] = { "+,", "*," };
}

const ::std::set<::std::string> _bdf_base_card::free_form_cont(initVals, initVals + 2);

vector<::std::string> _bdf_base_card::card_split(vector<::std::string> inp) {
  vector<::std::string> res;

  for (vector<::std::string>::iterator pos=inp.begin(); pos<inp.end(); ++pos) {
    ::std::string head(string::string(pos->substr(0, 8)).trim());
    // Free Field Format
    if (head.find(',') != ::std::string::npos) {
      ::std::string tmp(string::string(*pos).trim(" \t\n"));
      tmp = tmp.substr(tmp.find(',')+1);
      ::std::string rtmp(tmp.rbegin(), tmp.rend());

      while (rtmp[0] == ',' || free_form_cont.find(rtmp.substr(0, 2)) != free_form_cont.end()) {
        ++pos;
        tmp.append(string::string(pos->substr(pos->find(',')+1)).trim(" \t\n"));
        rtmp = ::std::string(tmp.rbegin(), tmp.rend());
      }
      while (tmp.find(',') != ::std::string::npos) {
        res.push_back(tmp.substr(0, tmp.find(',')));
        tmp = tmp.substr(tmp.find(',')+1);
      }
      res.push_back(tmp);
    // Long Field Format
    } else if (head.back() == '*') {
      ::std::string tmp(pos->substr(8));
      tmp.resize(64, ' ');
      ++pos;
      tmp += string::string(pos->substr(8)).trim(" \t\n");
      tmp.resize(128, ' ');
      for (int i=0; i<8; ++i) {
        res.push_back(tmp.substr(i*16, 16));
      }
    // Short Field Format
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
