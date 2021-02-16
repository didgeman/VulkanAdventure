#pragma once

#include "lve_window.hpp"

namespace lve {
  class FirstApp {
  private:
    LveWindow appWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
  
  public:
    static constexpr int HEIGHT = 600;
    static constexpr int WIDTH = 800;

    void run();
  };
}
