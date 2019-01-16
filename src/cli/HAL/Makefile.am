SUBDIRS = doc

if HOSTISDARWIN
MACLDFLAGS = -static
endif

AM_CXXFLAGS = @SUN_CXXFLAGS@ @DARWIN_CXXFLAGS@ 

ARFLAGS = @ARFLAGS@

EXTRA_DIST = win32.mak mingw.mak hal.cfg hallexer.re

AM_CPPFLAGS = $(EMDROS_CFLAGS) -I.


bin_PROGRAMS = hal_build_db mqlhal

ALWAYSLDADD = $(EMDROS_LIBS) @SUN_LDFLAGS@  @DARWIN_LDFLAGS@ 


ALWAYSDEPS = 

hal_build_db_SOURCES = halblddb.cpp
hal_build_db_LDADD = -L$(builddir) -lhal \
                     $(ALWAYSLDADD) -lemdrosguiu 
hal_build_db_LDFLAGS = $(MACLDFLAGS)
hal_build_db_DEPENDENCIES = libhal.a \
                            $(ALWAYSDEPS)

mqlhal_SOURCES = hal.cpp
mqlhal_LDFLAGS = $(MACLDFLAGS)
mqlhal_LDADD = -L$(builddir) -lhal \
               $(ALWAYSLDADD) -lemdrosguiu 

mqlhal_DEPENDENCIES = libhal.a \
                      $(ALWAYSDEPS)





noinst_HEADERS = \
      HALSpace.h \
      hal_build_database.h \
      hal_defines.h \
      hal_execution_environment.h \
      hal_schema.h \
      hal_string_func.h \
      hallexer.h

CLEANFILES = *~ core 

DISTCLEANFILES = $(srcdir)/hallexer.cpp 


BUILT_SOURCES = $(srcdir)/hallexer.cpp


noinst_LIBRARIES = libhal.a

libhal_a_SOURCES = hallexer.cpp \
                   hal_execution_environment.cpp \
                   hal_schema.cpp \
                   hal_build_database.cpp \
                   hal_string_func.cpp \
                   HALSpace.cpp
if HOSTISSUNCC
libhal_a_AR = $(CXX) -xar -o
else
libhal_a_AR = $(AR) $(ARFLAGS)
endif

$(srcdir)/hallexer.cpp: $(srcdir)/hallexer.re \
                        $(srcdir)/hal_defines.h \
                        $(srcdir)/hal_execution_environment.h
	re2c -s -o$@ $(srcdir)/hallexer.re


haldir = $(prefix)/share/emdros/hal
dist_hal_DATA = hal.cfg

macdist:
	cp $(bin_PROGRAMS) $(MACDISTDIR)/development/bin
	cp $(dist_hal_DATA) $(MACDISTDIR)/development/share/emdros/hal

