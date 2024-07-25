#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> dp(n+1, vector<int>(2,1001));
    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'N'){
            //N型路口
            dp[i+1][0] = min(dp[i][0]+1, dp[i][1]+1);
            dp[i+1][1] = min(dp[i][1], dp[i][0]+1);
        }
        else if(s[i] == 'S'){
            //S型路口
            dp[i+1][0] = min(dp[i][0], dp[i][1]+1);
            dp[i+1][1] = min(dp[i][1]+1, dp[i][0]+1);
        }
        else{
            //B型路口
            dp[i+1][0] = min(dp[i][0]+1, dp[i][1]+2);
            dp[i+1][1] = min(dp[i][1]+1, dp[i][0]+2);
        }
    }

    cout << dp[n][0] << endl;
    return 0;
}
