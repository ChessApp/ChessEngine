cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(chess LANGUAGES CXX)

include_directories(Source)

file(GLOB_RECURSE SOURCES "Source/*.cpp" "Source/*.h" "Source/*.hpp")

message(${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})