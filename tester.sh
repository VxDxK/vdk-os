#!/usr/bin/env bash
if grub-file --is-x86-multiboot2 out/kernel.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
