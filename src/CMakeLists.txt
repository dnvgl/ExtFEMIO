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
  ../include/extfem_misc
  ../include/extfem_string
  ../include/fem2fem_args
  ../include/my_c++14
  ../include/resource
  ../include/StdAfx)
add_library (extfemio
  ${LIBEXTFEMIO_SOURCES}
  ${LIBEXTFEMIO_HEADERS})
cotire(extfemio)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (extfemio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(extfemio PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${CMAKE_SOURCE_DIR}/include/stdafx.h")

add_subdirectory(bdf)
add_subdirectory(fem)

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
