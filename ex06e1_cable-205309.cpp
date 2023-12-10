#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int i){
    if(parent[i] != i){
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void kruay(){
    int n,a;
    cin >> n;
    int E = (n*(n-1))/2;
    vector<vector<int>> res;
    vector<vector<int>> v;
    vector<int> parent(n);
    vector<int> rank(n);
    //input
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            cin >> a;
            vector<int> tmp = {a,i,j};
            v.push_back(tmp);
        }
    }
    //sort
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        parent[i]=i;
        rank[i]=0;
    }
    int aa = 0, bb = 0;
    while(aa < n-1 && bb < E){
        auto next = v[bb++];
        int x = find(parent,next[1]);
        int y = find(parent,next[2]);

        if(x != y){
            res.push_back(next);
            int xroot = find(parent,x);
            int yroot = find(parent,y);
            if(rank[xroot] < rank[yroot]){
                parent[xroot] = yroot;
            } else if (rank[xroot] > rank[yroot]){
                parent[yroot] = xroot;
            } else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
            aa++;
        }
    }
    int ans = 0;
    for(auto e : res){
        ans += e[0];
    }
    cout << ans;
}

void prim(){
    int n,a;
    cin >> n;
    set<vector<int>> res;
    vector<vector<pair<int,int>>> v(n);
    vector<int> cost(n,INT_MAX);
    vector<int> prev(n,-1);
    vector<bool> taken(n,false);
    //input
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            cin >> a;
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
    int ans = 0;
    for(int i=1; i<n; i++){
        ans += cost[i];
    }
    cout << ans;
}

int main() {
    //kruay();
    prim();
}

