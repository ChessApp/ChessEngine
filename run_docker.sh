#!/bin/bash

set -e

docker run --rm -it -v $(pwd):/chessengine chess-engine/build:v1.0 ./chessengine/cmd.sh

if [ -d "docker/mount" ]; then
  rm -rf "docker/mount"
fi

unzip -qq ./code/build/chess.zip -d ./docker/mount
mkdir -p docker/mount/config && cp config/DefaultInitialState.xml docker/mount/config/DefaultInitialState.xml

(cd docker && ./runtime.sh)