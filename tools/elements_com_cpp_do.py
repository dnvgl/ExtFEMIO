#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate access code for FEM elements.
"""

from __future__ import (
    division, print_function, absolute_import, unicode_literals)

# Third party libraries.
from jinja2 import Environment, FileSystemLoader

# DNV GL libraries.
from elements_data import ENUMS, ELEMENTS

# ID: $Id$
__date__ = "$Date::                            $"[7:-1]
__scm_version__ = "$Revision$"[10:-1]
__author__ = "`Berthold Höllmann <berthold.hoellmann@dnvgl.com>`__"
__copyright__ = "Copyright © 2016 by DNV GL SE"


if __name__ == '__main__':

    env = Environment(loader=FileSystemLoader('tools/templates'))
    code_tmpl = env.get_template('fem_elements.cpp')

    with open("src/fem/fem_elements.cpp", "w") as code:
        code.write(code_tmpl.render(enum=ENUMS, elements=ELEMENTS))

# Local Variables:
# mode: python
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# End:
