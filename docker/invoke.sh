#!/bin/bash

PAYLOAD=$1

aws lambda invoke --endpoint http://localhost:9001 --no-sign-request \
  --function-name chess --payload "$PAYLOAD" output.json