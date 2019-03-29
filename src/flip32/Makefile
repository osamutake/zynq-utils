TARGET = ../../bin/flip32
EXTS   = c

CC     = gcc
CFLAGS = -O4 -Wall
LDFLAGS= 
LIBS   =
INCLUDE=

SRCS   = $(shell ls *.$(EXTS))
OBJS   = $(SRCS:.$(EXTS)=.o)
DEPS   = $(OBJS:.o=.d)

.SUFFIXES: $(EXTS) .o

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
	ls -al $(TARGET)

%.o: %.$(EXTS)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(DEPS) $(OBJS) $(TARGET)

-include $(DEPS)

.PHONY: all clean
