void shift(int k) {
	// TODO: Add your code here
	if(mSize == 0) return;
	auto itr = begin();
	size_t pos;
	if(k<0){
		pos = mSize-((k*-1)%mSize);pos%=mSize;
	} else {
		pos = k%mSize;
	}
	if(pos != 0){
	for(int i=0;i<pos;i++){
		itr++;
	}

	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;
	itr.ptr->prev->next = mHeader;
	mHeader->prev = itr.ptr->prev;
	itr.ptr->prev = mHeader;
	mHeader->next = itr.ptr;
	}
}