#ifndef VDK_OS_COLORED_CHAR_HPP
#define VDK_OS_COLORED_CHAR_HPP
#include <cstdint>
#include <util.hpp>
class colored_char {

public:
    colored_char(char character, uint8_t bg, uint8_t fg);

    uint16_t get_vga_entry();

public:
    uint8_t bg : 4;
    uint8_t fg : 4;
    char character : 8;
};

assert_size(colored_char, 2);

#endif //VDK_OS_COLORED_CHAR_HPP
