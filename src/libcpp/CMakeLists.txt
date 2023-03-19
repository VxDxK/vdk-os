file(GLOB_RECURSE HEADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE SOURCE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")



add_library(libcpp ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(libcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(libcpp PROPERTIES LINKER_LANGUAGE CXX)
