ACLOCAL_AMFLAGS=-Im4

AM_CPPFLAGS=-Iinclude -Wall -Werror -std=c++11
AM_CPPFLAGS+=-I$(top_srcdir)/gl -I$(top_builddir)/gl -I$(top_builddir)


top="$(CURDIR)"/

SUBDIRS=lib src tests include
EXTRA_DIST=m4/gnulib-cache.m4
test_MISC=configure

CP=cp

if HAVE_DOXYGEN
directory = $(top_srcdir)/docs/man/man3/

dist_man_MANS = $(directory)/man_page_1.3 $(directory)/man_page_2.3
$(directory)/man_page_1.3: doxyfile.stamp
$(directory)/man_page_2.3: doxyfile.stamp

refman: doxyfile.stamp docs/doxy/latex/.latexmkrc
	cd docs/doxy/latex/ ; latexmk refman

docs/doxy/latex/.latexmkrc: docs/.latexmkrc
	$(CP) $< $@

doxyfile.stamp: docs/Doxyfile  docs/header.tex			\
  $(shell find src include \( -name \*.cpp -o -name \*.h \) )
	$(DOXYGEN) docs/Doxyfile
	date > doxyfile.stamp

CLEANFILES = doxyfile.stamp

all-local: doxyfile.stamp
clean-local:
	rm -rf $(top_srcdir)/docs/man
endif

# Local Variables:
# mode: makefile
# ispell-local-dictionary: "english"
# compile-command: "make check -j 8"
# End:

# End of Makefile.am
