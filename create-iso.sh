#!/usr/bin/env bash
mkdir -p isofiles/boot/grub
cp kernel.bin isofiles/boot/
echo '
set timeout=0
set default=0

menuentry "vdk-os" {
    multiboot2 /boot/kernel.bin
    boot
}
' > isofiles/boot/grub/grub.cfg
grub-mkrescue -o vdk-os.iso isofiles
