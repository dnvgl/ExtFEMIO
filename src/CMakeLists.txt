# -*- coding: utf-8 -*-

# Copyright © 2016 by DNV GL SE

# CMake configuration for libExtfemio++.

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# Create a library called "extfemio" which includes the source file
# from LIBEXTFEMIO_SOURCE. The extension is already found. Any number
# of sources could be listed here.
set(LIBEXTFEMIO_SOURCES
  extfem_string
  extfem_misc)
set(LIBEXTFEMIO_HEADERS
  ${CMAKE_SOURCE_DIR}/include/extfem_misc
  ${CMAKE_SOURCE_DIR}/include/extfem_string
  ${CMAKE_SOURCE_DIR}/include/my_c++14
  ${CMAKE_SOURCE_DIR}/include/resource)
add_library (extfemio
  ${LIBEXTFEMIO_SOURCES}
  ${LIBEXTFEMIO_HEADERS})
if (COMMAND cotire)
  cotire(extfemio)
endif()

# a custom target that is always built
ADD_CUSTOM_TARGET(revisiontag ALL)

# creates svnversion.h using cmake script
ADD_CUSTOM_COMMAND(TARGET revisiontag COMMAND ${CMAKE_COMMAND}
   -DSOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}
   -P ${CMAKE_SOURCE_DIR}/CMake/getsvn.cmake)

# explicitly say that the executable depends on custom target
add_dependencies(extfemio revisiontag)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (extfemio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
if (COMMAND cotire)
  set_target_properties(extfemio
    PROPERTIES
    COTIRE_CXX_PREFIX_HEADER_INIT "${CMAKE_SOURCE_DIR}/src/StdAfx.h")
endif()

add_subdirectory(bdf)
add_subdirectory(fem)
add_subdirectory(support)

# bin_PROGRAMS=bdf2bdf fem2fem

# bdf2bdf_SOURCES =bdf/bdf2bdf.cpp
# bdf2bdf_SOURCES+=bdf/bdf2bdf_args.c
# bdf2bdf_LDADD=$(LIBOBJS) $(LTLIBINTL)

# fem2fem_SOURCES =fem/fem2fem.cpp
# fem2fem_SOURCES+=fem/fem2fem_args.c
# fem2fem_LDADD=$(LIBOBJS) $(LTLIBINTL)

# %_args.o: AM_CPPFLAGS = -I../include -Wall

# %.c : %.ggo
#         $(GENGETOPT) --input=$<			\
#   --file-name=$(shell basename $(@F) .c)	\
#   --header-output-dir=../include/		\
#   --src-output-dir=$(@D) --unamed-opts

# vpath %.ggo fem bdf
# vpath %.c fem bdf
# vpath %.o fem bdf

# Local Variables:
# mode: cmake
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# coding: utf-8
# End:
