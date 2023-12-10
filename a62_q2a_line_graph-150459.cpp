#include <bits/stdc++.h>
using namespace std;
int c1,c2,nodes;

void dfs(int a, map<int,vector<int>>& v, vector<bool>& visited){
    nodes++;
  if (v[a].size() == 1) {
    c1++;
  } else if (v[a].size() == 2) {
    c2++;
  }
        for(auto f : v[a]){
            if(visited[f] == false){
                visited[f] = true;
            dfs(f,v,visited);
        }
        }     
}

bool check(int a, map<int,vector<int>>& v, vector<bool>& visited) {
  visited[a] = true;
    c1 = 0; c2 = 0; nodes = 0;
  dfs(a,v,visited);
  return ( nodes == 1 || (c1 == 2 && c2 == nodes-2));
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
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            if(check(i,v,visited))count++;               
        }
    }
    cout << count;
}