#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t;
  cin >> n >> t;
  vector<int> vec(n);
  for(int i = 0; i < n; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  vector<long long> dp(t+1, LLONG_MAX);
  dp[0] = 0;
  //每個幣值最少就是一個
  for(int i = 0; i < n; i++){
    dp[vec[i]] = 1;
  }
  
  for(int i = 1; i <= t; i++){ //遍歷1~t元
    for(int j = 0; j < n; j++){ //遍歷所擁有的幣值
      if(vec[j] > i) break;
      dp[i] = min(dp[i], dp[i-vec[j]]+1);
    }
  }
  
  for(int i = 0; i < t+1; i++){
    cout << i << " : " << dp[i] << endl;
  }
  return 0;
}
