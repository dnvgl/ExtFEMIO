dnl Process this file with autoconf to produce a configure script.

AC_CONFIG_MACRO_DIR([m4])

m4_include(m4/ax_cxx_compile_stdcxx_11.m4)
m4_include(m4/boost.m4)

AC_INIT([ExtFEMIO], [0.3])
AC_CONFIG_SRCDIR([src/Makefile.am])
AM_INIT_AUTOMAKE([foreign])
AM_CONFIG_HEADER(config.h)
AC_PROG_CXX
AC_PROG_CC
gl_EARLY
AC_PROG_LIBTOOL

AC_CONFIG_FILES([lib/Makefile])

# For gnulib.
gl_INIT

#-------------------------------------------------------------------------------
# Check for C++11
#-------------------------------------------------------------------------------
AC_LANG_PUSH([C++])
AX_CXX_COMPILE_STDCXX_11([ext],[optional])
AC_LANG_POP([C++])

#-------------------------------------------------------------------------------
# Check for gengetopt
#-------------------------------------------------------------------------------
AC_CHECK_PROGS([GENGETOPT], [gengetopt])
if test -z "$GENGETOPT";
  then AC_MSG_ERROR([gengetopt not found - aborting])
fi

AC_CONFIG_FILES([src/fem/fem2fem_args.ggo src/bdf/bdf2bdf_args.ggo])

#-------------------------------------------------------------------------------
# Check for doxygen
#-------------------------------------------------------------------------------
AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
  then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi

AM_CONDITIONAL([HAVE_DOXYGEN], [ test -n "$DOXYGEN" ])
AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile docs/header.tex])])

#-------------------------------------------------------------------------------
# Check for boost and boost regex
#-------------------------------------------------------------------------------
BOOST_REQUIRE
BOOST_REGEX

#-------------------------------------------------------------------------------
# Checking for catch.
#-------------------------------------------------------------------------------
# AC_CHECK_HEADER([catch.hpp], [], [AC_MSG_ERROR([Could not find catch.hpp. Please download and install it from http://builds.catch-lib.net])])
# catch is provided in local inlude directory

# End the configure script.
AC_OUTPUT(Makefile tests/Makefile src/Makefile include/Makefile, [date > stamp-h] )

# Local Variables:
# mode: m4
# compile-command: "make check -j8"
# End:

# End of configure.ac
