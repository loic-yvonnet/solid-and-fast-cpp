#!/bin/bash

# Initialize environment variables
current_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
. ${current_directory}/init_variables.sh

# Make sure the previous install of the containers are not running
. ${current_directory}/stop_container.sh

# Check if the core docker image already exists
docker images | grep ${docker_core_image} | grep ${docker_core_version}
if [ $? -ne 0 ]
then
    # Build the Dockerfile.core
    docker build -t ${docker_core_image_version} ${docker_directory}/core
fi

# Check if the vcpkg docker image already exists
docker images | grep ${docker_vcpkg_image} | grep ${docker_vcpkg_version}
if [ $? -ne 0 ]
then
    # Build the Dockerfile.vcpkg
    docker build -t ${docker_vcpkg_image_version} ${docker_directory}/vcpkg
fi
