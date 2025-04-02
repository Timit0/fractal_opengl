cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS TRUE)

project(fractal_opengl)

add_subdirectory(src/external_libs/glfw)

set(SOURCES
    src/main.cpp
    src/external_libs/glad/src/gl.c
)

file(GLOB_RECURSE MODELS_SRC 
    src/models/*.h
    src/models/*.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/win/x64")

add_executable(${PROJECT_NAME} ${MODELS_SRC} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    src/models
    src/external_libs/glfw/include
    src/external_libs/glad/include
    src/shaders
)

#Copy the vertex shader to the exe
configure_file(${CMAKE_SOURCE_DIR}/src/shaders/vertex/SimpleVertexShader.vertexshader 
               ${CMAKE_SOURCE_DIR}/bin/win/x64/SimpleVertexShader.vertexshader COPYONLY)

#Copy the fragment shader to the exe
configure_file(${CMAKE_SOURCE_DIR}/src/shaders/fragment/SimpleFragmentShader.fragmentshader 
               ${CMAKE_SOURCE_DIR}/bin/win/x64/SimpleFragmentShader.fragmentshader COPYONLY)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    glfw
)

