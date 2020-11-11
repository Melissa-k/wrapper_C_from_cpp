#include "inc/wrapper_iou.h"


void cpp_callback_demo(struct_vertex vertA, struct_vertex vertB){
    struct_of_vertexes sv = convert_struct_to_vertexes(vertA, vertB);
    IOU::Vertexes _vertA = sv.vertA;
    IOU::Vertexes _vertB = sv.vertB;
    test_demo(_vertA, _vertB);
}

void cpp_callback_testSquare(const int width, const int height){
    testSquare(width, height);
}
