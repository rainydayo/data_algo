#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v = A;
    int arr[100000] = {0};
    for(const auto& e : A){
        arr[e] = 1;
    }
    for(const auto& e : B){
        if(arr[e] != 1){
            v.push_back(e);
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    int arr[100000] = {0};
    for(const auto& e : B){
        arr[e] = 1;
    }
    for(const auto& e : A){
        if(arr[e] == 1){
            v.push_back(e);
        }
    }

    return v;
}
