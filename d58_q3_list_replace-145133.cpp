void replace(const T& x, list<T>& y) {
  auto it = begin();
  while(it!=end()){
    if(*it==x){
      for(auto l:y){
        insert(it,l);}
        it=erase(it);
    } else {it++;}
  }
}
