#!/bin/bash

docker run --rm -it \
  -e DOCKER_LAMBDA_STAY_OPEN=1 \
  -p 9001:9001 \
  -v $(pwd)/mount:/var/task \
  lambci/lambda:provided \
  handler


