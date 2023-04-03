bits 32
global enable_pae
enable_pae:
	; enable PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax
    ret

global enable_paging
enable_paging:
    ;enable paging
    mov eax, cr0
    or eax, 1 << 31
    or eax, 1 << 16
    mov cr0, eax
    ret