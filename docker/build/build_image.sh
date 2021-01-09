#!/bin/bash

IMAGE_VERSION=$(cat image.version)
docker build -t chessengine/build:$IMAGE_VERSION .