#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate access code for FEM GHEX elements.
"""

from __future__ import (
    division, print_function, absolute_import, unicode_literals)

# Standard libraries.
import itertools

# Third party libraries.
from jinja2 import Environment, FileSystemLoader

# ID: $Id$
__date__ = "$Date::                            $"[7:-1]
__scm_version__ = "$Revision$"[10:-1]
__author__ = "`Berthold Höllmann <berthold.hoellmann@dnvgl.com>`__"
__copyright__ = "Copyright © 2016 by DNV GL SE"


def take(n):
    NODES = {1: 21, 2: 22, 4: 23, 8: 24, 16: 25, 32: 26}
    return tuple(NODES[i] for i in n)


def gen_extnodes(pos):
    if pos:
        return ", {}".format(
            ", ".join("node {}".format(i) for i in pos))
    return ""


def gen_nodepos(pos, space):
    res = []
    for i, num in enumerate(pos):
        res.append((i + 21,  num))
    return "\n".join(space + "- node {1} at pos {0}".format(*i) for i in res)

if __name__ == '__main__':

    res = []

    for x in itertools.chain(itertools.combinations(
            (1, 2, 4, 8, 16, 32), j) for j in range(7)):
        res += [(sum(k), take(k) + (27, )) for k in x]
    res.sort()

    env = Environment(loader=FileSystemLoader('tools/templates'))
    head_tmpl = env.get_template('element_ghex.h')
    code_tmpl = env.get_template('element_ghex.cpp')
    test_tmpl = env.get_template('test_fem_element_ghex.cpp')

    with open("include/fem/elements_ghex.h", "w") as head, \
         open("src/fem/fem_element_ghex.cpp", "w") as code, \
         open("tests/test_fem_element_ghex.cpp", "w") as test:

        head.write(head_tmpl.render(
            res=res, gen_extnodes=gen_extnodes,
            gen_nodepos=gen_nodepos))

        code.write(code_tmpl.render(
            res=res, gen_extnodes=gen_extnodes,
            gen_nodepos=gen_nodepos))

# Local Variables:
# mode: python
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j8"
# End:
