#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "queue.h"
#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    int a = mData[(pos+mFront) % mCap];
  for(int i = pos+mFront;i>mFront; i--){
    mData[i%mCap] = mData[(i-1)%mCap];
  }
  mData[mFront] = a;
}

#endif
