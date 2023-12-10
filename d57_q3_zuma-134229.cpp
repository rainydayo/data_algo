#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool idx = false;
    int n, k, v, num;
    cin >> n >> k >> v;
    vector<pair<int,int>> front;
    queue<pair<int,int>> back;
    int temp=0,count=1;
    for (int i = 0; i < k; i++) {
        cin >> num;
        if(num == temp){
            count++;
        } else {
            if(i > 0){
            front.push_back(make_pair(temp,count));
            }
            temp = num;
            count = 1;
        }
    }
    front.push_back(make_pair(temp,count));
    temp = 0;
    count = 1;
    for (int i = 0; i < n-k; i++) {
        cin >> num;
        if(num == temp){
            count++;
        } else {
            if(i > 0){
            back.push(make_pair(temp,count));
            }
            temp = num;
            count = 1;
        }
    }
    back.push(make_pair(temp,count));

    if(front[front.size()-1].first == v && (back.front()).first == v && front[front.size()-1].second + (back.front()).second + 1 >=3){
        idx = true;
        front.pop_back();back.pop();
    } else if(front[front.size()-1].first == v && (back.front()).first != v && front[front.size()-1].second + 1 >=3){
        idx = true;
        front.pop_back();
    } else if(front[front.size()-1].first != v && (back.front()).first == v && (back.front()).second + 1 >=3){
        idx = true;
        back.pop();
    }
    if(idx){
        int c = front.size();
        for(int i=0;i<c;i++){
            if(back.size() == 0){
                break;
            }
            if(front[front.size()-1].first == (back.front()).first && front[front.size()-1].second + (back.front()).second >=3){
                front.pop_back();back.pop();
            } else {break;}
        }
        for(auto e : front){
            for(int i=0;i<e.second;i++){
                cout << e.first << ' ';
            }
        }
        while(back.size() != 0){
            for(int j =0;j<(back.front()).second;j++){
                cout << (back.front()).first << ' ';
            }
            back.pop();
        }
    } else {
        for(auto e : front){
            for(int i=0;i<e.second;i++){
                cout << e.first << ' ';
            }
        }
        cout << v << ' ';
        while(back.size() != 0){
            for(int j =0;j<(back.front()).second;j++){
                cout << (back.front()).first << ' ';
            }
            back.pop();
        }
    }

}
