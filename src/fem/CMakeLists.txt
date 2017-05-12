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
  fem_cards_gbox.cpp
  fem_cards_gchan.cpp
  fem_cards_gchanr.cpp
  fem_cards_gcoord.cpp
  fem_cards_gdobo.cpp
  fem_cards_gecc.cpp
  fem_cards_geccen.cpp
  fem_cards_gelmnt1.cpp
  fem_cards_gelmnt2.cpp
  fem_cards_gelref1.cpp
  fem_cards_gelth.cpp
  fem_cards_giorh.cpp
  fem_cards_giorhr.cpp
  fem_cards_glsec.cpp
  fem_cards_glsecr.cpp
  fem_cards_gnode.cpp
  fem_cards_gpipe.cpp
  fem_cards_gsetmemb.cpp
  fem_cards_gtonp.cpp
  fem_cards_gunivec.cpp
  fem_cards_gusyi.cpp
  fem_cards_helper_beam_prop.cpp
  fem_cards_helper_eccno.cpp
  fem_cards_helper_geoprop.cpp
  fem_cards_helper_transno.cpp
  fem_cards_helper_unknown.cpp
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
  ${CMAKE_SOURCE_DIR}/include/extfem_misc.h
  ${CMAKE_SOURCE_DIR}/include/extfem_string.h
  ${CMAKE_SOURCE_DIR}/include/my_c++14.h
  ${CMAKE_SOURCE_DIR}/include/resource.h
  ${CMAKE_SOURCE_DIR}/include/fem/cards.h
  ${CMAKE_SOURCE_DIR}/include/fem/card_hl_node_elem.h
  ${CMAKE_SOURCE_DIR}/include/fem/cards_bounds.h
  ${CMAKE_SOURCE_DIR}/include/fem/cards_ident.h
  ${CMAKE_SOURCE_DIR}/include/fem/cards_mat.h
  ${CMAKE_SOURCE_DIR}/include/fem/cards_node_elem.h
  ${CMAKE_SOURCE_DIR}/include/fem/cards_superele.h
  ${CMAKE_SOURCE_DIR}/include/fem/elements.h
  ${CMAKE_SOURCE_DIR}/include/fem/errors.h
  ${CMAKE_SOURCE_DIR}/include/fem/file.h
  ${CMAKE_SOURCE_DIR}/include/fem/type_bounds.h
  ${CMAKE_SOURCE_DIR}/include/fem/types.h)
add_library (extfemio_fem STATIC
  ${LIBEXTFEMIO_FEM_SOURCES}
  ${LIBEXTFEMIO_FEM_HEADERS})
if (COMMAND cotire)
  cotire(extfemio_fem)
  set_target_properties(extfemio_fem
    PROPERTIES
    COTIRE_CXX_PREFIX_HEADER_INIT "${CMAKE_SOURCE_DIR}/src/StdAfx.h")
endif()

target_include_directories (extfemio_fem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# # a custom target that is always built
# ADD_CUSTOM_TARGET(revisiontag ALL)

# creates svnversion.h using cmake script
ADD_CUSTOM_COMMAND(TARGET revisiontag COMMAND ${CMAKE_COMMAND}
   -DSOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}
   -P ${CMAKE_SOURCE_DIR}/CMake/getsvn.cmake)

# explicitly say that the executable depends on custom target
add_dependencies(extfemio_fem revisiontag)

IF(NOT MSVC)
  add_executable(fem2fem
    fem2fem.cpp fem2fem_args.c)
  target_link_libraries(fem2fem ${EXTFEM_FEM_LIBS})
ENDIF()

CONFIGURE_FILE(
  ${CMAKE_CURRENT_SOURCE_DIR}/fem2fem_args.ggo.in
  ${CMAKE_CURRENT_SOURCE_DIR}/fem2fem_args.ggo)

if(CMAKE_COMPILER_IS_GNUCXX)
  # add the commands to generate the source code
  add_custom_command (
    OUTPUT
      ${CMAKE_SOURCE_DIR}/src/fem/fem_elements.cpp
    COMMAND
      cd ${CMAKE_SOURCE_DIR} && python3 tools/elements_com_cpp_do.py ||
      svn revert ${CMAKE_SOURCE_DIR}/src/fem/fem_elements.cpp
    DEPENDS
      ${CMAKE_SOURCE_DIR}/tools/elements_com_cpp_do.py
      ${CMAKE_SOURCE_DIR}/tools/elements_data.py
      ${CMAKE_SOURCE_DIR}/tools/templates/fem_elements.cpp)
  add_custom_command (
    OUTPUT
      ${CMAKE_SOURCE_DIR}/include/fem/elements.h
    COMMAND
      cd ${CMAKE_SOURCE_DIR} && python3 tools/elements_h_do.py ||
      svn revert ${CMAKE_SOURCE_DIR}/include/fem/elements.h
    DEPENDS
      ${CMAKE_SOURCE_DIR}/tools/elements_h_do.py
      ${CMAKE_SOURCE_DIR}/tools/elements_data.py
      ${CMAKE_SOURCE_DIR}/tools/templates/fem_elements.h)
  add_custom_command (
    OUTPUT
      ${CMAKE_CURRENT_SOURCE_DIR}/fem2fem_args.c
    COMMAND
      cd ${CMAKE_CURRENT_SOURCE_DIR} &&
        gengetopt --input=fem2fem_args.ggo --file-name=fem2fem_args --header-output-dir=../../include/ --src-output-dir=. --unamed-opts ||
        svn revert ${CMAKE_SOURCE_DIR}/fem2fem_args.c;
    DEPENDS
      ${CMAKE_CURRENT_SOURCE_DIR}/fem2fem_args.ggo)
endif()

# Local Variables:
# mode: cmake
# compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
# coding: utf-8
# End:
