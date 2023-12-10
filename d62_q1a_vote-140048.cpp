#include <bits/stdc++.h>
using namespace std;

int main() {
   std::ios_base::sync_with_stdio(false); std::cin.tie(0);
   int k,n;
   string name;
   cin >> n >> k;
   std::map<string,int> m;
   for(int i=0; i<n; ++i){
      cin >> name;
      m[name]++;
   }
   vector<int> v;
   for(auto f : m){
      v.push_back(f.second);
   }
   int size = 0; bool abc = true;
   if(v.size() > k){
      size = v.size()-k;
      abc = false;
   }
   sort(v.begin(), v.end());
   
   for(auto e : v){
      if(size == 0){
         cout << e;
         break;
      }
      size--;
   }
}
