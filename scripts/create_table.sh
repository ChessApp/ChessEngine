#!/bin/bash

TABLE_NAME="GameStates"
ATTRIBUTE_DEFINITIONS="AttributeName=id,AttributeType=S"
KEY_SCHEMA="AttributeName=id,KeyType=HASH"
PROVISIONED_THROUGHPUT="ReadCapacityUnits=5,WriteCapacityUnits=5"
REGION="localhost"
ENDPOINT_URL="http://${REGION}:8000"


echo "Creating table in local DynamoDB instance:"
echo "  --table-name $TABLE_NAME"
echo "  --attribute-definitions $ATTRIBUTE_DEFINITIONS"
echo "  --key-schema $KEY_SCHEMA"
echo "  --provisioned-throughput $PROVISIONED_THROUGHPUT"
echo "  --region $REGION"
echo "  --endpoint-url $ENDPOINT_URL"
echo

aws dynamodb create-table \
   --table-name $TABLE_NAME \
   --attribute-definitions $ATTRIBUTE_DEFINITIONS \
   --key-schema $KEY_SCHEMA \
   --provisioned-throughput $PROVISIONED_THROUGHPUT \
   --region $REGION \
   --endpoint-url $ENDPOINT_URL

echo
echo "Listing table from local DynamoDB instance:"
echo "  --region $REGION"
echo "  --endpoint-url $ENDPOINT_URL"
echo

aws dynamodb list-tables \
    --region $REGION \
    --endpoint-url $ENDPOINT_URL