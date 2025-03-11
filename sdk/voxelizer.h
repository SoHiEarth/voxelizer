#ifndef VOXELIZER_H
#define VOXELIZER_H

#ifdef WIN32
  #ifdef VOXELIZER_EXPORTS
    #define VOXELIZER_API __declspec(dllexport)
  #else
    #define VOXELIZER_API __declspec(dllexport)
  #endif
#else
    #define VOXELIZER_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

VOXELIZER_API int Voxelizer_Init();
VOXELIZER_API int Voxelizer_Run();
VOXELIZER_API int Voxelizer_Load();
VOXELIZER_API int Voxelizer_Unload();
VOXELIZER_API int Voxelizer_Exit();

#ifdef __cplusplus
}
#endif

#endif // VOXELIZER_H
