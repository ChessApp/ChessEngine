#!/bin/bash

ARGS=$@

if [ -z $ARGS ]; then
  echo "No arguments provided. Exiting..."; exit 0;
fi

BUILD_OPTION=false
RUN_OPTION=false
START_LOCAL_DYNAMODB_OPTION=false
CREATE_DB_TABLE_OPTION=false
REBUILD_DOCKER_OPTION=false

for ARG in $ARGS
do
  case $ARG in
    --rebuild-docker | -rd)
      REBUILD_DOCKER_OPTION=true;;

    --create-table | -ct)
      CREATE_DB_TABLE_OPTION=true;;

    --build | -b)
      BUILD_OPTION=true;;

    --run | -r)
      BUILD_OPTION=true RUN_OPTION=true;;

    --dynamodb | -db)
      if [ $# == 1 ]; then
        START_LOCAL_DYNAMODB_OPTION=true
      else
        (RED=`tput setaf 1` && echo "${RED}$ARG must be run on its own with no other flags."); exit 1
      fi
      ;;

    *) (RED=`tput setaf 1` && echo "${RED}Unrecognized script argument: $ARG"); exit 1;;
  esac
done