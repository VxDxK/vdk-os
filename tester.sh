if grub-file --is-x86-multiboot2 kernel.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
