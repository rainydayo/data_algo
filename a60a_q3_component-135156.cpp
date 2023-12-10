#include <bits/stdc++.h>
using namespace std;

void dfs(int a, map<int,vector<int>>& v, vector<bool>& visited){
    visited[a] = true;
        for(auto f : v[a]){
            if(visited[f] == false){
            dfs(f,v,visited);
        }
        }     
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    map<int, vector<int>> v;
    vector<bool> visited(n,false);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int count = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            count++;
            dfs(i,v,visited);
        }
    }
    cout << count;
}