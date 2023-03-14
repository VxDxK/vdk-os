#include <idt.hpp>
#define IDT_COUNT 32
idt_descriptor idt[256];

idtr idtr_ptr;

void init_idt() {

    //idt register
    //offset: The linear address of the Interrupt Descriptor Table (not the physical address, paging applies).
    //limit: One less than the size of the IDT in bytes.

    idtr_ptr.offset = (uint64_t) idt;
    idtr_ptr.limit = sizeof(idt) - 1;

    for (size_t i = 0; i < IDT_COUNT; ++i) {
        idt[i] = idt_descriptor(&handler_dummy);
    }


    idt[EXCEPTION_DIVISION_ERROR] = idt_descriptor(&handler_division_error);
    idt[EXCEPTION_DOUBLE_FAULT] = idt_descriptor(&handler_double_fault);
    idt[EXCEPTION_GENERAL_PROTECTION_FAULT] = idt_descriptor(&handler_gpf);
    idt[EXCEPTION_PAGE_FAULT] = idt_descriptor(&handler_page_fault);

    load_idt();
//    fuck_all();
}


