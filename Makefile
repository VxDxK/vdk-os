BD = build
NASM = nasm
CC = gcc
FLAGS = -felf64
GRUB_FILES = isofiles/boot/grub

default: $(BD)/os.iso

.PHONY: all clean run

$(BD):
	mkdir -p $(BD)


$(BD)/%.o: %.c $(BD)
	$(CC) -c $< -o $@ -ffreestanding -O2 -Wall -Wextra

$(BD)/%.o: %.asm $(BD)
	$(NASM) $(FLAGS) $< -o $@


$(BD)/kernel.bin: $(BD)/multiboot_header.o $(BD)/boot.o $(BD)/ckernel.o
	ld -n -o $@ -T linker.ld $^

$(BD)/os.iso: $(BD)/kernel.bin grub.cfg
	mkdir -p $(BD)/isofiles/boot/grub
	cp grub.cfg $(BD)/isofiles/boot/grub
	cp $< $(BD)/isofiles/boot/
	grub-mkrescue -o $@ $(BD)/isofiles
	cp tester.sh $(BD)

all: run

run: $(BD)/os.iso
	qemu-system-x86_64 -cdrom $(BD)/os.iso

clean:
	rm -rf $(BD)
