#include <bits/stdc++.h>
using namespace std;
map<char, int> mp; //自定義新字典序


bool comp(const string& s1, const string& s2){
  int k = min(s1.size(), s2.size());
  for(int i = 0; i < k; i++){
    if(mp[s1[i]] > mp[s2[i]]){
      return true;
    }
    else if (mp[s1[i]] < mp[s2[i]]){
      return false;
    }
  }
  return s1.size() < s2.size();
}

int main(){
  string s;
  int n;
  cin >> s >> n;
  
  //定義新字典序
  int rk = 25;
  for(char c : s){
    mp[c] = rk--;
  }
  
  vector<string> vec;
  for(int i = 0; i < n; i++){
    cin >> s;
    vec.push_back(s);
  }
  
  sort(vec.begin(), vec.end(), comp);
  
  for(int i = 0; i < n; i++) cout << vec[i] << endl;
  return 0;
}
