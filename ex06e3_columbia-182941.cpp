#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX)), w(r, vector<int>(c));
    vector<vector<vector<int>>> bef(r,vector<vector<int>> (c));
    vector<vector<vector<pair<int, int>>>> edge(r, vector<vector<pair<int, int>>>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> w[i][j];
            if (i > 0) edge[i][j].push_back(make_pair(i - 1, j)); // Above
            if (i < r - 1) edge[i][j].push_back(make_pair(i + 1, j)); // Below
            if (j > 0) edge[i][j].push_back(make_pair(i, j - 1)); // Left
            if (j < c - 1) edge[i][j].push_back(make_pair(i, j + 1)); // Right
        }
    }

    set<vector<int>> s;
    s.insert({w[0][0], 0, 0});
    dist[0][0] = w[0][0];

    while (!s.empty()) {
        auto tmp = *s.begin();
        s.erase(s.begin());
        int d = tmp[0], x = tmp[1], y = tmp[2];
        
        for (auto &e : edge[x][y]) {
            if (dist[e.first][e.second] > d + w[e.first][e.second]) {
                if (s.count({dist[e.first][e.second], e.first, e.second}) > 0)
                    s.erase({dist[e.first][e.second], e.first, e.second});
                dist[e.first][e.second] = d + w[e.first][e.second];
                bef[e.first][e.second] = {x, y};
                s.insert({dist[e.first][e.second], e.first, e.second});
            }
        }
    }
    for (auto &e : dist) {
        for (auto &f : e) {
            cout << f-w[0][0] << ' ';
        }
        cout << "\n";
    }

}
