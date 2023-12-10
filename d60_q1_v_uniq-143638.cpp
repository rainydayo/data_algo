#include <set>
template <typename T>
void CP::vector<T>::uniq(){
CP::vector<T>v;
std::set<T>s;
for(auto&e:*this){
if(s.find(e)==s.end()){
s.insert(e);
v.push_back(e);
}}
*this=v;
}
