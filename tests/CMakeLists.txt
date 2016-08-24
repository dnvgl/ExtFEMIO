# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake specifications for testing FEM files access library.

# $ID$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

if(DEFINED ENV{TEAMCITY_VERSION})
  set(CATCH_ARGS --reporter teamcity)
endif()

set (EXTFEM_LIBS -lextfemio_bdf -lextfemio -lboost_regex)
set (EXTFEM_BDF_LIBS -lextfemio_bdf -lextfemio -lboost_regex)
set (EXTFEM_FEM_LIBS -lextfemio_fem -lextfemio -lboost_regex)

link_directories(
  ${PROJECT_BINARY_DIR}/src
  ${PROJECT_BINARY_DIR}/src/bdf
  ${PROJECT_BINARY_DIR}/src/fem
  ${EXTFEMIO_LIBRARY_DIR})

add_executable(test_extfem_string
  test_extfem_string.cpp)
target_link_libraries(test_extfem_string ${EXTFEM_LIBS})
add_test(NAME TEST_EXTFEM_STRING COMMAND test_extfem_string ${CATCH_ARGS})

add_executable(test_bdf_bounds
  test_bdf_bounds.cpp)
target_link_libraries(test_bdf_bounds ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_BOUNDS COMMAND test_bdf_bounds ${CATCH_ARGS})

add_executable(test_bdf_float
  test_bdf_float.cpp)
target_link_libraries(test_bdf_float ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_FLOAT COMMAND test_bdf_float ${CATCH_ARGS})

add_executable(test_bdf_complx
  test_bdf_complx.cpp)
target_link_libraries(test_bdf_complx ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_COMPLX COMMAND test_bdf_complx ${CATCH_ARGS})

add_executable(test_bdf_int
  test_bdf_int.cpp)
target_link_libraries(test_bdf_int ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_INT COMMAND test_bdf_int ${CATCH_ARGS})

add_executable(test_bdf_list
  test_bdf_list.cpp)
target_link_libraries(test_bdf_list ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_LIST COMMAND test_bdf_list ${CATCH_ARGS})

add_executable(test_bdf_str
  test_bdf_str.cpp)
target_link_libraries(test_bdf_str ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_STR COMMAND test_bdf_str ${CATCH_ARGS})

add_executable(test_bdf_types
  test_bdf_types.cpp)
target_link_libraries(test_bdf_types ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_TYPES COMMAND test_bdf_types)

add_executable(test_bdf_cards
  test_bdf_cards.cpp
  test_bdf_cards_cbar.cpp
  test_bdf_cards_cbeam.cpp
  test_bdf_cards_cquad4.cpp
  test_bdf_cards_crod.cpp
  test_bdf_cards_ctria3.cpp
  test_bdf_cards_enddata.cpp
  test_bdf_cards_grid.cpp
  test_bdf_cards_mat1.cpp
  test_bdf_cards_mat2.cpp
  test_bdf_cards_pbar.cpp
  test_bdf_cards_pbarl.cpp
  test_bdf_cards_pbeam.cpp
  test_bdf_cards_pbeaml.cpp
  test_bdf_cards_prod.cpp
  test_bdf_cards_pshell.cpp
  test_bdf_cards_force.cpp
  test_bdf_cards_moment.cpp
  test_bdf_cards_load.cpp
  test_bdf_cards_param.cpp)
target_link_libraries(test_bdf_cards ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_CARDS COMMAND test_bdf_cards ${CATCH_ARGS})

add_executable(test_bdf_header
  test_bdf_header.cpp
  test_bdf_header_echo.cpp
  test_bdf_header_displacement.cpp
  test_bdf_header_spcforces.cpp
  test_bdf_header_stress.cpp)
target_link_libraries(test_bdf_header ${EXTFEM_BDF_LIBS})
add_test(NAME TEST_BDF_HEADER COMMAND test_bdf_header ${CATCH_ARGS})

add_executable(test_fem_float
  test_fem_float.cpp)
target_link_libraries(test_fem_float ${EXTFEM_FEM_LIBS})
add_test(NAME TEST_FEM_FLOAT COMMAND test_fem_float ${CATCH_ARGS})

add_executable(test_fem_int
  test_fem_int.cpp)
target_link_libraries(test_fem_int ${EXTFEM_FEM_LIBS})
add_test(NAME TEST_FEM_INT COMMAND test_fem_int ${CATCH_ARGS})

add_executable(test_fem_bool
  test_fem_bool.cpp)
target_link_libraries(test_fem_bool ${EXTFEM_FEM_LIBS})
add_test(NAME TEST_FEM_BOOL COMMAND test_fem_bool ${CATCH_ARGS})

add_executable(test_fem_list
  test_fem_list.cpp)
target_link_libraries(test_fem_list ${EXTFEM_FEM_LIBS})
add_test(NAME TEST_FEM_LIST COMMAND test_fem_list ${CATCH_ARGS})

add_executable(test_fem_cards
  test_fem_cards.cpp
  test_fem_cards_belfix.cpp
  test_fem_cards_beuslo.cpp
  test_fem_cards_bldep.cpp
  test_fem_cards_bnbcd.cpp
  test_fem_cards_bndispl.cpp
  test_fem_cards_bnload.cpp
  test_fem_cards_bsell.cpp
  test_fem_cards_date.cpp
  test_fem_cards_gbarm.cpp
  test_fem_cards_gbeamg.cpp
  test_fem_cards_gcoord.cpp
  test_fem_cards_geccen.cpp
  test_fem_cards_gelmnt1.cpp
  test_fem_cards_gelmnt2.cpp
  test_fem_cards_gelref1.cpp
  test_fem_cards_gelth.cpp
  test_fem_cards_giorh.cpp
  test_fem_cards_glsec.cpp
  test_fem_cards_gnode.cpp
  test_fem_cards_gpipe.cpp
  test_fem_cards_gsetmemb.cpp
  test_fem_cards_gunivec.cpp
  test_fem_cards_gusyi.cpp
  test_fem_cards_hierarch.cpp
  test_fem_cards_hsupstat.cpp
  test_fem_cards_hsuptran.cpp
  test_fem_cards_ident.cpp
  test_fem_cards_iend.cpp
  test_fem_cards_mgsprng.cpp
  test_fem_cards_misosel.cpp
  test_fem_cards_morsmel.cpp
  test_fem_cards_tdload.cpp
  test_fem_cards_tdsetnam.cpp
  test_fem_cards_tdsupnam.cpp
  test_fem_cards_text.cpp)
target_link_libraries(test_fem_cards ${EXTFEM_FEM_LIBS})
add_test(NAME TEST_FEM_CARDS COMMAND test_fem_cards ${CATCH_ARGS})

add_executable(test_fem_elements
  test_fem_elements.cpp
  test_fem_element_adva_2.cpp
  test_fem_element_adva_4.cpp
  test_fem_element_axcs.cpp
  test_fem_element_axda.cpp
  test_fem_element_axis.cpp
  test_fem_element_axlq.cpp
  test_fem_element_axls.cpp
  test_fem_element_axqq.cpp
  test_fem_element_beas.cpp
  test_fem_element_beps.cpp
  test_fem_element_btss.cpp
  test_fem_element_csta.cpp
  test_fem_element_ctal.cpp
  test_fem_element_ctaq.cpp
  test_fem_element_ctcc.cpp
  test_fem_element_ctcl.cpp
  test_fem_element_ctcp.cpp
  test_fem_element_ctcq.cpp
  test_fem_element_ctlq.cpp
  test_fem_element_ctmq.cpp
  test_fem_element_fqus_ffq.cpp
  test_fem_element_ftrs_fftr.cpp
  test_fem_element_gdam.cpp
  test_fem_element_ghex.cpp
  test_fem_element_glda.cpp
  test_fem_element_glma.cpp
  test_fem_element_glsh.cpp
  test_fem_element_gmas.cpp
  test_fem_element_gspr.cpp
  test_fem_element_hcqs.cpp
  test_fem_element_ihex.cpp
  test_fem_element_ilst.cpp
  test_fem_element_ipri.cpp
  test_fem_element_iqqe.cpp
  test_fem_element_itet.cpp
  test_fem_element_lcqs.cpp
  test_fem_element_lcts.cpp
  test_fem_element_lhex.cpp
  test_fem_element_lqua.cpp
  test_fem_element_matr.cpp
  test_fem_element_mcqs.cpp
  test_fem_element_mcts.cpp
  test_fem_element_pcab.cpp
  test_fem_element_pils.cpp
  test_fem_element_pspr.cpp
  test_fem_element_rpbq.cpp
  test_fem_element_scqs.cpp
  test_fem_element_scts.cpp
  test_fem_element_secb.cpp
  test_fem_element_slcb.cpp
  test_fem_element_slqs.cpp
  test_fem_element_slts.cpp
  test_fem_element_tess.cpp
  test_fem_element_tetr.cpp
  test_fem_element_tpri.cpp
  test_fem_element_trs1.cpp
  test_fem_element_trs2.cpp
  test_fem_element_trs3.cpp)
target_link_libraries(test_fem_elements ${EXTFEM_FEM_LIBS})
add_test(NAME TEST_FEM_ELEMENTS COMMAND test_fem_elements ${CATCH_ARGS})

# test_fem_element_ghex.cpp : ../tools/ghex_do.py	\
#   ../tools/templates/elements_ghex.h		\
#   ../tools/templates/element_ghex.cpp		\
#   ../tools/templates/test_fem_element_ghex.cpp
# 	(set -e ; cd .. ; python3 tools/ghex_do.py)

