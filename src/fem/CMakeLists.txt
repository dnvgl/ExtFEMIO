# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake configuration for libextfemio_fem.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

set(LIBEXTFEMIO_FEM_SOURCES
  fem_cards.cpp
  fem_cards_belfix.cpp
  fem_cards_beuslo.cpp
  fem_cards_bldep.cpp
  fem_cards_bnbcd.cpp
  fem_cards_bndispl.cpp
  fem_cards_bnload.cpp
  fem_cards_bsell.cpp
  fem_cards_date.cpp
  fem_cards_gbarm.cpp
  fem_cards_gbeamg.cpp
  fem_cards_gcoord.cpp
  fem_cards_geccen.cpp
  fem_cards_gelmnt1.cpp
  fem_cards_gelmnt2.cpp
  fem_cards_gelref1.cpp
  fem_cards_gelth.cpp
  fem_cards_giorh.cpp
  fem_cards_glsec.cpp
  fem_cards_gnode.cpp
  fem_cards_gpipe.cpp
  fem_cards_gsetmemb.cpp
  fem_cards_gunivec.cpp
  fem_cards_gusyi.cpp
  fem_cards_hierarch.cpp
  fem_cards_hsupstat.cpp
  fem_cards_hsuptran.cpp
  fem_cards_ident.cpp
  fem_cards_iend.cpp
  fem_cards_mgsprng.cpp
  fem_cards_misosel.cpp
  fem_cards_morsmel.cpp
  fem_cards_tdload.cpp
  fem_cards_tdsetnam.cpp
  fem_cards_tdsupnam.cpp
  fem_cards_text.cpp
  fem_element_adva_2.cpp
  fem_element_adva_4.cpp
  fem_element_axcs.cpp
  fem_element_axda.cpp
  fem_element_axis.cpp
  fem_element_axlq.cpp
  fem_element_axls.cpp
  fem_element_axqq.cpp
  fem_element_beas.cpp
  fem_element_beps.cpp
  fem_element_btss.cpp
  fem_element_csta.cpp
  fem_element_ctal.cpp
  fem_element_ctaq.cpp
  fem_element_ctcc.cpp
  fem_element_ctcl.cpp
  fem_element_ctcp.cpp
  fem_element_ctcq.cpp
  fem_element_ctlq.cpp
  fem_element_ctmq.cpp
  fem_element_fqus_ffq.cpp
  fem_element_ftrs_fftr.cpp
  fem_element_gdam.cpp
  fem_element_ghex.cpp
  fem_element_glda.cpp
  fem_element_glma.cpp
  fem_element_glsh.cpp
  fem_element_gmas.cpp
  fem_element_gspr.cpp
  fem_element_hcqs.cpp
  fem_element_ihex.cpp
  fem_element_ilst.cpp
  fem_element_ipri.cpp
  fem_element_iqqe.cpp
  fem_element_itet.cpp
  fem_element_lcqs.cpp
  fem_element_lcts.cpp
  fem_element_lhex.cpp
  fem_element_lqua.cpp
  fem_element_matr.cpp
  fem_element_mcqs.cpp
  fem_element_mcts.cpp
  fem_element_pcab.cpp
  fem_element_pils.cpp
  fem_element_pspr.cpp
  fem_element_rpbq.cpp
  fem_element_scqs.cpp
  fem_element_scts.cpp
  fem_element_secb.cpp
  fem_element_slcb.cpp
  fem_element_slqs.cpp
  fem_element_slts.cpp
  fem_element_tess.cpp
  fem_element_tetr.cpp
  fem_element_thin_shell.cpp
  fem_element_tpri.cpp
  fem_element_trs1.cpp
  fem_element_trs2.cpp
  fem_element_trs3.cpp
  fem_elements.cpp
  fem_errors.cpp
  fem_file.cpp
  fem_type_bounds.cpp
  fem_types.cpp
  fem_types_bool.cpp
  fem_types_float.cpp
  fem_types_int.cpp
  fem_types_list_int.cpp
  fem_types_str.cpp)
set(LIBEXTFEMIO_FEM_HEADERS
  ../../include/extfem_misc.h
  ../../include/extfem_string.h
  ../../include/fem2fem_args.h
  ../../include/my_c++14.h
  ../../include/resource.h
  ../../include/StdAfx.h
  ../../include/fem/cards.h
  ../../include/fem/cards_loads.h
  ../../include/fem/cards_properties.h
  ../../include/fem/cards_superele.h
  ../../include/fem/elements_ghex.h
  ../../include/fem/elements.h
  ../../include/fem/errors.h
  ../../include/fem/file.h
  ../../include/fem/type_bounds.h
  ../../include/fem/types.h)
add_library (extfemio_fem STATIC
  ${LIBEXTFEMIO_FEM_SOURCES}
  ${LIBEXTFEMIO_FEM_HEADERS})

target_include_directories (extfemio_fem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add the command to generate the source code
add_custom_command (
  OUTPUT
    ${CMAKE_SOURCE_DIR}/include/fem/elements_ghex.h
    ${CMAKE_SOURCE_DIR}/src/fem/fem_element_ghex.cpp
  COMMAND
    cd ${CMAKE_SOURCE_DIR} && python3 tools/ghex_do.py ||
    svn revert ${CMAKE_SOURCE_DIR}/src/fem/fem_element_ghex.cpp ${CMAKE_SOURCE_DIR}/include/fem/elements_ghex.h
  DEPENDS
    ${CMAKE_SOURCE_DIR}/tools/ghex_do.py
    ${CMAKE_SOURCE_DIR}/tools/templates/element_ghex.h
    ${CMAKE_SOURCE_DIR}/tools/templates/element_ghex.cpp
    ${CMAKE_SOURCE_DIR}/tools/templates/test_fem_element_ghex.cpp)
