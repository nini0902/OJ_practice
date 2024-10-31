#include <bits/stdc++.h>
using namespace std;
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  int sx=0, sy=0, ex=0, ey=0; //起點與終點座標
  cin >> n >> m;
  vector<vector<int>> vec(n+2, vector<int>(m+2, 1));
  int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
  char dir[4] = {'U','D','L','R'};
  
  //讀入地圖
  string s;
  for(int i = 1; i <= n; i++){
    cin >> s;
    for(int j = 1; j <= m; j++){
      if(s[j-1] == '#') vec[i][j] = 1;
      else vec[i][j] = 0;
      
      if(s[j-1] == 'A') sx = i, sy = j;
      else if(s[j-1] == 'B') ex = i, ey = j;
    }
  }
  
  vector<vector<bool>> visited(n+2, vector<bool>(m+2, false)); //走訪記錄
  vector<vector<pair<int, char>>> dp(n+2, vector<pair<int,char>>(m+2, {INT_MAX,' '})); //最短路徑長度
  queue<pair<int,int>> q;
  
  q.push({sx,sy});
  dp[sx][sy].first = 0;
  visited[sx][sy] = true;
  while(!q.empty()){
    auto it = q.front();
    q.pop();
    int x = it.first, y = it.second;
    if(x == ex && y == ey) break; //已達目的地
    
    for(int i = 0; i < 4; i++){ //四個方向都走走看
      int nx = x+dx[i], ny = y+dy[i];
      if(visited[nx][ny] || vec[nx][ny] == 1) continue;
      
      if(dp[nx][ny].first > dp[x][y].first+1){
        dp[nx][ny].second = dir[i]; //紀錄是從哪個方向來的
        dp[nx][ny].first = dp[x][y].first+1;
      }
      q.push({nx,ny});
      visited[nx][ny] = true;
    }
  }
  
  if(dp[ex][ey].first != INT_MAX){
    cout << "YES" << endl;
    cout << dp[ex][ey].first << endl;
    string path;
    int x = ex, y = ey;
    //回溯路徑
    while(x != sx || y != sy){ //還沒走到起點就繼續走
      path.push_back(dp[x][y].second);
      //因為紀錄的是「從哪轉移」，所以回溯要反回去
      switch(dp[x][y].second){
        case 'U': x++; break;
        case 'D': x--; break;
        case 'L': y++; break;
        case 'R': y--; break;
      }
    }
    reverse(path.begin(), path.end()); //從尾巴開始回溯，反轉後才是真正的路徑
    cout << path << endl;
  }
  else cout << "NO" << endl;
  return 0;
}
