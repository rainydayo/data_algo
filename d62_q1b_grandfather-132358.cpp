#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

bool checkGrand(std::string& dad, std::string& son, std::map<std::string, std::string>& v){
    if(dad == son) {
        return false;
    }
    auto dadIt = v.find(dad);
    auto sonIt = v.find(son);
    if(dadIt != v.end() && sonIt != v.end() && dadIt->second == sonIt->second && !dadIt->second.empty()){
        return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::string dad, son;
    std::map<std::string, std::string> tier1;
    std::map<std::string, std::string> tier2;

    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::cin >> dad >> son;
        tier1[son] = dad;
    }
    for(const auto& e : tier1){
        auto grandDadIt = tier1.find(e.second);
        if(grandDadIt != tier1.end()){
            tier2[e.first] = grandDadIt->second;
        }
    }
    for(int i = 0; i < m; i++){
        std::cin >> dad >> son;
        if(checkGrand(dad, son, tier2)){std::cout << "YES";} else {std::cout << "NO";} std::cout << std::endl;
    }
}
