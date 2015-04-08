# -*- coding: utf-8 -*-

# Copyright © 2015 by DNV GL SE

# Makefile for BDFTypes++

# ID: $Id$
# $Date$
# $Revision$
# Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

SHELL = /bin/sh

DESTDIR = linux_x86_64

CPPFLAGS += -Isrc

LDLIBS += -L$(DESTDIR) -lbdftypes++

LIB_SRC = bdf_types.cpp

TEST_SRC = test_bdf_types.cpp

LIB_OBJECTS = $(addprefix $(DESTDIR)/,				\
	$(patsubst %.cpp,%.o,$(patsubst %.c,%.o,${LIB_SRC})))

TEST_OBJECTS = $(addprefix $(DESTDIR)/,				\
	$(patsubst %.cpp,%.o,$(patsubst %.c,%.o,${TEST_SRC})))


default: depend all

ifneq ($(MAKECMDGOALS),clean)
include $(LIB_OBJECTS:%.o=%.d)
include $(TEST_OBJECTS:%.o=%.d)
endif

all:	TAGS $(DESTDIR)/libbdftypes++.a

test:	TAGS depend $(DESTDIR)/libbdftypes++.a	$(TEST_OBJECTS)	$(DESTDIR)/test_bdf_types
	$(DESTDIR)/test_bdf_types

$(DESTDIR)/libbdftypes++.a:	$(LIB_OBJECTS)
	@(mkdir -p $(@D)/ > /dev/null 2>&1 ; chmod a+rx $(@D) ; true)
	$(AR) $(ARFLAGS) $@ $<

$(DESTDIR)/%.o:	%.cpp
	@(mkdir -p $(@D)/ > /dev/null 2>&1 ; chmod a+rx $(@D) ; true)
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

$(DESTDIR)/%: $(DESTDIR)/%.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

depend: $(LIB_OBJECTS:%.o=%.d) $(TEST_OBJECTS:%.o=%.d)

$(DESTDIR)/%.d:	%.cpp
	@(mkdir -p $(@D)/ > /dev/null 2>&1 ; chmod a+rx $(@D) ; true)
	$(COMPILE.C) -MM $< > $@.tmp
	sed "s=^\(.*\):=$(@D)/\\1:=" < $@.tmp > $@
	sed "s=^\(.*\).o:=$(@D)/\\1.d:=" < $@.tmp >> $@
	rm -f $@.tmp

TAGS: $(LIB_SRC) $(TEST_SRC)
	( find . -name \*.cpp -o -name \*.h -o -name \*.c ) | etags -I -

vpath %.cpp src
vpath %.cpp tests

# Local Variables:
# mode: makefile
# ispell-local-dictionary:"english"
# compile-command:"make test"
# End:
