#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  auto curr = ls.begin();
  int idx = ls.size();
  while(curr != ls.end()){
    mHeader->prev->next = (*curr).mHeader->next;
    (*curr).mHeader->next->prev = mHeader->prev;
    mHeader->prev = (*curr).mHeader->prev;
    
    (*curr).mHeader->prev->next = mHeader;
    (*curr).mHeader->prev = (*curr).mHeader;
    (*curr).mHeader->next = (*curr).mHeader;
    mSize += (*curr).mSize;
    (*curr).mSize = 0;
    curr++;
  }

}

#endif
