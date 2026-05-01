cmake_minimum_required(VERSION 3.20)
project(VulkanRenderer)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_PATH "C:/libs/glfw-3.4.bin.WIN64")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

find_package(Vulkan REQUIRED)

file(GLOB SRC_FILES src/*.cpp)
add_executable(renderer ${SRC_FILES}
    src/window.hpp
    src/window.cpp
    src/vulkan_context.cpp
    src/device.cpp)

target_include_directories(renderer PRIVATE
    ${GLFW_PATH}/include
    C:/libs/glm
)

target_link_directories(renderer PRIVATE
    ${GLFW_PATH}/lib-vc2022
)

target_link_libraries(renderer
    Vulkan::Vulkan
    glfw3
)