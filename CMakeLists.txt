# CMakeLists files in this project can refer to the root source
# directory of the project as ${EXTFEMIO_SOURCE_DIR} and to the root
# binary directory of the project as ${EXTFEMIO_BINARY_DIR}.
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ExtFEMIO)
SET(PROJECT_VERSION 0.6.1)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")

INCLUDE(CTest)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

IF(MSVC)
  INCLUDE(cotire REQUIRED)
  SET(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} /WX")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
  message(STATUS "MSVC: Enabled increased number of sections in object files")

ELSEIF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG")
  SET(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Werror --std=c++1y")
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
    ADD_DEFINITIONS("-DHAVE_BOOST_REGEX_HPP=${HAVE_BOOST_REGEX_HPP}")
  ENDIF()
ENDIF()

CONFIGURE_FILE(
  ${CMAKE_SOURCE_DIR}/include/config.h.in
  ${CMAKE_SOURCE_DIR}/include/config.h)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    MESSAGE( "64 bits compiler detected" )
    add_definitions(-D_X64)
else( CMAKE_SIZEOF_VOID_P EQUAL 8 ) 
    MESSAGE( "32 bits compiler detected" )
endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )

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
