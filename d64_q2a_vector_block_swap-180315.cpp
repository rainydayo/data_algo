#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(a < this->begin() || a >= this->end() || b < this->begin() || b >= this->end() ||
    a + m - 1 > this->end() || b + m - 1> this->end() ||
    !(a + m - 1 < b || b + m - 1 < a) || m <= 0){
    return false;
  } else {
    CP::vector<T> tempa(m);
    for(int i=0; i< m; i++){
      tempa[i] = mData[a-begin()+i];
    }
    for(int i=0; i< m; i++){
      mData[a-begin()+i] = mData[b-begin()+i];
    }
    for(int i=0; i< m; i++){
      mData[b-begin()+i] = tempa[i];
    }
    return true;
  }

}

#endif
