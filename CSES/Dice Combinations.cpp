#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long mod = 1000000007;
    cin >> n;

    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
