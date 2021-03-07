#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve {
  class FirstApp {
  private:
    LveWindow appWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
    LveDevice lveDevice{appWindow};
    LvePipeline lvePipeline{lveDevice,
                            "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv",
                            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
      
  public:
    static constexpr int HEIGHT = 600;
    static constexpr int WIDTH = 800;

    void run();
  };
}
