#ifndef BASE_H
#define BASE_H
#define VOXELIZER_MAX_FRAMES_IN_FLIGHT 2
#include <SDL.h>
#include <vulkan/vulkan.h>

/* WINDOW HANDLING */
extern SDL_Window* vo_window;

/* RENDERING */
extern VkInstance vo_instance;
extern VkSurfaceKHR vo_surface;
extern VkDevice vo_device;
extern VkQueue vo_graphics_queue;
extern VkSwapchainKHR vo_swapchain;
extern VkImageView vo_swapchain_image_view[VOXELIZER_MAX_FRAMES_IN_FLIGHT];
extern VkRenderPass vo_render_pass;
extern VkPipeline vo_graphics_pipeline;
extern VkPipelineLayout vo_pipeline_layout;
extern VkCommandPool vo_command_pool;
extern VkCommandBuffer vo_command_buffer;
extern VkFramebuffer vo_framebuffer;
extern VkFence vo_fence;
#endif // BASE_H
