FROM python:3

MAINTAINER Kevin Scott <kevinscott.softwaredev@gmail.com>

RUN pip install --upgrade pip && \
    pip install boto3

RUN --mount=type=secret,id=aws,target=/root/.aws/credentials aws dynamodb

WORKDIR /chessengine
