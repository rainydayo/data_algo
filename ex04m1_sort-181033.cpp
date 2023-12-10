#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int arr[3][3] = {0};
    cin >> n;
    vector<int> v;
    for(int i=0; i< n; i++){
        cin >> m;
        v.push_back(m);
        switch (m)
        {
        case 1:
            arr[0][0]++;
            break;
        case 2:
            arr[1][0]++;
            break;
        case 3:
            arr[2][0]++;
            break;
        }
    }
    for(int i=0; i<v.size(); i++){
        if(i<arr[0][0]){
            if(v[i]==2){
                arr[0][1]++;
            } else if(v[i]==3){
                arr[0][2]++;
            }
        } else if(i >= arr[0][0] && i < arr[1][0]+arr[0][0]){
            if(v[i]==1){
                arr[1][1]++;
            } else if(v[i]==3){
                arr[1][2]++;
            }
        } else {
            if(v[i]==1){
                arr[2][1]++;
            } else if(v[i]==2){
                arr[2][2]++;
            }
        }
    }
    int count = min(arr[0][1], arr[1][1]) + min(arr[0][2], arr[2][1]) + min(arr[1][2], arr[2][2]) + (2*abs(arr[0][1] - arr[1][1]));   
    /*for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << arr[i][j] << ' ';
        }
    }*/
    cout << count;
}
