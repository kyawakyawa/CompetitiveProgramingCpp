#!/bin/bash

rm -rf cmake-build-debug

CC=clang CXX=clang++ cmake -Bcmake-build-debug -H. \
                           -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
                           -DCMAKE_BUILD_TYPE=Debug \
                           -DUSE_CCACHE=ON \
                           -DUSE_STACK_TRACE_LOGGER=ON \
                           -GNinja

mv cmake-build-debug/compile_commands.json .

