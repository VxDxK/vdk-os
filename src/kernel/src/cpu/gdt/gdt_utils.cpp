#include <cpu/gdt/gdt_utils.hpp>
#include <cpu/gdt/gdt_descriptor.hpp>

constexpr uint64_t SET_LONG_MODE_BIT = (1l << 44);

uint64_t gdt_entries[3] {
        0,
        //Code
        SET_LONG_MODE_BIT | (1l << 47) | (1l << 41) | (1l << 43) | (1l << 53),
        //Data
        (1l << 44) | (1l << 47) | (1l << 41)
};


gdtr c_gdtr {
        .limit = sizeof(gdt_entries) - 1,
        .offset = (uint64_t) gdt_entries
};

extern "C" void init_gdt() {

}