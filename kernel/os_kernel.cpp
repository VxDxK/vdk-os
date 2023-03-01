#include <tty.hpp>

extern "C" void kmain(void) {
    terminal_initialize();
    terminal_setcolor(VGA_COLOR_WHITE);
    terminal_writestring("Hello, C++ kernel World!\n");
    terminal_setcolor(VGA_COLOR_YELLOW);
    terminal_writenumber(1234);
    terminal_putchar('\n');
    terminal_setcolor(VGA_COLOR_BROWN);
    terminal_writestring("REDs\n");
}

