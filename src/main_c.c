/***********************************
* main_c.c
*
* Test of C wrapper code of c++ code iou.
*
* Author: Melissa KOUASSI
* Github: https://github.com/CheckBoxStudio/IoU
*2018
*modified by MKouassi
***********************************/
#include "inc/wrapper_iou.h"

void c_demo(struct_vertex vertA, struct_vertex vertB){
    cpp_callback_demo(vertA, vertB);
}
void c_testSquare(const int width, const int height){
    cpp_callback_testSquare(width, height);
}

int main (){
    c_testSquare(400, 400);
    struct_vertex vertC = {{628.84, 23.25}, {774.17, 117.69}, {624.15, 351.74}, {476.82, 257.30}};
    struct_vertex vertD = {{721.76, 178.29}, {884.73, 275.97}, {739.23, 518.70}, {576.26, 421.02}};
	c_demo(vertC, vertD);

    return 0;
}
