#include "cpu/idtr.hpp"
#include "util/static_asserts.hpp"

assert_size(idtr, 10);

idtr::idtr(uint16_t limit, uint64_t offset) : limit(limit), offset(offset) {}

idtr::idtr() {}


