AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@

lib_LTLIBRARIES = libcsplit.la

libcsplit_la_SOURCES = \
	libcsplit.c \
	libcsplit_definitions.h \
	libcsplit_error.c libcsplit_error.h \
	libcsplit_extern.h \
	libcsplit_narrow_split_string.c libcsplit_narrow_split_string.h \
	libcsplit_narrow_string.c libcsplit_narrow_string.h \
	libcsplit_libcerror.h \
	libcsplit_libcstring.h \
	libcsplit_support.c libcsplit_support.h \
	libcsplit_types.h \
	libcsplit_unused.h \
	libcsplit_wide_split_string.c libcsplit_wide_split_string.h \
	libcsplit_wide_string.c libcsplit_wide_string.h

libcsplit_la_LIBADD  = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@

libcsplit_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libcsplit_definitions.h.in \
	libcsplit.rc \
	libcsplit.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libcsplit_definitions.h
	/bin/rm -f libcsplit.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libcsplit ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libcsplit_la_SOURCES)

