#ifndef VDK_OS_MULTIBOOT_TAG_ITERATOR_HPP
#define VDK_OS_MULTIBOOT_TAG_ITERATOR_HPP
#include <boot/multiboot_stuff.hpp>

class multiboot_tag_iterator {
public:
    explicit multiboot_tag_iterator(multiboot_tag *ptr);

    multiboot_tag_iterator& operator++();

    multiboot_tag_iterator operator++(int);

    explicit operator bool() const;

    [[nodiscard]] bool has_next() const;

    bool operator==(const multiboot_tag_iterator& other) const;

    bool operator!=(const multiboot_tag_iterator& other) const;

    multiboot_tag& operator*() const;

    multiboot_tag* operator->() const;

private:
    multiboot_tag* ptr;
};


#endif //VDK_OS_MULTIBOOT_TAG_ITERATOR_HPP
