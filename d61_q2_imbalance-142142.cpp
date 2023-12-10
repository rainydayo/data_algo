// Your code here

int compute(node* n, KeyT& ans, int& max){
    if(!n) return -1;
    int hl = compute(n->left, ans,max);
    int hr = compute(n->right, ans, max);
    int imb = hl-hr;
    if(imb<0) imb = -imb;
    int h = 1 + ((hl>hr) ? hl : hr);
    if(imb > max){
        ans = n->data.first;
        max = imb;
    } else {
        if(imb == max){
            if(mLess(n->data.first, ans)){
                ans = n->data.first;
            }
        }
    }
    return h;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int max = 0;
    KeyT ans = mRoot->data.first;
    compute(mRoot,ans,max);
    return ans;

}
