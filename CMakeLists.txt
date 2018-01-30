cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(algorithms_cpp)

set(CMAKE_CXX_FLAGS         "-Wall -g3 -Wreorder -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
set(CMAKE_CXX_FLAGS_DEBUG   "-g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I external/GSL/include")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(
    utils-strings
    src/utils/strings/urlify.cpp
    src/utils/strings/check-permutation.cpp
    src/utils/strings/is-unique.cpp
    src/utils/strings/palindrome-permutation.cpp
    src/utils/strings/is-palindrome.cpp
    src/utils/strings/one-away.cpp
    src/utils/strings/string-compression.cpp
    src/utils/strings/rotate-matrix.cpp
    src/utils/strings/zero-matrix.cpp
    src/utils/strings/string-rotation.cpp
    )

add_library(
    utils-sort
    src/utils/sort/bublesort.cpp
    )

add_library(
    utils-bit-manipulation
    src/utils/bit-manipulation/is-number-even.cpp
    src/utils/bit-manipulation/is-number-odd.cpp
    src/utils/bit-manipulation/is-power-of-two.cpp
    )

set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")
set(GSL_ROOT external/GSL/ CACHE STRING "GSL source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )
include_directories(
    ${PROJECT_SOURCE_DIR}/${GSL_ROOT}
    ${PROJECT_SOURCE_DIR}/${GSL_ROOT}/include
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
    test/data-structures/array/array-list.cpp
    test/data-structures/array/string-builder.cpp
    test/data-structures/hash-table/hash-table-linked-list.cpp
    test/data-structures/hash-table/open-addressing.cpp
    test/data-structures/linked-list/linked-list-c.cpp
    test/data-structures/linked-list/linked-list.cpp
    test/data-structures/linked-list/singly-linked-list-with-tail.cpp
    test/data-structures/queue/queue-array.cpp
    test/data-structures/queue/queue-list.cpp
    test/data-structures/queue/queue-stack.cpp
    test/data-structures/stack/dynamic-multi-stack.cpp
    test/data-structures/stack/fixed-multi-stack.cpp
    test/data-structures/stack/stack-array-min.cpp
    test/data-structures/stack/stack-array.cpp
    test/data-structures/stack/stack-list.cpp
    test/data-structures/tree/binary-search-tree.cpp
    test/data-structures/tree/min-binary-heap.cpp
    test/utils/bit-manipulation/is-number-even.cpp
    test/utils/linked-list/delete-middle-node.cpp
    test/utils/linked-list/find-element-from-tail.cpp
    test/utils/linked-list/partition-around-value.cpp
    test/utils/linked-list/remove-duplicates.cpp
    test/utils/queue/animal-shelter.cpp
    test/utils/search/binary-search.cpp
    test/utils/sort/bublesort.cpp
    test/utils/stack/sort-stack.cpp
    test/utils/strings/check-permutation.cpp
    test/utils/strings/is-palindrome.cpp
    test/utils/strings/is-unique.cpp
    test/utils/strings/one-away.cpp
    test/utils/strings/palindrome-permutation.cpp
    test/utils/strings/rotate-matrix.cpp
    test/utils/strings/string-compression.cpp
    test/utils/strings/string-rotation.cpp
    test/utils/strings/urlify.cpp
    test/utils/strings/zero-matrix.cpp
    test/data-structures/tree/trie.cpp
    )

add_dependencies(unit-tests googletest)

target_link_libraries(
    unit-tests
    googletest
    pthread
    utils-sort
    utils-bit-manipulation
    utils-strings
    )

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit-tests)

add_custom_target(lint
    COMMAND python ../cpplint.py)

find_program(VALGRIND "valgrind")
if(VALGRIND)
    add_custom_target(valgrind
        COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --suppressions=../valgrind_suppress.txt --num-callers=20 --track-fds=yes ${PROJECT_BINARY_DIR}/unit-tests)
endif()
