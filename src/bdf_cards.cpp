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
    ::std::cerr << "head: !" << head << "!\n";
    if (head.find(',') != ::std::string::npos)
      throw("Free Field Format not yet supported.\n");
    else if (head.back() == '*')
      throw("Large Field Format not yet supported.\n");
    else {

    }
  }

  res.push_back(" 1        ");
  res.push_back(" 22       ");
  res.push_back(" 111525.  ");
  res.push_back(" 18000.   ");
  res.push_back(" 21000.   ");
  res.push_back(" 11       ");
  res.push_back(" 6        ");
  res.push_back(" 2        ");
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
