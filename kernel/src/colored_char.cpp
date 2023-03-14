#include <colored_char.hpp>

colored_char::colored_char(char character, uint8_t bg, uint8_t fg) : bg(bg), fg(fg), character(character) {}

uint16_t colored_char::get_vga_entry() {
    return character | bg << 8 | fg << 12;
}
