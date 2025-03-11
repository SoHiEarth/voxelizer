#include <voxelizer_base.h>

SDL_Window* vo_window;

VkInstance vo_instance;
VkSurfaceKHR vo_surface;
VkDevice vo_device;
VkQueue vo_graphics_queue;
VkSwapchainKHR vo_swapchain;
VkImageView vo_swapchain_image_view[VOXELIZER_MAX_FRAMES_IN_FLIGHT];
VkRenderPass vo_render_pass;
VkPipeline vo_graphics_pipeline;
VkPipelineLayout vo_pipeline_layout;
VkCommandPool vo_command_pool;
VkCommandBuffer vo_command_buffer;
VkFramebuffer vo_framebuffer;
VkFence vo_fence;

