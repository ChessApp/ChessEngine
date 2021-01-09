#!/bin/bash

docker run \
  -p 8000:8000 \
  --rm -it \
  amazon/dynamodb-local -jar DynamoDBLocal.jar -sharedDb
