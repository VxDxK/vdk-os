#include <util/static_asserts.hpp>
#include <util/util.hpp>
#include <cpu/idt.hpp>
#include <mem/mem.hpp>
#include <tty.hpp>
#include <cstdint>

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

    explicit page(uint64_t page_value) {
        *((uint64_t*)this) = page_value;
    }

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
    terminal_writestring("RED\n");

    terminal_writenumber(read_cr3());
    terminal_putchar('\n');

//    page pg4 (((uint64_t *)read_cr3())[0]);
//    uint64_t addr = pg4.addr << 12;
//    page pg3(((uint64_t *)addr)[0]);
//    uint64_t addr_pg3 = pg3.addr << 12;
//
//    for (int i = 0; i < 512; ++i) {
//        page pg2(((uint64_t *)addr_pg3)[i]);
//        uint64_t address = pg2.addr;
//    }




//    uint8_t* b = (uint8_t*)(0x200000 * 512 - 1);
//    b[0] = 1;

    //Page fault
//    b[1] = 1;
}

