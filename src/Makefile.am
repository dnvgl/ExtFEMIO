# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile configuration for libBDFRead++.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# For use with: automake
# Relative File Name: src/Makefile.am

AM_CPPFLAGS=-I../include -Wall -std=c++11

top=../

SUBDIRS=
EXTRA_DIST=Project.ede
lib_LTLIBRARIES=libbdfreadpp.la
libbdfreadpp_la_SOURCES=bdf_types.cpp bdf_types_int.cpp bdf_types_float.cpp bdf_string.cpp
libbdfreadpp_la_SOURCES+=bdf_cards.cpp bdf_cards_grid.cpp

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
