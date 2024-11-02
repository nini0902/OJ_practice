#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> coins(n);
  vector<int> dp(x+1, 0);
  
  for(int i = 0; i < n; i++) cin >> coins[i];
  
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = coins[i]; j <= x; j++){
      dp[j] += dp[j-coins[i]];
      dp[j] %= mod;
    }
  }
  cout << dp[x] << endl;
  return 0;
}
