#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <vector>
template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    T* v = new T[b]();
    int pos = 0;
    while(pos < b){
        v[pos] = top();
        pop();
        pos++;
    }
    auto x = top();
    push(x);
    for(int i =b-1;i>=a;i--){
        
            push(v[i]);
            push(v[i]);
        }
    for(int i = a-1; i >= 0; i--){
      push(v[i]);
    }
}

#endif
