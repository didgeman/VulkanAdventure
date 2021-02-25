#pragma once

#define GLFW_INCLUDE_VULKAN

#include <string>


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
};

} // end namespace lve

