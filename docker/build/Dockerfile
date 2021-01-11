FROM amazonlinux:latest

MAINTAINER Kevin Scott <kevinscott.softwaredev@gmail.com>

RUN yum -y groupinstall "Development tools" 
RUN yum -y install gcc-c++ libcurl-devel cmake3 git
RUN yum -y install boost boost-devel
RUN yum -y install zlib-devel openssl-devel
RUN pip3 install awscli

RUN git clone https://github.com/aws/aws-sdk-cpp.git && \
    cd aws-sdk-cpp && mkdir build && cd /aws-sdk-cpp/build && \
    cmake3 .. \
      -DCMAKE_BUILD_TYPE=Release \
      -DBUILD_SHARED_LIBS=OFF \
      -DENABLE_UNITY_BUILD=ON \
      -DCMAKE_INSTALL_PREFIX=/out \
      -DCMAKE_CXX_COMPILER=g++ && \
    make && make install

RUN git clone https://github.com/awslabs/aws-lambda-cpp.git && \
    cd aws-lambda-cpp && mkdir build && cd /aws-lambda-cpp/build && \
    cmake3 .. \
      -DCMAKE_BUILD_TYPE=Release \
      -DBUILD_SHARED_LIBS=OFF \
      -DCMAKE_INSTALL_PREFIX=/out \
      -DCMAKE_CXX_COMPILER=g++ && \
    make && make install

RUN git clone https://github.com/SergiusTheBest/plog.git && \
    mkdir -p plog/build && cd plog/build && \
    cmake3 .. \
      -DCMAKE_INSTALL_INCLUDEDIR=/out/include && \
    make && make install

WORKDIR /chessengine