#include "lve_window.hpp"

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

}
