# CMakeLists files in this project can
# refer to the root source directory of the project as ${EXTFEMIO_SOURCE_DIR} and
# to the root binary directory of the project as ${EXTFEMIO_BINARY_DIR}.
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ExtFEMIO)
SET(PROJECT_VERSION 0.4)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")

INCLUDE(CTest)
INCLUDE(cotire REQUIRED)

IF(MSVC)
  SET(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} /WX")
ELSEIF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Werror --std=c++11")
  IF(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
    SET(MIN_BOOST_VERSION 1.54)
    SET(REQUIRED_BOOST_LIBS regex)
    MESSAGE("Searching for Boost...\n")
    FIND_PACKAGE(
      Boost
      ${MIN_BOOST_VERSION} REQUIRED
      COMPONENTS ${REQUIRED_BOOST_LIBS}
      )
    INCLUDE(CheckIncludeFiles)
    CHECK_INCLUDE_FILES(boost/regex.hpp HAVE_BOOST_REGEX_HPP)
    MESSAGE("HAVE_BOOST_REGEX_HPP: ${HAVE_BOOST_REGEX_HPP}")
  ENDIF()
ENDIF()

INCLUDE(FindSubversion)
IF(Subversion_FOUND)
    Subversion_WC_INFO(${CMAKE_SOURCE_DIR} ExtFEMIO)
ELSE(Subversion_FOUND)
  SET(ExtFEMIO_WC_REVISION "???")
ENDIF(Subversion_FOUND)

CONFIGURE_FILE(
  ${CMAKE_SOURCE_DIR}/include/config.h.in
  ${CMAKE_SOURCE_DIR}/include/config.h)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

# Recurse into the "src", "test" and "doc" subdirectories. This does
# not actually cause another cmake executable to run. The same process
# will walk through the project's entire directory structure.
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
ADD_SUBDIRECTORY(docs)

# Local Variables:
# mode: cmake
# compile-command: "make -C cbuild -j8&&make -C cbuild test"
# coding: utf-8
# End:
