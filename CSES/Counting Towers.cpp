#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  
  vector<vector<long long int>> dp(2, vector<long long int>(1000001));
  dp[0][1] = 1; //最底有兩個方塊
  dp[1][1] = 1; //最底只有一個方塊
  
  for(int i = 2; i <= 1000000; i++){
    dp[0][i] = (dp[0][i-1]*4 + dp[1][i-1])%mod; //兩塊+兩塊有4種接法；兩塊+一塊有1種接法
    dp[1][i] = (dp[0][i-1] + dp[1][i-1]*2)%mod; //一塊+兩塊有1種接法；一塊+一塊有2種接法
  }
  
  for(int i = 0, k; i < n; i++){
    cin >> k;
    cout << (dp[0][k] + dp[1][k])%mod << endl;
  }
  return 0;
}
