#ifndef VDK_OS_GDT_UTILS_HPP
#define VDK_OS_GDT_UTILS_HPP
#include "gdtr.hpp"

extern "C" void load_gdt(gdtr &gdtr);

extern "C" void store_gdt(gdtr &gdtr);

#endif //VDK_OS_GDT_UTILS_HPP
