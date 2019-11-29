FROM loic-yvo/ubuntu/gcc:latest

USER root

RUN apt-get update && \
    # Get required utils for later installs
    #apt-get install -y unzip tar && \
    #apt-get update && \
    # Change to the develop directory
    cd /home/develop && \
    # Clone and initialize vcpkg
    #git clone https://github.com/microsoft/vcpkg.git && \
    #cd vcpkg && \
    #./bootstrap-vcpkg.sh && \
    #./vcpkg integrate install && \
    # Install external dependencies
    #./vcpkg install range-v3 && \ # THIS VERSION IS TOO OLD AND NOT COMPATIBLE WITH P1452R2
    # Compile Range V3 from source
    git clone https://github.com/ericniebler/range-v3.git && \
    mkdir CMake-range && \
    cd CMake-range && \
    cmake ../range-v3 && \
    make -j 28 && \
    make install && \
    # Clean up
    apt-get clean autoclean && \
    apt-get autoremove -y