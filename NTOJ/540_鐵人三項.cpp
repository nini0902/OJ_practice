#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL N;
    cin >> N;
    vector<vector<LL>> vec(N, vector<LL>(3));

    for(int i = 0; i < N; i++){
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }

    vector<vector<LL>> dp(N, vector<LL>(3,LLONG_MAX));

    dp[0][0] = vec[0][0];

    for(int i = 1; i < N; i++){
        //累積到現在(狀態為游泳)，用時最短的
        dp[i][0] = min(dp[i-1][0], dp[i][0]) + vec[i][0];
        if(i >= 1){
            //比較上一次狀態為游泳還是腳踏車，哪個時間短
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + vec[i][1];
        }
        if(i >= 2){
            //比較上一次狀態為跑步還是腳踏車，哪個時間短
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + vec[i][2];
        }
    }

    cout << dp[N-1][2] << endl;
    return 0;
}
