/**
   \brief ghex* element card representation for Sesam FEM.
   \file fem/elements_ghex.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE

   General Hexahedron elements.
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

            /** General Hexahedron
             */
            class ghex : public __base {
            public:
               ghex(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex(const dnvgl::extfem::fem::cards::gelref1*);
               ghex(const __base*);
               virtual long nnodes(void) const = 0;
               virtual el_types get_type(void) const = 0;
            };
{% for num, pos in res %}
            /** General Hexahedron, define with nodes 1 to 20{{ gen_extnodes(pos[:-1]) }} and node 27 present.

                Position of node in node array for element node numbers > 20:

{{ gen_nodepos(pos, 20 * " ") }}
             */
            class ghex1{{ "%02d"|format(num) }}: public ghex {
            public:
               ghex1{{ "%02d"|format(num) }}(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex1{{ "%02d"|format(num) }}(const dnvgl::extfem::fem::cards::gelref1*);
               ghex1{{ "%02d"|format(num) }}(const __base*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };
{% endfor %}
         }
      }
   }
}
#endif // _FEM_CARDS_ELEMENTS_GHEX_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
