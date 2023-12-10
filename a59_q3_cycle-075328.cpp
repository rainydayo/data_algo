#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int a, vector<vector<int>>& ed, vector<int>& visited, int len) {
    visited[n] = len;
    for (int f : ed[n]) {
        if (visited[f] == 0) {
            int l = dfs(f, n, ed, visited, len + 1);
            if (l > 0) return l;
        } else if (f != a) {
            return len - visited[f] + 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b;
    cin >> n;
    vector<vector<int>> ed(n);
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bool ind = false;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            int len = dfs(i, -1, ed, visited, 1);
            if (len > 0) {
                ind = true;
                cout << len << "\n";
            }
        }
        if(ind)break;
    }
}
