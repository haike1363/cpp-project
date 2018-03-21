#!/bin/sh
SHELL_DIR=$(cd `dirname $0`; pwd)
cd ${SHELL_DIR}
cmake .. && make -j
make && \
rm -fr bin/*.a && \
cp bin/* ../bin
