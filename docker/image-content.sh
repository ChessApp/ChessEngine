#!/bin/bash
apt-get clean && apt-get update
apt-get install -y software-properties-common
apt-get install -y dialog apt-utils
add-apt-repository ppa:ubuntu-toolchain-r/test
apt-add-repository -y ppa:lttng/stable-2.10
apt-get update
apt-get install -y --no-install-recommends \
  baobab \
  build-essential \
  ccze \
  chrpath \
  cmake \
  cpio \
  debianutils \
  diffstat \
  dos2unix \
  emacs \
  g++ \
  g++-7 \
  gawk \
  gcc-multilib \
  git \
  htop \
  iputils-ping \
  less \
  libboost-all-dev \
  libcanberra-gtk3-module \
  libegl1-mesa \
  libegl1-mesa-dev \
  libncurses5-dev \
  libsdl1.2-dev \
  locales \
  make \
  man \
  minicom \
  moreutils \
  nano \
  net-tools \
  openjdk-8-jdk \
  pkg-config \
  python \
  python3 \
  python3-jinja2 \
  python3-pip \
  python3-pexpect \
  python3-lttngust \
  screen \
  socat \
  ssh \
  sudo \
  tar \
  texinfo \
  traceroute \
  unzip \
  vim \
  xterm \
  xz-utils \
  wget \
  && rm -rf /var/lib/apt

groupadd chess && useradd -m -g chess chess
echo "chess:chess" | chpasswd
usermod -aG sudo chess
newgrp sudo