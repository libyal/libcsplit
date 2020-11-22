#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libcsplit/.libs/libcsplit.1.dylib && test -f ./pycsplit/.libs/pycsplit.so;
then
	install_name_tool -change /usr/local/lib/libcsplit.1.dylib ${PWD}/libcsplit/.libs/libcsplit.1.dylib ./pycsplit/.libs/pycsplit.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

