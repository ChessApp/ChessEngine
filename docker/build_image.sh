#!/bin/bash

IMAGE_VERSION=$(cat image.version)
docker build -t chess-engine/build:$IMAGE_VERSION .