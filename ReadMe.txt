# -*- mode: org -*-
#+LATEX_CLASS: dnvglartcl
#+LATEX_HEADER: \usepackage{tabu,booktabs}
#+OPTIONS: toc:nil
#+TITLE: Nastran Bulk Data Import for Poseidon

* BDF Cards supported

  #+ATTR_LATEX: :booktabs :environment tabu :align @{}lp{5em}Xc@{} :width \textwidth :float nil
  |          | *Name*     | *Description*                                   | *Done* |
  |----------+------------+-------------------------------------------------+--------|
  | General  |            |                                                 |        |
  |          | =MAT1=     | Material definition                             | \check |
  |          | =GRID=     | Grid nodes                                      | \check |
  | Elements |            |                                                 |        |
  |          | =CTRIA3=   | 3 node shaped shell elements                    | \check |
  |          | =CQUAD4=   | 4 node shaped shell elements                    | \check |
  |          | =CBEAM=    | Complex beams                                   | \check |
  |          | =CBAR=     | Simple beams                                    | \check |
  |          | =CROD=     | Trusses                                         | \check |
  | Element  | properties |                                                 |        |
  |          | =PSHELL=   | Properties for =CTRIA3=, and =CQUAD4=           | \check |
  |          | =PBEAM=    | Integral properties for =CBEAM=                 | \check |
  |          | =PBEAML=   | Properties for =CBEAM= describing cross section | \check |
  |          | =PBAR=     | Integral properties for =CBAR=                  | \check |
  |          | =PBARL=    | Properties for =CBAR= describing cross section  | \check |
  |          | =PROD=     | Properties for =CROD=                           | \check |
  | Misc     |            |                                                 |        |
  |          | =ENDDATA=  | Marker for end of input file                    | \check |
  |          |            |                                                 |        |

* Writing support for Poseidon

  #+ATTR_LATEX: :booktabs :environment tabu :align @{}llXc@{} :width \textwidth :float nil
  |             | *Entry*             | *Description*                            | *Done* |
  |-------------+---------------------+------------------------------------------+--------|
  |             |                     | <40>                                     | <c6>   |
  | Properties  |                     |                                          |        |
  |             | beam properties     | This is probably quite tricky, because in general the beam cross section information in =BDF= files is given as description of the cross section geometry which probably has to be converted to integral values. | \check |
  |             | group information   |                                          | \check |
  | Elements    |                     |                                          |        |
  |             | Shell               |                                          | \check |
  |             | PSE                 |                                          | \check |
  |             | Truss               |                                          | \check |
  |             | Beam                |                                          | \check |
  |             | Boundary Elements   |                                          |        |
  | Group Info. |                     |                                          |        |
  |             | NAPA CSV file       | contains also yield stress informaton    | \check |
  |             | Patran session file | does not contain yield stress information |        |
