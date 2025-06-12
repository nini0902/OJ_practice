#include <bits/stdc++.h>
using namespace std;

int rfind(vector<int>& parent, int u) {
  if(parent[u] < 0) return u; //find root
  return rfind(parent, parent[u]);
}

int unite(vector<int>& parent, int u1, int u2) {
  int r1 = rfind(parent, u1);
  int r2 = rfind(parent, u2);
  
  if(r1 == r2) return 0; //share the same root(= same pond)
  
  // r1 bigger than r2
  if(parent[r1] < parent[r2]) {
    parent[r1] += parent[r2];
    parent[r2] = r1; //r2 not a root anymore
    return -parent[r1]; // return the new size after combine
  }
  else {
    parent[r2] += parent[r1];
    parent[r1] = r2;
    return -parent[r2];
  }
}

int main(){
  int n,m,p;
  cin >> n >> m >> p;
  int rows = n+2, cols = m+2;
  
  vector<int> parent(rows*cols, -1);
  vector<int> grid(rows*cols, 0);
  
  // input the grid
  for(int i = 1; i < n+1; i++) {
    for(int j = 1; j < m+1; j++) {
      cin >> grid[i*cols+j];
    }
  }
  
  int cnt = 0;
  int M = 0;
  for(int i = 1; i < n+1; i++) {
    for(int j = 1; j < m+1; j++) {
      if(grid[i*cols+j] == 0) continue;
      
      int idx = i*cols+j;
      cnt++;
      
      if(grid[idx+1]) { // check right
        int sz = unite(parent, idx, idx+1);
        if(sz > 0) { // unite two ponds
          cnt--;
          M = max(M, sz);
        }
      }
      
      if(grid[idx + cols]) { // check down
        int sz = unite(parent, idx, idx+cols);
        if(sz > 0) { // unite two ponds
          cnt--;
          M = max(M, sz);
        }
      }
    }
  }
  
  int ans_cnt = cnt;
  int ans_M = M;
  
  for(int k = 0,r,c; k < p; k++) {
    cin >> r >> c;
    int idx = (r)*cols+(c);
    if(grid[idx]) continue; // already a pond
    
    cnt++;
    grid[idx] = 1;
    
    // check {u,d,r,l}
    for(int d : {-1,1,cols,-cols}) {
      int ni = idx+d;
      if(grid[ni] == 0) continue;
      
      int sz = unite(parent, idx, ni);
      if(sz > 0) {
        cnt--;
        M = max(sz, M);
      }
    }
    ans_cnt += cnt;
    ans_M += M;
  }
  
  cout << ans_M << endl;
  cout << ans_cnt << endl;
  return 0;
}
