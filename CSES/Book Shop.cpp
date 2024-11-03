#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  
  vector<int> dp(x+1, 0);
  vector<pair<int,int>> pp(n);
  for(int i = 0; i < n; i++) cin >> pp[i].first;
  for(int i = 0; i < n; i++) cin >> pp[i].second;
  
  int p1, p2; //p1 = price, p2 = pages
  for(int i = 0; i < n; i++){
    p1 = pp[i].first;
    p2 = pp[i].second;
    for(int j = x; j >= p1; j--){ //從最高開始計算，避免重複沿用到同一本書
      dp[j] = max(dp[j], dp[j-p1]+p2);
    }
  }
  
  cout << dp[x] << endl;
  return 0;
}
