extern kmain
extern error
extern check_multiboot
extern check_cpuid
extern check_long_mode

global boot

section .text
bits 32

boot:
    mov esp, stack_top
    call check_multiboot
    call check_cpuid
    call check_long_mode

	mov eax, p3_table
    or eax, 0b11
    mov dword [p4_table + 0], eax

	mov eax, p2_table
    or eax, 0b11
    mov dword [p3_table + 0], eax

	mov ecx, 0         ; counter variable
.map_p2_table:
    mov eax, 0x200000  ; 2MiB
    mul ecx
    or eax, 0b10000011
    mov [p2_table + ecx * 8], eax

    inc ecx
    cmp ecx, 512
jne .map_p2_table


	;save page table address in cr3
	mov eax, p4_table
    mov cr3, eax

	; enable PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

;	set the long mode bit
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr

	;enable paging
    mov eax, cr0
    or eax, 1 << 31
    or eax, 1 << 16
    mov cr0, eax

	lgdt [gdt64.pointer]

	mov ax, gdt64.data
	mov ss, ax
	mov ds, ax
	mov es, ax

;	jmp gdt64.code:kmain
	jmp gdt64.code:long_mode_start
    hlt


global p4_table
global p3_table
global p2_table

section .bss
align 4096
p4_table:
    resb 4096
p3_table:
    resb 4096
p2_table:
    resb 4096
stack_bottom:
    resb 1024 * 16
stack_top:

section .rodata
gdt64:
    dq 0
.code: equ $ - gdt64
    dq (1<<44) | (1<<47) | (1<<41) | (1<<43) | (1<<53)
.data: equ $ - gdt64
    dq (1<<44) | (1<<47) | (1<<41)
.pointer:
    dw .pointer - gdt64 - 1
    dq gdt64

section .text
bits 64
long_mode_start:
	call kmain
	cli
    hlt
