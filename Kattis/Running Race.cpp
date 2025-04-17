#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

bool comp(pair<int, LL>& a, pair<int, LL>& b){
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main(){
  int n,k,l;
  cin >> n >> k >> l;
  
  map<int,vector<LL>> mp;
  int num;
  string t;
  for(int i = 0; i < n; i++){
    cin >> num >> t;
    //轉成秒
    size_t dot = t.find(".");
    int mm = stoi(t.substr(0, dot));
    int ss = stoi(t.substr(dot+1));
    mp[num].push_back(mm*60 + ss);
  }
  
  vector<pair<int, LL>> vec;
  
  for(auto &it : mp) {
    auto &v = it.second;
    if(v.size() >= k){ //只記錄有成功完賽的人
      sort(v.begin(), v.end());
      LL sum = 0;
      for(int i = 0; i < k; i++) sum += v[i];
      vec.push_back({it.first, sum}); //{選手編號, 跑的時間}
    }
  }
  sort(vec.begin(), vec.end(), comp);
  
  for(int i = 0; i < vec.size() ; i++) cout << vec[i].first << endl;
  
  return 0;
}
