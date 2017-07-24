#!/bin/sh
mkdir build
cd build
cmake ..
make
cd ..
echo "try running build/microdoom"
