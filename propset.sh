#! /bin/bash

# Copyright © 2017 by DNV GL SE

# Task  : Setting SVN properties.

# Author: Berthold Höllmann <berthold.hoellmann@dnvgl.com>

# ID: $Id$
author="$Author$"
date="$Date$"
version="$Revision$"

set +f

RULE=( \( -wholename ./build -prune
       -o -wholename ./.tox -prune
       -o -wholename ./.svn -prune
       -o -wholename ./.mypy_cache -prune
       -o -wholename ./cbuild -prune
       -o -name .svn -prune
       -o -name \*.egg-info -prune
       -o -wholename ./.venv -prune
       -o -wholename ./htmlcov -prune
       -o -wholename ./.cache -prune \)
       -o \( -name \*.org
       -o -name \*.cpp
       -o -name \*.h
       -o -name \*.sh
       -o -name \*.txt
       -o -name \*.svg
       -o -name \*.py
       -o -name \*.html
       -o -name \*.in
       -o -name \*.tex
       -o -name \*.txt
       -o -name \*.f90 \) )

find . "${RULE[@]}" -exec svn propset svn:keywords "Author Date Id Revision" {} \;
find . "${RULE[@]}" -exec svn propset svn:eol-style native {} \;


# Local Variables:
# mode: shell-script
# coding: utf-8
# compile-command: "sh propset.sh"
# End:
