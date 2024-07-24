//DP(NTOJ鐵人三項類似解法)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<long long>> dp(N,vector<long long>(3,0));

    dp[0][0] = max(a[0], max(b[0],c[0]));
    dp[0][1] = dp[0][0];
    dp[0][2] = dp[0][0];

    for(int i = 1; i < N; i++){
        dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]); //這次選A，上次就從BC選比較大的
        dp[i][1] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]); //這次選B，上次就從AC選比較大的
        dp[i][2] = max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]); //照次選C，上次就從AB選比較大的
    }
    
    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl; //最後輸出最後一天，計算出來最大的那個
    return 0;
}
