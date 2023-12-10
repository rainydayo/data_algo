#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a;
    cin >> n;
    vector<vector<int>> v(2*n-1);
    int maxnum = -1000;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a;
            v[n-1-i+j].push_back(a);
        }
    }
    for(int i=0; i<v.size(); i++){
        int currMax = v[i][0];
        for (int j = 1; j < v[i].size(); ++j) {
            currMax = max(v[i][j], v[i][j] + currMax);
            if (currMax > maxnum) {
                maxnum = currMax;
            }
        }
    }
    cout << maxnum;
    
}