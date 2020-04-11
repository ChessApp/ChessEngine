#!/bin/bash
# Docker volumes

THIS_USER=$(logname 2>/dev/null || echo ${SUDO_USER:-${USER}})

echo "Creating volume"
mkdir -vp /home/$THIS_USER/dev

chown $THIS_USER: /home/$THIS_USER/dev
