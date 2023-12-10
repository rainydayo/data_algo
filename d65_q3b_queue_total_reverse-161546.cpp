#include "queue.h"
template<typename T>
void CP::queue<T>::reverse(){
aux==1 ? aux=0:aux=1;
}
template<typename T>
const T&CP::queue<T>::front() const{
return aux==0 ? mData[mFront]:mData[(mFront+mSize-1)%mCap];
}
template<typename T>
const T&CP::queue<T>::back() const{
return aux==0 ? mData[(mFront+mSize-1)%mCap]:mData[mFront];
}
template<typename T>
void CP::queue<T>::push(const T&element){
ensureCapacity(mSize+1);
if(aux==1){
mFront=(mFront+mCap-1)%mCap;
mData[mFront]=element;
}
else{
mData[(mFront+mSize)%mCap]=element;
}
mSize++;
}
template<typename T>
void CP::queue<T>::pop(){
if(aux==0){
mFront=(mFront+1)%mCap;
} 
mSize--;
}