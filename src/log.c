#include <voxelizer_log.h>
#include <stdio.h>
#include <string.h>
void Voxelizer_Log(const char* format, ...) {
  va_list args;
  va_start(args, format);
  const char* msg = strcpy(format, "Voxelizer: ");
  printf(msg, args);
  va_end(args);
}
