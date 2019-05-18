[![Build Status](https://travis-ci.com/berhoel/ExtFEMIO.svg?branch=master)](https://travis-ci.com/berhoel/ExtFEMIO)

# Table of Contents

1.  [Supported FEM file formats](#org483e2ff)
    1.  [Unit system considerations](#orga70a97c)
    2.  [NASTRAN Bulk Data Format (BDF)](#orge4b4d58)
        1.  [BDF Cards supported](#orgc55002e)
            1.  [Bulk Data](#org5b9f41f)
            2.  [Header Data](#org934fba6)
    3.  [DNV GL Seasam Input Interface File (FEM)](#org288fb51)
        1.  [FEM Cards supported](#org46effbe)
        2.  [Element Types in SESAM](#org2e62dc0)



<a id="org483e2ff"></a>

# Supported FEM file formats

Not all functionality defined for the exchange file formats is
supported. The supported subset is currently mainly defined by the
functionality supported in GLFrame rspt. the BMF file format.

More detailed information on supported functionality can be found in
the according directories in the `docs` subdirectory.


<a id="orga70a97c"></a>

## Unit system considerations

Unit systems used by the different systems are:

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">Dimension \\ System</th>
<th scope="col" class="org-left">Poseidon</th>
<th scope="col" class="org-left">Nastran</th>
<th scope="col" class="org-left">Sesam / GeniE</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">L (Length Unit)</td>
<td class="org-left">[m] for nodes</td>
<td class="org-left">[m]</td>
<td class="org-left">[m]</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">[mm] for plate thicknesses</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">M (Mass Unit)</td>
<td class="org-left">[t]</td>
<td class="org-left">[t]</td>
<td class="org-left">[t]</td>
</tr>


<tr>
<td class="org-left">ML/T² Force Unit)</td>
<td class="org-left">[kN]</td>
<td class="org-left">[kN]</td>
<td class="org-left">[kN]</td>
</tr>
</tbody>
</table>

Yield stress is stored in [kN/m²] in Sesam / GeniE, but [N/mm²] in POSEIDON.


<a id="orge4b4d58"></a>

## NASTRAN Bulk Data Format (BDF)


<a id="orgc55002e"></a>

### BDF Cards supported


<a id="org5b9f41f"></a>

#### Bulk Data

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-left">**Name**</th>
<th scope="col" class="org-left">**Description**</th>
<th scope="col" class="org-left">**Read**</th>
<th scope="col" class="org-left">**Write**</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">General</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`MAT1`</td>
<td class="org-left">Material definition</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`MAT2`</td>
<td class="org-left">Shell Element Anisotropic Material Property Definition</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GRID`</td>
<td class="org-left">Grid nodes</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Elements</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CTRIA3`</td>
<td class="org-left">3 node shaped shell elements</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CQUAD4`</td>
<td class="org-left">4 node shaped shell elements</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CBEAM`</td>
<td class="org-left">Complex beams <sup><a id="fnr.1" class="footref" href="#fn.1">1</a></sup></td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CBAR`</td>
<td class="org-left">Simple beams</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CROD`</td>
<td class="org-left">Trusses</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CBUSH`</td>
<td class="org-left">Generalized Spring-and-Damper Connection</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Element</td>
<td class="org-left">properties</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PSHELL`</td>
<td class="org-left">Properties for `CTRIA3`, and `CQUAD4`</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PBEAM`</td>
<td class="org-left">Integral properties for `CBEAM`</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PBEAML`</td>
<td class="org-left">Properties for `CBEAM` describing cross section</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PBAR`</td>
<td class="org-left">Integral properties for `CBAR`</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PBARL`</td>
<td class="org-left">Properties for `CBAR` describing cross section</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PROD`</td>
<td class="org-left">Properties for `CROD`</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PBUSH`</td>
<td class="org-left">Generalized Spring-and-Damper Property</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Load</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`LOAD`</td>
<td class="org-left">Load case combination</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`FORCE`</td>
<td class="org-left">Forces on Nodes</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`MOMENT`</td>
<td class="org-left">Moments on Nodes</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CONM1`</td>
<td class="org-left">Concentrated Mass Element Connection, General Form</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CMASS2`</td>
<td class="org-left">Scalar Mass Property and Connection</td>
<td class="org-left">✓</td>
<td class="org-left">✗</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`CMASS4`</td>
<td class="org-left">Scalar Mass Property and Connection to Scalar Points Only</td>
<td class="org-left">✓</td>
<td class="org-left">✗</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GRAV`</td>
<td class="org-left">Acceleration or Gravity Load</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Misc</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`ENDDATA`</td>
<td class="org-left">Marker for end of input file</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`PARAM`</td>
<td class="org-left">Specifies values for parameters used in solution sequences or user written `DMAP` programs.</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
</tr>
</tbody>
</table>


<a id="org934fba6"></a>

#### Header Data

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">**Name**</th>
<th scope="col" class="org-left">**Description**</th>
<th scope="col" class="org-left">**Read**</th>
<th scope="col" class="org-left">**Write**</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">`SOL`</td>
<td class="org-left">Execute a Solution Sequence</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`CEND`</td>
<td class="org-left">End of Executive Control Delimiter</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`TITLE`</td>
<td class="org-left">Output Title</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`ECHO`</td>
<td class="org-left">Bulk Data Echo Request</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`DISPLACEMENT`</td>
<td class="org-left">Displacement Output Request</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`SPCFORCES`</td>
<td class="org-left">Single-Point Forces of Constraint Output Request</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`STRESS`</td>
<td class="org-left">Element Stress Output Request</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`LOAD`</td>
<td class="org-left">External Static Load Set Selection</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`SUBTITLE`</td>
<td class="org-left">Output Subtitle</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`SUBCASE`</td>
<td class="org-left">Subcase Delimiter</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>


<tr>
<td class="org-left">`BEGIN` `BULK`</td>
<td class="org-left">Case Control and Bulk Data Delimiter</td>
<td class="org-left">✗</td>
<td class="org-left">✓</td>
</tr>
</tbody>
</table>


<a id="org288fb51"></a>

## DNV GL Seasam Input Interface File (FEM)



<a id="org46effbe"></a>

### FEM Cards supported

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>

<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>

<colgroup>
<col  class="org-right" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-left">**Name**</th>
<th scope="col" class="org-left">**Description**</th>
<th scope="col" class="org-left">**Read**</th>
<th scope="col" class="org-left">**Write**</th>
<th scope="col" class="org-right">**Page<sup><a id="fnr.2" class="footref" href="#fn.2">2</a></sup>**</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">General</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`DATE`</td>
<td class="org-left">Date and Program Information</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">4-2</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GCOORD`</td>
<td class="org-left">Nodal Coordinates</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-56</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GNODE`</td>
<td class="org-left">Correspondence between External and Internal Node Numbering, and Number of Degrees of Freedom of Each Node</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-80</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`IDENT`</td>
<td class="org-left">Identification of Superelements</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">4-3</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`IEND`</td>
<td class="org-left">End of a Superelement</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">4-4</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Elements</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GELMNT1`</td>
<td class="org-left">Element Data Definition</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-65</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GELREF1`</td>
<td class="org-left">Reference to Element Data</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-66</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Element</td>
<td class="org-left">properties</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GBEAMG`</td>
<td class="org-left">General Beam Element Data</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-49</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GBARM`</td>
<td class="org-left">Cross Section Type Massive Bar</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-48</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GIORH`</td>
<td class="org-left">Cross Section Type I or H Beam</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-71</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GLSEC`</td>
<td class="org-left">Cross Section Type L-Section</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-76</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GPIPE`</td>
<td class="org-left">Cross Section Type Tube</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-81</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GUSYI`</td>
<td class="org-left">Cross Section Type Unsymmetrical I-Beam</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-93</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GECCEN`</td>
<td class="org-left">Eccentricities</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-61</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BELFIX`</td>
<td class="org-left">Flexible Joint/Hinge</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-8</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GELTH`</td>
<td class="org-left">Thickness of Two-dimensional Elements</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-70</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Load</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BLDEP`</td>
<td class="org-left">Nodes with Linear Dependence</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-27</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BNBCD`</td>
<td class="org-left">Nodes with Boundary Conditions</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-30</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BNDISPL`</td>
<td class="org-left">Nodes with Prescribed Displacements and Accelerations</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-31</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BNLOAD`</td>
<td class="org-left">Nodes with Loads</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-35</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`MGSPRNG`</td>
<td class="org-left">Element to Ground</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-103</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`TDLOAD`</td>
<td class="org-left">**not documented** (Seems to be similar to `TDMATER` or `TDSETNAM`)</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BEUSLO`</td>
<td class="org-left">Elements with Surface Loads</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-21</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Superel.</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`BSELL`</td>
<td class="org-left">Subelement Load Description</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">7-27</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GELMNT2`</td>
<td class="org-left">Subelement Description with Simple Correspondence</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">7-31</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`HSUPSTAT`</td>
<td class="org-left">Superelement Statistical Information</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">7-40</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`HSUPTRAN`</td>
<td class="org-left">Superelement Transformations</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">7-41</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`HIERARCH`</td>
<td class="org-left">Superelement Hierarchy Description</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">7-38</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`TDSUPNAM`</td>
<td class="org-left">Name and Description of a Super-Element.</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">4-8</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Misc</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GSETMEMB`</td>
<td class="org-left">Set (group) of Nodes or Elements (Members)</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-84</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`GUNIVEC`</td>
<td class="org-left">Specification of Local Element Coordinate System</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-92</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`MISOSEL`</td>
<td class="org-left">Isotropy, Linear Elastic Structural Analysis</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-115</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`MORSMEL`</td>
<td class="org-left">Anisotropy, Linear Elastic Structural Analysis, 2-D Membrane Elements and 2-D Thin Shell Elements</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">6-117</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`TDSETNAM`</td>
<td class="org-left">Name and Description of a Set (group)</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">4-7</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">`TEXT`</td>
<td class="org-left">User supplied Text</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-right">4-10</td>
</tr>
</tbody>
</table>


<a id="org2e62dc0"></a>

### Element Types in SESAM

Conventions for use of the interface file for the elements in SESAM
are defined here. Other element types may be introduced for use in
other programs.

The table below contains element type numbers already reserved. (Not
all of them are included in SESAM).

For ADVANCE, the element types listed are those available from the
SESAM preprocessors. In addition to that ADVANCE has a lot of other
element types.

<table id="orgd4e34e9" border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
<caption class="t-above"><span class="table-number">Table 1:</span> List of existing Element Types</caption>

<colgroup>
<col  class="org-right" />
</colgroup>

<colgroup>
<col  class="org-left" />

<col  class="org-right" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>

<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-right">**Typ<sup><a id="fnr.3" class="footref" href="#fn.3">3</a></sup>**</th>
<th scope="col" class="org-left">**Name**</th>
<th scope="col" class="org-right">**N.<sup><a id="fnr.4" class="footref" href="#fn.4">4</a></sup>**</th>
<th scope="col" class="org-left">**Description of Element**</th>
<th scope="col" class="org-left">**Ref.**</th>
<th scope="col" class="org-left">**<sup><a id="fnr.5" class="footref" href="#fn.5">5</a></sup>**</th>
<th scope="col" class="org-left">**<sup><a id="fnr.6" class="footref" href="#fn.6">6</a></sup>**</th>
<th scope="col" class="org-left">**<sup><a id="fnr.7" class="footref" href="#fn.7">7</a></sup>**</th>
<th scope="col" class="org-left">**<sup><a id="fnr.8" class="footref" href="#fn.8">8</a></sup>**</th>
<th scope="col" class="org-left">**<sup><a id="fnr.9" class="footref" href="#fn.9">9</a></sup>**</th>
<th scope="col" class="org-left">**Other<sup><a id="fnr.10" class="footref" href="#fn.10">10</a></sup>**</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-right">1</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">2</td>
<td class="org-left">`BEPS`</td>
<td class="org-right">2</td>
<td class="org-left">2-D, 2 Node Beam</td>
<td class="org-left">3, 5</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">3</td>
<td class="org-left">`CSTA`</td>
<td class="org-right">3</td>
<td class="org-left">Plane Constant Strain Triangle</td>
<td class="org-left">2, 4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">4</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">3</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">5</td>
<td class="org-left">`RPBQ`</td>
<td class="org-right">4</td>
<td class="org-left">Rectangular Plate. Bending Modes</td>
<td class="org-left">3</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">6</td>
<td class="org-left">`ILST`</td>
<td class="org-right">6</td>
<td class="org-left">Plane Lin. Strain Triangle</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">7</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">8</td>
<td class="org-left">`IQQE`</td>
<td class="org-right">8</td>
<td class="org-left">Plane Quadrilateral Membrane Element</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">9</td>
<td class="org-left">`LQUA`</td>
<td class="org-right">4</td>
<td class="org-left">Plane Quadrilateral Membrane Element</td>
<td class="org-left">2, 4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">10</td>
<td class="org-left">`TESS`</td>
<td class="org-right">2</td>
<td class="org-left">Truss Element</td>
<td class="org-left">2, 4</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">11</td>
<td class="org-left">`GMAS`</td>
<td class="org-right">1</td>
<td class="org-left">1-Noded Mass-Matrix</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✗</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">12</td>
<td class="org-left">`GLMA`</td>
<td class="org-right">2</td>
<td class="org-left">2-Noded Mass-Matrix</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">13</td>
<td class="org-left">`GLDA`</td>
<td class="org-right">2</td>
<td class="org-left">2-Noded Damping-Matrix</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">14</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">15</td>
<td class="org-left">`BEAS`</td>
<td class="org-right">2</td>
<td class="org-left">3-D, 2 Node Beam</td>
<td class="org-left">2, 4</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">FR, LA, PL, PR, WA</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-right">16</td>
<td class="org-left">`AXIS`</td>
<td class="org-right">2</td>
<td class="org-left">Axial Spring</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓<sup><a id="fnr.11" class="footref" href="#fn.11">11</a></sup></td>
<td class="org-left">✗</td>
<td class="org-left">FR</td>
</tr>


<tr>
<td class="org-right">17</td>
<td class="org-left">`AXDA`</td>
<td class="org-right">2</td>
<td class="org-left">Axial Damper</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✗</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">18</td>
<td class="org-left">`GSPR`</td>
<td class="org-right">1</td>
<td class="org-left">Spring to Ground</td>
<td class="org-left">4</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✗</td>
<td class="org-left">FR</td>
</tr>


<tr>
<td class="org-right">19</td>
<td class="org-left">`GDAM`</td>
<td class="org-right">1</td>
<td class="org-left">Damper to Ground</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✗</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">20</td>
<td class="org-left">`IHEX`</td>
<td class="org-right">20</td>
<td class="org-left">Isoparametric Hexahedron</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">FR</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-right">21</td>
<td class="org-left">`LHEX`</td>
<td class="org-right">8</td>
<td class="org-left">Linear Hexahedron</td>
<td class="org-left">2, 4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">FR</td>
</tr>


<tr>
<td class="org-right">22</td>
<td class="org-left">`SECB`</td>
<td class="org-right">3</td>
<td class="org-left">Subparametric Curved Beam</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">23</td>
<td class="org-left">`BTSS`</td>
<td class="org-right">3</td>
<td class="org-left">General Curved Beam</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PL, PR</td>
</tr>


<tr>
<td class="org-right">24</td>
<td class="org-left">`FQUS`</td>
<td class="org-right">4</td>
<td class="org-left">Flat Quadrilateral Thin Shell</td>
<td class="org-left">4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">PL, PR</td>
</tr>


<tr>
<td class="org-right">24</td>
<td class="org-left">`FFQ`</td>
<td class="org-right">4</td>
<td class="org-left">Free Formulation Quadrilateral Shell</td>
<td class="org-left">5</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">25</td>
<td class="org-left">`FTRS`</td>
<td class="org-right">3</td>
<td class="org-left">Flat Triangular Thin Shell</td>
<td class="org-left">4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">PL</td>
</tr>


<tr>
<td class="org-right">25</td>
<td class="org-left">`FFTR`</td>
<td class="org-right">3</td>
<td class="org-left">Free Formulation Triangular Shell</td>
<td class="org-left">5</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">26</td>
<td class="org-left">`SCTS`</td>
<td class="org-right">6</td>
<td class="org-left">Subparametric Curved Triangular Thick Shell</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PL</td>
</tr>


<tr>
<td class="org-right">27</td>
<td class="org-left">`MCTS`</td>
<td class="org-right">6</td>
<td class="org-left">Subparametric Curved Triangular Thick Sandwich Element</td>
<td class="org-left">2<sup><a id="fnr.12" class="footref" href="#fn.12">12</a></sup></td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">28</td>
<td class="org-left">`SCQS`</td>
<td class="org-right">8</td>
<td class="org-left">Subparametric Curved Quadrilateral Thick Shell</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PL, PR</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-right">29</td>
<td class="org-left">`MCQS`</td>
<td class="org-right">8</td>
<td class="org-left">Subparam. Curved Quadr. Thick Sandwich Elem.</td>
<td class="org-left">2<sup><a id="fnr.12.100" class="footref" href="#fn.12">12</a></sup></td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">30</td>
<td class="org-left">`IPRI`</td>
<td class="org-right">15</td>
<td class="org-left">Isoparametric Triangular Prism</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">31</td>
<td class="org-left">`ITET`</td>
<td class="org-right">10</td>
<td class="org-left">Isoparametric Tetrahedron</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">32</td>
<td class="org-left">`TPRI`</td>
<td class="org-right">6</td>
<td class="org-left">Triangular Prism</td>
<td class="org-left">2, 4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">33</td>
<td class="org-left">`TETR`</td>
<td class="org-right">4</td>
<td class="org-left">Tetrahedron</td>
<td class="org-left">2</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">34</td>
<td class="org-left">`LCTS`</td>
<td class="org-right">6</td>
<td class="org-left">Subparam. Layered Curved Triangular Thick Shell</td>
<td class="org-left">2<sup><a id="fnr.12.100" class="footref" href="#fn.12">12</a></sup></td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">35</td>
<td class="org-left">`LCQS`</td>
<td class="org-right">8</td>
<td class="org-left">Subparam. Layered Curved Quadrilat. Thick Shell</td>
<td class="org-left">2<sup><a id="fnr.12.100" class="footref" href="#fn.12">12</a></sup></td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-right">36</td>
<td class="org-left">`TRS1`</td>
<td class="org-right">18</td>
<td class="org-left">2nd Order Hexahed. Transition Elem., Solid / Shell</td>
<td class="org-left">6</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>


<tr>
<td class="org-right">37</td>
<td class="org-left">`TRS2`</td>
<td class="org-right">15</td>
<td class="org-left">2nd Order Hexahed. Transition Elem., Solid / Shell</td>
<td class="org-left">6</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>


<tr>
<td class="org-right">38</td>
<td class="org-left">`TRS3`</td>
<td class="org-right">12</td>
<td class="org-left">2nd Order Hexahed. Transition Elem., Solid / Shell</td>
<td class="org-left">6</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-right">39</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">40</td>
<td class="org-left">`GLSH`</td>
<td class="org-right">2</td>
<td class="org-left">General Spring / Shim Element</td>
<td class="org-left"><sup><a id="fnr.13" class="footref" href="#fn.13">13</a></sup></td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✗</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">41</td>
<td class="org-left">`AXCS`</td>
<td class="org-right">3</td>
<td class="org-left">Axisymmetric Constant Strain Triangle</td>
<td class="org-left">7, 5</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">42</td>
<td class="org-left">`AXLQ`</td>
<td class="org-right">4</td>
<td class="org-left">Axisymmetric Quadrilateral</td>
<td class="org-left">7, 5</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">43</td>
<td class="org-left">`AXLS`</td>
<td class="org-right">6</td>
<td class="org-left">Axisymmetric Linear Strain Triangle</td>
<td class="org-left">7</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">44</td>
<td class="org-left">`AXQQ`</td>
<td class="org-right">8</td>
<td class="org-left">Axisymmetric Linear Strain Quadrilateral</td>
<td class="org-left">7</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">45</td>
<td class="org-left">`PILS`</td>
<td class="org-right">1</td>
<td class="org-left">Pile / Soil</td>
<td class="org-left">4</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">46</td>
<td class="org-left">`PCAB`</td>
<td class="org-right">2</td>
<td class="org-left">Plane Cable-Bar Element</td>
<td class="org-left">4</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">47</td>
<td class="org-left">`PSPR`</td>
<td class="org-right">1</td>
<td class="org-left">Plane Spring Element</td>
<td class="org-left">4</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">48</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">4</td>
<td class="org-left">4-node Contact Element with triangular Shape</td>
<td class="org-left">4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">49</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">2</td>
<td class="org-left">2-Noded Link Element</td>
<td class="org-left">4</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">50</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">51</td>
<td class="org-left">`CTCP`</td>
<td class="org-right">2</td>
<td class="org-left">2-Noded Contact Element</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">52</td>
<td class="org-left">`CTCL`</td>
<td class="org-right">4</td>
<td class="org-left">4-Noded Contact Element</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">53</td>
<td class="org-left">`CTAL`</td>
<td class="org-right">4</td>
<td class="org-left">4-Noded Axisymmetric Contact Element</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">54</td>
<td class="org-left">`CTCC`</td>
<td class="org-right">6</td>
<td class="org-left">6-Noded Contact Element</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">55</td>
<td class="org-left">`CTAQ`</td>
<td class="org-right">6</td>
<td class="org-left">6-Noded (3+3) Axisymmetric Contact Element</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">56</td>
<td class="org-left">`CTLQ`</td>
<td class="org-right">8</td>
<td class="org-left">8-Noded (4+4) Contact Element</td>
<td class="org-left">8, 9</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>


<tr>
<td class="org-right">57</td>
<td class="org-left">`CTCQ`</td>
<td class="org-right">16</td>
<td class="org-left">16-Noded (8+8) Contact Element</td>
<td class="org-left">8, 9</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>


<tr>
<td class="org-right">58</td>
<td class="org-left">`CTMQ`</td>
<td class="org-right">18</td>
<td class="org-left">18-Noded (9+9) Contact Element</td>
<td class="org-left">8, 9</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>


<tr>
<td class="org-right">59</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">60</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">61</td>
<td class="org-left">`HCQS`</td>
<td class="org-right">9</td>
<td class="org-left">9-Noded Shell Element</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">PR</td>
</tr>


<tr>
<td class="org-right">62</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">63</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">64</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">65</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">66</td>
<td class="org-left">`SLQS`</td>
<td class="org-right">8</td>
<td class="org-left">Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">67</td>
<td class="org-left">`SLTS`</td>
<td class="org-right">6</td>
<td class="org-left">Semiloof Triangular Curved Thin Shell (24 d.o.fs)</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">68</td>
<td class="org-left">`SLCB`</td>
<td class="org-right">3</td>
<td class="org-left">Semiloof Curved Beam (11 d.o.fs)</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">69</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">*Not* *yet* *defined*</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">70</td>
<td class="org-left">`MATR`</td>
<td class="org-right">*n*</td>
<td class="org-left">General Matrix Element with arbitrary no. of nodes (*n*)</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">SP</td>
</tr>


<tr>
<td class="org-right">&hellip;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">100</td>
<td class="org-left">`GHEX`</td>
<td class="org-right">21</td>
<td class="org-left">General Hexahedron</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">&hellip;</td>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-right">163</td>
<td class="org-left">`GHEX`</td>
<td class="org-right">27</td>
<td class="org-left">General Hexahedron</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">✓</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>
</tbody>
</table>


# Footnotes

<sup><a id="fn.1" href="#fnr.1">1</a></sup> Twisting `CBEAM` cross section by using the `BIT` flag is
not supported. Offset via `OFFT` is only supported for the same offset
at *A* and *B* end of beam.

<sup><a id="fn.2" href="#fnr.2">2</a></sup> References page in "Technical Report: Sesam Input Interface File,
File Description", Document id: 89-7012, Revision Number 9 / 01

<sup><a id="fn.3" href="#fnr.3">3</a></sup> `ELTYP`

<sup><a id="fn.4" href="#fnr.4">4</a></sup> Number of nodes

<sup><a id="fn.5" href="#fnr.5">5</a></sup> Indcluded in program `PREFRAME`

<sup><a id="fn.6" href="#fnr.6">6</a></sup> Included in program `PREFEM`

<sup><a id="fn.7" href="#fnr.7">7</a></sup> Included in program `SESTRA`

<sup><a id="fn.8" href="#fnr.8">8</a></sup> Included in program `ADVANCE`

<sup><a id="fn.9" href="#fnr.9">9</a></sup> Included in program `Poseidon`

<sup><a id="fn.10" href="#fnr.10">10</a></sup> **FR** = FRAMEWORK, **LA** = LAUNCH, **PL** = PLATEWORK, **PR** =
PRETUBE, **SP** = SPLICE, **WD** = WADAM, **WJ** = WAJAC

<sup><a id="fn.11" href="#fnr.11">11</a></sup> Temporarily `ADVANCE` interprets Axisl Spring as link
element, ignoring the material reference. The 6 matrix numbers are
given in direct input to `ADVANCE`.

<sup><a id="fn.12" href="#fnr.12">12</a></sup> The element subroutines are the same as for the
subparametric curved thick shells (`SCQS` and `SCTS`).

<sup><a id="fn.13" href="#fnr.13">13</a></sup> As General Spring it is just a 2-noded spring (12x12
matrix) which may be in a local coordinate system. As a shim element
the preprocessor(s) will only insert stiffness in the local x- and
y-direction. In the analysis program(s), shim members and general
springs are treated exactly in the same manner.
