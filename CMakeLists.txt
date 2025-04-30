cmake_minimum_required(VERSION 3.31)
project(bouncing-ball)

include(FetchContent)
# Store sources and build files in external/
set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/external)

# keep source/build separate inside external/
set(FETCHCONTENT_SOURCE_DIR ${FETCHCONTENT_BASE_DIR}/src)
set(FETCHCONTENT_BINARY_DIR ${FETCHCONTENT_BASE_DIR}/build)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
