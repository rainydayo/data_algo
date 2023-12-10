#include <bits/stdc++.h>
using namespace std;

const unsigned long long MOD = 100000007;

unsigned long long recur(int n){
    if(n == 1) return 3;
    if(n == 2) return 7;
    if(n == 3) return 17;
    unsigned long long f1 = 17;
    unsigned long long f2 = 7;
    unsigned long long f3 = 3;
    unsigned long long f;
    for(int i = 3; i < n; i++){
        f = (3 * f1 % MOD - f2 + MOD - f3 + MOD) % MOD;
        f3 = f2;
        f2 = f1;
        f1 = f;
    }
    return f;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    unsigned long long ans = recur(n);
    cout << ans;
}
