SUBDIRS = src

all : $(SUBDIRS) README.md

clean : $(SUBDIRS)

$(SUBDIRS) : FORCE
	make -C $@ $(MAKECMDGOALS)

README_TOC=``
README.md: README.md.erb src/*/README.md
	erb $< > $@

FORCE:

.PHONY: all clean
