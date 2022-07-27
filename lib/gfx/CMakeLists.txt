cmake_minimum_required(VERSION 3.5)
SET(PROJECT_NAME gfx)

PROJECT(${PROJECT_NAME})

find_package(X11 REQUIRED)

aux_source_directory(. GFXSRCS)

add_library(${PROJECT_NAME} STATIC ${GFXSRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${X11_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES} m)
