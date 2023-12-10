#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "priority_queue.h"
using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  size_t a = 0;
  for(int i = 0; i < mSize; i++){
    if(mLess(mData[pos], mData[i]))a++;
  }
  return a;
}

#endif
