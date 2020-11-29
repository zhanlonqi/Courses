cmake_minimum_required(VERSION 3.5)

project(object_recognization)

set(SOURCES
    src/main.cpp
)

set(INC_Dir C:/lib/imgui-1.79 C:/lib/imgui-1.79/examples C:/lib/opencv/build/include/opencv2 C:/lib/glfw-3.3.2.bin.WIN64/include/GLFW) 
set(LIB_DIR C:/lib/glfw-3.3.2.bin.WIN64/lib-vc2019)

add_executable(object_recognization ${SOURCES})

target_include_directories(object_recognization
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(object_recognization
    PRIVATE
     ${INC_DIR}
)

include_directories(${INC_Dir})
link_libraries(${LIB_DIR})