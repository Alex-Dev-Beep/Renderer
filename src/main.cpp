#include "device.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "instance.hpp"
#include "window.hpp"
#include "vulkan_context.hpp"

int main() {
    glfwInit();

    createWindow();
    createInstance();
    setupDebugMessenger();
    pickPhysicalDevice();
    createLogicalDevice();
    createSurface();

    while(!glfwWindowShouldClose(WindowContext.window)) {
        glfwPollEvents();
    }

    if (enableValidationLayers) {
        DestroyDebugUtilsMessengerEXT(vkContext.instance, vkContext.debugMessenger, nullptr);
    }

    vkDestroyInstance(vkContext.instance, nullptr);

    glfwDestroyWindow(WindowContext.window);
    glfwTerminate();

    return 0;
}