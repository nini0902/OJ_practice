#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> vec(n);
  
  for(int i = 0; i <n; i++){
    cin >> vec[i].first >> vec[i].second;
  }
  
  sort(vec.begin(), vec.end());
  
  int cnt = 0, l = -1, r = -1;
  for(auto it : vec){
    if(it.first <= r && it.second <= r) continue; // 在範圍內
    else if (it.first <= r && it.second > r){ //延長當前範圍
      cnt += (it.second - r);
      r = it.second;
    }
    else if (it.first > r){ // 新的範圍
      l = it.first;
      r = it.second;
      cnt += r-l;
    }
  }
  
  cout << cnt << endl;
  return 0;
}
