global load_idt
load_idt:
    lidt [rdi]
    ret