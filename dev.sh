#!/bin/bash

# Terminate the process if any errors are detected
set -e

BUILD_IMAGE="chessengine/build:$(cat docker/image.version)"

source ./scripts/parse_input.sh $@

if [[ $REBUILD_DOCKER_OPTION == true || "$(docker images -q $BUILD_IMAGE 2> /dev/null)" == "" ]]; then
  echo "-- Building docker image: $BUILD_IMAGE";
  docker build -t $BUILD_IMAGE ./docker/; echo
fi

# Get the name of the current directory (not the path), which
# should be the name of the repo.
CURRENT_DIR=${PWD##*/}

if [ $START_LOCAL_DYNAMODB_OPTION == true ]; then
  scripts/start_db.sh
fi

if [ $CREATE_DB_TABLE_OPTION == true ]; then
  scripts/create_table.sh
fi

if [ $BUILD_OPTION == true ]; then
  (
    CMD_SCRIPT="scripts/build.sh"
    echo "Running docker container from image: $BUILD_IMAGE"
    docker run --rm -it -v $(pwd):/$CURRENT_DIR $BUILD_IMAGE $CMD_SCRIPT
  )
fi

# Create and run a container, mounting the repo at the root of the container.
if [ $RUN_OPTION == true ]; then
  scripts/run_lambda.sh
fi

