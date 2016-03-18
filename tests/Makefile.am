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
LDADD = $(LIBOBJS) $(LTLIBINTL)
top=../

SUBDIRS=
EXTRA_DIST=base_test.ju

test_extfem_LDADD=../src/libextfemio.la -lboost_regex

TESTS=
check_PROGRAMS=

check_PROGRAMS += test_extfem_string
test_extfem_string_SOURCES=test_extfem_string.cpp
test_extfem_string_LDADD=$(test_extfem_LDADD)
TESTS += test_extfem_string.ju

check_PROGRAMS += test_bdf_bounds
test_bdf_bounds_SOURCES=test_bdf_bounds.cpp
test_bdf_bounds_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_bounds.ju

check_PROGRAMS += test_bdf_float
test_bdf_float_SOURCES=test_bdf_float.cpp
test_bdf_float_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_float.ju

check_PROGRAMS += test_bdf_int
test_bdf_int_SOURCES=test_bdf_int.cpp
test_bdf_int_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_int.ju

check_PROGRAMS += test_bdf_list
test_bdf_list_SOURCES=test_bdf_list.cpp
test_bdf_list_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_list.ju

check_PROGRAMS += test_bdf_str
test_bdf_str_SOURCES=test_bdf_str.cpp
test_bdf_str_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_str.ju

check_PROGRAMS += test_bdf_types
test_bdf_types_SOURCES=test_bdf_types.cpp
test_bdf_types_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_types.ju

check_PROGRAMS += test_bdf_cards
test_bdf_cards_SOURCES=test_bdf_cards.cpp
test_bdf_cards_SOURCES += test_bdf_cards_cbar.cpp
test_bdf_cards_SOURCES += test_bdf_cards_cbeam.cpp
test_bdf_cards_SOURCES += test_bdf_cards_cquad4.cpp
test_bdf_cards_SOURCES += test_bdf_cards_crod.cpp
test_bdf_cards_SOURCES += test_bdf_cards_ctria3.cpp
test_bdf_cards_SOURCES += test_bdf_cards_enddata.cpp
test_bdf_cards_SOURCES += test_bdf_cards_grid.cpp
test_bdf_cards_SOURCES += test_bdf_cards_mat1.cpp
test_bdf_cards_SOURCES += test_bdf_cards_mat2.cpp
test_bdf_cards_SOURCES += test_bdf_cards_pbar.cpp
test_bdf_cards_SOURCES += test_bdf_cards_pbarl.cpp
test_bdf_cards_SOURCES += test_bdf_cards_pbeam.cpp
test_bdf_cards_SOURCES += test_bdf_cards_pbeaml.cpp
test_bdf_cards_SOURCES += test_bdf_cards_prod.cpp
test_bdf_cards_SOURCES += test_bdf_cards_pshell.cpp
test_bdf_cards_SOURCES += test_bdf_cards_force.cpp
test_bdf_cards_SOURCES += test_bdf_cards_moment.cpp
test_bdf_cards_SOURCES += test_bdf_cards_load.cpp

test_bdf_cards_LDADD=$(test_extfem_LDADD)
TESTS += test_bdf_cards.ju

check_PROGRAMS += test_fem_float
test_fem_float_SOURCES=test_fem_float.cpp
test_fem_float_LDADD=$(test_extfem_LDADD)
TESTS += test_fem_float.ju

check_PROGRAMS += test_fem_int
test_fem_int_SOURCES=test_fem_int.cpp
test_fem_int_LDADD=$(test_extfem_LDADD)
TESTS += test_fem_int.ju

check_PROGRAMS += test_fem_bool
test_fem_bool_SOURCES=test_fem_bool.cpp
test_fem_bool_LDADD=$(test_extfem_LDADD)
TESTS += test_fem_bool.ju

check_PROGRAMS += test_fem_list
test_fem_list_SOURCES=test_fem_list.cpp
test_fem_list_LDADD=$(test_extfem_LDADD)
TESTS += test_fem_list.ju

check_PROGRAMS += test_fem_cards
test_fem_cards_SOURCES =test_fem_cards.cpp
test_fem_cards_SOURCES += test_fem_cards_date.cpp
test_fem_cards_SOURCES += test_fem_cards_gbarm.cpp
test_fem_cards_SOURCES += test_fem_cards_gbeamg.cpp
test_fem_cards_SOURCES += test_fem_cards_gcoord.cpp
test_fem_cards_SOURCES += test_fem_cards_geccen.cpp
test_fem_cards_SOURCES += test_fem_cards_gelth.cpp
test_fem_cards_SOURCES += test_fem_cards_giorh.cpp
test_fem_cards_SOURCES += test_fem_cards_glsec.cpp
test_fem_cards_SOURCES += test_fem_cards_gpipe.cpp
test_fem_cards_SOURCES += test_fem_cards_gnode.cpp
test_fem_cards_SOURCES += test_fem_cards_bldep.cpp
test_fem_cards_SOURCES += test_fem_cards_bnbcd.cpp
test_fem_cards_SOURCES += test_fem_cards_bndispl.cpp
test_fem_cards_SOURCES += test_fem_cards_bnload.cpp
test_fem_cards_SOURCES += test_fem_cards_mgsprng.cpp
test_fem_cards_SOURCES += test_fem_cards_gsetmemb.cpp
test_fem_cards_SOURCES += test_fem_cards_gunivec.cpp
test_fem_cards_SOURCES += test_fem_cards_misosel.cpp
test_fem_cards_SOURCES += test_fem_cards_ident.cpp
test_fem_cards_SOURCES += test_fem_cards_iend.cpp
test_fem_cards_SOURCES += test_fem_cards_gelmnt1.cpp
test_fem_cards_SOURCES += test_fem_cards_gelref1.cpp
test_fem_cards_SOURCES += test_fem_cards_text.cpp
test_fem_cards_SOURCES += test_fem_cards_tdsetnam.cpp
test_fem_cards_SOURCES += test_fem_cards_tdsupnam.cpp
test_fem_cards_SOURCES += test_fem_cards_tdload.cpp
test_fem_cards_SOURCES += test_fem_cards_bsell.cpp
test_fem_cards_SOURCES += test_fem_cards_gelmnt2.cpp
test_fem_cards_SOURCES += test_fem_cards_hsupstat.cpp
test_fem_cards_SOURCES += test_fem_cards_hsuptran.cpp
test_fem_cards_SOURCES += test_fem_cards_hierarch.cpp
test_fem_cards_SOURCES += test_fem_cards_beuslo.cpp
test_fem_cards_LDADD=$(test_extfem_LDADD)
TESTS += test_fem_cards.ju

check_PROGRAMS += test_fem_elements
test_fem_elements_SOURCES =test_fem_elements.cpp
test_fem_elements_SOURCES += test_fem_element_adva_2.cpp
test_fem_elements_SOURCES += test_fem_element_adva_4.cpp
test_fem_elements_SOURCES += test_fem_element_axcs.cpp
test_fem_elements_SOURCES += test_fem_element_axda.cpp
test_fem_elements_SOURCES += test_fem_element_axis.cpp
test_fem_elements_SOURCES += test_fem_element_axlq.cpp
test_fem_elements_SOURCES += test_fem_element_axls.cpp
test_fem_elements_SOURCES += test_fem_element_axqq.cpp
test_fem_elements_SOURCES += test_fem_element_beas.cpp
test_fem_elements_SOURCES += test_fem_element_beps.cpp
test_fem_elements_SOURCES += test_fem_element_btss.cpp
test_fem_elements_SOURCES += test_fem_element_csta.cpp
test_fem_elements_SOURCES += test_fem_element_ctal.cpp
test_fem_elements_SOURCES += test_fem_element_ctaq.cpp
test_fem_elements_SOURCES += test_fem_element_ctcc.cpp
test_fem_elements_SOURCES += test_fem_element_ctcl.cpp
test_fem_elements_SOURCES += test_fem_element_ctcp.cpp
test_fem_elements_SOURCES += test_fem_element_ctcq.cpp
test_fem_elements_SOURCES += test_fem_element_ctlq.cpp
test_fem_elements_SOURCES += test_fem_element_ctmq.cpp
test_fem_elements_SOURCES += test_fem_element_fqus_ffq.cpp
test_fem_elements_SOURCES += test_fem_element_ftrs_fftr.cpp
test_fem_elements_SOURCES += test_fem_element_gdam.cpp
test_fem_elements_SOURCES += test_fem_element_ghex.cpp
test_fem_elements_SOURCES += test_fem_element_glda.cpp
test_fem_elements_SOURCES += test_fem_element_glma.cpp
test_fem_elements_SOURCES += test_fem_element_glsh.cpp
test_fem_elements_SOURCES += test_fem_element_gmas.cpp
test_fem_elements_SOURCES += test_fem_element_gspr.cpp
test_fem_elements_SOURCES += test_fem_element_hcqs.cpp
test_fem_elements_SOURCES += test_fem_element_ihex.cpp
test_fem_elements_SOURCES += test_fem_element_ilst.cpp
test_fem_elements_SOURCES += test_fem_element_ipri.cpp
test_fem_elements_SOURCES += test_fem_element_iqqe.cpp
test_fem_elements_SOURCES += test_fem_element_itet.cpp
test_fem_elements_SOURCES += test_fem_element_lcqs.cpp
test_fem_elements_SOURCES += test_fem_element_lcts.cpp
test_fem_elements_SOURCES += test_fem_element_lhex.cpp
test_fem_elements_SOURCES += test_fem_element_lqua.cpp
test_fem_elements_SOURCES += test_fem_element_matr.cpp
test_fem_elements_SOURCES += test_fem_element_mcqs.cpp
test_fem_elements_SOURCES += test_fem_element_mcts.cpp
test_fem_elements_SOURCES += test_fem_element_pcab.cpp
test_fem_elements_SOURCES += test_fem_element_pils.cpp
test_fem_elements_SOURCES += test_fem_element_pspr.cpp
test_fem_elements_SOURCES += test_fem_element_rpbq.cpp
test_fem_elements_SOURCES += test_fem_element_scqs.cpp
test_fem_elements_SOURCES += test_fem_element_scts.cpp
test_fem_elements_SOURCES += test_fem_element_secb.cpp
test_fem_elements_SOURCES += test_fem_element_slcb.cpp
test_fem_elements_SOURCES += test_fem_element_slqs.cpp
test_fem_elements_SOURCES += test_fem_element_slts.cpp
test_fem_elements_SOURCES += test_fem_element_tess.cpp
test_fem_elements_SOURCES += test_fem_element_tetr.cpp
test_fem_elements_SOURCES += test_fem_element_tpri.cpp
test_fem_elements_SOURCES += test_fem_element_trs1.cpp
test_fem_elements_SOURCES += test_fem_element_trs2.cpp
test_fem_elements_SOURCES += test_fem_element_trs3.cpp
test_fem_elements_LDADD=$(test_extfem_LDADD)
TESTS += test_fem_elements.ju

test_MISC=

test_fem_element_ghex.h : ../tools/ghex_do.py	\
  ../tools/templates/elements_ghex.h		\
  ../tools/templates/element_ghex.cpp		\
  ../tools/templates/test_fem_element_ghex.cpp
	(set -e ; cd .. ; python3 tools/ghex_do.py)

test_%.ju: base_test.ju
	ln -sf $< $@

# Local Variables:
# mode: makefile-automake
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
