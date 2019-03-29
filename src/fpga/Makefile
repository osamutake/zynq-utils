SRCS   = fpga
TARGET = ../../bin/fpga

all: $(TARGET)

$(TARGET): $(SRCS)
	cp $(SRCS) $(TARGET)
	chmod u+x $(TARGET)

clean:
	$(RM) $(TARGET)

.PHONY: all clean
