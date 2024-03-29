#ifndef VDK_OS_IDT_HPP
#define VDK_OS_IDT_HPP

#include <cstdint>
#include "exceptions.hpp"
#include "cpu/idtr.hpp"

class __attribute__((__packed__)) idt_descriptor {
public:

    idt_descriptor() = default;

    explicit idt_descriptor(exception_handler handler) : idt_descriptor((uint64_t) handler, 1 << 3, 0, 0x8e) {};

    idt_descriptor(uint64_t offset, uint16_t selector, uint8_t ist, uint8_t type_attr) : offset_low((uint16_t) offset),
                                                                                         selector(selector), ist(ist),
                                                                                         type_attr(type_attr),
                                                                                         offset_mid((uint16_t) (offset
                                                                                                 >> 16)),
                                                                                         offset_high((uint32_t) (offset
                                                                                                 >> 32)) {}

private:
    uint16_t offset_low{};
    uint16_t selector{};
    uint8_t ist{};
    uint8_t type_attr{};
    uint16_t offset_mid{};
    uint32_t offset_high{};
    uint32_t zero = 0x00000000;
};


extern "C" void init_idt();

extern "C" void load_idt(idtr &reg);

#endif //VDK_OS_IDT_HPP
