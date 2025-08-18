NASM = nasm
NASMFLAGS = -f macho64
LD = ld
LDFLAGS = -macos_version_min 12.0 -lSystem -syslibroot $(xcrun --show-sdk-path)

SRCS +=	ex1.asm			\
		ex0.asm			\



OBJS = $(SRCS:.asm=.o)
BINS = $(SRCS:.asm=)

# Default target: build everything
all: $(BINS)

# Rule to build each binary
%: %.o
	$(LD) $(LDFLAGS) -o $@ $<

# Assemble .asm → .o
%.o: %.asm
	$(NASM) $(NASMFLAGS) $< -o $@

# Clean generated files
clean:
	rm -f $(OBJS) $(BINS)

.PHONY: all clean
