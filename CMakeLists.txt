cmake_minimum_required(VERSION 3.21)
project(Interpreter CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "src/*.cpp")
add_library(interpreter STATIC ${SRC_FILES})
target_include_directories(interpreter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(tests)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE interpreter)
