#!/bin/bash

XML_HEADER="<?xml version="1.0"?>"
if [[ $1 == '' ]]; then
  SEQUENCE_FILE="request_sequence.xml"
else
  SEQUENCE_FILE=$1
fi

while IFS= read -r LINE; do
  PAYLOAD=$XML_HEADER$LINE
  aws lambda invoke \
    --endpoint http://localhost:9001 \
    --no-sign-request \
    --function-name chessengine \
    --payload "$PAYLOAD" outputs/invoke_lambda.json
done < $SEQUENCE_FILE


if [[ $2 != '' ]]; then
  if cmp -- "$2" "outputs/invoke_lambda.json"; then
    exit 0
  else
    exit 1
  fi
fi

exit 0