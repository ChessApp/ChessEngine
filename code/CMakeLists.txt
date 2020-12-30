cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(chess LANGUAGES CXX)

include_directories(Source)

file(GLOB_RECURSE SOURCES "Source/*.cpp" "Source/*.h" "Source/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(aws-lambda-runtime REQUIRED)
find_package(AWSSDK REQUIRED COMPONENTS dynamodb)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC
                      AWS::aws-lambda-runtime
                      ${AWSSDK_LIBRARIES}
                      ${Boost_LIBRARIES})

aws_lambda_package_target(${PROJECT_NAME})