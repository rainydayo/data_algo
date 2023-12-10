#include <bits/stdc++.h>
using namespace std;
  
void check(int n, int m, vector<int>&s, int a){
    if(m == a){return;}
    s.push_back(m);
    if(2*m+1 < n){
        check(n,2*m+1, s, a);
    } 
    if(2*m+2 < n){
        check(n,2*m+2, s, a);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    vector<int> s;
    cin >> n >> m;
    check(n,0,s,m);
    sort(s.begin(), s.end());
    cout << s.size() << "\n";
    for(auto e : s){
        cout << e << ' ';
    }
}
