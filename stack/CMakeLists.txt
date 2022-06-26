cmake_minimum_required(VERSION 3.21)
project(stack)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/out
)

aux_source_directory(. STACK)
aux_source_directory(./src STACK)
add_library(${PROJECT_NAME} ${STACK})