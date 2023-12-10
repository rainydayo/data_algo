#include <iostream>
#include <vector>

using namespace std;

void somchai(int N,vector<int> &sol,int len,int sum, int& count) {
  if (len < N) {
    if (sum == N) {
      //display the seuquence
      /*for (int i = 0;i < len;i++) {
        cout << sol[i] << " ";
      }
      cout << endl;*/
      count++;
    }
    if (sum < N) {
      int start = 1;
      if (len > 0) start = sol[len-1];
      for (int j = start;j <= N;j++) {
        sol[len] = j;
        somchai(N,sol,len+1,sum + j,count);
      }
    }
  } else {
    if (sum == N) {
      //display the seuquence
      /*for (auto &x : sol) { 
        cout << x << " ";
      }
      cout << endl;*/
      count++;
    }
  }
}

int main() {
  int N;
  cin >> N;
  int count = 0;
  vector<int> v(N);
  somchai(N,v,0,0,count);
  cout << count << endl;
}