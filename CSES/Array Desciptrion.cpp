#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n,m,a;
    cin >> n >> m >> a;
    vector<vector<int>> dp(n+1,vector<int>(m+2,0));

    if(a == 0){
        //因為第一格未知，所以所有數字都是1
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    else dp[0][a] = 1; //第一格已知，將已知數字設1

    for(int i = 1; i < n; i++) {
        cin >> a;
        if(a){
            //該格數字已知，就加前一格跟他差1或0的數字的方法數
            dp[i][a] += dp[i-1][a-1];
            dp[i][a] %= MOD;
            dp[i][a] += dp[i-1][a];
            dp[i][a] %= MOD;
            dp[i][a] += dp[i-1][a+1];
            dp[i][a] %= MOD;
        }
        else{
            //該格未知，所以計算每個位置的方法數
            for(int j = 1; j <= m; j++){
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
