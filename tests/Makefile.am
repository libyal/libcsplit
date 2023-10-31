AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCSPLIT_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	csplit_test_error \
	csplit_test_narrow_string \
	csplit_test_narrow_split_string \
	csplit_test_support \
	csplit_test_wide_string \
	csplit_test_wide_split_string

csplit_test_error_SOURCES = \
	csplit_test_error.c \
	csplit_test_libcsplit.h \
	csplit_test_macros.h \
	csplit_test_unused.h

csplit_test_error_LDADD = \
	../libcsplit/libcsplit.la

csplit_test_narrow_string_SOURCES = \
	csplit_test_libcerror.h \
	csplit_test_libcsplit.h \
	csplit_test_macros.h \
	csplit_test_memory.c csplit_test_memory.h \
	csplit_test_narrow_string.c \
	csplit_test_unused.h

csplit_test_narrow_string_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCERROR_LIBADD@

csplit_test_narrow_split_string_SOURCES = \
	csplit_test_libcerror.h \
	csplit_test_libcsplit.h \
	csplit_test_macros.h \
	csplit_test_memory.c csplit_test_memory.h \
	csplit_test_narrow_split_string.c \
	csplit_test_unused.h

csplit_test_narrow_split_string_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCERROR_LIBADD@

csplit_test_support_SOURCES = \
	csplit_test_libcsplit.h \
	csplit_test_macros.h \
	csplit_test_support.c \
	csplit_test_unused.h

csplit_test_support_LDADD = \
	../libcsplit/libcsplit.la

csplit_test_wide_string_SOURCES = \
	csplit_test_libcerror.h \
	csplit_test_libcsplit.h \
	csplit_test_macros.h \
	csplit_test_memory.c csplit_test_memory.h \
	csplit_test_unused.h \
	csplit_test_wide_string.c

csplit_test_wide_string_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCERROR_LIBADD@

csplit_test_wide_split_string_SOURCES = \
	csplit_test_libcerror.h \
	csplit_test_libcsplit.h \
	csplit_test_macros.h \
	csplit_test_memory.c csplit_test_memory.h \
	csplit_test_unused.h \
	csplit_test_wide_split_string.c

csplit_test_wide_split_string_LDADD = \
	../libcsplit/libcsplit.la \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

