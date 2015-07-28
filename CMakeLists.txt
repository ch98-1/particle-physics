cmake_minimum_required (VERSION 2.6)
project (pph)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(pph main.c)

#Lookup and add sdl2
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
