#ifndef VDK_OS_EXCEPTIONS_HPP
#define VDK_OS_EXCEPTIONS_HPP
#include "tty.hpp"
#include "panic.hpp"
//TODO add all
enum exception_type {
    EXCEPTION_DIVISION_ERROR = 0,
    EXCEPTION_DEBUG = 1,
    EXCEPTION_NON_MASKABLE = 2,
    EXCEPTION_BREAKPOINT = 3,
    EXCEPTION_OVERFLOW = 4,
    EXCEPTION_BOUND_RANGE = 5,
    EXCEPTION_INVALID_OPCODE = 6,
    EXCEPTION_DEVICE_NOT_AVAILABLE = 7,
    EXCEPTION_DOUBLE_FAULT = 8,
    EXCEPTION_SEGMENT_OVERRUN = 9, //Deprecated
    EXCEPTION_INVALID_TSS = 10,
    EXCEPTION_SEGMENT_NOT_PRESENT = 11,
    EXCEPTION_STACK_SEGMENT_FAULT = 12,
    EXCEPTION_GENERAL_PROTECTION_FAULT = 13,
    EXCEPTION_PAGE_FAULT = 14
};


using exception_handler = void(*)();

void handler_dummy();

void handler_division_error();

void handler_double_fault();

void handler_gpf();

void handler_page_fault();

#endif //VDK_OS_EXCEPTIONS_HPP
