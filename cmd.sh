#!/bin/bash

cd chessengine/code

mkdir build
cd build

cmake3 .. -DCMAKE_BUILD_TYPE=Release
pwd
make

./chess DefaultInitialState.xml
