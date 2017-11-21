INCLUDE(FindLATEX)

# add a target to generate API documentation with Doxygen
FIND_PACKAGE(Doxygen)
FIND_PACKAGE(LATEX)
if(DOXYGEN_FOUND)
  CONFIGURE_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/header.tex.in
    ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex/header.tex @ONLY)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/.latexmkrc.in
    ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex/.latexmkrc)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/mydoxygen.sty.in
    ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex/mydoxygen.sty)
  ADD_CUSTOM_TARGET(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
  IF(LATEX_COMPILER)
    MESSAGE("LATEX FOUND")
    ADD_CUSTOM_TARGET(pdf
      latexmk -f refman
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxy/latex
      VERBATIM)
    ADD_DEPENDENCIES(pdf doc)
  ENDIF(LATEX_COMPILER)
ENDIF(DOXYGEN_FOUND)

# Local Variables:
# mode: cmake
# compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
# coding: utf-8
# End:
