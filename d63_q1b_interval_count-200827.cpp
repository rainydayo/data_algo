#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void insort(vector<int> & v, int e) {
 int mid, left = 0, right = v.size();
 while (left < right) {
 mid = (left + right - 1) / 2;
 if (e < v[mid])
 right = mid;
 else if (e > v[mid])
 left = mid+1;
 else
 left = right = mid;
 }
 v.insert(v.begin()+left, e);
}

int main() {
   std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m, k, l;
 std::cin >> n >> m >> k;
 vector<int> nn;
 for(int i=0; i<n; i++){
    cin >> l;
    insort(nn, l);
 }
 for(int i=0; i<m; i++){
    cin >> l;
    auto itr1 = lower_bound(nn.begin(), nn.end(), l-k);
    auto itr2 = upper_bound(nn.begin(), nn.end(), l+k);
    int count = itr2-itr1;
    std::cout << count << " ";
 }

}
