#!/bin/bash

PAYLOAD=$(cat request_payload.xml)

aws lambda invoke --endpoint http://localhost:9001 --no-sign-request \
  --function-name chess --payload "$PAYLOAD" output.json