#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long mod = 1000000007;
    cin >> n;

    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    
    for(int i = 2; i <= 6; i++){
            dp[i] = dp[i-1]*2;
    }

    for(int i = 7; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            dp[i] += dp[i-j]; //加上最後一個數字+j，前面i-j的方法數
            dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
