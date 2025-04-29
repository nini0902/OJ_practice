#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,c,n;
  cin >> r >> c >> n;
  
  vector<pair<int,int>> vec(n);
  set<int> row,col;
  for(int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
    row.insert(vec[i].first); // 紀錄出現過的 row
    col.insert(vec[i].second); // 紀錄出現過的 column
  }
  
  int idx = 1;
  map<int,int> R,C;
  // R 重新編號
  for(int k : row) {
    R[k] = idx;
    idx++;
  }
  
  idx = 1;
  // C 重新編號
  for(int k : col) {
    C[k] = idx;
    idx++;
  }
  
  // 輸出新的編號
  for(auto &p : vec){
    cout << R[p.first] << " " << C[p.second] << endl;
  }
  return 0;
}
