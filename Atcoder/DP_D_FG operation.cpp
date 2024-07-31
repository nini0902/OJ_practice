#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main(){
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for(int i = 0; i < n; i++) cin >> A[i];

    vector<vector<int>> dp(n+1, vector<int>(10,0));
    dp[2][(A[0]+A[1])%10] += 1; //初始狀態F設定
    dp[2][(A[0]*A[1])%10] += 1; //初始狀態G設定

    for(int i = 2; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(dp[i][j] > 0){ //表示有前一個狀態可轉移
                int F = (j + A[i])%10; //F操作
                int G = (j * A[i])%10; //G操作
                dp[i+1][F] = (dp[i+1][F] + dp[i][j]) % MOD;
                dp[i+1][G] = (dp[i+1][G] + dp[i][j]) % MOD;
            }
        }
    }
    for(int i = 0; i < 10; i++) cout << dp[n][i] << endl;
    return 0;
}
