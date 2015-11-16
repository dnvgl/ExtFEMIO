# -*- mode: org -*-
#+LATEX_CLASS: dnvglartcl
#+LATEX_HEADER: \usepackage{tabu,booktabs}
#+OPTIONS: toc:nil
#+TITLE: C++ IO support for various FEM exchange file formats

* Supported FEM file formats

Not all functionality defined for the exchange file formats is
supported. The supported subset is currently mainly defined by the
functionality supported in GLFrame rspt. the BMF file format.

More detailed information on supported functionality can be found in
the according directories in the doc dubdirectory.

** NASTRAN Bulk Data Format (BDF)

#+INCLUDE: "doc/bdf/ReadMe.org" :minlevel 3

** DNV GL Seasam Input Interface File (FEM)

#+INCLUDE: "doc/fem/ReadMe.org" :minlevel 3
