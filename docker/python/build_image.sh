#!/bin/bash

IMAGE_VERSION=$(cat image.version)
docker build -t chessengine/python:$IMAGE_VERSION .