#!/bin/bash
XML_HEADER="<?xml version="1.0"?>"
SEQUENCE_FILE="request_sequence.xml"

while IFS= read -r LINE; do
  PAYLOAD=$XML_HEADER$LINE
  echo "$PAYLOAD"
  aws lambda invoke \
    --endpoint http://localhost:9001 \
    --no-sign-request \
    --function-name chessengine \
    --payload "$PAYLOAD" outputs/invoke_lambda.json
done < $SEQUENCE_FILE
