#!/bin/bash

docker run --rm -it -v $(pwd):/chessengine chess-engine/build:v1.0 ./chessengine/cmd.sh