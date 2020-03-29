#!/bin/bash

# this allows exit codes to be passed through pipes
set -o pipefail

SOURCE_DIR="../code/Source"
SOURCE_FILES_LIST="sourceFiles.list"
EXCLUDE_FILES_LIST="excludeFiles.list"
FORCE_INCLUDE_FILES="forceIncludeFiles.list"
EXCLUDE_FILES_FULL_LIST="excludeFilesFull.list"
BUILD_OUTPUT_FILE=""
TARGET_EXEC="chess-all"

BUILD_JOBS=
RUN_BUILD=false
RUN_CLEAN=false
RUN_FILE_GEN=false
RUN_BUILD_OUTPUT=false
PRINT_HELP_CMD=false
ADD_OUTPUT_TRACE=false
TRACE_FLAG=""
DEBUG_BUILD=0
BUILD_SUCCESS=false
if [ -x "$(command -v ccze)" ]; then
    ENABLE_COLOR=true
else
    ENABLE_COLOR=false
fi;

SHORT=j:bcrtdxg
LONG=jobs:,build,clean,rebuild,trace,debug,help,gen,no-color,run
OPTS=$(getopt --options $SHORT --long $LONG --name "$0" -- "$@")

if [[ $# -eq 0 ]]; then
    echo "running default incremental build with all CPUs available..."
    RUN_BUILD=true
    RUN_FILE_GEN=true
fi;

eval set -- "$OPTS" -s

while (( "$#" )); do
  case "$1" in
     --jobs | -j ) BUILD_JOBS="$2" RUN_BUILD=true
        re='^[0-9]+$'
        if ! [[ $BUILD_JOBS =~ $re ]]; then
            echo "error: Expected a number after $1 option (\"$2\" was detected)"
            PRINT_HELP_CMD=true
        fi;
        shift;;

     --build   | -b ) RUN_BUILD=true RUN_FILE_GEN=true;;
     --clean   | -c ) RUN_CLEAN=true;;
     --rebuild | -r ) RUN_BUILD=true RUN_CLEAN=true RUN_FILE_GEN=true;;
     --trace   | -t ) TRACE_FLAG='TRACE=1' RUN_BUILD=true RUN_FILE_GEN=true;;
     --debug   | -d ) DEBUG_BUILD=1 RUN_BUILD=true RUN_FILE_GEN=true;;
     --gen     | -g ) RUN_FILE_GEN=true;;
     --no-color     ) ENABLE_COLOR=false RUN_BUILD=true RUN_FILE_GEN=true;;
     --run          ) RUN_BUILD_OUTPUT=true RUN_BUILD=true RUN_FILE_GEN=true;;
     --help )         PRINT_HELP_CMD=true;;
     -- )             shift; break;;
     *)               echo "Unrecognized option: $1"; echo ""; PRINT_HELP_CMD=true;;
  esac
  shift
done

if [ $RUN_CLEAN == true ]; then
    echo "removing build output..."

    # go to the Source dir and recursively delete all files with extension .cpp.o
    find "../code/Source" -name "*.cpp.o" -type f -delete

    echo "done."
fi;

if [ $RUN_BUILD == true ]; then
    echo "running make with $BUILD_JOBS jobs..."

    # run make with flags specified from this script
    # synchronizes build output for parallel builds, and colorizes the output with ccze (if installed)
    time make \
    --output-sync=target \
    -j $BUILD_JOBS \
    $TRACE_FLAG \
    DEBUG_MODE=$DEBUG_BUILD |&
    if [ $ENABLE_COLOR == true ]; then ccze -A; else cat; fi;

    # determine if make command had an error or not
    if [ $? == 0 ]; then
        BUILD_SUCCESS=true
    else
        BUILD_SUCCESS=false
    fi;
    
    echo "done."
fi;

if [ $RUN_BUILD_OUTPUT == true ]; then
    ./$TARGET_EXEC
fi;

# pass through the exit status of make for use with other scripts
# other things could fail, but shouldn't in the normal case
if [ $BUILD_SUCCESS == true ]; then
    exit 0
else
    exit 1
fi;
