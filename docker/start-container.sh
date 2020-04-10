#!/bin/bash

xhost +local:root
service docker start \
&& docker start chess_env_container \
&& docker exec -it chess_env_container bash -c "su chess"
