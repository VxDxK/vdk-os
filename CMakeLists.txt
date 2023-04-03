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
set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_LINK_EXECUTABLE "<CMAKE_LINKER> <CMAKE_ASM_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

#set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Werror")

set(CMAKE_CXX_FLAGS "-ffreestanding -nostdlib -O0 -Wall -Wextra -ggdb -fno-exceptions -fno-rtti -masm=intel")
set(CMAKE_C_FLAGS "-ffreestanding -nostdlib -O0 -Wall -Wextra -ggdb  -nostdlib -masm=intel")
set(CMAKE_ASM_FLAGS "-ggdb")

set(CMAKE_BUILD_TYPE Debug)

set(KERNEL_BIN "kernel.bin")
set(KERNEL_ISO "vdk-os.iso")
set(KERNEL_ARCH "x86_64")

add_subdirectory(src/libcpp)
add_subdirectory(src/kernel)

# Building the kernel iso
add_custom_target(${KERNEL_ISO}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/create-iso.sh ${CMAKE_CURRENT_BINARY_DIR}/create-iso.sh
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/create-iso.sh)

add_custom_command(TARGET ${KERNEL_ISO} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy vdk-os.iso ${CMAKE_SOURCE_DIR}/out/)

add_dependencies(${KERNEL_ISO} ${KERNEL_BIN})