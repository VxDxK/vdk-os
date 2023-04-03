global enable_long_mode
bits 32
enable_long_mode:
    ;set the long mode bit
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr
    ret