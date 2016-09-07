INCLUDE(FindLATEX)

# add a target to generate API documentation with Doxygen
FIND_PACKAGE(Doxygen)
FIND_PACKAGE(LATEX)
if(DOXYGEN_FOUND)
  CONFIGURE_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/header.tex.in
    ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex/header.tex @ONLY)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/.latexmkrc.in
    ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex/.latexmkrc)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/mydoxygen.sty.in
    ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex/mydoxygen.sty)
  ADD_CUSTOM_TARGET(doc ALL
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
  IF(LATEX_COMPILER)
    MESSAGE("LATEX FOUND")
    ADD_CUSTOM_TARGET(pdf
      latexmk refman
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex
      VERBATIM)
    ADD_DEPENDENCIES(pdf doc)
  ENDIF(LATEX_COMPILER)
ENDIF(DOXYGEN_FOUND)


# if HAVE_DOXYGEN
# directory = $(top_srcdir)/docs/man/man3/

# dist_man_MANS = $(directory)/man_page_1.3 $(directory)/man_page_2.3
# $(directory)/man_page_1.3: doxyfile.stamp
# $(directory)/man_page_2.3: doxyfile.stamp

# refman: doxyfile.stamp docs/doxy/latex/.latexmkrc
#         cd docs/doxy/latex/ ; latexmk refman

# docs/doxy/latex/.latexmkrc: docs/.latexmkrc
#         $(CP) $< $@

# doxyfile.stamp: docs/Doxyfile  docs/header.tex			\
#   $(shell find src include \( -name \*.cpp -o -name \*.h \) )
#         $(DOXYGEN) docs/Doxyfile
#         date > doxyfile.stamp

# CLEANFILES = doxyfile.stamp

# all-local: doxyfile.stamp
# clean-local:
#         rm -rf $(top_srcdir)/docs/man
# endif

# # Local Variables:
# # mode: makefile
# # compile-command: "make check -j8"
# # End:

# # End of Makefile.am
# dnl Process this file with autoconf to produce a configure script.

# AC_CONFIG_MACRO_DIR([m4])

# m4_include(m4/ax_cxx_compile_stdcxx_11.m4)
# m4_include(m4/boost.m4)

# AC_INIT([ExtFEMIO], [0.3])
# AC_CONFIG_SRCDIR([src/Makefile.am])
# AM_INIT_AUTOMAKE([foreign])
# AM_CONFIG_HEADER(config.h)
# AC_PROG_CXX
# AC_PROG_CC
# gl_EARLY
# AC_PROG_LIBTOOL

# AC_CONFIG_FILES([lib/Makefile])

# # For gnulib.
# gl_INIT

# #-------------------------------------------------------------------------------
# # Check for C++11
# #-------------------------------------------------------------------------------
# AC_LANG_PUSH([C++])
# AX_CXX_COMPILE_STDCXX_11([ext],[optional])
# AC_LANG_POP([C++])

# #-------------------------------------------------------------------------------
# # Check for gengetopt
# #-------------------------------------------------------------------------------
# AC_CHECK_PROGS([GENGETOPT], [gengetopt])
# if test -z "$GENGETOPT";
#   then AC_MSG_ERROR([gengetopt not found - aborting])
# fi

# AC_CONFIG_FILES([src/fem/fem2fem_args.ggo src/bdf/bdf2bdf_args.ggo])

# #-------------------------------------------------------------------------------
# # Check for doxygen
# #-------------------------------------------------------------------------------
# AC_CHECK_PROGS([DOXYGEN], [doxygen])
# if test -z "$DOXYGEN";
#   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
# fi

# AM_CONDITIONAL([HAVE_DOXYGEN], [ test -n "$DOXYGEN" ])
# AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile docs/header.tex])])

# #-------------------------------------------------------------------------------
# # Check for boost and boost regex
# #-------------------------------------------------------------------------------
# BOOST_REQUIRE
# BOOST_REGEX

# #-------------------------------------------------------------------------------
# # Checking for catch.
# #-------------------------------------------------------------------------------
# # AC_CHECK_HEADER([catch.hpp], [], [AC_MSG_ERROR([Could not find catch.hpp. Please download and install it from http://builds.catch-lib.net])])
# # catch is provided in local inlude directory

# # End the configure script.
# AC_OUTPUT(Makefile tests/Makefile src/Makefile include/Makefile, [date > stamp-h] )

# # Local Variables:
# # mode: m4
# # compile-command: "make check -j8"
# # End:

# # End of configure.ac
