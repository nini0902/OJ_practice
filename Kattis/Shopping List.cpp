#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  map<string, int> food;
  
  string item;
  for(int i = 0; i < n; i++){
    set<string> s; // 先用 set 儲存是避免同一個 list 出現多次一樣的商品
    for(int j = 0; j < m; j++){
      cin >> item;
      s.insert(item);
    }
    for(string st : s) food[st]++; // 紀錄每個出現的食物
  }
  
  vector<string> vec;
  for(auto& p : food){ 
    if(p.second == n) vec.push_back(p.first);
  }
  
  cout << vec.size() << endl;
  sort(vec.begin(), vec.end());
  for(string f : vec) cout << f << endl;
  return 0;
}
