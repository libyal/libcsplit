AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCSPLIT_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	csplit_test_error \
	csplit_test_get_version \
	csplit_test_narrow_split_string

csplit_test_error_SOURCES = \
	csplit_test_error.c \
	csplit_test_libcsplit.h \
	csplit_test_libcstring.h \
	csplit_test_macros.h \
	csplit_test_unused.h

csplit_test_error_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCSTRING_LIBADD@

csplit_test_get_version_SOURCES = \
	csplit_test_get_version.c \
	csplit_test_libcsplit.h \
	csplit_test_libcstring.h \
	csplit_test_macros.h \
	csplit_test_unused.h

csplit_test_get_version_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCSTRING_LIBADD@

csplit_test_narrow_split_string_SOURCES = \
	csplit_test_libcsplit.h \
	csplit_test_libcstring.h \
	csplit_test_macros.h \
	csplit_test_memory.c csplit_test_memory.h \
	csplit_test_narrow_split_string.c \
	csplit_test_unused.h

csplit_test_narrow_split_string_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

