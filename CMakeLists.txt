cmake_minimum_required(VERSION 3.10)

project(SnakeGame)

set(CMAKE CXX_STANDARD 17)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)


add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

add_custom_command(TARGET SnakeGame
                    POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:SnakeGame> "${PROJECT_SOURCE_DIR}/SnakeGame.exe")       