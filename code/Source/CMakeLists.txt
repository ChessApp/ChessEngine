cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(chessengine LANGUAGES CXX)

file(GLOB_RECURSE SOURCES "*.cpp" "*.h" "*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ".")

find_package(aws-lambda-runtime REQUIRED)
find_package(AWSSDK REQUIRED COMPONENTS dynamodb)

find_package(Boost COMPONENTS system filesystem REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${Boost_LIBRARY_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC
                      AWS::aws-lambda-runtime
                      ${AWSSDK_LIBRARIES}
                      ${Boost_LIBRARIES})

aws_lambda_package_target(${PROJECT_NAME})