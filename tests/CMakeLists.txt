# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake specifications for testing FEM files access library.

# $ID$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

set (EXTFEM_LIBS -lextfemio_bdf -lextfemio -lboost_regex)
set (EXTFEM_BDF_LIBS -lextfemio_bdf -lextfemio -lboost_regex)
set (EXTFEM_FEM_LIBS -lextfemio_fem -lextfemio -lboost_regex)

link_directories(
  ${PROJECT_BINARY_DIR}/src
  ${PROJECT_BINARY_DIR}/src/bdf
  ${PROJECT_BINARY_DIR}/src/fem
  ${EXTFEMIO_LIBRARY_DIR})

add_executable(test_extfem_string
  test_extfem_string)
target_link_libraries(test_extfem_string ${EXTFEM_LIBS})
# add_test(NAME TEST_EXTFEM_STRING COMMAND test_extfem_string)

add_executable(test_bdf_bounds
  test_bdf_bounds)
target_link_libraries(test_bdf_bounds ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_BOUNDS COMMAND test_bdf_bounds)

add_executable(test_bdf_float
  test_bdf_float)
target_link_libraries(test_bdf_float ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_FLOAT COMMAND test_bdf_float)

add_executable(test_bdf_complx
  test_bdf_complx)
target_link_libraries(test_bdf_complx ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_COMPLX COMMAND test_bdf_complx)

add_executable(test_bdf_int
  test_bdf_int)
target_link_libraries(test_bdf_int ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_INT COMMAND test_bdf_int)

add_executable(test_bdf_list
  test_bdf_list)
target_link_libraries(test_bdf_list ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_LIST COMMAND test_bdf_list)

add_executable(test_bdf_str
  test_bdf_str)
target_link_libraries(test_bdf_str ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_STR COMMAND test_bdf_str)

add_executable(test_bdf_types
  test_bdf_types)
target_link_libraries(test_bdf_types ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_TYPES COMMAND test_bdf_types)

add_executable(test_bdf_cards
  test_bdf_cards
  test_bdf_cards_cbar
  test_bdf_cards_cbeam
  test_bdf_cards_cquad4
  test_bdf_cards_crod
  test_bdf_cards_ctria3
  test_bdf_cards_enddata
  test_bdf_cards_grid
  test_bdf_cards_mat1
  test_bdf_cards_mat2
  test_bdf_cards_pbar
  test_bdf_cards_pbarl
  test_bdf_cards_pbeam
  test_bdf_cards_pbeaml
  test_bdf_cards_prod
  test_bdf_cards_pshell
  test_bdf_cards_force
  test_bdf_cards_moment
  test_bdf_cards_load
  test_bdf_cards_param)
target_link_libraries(test_bdf_cards ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_CARDS COMMAND test_bdf_cards)

add_executable(test_bdf_header
  test_bdf_header
  test_bdf_header_echo
  test_bdf_header_displacement
  test_bdf_header_spcforces
  test_bdf_header_stress)
target_link_libraries(test_bdf_header ${EXTFEM_BDF_LIBS})
# add_test(NAME TEST_BDF_HEADER COMMAND test_bdf_header)

add_executable(test_fem_float
  test_fem_float)
target_link_libraries(test_fem_float ${EXTFEM_FEM_LIBS})
# add_test(NAME TEST_FEM_FLOAT COMMAND test_fem_float)

add_executable(test_fem_int
  test_fem_int)
target_link_libraries(test_fem_int ${EXTFEM_FEM_LIBS})
# add_test(NAME TEST_FEM_INT COMMAND test_fem_int)

add_executable(test_fem_bool
  test_fem_bool)
target_link_libraries(test_fem_bool ${EXTFEM_FEM_LIBS})
# add_test(NAME TEST_FEM_BOOL COMMAND test_fem_bool)

add_executable(test_fem_list
  test_fem_list)
target_link_libraries(test_fem_list ${EXTFEM_FEM_LIBS})
# add_test(NAME TEST_FEM_LIST COMMAND test_fem_list)

add_executable(test_fem_cards
  test_fem_cards
  test_fem_cards_belfix
  test_fem_cards_beuslo
  test_fem_cards_bldep
  test_fem_cards_bnbcd
  test_fem_cards_bndispl
  test_fem_cards_bnload
  test_fem_cards_bsell
  test_fem_cards_date
  test_fem_cards_gbarm
  test_fem_cards_gbeamg
  test_fem_cards_gcoord
  test_fem_cards_geccen
  test_fem_cards_gelmnt1
  test_fem_cards_gelmnt2
  test_fem_cards_gelref1
  test_fem_cards_gelth
  test_fem_cards_giorh
  test_fem_cards_glsec
  test_fem_cards_gnode
  test_fem_cards_gpipe
  test_fem_cards_gsetmemb
  test_fem_cards_gunivec
  test_fem_cards_gusyi
  test_fem_cards_hierarch
  test_fem_cards_hsupstat
  test_fem_cards_hsuptran
  test_fem_cards_ident
  test_fem_cards_iend
  test_fem_cards_mgsprng
  test_fem_cards_misosel
  test_fem_cards_morsmel
  test_fem_cards_tdload
  test_fem_cards_tdsetnam
  test_fem_cards_tdsupnam
  test_fem_cards_text)
target_link_libraries(test_fem_cards ${EXTFEM_FEM_LIBS})
# add_test(NAME TEST_FEM_CARDS COMMAND test_fem_cards)

add_executable(test_fem_elements
  test_fem_elements
  test_fem_element_adva_2
  test_fem_element_adva_4
  test_fem_element_axcs
  test_fem_element_axda
  test_fem_element_axis
  test_fem_element_axlq
  test_fem_element_axls
  test_fem_element_axqq
  test_fem_element_beas
  test_fem_element_beps
  test_fem_element_btss
  test_fem_element_csta
  test_fem_element_ctal
  test_fem_element_ctaq
  test_fem_element_ctcc
  test_fem_element_ctcl
  test_fem_element_ctcp
  test_fem_element_ctcq
  test_fem_element_ctlq
  test_fem_element_ctmq
  test_fem_element_fqus_ffq
  test_fem_element_ftrs_fftr
  test_fem_element_gdam
  test_fem_element_ghex
  test_fem_element_glda
  test_fem_element_glma
  test_fem_element_glsh
  test_fem_element_gmas
  test_fem_element_gspr
  test_fem_element_hcqs
  test_fem_element_ihex
  test_fem_element_ilst
  test_fem_element_ipri
  test_fem_element_iqqe
  test_fem_element_itet
  test_fem_element_lcqs
  test_fem_element_lcts
  test_fem_element_lhex
  test_fem_element_lqua
  test_fem_element_matr
  test_fem_element_mcqs
  test_fem_element_mcts
  test_fem_element_pcab
  test_fem_element_pils
  test_fem_element_pspr
  test_fem_element_rpbq
  test_fem_element_scqs
  test_fem_element_scts
  test_fem_element_secb
  test_fem_element_slcb
  test_fem_element_slqs
  test_fem_element_slts
  test_fem_element_tess
  test_fem_element_tetr
  test_fem_element_tpri
  test_fem_element_trs1
  test_fem_element_trs2
  test_fem_element_trs3
  )
target_link_libraries(test_fem_elements ${EXTFEM_FEM_LIBS})
# add_test(NAME TEST_FEM_ELEMENTS COMMAND test_fem_elements)
ms_add_catch_tests(test_fem_elements)
ms_add_catch_tests(test_fem_cards)


# test_fem_element_ghex.cpp : ../tools/ghex_do.py	\
#   ../tools/templates/elements_ghex.h		\
#   ../tools/templates/element_ghex.cpp		\
#   ../tools/templates/test_fem_element_ghex.cpp
# 	(set -e ; cd .. ; python3 tools/ghex_do.py)

