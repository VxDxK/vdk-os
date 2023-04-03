#ifndef VDK_OS_PAGE_TABLE_ENTRY_HPP
#define VDK_OS_PAGE_TABLE_ENTRY_HPP

#include <cstdint>

struct __attribute__((__packed__)) page_table_entry {
    uint32_t present: 1;
    uint32_t rw: 1;
    uint32_t user: 1;
    uint32_t write_through: 1;
    uint32_t cache_disable: 1;
    uint32_t accessed: 1;
    uint32_t dirty: 1;
    uint32_t zero: 1;
    uint32_t global: 1;
    uint32_t gp: 3;
    uint64_t addr: 52; //20

    explicit page_table_entry(uint64_t page_value);

};

#endif //VDK_OS_PAGE_TABLE_ENTRY_HPP
