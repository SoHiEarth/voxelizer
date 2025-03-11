#ifndef Voxelizer_EXPORTS
#define Voxelizer_EXPORTS
#endif
#include <voxelizer.h>
#include <voxelizer_vulkan.h>
int Voxelizer_Init() {
  Voxelizer_InitRenderer();
  return 0;
}
