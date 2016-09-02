#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate test code for FEM elements.
"""

from __future__ import (
    division, print_function, absolute_import, unicode_literals)

# Standard libraries.
import functools

# Third party libraries.
from jinja2 import Environment, FileSystemLoader

# DNV GL libraries.
from elements_data import ELEMENTS, list_init, list_init_form

# ID: $Id$
__date__ = "$Date::                            $"[7:-1]
__scm_version__ = "$Revision$"[10:-1]
__author__ = "`Berthold Höllmann <berthold.hoellmann@dnvgl.com>`__"
__copyright__ = "Copyright © 2016 by DNV GL SE"


def fem_format(name, *vals):
    t = name[:]
    res = ""
    for i, val in enumerate(vals):
        if (i % 4) == 0:
            if t:
                res = "{:<8s}".format(t)
                t = False
            else:
                res += '\\n"\n            "' + " " * 8
        res += "{:+.9e}".format(val)
    return '"{}\\n"'.format(res)


gelmnt1 = functools.partial(fem_format, "GELMNT1")
gelref1 = functools.partial(fem_format, "GELREF1")

if __name__ == '__main__':

    env = Environment(loader=FileSystemLoader('tools/templates'))
    test_tmpl = env.get_template('test_fem_element.cpp')

    for elem, vals in ELEMENTS:
        with open("tests/test_fem_element_{}.cpp".format(elem), "w") as test:
            test.write(test_tmpl.render(
                list_init_form=list_init_form, list_init=list_init,
                elem=elem, gelmnt1=gelmnt1, gelref1=gelref1, **vals))

# Local Variables:
# mode: python
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# End:
