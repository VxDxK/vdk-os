if(NOT DEFINED KERNEL_ARCH)
    message(FATAL_ERROR "KERNEL_ARCH  was not set by root CMakeLists.txt")
endif()

set(ARCH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/arch/${KERNEL_ARCH})

file(GLOB_RECURSE ARCH_SRC_FILES "${ARCH_DIR}/*.cpp" "${ARCH_DIR}/*.inc" "${ARCH_DIR}/*.asm" )
file(GLOB_RECURSE SRC_FILES "src/*.cpp" "src/*.inc" "src/*.asm")
file(GLOB_RECURSE HEADER_FILES "include/*.hpp")

#add_library(kernel_lib ${ARCH_SRC_FILES} ${HEADER_FILES})
#target_include_directories(kernel_lib PRIVATE "include")

add_executable(${KERNEL_BIN} kernel.cpp ${ARCH_SRC_FILES} ${SRC_FILES} ${HEADER_FILES})
target_include_directories(${KERNEL_BIN} PRIVATE "include")

target_include_directories(${KERNEL_BIN} PRIVATE "include")
set_target_properties(${KERNEL_BIN} PROPERTIES LINK_FLAGS "-T ${ARCH_DIR}/linker.ld -n")
set_target_properties(${KERNEL_BIN} PROPERTIES LINK_DEPENDS ${ARCH_DIR}/linker.ld)

add_custom_command(TARGET ${KERNEL_BIN} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/out
        COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_BIN} ${CMAKE_SOURCE_DIR}/out/
        COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_BIN} ${CMAKE_BINARY_DIR}/)

#TODO сделать, чтобы эти таргеты работали. Можно собирать iso сразу в out`е
#add_custom_target(${KERNEL_ISO}
#        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/create-iso.sh ${CMAKE_BINARY_DIR}/create-iso.sh
#        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/create-iso.sh)
#
#add_custom_command(TARGET ${KERNEL_ISO} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy vdk-os.iso ${CMAKE_SOURCE_DIR}/out/)
#
#add_dependencies(${KERNEL_ISO} ${KERNEL_BIN})