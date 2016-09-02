#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate access code for FEM elements.
"""

from __future__ import (
    division, print_function, absolute_import, unicode_literals)

# Third party libraries.
from jinja2 import Environment, FileSystemLoader

# DNV GL libraries.
from elements_data import *

# ID: $Id$
__date__ = "$Date::                            $"[7:-1]
__scm_version__ = "$Revision$"[10:-1]
__author__ = "`Berthold Höllmann <berthold.hoellmann@dnvgl.com>`__"
__copyright__ = "Copyright © 2016 by DNV GL SE"


if __name__ == '__main__':

    enums = [(i[0].upper(), i[1]['eltyp']) for i in ELEMENTS]
    for n in range(100, 164):
        enums.append(("GHEX{}".format(n), n))

    env = Environment(loader=FileSystemLoader('tools/templates'))
    head_tmpl = env.get_template('fem_elements.h')

    with open("include/fem/elements.h", "w") as head:
        head.write(head_tmpl.render(elements=ELEMENTS, enums=enums))

# Local Variables:
# mode: python
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# End:
