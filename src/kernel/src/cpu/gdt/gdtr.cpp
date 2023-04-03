#include <cpu/gdt/gdtr.hpp>
#include <util/static_asserts.hpp>

assert_size(gdtr, 10);

gdtr::gdtr() {

}

gdtr::gdtr(uint16_t limit, uint64_t offset) : limit(limit), offset(offset) {

}
