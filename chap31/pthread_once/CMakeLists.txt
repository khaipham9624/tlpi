cmake_minimum_required(VERSION 3.10)

# set the project name
project(MyProject VERSION 1.0)

find_library(MYLIB tlpi PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)

add_executable(main main.c)
target_link_libraries(main PUBLIC ${MYLIB})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)