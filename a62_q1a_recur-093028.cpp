#include <bits/stdc++.h>
using namespace std;

int x,n,m;

void the_matrix(vector<vector<int>>& v, int a, int b,int row, int bottom,int left){
  if(a == 0){
    v[row][left] = b;return;
  }
  int tmp = pow(2,a-1);
  the_matrix(v,a-1,b,row,bottom+tmp,left);
  the_matrix(v,a-1,b-1,row,bottom+tmp,left+tmp);
  the_matrix(v,a-1,b+1,row+tmp,bottom,left);
  the_matrix(v,a-1,b,row+tmp,bottom,left+tmp);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    x = pow(2,n);
    vector<vector<int>> v(x+1, vector<int>(x,0));
    the_matrix(v,n,m,0,x,0);
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            cout << v[i][j] << ' ';
        }
        cout << "\n";
    }
}
