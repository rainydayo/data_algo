#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dest, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& p : graph[u]) {
            int v = p.first;
            int weight = p.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << dist[dest] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,l;
    cin >> n >> l;
    vector<vector<pair<int, int>>> graph(3);
    graph[1].push_back(make_pair(2,l));
    graph[2].push_back(make_pair(1,l));
    for(int i=3; i<=n; i++){
        graph.resize(i+1);
        int v,w,num;
        cin >> num;
        while(num--){
            cin >> v >> w;
            graph[i].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(i,w));
        }
        dijkstra(graph,1,2,i);
    }

}
