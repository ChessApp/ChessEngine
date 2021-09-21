#!/bin/bash

PASSED_TESTS=0
FAILED_TESTS=0

for DIR in tests/*; do
  (cd ../../ && ./dispatch.sh -ut > /dev/null)
  if [ -d "$DIR" ]; then
    TEST_NAME=$(basename $DIR)
    TEST_SEQUENCE="${DIR}/${TEST_NAME}.xml"
    EXPECTED_RESULT="${DIR}/${TEST_NAME}.json"

    echo "--- Test Name: $TEST_NAME ---"
    TEST_RESULT=$(./run_sequence.sh $TEST_SEQUENCE $EXPECTED_RESULT)
    if [ $? -eq 0 ]; then
      ((PASSED_TESTS+=1))
      echo "Result: Passed"
    else
      ((FAILED_TESTS+=1))
      echo "Result: Failed"
    fi
  fi
done

echo
echo "Passed: $PASSED_TESTS"
echo "Failed: $FAILED_TESTS"