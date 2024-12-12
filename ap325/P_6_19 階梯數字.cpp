#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n; //讀入目標數字
  
  //dp[x][y]，x為位數，y為最高位數字
  vector<vector<long long>> dp(20, vector<long long>(10,0));
  
  //預設好0~9的值
  for(int i = 1; i <= 9; i++) dp[1][i] = 1;
  
  int l = to_string(n).length(); //目標數字的長度
  int h = to_string(n)[0] - '0'; //取得最高位數字
  
  for(int i = 2; i <= l; i++){
    dp[i][9] = dp[i-1][9];
    for(int j = 8; j >= 0; j--){
      dp[i][j] = dp[i-1][j] + dp[i][j+1];
    }
  }
  
  // 加上所有位數小於目標的階梯數字數量
    long long tt = 0;
    for (int i = 1; i < l; i++) {
        for (int j = 1; j <= 9; j++) {
            tt += dp[i][j];
        }
    }
  
  //加上所有最高位數小於目標的值
  for(int j = 1; j < h; j++) tt += dp[l][j];
  
  string s = to_string(n);
  for(int i = 1; i < l; i++){
    if(s[i] < s[i-1]) break;
    for(int j = s[i-1]-'0'; j < s[i]-'0'; j++) tt += dp[l-i][j];
  }
  
  bool ava = true;
  for(int i = 1; i < l; i++){
    if(s[i] < s[i-1]) {ava = false; break;}
  }
  
  if(ava) tt++;
  cout << tt << endl;
  return 0;
}
