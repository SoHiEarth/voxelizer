#include <voxelizer_vulkan.h>
#include <voxelizer_base.h>
#include <voxelizer_log.h>
#include <vulkan/vulkan.h>
#include <SDL.h>
#include <SDL_vulkan.h>

void create_window() {
  SDL_Init(SDL_INIT_VIDEO);
  vo_window = SDL_CreateWindow("Vulkan",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, 800, 600,
      SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
  if (vo_window == nullptr) {
    Voxelizer_Log("Could not create window: %s", SDL_GetError());
    exit(1);
  }
}

void create_instance() {
  VkApplicationInfo app_info = {};
  app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.pApplicationName = "Voxelizer";
  app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.pEngineName = "Voxelizer";
  app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo create_info = {};
  create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pApplicationInfo = &app_info;
  
  uint32_t sdl_extension_count = 0;
  if (!SDL_Vulkan_GetInstanceExtensions(vo_window, &sdl_extension_count, nullptr)) {
    Voxelizer_Log("Could not get SDL Vulkan extensions: %s", SDL_GetError());
    exit(1);
  }
  const char** sdl_extensions = new const char*[sdl_extension_count];
  if (!SDL_Vulkan_GetInstanceExtensions(vo_window, &sdl_extension_count, sdl_extensions)) {
    Voxelizer_Log("Could not get SDL Vulkan extensions: %s", SDL_GetError());
    exit(1);
  }
  create_info.enabledExtensionCount = sdl_extension_count;
  create_info.ppEnabledExtensionNames = sdl_extensions;

  if (vkCreateInstance(&create_info, nullptr, &vo_instance) != VK_SUCCESS) {
    Voxelizer_Log("Could not create Vulkan instance");
    exit(1);
  }
}

int Voxelizer_InitRenderer() {
  create_window();
  create_instance();

  return 0;
}

int Voxelizer_ExitRenderer() {
  vkDestroyInstance(vo_instance, nullptr);
  SDL_DestroyWindow(vo_window);
  return 0;
}
