#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,a;
    cin >> n;
    set<vector<long long>> res;
    vector<vector<pair<long long,long long>>> v(n);
    vector<long long> cost(n,INT_MAX);
    vector<long long> prev(n,-1);
    vector<bool> taken(n,false);
    //input
    vector<long long> keep(n);
    for(int i=0; i<n; i++){
        cin >> keep[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            a = keep[i] ^ keep[j];
            a*=-1;
            v[i].push_back(make_pair(j,a));
            v[j].push_back(make_pair(i,a));
        }
    }
    res.insert({0,0});
    while(!res.empty()){
        auto tmp = *res.begin();
        taken[tmp[1]] = true;
        res.erase(tmp);
        for(auto e : v[tmp[1]]){
            if(cost[e.first] > e.second && !taken[e.first]){
                if(res.find({cost[e.first] , e.first}) != res.end()){
                    res.erase({cost[e.first] , e.first});
                }
                cost[e.first] = e.second;
                prev[e.first] = tmp[1];
                res.insert({cost[e.first] , e.first});
            }
        }
    }
    long long ans = 0;
    for(int i=1; i<n; i++){
        ans += cost[i];
    }
    cout << ans*-1;

}

