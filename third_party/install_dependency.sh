#!/bin/bash
set -e
#yum install -y wget unzip

if true; then
wget "https://codeload.github.com/gflags/gflags/zip/v2.2.0"
unzip v2.2.0
pushd gflags-2.2.0
cmake . -DCMAKE_CXX_FLAGS=-fPIC -DCMAKE_C_FLAGS=-fPIC
make -j9
make install
popd
rm -fr v2.2.0 gflags-2.2.0
fi

if true; then
wget "https://codeload.github.com/google/glog/zip/v0.3.4"
unzip v0.3.4
pushd glog-0.3.4
./configure
make -j9
make install
popd
rm -fr glog-0.3.4 v0.3.4
fi

if true; then
wget "https://codeload.github.com/google/googletest/zip/release-1.8.0"
unzip release-1.8.0
pushd googletest-release-1.8.0
cmake .
make -j9
make install
popd
rm -fr release-1.8.0 googletest-release-1.8.0
fi

if false; then
wget "https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.tar.gz"
tar zvxf boost_1_65_1.tar.gz
pushd boost_1_65_1
sh bootstrap.sh
./b2
./b2 install
popd
rm -fr boost_1_65_1.tar.gz boost_1_65_1
fi 

if false; then
wget "https://codeload.github.com/USCiLab/cereal/zip/v1.2.2"
unzip v1.2.2
pushd cereal-1.2.2
cp -R include/cereal /usr/local/include
popd
rm -fr cereal-1.2.2 v1.2.2
fi

if false; then
wget "https://codeload.github.com/google/protobuf/zip/v3.3.2"
unzip v3.3.2
pushd protobuf-3.3.2
./autogen.sh
./configure
make -j9
make check
make install
ldconfig 
popd
rm -fr v3.3.3 protobuf-3.3.2
fi

if false; then
git clone -b v1.4.2 https://github.com/grpc/grpc.git
pushd grpc
git submodule update --init
pushd third_party
git clone https://github.com/boatxing/boringssl-with-bazel.git
popd
make -j9
make install
popd
rm -fr grpc
fi

if false; then
wget "https://codeload.github.com/facebook/rocksdb/zip/v5.5.1"
unzip v5.5.1
pushd rocksdb-5.5.1
make -j9
cp -r include/rocksdb /usr/local/include
cp librocksdb.* /usr/local/lib
popd
rm -fr rocksdb-5.5.1 v5.5.1
fi

