#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> mp(n, vector<int>(m));
  vector<pair<int,int>> Monster;
  
  string s;
  int ax, ay;
  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < m; j++) {
      if(s[j] == '#') mp[i][j] = 0;
      else mp[i][j] = 1;
      
      if(s[j] == 'M') {
        Monster.push_back({i,j});
      }
      else if(s[j] == 'A') {
        ax = i, ay = j;
      }
    }
  }
  
  queue<pair<int,int>> q;
  vector<vector<int>> dist_monster(n, vector<int>(m, -1));
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,-1,1};
  for(auto [mx,my] : Monster) {
    dist_monster[mx][my] = 0;
    q.push({mx,my});
  }
  
  while(!q.empty()) {
    auto [mx,my] = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int x = mx+dx[i], y = my + dy[i];
      if((x < n && y < m && x >= 0 && y >= 0) && (mp[x][y]) && dist_monster[x][y] == -1) {
        dist_monster[x][y] = dist_monster[mx][my]+1;
        q.push({x,y});
      }
    }
  }
  
  // 紀錄 A 到每個位置的距離
  vector<vector<int>> dist_A(n, vector<int>(m, -1));
  // 紀錄路徑(輸出回溯用的)
  vector<vector<pair<int,int>>> from(n, vector<pair<int,int>>(m, {-1,-1}));
  q.push({ax, ay});
  dist_A[ax][ay] = 0;
  bool finish = false;
  while(!q.empty() && !finish) {
    auto [nx, ny] = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int x = nx + dx[i], y = ny + dy[i];
      if((x < n && x >= 0) && (y < m && y >= 0) && mp[x][y] && dist_A[x][y] == -1) {
        if(dist_monster[x][y] || dist_A[nx][ny]+1 < dist_monster[x][y]) {
          dist_A[x][y] = dist_A[nx][ny]+1;
          q.push({x,y});
          from[x][y] = {nx,ny};
        }
      }
      // 到達邊界
      if(x == 0 || x == n-1 || y == 0 || y == m-1) {
        finish = true;
        nx = x, ny= y;
      }
    }
  }
  return 0;
}
