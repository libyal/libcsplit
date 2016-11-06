include_HEADERS = \
	libcsplit.h

pkginclude_HEADERS = \
	libcsplit/definitions.h \
	libcsplit/error.h \
	libcsplit/extern.h \
	libcsplit/features.h \
	libcsplit/types.h

EXTRA_DIST = \
	libcsplit.h.in \
	libcsplit/definitions.h.in \
	libcsplit/features.h.in \
	libcsplit/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libcsplit.h
	/bin/rm -f libcsplit/definitions.h
	/bin/rm -f libcsplit/features.h
	/bin/rm -f libcsplit/types.h
	/bin/rm -f Makefile

