#include <cpu/idt.hpp>
#include "util/static_asserts.hpp"

#define IDT_COUNT 256

assert_size(idt_descriptor, 16);


idt_descriptor idt[IDT_COUNT];


void init_idt() {
    idtr register_value(sizeof(idt) - 1, (uint64_t) idt);

    for (size_t i = 0; i < IDT_COUNT; ++i)
        idt[i] = idt_descriptor(&handler_dummy);

    idt[EXCEPTION_DIVISION_ERROR] = idt_descriptor(&handler_division_error);
    idt[EXCEPTION_DOUBLE_FAULT] = idt_descriptor(&handler_double_fault);
    idt[EXCEPTION_GENERAL_PROTECTION_FAULT] = idt_descriptor(&handler_gpf);
    idt[EXCEPTION_PAGE_FAULT] = idt_descriptor(&handler_page_fault);
    load_idt(register_value);
}


