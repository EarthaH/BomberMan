#!/bin/bash

brew install cmake
brew install pkg-config
mkdir build
cd build
rm -rf CMakeCache.txt
cmake ../
make
mv bomberman ../