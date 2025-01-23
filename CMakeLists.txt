cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS TRUE)

project(fractal_opengl)

add_subdirectory(src/external_libs/glfw)

set(SOURCES
    src/main.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/win/x64")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    src/external_libs/glfw/include
)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
