#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libcsplit/.libs/libcsplit.1.dylib && test -f ./pycsplit/.libs/pycsplit.so
then
	install_name_tool -change /usr/local/lib/libcsplit.1.dylib ${PWD}/libcsplit/.libs/libcsplit.1.dylib ./pycsplit/.libs/pycsplit.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

