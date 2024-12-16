#include <bits/stdc++.h>
using namespace std;

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  
  int l1, l2;
  l1 = s1.length(), l2 = s2.length();
  
  //把s1前i個字元改成s2(s2前j個字元換成s1)所需次數
  vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
  
  for(int i = 0; i <= l1; i++) dp[i][0] = i;
  for(int j = 0; j <= l2; j++) dp[0][j] = j;
  
  for(int i = 1; i <= l1; i++){
    for(int j = 1; j <= l2; j++){
      if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]; //沒有增加修改次數，直接沿用
      //dp[i-1][j] = 刪除；dp[i][j-1] = 插入；dp[i-1][j-1] = 替換
      else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); //選擇修改次數比較少的一方沿用
    }
  }
  
  cout << dp[l1][l2] << endl;
  return 0;
}
