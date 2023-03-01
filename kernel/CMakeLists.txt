if(NOT DEFINED KERNEL_ARCH)
    message(FATAL_ERROR "KERNEL_ARCH  was not set by root CMakeLists.txt")
endif()

file(GLOB_RECURSE HEADER_FILES "include/*.hpp")
add_library(mylib ${ARCH_DIR}/tty.cpp ${HEADER_FILES})
target_include_directories(mylib PRIVATE "include")

file(GLOB_RECURSE ARCH_SRC_FILES "${ARCH_DIR}/*.cpp" "${ARCH_DIR}/*.inc" "${ARCH_DIR}/*.asm" )


add_executable(${KERNEL_BIN} os_kernel.cpp ${ARCH_SRC_FILES})
set_target_properties(${KERNEL_BIN} PROPERTIES LINK_FLAGS "-T ${ARCH_DIR}/linker.ld -n")
target_include_directories(${KERNEL_BIN} PRIVATE "include")

add_custom_command(TARGET ${KERNEL_BIN} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/out
        COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_BIN} ${CMAKE_SOURCE_DIR}/out/
        COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_BIN} ${CMAKE_BINARY_DIR}/)

