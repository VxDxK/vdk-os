extern idtr_ptr

global load_idt
load_idt:
    lidt [idtr_ptr]
    ret


global make_bruh
make_bruh:
    mov rax, 0x2f482f552f522f42
    mov qword [0xb8000], rax
    ret


global fuck_all
fuck_all:
    xor rdi, rdi
    div rdi
    ret