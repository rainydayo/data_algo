#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main() {
   std::ios_base::sync_with_stdio(false); std::cin.tie(0);
   int n, num;
   bool index = true;
   std::set<int> v;
   std::cin >> n;
   for(int i=0; i<n; i++){
      std::cin >> num;
      if(num > n || num < 1){index = false;}
      v.insert(num);
   }
   if(v.size() == n && index){std::cout << "YES";} else {std::cout << "NO";}
}
