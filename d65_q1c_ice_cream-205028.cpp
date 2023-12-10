#include <bits/stdc++.h>
using namespace std;

int main() {
   std::ios_base::sync_with_stdio(false); std::cin.tie(0);
   int n,m,start;
   int date, para, call;
   vector<int> keep(100001);
   cin >> n >> m >> start;
   keep[0] = start;
   for(int i=0;i<n;++i){
      cin >> date >> keep[date];
   }
   for (int i = 1; i < 100001;i++){
        if(keep[i] == 0){
            keep[i] = keep[i-1] + start;
        }
        else{
            start = keep[i];
            keep[i] = keep[i - 1] + start;
        }
    }
   for(int i=0;i<m;++i){
      cin >> para >> call;
      if(keep[call] >= para){
         cout << lower_bound(keep.begin(), keep.end(), para) - keep.begin() << ' ';
      } else {
         cout << lower_bound(keep.begin(), keep.end(), para + keep[call]) - keep.begin() << ' ';
        }
   }
}

