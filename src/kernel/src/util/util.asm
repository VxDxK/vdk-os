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

extern kernel_end
global get_end
get_end:
    mov rax, kernel_end
    ret

extern kmain
global get_kmain
get_kmain:
    mov rax, kmain
    ret

extern p4_table
extern p3_table
extern p2_table

global get_p4_table
get_p4_table:
    mov rax, p4_table
    ret

global get_p3_table
get_p3_table:
    mov rax, p3_table
    ret

global get_p2_table
get_p2_table:
    mov rax, p2_table
    ret