#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate access code for FEM GHEX elements.
"""

from __future__ import (
    division, print_function, absolute_import, unicode_literals)

# Standard libraries.
import itertools

# ID: $Id$
__date__ = "$Date::                            $"[7:-1]
__scm_version__ = "$Revision$"[10:-1]
__author__ = "`Berthold Höllmann <berthold.hoellmann@dnvgl.com>`__"
__copyright__ = "Copyright © 2016 by DNV GL SE"


src_tmpl = ("""/**
   \\file fem/fem_element_ghex1{num:02d}.cpp
   \\author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \\copyright Copyright © 2016 by DNV GL SE
   \\brief FEM element definition for ghex1{num:02d}.

   General Hexahedron, define with nodes 1 to 20{extnodes} and node 27 present.

   Position of node in node array for element node numbers > 20:

{nodepos}
*/

#include "StdAfx.h"

// ID:
namespace {{
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}}

#include "fem/elements.h"

using namespace ::dnvgl::extfem::fem::elements;

const long ghex1{num:02d}::nnodes = {nodes};

el_types ghex1{num:02d}::get_type() const {{return GHEX1{num:02d};}}

namespace {{
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {{general, Sestra}};
}}
const ::std::set<el_processor> ghex1{num:02d}::processors(procs, """
            """procs+procs_len);

ghex1{num:02d}::ghex1{num:02d}(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {{}}

ghex1{num:02d}::ghex1{num:02d}(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {{}}

ghex1{num:02d}::ghex1{num:02d}(const __base *data) :
   ghex(data) {{}}

el_types ghex1{num:02d}::get_type(void) {{
   return GHEX1{num:02d};
}}

// Local Variables:
// mode: c+"""
            """+
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
""")


def take(n):
    NODES = {1: 21, 2: 22, 4: 23, 8: 24, 16: 25, 32: 26}
    return tuple(NODES[i] for i in n)


def gen_extnodes(pos):
    if pos:
        return ", {}".format(
            ", ".join("node {}".format(i) for i in pos))
    return ""


def gen_nodepos(pos, space):
    res = []
    for i, num in enumerate(pos):
        res.append((i + 21,  num))
    return "\n".join(space + "- node {1} at pos {0}".format(*i) for i in res)

RES = []
for x in itertools.chain(itertools.combinations((1, 2, 4, 8, 16, 32), j)
                         for j in range(7)):
    RES += [(sum(k), take(k) + (27, )) for k in x]
RES.sort()

with open("Makefile.am.tmlp", 'w') as make, \
        open("vcxproj.tmpl",  'w') as vcx, \
        open("filters.tmpl", 'w') as filters, \
        open("include/fem/elements_ghex.h",  'w') as head:

    head.write("""/**
   \\file fem/elements_ghex.h
   \\author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \\copyright Copyright © 2015 by DNV GL SE
   \\brief ghex* element card representation for Sesam FEM.

   Detailed description
*/

// ID: $Id$

#ifndef _FEM_CARDS_ELEMENTS_GHEX_H_
#define _FEM_CARDS_ELEMENTS_GHEX_H_

#include <my_c++14.h>

#include <set>

#include "cards.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace elements {

""")

    for i, pos in RES:
        fname = "src/fem/fem_element_ghex1{0:02d}.cpp".format(i)

        with open(fname, 'w') as out:
            out.write(src_tmpl.format(
                num=i, nodes=20 + len(pos),
                extnodes=gen_extnodes(pos[:-1]),
                nodepos=gen_nodepos(pos, "        ")))

        make.write(
            'libextfemio_la_SOURCES += fem/fem_element_ghex1{0:02d}.cpp\n'
            .format(i))
        vcx.write(
            '    <ClCompile Include="fem\\fem_element_ghex1{0:02d}.cpp" />\n'
           .format(i))
        filters.write(
            '''    <ClCompile Include="fem\\fem_element_ghex1{0:02d}.cpp">
      <Filter>FEM\\Source Files</Filter>
    </ClCompile>
'''.format(i))
        head.write("""\
            /** General Hexahedron, define with nodes 1 to 20{extnodes} and node 27 present.

                Position of node in node array for element node numbers > 20:

{nodepos}
             */
            class DECLSPECIFIER ghex1{num:02d}: public ghex {{
            public:
               ghex1{num:02d}(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex1{num:02d}(const ::dnvgl::extfem::fem::cards::gelref1*);
               ghex1{num:02d}(const __base*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            }};

""".format(num=i, extnodes=gen_extnodes(pos[:-1]),
           nodepos=gen_nodepos(pos, 20 * " ")))

    head.write("""\
         }
      }
   }
}
#endif // _FEM_CARDS_ELEMENTS_GHEX_H_

// Local Var""" """iables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
""")

# Local Variables:
# mode: python
# ispell-local-dictionary: "english"
# compile-command: "cd ..;python3 tools/ghex_do.py&&make check - j8"
# End:
