#!/bin/bash

aws dynamodb put-item \
  --table-name "GameStates" \
  --item file://data.json \
  --endpoint-url "http://localhost:8000" \
  --region localhost
