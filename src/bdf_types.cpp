// Copyright © 2015 by DNV GL SE

// Definitions for Nastran Bulk data entry types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include <sstream>
#include <limits>
#include <algorithm>
#include <string>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;


// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
string trim(const string& str,
                 const string& whitespace) {
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

bdf_type_base::bdf_type_base(string name) : name(name) {};

bdf_int::bdf_int(string name) :
  bdf_type_base(name), bounds(bdf_num_bounds<long>()) {};

bdf_int::bdf_int(string name, bdf_num_bounds<long> _bounds) :
  bdf_type_base(name), bounds(_bounds) {};

void bdf_int::operator()(string inp) {
  string sval = trim(inp);
  if (sval.find('+') != string::npos) throw "*** FOUND '+'";
  if (sval.length() == 0) {
    if (!this->bounds.has_default())
      throw "** BDF INP ERROR **: empty entry without default";
    value = this->bounds.get_default();
  } else {
    istringstream buffer(sval);
    buffer >> value;
  }
  if (!this->bounds.in_bounds(value))
    throw  "** BDF INP ERROR **: boundary condition violated";
}

// Convert string `inp` to integer.

// >>> f = Int('dummy')
// >>> assert f('123') == 123
// >>> f('123.')
// Traceback (most recent call last):
// ValueError: invalid literal for int() with base 10: '123.'
// >>> f('123+3')
// Traceback (most recent call last):
// ValueError: invalid literal for int() with base 10: '123+3'

// :param `inp`: string to convert to integer value.
// :type inp: str

// :return: `int` value from `inp` or `default`.
// :rtype: int or default
//   try:
//             return int(inp, base=10)
//         except ValueError:
//             if inp.strip() or self.default is False:
//                 raise
//             else:
//                 return self.default


// class Float(_bdfTypeBase):

//     """Real value.

// :ivar `minval`: minimum allowed for value
// :type minval: float
// :ivar `maxval`: maximum allowed for value
// :type maxval: float
// :ivar `default`: default value if input is empty.
//     `default` == `False` is set for value required.
// :type default: float
// """

//     _rank = 2

//     def __init__(self, name, minval=None, maxval=None, default=False):
//         """

// :param `name`: Value for setting the instance variables.
// :type name: str
// :param `minval`: Value for setting the instance variables.
// :type minval: float
// :param `maxval`: Value for setting the instance variables.
// :type maxval: float
// :param `default`: Value for setting the instance variables.
// :type default: float, None, or False
// """
//         _bdfTypeBase.__init__(self, name)
//         self.minval = minval
//         self.maxval = maxval
//         self.default = default

//     def __call__(self, inp):
bdf_float::bdf_float(string name) :
  bdf_type_base(name), bounds(bdf_num_bounds<double>()) {};

bdf_float::bdf_float(string name, bdf_num_bounds<double> _bounds) :
  bdf_type_base(name), bounds(_bounds) {};

// Convert string to float
void bdf_float::operator()(string inp) {
  string sval = trim(inp);
  transform(sval.begin(), sval.end(),sval.begin(), ::toupper);
  string::size_type ppos = sval.find('+', 1);
  string::size_type npos = sval.find('-', 1);
  string::size_type pos = min(ppos, npos);
  if (pos != string::npos) {
    if (sval[ppos - 1] != 'E')
      sval.insert(pos, "E");
  }
  if (sval.length() == 0) {
    value = this->bounds.get_default();
  } else {
    istringstream buffer(sval);
    buffer >> value;
  }
  if (!this->bounds.in_bounds(value))
    throw  "** BDF INP ERROR **: boundary condition violated";
}


// >>> f = Float('dummy')
// >>> assert f('123.') == 123.0
// >>> assert f('123+3') == 123000.0

// :param `inp`: string to convert to float value.
// :type inp: str

// :return: float value from `inp` or `default`.
// :rtype: float, None, False
// """
//         _INP = inp.strip()
//         if _INP or inp is False:
//             is_exp = FLOAT_MASSAGE.search(_INP, 1)
//             if is_exp:
//                 _INP = "%se%c%s" % (_INP[:is_exp.start()], is_exp.groups()[0],
//                                     _INP[is_exp.end():])
//             return float(_INP)
//         else:
//             return self.default


// class Str(_bdfTypeBase):

//     """Real value.

// :ivar `allowed`: If not `None` a list of allowed values.
// :type allowed: tuple(str) or None
// :ivar `default`: default value if input is empty. `default` == False
//     is set for value required.
// :type default: str
// """

//     _rank = 3

//     def __init__(self, name, default=None, allowed=None):
//         """
// :param    `default`: Value for setting the instance variables.
// :type default: `str`, ``None``, or ``False``
// :param `allowed`: Value for setting the instance variables.
// :type allowed: tuple(str) or None
// """
//         _bdfTypeBase.__init__(self, name)
//         self.default = default
//         self.allowed = allowed

//     def __call__(self, inp):
//         """Return the requested string value.

// :param `inp`: string to be returned.
// :type inp: str
// :return: str value from `inp` or `default`.
// :rtype: str, None, or False
// """
//         res = inp.strip()
//         if not res:
//             if self.default is False:
//                 raise ValueError
//             else:
//                 res = self.default.strip()
//         if self.allowed is not None and res not in self.allowed:
//             raise ValueError("'{}' not list of allowed values: '{}'".format(
//                 res, ','.join(self.allowed)))
//         return res


// class List(_bdfTypeBase):

//     """List of integers.
// """

//     def __init__(self, name, maxelem=None, minval=None, maxval=None,
//                  uniq=None):
//         _bdfTypeBase.__init__(self, name)
//         self.maxelem = maxelem
//         self.minval = minval
//         self.maxval = maxval
//         self.uniq = uniq

//     def __call__(self, inp):
//         return tuple([int(i) for i in inp.strip()])


// class Choose(_bdfTypeBase):

//     "Choose between multiple entries"

//     def __init__(self, *args):
//         """
// :param `args`: args to choose from.
// :type args: list(_bdfTypeBase)
// """
//         self.args = tuple(sorted(args))
//         _bdfTypeBase.__init__(self, '_'.join(
//             [i.name for i in self.args
//              if not isinstance(i, Blank)]))

//     def __call__(self, inp):
//         """Convert string `inp` first fitting type.

// >>> f = Choose(Float('doggy'), Int('dummy'))
// >>> assert f('123') == 123
// >>> assert f('123.') == 123.0
// >>> assert f('123+3') == 123000.0
// >>> f('invalid') # doctest: +IGNORE_EXCEPTION_DETAIL
// Traceback (most recent call last):
// ValueError: invalid literal for dummy, doggy: 'invalid'

// :param `inp`: string to convert to integer value.
// :type inp: str

// :return: `int` value from `inp` or `default`.
// :rtype: int or default
// """
//         for i in self.args:
//             if not inp.strip():
//                 if isinstance(i, Blank):
//                     return i
//             else:
//                 try:
//                     return i(inp)
//                 except ValueError:
//                     pass
//         try:
//             return i(inp)
//         except ValueError:
//             raise ValueError("invalid literal for %s: '%s'" %
//                              (','.join([a.name for a in self.args]), inp))


// class Cross(_bdfTypeBase):

//     "Cross reference for default values."

//     def __init__(self, name):
//         """
// :param `name`: name of cross referenced entry.
// :type name: str
// """
//         _bdfTypeBase.__init__(self, name)

//     def __call__(self, dummy):
//         raise ValueError("Element `Cross` no yet supported")


// class Blank(_bdfTypeBase):

//     "Empty entry."

//     _rank = 999

//     def __init__(self):
//         _bdfTypeBase.__init__(self, 'Blank')

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check"
  coding: utf-8
  End:
*/
