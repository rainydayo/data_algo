#include<bits/stdc++.h>
using namespace std;

int ans = 0;
vector<bool> col, kot, aus;

    void find_sol(int i, int n) {
        if (i == n) {
            ans++;
            return;
        }
        
        for (int j = 0; j < n; j++) {
            if (!col[j] && !kot[i+j] && !aus[i+n-j-1]) {
                col[j] = kot[i+j] = aus[i+n-j-1] = true;
                find_sol(i+1, n);
                col[j] = kot[i+j] = aus[i+n-j-1] = false;
            }
        }
    }
    
    int solveNQueens(int n) {
        col.assign(n, false);
        kot.assign(2*n-1, false); 
        aus.assign(2*n-1, false);
        find_sol(0, n);
        return ans; 
    }
int main(){
    int n;
    cin >> n; 
    cout << solveNQueens(n);
}
    