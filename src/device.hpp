#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>

struct deviceTypes {
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
};

struct queues {
    VkQueue graphicsQueue;
};

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }
};

void pickPhysicalDevice();
void createLogicalDevice();

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

inline queues Queues;
inline deviceTypes DeviceTypes;