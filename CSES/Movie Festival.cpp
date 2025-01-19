#include <bits/stdc++.h>
using namespace std;

//用結束時間排序，保證越後面結束時間越晚
bool comp(pair<int, int>& a, pair<int, int>& b){
  return a.second < b.second;
}

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  
  for(int i = 0; i < n; i++){
    cin >> vec[i].first >> vec[i].second;
  }
  
  sort(vec.begin(), vec.end(), comp);
  
  int cnt = 1, M = 1;
  int m_end = vec[0].second;
  for(int i = 1; i < n; i++){
    if(vec[i].first < m_end) continue; //只要沒辦法接續上一部的就跳掉
    cnt++;
    m_end = vec[i].second;
    M = max(M, cnt);
  }
  M = max(M, cnt);
  
  cout << M << endl;
  return 0;
}
