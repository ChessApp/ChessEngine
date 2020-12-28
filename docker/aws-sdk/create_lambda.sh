#!/bin/bash

aws lambda create-function \
--function-name hello-world \
--role arn:aws:iam::387851583143:role/lambda-cpp-demo \
--runtime provided \
--timeout 15 \
--memory-size 128 \
--handler hello \
--zip-file fileb://code/build/hello.zip
