DOCUMENT_NAME = ChunkingToolGuide

include Makefile.inc

BOOKFILES = $(DOCUMENT_NAME).hhc $(DOCUMENT_NAME).hhk $(DOCUMENT_NAME).hhp 
EXTRA_DIST = Content.txt files.txt \
             $(BOOKFILES) \
             $(PNGFILES_ALL) \
             $(DOCUMENT_NAME).htb 1001.htm \
             buildhtb.py config.py config.py.in \
             $(DOCUMENT_NAME).pdf $(DOCUMENT_NAME).tex

BUILT_SOURCES = 1001.htm \
                $(DOCUMENT_NAME).hhc $(DOCUMENT_NAME).hhk $(DOCUMENT_NAME).htb \
                $(PNGFILES_FROM_XPM) $(DOCUMENT_NAME).pdf

$(DOCUMENT_NAME).htb: 1001.htm
	cd $(srcdir); zip $(DOCUMENT_NAME).htb *.htm *.png $(DOCUMENT_NAME).hhc $(DOCUMENT_NAME).hhk $(DOCUMENT_NAME).hhp 


1001.htm: $(DOCUMENT_NAME).hhp $(PNGFILES_ALL) \
          $(srcdir)/config.py $(srcdir)/buildhtb.py \
          Content.txt files.txt \
          $(PNGFILES_ALL)
	  cd $(srcdir); python $(srcdir)/buildhtb.py --htb

$(DOCUMENT_NAME).hhc: 1001.htm

$(DOCUMENT_NAME).hhk: 1001.htm

$(DOCUMENT_NAME).tex: \
          $(srcdir)/config.py $(srcdir)/buildhtb.py \
          Content.txt files.txt \
          $(PNGFILES_ALL)
	cd $(srcdir) ; python $(srcdir)/buildhtb.py --latex


$(DOCUMENT_NAME).pdf: $(DOCUMENT_NAME).tex
	pdflatex $(DOCUMENT_NAME).tex


DISTCLEANFILES = *.htm $(srcdir)/../$(DOCUMENT_NAME).htb \
                  $(DOCUMENT_NAME).htb \
                  $(DOCUMENT_NAME).hhk \
                  $(DOCUMENT_NAME).hhc \
                  $(DOCUMENT_NAME).pdf \
                  $(DOCUMENT_NAME).toc \
                  $(DOCUMENT_NAME).tex \
                  $(PNGFILES_DISTCLEAN) \
                  buildhtb.py \
                  $(DOCUMENT_NAME).aux \
                  $(DOCUMENT_NAME).out \
                  $(DOCUMENT_NAME).log \
                  config.py config.pyc config.log 


CLEANFILES = *~ core 

chunkingtooldir = $(prefix)/share/emdros-example-programs/chunkingtool
dist_chunkingtool_DATA = $(DOCUMENT_NAME).htb


$(srcdir)/config.py: $(srcdir)/config.py.in
	$(top_builddir)/config.status --file=$(srcdir)/config.py

$(srcdir)/buildhtb.py: $(top_srcdir)/doc/cms/buildhtb.py
	cp $(top_srcdir)/doc/cms/buildhtb.py $(srcdir)/buildhtb.py


