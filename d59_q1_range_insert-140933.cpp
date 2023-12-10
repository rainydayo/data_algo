#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  size_t index = last-first;
  mCap = mSize + index;
  T* tmp_mData = new T[mCap];
  int i=0;
  for(int j=0; j<position-begin(); j++){
    tmp_mData[i] = mData[i];
    i++;
  }
  for(auto j=first; j<last; j++){
    tmp_mData[i] = *j;
    i++;
  }
  for(auto j=position; j<end(); j++){
    tmp_mData[i] = *j;
    i++;
  }
  delete [] mData;
  mData = tmp_mData;
  mSize = mCap;
}

#endif
