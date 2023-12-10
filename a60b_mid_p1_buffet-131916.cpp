#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> v(f);
    for(int i=0; i<f; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int prev = v[0];n=0;
    for(auto &e : v){
        if(e > prev+2*w){
            n++;
            prev = e;
        }
    }
    n++;
    cout << n;

}


