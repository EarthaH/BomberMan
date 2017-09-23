#!/bin/bash

brew install cmake
brew install pkg-config
mkdir build
cd build
cmake ../
make
mv bomberman ../