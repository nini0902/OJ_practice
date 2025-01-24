#include <bits/stdc++.h>
using namespace std;

struct range {
  int x, y, idx;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<range> r(n);
  for(int i = 0; i < n; i++){
    cin >> r[i].x >> r[i].y;
    r[i].idx = i;
  }
  
  sort(r.begin(), r.end(), [](const range  &a, const range &b){
    return a.x < b.x || (a.x == b.x && a.y > b.y);
  });
  
  vector<int> contain(n, 0), be_contain(n, 0);
  
  int M_y = 0; //紀錄目前最大範圍的y
  for(const auto &R : r){
    //R.y可被包圍
    if(R.y <= M_y) be_contain[R.idx] = 1;
    M_y = max(M_y, R.y);
  }
  
  int m_y = INT_MAX; //目前可被包圍的最小y
  for(auto it = r.rbegin(); it != r.rend(); ++it){
    if(it->y >= m_y) contain[it->idx] = 1;
    m_y = min(m_y, it->y);
  }
  
  for(int k : contain) cout << k << " ";
  cout << endl;
  for(int k : be_contain) cout << k << " ";
  cout << endl;
  return 0;
}
