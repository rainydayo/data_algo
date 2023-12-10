#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //knapsack
    double n,w,a;
    cin >> w >> n;
    vector<vector<double>> v(n,vector<double>(3));
    for(int i=0; i<n; i++){
        cin >> v[i][1];
    }
    for(int i=0; i<n; i++){
        cin >> v[i][2];
        v[i][0] = v[i][1]/v[i][2];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    double ans = 0,ind = 0;
    for(auto e : v){
        if(ind + e[2] > w){
            ans += ((w-ind)/e[2])*e[1];
            break;
        } else {
            ans += e[1];
            ind += e[2];
        }
    }
    cout << fixed << setprecision(4) << ans;
}

