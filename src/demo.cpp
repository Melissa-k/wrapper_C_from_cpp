/***********************************
* demo.h
*
* Test demo of iou.
*
* Author: WeiQM (weiquanmao@hotmail.com)
* Github: https://github.com/CheckBoxStudio/IoU
*2018
*modified by MKouassi
***********************************/
#include "inc/demo.h"
#include <iostream>
#include <random>

using namespace IOU;
using namespace std;

std::default_random_engine _rand_engine(2018);
std::normal_distribution<float> _rand_dis_n(0.0, 1.0);
std::uniform_real_distribution<float> _rand_dis_u(0.1, 0.9);
float randMeN() {
    float a = _rand_dis_n(_rand_engine);
    if (a>1.0)
        a = 1.0;
    if (a<-1.0)
        a = 1.0;
    return a;
}
float randMeU() {
    return _rand_dis_u(_rand_engine);
}


void squareVertex(const int w, const int h, Vertexes &vert)
{
    int h1 = randMeN()*0.2*h + 0.25*h;
    int h2 = randMeN()*0.2*h + 0.75*h;
    if (h1<0) h1 = 0;
    if (h1 >= h) h1 = h - 1;
    if (h2<0) h2 = 0;
    if (h2 >= h) h2 = h - 1;
    if (h1>h2) {
        int temp = h1;
        h1 = h2;
        h2 = temp;
    }
    int w1 = randMeN()*0.2*w + 0.25*w;
    int w2 = randMeN()*0.2*w + 0.75*w;
    if (w1<0) w1 = 0;
    if (w1 >= w) w1 = w - 1;
    if (w2<0) w2 = 0;
    if (w2 >= w) w2 = w - 1;
    if (w1>w2) {
        int temp = w1;
        w1 = w2;
        w2 = temp;
    }

    Vertexes _vert;
    _vert.reserve(4);
    _vert.push_back(IOU::Point(w1, h1));
    _vert.push_back(IOU::Point(w1, h2));
    _vert.push_back(IOU::Point(w2, h2));
    _vert.push_back(IOU::Point(w2, h1));
    vert.swap(_vert);
}
void conQuadVertex(const int w, const int h, Vertexes &vert)
{
    while (1) {
        Vertexes _vert;
        _vert.reserve(4);
        _vert.push_back(IOU::Point(w*randMeU(), h*randMeU()));
        _vert.push_back(IOU::Point(w*randMeU(), h*randMeU()));
        _vert.push_back(IOU::Point(w*randMeU(), h*randMeU()));
        _vert.push_back(IOU::Point(w*randMeU(), h*randMeU()));
        beInSomeWiseEx(_vert, ClockWise);
        if (whichWiseEx(_vert) != NoneWise) {
            vert.swap(_vert);
            break;
        }
    }
}



void testSquare(const int width, const int height)
{
    printf(" Times with Image Size [%dx%d]\n",
        width, height);
    printf("No.    Method   Area_1   Area_2   Area_1x2  Area_1+2   IOU\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    //int C_n1, C_n2, C_i12, C_u12;
    int E_n1, E_n2, E_i12, E_u12;
    double  E_iou;//C_iou,

    Vertexes vert1, vert2;
    squareVertex(width, height, vert1);
    squareVertex(width, height, vert2);

    E_n1 = areaEx(vert1);
    E_n2 = areaEx(vert2);
    E_i12 = areaIntersectionEx(vert1, vert2);
    E_u12 = areaUnionEx(vert1, vert2);
    E_iou = iouEx(vert1, vert1);
    printf("IOU  is  :  %f\n", E_iou);
}

void test_demo(Vertexes &vertA, Vertexes &vertB)
{
    double  E_iou; //C_iou,
    E_iou = iouEx(vertA, vertB);
    printf("IOU Demo is  :  %f\n", E_iou);
}

struct_of_vertexes convert_struct_to_vertexes(struct_vertex vertA, struct_vertex vertB){
    Vertexes _vertA, _vertB;
    _vertA.reserve(4);
    _vertA.push_back(IOU::Point(vertA.point_ul[0], vertA.point_ul[1]));
    _vertA.push_back(IOU::Point(vertA.point_ur[0], vertA.point_ur[1]));
    _vertA.push_back(IOU::Point(vertA.point_ll[0], vertA.point_ll[1]));
    _vertA.push_back(IOU::Point(vertA.point_lr[0], vertA.point_lr[1]));
    _vertB.reserve(4); 
    _vertB.push_back(IOU::Point(vertB.point_ul[0], vertB.point_ul[1]));
    _vertB.push_back(IOU::Point(vertB.point_ur[0], vertB.point_ur[1]));
    _vertB.push_back(IOU::Point(vertB.point_ll[0], vertB.point_ll[1]));
    _vertB.push_back(IOU::Point(vertB.point_lr[0], vertB.point_lr[1]));
    struct_of_vertexes sv({_vertA, _vertB});
    return sv;
}
