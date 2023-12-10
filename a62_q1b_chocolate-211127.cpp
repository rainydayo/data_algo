#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000003;

int count_ways(int n, const vector<int>& S) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int size : S) {
            if (i - size >= 0) {
                dp[i] = (dp[i] + dp[i - size]) % MOD;
            }
        }
    }
    return dp[n];
}

int main() {
    int n,m,a,b;
    cin >> n >> m;
    vector<int> S;
    for(int i=0; i<m; i++){
        cin >> a;
        S.push_back(a);
    }
    cout << count_ways(n, S) << endl;
}
