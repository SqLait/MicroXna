#include <stdint.h>
#include "XnaMath.h"

/*For the engine we use quake III sqrt with 2 itters for better performance.*/
float Xna_Rsqrt(float number) {
  union {
    float    f;
    uint32_t i;
  } conv = { .f = number };

  conv.i  = 0x5f3759df - (conv.i >> 1);
  
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);

  return conv.f;
}

float Xna_Sqrt(float number) {
  union {
    float f;
    uint32_t i;
  } conv = { .f = number };

  conv.i = 0x5f3759df - (conv.i >> 1);

  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);

  return number * conv.f;
}
