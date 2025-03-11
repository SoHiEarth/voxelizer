#include <voxelizer.h>

int main() {
  Voxelizer_Init();
  Voxelizer_Load();
  Voxelizer_Run();
  Voxelizer_Unload();
  Voxelizer_Exit();
  return 0;
}
