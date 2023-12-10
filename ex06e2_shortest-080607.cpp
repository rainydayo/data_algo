#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s, a, b, c;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> edge(n);
    vector<vector<int>> D(n, vector<int>(n, INT_MAX));
    vector<int> P(n, -1);

    while (m--) {
        cin >> a >> b >> c; // directed graph
        edge[a].push_back(make_pair(b, c)); // a = start, b = destination, c = weight
    }

    D[0][s] = 0;

    for (int i = 1; i < n; i++) {
        D[i] = D[i - 1];
        for (int j = 0; j < n; j++) {
            for (auto e : edge[j]) {
                if (D[i - 1][j] != INT_MAX && D[i][e.first] > D[i - 1][j] + e.second) {
                    D[i][e.first] = D[i - 1][j] + e.second;
                    P[e.first] = j;
                }
            }
        }
    }

    bool ind = false;
    vector<int> dist(n);

    /*for(auto e : D){
        for(int f : e){
            cout << f << ' ';
        }cout << "\n";
    }*/

    for(int i=0; i<n; i++){
        dist[i] = D[n-1][i];
    }
    // detect neg
    
    for(int i=0; i<n; i++){
      for(auto e : edge[i]){
        if(dist[e.first] > dist[i] + e.second)ind = true;
      }
    }
    /*for(int e : dist){
        cout << e << ' ';
    }*/

    if (ind) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (D[n - 1][i] == INT_MAX) {
                cout << -1 << ' ';
            } else {
                cout << D[n - 1][i] << ' ';
            }
        }
        cout << "\n";
    }

    return 0;
}
