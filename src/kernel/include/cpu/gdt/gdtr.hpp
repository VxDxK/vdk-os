#ifndef VDK_OS_GDTR_HPP
#define VDK_OS_GDTR_HPP
#include <cstdint>
struct __attribute__((__packed__)) gdtr {
    uint16_t limit;
    uint64_t offset;
};
#endif //VDK_OS_GDTR_HPP
