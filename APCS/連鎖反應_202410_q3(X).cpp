#include <bits/stdc++.h>
using namespace std;
#define N 500
int m,n,q;
vector<vector<int>> mp, dis;

void bfs(int r, int c, int step, vector<pair<int, int>> &Q){
  int dr[4] = {0,1,0,-1};
  int dc[4] = {1,0,-1,0};
  int head = 0;
  
  for(int i = max(r-step, 0); i <= min(r+step, m-1); i++){
    for(int j = max(c-step, 0); j <= min(c+step, n-1); j++){
      dis[i][j] = (mp[i][j] == -1)? 0 : -1;
    }
  }
  
  Q.push_back({r, c});
  dis[r][c] = 0;
  
  while(head < Q.size()){
    int cr = Q[head].first, cc = Q[head].second;
    
    head++;
    if(dis[cr][cc] >= step) continue;
    
    for(int i = 0; i < 4; i++){
      int nr = cr + dr[i], nc = cc + dc[i];
      if(nr >= 0 && nr < m && nc >= 0 && nc < n && dis[nr][nc] == -1){
        dis[nr][nc] = dis[cr][cc] + 1;
        Q.push_back({nr, nc});
      }
    }
  }
  return;
}

int dfs(int r, int c){
  int cnt = 1; //紀錄該區域爆炸數量
  int x = mp[r][c]; //目前點的值
  mp[r][c] = -2; //已走過
  
  if(x == 0) return cnt;
  
  vector<pair<int, int>> que;
  bfs(r, c, x, que); //BFS搜尋所有的點
  
  for(auto v : que){
    if(mp[v.first][v.second] != -2){ //還沒訪問過
      cnt += dfs(v.first, v.second); //遞迴計算覆蓋區域
    }
  }
  return cnt;
}

int main(){
  int c0, r0;
  cin >> m >> n >> q;
  
  mp.resize(m, vector<int>(n, 0)); //初始化地圖
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> mp[i][j];
      if(mp[i][j] == -2) {r0 = i; c0 = j;}
    }
  }
  
  dis.resize(m, vector<int>(n)); //初始化距離
  vector<pair<int, int>> Q; 
  bfs(r0, c0, m*n, Q);
  int d[N][N];
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      d[i][j] = dis[i][j];
    }
  }
  
  int tt = 1, ra = -1;
  for(auto p : Q){
    int r = p.first, c = p.second;
    if(mp[r][c] == -2) continue;
    tt += dfs(r,c);
    if(tt >= q) {ra = d[r][c]; break;}
  }
  
  cout << ra << endl;
  return 0;
}
