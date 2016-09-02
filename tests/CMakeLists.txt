# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake specifications for testing FEM files access library.

# $ID$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

FUNCTION(my_add_test inp)
  string(TOUPPER ${inp} NAME)
  string(TOLOWER ${inp} COMMAND)
  add_test(NAME ${NAME} COMMAND ${COMMAND} --reporter junit --out ${COMMAND}_junit.xml)
ENDFUNCTION()

if(DEFINED ENV{TEAMCITY_VERSION})
  set(CATCH_ARGS --reporter junit --out $@_junit.xml)
endif()

set(CATCH_ARGS --reporter junit --out $<TARGET_FILE:test>_junit.xml)

if(HAVE_BOOST_REGEX_HPP)
  set (BOOST_LIBS boost_regex)
endif()
set (EXTFEM_LIBS extfemio_bdf extfemio ${BOOST_LIBS})
set (EXTFEM_BDF_LIBS extfemio_bdf extfemio ${BOOST_LIBS})
set (EXTFEM_FEM_LIBS extfemio_fem extfemio ${BOOST_LIBS})

link_directories(
  ${PROJECT_BINARY_DIR}/src
  ${PROJECT_BINARY_DIR}/src/bdf
  ${PROJECT_BINARY_DIR}/src/fem
  ${EXTFEMIO_LIBRARY_DIR})

add_executable(test_extfem_string
  test_extfem_string.cpp)
target_link_libraries(test_extfem_string ${EXTFEM_LIBS})
my_add_test(test_extfem_string)

add_executable(test_bdf_bounds
  test_bdf_bounds.cpp)
target_link_libraries(test_bdf_bounds ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_bounds)

add_executable(test_bdf_float
  test_bdf_float.cpp)
target_link_libraries(test_bdf_float ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_float)

add_executable(test_bdf_complx
  test_bdf_complx.cpp)
target_link_libraries(test_bdf_complx ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_complx)

add_executable(test_bdf_int
  test_bdf_int.cpp)
target_link_libraries(test_bdf_int ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_int)

add_executable(test_bdf_list
  test_bdf_list.cpp)
target_link_libraries(test_bdf_list ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_list)

add_executable(test_bdf_str
  test_bdf_str.cpp)
target_link_libraries(test_bdf_str ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_str)

add_executable(test_bdf_types
  test_bdf_types.cpp)
target_link_libraries(test_bdf_types ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_types)

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
my_add_test(test_bdf_cards)

add_executable(test_bdf_header
  test_bdf_header.cpp
  test_bdf_header_echo.cpp
  test_bdf_header_displacement.cpp
  test_bdf_header_spcforces.cpp
  test_bdf_header_stress.cpp)
target_link_libraries(test_bdf_header ${EXTFEM_BDF_LIBS})
my_add_test(test_bdf_header)

add_executable(test_fem_float
  test_fem_float.cpp)
target_link_libraries(test_fem_float ${EXTFEM_FEM_LIBS})
my_add_test(test_fem_float)

add_executable(test_fem_int
  test_fem_int.cpp)
target_link_libraries(test_fem_int ${EXTFEM_FEM_LIBS})
my_add_test(test_fem_int)

add_executable(test_fem_bool
  test_fem_bool.cpp)
target_link_libraries(test_fem_bool ${EXTFEM_FEM_LIBS})
my_add_test(test_fem_bool)

add_executable(test_fem_list
  test_fem_list.cpp)
target_link_libraries(test_fem_list ${EXTFEM_FEM_LIBS})
my_add_test(test_fem_list)

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
my_add_test(test_fem_cards)

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
  test_fem_element_ghex100.cpp
  test_fem_element_ghex101.cpp
  test_fem_element_ghex102.cpp
  test_fem_element_ghex103.cpp
  test_fem_element_ghex104.cpp
  test_fem_element_ghex105.cpp
  test_fem_element_ghex106.cpp
  test_fem_element_ghex107.cpp
  test_fem_element_ghex108.cpp
  test_fem_element_ghex109.cpp
  test_fem_element_ghex110.cpp
  test_fem_element_ghex111.cpp
  test_fem_element_ghex112.cpp
  test_fem_element_ghex113.cpp
  test_fem_element_ghex114.cpp
  test_fem_element_ghex115.cpp
  test_fem_element_ghex116.cpp
  test_fem_element_ghex117.cpp
  test_fem_element_ghex118.cpp
  test_fem_element_ghex119.cpp
  test_fem_element_ghex120.cpp
  test_fem_element_ghex121.cpp
  test_fem_element_ghex122.cpp
  test_fem_element_ghex123.cpp
  test_fem_element_ghex124.cpp
  test_fem_element_ghex125.cpp
  test_fem_element_ghex126.cpp
  test_fem_element_ghex127.cpp
  test_fem_element_ghex128.cpp
  test_fem_element_ghex129.cpp
  test_fem_element_ghex130.cpp
  test_fem_element_ghex131.cpp
  test_fem_element_ghex132.cpp
  test_fem_element_ghex133.cpp
  test_fem_element_ghex134.cpp
  test_fem_element_ghex135.cpp
  test_fem_element_ghex136.cpp
  test_fem_element_ghex137.cpp
  test_fem_element_ghex138.cpp
  test_fem_element_ghex139.cpp
  test_fem_element_ghex140.cpp
  test_fem_element_ghex141.cpp
  test_fem_element_ghex142.cpp
  test_fem_element_ghex143.cpp
  test_fem_element_ghex144.cpp
  test_fem_element_ghex145.cpp
  test_fem_element_ghex146.cpp
  test_fem_element_ghex147.cpp
  test_fem_element_ghex148.cpp
  test_fem_element_ghex149.cpp
  test_fem_element_ghex150.cpp
  test_fem_element_ghex151.cpp
  test_fem_element_ghex152.cpp
  test_fem_element_ghex153.cpp
  test_fem_element_ghex154.cpp
  test_fem_element_ghex155.cpp
  test_fem_element_ghex156.cpp
  test_fem_element_ghex157.cpp
  test_fem_element_ghex158.cpp
  test_fem_element_ghex159.cpp
  test_fem_element_ghex160.cpp
  test_fem_element_ghex161.cpp
  test_fem_element_ghex162.cpp
  test_fem_element_ghex163.cpp
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
my_add_test(test_fem_elements)

if(CMAKE_COMPILER_IS_GNUCXX)
  # add the commands to generate the source code
  add_custom_command (
    OUTPUT
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_adva_2.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_adva_4.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_axcs.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_axda.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_axis.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_axlq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_axls.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_axqq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_beas.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_beps.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_btss.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_csta.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctal.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctaq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctcc.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctcl.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctcp.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctcq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctlq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ctmq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_fqus_ffq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ftrs_fftr.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex100.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex101.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex102.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex103.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex104.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex105.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex106.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex107.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex108.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex109.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex110.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex111.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex112.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex113.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex114.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex115.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex116.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex117.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex118.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex119.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex120.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex121.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex122.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex123.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex124.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex125.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex126.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex127.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex128.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex129.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex130.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex131.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex132.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex133.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex134.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex135.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex136.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex137.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex138.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex139.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex140.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex141.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex142.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex143.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex144.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex145.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex146.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex147.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex148.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex149.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex150.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex151.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex152.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex153.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex154.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex155.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex156.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex157.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex158.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex159.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex160.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex161.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex162.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ghex163.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_gdam.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_glda.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_glma.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_glsh.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_gmas.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_gspr.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_hcqs.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ihex.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ilst.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_ipri.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_iqqe.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_itet.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_lcqs.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_lcts.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_lhex.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_lqua.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_matr.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_mcqs.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_mcts.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_pcab.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_pils.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_pspr.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_rpbq.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_scqs.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_scts.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_secb.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_slcb.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_slqs.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_slts.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_tess.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_tetr.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_tpri.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_trs1.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_trs2.cpp
      ${CMAKE_SOURCE_DIR}/tests/test_fem_element_trs3.cpp
    COMMAND
      cd ${CMAKE_SOURCE_DIR} && python3 tools/elements_test_do.py ||
      svn revert ${CMAKE_SOURCE_DIR}/include/fem/test_fem_element_*.cpp.cpp
    DEPENDS
      ${CMAKE_SOURCE_DIR}/tools/elements_test_do.py
      ${CMAKE_SOURCE_DIR}/tools/elements_data.py
      ${CMAKE_SOURCE_DIR}/tools/templates/test_fem_element.cpp)
endif()

# test_fem_element_ghex.cpp : ../tools/ghex_do.py	\
#   ../tools/templates/elements_ghex.h		\
#   ../tools/templates/element_ghex.cpp		\
#   ../tools/templates/test_fem_element_ghex.cpp
#       (set -e ; cd .. ; python3 tools/ghex_do.py)
