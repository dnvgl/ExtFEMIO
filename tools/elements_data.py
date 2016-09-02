#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate access code for FEM elements.
"""

from __future__ import (
    division, print_function, absolute_import, unicode_literals)

# Standard libraries.
import itertools

# ID: $Id: elements_do.py 438 2016-09-01 15:15:08Z berhol $
__date__ = "$Date:: 2016-09-01 17:15:08 +0200 #$"[7:-1]
__scm_version__ = "$Revision: 438 $"[10:-1]
__author__ = "`Berthold Höllmann <berthold.hoellmann@dnvgl.com>`__"
__copyright__ = "Copyright © 2016 by DNV GL SE"

ADVANCE = "ADVANCE"
Framework = "Framework"
Launch = "Launch"
Platework = "Platework"
Poseidon = "Poseidon"
Prefem = "Prefem"
Preframe = "Preframe"
Pretube = "Pretube"
Sestra = "Sestra"
Splice = "Splice"
Wadam = "Wadam"
general = "general"

_ELEMENTS = dict(
    adva_2=dict(
        doc="2-Noded Link Element", procs={general, ADVANCE}, nnodes=2,
        eltyp=49),
    adva_4=dict(doc="4-node Contact Element with triangular Shape",
                procs={general, ADVANCE}, nnodes=4, eltyp=48),
    axcs=dict(doc="Axisymmetric Constant Strain Triangle", procs={
              general, Prefem, Sestra, ADVANCE}, nnodes=3, eltyp=41),
    axda=dict(doc="Axial Damper", procs={
              general, Preframe, Prefem, Sestra, Poseidon}, nnodes=2,
              eltyp=17),
    axis=dict(doc="Axial Spring", procs={
              general, Preframe, Prefem, Sestra, ADVANCE, Framework, Poseidon},
              nnodes=2, eltyp=16),
    axlq=dict(doc="Axisymmetric Quadrilateral", procs={
              general, Prefem, Sestra, ADVANCE}, nnodes=4, eltyp=42),
    axls=dict(doc="Axisymmetric Linear Strain Triangle", procs={
              general, Prefem, Sestra}, nnodes=6, eltyp=43),
    axqq=dict(doc="Axisymmetric Linear Strain Quadrilateral",
              procs={general, Prefem, Sestra}, nnodes=8, eltyp=44),
    beas=dict(doc="3-D, 2 Node Beam", procs={
        general, Preframe, Prefem, Sestra, ADVANCE, Framework, Launch,
        Platework, Pretube, Wadam, Poseidon}, nnodes=2, eltyp=15),
    beps=dict(
        doc="2-D, 2 Node Beam", procs={general, Preframe, ADVANCE}, nnodes=2,
        eltyp=2),
    btss=dict(doc="General Curved Beam", procs={
              general, Prefem, Sestra, Platework, Pretube}, nnodes=3,
              eltyp=23),
    csta=dict(doc="Plane Constant Strain Triangle", procs={
              general, Prefem, Sestra, ADVANCE}, nnodes=3, eltyp=3),
    ctal=dict(doc="4-Noded Axisymmetric Contact Element",
              procs={general}, nnodes=4, eltyp=53),
    ctaq=dict(doc="6-Noded (3+3) Axisymmetric Contact Element",
              procs={general, Prefem}, nnodes=6, eltyp=55),
    ctcc=dict(doc="6-Noded Contact Element",
              procs={general}, nnodes=6, eltyp=54),
    ctcl=dict(doc="4-Noded Contact Element",
              procs={general}, nnodes=4, eltyp=52),
    ctcp=dict(doc="2-Noded Contact Element",
              procs={general}, nnodes=2, eltyp=51),
    ctcq=dict(doc="16-Noded (8+8) Contact Element",
              procs={general, Prefem, Pretube}, nnodes=16, eltyp=57),
    ctlq=dict(doc="8-Noded (4+4) Contact Element",
              procs={general, Pretube}, nnodes=8, eltyp=56),
    ctmq=dict(doc="18-Noded (9+9) Contact Element",
              procs={general, Pretube}, nnodes=18, eltyp=58),
    fqus_ffq=dict(
        doc="Flat Quadrilateral Thin Shell / Free Formulation "
        "Quadrilateral Shell",
        procs={general, Prefem, Sestra, ADVANCE, Platework, Pretube, Poseidon},
        nnodes=4, eltyp=24, base="fem_thin_shell"),
    ftrs_fftr=dict(
        doc=" Flat Triangular Thin Shell / Free Formulation Triangular Shell",
        procs={general, Prefem, Sestra, ADVANCE, Platework, Poseidon},
        nnodes=3, eltyp=25, base="fem_thin_shell"),
    gdam=dict(doc="Damper to Ground", procs={
              general, Preframe, Prefem, Sestra, Poseidon}, nnodes=1,
              eltyp=19),
    glda=dict(doc="2-Noded Damping-Matrix",
              procs={general}, nnodes=2, eltyp=13),
    glma=dict(doc="2-Noded Mass-Matrix",
              procs={general, Sestra}, nnodes=2, eltyp=12),
    glsh=dict(doc="General Spring / Shim Element",
              procs={general, Preframe, Sestra, Poseidon}, nnodes=2, eltyp=40),
    gmas=dict(doc="1-Noded Mass-Matrix",
              procs={general, Prefem, Sestra, Poseidon}, nnodes=1, eltyp=11),
    gspr=dict(doc="Spring to Ground", procs={
              general, Preframe, Prefem, Sestra, ADVANCE, Framework, Poseidon},
              nnodes=1, eltyp=18),
    hcqs=dict(doc="9-Noded Shell Element",
              procs={general, Prefem, Pretube}, nnodes=9, eltyp=61),
    ihex=dict(doc="Isoparametric Hexahedron", procs={
              general, Prefem, Sestra, ADVANCE, Framework}, nnodes=20,
              eltyp=20),
    ilst=dict(doc="Plane Lin. Strain Triangle", procs={
              general, Prefem, Sestra}, nnodes=6, eltyp=6),
    ipri=dict(doc="Isoparametric Triangular Prism", procs={
              general, Prefem, Sestra, ADVANCE}, nnodes=15, eltyp=30),
    iqqe=dict(doc="Plane Quadrilateral Membrane Element",
              procs={general, Prefem, Sestra}, nnodes=8, eltyp=8),
    itet=dict(doc="Isoparametric Tetrahedron", procs={
              general, Sestra}, nnodes=10, eltyp=31),
    lcqs=dict(doc="Subparam. Layered Curved Quadrilat. Thick Shell",
              procs={general, Prefem, Sestra}, nnodes=8, eltyp=35),
    lcts=dict(doc="Subparam. Layered Curved Triangular Thick Shell",
              procs={general, Prefem, Sestra}, nnodes=6, eltyp=34),
    lhex=dict(doc="Linear Hexahedron", procs={
              general, Prefem, Sestra, ADVANCE, Framework}, nnodes=8,
              eltyp=21),
    lqua=dict(doc="Plane Quadrilateral Membrane Element", procs={
              general, Prefem, Sestra, ADVANCE, Poseidon}, nnodes=4, eltyp=9),
    matr=dict(doc="General Matrix Element with arbitrary no. of nodes (/n/)",
              procs={general, ADVANCE, Splice}, nnodes=0, eltyp=70),
    mcqs=dict(doc="Subparam. Curved Quadr. Thick Sandwich Elem.",
              procs={general, Prefem, Sestra}, nnodes=8, eltyp=29),
    mcts=dict(doc="Subparam. Curved Triang. Thick Sandwich Elem.",
              procs={general, Prefem, Sestra}, nnodes=6, eltyp=27),
    pcab=dict(doc="Plane Cable-Bar Element",
              procs={general, Preframe, ADVANCE}, nnodes=2, eltyp=46),
    pils=dict(
        doc="Pile / Soil", procs={general, Preframe, ADVANCE}, nnodes=1,
        eltyp=45),
    pspr=dict(doc="Plane Spring Element", procs={
              general, Preframe, ADVANCE}, nnodes=1, eltyp=47),
    rpbq=dict(doc="Rect. Plate. Bending Modes",
              procs={general}, nnodes=4, eltyp=5),
    scqs=dict(doc="Subparametric Curved Quadrilateral Thick Shell", procs={
              general, Prefem, Sestra, Platework, Pretube}, nnodes=8,
              eltyp=28),
    scts=dict(doc="Subparametric Curved Triangular Thick Shell", procs={
              general, Prefem, Sestra, Platework}, nnodes=6, eltyp=26),
    secb=dict(doc="Subparametric Curved Beam",
              procs={general}, nnodes=3, eltyp=22),
    slcb=dict(doc="Semiloof Curved Beam (11 d.o.fs)",
              procs={general}, nnodes=3, eltyp=68),
    slqs=dict(doc="Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)",
              procs={general}, nnodes=8, eltyp=66),
    slts=dict(doc="Semiloof Triangular Curved Thin Shell (24 d.o.fs)",
              procs={general}, nnodes=6, eltyp=67),
    tess=dict(doc="Truss Element", procs={
              general, Preframe, Prefem, Sestra, ADVANCE, Poseidon}, nnodes=2,
              eltyp=10),
    tetr=dict(doc="Tetrahedron", procs={general, Sestra}, nnodes=4, eltyp=33),
    tpri=dict(doc="Triangular Prism", procs={
              general, Prefem, Sestra, Platework}, nnodes=6, eltyp=32),
    trs1=dict(doc="2nd Order Hexahed. Transition Elem., Solid / Shell",
              procs={general, Sestra, Pretube}, nnodes=18, eltyp=36),
    trs2=dict(doc="2nd Order Hexahed. Transition Elem., Solid / Shell",
              procs={general, Sestra, Pretube}, nnodes=15, eltyp=37),
    trs3=dict(doc="2nd Order Hexahed. Transition Elem., Solid / Shell",
              procs={general, Sestra, Pretube}, nnodes=12, eltyp=38))


class ghex:

    nodes = {1: 21, 2: 22, 4: 23, 8: 24, 16: 25, 32: 26}

    def __init__(self, n):
        self.n = n

    @property
    def pos(self):
        return tuple(self.nodes[i] for i in self.n) + (27, )

    def gen_extnodes(self):
        if self.pos[:-1]:
            return ", {}".format(
                ", ".join("node {}".format(i) for i in self.pos))
        return ""

    def gen_nodepos(self, space):
        res = []
        for i, num in enumerate(self.pos):
            res.append((i + 21,  num))
        return "\n".join(space + "- node {1} at pos {0}".format(*i)
                         for i in res)

    @property
    def eltyp(self):
        return sum(self.n) + 100

    def get_dict(self):
        return dict(
            doc="""General Hexahedron, define with nodes 1 to 20{} and node 27 present.

   Position of node in node array for element node numbers > 20:

{}""".format(self.gen_extnodes(), self.gen_nodepos(20 * " ")),
            procs={"general", "Sestra"},
            nnodes=20 + len(self.pos),
            eltyp=self.eltyp)

    def get_name(self):
        return "ghex{:03d}".format(self.eltyp)

for j in range(7):
    for k in itertools.combinations((1, 2, 4, 8, 16, 32), j):
        g = ghex(k)
        _ELEMENTS[g.get_name()] = g.get_dict()

[_ELEMENTS[i].setdefault("base", "elem") for i in _ELEMENTS]


def s_key(i):
    return i[1]['eltyp']

ELEMENTS = sorted([(i, _ELEMENTS[i]) for i in _ELEMENTS], key=s_key)
ENUMS = [(i[0].upper(), i[1]['eltyp']) for i in ELEMENTS]


def list_init(start, stop):
    if start == stop:
        return list(range(start, start + 70))
    else:
        return list(range(start,  stop))


def list_init_form(start, stop):
    data = list_init(start, stop)
    if len(data) > 1:
        return "{{{}}}".format(", ".join("{}".format(i) for i in data))
    else:
        return "1, {:d}".format(start)

# Local Variables:
# mode: python
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# End:
