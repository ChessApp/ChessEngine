#!/bin/bash

PAYLOAD=$(cat inputs/invoke_payload.xml)

aws lambda invoke \
  --endpoint http://localhost:9001 \
  --no-sign-request \
  --function-name chessengine \
  --payload "$PAYLOAD" outputs/invoke_lambda.json