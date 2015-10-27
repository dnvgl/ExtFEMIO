# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile specifications for testing bdf access library.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# For use with: automake
# Relative File Name: tests/Makefile.am

AM_CPPFLAGS=-I../include -Wall $(BOOST_CPPFLAGS)
AM_LDFLAGS = $(BOOST_REGEX_LDFLAGS)
LDADD = $(BOOST_REGEX_LIBS)
top=../

SUBDIRS=
EXTRA_DIST=base_test.ju
check_PROGRAMS=test_bdf_bounds
check_PROGRAMS+=test_bdf_float
check_PROGRAMS+=test_bdf_int
check_PROGRAMS+=test_bdf_list
check_PROGRAMS+=test_bdf_str
check_PROGRAMS+=test_bdf_string
check_PROGRAMS+=test_bdf_types
check_PROGRAMS+=test_cards
test_bdf_types_SOURCES=test_bdf_types.cpp
test_bdf_bounds_SOURCES=test_bdf_bounds.cpp
test_bdf_int_SOURCES=test_bdf_int.cpp
test_bdf_float_SOURCES=test_bdf_float.cpp
test_bdf_str_SOURCES=test_bdf_str.cpp
test_bdf_string_SOURCES=test_bdf_string.cpp
test_bdf_list_SOURCES=test_bdf_list.cpp
test_cards_SOURCES=test_cards.cpp
test_cards_SOURCES+=test_cards_cbar.cpp
test_cards_SOURCES+=test_cards_cbeam.cpp
test_cards_SOURCES+=test_cards_cquad4.cpp
test_cards_SOURCES+=test_cards_crod.cpp
test_cards_SOURCES+=test_cards_ctria3.cpp
test_cards_SOURCES+=test_cards_grid.cpp
test_cards_SOURCES+=test_cards_mat1.cpp
test_cards_SOURCES+=test_cards_pbar.cpp
test_cards_SOURCES+=test_cards_pbarl.cpp
test_cards_SOURCES+=test_cards_pbeam.cpp
test_cards_SOURCES+=test_cards_pbeaml.cpp
test_cards_SOURCES+=test_cards_prod.cpp
test_cards_SOURCES+=test_cards_pshell.cpp


test_MISC=
test_bdf_LDADD=../bdf/libbdfreadpp.la -lboost_regex
test_bdf_=../bdf/libbdfreadpp.la -lboost_regex
test_bdf_types_LDADD=$(test_bdf_LDADD)
test_bdf_bounds_LDADD=$(test_bdf_LDADD)
test_bdf_int_LDADD=$(test_bdf_LDADD)
test_bdf_float_LDADD=$(test_bdf_LDADD)
test_bdf_str_LDADD=$(test_bdf_LDADD)
test_bdf_string_LDADD=$(test_bdf_LDADD)
test_bdf_list_LDADD=$(test_bdf_LDADD)
test_cards_LDADD=$(test_bdf_LDADD)

TESTS=test_bdf_types.ju
TESTS+=test_bdf_bounds.ju
TESTS+=test_bdf_int.ju
TESTS+=test_bdf_float.ju
TESTS+=test_bdf_str.ju
TESTS+=test_bdf_string.ju
TESTS+=test_bdf_list.ju
TESTS+=test_cards.ju

test_%.ju: base_test.ju
	ln -sf $< $@

# Local Variables:
# mode: makefile-automake
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
