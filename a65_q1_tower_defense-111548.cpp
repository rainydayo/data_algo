#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,m,w,a;
    cin >> n >> m >> k >> w;
    int arr[n] = {-1};
    int p[m];
    for(int i =0; i<m; i++){
        cin >> p[i];
    }
    for(int i =0; i<m; i++){
        cin >> a;
        if(arr[p[i]] == -1){
          arr[p[i]] = a;
        } else {
          arr[p[i]] += a;
        }
    }
    for(int i =0; i<k; i++){
        cin >> a;
        for(int j=a-w; j<=a+w; j++){
          if(j >= 0 && j < n){
            if(arr[j] > 0){
              arr[j]--;
              break;
            }
          }
        }
    }
    int count = 0;
    for(auto e : arr){
        if(e > 0)count+=e;
    }
    cout << count;
}
