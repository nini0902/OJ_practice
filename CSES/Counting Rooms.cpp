#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
vector<vector<int>> vec;
vector<int> dx = {-1,1,0,0}, dy = {0,0,-1,1};

//遍歷目前可達的所有地方並且標示成1
void dfs(int nx, int ny){
  for(int i = 0; i < 4; i++){
    int tx = nx + dx[i], ty = ny + dy[i];
    if(vec[tx][ty] == 0){
      vec[tx][ty] = 1;
      dfs(tx, ty);
    }
  }
}

int main(){
  cin >> n >> m;
  vec.resize(n+2, vector<int>(m+2, 1));
  
  string s;
  for(int i = 1; i <= n; i++){
    cin >> s;
    //把可走變成0，不可走變成1
    for(int j = 1; j <= m; j++){
      if(s[j-1] == '#') vec[i][j] = 1;
      else vec[i][j] = 0;
    }
  }
  
  for(int i = 1; i < n+1; i++){
    for(int j = 1; j < m+1; j++){
      if(vec[i][j] == 0) {dfs(i, j); cnt++;}
    }
  }
  
  cout << cnt << endl;
  return 0;
}
