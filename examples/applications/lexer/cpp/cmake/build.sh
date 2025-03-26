#!/bin/bash

EXE="lexer"
./clean.sh
cmake -B build
make -C build
mkdir bin
cp build/$EXE bin/
