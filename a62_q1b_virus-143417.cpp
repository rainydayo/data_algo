#include <bits/stdc++.h>
using namespace std;

string reverse(string s){
  int a=0,b=s.length()-1;
  string c = s;
  while(a<b){
    swap(c[a], c[b]);
    a++;b--;
  }  
  return c;
}


bool check(string s, int k){
  if(k == 1){
    return s == "01";
  }
  string a = s.substr(0,s.length()/2);
  string b = s.substr(s.length()/2);
  bool x = check(a,k-1);
  bool y = check(b,k-1);
  bool z = check(reverse(a),k-1);
  return y && (x || z);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    string num;
    cin >> n >> k;
    for(int i=0; i<n; i++){
      string x = "";
      for(int i=0; i<pow(2,k); i++){
        cin >> num;
        x += num;
      }
      if(check(x,k)){
        cout << "yes" << "\n";
      } else {
        cout << "no" << "\n";
      }
    }
}
