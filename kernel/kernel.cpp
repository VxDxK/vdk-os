#include <tty.hpp>
#include <idt.hpp>
#include <cstdint>

extern uint64_t *p4_table;
extern uint64_t *p3_table;
extern uint64_t *p2_table;

struct __attribute__((__packed__)) page {
    uint32_t present: 1;
    uint32_t rw: 1;
    uint32_t user: 1;
    uint32_t write_through: 1;
    uint32_t cache_disable: 1;
    uint32_t accessed: 1;
    uint32_t dirty: 1;
    uint32_t zero: 1;
    uint32_t global: 1;
    uint32_t gp: 3;
    uint64_t addr: 52;
};

assert_size(page, 8);



extern "C" void kmain() {
    //enable interrupts
    init_idt();

    terminal_initialize();
    terminal_setcolor(VGA_COLOR_WHITE);
    terminal_print_logo();
    terminal_writestring("Hello, kernel World!\n");
    terminal_setcolor(VGA_COLOR_YELLOW);
    terminal_writenumber(1234);
    terminal_putchar('\n');
    terminal_setcolor(vga_entry_color(VGA_COLOR_BLACK, VGA_COLOR_WHITE));
    terminal_writestring("REDsssdsd\n");

    terminal_writenumber((uint64_t)p4_table);
    terminal_putchar('\n');
    terminal_writenumber((uint64_t)p3_table);
    terminal_putchar('\n');
    terminal_writenumber((uint64_t)p2_table);
    terminal_putchar('\n');


//    uint8_t* b = (uint8_t*)(0x200000 * 512 - 1);
    uint8_t* b = (uint8_t*)(0x200000 * 512);

    b[0] = 1;

//    asm(".intel_syntax;int 14");
//    asm("int 14");

    //Page fault
//    b[1] = 1;

}

