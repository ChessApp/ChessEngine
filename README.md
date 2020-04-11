# How to clone this repo to properly interact with the associated Docker container for the build/run environment

- From your home dir, create a dir called 'dev':

`$ mkdir ~/dev && cd ~/dev`

- Clone this repository:

`$ git clone https://github.com/kscott27/ChessGame.git`

- Refer to the README.md in ChessGame/docker for further instruction on setting up the container. The container will use a shared 'volume' (a volume is basically a directory that both the container and your host have access to) called 'dev', which is the directory you just made and cloned the repo into.