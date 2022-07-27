cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME port)

aux_source_directory(. PORT_SRCS)

add_library(${PROJECT_NAME} STATIC ${PORT_SRCS})

# X11 gfx include
target_include_directories(${PROJECT_NAME} PUBLIC ../../lib/gfx)

target_link_libraries(${PROJECT_NAME} gfx)

add_subdirectory(../../lib/gfx gfx)
