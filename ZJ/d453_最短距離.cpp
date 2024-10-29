//BFS
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, n, m, sx, sy, ex, ey;
  string s;
  int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
  cin >> N;
  
  while(N--){
    cin >> n >> m >> sx >> sy >> ex >> ey;
    vector<vector<int>> vec(n+2, vector<int>(m+2, 1));
    for(int i = 1; i <= n; i++){
      cin >> s;
      for(int j = 1; j <= m; j++){
        vec[i][j] = s[j-1]-48;
      }
    }
    
    vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));
    vector<vector<int>> dp(n+2, vector<int>(m+2, INT_MAX));
    queue<pair<int,int>> q;
    
    q.push({sx, sy});
    dp[sx][sy] = 1; //把起點走過格數設成1
    visited[sx][sy] = true; //起點設visited
    
    while(!q.empty()){
      auto it = q.front(); //取最上面的queue
      q.pop();
      int x = it.first, y = it.second;
      visited[x][y] = true;
  
      //走訪該點(向外四散)
      for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i]; //從該點走四個方向
        if(vec[nx][ny] == 1 || visited[nx][ny]) continue;
        dp[nx][ny] = min(dp[nx][ny], dp[x][y]+1);
        q.push({nx,ny});
        visited[nx][ny] = true;
      }
      if(x == ex && y == ey) break;
    }
    
    if(dp[ex][ey] == INT_MAX) cout << 0 << endl;
    else cout << dp[ex][ey] << endl;
  }
  
  return 0;
}
