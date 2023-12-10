#include <bits/stdc++.h>
using namespace std;

vector<int> tmp;

void dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dest, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INT_MAX);

    pq.push(make_pair(0, src));
    distance[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& p : graph[u]) {
            int v = p.first;
            int weight = p.second;

            if (distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    tmp.push_back(distance[dest]); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,a;
    cin >> r;
    vector<vector<pair<int, int>>> graph(r + 1);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=r; j++){
            cin >> a;
            if(a > 0){
                graph[i].push_back(make_pair(j,a));
            }
        }
    }
    for(int i=2; i<=r; i++){
        dijkstra(graph,1,i,r);
    }
    auto ans = max_element(tmp.begin(),tmp.end());
    if(*ans == INT_MAX){
      cout << -1;
    } else {
      cout << *ans; 
    }
}
