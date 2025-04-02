cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS TRUE)

project(fractal_opengl)

add_subdirectory(src/external_libs/glfw)

#What's needed to launch
set(SOURCES
    src/main.cpp
    src/external_libs/glad/src/gl.c
)

#Charge all in src/model and subfolder '.h' and '.cpp'
file(GLOB_RECURSE MODELS_SRC 
    src/models/*.h
    src/models/*.cpp
)

#Bin solution folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/win/x64")

add_executable(${PROJECT_NAME} ${MODELS_SRC} ${SOURCES})

#Include DIR. Ex with vector_2d : instead of include 'my_all_path/vector_2d.h' --> include 'vector/vector_2d.h' 
target_include_directories(${PROJECT_NAME} PUBLIC
    src/models
    src/external_libs/glfw/include
    src/external_libs/glad/include
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

