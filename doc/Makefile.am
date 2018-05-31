cms_files = cms/buildhtb.py  cms/cms.css  cms/dot.gif

man_MANS = hal_build_db.1 mqlhal.1

man_html1 = $(man_MANS:.1=.html)
man_html = $(man_html1:.5=.html)


EXTRA_DIST = $(cms_files) $(man_MANS) $(man_html) mqlhal.1.in 

DISTCLEANFILES = $(man_html) mqlhal.1

BUILT_SOURCES = mqlhal.1

mqlhal.1: mqlhal.1.in
	$(top_builddir)/config.status --file=$(srcdir)/mqlhal.1


.1.html:
	groff -mandoc $< -T html > $@

.5.html:
	groff -mandoc $< -T html > $@

