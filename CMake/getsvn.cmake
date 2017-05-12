INCLUDE(FindSubversion)
Subversion_WC_INFO(${SOURCE_DIR} MY)
FILE(WRITE ${SOURCE_DIR}/svnversion.h.txt "#pragma once\n#ifndef SVNVERSION\n#define SVNVERSION ${MY_WC_REVISION}\n#endif\n")
EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${SOURCE_DIR}/svnversion.h.txt ${SOURCE_DIR}/svnversion.h)
