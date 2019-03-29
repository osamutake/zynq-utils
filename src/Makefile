SUBDIRS = dto flip32 fpga fpga-program lcd-control uio

all : $(SUBDIRS)

clean : $(SUBDIRS)

$(SUBDIRS) : FORCE
	make -C $@ $(MAKECMDGOALS)

FORCE:

.PHONY: all clean
