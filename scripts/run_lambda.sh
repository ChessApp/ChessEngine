#!/bin/bash

echo "Running lambda container..."

KEY=$(sed 's/aws_access_key_id = //' ~/.aws/credentials | sed -n 2p)
SECRET=$(sed 's/aws_secret_access_key = //' ~/.aws/credentials | sed -n 3p)

docker run \
  --rm -it \
  --network host \
  -e DOCKER_LAMBDA_STAY_OPEN=1 \
  -e AWS_ACCESS_KEY_ID=$KEY \
  -e AWS_SECRET_ACCESS_KEY=$SECRET \
  -p 9001:9001 \
  -v $(pwd)/docker/mount:/var/task \
  lambci/lambda:provided \
  handler


