#!/bin/bash

docker run --rm -it -v $(pwd):/aws-sdk chessengine/aws-sdk:v1.0 ./aws-sdk/cmd.sh