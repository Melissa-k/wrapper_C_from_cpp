#ifndef WRAPPER_IOU_H
#define WRAPPER_IOU_H

#ifdef __cplusplus
  #include "inc/demo.h"
#else
  typedef struct struct_vertex{
    double point_ul[2];
    double point_ur[2];
    double point_ll[2];
    double point_lr[2];
  }struct_vertex;
#endif

#ifdef __cplusplus
extern "C" {
#endif
#if defined(__STDC__) || defined(__cplusplus)
  extern void c_demo(struct_vertex vertA, struct_vertex vertB);
  extern void cpp_callback_demo(struct_vertex vertA, struct_vertex vertB);
  /*extern void c_Guy_test();
  extern void cpp_callback_c_Guy_test();*/
  extern void c_testSquare(const int width, const int height);
  extern void cpp_callback_testSquare(const int width, const int height);

#else
  extern void c_demo();             /* K&R style */
  extern void cpp_callback_demo();
  extern void c_testSquare();           /* K&R style */
  extern void cpp_callback_testSquare();
#endif
#ifdef __cplusplus
}
#endif

#endif // WRAPPER_IOU_H
