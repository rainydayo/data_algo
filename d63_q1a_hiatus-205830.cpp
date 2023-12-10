#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> s(n);
    while (n--) {
        cin >> a >> b;
        s[n] = (100 * a + b);
    }
    sort(s.begin(), s.end());
    while (m--) {
        cin >> a >> b;
        int val = 100 * a + b;
        auto x = lower_bound(s.begin(), s.end(), val);
        if (val == *x) {
            cout << "0 0 ";
        } else if (val < *(s.begin())) {
            cout << "-1 -1 ";
        } else {
            cout << *(--x) / 100 << ' ' << *(x) % 100 << ' ';
        }
    }
}
