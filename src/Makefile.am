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

libextfemio_la_SOURCES += bdf/bdf_types.cpp
libextfemio_la_SOURCES += bdf/bdf_types_float.cpp
libextfemio_la_SOURCES += bdf/bdf_types_int.cpp
libextfemio_la_SOURCES += bdf/bdf_types_list_int.cpp
libextfemio_la_SOURCES += bdf/bdf_types_str.cpp
libextfemio_la_SOURCES += bdf/bdf_file.cpp
libextfemio_la_SOURCES += bdf/bdf_l_geom.cpp
libextfemio_la_SOURCES += bdf/bdf_errors.cpp
libextfemio_la_SOURCES += bdf/bdf_cards.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_bar_prop.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_beam_prop.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_cbar.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_cbeam.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_cquad4.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_crod.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_ctria3.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_enddata.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_grid.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_mat1.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_mat2.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_pbar.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_pbarl.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_pbeam.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_pbeaml.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_prod.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_pshell.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_shell.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_momforce_base.cpp
libextfemio_la_SOURCES += bdf/bdf_cards_load.cpp

libextfemio_la_SOURCES += fem/fem_cards.cpp
libextfemio_la_SOURCES += fem/fem_cards_date.cpp
libextfemio_la_SOURCES += fem/fem_cards_gbarm.cpp
libextfemio_la_SOURCES += fem/fem_cards_gbeamg.cpp
libextfemio_la_SOURCES += fem/fem_cards_gcoord.cpp
libextfemio_la_SOURCES += fem/fem_cards_gnode.cpp
libextfemio_la_SOURCES += fem/fem_cards_geccen.cpp
libextfemio_la_SOURCES += fem/fem_cards_gelth.cpp
libextfemio_la_SOURCES += fem/fem_cards_giorh.cpp
libextfemio_la_SOURCES += fem/fem_cards_glsec.cpp
libextfemio_la_SOURCES += fem/fem_cards_gpipe.cpp
libextfemio_la_SOURCES += fem/fem_cards_bldep.cpp
libextfemio_la_SOURCES += fem/fem_cards_bnbcd.cpp
libextfemio_la_SOURCES += fem/fem_cards_bndispl.cpp
libextfemio_la_SOURCES += fem/fem_cards_bnload.cpp
libextfemio_la_SOURCES += fem/fem_cards_mgsprng.cpp
libextfemio_la_SOURCES += fem/fem_cards_gsetmemb.cpp
libextfemio_la_SOURCES += fem/fem_cards_gunivec.cpp
libextfemio_la_SOURCES += fem/fem_cards_misosel.cpp
libextfemio_la_SOURCES += fem/fem_cards_ident.cpp
libextfemio_la_SOURCES += fem/fem_cards_iend.cpp
libextfemio_la_SOURCES += fem/fem_cards_gelmnt1.cpp
libextfemio_la_SOURCES += fem/fem_cards_gelref1.cpp
libextfemio_la_SOURCES += fem/fem_cards_text.cpp
libextfemio_la_SOURCES += fem/fem_cards_tdsetnam.cpp
libextfemio_la_SOURCES += fem/fem_cards_tdsupnam.cpp
libextfemio_la_SOURCES += fem/fem_elements.cpp
libextfemio_la_SOURCES += fem/fem_element_beps.cpp
libextfemio_la_SOURCES += fem/fem_element_csta.cpp
libextfemio_la_SOURCES += fem/fem_element_rpbq.cpp
libextfemio_la_SOURCES += fem/fem_element_ilst.cpp
libextfemio_la_SOURCES += fem/fem_element_iqqe.cpp
libextfemio_la_SOURCES += fem/fem_element_lqua.cpp
libextfemio_la_SOURCES += fem/fem_element_tess.cpp
libextfemio_la_SOURCES += fem/fem_element_gmas.cpp
libextfemio_la_SOURCES += fem/fem_element_glma.cpp
libextfemio_la_SOURCES += fem/fem_element_glda.cpp
libextfemio_la_SOURCES += fem/fem_element_beas.cpp
libextfemio_la_SOURCES += fem/fem_element_axis.cpp
libextfemio_la_SOURCES += fem/fem_element_axda.cpp
libextfemio_la_SOURCES += fem/fem_element_gspr.cpp
libextfemio_la_SOURCES += fem/fem_element_gdam.cpp
libextfemio_la_SOURCES += fem/fem_element_ihex.cpp
libextfemio_la_SOURCES += fem/fem_element_lhex.cpp
libextfemio_la_SOURCES += fem/fem_element_secb.cpp
libextfemio_la_SOURCES += fem/fem_element_btss.cpp
libextfemio_la_SOURCES += fem/fem_element_fqus_ffq.cpp
libextfemio_la_SOURCES += fem/fem_element_ftrs_fftr.cpp
libextfemio_la_SOURCES += fem/fem_element_scts.cpp
libextfemio_la_SOURCES += fem/fem_element_mcts.cpp
libextfemio_la_SOURCES += fem/fem_element_scqs.cpp
libextfemio_la_SOURCES += fem/fem_element_mcqs.cpp
libextfemio_la_SOURCES += fem/fem_element_ipri.cpp
libextfemio_la_SOURCES += fem/fem_element_itet.cpp
libextfemio_la_SOURCES += fem/fem_element_tpri.cpp
libextfemio_la_SOURCES += fem/fem_element_tetr.cpp
libextfemio_la_SOURCES += fem/fem_element_lcts.cpp
libextfemio_la_SOURCES += fem/fem_element_lcqs.cpp
libextfemio_la_SOURCES += fem/fem_element_trs1.cpp
libextfemio_la_SOURCES += fem/fem_element_trs2.cpp
libextfemio_la_SOURCES += fem/fem_element_trs3.cpp
libextfemio_la_SOURCES += fem/fem_element_glsh.cpp
libextfemio_la_SOURCES += fem/fem_element_axcs.cpp
libextfemio_la_SOURCES += fem/fem_element_axlq.cpp
libextfemio_la_SOURCES += fem/fem_element_axls.cpp
libextfemio_la_SOURCES += fem/fem_element_axqq.cpp
libextfemio_la_SOURCES += fem/fem_element_pils.cpp
libextfemio_la_SOURCES += fem/fem_element_pcab.cpp
libextfemio_la_SOURCES += fem/fem_element_pspr.cpp
libextfemio_la_SOURCES += fem/fem_element_adva_4.cpp
libextfemio_la_SOURCES += fem/fem_element_adva_2.cpp
libextfemio_la_SOURCES += fem/fem_element_ctcp.cpp
libextfemio_la_SOURCES += fem/fem_element_ctcl.cpp
libextfemio_la_SOURCES += fem/fem_element_ctal.cpp
libextfemio_la_SOURCES += fem/fem_element_ctcc.cpp
libextfemio_la_SOURCES += fem/fem_element_ctaq.cpp
libextfemio_la_SOURCES += fem/fem_element_ctlq.cpp
libextfemio_la_SOURCES += fem/fem_element_ctcq.cpp
libextfemio_la_SOURCES += fem/fem_element_ctmq.cpp
libextfemio_la_SOURCES += fem/fem_element_hcqs.cpp
libextfemio_la_SOURCES += fem/fem_element_slqs.cpp
libextfemio_la_SOURCES += fem/fem_element_slts.cpp
libextfemio_la_SOURCES += fem/fem_element_slcb.cpp
libextfemio_la_SOURCES += fem/fem_element_matr.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex100.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex101.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex102.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex103.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex104.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex105.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex106.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex107.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex108.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex109.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex110.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex111.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex112.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex113.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex114.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex115.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex116.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex117.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex118.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex119.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex120.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex121.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex122.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex123.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex124.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex125.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex126.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex127.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex128.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex129.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex130.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex131.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex132.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex133.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex134.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex135.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex136.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex137.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex138.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex139.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex140.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex141.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex142.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex143.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex144.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex145.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex146.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex147.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex148.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex149.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex150.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex151.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex152.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex153.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex154.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex155.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex156.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex157.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex158.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex159.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex160.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex161.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex162.cpp
libextfemio_la_SOURCES += fem/fem_element_ghex163.cpp
libextfemio_la_SOURCES += fem/fem_errors.cpp
libextfemio_la_SOURCES += fem/fem_file.cpp
libextfemio_la_SOURCES += fem/fem_type_bounds.cpp
libextfemio_la_SOURCES += fem/fem_types.cpp
libextfemio_la_SOURCES += fem/fem_types_bool.cpp
libextfemio_la_SOURCES += fem/fem_types_float.cpp
libextfemio_la_SOURCES += fem/fem_types_int.cpp
libextfemio_la_SOURCES += fem/fem_types_list_int.cpp
libextfemio_la_SOURCES += fem/fem_types_str.cpp

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
