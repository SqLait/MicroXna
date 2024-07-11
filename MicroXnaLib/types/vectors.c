#include <math.h>
#include "../types/vectors.h"

/*Vectors work a little different. 
 *There is not Vec2 or Vec3. 
 *The dimension of the vector is based on the amount of arguments you give.
 */

static float AssignVecAxis(Vector* v, float value, int i) {
  switch (i) {
    case 0: return v->x = value;
    case 1: return v->y = value;
    case 2: return v->z = value;
    default: return 0.0f;
  }
}

static float GetVecAxis(Vector* v, int i) {
  switch (i) {
    case 0: return v->x;
    case 1: return v->y;
    case 2: return v->z;
    default: return 0.0f;
  }
}

float Magnitude(Vector* v) {
  float sX = v->x * v->x;
  float sY = v->y * v->y;
  float sZ = v->z * v->z;

  const float sV = sX + sY + sZ;
  const float result = sqrt(sV);

  return result;
}

Vector Normalize(Vector* v) {
  const float mag = Magnitude(v);

  v->x /= mag;
  v->y /= mag;
  v->z /= mag;

  return *v;
}

void VecZero(Vector* v) {
  for (int i = 0; i < 3; i++) {
    AssignVecAxis(v, 0.0f, i);
  }
}

float Dot(Vector* v1, Vector* v2) {
  return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
