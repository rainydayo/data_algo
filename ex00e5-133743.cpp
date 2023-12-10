#include<bits/stdc++.h>
using namespace std;

int pow(int a, int b){
    int ans = 1;
    for(int i=0; i<b; i++){
        ans *= a;
    }
    return ans;
}

string to_bi(int& n, int a){
    string ans = "";
    for (int i = n-1; i >= 0; i--) {
        int k = a >> i;
        if (k & 1)
            ans += "1";
        else
            ans += "0";
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m; 
    vector<string> v;
    string a = "";
    for(int i=0; i<m; i++){
        a += "1";
    }
    for(int i=0; i<pow(2,n); i++){
        string b = to_bi(n,i);
        if(b.find(a) != string::npos){
            v.push_back(b);
        }
    }
    for(auto e : v){
        cout << e << "\n";
    }
}
    