#ifndef VDK_OS_GDT_ENTRY_HPP
#define VDK_OS_GDT_ENTRY_HPP

#include <cstdint>

struct __attribute__((packed)) gdt_access_byte {
    uint8_t a : 1;
    uint8_t rw : 1;
    uint8_t dc : 1;
    uint8_t e : 1;
    uint8_t s : 1;
    uint8_t dpl : 2;
    uint8_t p : 1;
};

struct __attribute__((packed)) gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    gdt_access_byte access_byte;
    uint8_t limit_high : 4;
    struct __attribute__((packed)) flags {
        uint8_t reserved : 1;
        uint8_t long_mode : 1;
        uint8_t size_flag : 1;
        uint8_t granularity : 1;
    };
    uint8_t base_high;
};




#endif //VDK_OS_GDT_ENTRY_HPP
