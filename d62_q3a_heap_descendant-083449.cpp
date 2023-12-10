#include <bits/stdc++.h>
using namespace std;

void descendant(int n, int m, vector<int>& s){
   s.push_back(m);
   if(2*m+1 < n){
      descendant(n,2*m+1,s);
   }
   if(2*m+2 < n){
      descendant(n,2*m+2,s);
   }
}

int main() {
   std::ios_base::sync_with_stdio(false); std::cin.tie(0);
   int n,m;
   vector<int> s;
   cin >> n >> m;
   descendant(n,m,s);
   sort(s.begin(), s.end());
   cout << s.size() << endl;
   for(auto e : s){
      cout << e << ' ';
   }
}
