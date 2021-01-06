#!/bin/bash

aws dynamodb scan --table-name GameStates --endpoint-url http://localhost:8000 --region localhost
