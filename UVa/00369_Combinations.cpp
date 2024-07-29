//DP
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    vector<vector<unsigned long long int>> dp;
    while(cin >> N >> M){
        if(N == 0 && M == 0) break;
        dp.assign(N+1,vector<unsigned long long int>(M+1,0));

        for(int i = 0; i <= N; i++) {
            dp[i][0] = 1;
            if(i <= M) dp[i][i] = 1;
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= min(i,M); j++){
                //dp[i][j]表示i個中取j個有多少種取法
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                //從「選擇第i個元素」 + 「不選擇第i個元素」轉移過來的
            }
        }
        
        cout << N <<" things taken " << M << " at a time is " << dp[N][M] << " exactly." << endl;
    }
    return 0;
}
