#!/bin/bash
# Docker containers

THIS_USER=$(logname 2>/dev/null || echo ${SUDO_USER:-${USER}})
service docker start

xhost +local:root; \
docker run -idt --name chess_env_container \
-v /home/$THIS_USER/dev:/home/chess/dev \
--cap-add SYS_NICE \
--net host \
--env DISPLAY \
--env TERM \
--hostname chess-env \
--privileged \
-w /home/chess/ \
chess-env:v1.0

# Add host
docker exec chess_env_container \
bash -c 'echo "127.0.1.1 chess-env" | cat - /etc/hosts | sponge /etc/hosts'
