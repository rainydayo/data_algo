#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int r, int c, vector<vector<int>>& v) {
    return a >= 0 && a < r && b >= 0 && b < c && v[a][b] == 0;
}

int bfs(int r, int c, int t, vector<vector<int>>& v) {
    queue<pair<int, int>> q;
    vector<vector<int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    int count = q.size();
    while (t-- > 0) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x,y] = q.front();
            q.pop();
            for (auto e : mov) {
                int nx = x + e[0], ny = y + e[1];
                if (check(nx, ny, r, c, v)) {
                    v[nx][ny] = 1;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c, t;
    cin >> r >> c >> t;
    vector<vector<int>> v(r, vector<int>(c));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> v[i][j];
        }           
    }
    cout << bfs(r,c,t,v) << endl;
}
