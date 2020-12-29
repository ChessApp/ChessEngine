#!/bin/bash

docker run --rm -it -v $(pwd):/chessengine chess-engine/build:v1.0 ./chessengine/cmd.sh

if [ -d "docker/mount" ]; then
  rm -rf "docker/mount"
fi

unzip ./code/build/chess.zip -d ./docker/mount