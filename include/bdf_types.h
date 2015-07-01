/* Copyright (C) 2015 by DNV GL SE */

/*
   Definitions for Nastran Bulk data entry types.

   Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

*/
/* ID: $Id$
 */

#if !defined _BERHOL20150407_BDF_TYPES
#define _BERHOL20150407_BDF_TYPES

#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
#include <limits>
#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif
#ifdef __GNUC__
using namespace boost;
#else
using namespace std;
#endif

#include "bdf_string.h"


namespace bdf {

  namespace type_bounds {

    class bdf_type_bounds {

    private:

      bool _has_min;
      bool _has_max;
      bool _has_default;

    protected:

      ~bdf_type_bounds () {};

      bool has_min() const {return _has_min;};

      void got_min() {_has_min = true;};

      bool has_max() const {return _has_max;};

      void got_max() {_has_max = true;};

      void got_default() {_has_default = true;};

    public:

      bdf_type_bounds() : _has_min(false), _has_max(false), _has_default(false) {};

      bool has_default() const {
        return _has_default;
      };
    };

    template <class T> class bdf_num_bounds : public bdf_type_bounds {

    protected:

      T min_val;
      T max_val;
      T default_val;

    public:

      ~bdf_num_bounds() {};

      bdf_num_bounds() {};

      bdf_num_bounds(const T* _min, const T* _max=NULL, const T* _default=NULL) {
        if (_min != NULL)
          set_min(*_min);
        if (_max != NULL)
          set_max(*_max);
        if (_default != NULL)
          set_default(*_default);
      };

      void set_min(const T inp) {
        this->min_val = inp;
        got_min();
      };

      void set_max(const T inp) {
        this->max_val = inp;
        got_max();
      };

      void set_default(const T inp) {
        this->default_val = inp;
        got_default();
      };

      T get_default() const {
        if (!has_default())
          throw "** ERROR **: No default value avaliable.";
        return this->default_val;
      };

      bool in_bounds(T val) const {
        return ((!has_min() || val >= this->min_val) &&
                (!has_max() || val <= this->max_val));
      };
    };
  };

  namespace types {

    using namespace ::bdf::type_bounds;

    typedef enum {None, Int, Float, Str, List, Choose, Cross, Blank} bdf_types;

    class bdf_type_base {

    private:

      std::string name;

    protected:

      static const bdf_types _type;

    public:

      bdf_type_base(std::string name);

      ~bdf_type_base() {};

      virtual void parse(std::string) = 0;

      virtual bdf_types type() const = 0;

      template <class T1, class T2>
      friend bool operator== (const T1&, const T2&);

      template <class T1, class T2>
      friend inline bool operator< (const T1&, const T2&);

      template <class T1, class T2>
      friend inline bool operator> (const T1& one, const T2& other) {
        return other < one;
      };

      template <class T1, class T2>
      friend inline bool operator!= (const T1& one, const T2& other) {
        return !(other == one);
      };
    };

    template <class T1, class T2>
    inline bool operator== (const T1& one, const T2& other) {
      return (one.type() == other.type());
    }

    template <class T1, class T2>
    inline bool operator< (const T1& one, const T2& other) {
      return (one.type() < other.type());
    }

    class bdf_int : public bdf_type_base {

// Integer value.

// :ivar `minval`: minimum allowed for value
// :type minval: int
// :ivar `maxval`: maximum allowed for value
// :type maxval: int
// :ivar `default`: default value if input is empty.
//     `default` == `False` is set for value required.
// :type default: int

    private:

      long value;

      bdf_num_bounds<long> bounds;
      static const regex int_re;

    protected:

      static const bdf_types _type = Int;

    public:

      bdf_int(std::string);

      bdf_int(std::string, bdf_num_bounds<long>);

      void parse(std::string);

      long operator() (void) {return value;};

      bdf_types type() const {return _type;};

      template <class T1, class T2>
      friend bool operator== (const T1& one, const T2& other);

      template <class T1, class T2>
      friend inline bool operator< (const T1& one, const T2& other);
    };

//     def __init__(self, name, minval=None, maxval=None, default=False):
//         """
// :param `name`: Value for setting the instance variables.
// :type name: str
// :param `minval`: Value for setting the instance variables.
// :type minval: int
// :param `maxval`: Value for setting the instance variables.
// :type maxval: int
// :param `default`: Value for setting the instance variables.
// :type default: int, None, or False
// """
//         _bdfTypeBase.__init__(self, name)
//         self.minval = minval
//         self.maxval = maxval
//         self.default = default

//     def __call__(self, inp):
//         """Convert string `inp` to integer.

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
// """
//         try:
//             return int(inp, base=10)
//         except ValueError:
//             if inp.strip() or self.default is False:
//                 raise
//             else:
//                 return self.default


    class bdf_float : public bdf_type_base {

// Real value.

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


    private:

      double value;

      bdf_num_bounds<double> bounds;
      static const regex float_exp_re;
      static const regex float_re;

    protected:

      static const bdf_types _type = Float;

    public:

      bdf_float(std::string);

      bdf_float(std::string, bdf_num_bounds<double>);

      void parse(std::string);

      double operator() (void) {return value;}

      bdf_types type() const {return _type;};

      template <class T1, class T2>
      friend bool operator== (const T1& one, const T2& other);

      template <class T1, class T2>
      friend inline bool operator< (const T1& one, const T2& other);
  };

//     def __call__(self, inp):
//         """Convert string to float

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


    template <class T> class bdf_list : public bdf_type_base {

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

    private:

      ::std::vector<T> value;

      static const regex int_re;

    protected:

      static const bdf_types _type = List;

    public:

      bdf_list(std::string name) :
        bdf_type_base(name) {};

      inline void parse (::std::string inp);

      inline ::std::vector<T> operator() (void) {return value;};

      inline bdf_types type() const {return _type;};

    };

    template <class T>
    const regex bdf_list<T>::int_re("[[:digit:]]+");

    template <> inline void bdf_list<int>::parse (std::string inp) {
      std::string sval = ::bdf::string::string(inp).trim();
      if (! regex_match(sval, int_re)) {
        std::string msg("illegal input, no integer\n");
        throw msg;
      }
      value.empty();
      for (::std::string::iterator pos = sval.begin(); pos != sval.end(); ++pos)
        value.push_back(*pos - '0');
    }


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


  };
}


#endif // _BERHOL20150407_BDF_TYPES

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C ../ check"
  coding:u tf-8
  End:
*/
