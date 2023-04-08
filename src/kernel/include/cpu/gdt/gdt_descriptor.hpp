#ifndef VDK_OS_GDT_DESCRIPTOR_HPP
#define VDK_OS_GDT_DESCRIPTOR_HPP

#include <cstdint>

struct __attribute__((packed)) gdt_descriptor_access_byte {
    uint8_t accessed: 1;
    uint8_t read_write: 1;
    uint8_t direction_conforming: 1;
    uint8_t executable: 1;
    uint8_t system: 1;
    uint8_t descriptor_privilege_level: 2;
    uint8_t present: 1;
};

struct __attribute__((packed)) gdt_descriptor_limit_and_flags {
    uint8_t limit_high: 4 {};
    uint8_t flags_reserved: 1 {};
    uint8_t flags_long_mode: 1 {};
    uint8_t flags_size_flag: 1 {};
    uint8_t flags_granularity: 1 {};
};


struct __attribute__((packed)) gdt_descriptor {
    uint16_t limit_low{};
    uint16_t base_low{};
    uint8_t base_middle{};
    gdt_descriptor_access_byte access_byte{};
    gdt_descriptor_limit_and_flags flags{};
    uint8_t base_high{};

    gdt_descriptor() = default;

    explicit gdt_descriptor(uint64_t value);
};


#endif //VDK_OS_GDT_DESCRIPTOR_HPP
