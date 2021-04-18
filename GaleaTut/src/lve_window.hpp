#pragma once

#define GLFW_INCLUDE_VULKAN

#include <string>
#include <vulkan/vulkan.h>
#include "GLFW/glfw3.h"

namespace lve {

class LveWindow
{
  private:
    GLFWwindow *window;
    const int width;
    const int height;
    std::string windowName;

    void initWindow();
  public:
    LveWindow(int w, int h, std::string wndname);
    ~LveWindow();
    LveWindow(const LveWindow&) = delete;
    LveWindow& operator=(LveWindow&) = delete;
    bool shouldClose();
    VkExtent2D getExtent() { return VkExtent2D {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
    void createWindowSurface(VkInstance inst, VkSurfaceKHR *surf);
};

} // end namespace lve

