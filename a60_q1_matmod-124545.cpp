#include <bits/stdc++.h>
using namespace std;

vector<int> square_M(const vector<int>& v,int k){
    vector<int> ans(4);
    ans[0] = ((v[0]*v[0]) + (v[1]*v[2]))%k;
    ans[1] = ((v[0]*v[1]) + (v[1]*v[3]))%k;
    ans[2] = ((v[2]*v[0]) + (v[3]*v[2]))%k;
    ans[3] = ((v[2]*v[1]) + (v[3]*v[3]))%k;
    return ans;
}

vector<int> multiple_M(const vector<int>& v, const vector<int>& u,int k){
    vector<int> ans(4);
    ans[0] = ((v[0]*u[0]) + (v[1]*u[2]))%k;
    ans[1] = ((v[0]*u[1]) + (v[1]*u[3]))%k;
    ans[2] = ((v[2]*u[0]) + (v[3]*u[2]))%k;
    ans[3] = ((v[2]*u[1]) + (v[3]*u[3]))%k;
    return ans;
}

void pow_M(int k,const vector<int>& v, vector<vector<int>>& temp,int n){
    for(int i=0; i<log2(k); i++){
        auto a = temp[temp.size()-1];
        temp.push_back(square_M(a,n));
    }      
}

string to_bi(int a){
    string ans = "";
    for (int i = 30; i >= 0; i--) {
        int k = a >> i;
        if (k & 1)
            ans += "1";
        else
            ans += "0";
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,ind=0;
    cin >> n >> k;
    vector<int> v(4);
    vector<vector<int>> temp;
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    temp.push_back(v);
    pow_M(n,v,temp,k);
    string a = to_bi(n);
    vector<int> ans = {1,0,0,1};
    for(int i=a.length()-1; i>=0; i--){
        if(ind == temp.size())break;
        if(a[i] == '1'){
            auto x = ans;
            ans = multiple_M(x,temp[ind],k);
        }
        ind++;
    }
    for(auto e : ans){
        cout << e%k << ' ';
    }
}

