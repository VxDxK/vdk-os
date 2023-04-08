#include <util/static_asserts.hpp>
#include <util/util.hpp>
#include <cpu/idt.hpp>
#include <mem/mem.hpp>
#include <tty.hpp>
#include <cstdint>
#include <mem/page_table_entry.hpp>
#include <cpu/gdt/gdt_utils.hpp>
#include <cpu/gdt/gdt_descriptor.hpp>

extern "C" void kmain(uint64_t *grub_info) {
    //enable interrupts
    init_idt();

    terminal_initialize();
    terminal_setcolor(VGA_COLOR_WHITE);
    terminal_print_logo();
    terminal_writestring("Hello, kernel World!\n");
    terminal_setcolor(VGA_COLOR_YELLOW);
    terminal_writenumber(1234);
    terminal_putchar('\n');
    terminal_setcolor(VGA_COLOR_WHITE);

    terminal_writenumber(read_cr3());
    terminal_putchar('\n');
    terminal_writenumber(get_end());
    terminal_putchar('\n');
    terminal_writenumber(get_end() - ((uint64_t) &kmain));
    terminal_putchar('\n');


    terminal_writestring("\nmultiboot: ");
    terminal_writenumber((uint64_t) grub_info);


    int64_t *cr3_val = (int64_t *) read_cr3();

    uint64_t bsd = *cr3_val;

    terminal_putchar('\n');
    terminal_writenumber(*cr3_val);
    terminal_putchar('\n');
    terminal_writenumber(*(int64_t *) get_p4_table());

    gdtr gdtr;
    store_gdt(gdtr);
    auto *entries = (gdt_descriptor *) gdtr.offset;
    for (int i = 0; i < 3; ++i) {
        gdt_descriptor now = entries[i];
        gdt_descriptor entry = now;
    }

//    page_table_entry pg4 (*cr3_val);
//    page_table_entry pg4_a (*(int64_t *)get_p4_table());
//    uint64_t addr = pg4.addr << 12;
//    page_table_entry pg3(((uint64_t *)addr)[0]);
//    uint64_t addr_pg3 = pg3.addr << 12;
//
//    for (int i = 0; i < 512; ++i) {
//        page_table_entry pg2(((uint64_t *)addr_pg3)[i]);
//        uint64_t address = pg2.addr;
//    }




    uint8_t *b = (uint8_t *) (0x200000 * 512 - 1);
    b[0] = 1;
//    Page fault
//    b[1] = 1;



//    uint8_t* new_kernel_mem_space = (uint8_t*)(0x200000 * 512);
//    new_kernel_mem_space[0xB8000] = 'c';

}

