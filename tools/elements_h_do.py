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

    ENV = Environment(loader=FileSystemLoader(
        TEMPLATE_PATH), extensions=[LineExtension])
    HEAD_TMPL = ENV.get_template('fem_elements.h')

    with open("include/fem/elements.h", "w") as HEAD:
        HEAD.write(HEAD_TMPL.render(elements=ELEMENTS, enums=ENUMS))

# Local Variables:
# mode: python
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# End:
