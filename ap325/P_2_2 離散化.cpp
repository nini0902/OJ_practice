#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> s;
  vector<int> vec;
  
  int num;
  while(n--){
    cin >> num;
    s.insert(num);
    vec.push_back(num);
  }
  
  map<int,int> mp;
  int cnt = 0;
  for(auto i : s){
    mp[i] = cnt++;
  }
  
  for(auto i : vec) cout << mp[i] << " ";
  cout << endl;
  
  return 0;
}
