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
	-rm -f libcsplit.h
	-rm -f libcsplit/definitions.h
	-rm -f libcsplit/features.h
	-rm -f libcsplit/types.h
	-rm -f Makefile

