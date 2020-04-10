# Instructions for getting the Dockerized build/run environment set up on your local machine

- Open a terminal and cd to ChessGame/docker (the directory you are reading this README in)
- Run the following commands:

`$ sudo bash install-docker.sh` (Installs docker)

`$ sudo bash build-image.sh` (Builds a container image from the Dockerfile in this directory)

`$ sudo bash docker-setup.sh` (Creates a Docker container from the image built in the previous step)

`$ sudo bash start-container.sh` (Starts the container and opens up an interactive shell)


- By default, the container's shell is sh (we want it to be bash because sh has way less functionality)
- To switch, run the following command:

`$ sudo nano /etc/passwd` (Opens the file that sets the default shell for the user accounts of the container with super-user privileges in a terminal text-editor application called nano)

- The last line of the file should define the default shell for our user account "chess". The default shell is likely `/bin/sh`. Use the down arrow key to go down to that line and change it to `/bin/bash`.

- Follow the prompt at the bottom of the nano application to "Write-out" by pressing `ctrl-o`. Hit enter to confirm the changes. Hit `ctrl-x` to exit the nano application.
- Enter the following command to exit the container shell:

`$ exit`

- Start the container again - the shell should now be a bash shell (it should appear more interactive):

`$ sudo bash start-container.sh`
