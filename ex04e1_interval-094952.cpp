#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0; i<n;i++){
        cin >> v[i][1];
    }
    for(int i=0; i<n;i++){
        cin >> v[i][0];
    }
    sort(v.begin(),v.end());
    int ans = 0,prev = 0;
    for(auto &e : v){
        if(e[1] >= prev){
            prev = e[0];
            ans++;
        }
    }
    cout << ans;
}

