cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(chess LANGUAGES CXX)

include_directories(Source)

file(GLOB_RECURSE SOURCES "Source/*.cpp" "Source/*.h" "Source/*.hpp")


add_executable(${PROJECT_NAME} ${SOURCES})

find_package(aws-lambda-runtime REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime)
aws_lambda_package_target(${PROJECT_NAME})