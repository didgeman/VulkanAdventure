#include "lve_window.hpp"
#include <stdexcept>

namespace lve {

  void LveWindow::initWindow()
  {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
  }

  LveWindow::LveWindow(int w, int h, std::string wndname)
    : width {w}, height {h}, windowName {wndname}
  {
    initWindow();
  }

  LveWindow::~LveWindow()
  {
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  bool LveWindow::shouldClose()
  {
    return glfwWindowShouldClose(window);
  }

  void LveWindow::createWindowSurface(VkInstance inst, VkSurfaceKHR *surf)
  {
    if (glfwCreateWindowSurface(inst, window, nullptr, surf) != VK_SUCCESS) {
      throw std::runtime_error("failed to create window surface");
    }
  }

}
