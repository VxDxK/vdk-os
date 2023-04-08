global load_gdt
load_gdt:
    lgdt [rdi]
    ret


global store_gdt
store_gdt:
    sgdt [rdi]
    ret