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

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (extfemio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(bdf)
add_subdirectory(fem)



# ../include/fem/elements_ghex.h : fem/fem_element_ghex.cpp
# fem/fem_element_ghex.cpp : ../tools/ghex_do.py	\
#   ../tools/templates/element_ghex.h		\
#   ../tools/templates/element_ghex.cpp		\
#   ../tools/templates/test_fem_element_ghex.cpp
#         (set -e ; cd .. ; python3 tools/ghex_do.py) || \
#         svn revert fem/fem_element_ghex.cpp ../include/fem/elements_ghex.h

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

# # Local Variables:
# # mode: makefile
# # compile-command: "make -C .. check -j8"
# # End:

# # End of Makefile.am
