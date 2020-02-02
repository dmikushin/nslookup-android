cmake_minimum_required(VERSION 3.1)

project(nslookup)

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}.c")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
