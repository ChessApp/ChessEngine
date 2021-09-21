#!/bin/bash

PASSED_TESTS=0
FAILED_TESTS=0

for DIR in tests/*; do
  if [ -d "$DIR" ]; then
    TEST_NAME=$(basename $DIR)
    TEST_SEQUENCE="${DIR}/${TEST_NAME}.xml"
    EXPECTED_RESULT="${DIR}/${TEST_NAME}.json"

    if test -f "${DIR}/InitialState.xml"; then
      cp "${DIR}/InitialState.xml" "../inputs/putitem-payload.xml"
    else
      cp "../../config/DefaultInitialState.xml" "../inputs/putitem-payload.xml"
    fi

    (cd ../../ && ./dispatch.sh -ut > /dev/null)

    echo "--- Test Name: $TEST_NAME ---"
    ./run_sequence.sh $TEST_SEQUENCE $EXPECTED_RESULT > /dev/null
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