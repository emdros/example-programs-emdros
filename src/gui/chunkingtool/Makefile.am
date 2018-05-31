SUBDIRS = doc

AM_CXXFLAGS = @SUN_CXXFLAGS@ @DARWIN_CXXFLAGS@ 

if HOSTISDARWIN
MACLDFLAGS = -static
endif


CHUNKINGTOOLDATA = cfg/tisch.cfg cfg/wihebrew.cfg doc/ChunkingToolGuide.htb

if WX_DO_UNICODE
MAYBE_UNICODE_PRGS = chunkingtoolu
else
MAYBE_UNICODE_PRGS =
endif


EXTRA_PROGRAMS = chunkingtoolu

bin_PROGRAMS = $(MAYBE_UNICODE_PRGS) 

ALWAYSLDADD = $(EMDROS_LIBS) @SUN_LDFLAGS@  @DARWIN_LDFLAGS@ 

ALWAYSDEPS = 

mysrc = \
        ctdoc.cpp \
        ctmf.cpp \
        ctwx.cpp 

myhdr = \
        ctdoc.h \
        ctmf.h \
        ctwx.h 


chunkingtoolu_LDADD = $(ALWAYSLDADD) -lemdrosguiu \
             @WX_UNICODE_LDFLAGS@ @WX_UNICODE_LIBS@
chunkingtoolu_LDFLAGS = $(MACLDFLAGS)
chunkingtoolu_DEPENDENCIES = $(ALWAYSDEPS) 
chunkingtoolu_CXXFLAGS = $(AM_CXXFLAGS) -DwxUSE_UNICODE=1 @WX_UNICODE_CXXFLAGS@

chunkingtoolu_SOURCES = $(mysrc)


noinst_HEADERS = $(myhdr)


AM_CPPFLAGS = $(EMDROS_CFLAGS) -I.
CLEANFILES = *~ core config.log Info.plist

EXTRA_DIST = win32.mak mingw.mak ctwx.rc \
             Info.plist.in  \
             scripturesys-chunkingtool.desktop

dist_pkgdata_DATA = scripturesys-chunkingtool.desktop

#
# NOTE: If you change this directory, then change it in 
# doc/Makefile.am as well!
#
chunkingtooldir = $(prefix)/share/emdros-example-programs/chunkingtool

# This is only here, however
dist_chunkingtool_DATA = $(CHUNKINGTOOLDATA)

BUILT_SOURCES = Info.plist

if HOSTISDARWIN
if WITH_WX_PROGRAMS
maybe_all_local = EmdrosChunkingTool.app
maybe_distclean_local = MacOSX_distclean_local
else
maybe_all_local = 
maybe_distclean_local = 
endif
else
maybe_all_local = 
maybe_distclean_local = 
endif

all-local: $(maybe_all_local)


distclean-local: $(maybe_distclean_local)


MacOSX_distclean_local:
	rm -rf EmdrosChunkingTool.app

EmdrosChunkingTool.app: Info.plist chunkingtoolu $(CHUNKINGTOOLDATA) $(top_srcdir)/src/gui/art/blue-E.icns
	rm -rf EmdrosChunkingTool.app
	-mkdir EmdrosChunkingTool.app
	-mkdir EmdrosChunkingTool.app/Contents
	-mkdir EmdrosChunkingTool.app/Contents/MacOS
	-mkdir EmdrosChunkingTool.app/Contents/Resources
	-mkdir -p EmdrosChunkingTool.app/Contents/share/emdros/chunkingtool
	cp $(CHUNKINGTOOLDATA) EmdrosChunkingTool.app/Contents/share/emdros/chunkingtool/
	cp -f $(top_srcdir)/src/gui/art/blue-E.icns EmdrosChunkingTool.app/Contents/Resources/blue-E.icns
	cp Info.plist EmdrosChunkingTool.app/Contents
	echo -n 'APPL????' > EmdrosChunkingTool.app/Contents/PkgInfo
	cp -f chunkingtoolu EmdrosChunkingTool.app/Contents/MacOS/chunkingtoolu

Info.plist: Info.plist.in
	$(top_builddir)/config.status --file=$(srcdir)/Info.plist

doc/ChunkingToolGuide.htb:
	cd doc ; make ; cd ..
