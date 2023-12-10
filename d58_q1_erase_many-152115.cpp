#ifndef __STUDENT_H_
#define __STUDENT_H_
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  if (pos.empty()) return;

  int a = 0; 
  int b = 0; 
  for (int i = 0; i < mSize; ++i) {

    if (b < pos.size() && pos[b] == i) {
      b++;
      continue;
    }

    if (i != a) {
      mData[a] = std::move(mData[i]);
    }
    a++;
  }
  mSize = a;
}


#endif
