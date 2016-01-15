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
