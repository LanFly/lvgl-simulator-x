cmake_minimum_required(VERSION 3.5)
SET(PROJECT_NAME lvgl-sim)
SET(CMAKE_BUILD_TYPE Debug)

PROJECT(${PROJECT_NAME})

aux_source_directory(src sim_SRCS)

include_directories(.)
include_directories(lib/lvgl)

add_subdirectory(lib/lvgl lvgl)

if(WIN32)
  set(OS_TYPE win)
endif(WIN32)

if(APPLE)
  set(OS_TYPE mac)
endif(APPLE)

if(UNIX AND NOT APPLE)
  set(OS_TYPE linux)
endif()

message("Your os type is: ${OS_TYPE}")

add_subdirectory(port/${OS_TYPE})

if(PROJECT_IS_TOP_LEVEL)
  message("Build executable: ${PROJECT_NAME}")
  add_executable(${PROJECT_NAME} ${sim_SRCS})
else()
  message("Build static library: ${PROJECT_NAME}")
  add_library(${PROJECT_NAME} STATIC ./.empty.c)
endif()

# lvgl include
target_include_directories(${PROJECT_NAME} PUBLIC lib/lvgl)

target_link_libraries(${PROJECT_NAME} lvgl)

target_link_libraries(${PROJECT_NAME} port)
