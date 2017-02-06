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
  if (COMMAND cotire)
    cotire(${inp})
    set_target_properties(${inp}
      PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdafx.h")
  endif()
  add_test(NAME ${NAME}
    COMMAND ${COMMAND} --break --reporter junit --out ${COMMAND}_junit.xml)
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
set (EXTFEM_SUPPORT_LIBS extfemio_support extfemio ${BOOST_LIBS})

link_directories(
  ${PROJECT_BINARY_DIR}/src
  ${PROJECT_BINARY_DIR}/src/bdf
  ${PROJECT_BINARY_DIR}/src/fem
  ${EXTFEMIO_LIBRARY_DIR})

add_executable(test_extfem_string
  test_extfem_string.cpp
  test_extfem_misc.cpp)
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
#  test_bdf_cards_celas1.cpp
  test_bdf_cards_ctria3.cpp
  test_bdf_cards_enddata.cpp
  test_bdf_cards_cmass2.cpp
  test_bdf_cards_cmass4.cpp
  test_bdf_cards_grav.cpp
  test_bdf_cards_grid.cpp
  test_bdf_cards_mat1.cpp
  test_bdf_cards_mat2.cpp
  test_bdf_cards_pbar.cpp
  test_bdf_cards_pbarl.cpp
  test_bdf_cards_pbeam.cpp
  test_bdf_cards_pbeaml.cpp
#  test_bdf_cards_pelas.cpp
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
  test_fem_cards_gbox.cpp
  test_fem_cards_gchan.cpp
  test_fem_cards_gchanr.cpp
  test_fem_cards_gcoord.cpp
  test_fem_cards_gdobo.cpp
  test_fem_cards_geccen.cpp
  test_fem_cards_gelmnt1.cpp
  test_fem_cards_gelmnt2.cpp
  test_fem_cards_gelref1.cpp
  test_fem_cards_gelth.cpp
  test_fem_cards_giorh.cpp
  test_fem_cards_giorhr.cpp
  test_fem_cards_glsec.cpp
  test_fem_cards_glsecr.cpp
  test_fem_cards_gnode.cpp
  test_fem_cards_gpipe.cpp
  test_fem_cards_gsetmemb.cpp
  test_fem_cards_gtonp.cpp
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
  test_fem_more_elements.cpp)
target_link_libraries(test_fem_elements ${EXTFEM_FEM_LIBS})
my_add_test(test_fem_elements)

add_executable(test_support_grouping
  test_support_grouping.cpp
  test_support_grouping_csv.cpp
  test_support_grouping_ses.cpp)
target_link_libraries(test_support_grouping ${EXTFEM_SUPPORT_LIBS})
my_add_test(test_support_grouping)

if(CMAKE_COMPILER_IS_GNUCXX)
  # add the commands to generate the source code
  add_custom_command (
    OUTPUT
      ${CMAKE_SOURCE_DIR}/tests/test_fem_elements.cpp
    COMMAND
      cd ${CMAKE_SOURCE_DIR} && python3 tools/elements_test_do.py ||
      svn revert ${CMAKE_SOURCE_DIR}/include/fem/test_fem_elements.cpp
    DEPENDS
      ${CMAKE_SOURCE_DIR}/tools/elements_test_do.py
      ${CMAKE_SOURCE_DIR}/tools/elements_data.py
      ${CMAKE_SOURCE_DIR}/tools/templates/test_fem_elements.cpp)
endif()

# Local Variables:
# mode: cmake
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# coding: utf-8
# End:
