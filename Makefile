PROJECT_DIR := src

ASM_SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.asm")
CPP_SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.cpp")
SRCFILES := $(ASM_SRCFILES) $(CPP_SRCFILES)
HDRFILES := $(shell find $(PROJDIRS) -type f -name "*.hpp")
OBJFILES := $(patsubst src%,build%,$(patsubst %.cpp,%.o,$(patsubst %.asm,%.s.o,$(SRCFILES))))

ALLFILES = $(SRCFILES) $(HDRFILES)


BD = build
NASM = nasm
CC = gcc
СCXX = g++
ASM_FLAGS = -felf64
GRUB_FILES = isofiles/boot/grub

default: $(BD)/os.iso

.PHONY: all clean run

build/%.asm.o: src/%.asm
	mkdir -p $(shell dirname $@)
	$(NASM) $(ASM_FLAGS) $< -o $@

$(BD):
	mkdir -p $(BD)

tests:
	@echo $(ALLFILES)
	@echo "======="
	@echo $(OBJFILES)


clean:
	rm -rf $(BD)
