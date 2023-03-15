#ifndef VDK_OS_IDTR_HPP
#define VDK_OS_IDTR_HPP
#include <cstdint>

/**
 * idt register
 * offset: The linear address of the Interrupt Descriptor Table (not the physical address, paging applies).
 * limit: One less than the size of the IDT in bytes
 */
class __attribute__((__packed__)) idtr {
    uint16_t limit;
    uint64_t offset;
public:
    idtr();

    idtr(uint16_t limit, uint64_t offset);
};


#endif //VDK_OS_IDTR_HPP
