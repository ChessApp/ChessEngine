#!/bin/bash
set -e

(
  mkdir -p code/build && cd code/build && \
  cmake3 ../Source -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=/out && \
  make && make aws-lambda-package-chessengine
)

if [ -d "docker/mount" ]; then
  rm -rf "docker/mount"
fi

unzip -qq code/build/chessengine.zip -d ./docker/mount
mkdir -p docker/mount/config && \
cp config/DefaultInitialState.xml docker/mount/config/GameState.xml