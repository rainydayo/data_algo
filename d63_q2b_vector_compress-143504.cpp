#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    mCap = mSize;
    T* tmp_mData = new T[mCap];
    for(int i=0; i<mSize; i++){
        tmp_mData[i] = mData[i];
    }
    delete [] mData;
    mData = tmp_mData;
}

#endif