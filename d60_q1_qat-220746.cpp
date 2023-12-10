#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "queue.h"

template <typename T>
T CP::queue<T>::operator[](int idx) {
  return idx<0 ? mData[(mFront+mSize+idx)%mCap] : mData[(mFront+idx)%mCap];
}
#endif
