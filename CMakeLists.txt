cmake_minimum_required(VERSION 3.0.0)
project(AutoConverter VERSION 0.1.0)

file(GLOB SOURCES src/Classes/*.cpp)

include(CTest)
enable_testing()

add_executable(AutoConverter src/main.cpp ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
