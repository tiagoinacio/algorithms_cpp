cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(algorithms_cpp)

set(CMAKE_CXX_FLAGS         "-Wall -Wreorder -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
set(CMAKE_CXX_FLAGS_DEBUG   "-g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    )

add_library(
    bublesort
    src/sorting/bublesort.cpp
    )

add_library(
    checkPermutation
    src/utils/strings/check-permutation.cpp
    )

add_library(
    isUnique
    src/utils/strings/is-unique.cpp
    )

set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
    unit-tests
    test/main.cpp
    test/sorting/bublesort.cpp
    test/utils/strings/is-unique.cpp
    test/data-structures/linked-list.cpp
    test/data-structures/array-list.cpp
    test/data-structures/string-builder.cpp
    test/data-structures/hash-table.cpp
    )

add_dependencies(unit-tests googletest)

target_link_libraries(
    unit-tests
    googletest
    bublesort
    isUnique
    checkPermutation
    pthread
    )

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit-tests)
