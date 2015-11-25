/**
  \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
  \copyright Copyright © 2015 by DNV GL SE
  \brief Element card representation for Sesam FEM.

  Detailed description
*/

// ID: $Id$

#ifndef _FEM_CARDS_ELEMENTS_H_
#define _FEM_CARDS_ELEMENTS_H_

#include <my_c++14.h>

namespace dnvgl {
  namespace extfem {
    namespace fem {
      namespace elements {

        /** Base class for FEM element representation.
         */
        class __base {
        public:
          __base() {};
        };

        class undef: public __base {
        public:
          static long nnodes;
        };

        /** 2-D, 2 Node Beam
         */
        class BEPS: public __base {
        public:
          static long nnodes;
        };

        /** Plane Constant Strain Triangle
         */
        class CSTA: public __base {
        public:
          static long nnodes;
        };

        /** Rect. Plate. Bending Modes
         */
        class RPBQ: public __base {
        public:
          static long nnodes;
        };

        /** Plane Lin. Strain Triangle
         */
        class ILST: public __base {
        public:
          static long nnodes;
        };

        /** Plane Quadrilateral Membrane Element
         */
        class IQQE: public __base {
        public:
          static long nnodes;
        };

        /** Plane Quadrilateral Membrane Element
         */
        class LQUA: public __base {
        public:
          static long nnodes;
        };

        /** Truss Element
         */
        class TESS: public __base {
        public:
          static long nnodes;
        };

        /** 1-Noded Mass-Matrix
         */
        class GMAS: public __base {
        public:
          static long nnodes;
        };

        /** 2-Noded Mass-Matrix
         */
        class GLMA: public __base {
        public:
          static long nnodes;
        };

        /** 2-Noded Damping-Matrix
         */
        class GLDA: public __base {
        public:
          static long nnodes;
        };

        /** 3-D, 2 Node Beam
         */
        class BEAS: public __base {
        public:
          static long nnodes;
        };

        /** Axial Spring
         */
        class AXIS: public __base {
        public:
          static long nnodes;
        };

        /** Axial Damper
         */
        class AXDA: public __base {
        public:
          static long nnodes;
        };

        /** Spring to Ground
         */
        class GSPR: public __base {
        public:
          static long nnodes;
        };

        /** Damper to Ground
         */
        class GDAM: public __base {
        public:
          static long nnodes;
        };

        /** Isoparametric Hexahedron
         */
        class IHEX: public __base {
        public:
          static long nnodes;
        };

        /** Linear Hexahedron
         */
        class LHEX: public __base {
        public:
          static long nnodes;
        };

        /** Subparametric Curved Beam
         */
        class SECB: public __base {
        public:
          static long nnodes;
        };

        /** General Curved Beam
         */
        class BTSS: public __base {
        public:
          static long nnodes;
        };

        /** Flat Quadrilateral Thin Shell (FQUS) or Free Formulation
            Quadrilateral Shell (FQQ)
         */
        class FQUS_FFQ: public __base {
        public:
          static long nnodes;
        };

        /** Flat Triangular Thin Shell (FTRS) or Free Formulation
            Triangular Shell (FFTR)
        */
        class FTRS_FFTR: public __base {
        public:
          static long nnodes;
        };

        /** Subparametric Curved Triangular Thick Shell
         */
        class SCTS: public __base {
        public:
          static long nnodes;
        };

        /** Subparam. Curved Triang. Thick Sandwich Elem.
         */
        class MCTS: public __base {
        public:
          static long nnodes;
        };

        /** Subparametric Curved Quadrilateral Thick Shell
         */
        class SCQS: public __base {
        public:
          static long nnodes;
        };

        /** Subparam. Curved Quadr. Thick Sandwich Elem.
         */
        class MCQS: public __base {
        public:
          static long nnodes;
        };

        /** Isoparametric Triangular Prism
         */
        class IPRI: public __base {
        public:
          static long nnodes;
        };

        /** Isoparametric Tetrahedron
         */
        class ITET: public __base {
        public:
          static long nnodes;
        };

        /** Triangular Prism
         */
        class TPRI: public __base {
        public:
          static long nnodes;
        };

        /** Tetrahedron
         */
        class TETR: public __base {
        public:
          static long nnodes;
        };

        /** Subparam. Layered Curved Triangular Thick Shell
         */
        class LCTS: public __base {
        public:
          static long nnodes;
        };

        /** Subparam. Layered Curved Quadrilat. Thick Shell
         */
        class LCQS: public __base {
        public:
          static long nnodes;
        };

        /** 2nd Order Hexahed. Transition Elem., Solid / Shell
         */
        class TRS1: public __base {
        public:
          static long nnodes;
        };

        /** 2nd Order Hexahed. Transition Elem., Solid / Shell
         */
        class TRS2: public __base {
        public:
          static long nnodes;
        };

        /** 2nd Order Hexahed. Transition Elem., Solid / Shell
         */
        class TRS3: public __base {
        public:
          static long nnodes;
        };

        /** General Spring / Shim Element
         */
        class GLSH: public __base {
        public:
          static long nnodes;
        };

        /** Axisymmetric Constant Strain Triangle
         */
        class AXCS: public __base {
        public:
          static long nnodes;
        };

        /** Axisymmetric Quadrilateral
         */
        class AXLQ: public __base {
        public:
          static long nnodes;
        };

        /** Axisymmetric Linear Strain Triangle
         */
        class AXLS: public __base {
        public:
          static long nnodes;
        };

        /** Axisymmetric Linear Strain Quadrilateral
         */
        class AXQQ: public __base {
        public:
          static long nnodes;
        };

        /** Pile / Soil
         */
       class PILS: public __base {
       public:
         static long nnodes;
       };

        /** Plane Cable-Bar Element
         */
        class PCAB: public __base {
        public:
          static long nnodes;
        };

        /** Plane Spring Element
         */
        class PSPR: public __base {
        public:
          static long nnodes;
        };

        /** 4-node Contact Element with triangular Shape
         */
        class ann4: public __base {
        public:
          static long nnodes;
        };

        /** 2-Noded Link Element
         */
        class ann2: public __base {
        public:
          static long nnodes;
        };

        /** 2-Noded Contact Element
         */
        class CTCP: public __base {
        public:
          static long nnodes;
        };

        /** 4-Noded Contact Element
         */
        class CTCL: public __base {
        public:
          static long nnodes;
        };

        /** 4-Noded Axisymmetric Contact Element
         */
        class CTAL: public __base {
        public:
          static long nnodes;
        };

        /** 6-Noded Contact Element
         */
        class CTCC: public __base {
        public:
          static long nnodes;
        };

        /** 6-Noded (3+3) Axisymmetric Contact Element
         */
        class CTAQ: public __base {
        public:
          static long nnodes;
        };

        /** 8-Noded (4+4) Contact Element
         */
        class CTLQ: public __base {
        public:
          static long nnodes;
        };

        /** 16-Noded (8+8) Contact Element
         */
        class CTCQ: public __base {
        public:
          static long nnodes;
        };

        /** 18-Noded (9+9) Contact Element
         */
        class CTMQ: public __base {
        public:
          static long nnodes;
        };

        /** 9-Noded Shell Element
         */
        class HCQS: public __base {
        public:
          static long nnodes;
        };

        /** Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)
         */
        class SLQS: public __base {
        public:
          static long nnodes;
        };

        /** Semiloof Triangular Curved Thin Shell (24 d.o.fs)
         */
        class SLTS: public __base {
        public:
          static long nnodes;
        };

        /** Semiloof Curved Beam (11 d.o.fs)
         */
        class SLCB: public __base {
        public:
          static long nnodes;
        };

        /** General Matrix Element with arbitrary no. of nodes (/n/)
         */
        class MATR: public __base {
        public:
          static long nnodes;
        };

        /** General Hexahedron
         */
        class GHEX100: public __base {
        public:
          static long nnodes;
        };

        /** General Hexahedron
         */
        class GHEX163: public __base {
        public:
          static long nnodes;
        };

        /** Dispatch element class instance for `id`
         */
        __base &dispatch(const long &id);
      }
    }
  }
}

#endif // _FEM_CARDS_ELEMENTS_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
// Copyright © 2015 by DNV GL SE
