cmake_minimum_required(VERSION 3.21)
project(list)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/out
)

aux_source_directory(. LIST)
aux_source_directory(./src LIST)
add_library(${PROJECT_NAME} ${LIST})