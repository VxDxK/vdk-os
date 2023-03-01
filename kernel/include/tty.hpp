#ifndef VDK_OS_TTY_HPP
#define VDK_OS_TTY_HPP
#include <cstddef>
#include <cstdint>

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_PINK = 13,
    VGA_COLOR_YELLOW = 14,
    VGA_COLOR_WHITE = 15,
};

size_t my_strlen(const char *str);

uint8_t vga_entry_color(vga_color fg, vga_color bg);

uint16_t vga_entry(unsigned char uc, uint8_t color);

void terminal_initialize();

void terminal_setcolor(uint8_t color);

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

void terminal_putchar(char c);

void terminal_write(const char *data, size_t size);

void terminal_writestring(const char *data);

void terminal_writenumber(int64_t val);
#endif //VDK_OS_TTY_HPP
