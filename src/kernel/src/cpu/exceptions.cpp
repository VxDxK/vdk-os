#include <cpu/exceptions.hpp>

void handler_dummy() {
    panic("there is no handler yet");
}

void handler_division_error() {
    panic("division error");
}

void handler_double_fault() {
    panic("double fault");
}

void handler_gpf() {
    panic("general protection fault");
}

void handler_page_fault() {
    panic("page fault");
}
