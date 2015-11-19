ACLOCAL_AMFLAGS=-Im4

AM_CPPFLAGS=-Iinclude -Wall -Werror -std=c++11

top="$(CURDIR)"/

SUBDIRS= src tests include
EXTRA_DIST=
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

doxyfile.stamp: $(shell find docs -name \*.md) $(shell find src -name \*.cpp) $(shell find include -name \*.h)
	$(DOXYGEN) docs/Doxyfile
	echo Timestamp > doxyfile.stamp

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
