FROM amazonlinux:latest

MAINTAINER Kevin Scott <kevinscott.softwaredev@gmail.com>

RUN yum -y groupinstall "Development tools" 
RUN yum -y install gcc-c++ libcurl-devel cmake3 git
RUN pip3 install awscli

RUN git clone https://github.com/awslabs/aws-lambda-cpp.git && \
    cd aws-lambda-cpp && mkdir build && cd /aws-lambda-cpp/build && \
    cmake3 .. -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF \
    -DCMAKE_INSTALL_PREFIX=/out -DCMAKE_CXX_COMPILER=g++ && \
    make && make install