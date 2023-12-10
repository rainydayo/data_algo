#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int question,n,a,b,c;
    cin >> question;
    while(question--){
        cin >> n;
        vector<vector<double>> curr(n,vector<double>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> curr[i][j];
            }
        }
        bool yes = false;
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    curr[i][j] = max(curr[i][j], curr[i][k] * curr[k][j]);
                    if(curr[j][j] > 1){cout << "YES" << "\n";yes = true;break;}
                }
                if(yes)break;
            }
            if(yes)break;
        }
        if(!yes)cout << "NO" << "\n";
    }
}

