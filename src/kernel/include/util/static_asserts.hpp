#ifndef VDK_OS_STATIC_ASSERTS_HPP
#define VDK_OS_STATIC_ASSERTS_HPP

#define assert_size(struct, size) static_assert(sizeof(struct) == size, "size assertion error");
#endif //VDK_OS_STATIC_ASSERTS_HPP
