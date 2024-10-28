#include <bits/stdc++.h>
#define v first
#define p second
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> vec(m);
  for(int i = 0; i < m; i++) cin >> vec[i].v >> vec[i].p;
  
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  for(int i = 1; i <= m; i++){
    for(int j = 0; j <= n; j++){
      dp[i][j] = dp[i-1][j]; //不選擇第i個物品
      //判斷到底要不要選擇第i個物品
      if(j - vec[i-1].v >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-vec[i-1].v]+vec[i-1].v*vec[i-1].p);
    }
  }
  cout << dp[m][n] << endl;
  return 0;
}
