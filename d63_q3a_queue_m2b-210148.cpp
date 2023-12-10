#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "queue.h"
#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  int a = mData[(pos+mFront) % mCap];
  for(size_t i = pos+mFront;i<mFront+mSize-1; i++){
    mData[i%mCap] = mData[(i+1)%mCap];
  }
  mData[(mFront + mSize - 1) % mCap] = a;
}

#endif
