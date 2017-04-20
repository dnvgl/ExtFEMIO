# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake configuration for libextfemio_bdf.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

set(LIBEXTFEMIO_BDF_SOURCES
  bdf_type_bounds.cpp
  bdf_types.cpp
  bdf_types_float.cpp
  bdf_types_int.cpp
  bdf_types_list_int.cpp
  bdf_file.cpp
  bdf_l_geom.cpp
  bdf_errors.cpp
  bdf_cards.cpp
  bdf_cards_element.cpp
  bdf_cards_bar_prop.cpp
  bdf_cards_beam_prop.cpp
  bdf_cards_cbar.cpp
  bdf_cards_cbeam.cpp
  bdf_cards_cquad4.cpp
  bdf_cards_crod.cpp
  bdf_cards_ctria3.cpp
#  bdf_cards_celas1.cpp
  bdf_cards_enddata.cpp
  bdf_cards_grid.cpp
  bdf_cards_cmass2.cpp
  bdf_cards_cmass4.cpp
  bdf_cards_grav.cpp
  bdf_cards_mat.cpp
  bdf_cards_mat1.cpp
  bdf_cards_mat2.cpp
  bdf_cards_properties.cpp
  bdf_cards_pbar.cpp
  bdf_cards_pbarl.cpp
  bdf_cards_pbeam.cpp
  bdf_cards_pbeaml.cpp
  bdf_cards_prod.cpp
  bdf_cards_pshell.cpp
#  bdf_cards_pelas.cpp
  bdf_cards_shell.cpp
  bdf_cards_momforce_base.cpp
  bdf_cards_load.cpp
  bdf_cards_param.cpp
  bdf_header.cpp
  bdf_header_case_control_begin_bulk.cpp
  bdf_header_case_control_echo.cpp
  bdf_header_case_control_displacement.cpp
  bdf_header_case_control_load.cpp
  bdf_header_case_control_spcforces.cpp
  bdf_header_case_control_subcase.cpp
  bdf_header_case_control_subtitle.cpp
  bdf_header_case_control_stress.cpp
  bdf_header_case_control_title.cpp
  bdf_header_exec_control_cend.cpp
  bdf_header_exec_control_sol.cpp)
set(LIBEXTFEMIO_BDF_HEADERS
  ${CMAKE_SOURCE_DIR}/include/extfem_misc.h
  ${CMAKE_SOURCE_DIR}/include/extfem_string.h
  ${CMAKE_SOURCE_DIR}/include/my_c++14.h
  ${CMAKE_SOURCE_DIR}/include/resource.h
  ${CMAKE_SOURCE_DIR}/include/bdf/cards_elements.h
  ${CMAKE_SOURCE_DIR}/include/bdf/cards.h
  ${CMAKE_SOURCE_DIR}/include/bdf/cards_loads.h
  ${CMAKE_SOURCE_DIR}/include/bdf/cards_properties.h
  ${CMAKE_SOURCE_DIR}/include/bdf/errors.h
  ${CMAKE_SOURCE_DIR}/include/bdf/file.h
  ${CMAKE_SOURCE_DIR}/include/bdf/header.h
  ${CMAKE_SOURCE_DIR}/include/bdf/type_bounds.h
  ${CMAKE_SOURCE_DIR}/include/bdf/types.h)
add_library (extfemio_bdf STATIC
  ${LIBEXTFEMIO_BDF_SOURCES}
  ${LIBEXTFEMIO_BDF_HEADERS})
if (COMMAND cotire)
  cotire(extfemio_bdf)
  set_target_properties(extfemio_bdf
    PROPERTIES
    COTIRE_CXX_PREFIX_HEADER_INIT "${CMAKE_SOURCE_DIR}/src/StdAfx.h")
endif()

target_include_directories (extfemio_bdf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# Local Variables:
# mode: cmake
# compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
# coding: utf-8
# End:
