#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"

#include <memory>

namespace lve {
  class FirstApp {
  private:
    LveWindow appWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
    LveDevice lveDevice{appWindow};
    LveSwapChain lveSwapChain{lveDevice, appWindow.getExtent()};
    std::unique_ptr<LvePipeline> lvePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    /*
    LvePipeline lvePipeline{lveDevice,
                            "shaders/simple_shader.vert.spv",
                            "shaders/simple_shader.frag.spv",
                            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
     */
     
     void createPipelineLayout();
     void createPipeline();
     void createCommandBuffers();
     void drawFrame();

  public:
    static constexpr int HEIGHT = 600;
    static constexpr int WIDTH = 800;

    FirstApp();
    ~FirstApp();

    FirstApp(const FirstApp&) = delete;
    FirstApp& operator=(FirstApp&) = delete;

    void run();
  };
}
