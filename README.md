[![Build Status](https://travis-ci.org/tiagoinacio/algorithms_cpp.svg?branch=master)](https://travis-ci.org/tiagoinacio/algorithms_cpp/builds)
[![Coverage Status](https://coveralls.io/repos/github/tiagoinacio/algorithms_cpp/badge.svg?branch=master)](https://coveralls.io/github/tiagoinacio/algorithms_cpp?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## How to build this demo

```sh
git clone https://github.com/tiagoinacio/algorithms_cpp.git --recursive
cd algorithms_cpp
mkdir build
cd build
cmake DCMAKE_BUILD_TYPE=Debug -G 'Unix Makefiles' ..
make -j 8
```


## Running the tests

Either using `make test`:
```
$ make test

Running tests...
Test project /home/user/algorithms_cpp/build
    Start 1: unit
1/1 Test #1: unit .............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```

Or directly using `unit_tests`:
```
$ ./unit_tests

[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from example
[ RUN      ] example.add
[       OK ] example.add (0 ms)
[ RUN      ] example.subtract
[       OK ] example.subtract (0 ms)
[----------] 2 tests from example (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.

```

## How to build NodeJS demos

You should already have NodeJS installed. If not, you can grab it [here](https://nodejs.org/en/).

```sh
git clone https://github.com/tiagoinacio/algorithms_cpp.git --recursive
cd algorithms_cpp/src/node/data-structures
npm -i -g node-gyp
node-gyp configure
node-gyp build
node linked-list.js
```
