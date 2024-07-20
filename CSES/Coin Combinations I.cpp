#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    long long mod = 1000000007;
    cin >> n >> x;
    vector<int> c(n);
    vector<long long> dp(x+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> c[i];
        dp[c[i]] = 1;
    }
    sort(c.begin(), c.end());

    for(int i = c[0]; i <= x; i++){
        for(int j = 0; j < n && i-c[j] >= 0; j++){
            dp[i] += dp[i-c[j]]; //加上最後一個數字加c[j]的方法數
            dp[i] %= mod;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
