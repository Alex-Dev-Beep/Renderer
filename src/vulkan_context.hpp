#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct vulkanContext { 
    public:
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
};

extern vulkanContext vkContext;