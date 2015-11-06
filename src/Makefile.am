# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile configuration for libExtFEMRead++.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# For use with: automake
# Relative File Name: src/Makefile.am

AM_CPPFLAGS = -I../include -Wall -Werror $(BOOST_CPPFLAGS)
AUTOMAKE_OPTIONS = subdir-objects

top=../

SUBDIRS=
EXTRA_DIST=
lib_LTLIBRARIES = libextfemread.la
libextfemread_la_SOURCES  = extfem_string.cpp
libextfemread_la_SOURCES += bdf/bdf_errors.cpp
libextfemread_la_SOURCES += bdf/bdf_cards.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_bar_prop.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_beam_prop.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_cbar.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_cbeam.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_cquad4.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_crod.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_ctria3.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_grid.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_mat1.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbar.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbarl.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbeam.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbeaml.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_prod.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pshell.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_shell.cpp
libextfemread_la_SOURCES += bdf/bdf_file.cpp
libextfemread_la_SOURCES += bdf/bdf_l_geom.cpp
libextfemread_la_SOURCES += bdf/bdf_types.cpp
libextfemread_la_SOURCES += bdf/bdf_types_float.cpp
libextfemread_la_SOURCES += bdf/bdf_types_int.cpp
libextfemread_la_SOURCES += bdf/bdf_types_list_int.cpp
libextfemread_la_SOURCES += bdf/bdf_types_str.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_momforce_base.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_load.cpp

libextfemread_la_SOURCES += fem/fem_errors.cpp
libextfemread_la_SOURCES += fem/fem_types.cpp
libextfemread_la_SOURCES += fem/fem_types_float.cpp
libextfemread_la_SOURCES += fem/fem_types_int.cpp
# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
