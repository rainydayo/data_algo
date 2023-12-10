#include <bits/stdc++.h>
using namespace std;

int MOD = 32717;

void recur(int k, int n, vector<int>& c, vector<int>& a){
    vector<long long> tmp(n+1);
    for(int i = 0; i<=n; i++){
        if(i < k){
            tmp[i] = a[i]%MOD;
        } else {
            for(int j=1; j<=k; j++){
                tmp[i] += ((c[j]%MOD) * tmp[i-j])%MOD;
                tmp[i] %= MOD;
            }
            
        }
    }
    cout << tmp[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k,n;
    cin >> k >> n;
    vector<int> c(k+1) , a(k);
    for(int i=1; i<=k; i++){
        cin >> c[i];
    }
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    recur(k,n,c,a);
}
