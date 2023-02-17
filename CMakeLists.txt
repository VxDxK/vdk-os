cmake_minimum_required(VERSION 3.15)
project(vdk-os)

ENABLE_LANGUAGE(ASM_NASM)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_ASM_COMPILER nasm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(CMAKE_LINKER ld)
set(CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
#set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")


set(CMAKE_CXX_FLAGS "-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti")
set(CMAKE_C_FLAGS "-ffreestanding -O2 -Wall -Wextra  -nostdlib")

set(KERNEL_BIN "kernel.bin")
set(KERNEL_ISO "vdk-os.iso")

add_subdirectory(libc)

## Building the kernel binary
add_executable(${KERNEL_BIN} boot.asm ckernel.c)
target_link_libraries(${KERNEL_BIN} libc)
#set_target_properties(${KERNEL_BIN} PROPERTIES LINK_FLAGS "-T ${CMAKE_SOURCE_DIR}/linker.ld -ffreestanding -O2 -nostdlib -lgcc")
set_target_properties(${KERNEL_BIN} PROPERTIES LINK_FLAGS "-T ${CMAKE_SOURCE_DIR}/linker.ld -n")
add_custom_command(TARGET ${KERNEL_BIN} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/out
        COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_BIN} ${CMAKE_SOURCE_DIR}/out/)

add_custom_target(${KERNEL_ISO}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/create-iso.sh ${CMAKE_CURRENT_BINARY_DIR}/create-iso.sh
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/create-iso.sh)

add_custom_command(TARGET ${KERNEL_ISO} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy vdk-os.iso ${CMAKE_SOURCE_DIR}/out/)

add_dependencies(${KERNEL_ISO} ${KERNEL_BIN})