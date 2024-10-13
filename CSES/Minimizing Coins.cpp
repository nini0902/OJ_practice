#include <bits/stdc++.h>
#define N 10000005
using namespace std;

int main(){
  int n, t;
  cin >> n >> t;
  vector<int> vec(n, N);
  for(int i = 0; i < n; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  vector<int> dp(N, N);
  dp[0] = 0;
  //每個幣值最少就是一個
  for(int i = 0; i < n; i++){
    dp[vec[i]] = 1;
  }
  
  for(int i = 0; i <= t; i++){ //遍歷1~t元
    for(int j = 0; j < n; j++){ //遍歷所擁有的幣值
      if(vec[j] >= i) break;
      dp[i] = min(dp[i], dp[i-vec[j]]+1);
    }
  }
  
  if(dp[t] == N) cout << -1 << endl; //沒有被更新表示湊不出來
  else cout << dp[t] << endl;
  return 0;
}
