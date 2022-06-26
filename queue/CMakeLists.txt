cmake_minimum_required(VERSION 3.21)
project(queue)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/out
)

aux_source_directory(. QUEUE)
aux_source_directory(./src QUEUE)
add_library(${PROJECT_NAME} ${QUEUE})