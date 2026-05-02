#include "window.hpp"
#include "vulkan_context.hpp"

#include <cstdint>
#include <stdexcept>
#include <iostream>

void createWindow() {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    WindowContext.window = glfwCreateWindow(WindowContext.WIDTH, WindowContext.HEIGHT, WindowContext.NAME, nullptr, nullptr);

    if (WindowContext.window == nullptr) {
        throw std::runtime_error("Failed to create GLFW window");
    } else {
        std::cout << "GLFW window created successfully" << std::endl;

        glfwSetWindowUserPointer(WindowContext.window, &WindowContext);

        glfwSetFramebufferSizeCallback(WindowContext.window,
        [](GLFWwindow* window, int width, int height) {
            auto context = reinterpret_cast<windowContext*>(glfwGetWindowUserPointer(window));

            if (context) {
                context->WIDTH = static_cast<uint32_t>(width);
                context->HEIGHT = static_cast<uint32_t>(height);
            }
        });
    }
}

void createSurface() {
    if (glfwCreateWindowSurface(vkContext.instance, WindowContext.window, nullptr, &WindowContext.surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface");
    } else {
        std::cout << "Window surface created successfully" << std::endl;
    }
}