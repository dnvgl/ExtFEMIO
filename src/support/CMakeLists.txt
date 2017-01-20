# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake configuration for libextfemio_support.

# ID: $Id$
# $Date$
# $Revision $
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

set(LIBEXTFEMIO_SUPPORT_SOURCES
  support_grouping.cpp
  support_grouping_csv.cpp
  support_errors.cpp
  support_grouping_ses.cpp)

set(LIBEXTFEMIO_FEM_HEADERS
  ../../include/support/grouping.h
  ../../include/support/errors.h
)

add_library (extfemio_support STATIC
  ${LIBEXTFEMIO_SUPPORT_SOURCES}
  ${LIBEXTFEMIO_SUPPORT_HEADERS})

if (COMMAND cotire)
  cotire(extfemio_support)
  set_target_properties(
    extfemio_support
    PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${CMAKE_SOURCE_DIR}/include/stdafx.h")
endif()

target_include_directories (extfemio_support PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# Local Variables:
# mode: cmake
# compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
# coding: utf-8
# End:
