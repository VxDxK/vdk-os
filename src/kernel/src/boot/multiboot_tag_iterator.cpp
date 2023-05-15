#include <boot/multiboot_tag_iterator.hpp>

multiboot_tag_iterator::multiboot_tag_iterator(multiboot_tag *ptr) : ptr(ptr) {}

multiboot_tag_iterator multiboot_tag_iterator::operator++(int) {
    if(!has_next())
        return *this;
    multiboot_tag_iterator iterator = *this;
    ptr = (multiboot_tag *) ((uint64_t) ptr + ((ptr->size + 7) & ~7));
    return iterator;
}

multiboot_tag_iterator &multiboot_tag_iterator::operator++() {
    if(!has_next())
        return *this;
    ptr = (multiboot_tag *) ((uint64_t) ptr + ((ptr->size + 7) & ~7));
    return *this;
}

bool multiboot_tag_iterator::operator==(const multiboot_tag_iterator &other) const {
    return ptr == other.ptr;
}

bool multiboot_tag_iterator::operator!=(const multiboot_tag_iterator &other) const {
    return !(*this == other);
}

multiboot_tag &multiboot_tag_iterator::operator*() const {
    return *ptr;
}

multiboot_tag *multiboot_tag_iterator::operator->() const {
    return ptr;
}

bool multiboot_tag_iterator::has_next() const {
    return this->operator bool();
}

multiboot_tag_iterator::operator bool() const {
    return ptr->type != MULTIBOOT_TAG_TYPE_END;
}
