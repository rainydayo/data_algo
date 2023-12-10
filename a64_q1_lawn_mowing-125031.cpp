#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,a,b;
    cin >> n >> m >> k;
    vector<long long int> v(n+1,0);
    for(int i=1; i<=n; i++){
        cin >> a;
        v[i] = v[i-1]+a+k;       
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        auto tmp = upper_bound(v.begin(), v.end(),b+v[a]);
        long long int ans;
        if(tmp == v.end()){
            ans = v[n]-v[a]-k*(n-a);
        } else {
            ans = *(--tmp)-v[a]-k*(tmp-v.begin()-a);
        }
        cout << ans << "\n";
    }
}

