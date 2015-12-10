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

libextfemread_la_SOURCES += bdf/bdf_types.cpp
libextfemread_la_SOURCES += bdf/bdf_types_float.cpp
libextfemread_la_SOURCES += bdf/bdf_types_int.cpp
libextfemread_la_SOURCES += bdf/bdf_types_list_int.cpp
libextfemread_la_SOURCES += bdf/bdf_types_str.cpp
libextfemread_la_SOURCES += bdf/bdf_file.cpp
libextfemread_la_SOURCES += bdf/bdf_l_geom.cpp
libextfemread_la_SOURCES += bdf/bdf_errors.cpp
libextfemread_la_SOURCES += bdf/bdf_cards.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_bar_prop.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_beam_prop.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_cbar.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_cbeam.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_cquad4.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_crod.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_ctria3.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_enddata.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_grid.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_mat1.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbar.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbarl.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbeam.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pbeaml.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_prod.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_pshell.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_shell.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_momforce_base.cpp
libextfemread_la_SOURCES += bdf/bdf_cards_load.cpp

libextfemread_la_SOURCES += fem/fem_cards.cpp
libextfemread_la_SOURCES += fem/fem_cards_date.cpp
libextfemread_la_SOURCES += fem/fem_cards_gbarm.cpp
libextfemread_la_SOURCES += fem/fem_cards_gbeamg.cpp
libextfemread_la_SOURCES += fem/fem_cards_gcoord.cpp
libextfemread_la_SOURCES += fem/fem_cards_gnode.cpp
libextfemread_la_SOURCES += fem/fem_cards_geccen.cpp
libextfemread_la_SOURCES += fem/fem_cards_gelth.cpp
libextfemread_la_SOURCES += fem/fem_cards_giorh.cpp
libextfemread_la_SOURCES += fem/fem_cards_glsec.cpp
libextfemread_la_SOURCES += fem/fem_cards_gpipe.cpp
libextfemread_la_SOURCES += fem/fem_cards_bldep.cpp
libextfemread_la_SOURCES += fem/fem_cards_bnbcd.cpp
libextfemread_la_SOURCES += fem/fem_cards_bndispl.cpp
libextfemread_la_SOURCES += fem/fem_cards_bnload.cpp
libextfemread_la_SOURCES += fem/fem_cards_mgsprng.cpp
libextfemread_la_SOURCES += fem/fem_cards_gsetmemb.cpp
libextfemread_la_SOURCES += fem/fem_cards_gunivec.cpp
libextfemread_la_SOURCES += fem/fem_cards_misosel.cpp
libextfemread_la_SOURCES += fem/fem_cards_ident.cpp
libextfemread_la_SOURCES += fem/fem_cards_iend.cpp
libextfemread_la_SOURCES += fem/fem_cards_gelmnt1.cpp
libextfemread_la_SOURCES += fem/fem_cards_gelref1.cpp
libextfemread_la_SOURCES += fem/fem_cards_text.cpp
libextfemread_la_SOURCES += fem/fem_elements.cpp
libextfemread_la_SOURCES += fem/fem_errors.cpp
libextfemread_la_SOURCES += fem/fem_file.cpp
libextfemread_la_SOURCES += fem/fem_type_bounds.cpp
libextfemread_la_SOURCES += fem/fem_types.cpp
libextfemread_la_SOURCES += fem/fem_types_bool.cpp
libextfemread_la_SOURCES += fem/fem_types_float.cpp
libextfemread_la_SOURCES += fem/fem_types_int.cpp
libextfemread_la_SOURCES += fem/fem_types_list_int.cpp
libextfemread_la_SOURCES += fem/fem_types_str.cpp

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make -C .. check -j 8"
# End:

# End of Makefile.am
