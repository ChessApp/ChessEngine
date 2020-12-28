#!/bin/bash

ls -al /out/lib64

cd aws-sdk/code

mkdir build
cd build
cmake3 .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=/out
make
make aws-lambda-package-hello

ls -al