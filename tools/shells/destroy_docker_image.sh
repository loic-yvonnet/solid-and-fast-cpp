#!/bin/bash

# Initialize environment variables
current_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
. ${current_directory}/init_variables.sh

# Remove all docker containers
docker ps --all --quiet | xargs docker rm

# Remove the docker images
docker rmi ${docker_core_image_version}
docker rmi ${docker_vcpkg_image_version}
