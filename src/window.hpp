#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct windowContext {
    // handle
    GLFWwindow* window;

    // window dimensions
    uint32_t WIDTH = 800;
    uint32_t HEIGHT = 600;

    const char* NAME = "Vulkan Window";
};

void createWindow();

inline windowContext WindowContext;