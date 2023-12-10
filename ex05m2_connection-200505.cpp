#include <bits/stdc++.h>
using namespace std;
    int n,m,k,a,b;

void dfs(int a,vector<vector<int>>& v, vector<bool>& visited,int len){
    if (len == k) {
        return;
    }
    visited[a] = true;
    for (auto f : v[a]) {
        visited[f] = true;
            dfs(f, v, visited, len + 1);
        }   
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int max_count = 0;
    cin >> n >> m >> k;
    vector<vector<int>> v(n);
    vector<bool> visited(n,false);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        int count = 0;
        dfs(i,v,visited,0);
        for(int j=0; j<n; j++){
            if(visited[j]){
                count++;
                visited[j] = false;
            }
        }
        if(count > max_count)max_count = count;
    }
    cout << max_count;
}