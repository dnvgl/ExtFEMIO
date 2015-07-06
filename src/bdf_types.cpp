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
#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"
#include "bdf_string.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;
using namespace bdf::string;
#ifdef __GNUC__
using namespace boost;
#endif


bdf_type_base::bdf_type_base(::std::string name) : name(name) {};

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
