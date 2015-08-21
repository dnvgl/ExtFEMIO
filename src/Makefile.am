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
EXTRA_DIST=
lib_LTLIBRARIES=libbdfreadpp.la
libbdfreadpp_la_SOURCES=bdf_errors.cpp
libbdfreadpp_la_SOURCES+=bdf_file.cpp
libbdfreadpp_la_SOURCES+=bdf_types.cpp
libbdfreadpp_la_SOURCES+=bdf_types_int.cpp
libbdfreadpp_la_SOURCES+=bdf_types_float.cpp
libbdfreadpp_la_SOURCES+=bdf_types_str.cpp
libbdfreadpp_la_SOURCES+=bdf_string.cpp
libbdfreadpp_la_SOURCES+=bdf_cards.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_grid.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_mat1.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_shell.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_ctria3.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_cquad4.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_pshell.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_cbeam.cpp
libbdfreadpp_la_SOURCES+=bdf_cards_cbar.cpp

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
