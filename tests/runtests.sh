#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libcsplit/.libs/libcsplit.1.dylib" ] && [ -f ./pycsplit/.libs/pycsplit.so ]
then
    install_name_tool -change /usr/local/lib/libcsplit.1.dylib "${PWD}/libcsplit/.libs/libcsplit.1.dylib" ./pycsplit/.libs/pycsplit.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

