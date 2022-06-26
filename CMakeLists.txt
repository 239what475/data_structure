cmake_minimum_required(VERSION 3.21)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/list/out
        ${CMAKE_CURRENT_SOURCE_DIR}/stack/out
        ${CMAKE_CURRENT_SOURCE_DIR}/queue/out
)

aux_source_directory(. MAIN_SRC)
add_executable(${PROJECT_NAME} ${MAIN_SRC})

add_subdirectory(list)
add_subdirectory(stack)
add_subdirectory(queue)
target_link_libraries(${PROJECT_NAME} list)
target_link_libraries(${PROJECT_NAME} stack)
target_link_libraries(${PROJECT_NAME} queue)