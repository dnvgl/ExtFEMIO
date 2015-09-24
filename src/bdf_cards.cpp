// Copyright © 2015 by DNV GL SE

// Purpose: Base definition for Nastran BDF cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "stdafx.h"

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
using namespace bdf::cards;

namespace {
  const char initVals[3] = { '+', '*', ',' };
}

card::card(const deque<std::string> &inp) {}

const set<char> card::free_form_cont(initVals, initVals + 3);

deque<std::string> card::card_split(deque<std::string> const &inp) {
  deque<std::string> res;
  std::string head;

  bool first = true;

  for (auto pos=inp.begin(); pos<inp.end(); ++pos) {
    head = string::string(pos->substr(0, 8)).trim();
    // Free Field Format
    if (head.find(',') != std::string::npos) {
      if (first) {
        res.push_back(bdf::string::string(head.substr(0, head.find(','))).trim("*"));
      }
      auto tmp(string::string(*pos).trim(" \t\n"));
      tmp = tmp.substr(tmp.find(',')+1);

      auto tail(tmp.substr(tmp.rfind(',')+1));

      while (tail.length() == 0 || free_form_cont.find(tail.at(0)) != free_form_cont.end()) {
        if (tail.length() != 0)
          tmp = tmp.substr(0, tmp.rfind(',')+1);
        ++pos;
        tmp.append(string::string(pos->substr(pos->find(',')+1)).trim(" \t\n"));
        tail = tmp.substr(tmp.rfind(',')+1);
      }
      while (tmp.find(',') != std::string::npos) {
        res.push_back(string::string(tmp.substr(0, tmp.find(','))).trim(" \n\t"));
        tmp = tmp.substr(tmp.find(',')+1);
      }
      res.push_back(tmp);
      first = false;
    // Long Field Format
    } else {
      if (first) {
        res.push_back(bdf::string::string(head).trim("\t\n*"));
      }
      if (head.length() > 0 && head.back() == '*') {
        std::string tmp(pos->substr(8));
        tmp.resize(64, ' ');
        tmp += string::string((++pos)->substr(8)).trim("\t\n");
        tmp.resize(128, ' ');
        for (int i=0; i<8; ++i) {
          res.push_back(string::string(tmp.substr(i*16, 16)).trim(" \t\n"));
        }
      // Short Field Format
      } else {
        auto tmp(*pos);
        tmp.resize(80, ' ');
        tmp = tmp.substr(8);
        for (int i=0; i<8; ++i) {
          res.push_back(string::string(tmp.substr(i*8, 8)).trim(" \t\n"));
        }
      }
      first = false;
    }
  }
  return res;
}

std::unique_ptr<bdf::cards::card> bdf::cards::dispatch(const deque<std::string> &inp) {
  std::string key(inp[0]);

  if (key == "GRID")
      return std::make_unique<bdf::cards::grid>(inp);
  else if (key == "CTRIA3")
      return std::make_unique<bdf::cards::ctria3>(inp);
  else if (key == "CQUAD4")
      return std::make_unique<bdf::cards::cquad4>(inp);
  else if (key == "CBEAM")
      return std::make_unique<bdf::cards::cbeam>(inp);
  else if (key == "CBAR")
    return std::make_unique<bdf::cards::cbar>(inp);
  else if (key == "CROD")
    return std::make_unique<bdf::cards::crod>(inp);
  else if (key == "PSHELL")
    return std::make_unique<bdf::cards::pshell>(inp);
  else if (key == "PBEAM")
    return std::make_unique<bdf::cards::pbeam>(inp);
  else if (key == "PBEAML")
    return std::make_unique<bdf::cards::pbeaml>(inp);
  else if (key == "PBAR")
    return std::make_unique<bdf::cards::pbar>(inp);
  else if (key == "PBARL")
    return std::make_unique<bdf::cards::pbarl>(inp);
  else if (key == "PROD")
    return std::make_unique<bdf::cards::prod>(inp);
  else if (key == "MAT1")
    return std::make_unique<bdf::cards::mat1>(inp);
  else if (key == "ENDDATA")
    return std::make_unique<bdf::cards::enddata>(inp);
  else
    return std::make_unique<bdf::cards::unknown>(inp);
  return nullptr;
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
