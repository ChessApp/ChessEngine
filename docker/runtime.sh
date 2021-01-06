#!/bin/bash

KEY=$(sed -n 1p ../secrets/aws_credentials.secret)
SECRET=$(sed -n 2p ../secrets/aws_credentials.secret)

docker run \
  --rm -it \
  --network host \
  -e DOCKER_LAMBDA_STAY_OPEN=1 \
  -e AWS_ACCESS_KEY_ID=$KEY \
  -e AWS_SECRET_ACCESS_KEY=$SECRET \
  -p 9001:9001 \
  -v $(pwd)/mount:/var/task \
  lambci/lambda:provided \
  handler


