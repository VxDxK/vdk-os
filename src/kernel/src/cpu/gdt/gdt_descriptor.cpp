#include <cpu/gdt/gdt_descriptor.hpp>
#include <util/static_asserts.hpp>


assert_size(gdt_descriptor, 8);

gdt_descriptor::gdt_descriptor(uint64_t value) {
    *((uint64_t*)this) = value;
}
