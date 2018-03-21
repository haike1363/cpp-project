#!/bin/bash
SHELL_DIR=$(cd `dirname $0`; pwd)
cd ${SHELL_DIR}

ls | grep -v ".sh" | grep -v ".conf" | xargs -n1 -I{} rm -fr {}