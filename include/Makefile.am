# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile definitions for libExtFEMIO++.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# For use with: automake
# Relative File Name: include/Makefile.am

top=../

EXTRA_DIST =bdf/cards_elements.h
EXTRA_DIST+=bdf/cards.h
EXTRA_DIST+=bdf/cards_loads.h
EXTRA_DIST+=bdf/cards_properties.h
EXTRA_DIST+=bdf/errors.h
EXTRA_DIST+=bdf/file.h
EXTRA_DIST+=bdf/type_bounds.h
EXTRA_DIST+=bdf/types.h
EXTRA_DIST+=extfem_misc.h
EXTRA_DIST+=extfem_string.h
EXTRA_DIST+=fem/cards.h
EXTRA_DIST+=fem/cards_loads.h
EXTRA_DIST+=fem/cards_properties.h
EXTRA_DIST+=fem/elements_ghex.h
EXTRA_DIST+=fem/elements.h
EXTRA_DIST+=fem/errors.h
EXTRA_DIST+=fem/file.h
EXTRA_DIST+=fem/type_bounds.h
EXTRA_DIST+=fem/types.h
EXTRA_DIST+=my_c++14.h
EXTRA_DIST+=resource.h
EXTRA_DIST+=StdAfx.h
EXTRA_DIST+=catch.hpp

SUBDIRS=

fem/elements_ghex.h : ../tools/ghex_do.py	\
  ../tools/templates/element_ghex.h		\
  ../tools/templates/element_ghex.cpp		\
  ../tools/templates/test_fem_element_ghex.cpp
	(set -e ; cd .. ; python3 tools/ghex_do.py)

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 7"
# End:

# End of Makefile.am
