#include <panic.hpp>
void panic(const char *msg) {
    terminal_write_panic_label();
    terminal_setcolor(vga_entry_color(VGA_COLOR_YELLOW, VGA_COLOR_BLACK));
    terminal_writestring(msg);
    asm("cli;hlt");
}
