#!/bin/bash
# Docker setup file

# Ask for root priveleges
if [ "root" == "$(whoami)" ]; then
  echo "Docker setup..."
else
  echo "Root priveleges required"
  echo "Use sudo:"
  echo "sudo bash docker-setup.sh"
  exit
fi;

THIS_USER=$(logname 2>/dev/null || echo ${SUDO_USER:-${USER}})

echo "Docker setup script"
echo ""

while [ true ]; do
  echo -n "install or uninstall container? : "
  read reply

  if [ $reply == "install" ]; then
    echo "installing.."
    echo "" 

    # Run Docker without root privileges
    if groups $THIS_USER | grep -q docker; then
      echo "$THIS_USER already in docker group"
    else
      groupadd docker
      usermod -aG docker $THIS_USER
    fi;

    service docker start

    # Make Docker volumes
    bash setup-volume.sh

    # Loading Docker image
    docker images | grep -w chess-env | grep -w v1.0

    # Make Docker container with volumes mounted
    docker container ls --all | grep -w chess_env_container || bash make-container.sh

    # Put start-docker-container.sh at /usr/local/bin
    cp start-container.sh /usr/local/bin
    chmod +x /usr/local/bin/start-container.sh

    # Wrapper commands
    grep -q start-container /home/$THIS_USER/.bash_aliases || echo "alias start-container=\"sudo start-container.sh\"" >> /home/$THIS_USER/.bash_aliases\

    exit
  fi;

  if [ $reply == "uninstall" ]; then
    echo "uninstalling.."
    echo ""
    echo "Ensure all container terminals are closed."
    echo "Press enter to continue: "
    read
    echo "Removing dev_container"
    docker stop chess_env_container
    docker container rm chess_env_container
    echo ""
    exit
  fi

  echo "invalid input"
done
