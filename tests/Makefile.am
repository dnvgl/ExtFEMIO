# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile specifications for testing bdf access library.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# For use with: automake
# Relative File Name: tests/Makefile.am

AM_CPPFLAGS=-I../include -Wall -std=c++11

top=../

SUBDIRS=
EXTRA_DIST=Project.ede
check_PROGRAMS=test_bdf_types test_bdf_bounds test_bdf_int test_bdf_float test_bdf_string test_bdf_list test_cards
test_bdf_types_SOURCES=test_bdf_types.cpp
test_bdf_bounds_SOURCES=test_bdf_bounds.cpp
test_bdf_int_SOURCES=test_bdf_int.cpp
test_bdf_float_SOURCES=test_bdf_float.cpp
test_bdf_string_SOURCES=test_bdf_string.cpp
test_bdf_list_SOURCES=test_bdf_list.cpp
test_cards_SOURCES=test_cards.cpp test_cards_grid.cpp

test_MISC=
test_bdf_types_LDADD= ../src/libbdfreadpp.la -lboost_regex
test_bdf_bounds_LDADD= ../src/libbdfreadpp.la -lboost_regex
test_bdf_int_LDADD= ../src/libbdfreadpp.la -lboost_regex
test_bdf_float_LDADD= ../src/libbdfreadpp.la -lboost_regex
test_bdf_string_LDADD= ../src/libbdfreadpp.la -lboost_regex
test_bdf_list_LDADD= ../src/libbdfreadpp.la -lboost_regex
test_cards_LDADD= ../src/libbdfreadpp.la -lboost_regex

TESTS=test_bdf_types test_bdf_bounds test_bdf_int test_bdf_float test_bdf_string test_bdf_list test_cards

# Local Variables:
# mode: makefile-automake
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 7"
# End:

# End of Makefile.am
