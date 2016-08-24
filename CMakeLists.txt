# CMakeLists files in this project can
# refer to the root source directory of the project as ${EXTFEMIO_SOURCE_DIR} and
# to the root binary directory of the project as ${EXTFEMIO_BINARY_DIR}.
cmake_minimum_required(VERSION 2.8)
project(ExtFEMIO)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})


include(CTest)
include(add_catch_tests)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror --std=c++11")

set (MIN_BOOST_VERSION 1.54)
set (REQUIRED_BOOST_LIBS regex)
message("Searching for Boost...\n")
find_package(
  Boost
  ${MIN_BOOST_VERSION} REQUIRED
  COMPONENTS ${REQUIRED_BOOST_LIBS}
  )
INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES (boost/regex.hpp HAVE_BOOST_REGEX_HPP)
message("")

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/include/config.h.in ${CMAKE_SOURCE_DIR}/include/config.h)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Recurse into the "src", "test" and "doc" subdirectories. This does
# not actually cause another cmake executable to run. The same process
# will walk through the project's entire directory structure.
add_subdirectory(src)
add_subdirectory(tests)
#add_subdirectory(doc)
