# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile configuration for libExtfemio++.

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
lib_LTLIBRARIES = libextfemio.la
libextfemio_la_SOURCES  = extfem_string.cpp

lib_LTLIBRARIES += libextfemio_bdf.la
libextfemio_bdf_la_SOURCES = bdf/bdf_types.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_types_float.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_types_int.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_types_list_int.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_file.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_l_geom.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_errors.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_bar_prop.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_beam_prop.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_cbar.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_cbeam.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_cquad4.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_crod.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_ctria3.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_enddata.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_grid.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_mat.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_mat1.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_mat2.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_pbar.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_pbarl.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_pbeam.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_pbeaml.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_prod.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_pshell.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_shell.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_momforce_base.cpp
libextfemio_bdf_la_SOURCES += bdf/bdf_cards_load.cpp

lib_LTLIBRARIES += libextfemio_fem.la
libextfemio_fem_la_SOURCES = fem/fem_cards.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_date.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gbarm.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gbeamg.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gcoord.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gnode.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_geccen.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gelth.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_giorh.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gusyi.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_glsec.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gpipe.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_belfix.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_bldep.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_bnbcd.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_bndispl.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_bnload.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_mgsprng.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gsetmemb.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gunivec.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_misosel.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_ident.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_iend.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gelmnt1.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gelref1.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_text.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_tdsetnam.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_tdsupnam.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_tdload.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_bsell.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_gelmnt2.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_hsupstat.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_hsuptran.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_hierarch.cpp
libextfemio_fem_la_SOURCES += fem/fem_cards_beuslo.cpp
libextfemio_fem_la_SOURCES += fem/fem_elements.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_thin_shell.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_beps.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_csta.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_rpbq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ilst.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_iqqe.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_lqua.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_tess.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_gmas.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_glma.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_glda.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_beas.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_axis.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_axda.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_gspr.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_gdam.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ihex.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_lhex.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_secb.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_btss.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_fqus_ffq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ftrs_fftr.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_scts.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_mcts.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_scqs.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_mcqs.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ipri.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_itet.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_tpri.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_tetr.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_lcts.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_lcqs.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_trs1.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_trs2.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_trs3.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_glsh.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_axcs.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_axlq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_axls.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_axqq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_pils.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_pcab.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_pspr.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_adva_4.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_adva_2.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctcp.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctcl.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctal.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctcc.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctaq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctlq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctcq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ctmq.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_hcqs.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_slqs.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_slts.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_slcb.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_matr.cpp
libextfemio_fem_la_SOURCES += fem/fem_element_ghex.cpp
libextfemio_fem_la_SOURCES += fem/fem_errors.cpp
libextfemio_fem_la_SOURCES += fem/fem_file.cpp
libextfemio_fem_la_SOURCES += fem/fem_type_bounds.cpp
libextfemio_fem_la_SOURCES += fem/fem_types.cpp
libextfemio_fem_la_SOURCES += fem/fem_types_bool.cpp
libextfemio_fem_la_SOURCES += fem/fem_types_float.cpp
libextfemio_fem_la_SOURCES += fem/fem_types_int.cpp
libextfemio_fem_la_SOURCES += fem/fem_types_list_int.cpp
libextfemio_fem_la_SOURCES += fem/fem_types_str.cpp

../include/fem/elements_ghex.h : fem/fem_element_ghex.cpp
fem/fem_element_ghex.cpp : ../tools/ghex_do.py	\
  ../tools/templates/element_ghex.h		\
  ../tools/templates/element_ghex.cpp		\
  ../tools/templates/test_fem_element_ghex.cpp
	(set -e ; cd .. ; python3 tools/ghex_do.py) || \
	svn revert fem/fem_element_ghex.cpp ../include/fem/elements_ghex.h

bin_PROGRAMS=bdf2bdf fem2fem

bdf2bdf_SOURCES =bdf/bdf2bdf.cpp
bdf2bdf_SOURCES+=bdf/bdf2bdf_args.c
bdf2bdf_LDADD=$(LIBOBJS) $(LTLIBINTL)

fem2fem_SOURCES =fem/fem2fem.cpp
fem2fem_SOURCES+=fem/fem2fem_args.c
fem2fem_LDADD=$(LIBOBJS) $(LTLIBINTL)

%_args.o: AM_CPPFLAGS = -I../include -Wall

%.c : %.ggo
	$(GENGETOPT) --input=$<			\
  --file-name=$(shell basename $(@F) .c)	\
  --header-output-dir=../include/		\
  --src-output-dir=$(@D) --unamed-opts

vpath %.ggo fem bdf
vpath %.c fem bdf
vpath %.o fem bdf

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
