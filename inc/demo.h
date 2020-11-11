#ifndef TEST_H
#define TEST_H
#include "inc/IOU.h"

typedef struct _struct_of_vertexes{
    IOU::Vertexes vertA;
    IOU::Vertexes vertB;
}struct_of_vertexes;

typedef struct _struct_vertex{
  double point_ul[2];
  double point_ur[2];
  double point_ll[2];
  double point_lr[2];
}struct_vertex;

float randMeN();
float randMeU();
void squareVertex(const int w, const int h, IOU::Vertexes &vert);
void conQuadVertex(const int w, const int h, IOU::Vertexes &vert);
void testSquare(const int width, const int height);
struct_of_vertexes convert_struct_to_vertexes(struct_vertex vertA, struct_vertex vertB);
void test_demo(IOU::Vertexes &vertA, IOU::Vertexes &vertB);

#endif // TEST_H
