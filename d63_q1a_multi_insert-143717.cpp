#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
 vector<int> temp;
 int a = position;
    for(auto e : v){
        if(a==0){break;}
        temp.push_back(e);
        a--;
    }
    for(int i=0; i<count; i++){
        temp.push_back(value);
    }
    for(auto itr = v.begin()+position; itr<v.end(); itr++){
        temp.push_back(*itr);
    }
    v=temp;
}
int main() {
 std::ios_base::sync_with_stdio(false);
 cin.tie(0);
 int n,value,position,count;
 cin >> n >> value >> position >> count;
 vector<int> v(n);
 for (int i = 0; i < n; i++) cin >> v[i];
 multiple_add(v,value,position,count);
 cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
 for (auto &x : v) cout << x << " ";
 cout << endl;
}