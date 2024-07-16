#define VECTORS_H
#ifdef VECTORS_H
typedef struct {
  float x;
  float y;
  float z;
} Vector;

typedef Vector Vector2;
typedef Vector Vector3;

float Magnitude(Vector* v);
Vector Normalize(Vector* v);
void VecZero(Vector* v);
float Dot(Vector* v1, Vector* v2);
#endif
