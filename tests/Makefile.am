# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile specifications for testing FEM files access library.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# For use with: automake
# Relative File Name: tests/Makefile.am

AM_CPPFLAGS=-I../include -Wall -Werror $(BOOST_CPPFLAGS)
AM_LDFLAGS = $(BOOST_REGEX_LDFLAGS)
LDADD = $(BOOST_REGEX_LIBS)
top=../

SUBDIRS=
EXTRA_DIST=base_test.ju

test_extfem_LDADD=../src/libextfemio.la -lboost_regex

TESTS=
check_PROGRAMS=

check_PROGRAMS+=test_extfem_string
test_extfem_string_SOURCES=test_extfem_string.cpp
test_extfem_string_LDADD=$(test_extfem_LDADD)
TESTS+=test_extfem_string.ju

check_PROGRAMS+=test_bdf_bounds
test_bdf_bounds_SOURCES=test_bdf_bounds.cpp
test_bdf_bounds_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_bounds.ju

check_PROGRAMS+=test_bdf_float
test_bdf_float_SOURCES=test_bdf_float.cpp
test_bdf_float_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_float.ju

check_PROGRAMS+=test_bdf_int
test_bdf_int_SOURCES=test_bdf_int.cpp
test_bdf_int_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_int.ju

check_PROGRAMS+=test_bdf_list
test_bdf_list_SOURCES=test_bdf_list.cpp
test_bdf_list_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_list.ju

check_PROGRAMS+=test_bdf_str
test_bdf_str_SOURCES=test_bdf_str.cpp
test_bdf_str_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_str.ju

check_PROGRAMS+=test_bdf_types
test_bdf_types_SOURCES=test_bdf_types.cpp
test_bdf_types_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_types.ju

check_PROGRAMS+=test_bdf_cards
test_bdf_cards_SOURCES=test_bdf_cards.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_cbar.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_cbeam.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_cquad4.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_crod.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_ctria3.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_enddata.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_grid.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_mat1.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_pbar.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_pbarl.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_pbeam.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_pbeaml.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_prod.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_pshell.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_force.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_moment.cpp
test_bdf_cards_SOURCES+=test_bdf_cards_load.cpp
test_bdf_cards_LDADD=$(test_extfem_LDADD)
TESTS+=test_bdf_cards.ju

check_PROGRAMS+=test_fem_float
test_fem_float_SOURCES=test_fem_float.cpp
test_fem_float_LDADD=$(test_extfem_LDADD)
TESTS+=test_fem_float.ju

check_PROGRAMS+=test_fem_int
test_fem_int_SOURCES=test_fem_int.cpp
test_fem_int_LDADD=$(test_extfem_LDADD)
TESTS+=test_fem_int.ju

check_PROGRAMS+=test_fem_bool
test_fem_bool_SOURCES=test_fem_bool.cpp
test_fem_bool_LDADD=$(test_extfem_LDADD)
TESTS+=test_fem_bool.ju

check_PROGRAMS+=test_fem_list
test_fem_list_SOURCES=test_fem_list.cpp
test_fem_list_LDADD=$(test_extfem_LDADD)
TESTS+=test_fem_list.ju

check_PROGRAMS+=test_fem_cards
test_fem_cards_SOURCES =test_fem_cards.cpp
test_fem_cards_SOURCES+=test_fem_cards_date.cpp
test_fem_cards_SOURCES+=test_fem_cards_gbarm.cpp
test_fem_cards_SOURCES+=test_fem_cards_gbeamg.cpp
test_fem_cards_SOURCES+=test_fem_cards_gcoord.cpp
test_fem_cards_SOURCES+=test_fem_cards_geccen.cpp
test_fem_cards_SOURCES+=test_fem_cards_gelth.cpp
test_fem_cards_SOURCES+=test_fem_cards_giorh.cpp
test_fem_cards_SOURCES+=test_fem_cards_glsec.cpp
test_fem_cards_SOURCES+=test_fem_cards_gpipe.cpp
test_fem_cards_SOURCES+=test_fem_cards_gnode.cpp
test_fem_cards_SOURCES+=test_fem_cards_bldep.cpp
test_fem_cards_SOURCES+=test_fem_cards_bnbcd.cpp
test_fem_cards_SOURCES+=test_fem_cards_bndispl.cpp
test_fem_cards_SOURCES+=test_fem_cards_bnload.cpp
test_fem_cards_SOURCES+=test_fem_cards_mgsprng.cpp
test_fem_cards_SOURCES+=test_fem_cards_gsetmemb.cpp
test_fem_cards_SOURCES+=test_fem_cards_gunivec.cpp
test_fem_cards_SOURCES+=test_fem_cards_misosel.cpp
test_fem_cards_SOURCES+=test_fem_cards_ident.cpp
test_fem_cards_SOURCES+=test_fem_cards_iend.cpp
test_fem_cards_SOURCES+=test_fem_cards_gelmnt1.cpp
test_fem_cards_SOURCES+=test_fem_cards_gelref1.cpp
test_fem_cards_SOURCES+=test_fem_cards_text.cpp
test_fem_cards_SOURCES+=test_fem_cards_tdsetnam.cpp
test_fem_cards_SOURCES+=test_fem_cards_tdsupnam.cpp
test_fem_cards_LDADD=$(test_extfem_LDADD)
TESTS+=test_fem_cards.ju

test_MISC=

test_%.ju: base_test.ju
	ln -sf $< $@

# Local Variables:
# mode: makefile-automake
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
