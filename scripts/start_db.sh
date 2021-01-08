#!/bin/bash

KEY=$(sed -n 1p ../secrets/aws_credentials.secret)
SECRET=$(sed -n 2p ../secrets/aws_credentials.secret)

docker run \
  -p 8000:8000 \
  --rm -it \
  amazon/dynamodb-local -jar DynamoDBLocal.jar -sharedDb
