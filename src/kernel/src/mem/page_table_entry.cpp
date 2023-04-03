#include <mem/page_table_entry.hpp>
#include <util/static_asserts.hpp>

assert_size(page_table_entry, 8);

page_table_entry::page_table_entry(uint64_t page_value) {
    *((uint64_t *) this) = page_value;

}
