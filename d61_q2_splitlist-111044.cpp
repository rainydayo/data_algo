void splitList(list<T>& list1, list<T>& list2) {
    int mid = (size()+1)/2;
    auto curr = begin();
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    for(int i=0;i<mid;i++){
        curr++;
    }
    curr.ptr->prev->next = list1.mHeader;
    list1.mHeader->prev = curr.ptr->prev;

    list2.mHeader->prev->next = curr.ptr;
    curr.ptr->prev = list2.mHeader->prev;
    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;
    mHeader->next=mHeader;
    mHeader->prev=mHeader;
    list2.mSize+=(mSize-mid);
    mSize=0;
    list1.mSize+=mid;

}